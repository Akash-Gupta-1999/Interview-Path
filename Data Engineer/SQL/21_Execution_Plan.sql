https://www.youtube.com/watch?v=O7AzUDogXsw&list=PLNcg_FV9n7qZY_2eAtUzEUulNjTJREhQe&index=38
/* ==============================================================================
   SQL Execution Plans - Query Optimization & Performance Analysis
-------------------------------------------------------------------------------
   This script provides comprehensive coverage of SQL Execution Plans including:
   - Understanding execution plans and their components
   - How to view and interpret execution plans
   - Query optimization techniques
   - Identifying performance bottlenecks
   - Cost-based optimization principles
   - Index usage analysis through execution plans
   - Common execution plan operators and their meanings
   - Best practices for query performance tuning

   Table of Contents:
       1. Introduction to Execution Plans
       2. Viewing Execution Plans (Estimated vs Actual)
       3. Key Execution Plan Operators
       4. Understanding Costs and Statistics
       5. Identifying Missing Indexes
       6. Query Optimization Techniques
       7. Common Performance Issues and Solutions
       8. Best Practices for Query Performance
=================================================================================
*/

/* ==============================================================================
   1. INTRODUCTION TO EXECUTION PLANS
============================================================================== */

/*
   What is an Execution Plan?
   ===========================
   An execution plan is a detailed, step-by-step breakdown of how the database
   engine will (estimated plan) or did (actual plan) execute a SQL query.
   
   Key Purposes:
   - Understand query flow and data movement
   - Identify performance bottlenecks
   - Visualize resource consumption (CPU, I/O)
   - Optimize queries based on actual behavior
   - Make informed decisions about indexing
   
   The Query Optimizer:
   - Analyzes the incoming query
   - Considers available indexes and table statistics
   - Evaluates multiple execution strategies
   - Chooses the plan with the lowest estimated cost
   - Cost = CPU cost + I/O cost + Memory cost
*/

-- Enable Statistics to see I/O and CPU information
SET STATISTICS IO ON;
SET STATISTICS TIME ON;
SET STATISTICS CPU ON;

-- Simple query to demonstrate execution plan analysis
SELECT 
    CustomerID, 
    FirstName, 
    LastName, 
    EmailAddress
FROM Sales.Customers
WHERE CountryRegionCode = 'US';

-- Turn off statistics
SET STATISTICS IO OFF;
SET STATISTICS TIME OFF;
SET STATISTICS CPU OFF;

/*
   SQL Server Management Studio (SSMS) Methods to View Plans:
   
   1. Estimated Execution Plan:
      - Press CTRL + L before executing the query
      - Shows predicted execution without running the query
      - Based on statistics and cost estimation
      - Faster to view but may not match actual execution
   
   2. Actual Execution Plan:
      - Press CTRL + M before executing the query
      - Shows real execution after query runs
      - Includes actual row counts and statistics
      - Best for performance analysis
   
   3. Include Actual Execution Plan:
      - Query Menu → Include Actual Execution Plan → Execute
      - Shows execution details alongside query results
*/

/* ==============================================================================
   2. VIEWING EXECUTION PLANS - ESTIMATED VS ACTUAL
============================================================================== */

-- Example 1: Table Scan vs Index Seek
-- ====================================

-- Query WITHOUT proper index (will cause Table Scan)
SELECT CustomerID, FirstName, LastName
FROM Sales.Customers
WHERE EmailAddress = 'nicole0@adventure-works.com';

-- Create an index on EmailAddress
CREATE NONCLUSTERED INDEX idx_Customers_Email
ON Sales.Customers (EmailAddress)
INCLUDE (FirstName, LastName);

-- Same query WITH index (should use Index Seek)
SELECT CustomerID, FirstName, LastName
FROM Sales.Customers
WHERE EmailAddress = 'nicole0@adventure-works.com';

-- Example 2: Join Performance Analysis
-- ====================================

-- Inefficient join without proper indexes
SELECT 
    c.CustomerID,
    c.FirstName,
    o.OrderID,
    o.OrderDate
FROM Sales.Customers c
INNER JOIN Sales.Orders o ON c.CustomerID = o.CustomerID
WHERE c.CountryRegionCode = 'US'
  AND o.OrderDate >= '2014-01-01';

-- Create indexes to optimize the join
CREATE NONCLUSTERED INDEX idx_Customers_Country
ON Sales.Customers (CountryRegionCode)
INCLUDE (FirstName);

CREATE NONCLUSTERED INDEX idx_Orders_Date
ON Sales.Orders (OrderDate)
INCLUDE (CustomerID);

-- Same join query with optimized indexes
SELECT 
    c.CustomerID,
    c.FirstName,
    o.OrderID,
    o.OrderDate
FROM Sales.Customers c
INNER JOIN Sales.Orders o ON c.CustomerID = o.CustomerID
WHERE c.CountryRegionCode = 'US'
  AND o.OrderDate >= '2014-01-01';

/* ==============================================================================
   3. KEY EXECUTION PLAN OPERATORS
============================================================================== */

/*
   Table Scan / Clustered Index Scan
   ==================================
   - Reads every row in the table or index from beginning to end
   - Cost: HIGH (especially on large tables)
   - I/O Operations: Proportional to table size
   - When Used: 
     * No suitable index available
     * Selecting significant portion of table
     * Statistics indicate scanning is cheaper than seeking
   
   Example Causes:
   - Filtering on non-indexed column
   - Using functions on indexed column (e.g., YEAR(DateColumn) = 2023)
   - Retrieving most table data
*/

-- Causes a Table Scan (no index on Department)
SELECT CustomerID, FirstName
FROM Sales.Customers
WHERE Department = 'Engineering';

-- Create index to convert to seek
CREATE NONCLUSTERED INDEX idx_Customers_Department
ON Sales.Customers (Department);

/*
   Index Seek
   ==========
   - Uses index structure to navigate directly to matching rows
   - Cost: LOW (logarithmic time complexity)
   - I/O Operations: Minimal
   - Best Case: Narrow WHERE clause matching index key
   
   Conditions for Index Seek:
   1. Filter condition matches index key columns
   2. No functions applied to indexed column
   3. Data types match between filter and index
   4. Statistics favor seeking over scanning
*/

-- Efficient query using Index Seek
SELECT CustomerID, FirstName, LastName
FROM Sales.Customers
WHERE CountryRegionCode = 'US'
  AND CustomerID > 1000;

/*
   Index Scan
   ==========
   - Scans through entire index (not necessarily entire table)
   - Cost: MODERATE (more efficient than table scan)
   - Similar to table scan but on index structure instead
   
   When Optimizer Chooses Index Scan:
   1. WHERE clause references non-leading index column
   2. Query covers columns in index (covering index advantage)
   3. Seeks would be more expensive than scan
   4. Index is selective enough to be efficient
*/

-- May cause Index Scan if WHERE doesn't match index key
SELECT CustomerID, FirstName
FROM Sales.Customers
WHERE LastName LIKE 'M%';

/*
   Nested Loops Join
   =================
   - Outer input: "driving" table (smaller result set)
   - Inner input: Searched for each outer row
   - Cost: Optimal for small inner sets or good indexes
   - Logic: For each row in outer table, seek matching rows in inner table
   
   When Used:
   - Small outer input (< 1000 rows typically)
   - Good index on inner table join column
   - One table much smaller than other
*/

-- Likely uses Nested Loops (if outer input is small)
SELECT 
    c.CustomerID,
    c.FirstName,
    o.OrderID
FROM Sales.Customers c
INNER JOIN Sales.Orders o ON c.CustomerID = o.CustomerID
WHERE c.CustomerID < 10;

/*
   Hash Join
   =========
   - Build Phase: Hash table created from smaller input
   - Probe Phase: Each row from larger input probes the hash table
   - Cost: Moderate, good for larger sets without indexes
   - Memory: Requires memory for hash table
   
   When Used:
   - Both inputs are large
   - No useful indexes on join columns
   - Neither input is sorted
   - Good for equijoins (= condition)
*/

-- May use Hash Join for large joins without indexes
SELECT 
    c.CustomerID,
    p.ProductID,
    COUNT(*) as OrderCount
FROM Sales.Customers c
INNER JOIN Sales.Orders o ON c.CustomerID = o.CustomerID
INNER JOIN Sales.OrderDetails od ON o.OrderID = od.OrderID
INNER JOIN Production.Products p ON od.ProductID = p.ProductID
GROUP BY c.CustomerID, p.ProductID;

/*
   Merge Join
   ==========
   - Both inputs must be sorted on join column
   - Efficient for large sorted inputs
   - Cost: Low memory, moderate CPU
   - One pass through both inputs
   
   When Used:
   - Both inputs are sorted (or sorted by index)
   - Large equijoins
   - Memory constraints
*/

-- May use Merge Join if both inputs are sorted
SELECT 
    c.CustomerID,
    o.OrderID
FROM Sales.Customers c
INNER JOIN Sales.Orders o ON c.CustomerID = o.CustomerID
ORDER BY c.CustomerID;

/*
   Sort
   ====
   - Sorts result set by specified columns
   - Cost: Can be expensive for large datasets
   - CPU intensive: O(n log n) complexity
   - Memory: May spill to disk if data too large
   
   When Occurs:
   - ORDER BY without matching index
   - GROUP BY without matching index
   - DISTINCT operation
   - Window functions with PARTITION BY
*/

-- Causes Sort (ORDER BY without index)
SELECT CustomerID, FirstName
FROM Sales.Customers
ORDER BY FirstName DESC;

-- Create index to eliminate Sort
CREATE NONCLUSTERED INDEX idx_Customers_FirstName_Desc
ON Sales.Customers (FirstName DESC);

/*
   Stream Aggregate
   ================
   - Aggregates pre-sorted input
   - Cost: Very efficient, single pass
   - Requires input to be sorted by GROUP BY column
   
   When Used:
   - Input is already sorted
   - Grouped by indexed column
*/

-- Efficient aggregation with proper index
SELECT 
    CountryRegionCode,
    COUNT(*) as CustomerCount
FROM Sales.Customers
GROUP BY CountryRegionCode
ORDER BY CountryRegionCode;

/*
   Hash Aggregate
   ==============
   - Uses hash table to group rows
   - Cost: Moderate, requires memory
   - No sorting requirement on input
   
   When Used:
   - Input not sorted
   - No suitable index
   - Memory available
*/

-- May use Hash Aggregate
SELECT 
    FirstName,
    COUNT(*) as NameCount
FROM Sales.Customers
GROUP BY FirstName;

/*
   Filter
   ======
   - Applies WHERE condition to rows
   - Cost: Low per row, but multiplied by row count
   - Appears before aggregations if filtering needed
   
   When Used:
   - Additional filtering after other operations
   - HAVING clause conditions
*/

-- Shows Filter operator after aggregation
SELECT 
    CountryRegionCode,
    COUNT(*) as CustomerCount
FROM Sales.Customers
GROUP BY CountryRegionCode
HAVING COUNT(*) > 10;

/*
   Top
   ===
   - Limits result set to specified number of rows
   - Cost: Very low, stops processing after limit reached
   - Optimization: Can stop index seek early
   
   Efficient TOP:
   - With ORDER BY matching index
   - Processes minimum rows needed
*/

-- Efficient TOP with matching index
SELECT TOP 10
    CustomerID,
    FirstName
FROM Sales.Customers
WHERE CountryRegionCode = 'US'
ORDER BY CustomerID DESC;

/* ==============================================================================
   4. UNDERSTANDING COSTS AND STATISTICS
============================================================================== */

/*
   Key Execution Plan Metrics:
   ===========================
   
   Estimated Rows vs Actual Rows:
   - Large discrepancies indicate outdated statistics
   - Can lead to poor plan choices
   - Solution: Update statistics with sp_updatestats
   
   Estimated Subtree Cost:
   - Relative cost (not actual time in milliseconds)
   - Higher number = more expensive operation
   - Used by optimizer to choose between plans
   - Compare relative costs between operations
   
   I/O Statistics (from SET STATISTICS IO):
   - Logical Reads: Pages read from memory/disk
   - Physical Reads: Pages read from disk
   - Read-Ahead Reads: Sequential read-ahead operations
   - Lob Logical Reads: Large object reads
   
   CPU Statistics (from SET STATISTICS CPU):
   - CPU time: Milliseconds of CPU processing
   - Elapsed time: Wall clock time
   - Discrepancy indicates waits or blocking
*/

-- Enable all statistics for detailed analysis
SET STATISTICS IO ON;
SET STATISTICS TIME ON;
SET STATISTICS CPU ON;

SELECT 
    CustomerID,
    FirstName,
    LastName,
    CountryRegionCode
FROM Sales.Customers
WHERE CountryRegionCode = 'US'
  AND YEAR(ModifiedDate) = 2023;

SET STATISTICS IO OFF;
SET STATISTICS TIME OFF;
SET STATISTICS CPU OFF;

-- Update statistics if estimates are far off
UPDATE STATISTICS Sales.Customers;
-- Or specific index:
UPDATE STATISTICS Sales.Customers (idx_Customers_Country);

/* ==============================================================================
   5. IDENTIFYING MISSING INDEXES
============================================================================== */

/*
   SQL Server provides Dynamic Management Views (DMVs) to identify missing indexes:
   
   sys.dm_db_missing_index_details - Details of missing indexes
   sys.dm_db_missing_index_groups - Groups of similar missing indexes
   sys.dm_db_missing_index_groups_stats - Statistics on missing indexes
*/

-- Query to find missing indexes with impact
SELECT TOP 20
    CONVERT(DECIMAL(18,2), 
        migs.avg_total_user_cost * migs.avg_user_impact * (migs.user_seeks + migs.user_scans)
    ) AS Improvement,
    mid.equality_columns,
    mid.inequality_columns,
    mid.included_columns,
    migs.user_seeks,
    migs.user_scans,
    migs.user_lookups,
    mid.statement
FROM sys.dm_db_missing_index_details mid
INNER JOIN sys.dm_db_missing_index_groups mig ON mid.index_handle = mig.index_handle
INNER JOIN sys.dm_db_missing_index_groups_stats migs ON mig.index_group_id = migs.group_handle
WHERE database_id = DB_ID()
ORDER BY Improvement DESC;

-- Query to find unused indexes
SELECT 
    OBJECT_NAME(i.object_id) AS TableName,
    i.name AS IndexName,
    ius.user_seeks,
    ius.user_scans,
    ius.user_lookups,
    ius.user_updates
FROM sys.indexes i
LEFT JOIN sys.dm_db_index_usage_stats ius 
    ON i.object_id = ius.object_id 
    AND i.index_id = ius.index_id
    AND ius.database_id = DB_ID()
WHERE OBJECTPROPERTY(i.object_id, 'IsUserTable') = 1
  AND i.index_id > 0  -- Exclude heaps
ORDER BY COALESCE(ius.user_seeks, 0) + COALESCE(ius.user_scans, 0) + COALESCE(ius.user_lookups, 0);

/* ==============================================================================
   6. QUERY OPTIMIZATION TECHNIQUES
============================================================================== */

-- Technique 1: Use SARGable Predicates (Search Argument Able)
-- =========================================================

-- BAD: Function on column prevents index seek
SELECT CustomerID, FirstName
FROM Sales.Customers
WHERE YEAR(ModifiedDate) = 2023;

-- GOOD: Direct comparison allows index seek
SELECT CustomerID, FirstName
FROM Sales.Customers
WHERE ModifiedDate >= '2023-01-01'
  AND ModifiedDate < '2024-01-01';

-- Technique 2: Avoid OR with different columns
-- ============================================

-- BAD: May cause table scan
SELECT CustomerID, FirstName
FROM Sales.Customers
WHERE CountryRegionCode = 'US'
   OR CountryRegionCode = 'CA'
   OR CountryRegionCode = 'MX';

-- GOOD: Use IN for better optimization
SELECT CustomerID, FirstName
FROM Sales.Customers
WHERE CountryRegionCode IN ('US', 'CA', 'MX');

-- Technique 3: Filter early in the query
-- ======================================

-- BAD: Joins all rows then filters
SELECT 
    c.CustomerID,
    o.OrderID
FROM Sales.Customers c
INNER JOIN Sales.Orders o ON c.CustomerID = o.CustomerID
WHERE c.CountryRegionCode = 'US';

-- GOOD: Filter customer first (if many customers)
SELECT 
    c.CustomerID,
    o.OrderID
FROM Sales.Customers c
INNER JOIN Sales.Orders o ON c.CustomerID = o.CustomerID
WHERE c.CountryRegionCode = 'US';
-- The optimizer should recognize this and push filter down

-- Technique 4: Use Covering Indexes
-- ==================================

-- Non-covering index (requires key lookup)
CREATE NONCLUSTERED INDEX idx_Customers_Country_NonCovering
ON Sales.Customers (CountryRegionCode);

-- Query requires lookup to get FirstName
SELECT CountryRegionCode, FirstName
FROM Sales.Customers
WHERE CountryRegionCode = 'US';

-- Covering index (includes all needed columns)
DROP INDEX idx_Customers_Country_NonCovering ON Sales.Customers;

CREATE NONCLUSTERED INDEX idx_Customers_Country_Covering
ON Sales.Customers (CountryRegionCode)
INCLUDE (FirstName, LastName);

-- Same query now uses only index, no lookup
SELECT CountryRegionCode, FirstName
FROM Sales.Customers
WHERE CountryRegionCode = 'US';

-- Technique 5: Use Composite Indexes Wisely
-- =========================================

-- Composite index with good column order
CREATE NONCLUSTERED INDEX idx_Customers_Composite
ON Sales.Customers (CountryRegionCode, CustomerID)
INCLUDE (FirstName);

-- Uses index efficiently (follows leftmost prefix rule)
SELECT FirstName, CustomerID
FROM Sales.Customers
WHERE CountryRegionCode = 'US'
  AND CustomerID > 500;

-- Does NOT use index efficiently (wrong column order)
SELECT FirstName
FROM Sales.Customers
WHERE CustomerID > 500
  AND CountryRegionCode = 'US';

-- Technique 6: Avoid SELECT *
-- ===========================

-- BAD: Returns all columns, may not use covering index
SELECT *
FROM Sales.Customers
WHERE CountryRegionCode = 'US';

-- GOOD: Specify needed columns, allows index optimization
SELECT CustomerID, FirstName, CountryRegionCode
FROM Sales.Customers
WHERE CountryRegionCode = 'US';

-- Technique 7: Consider Index Hints (use sparingly)
-- ================================================

-- Force use of specific index (usually optimizer is smarter)
SELECT CustomerID, FirstName
FROM Sales.Customers WITH (INDEX(idx_Customers_Country_Covering))
WHERE CountryRegionCode = 'US';

-- Force index seek instead of scan
SELECT CustomerID, FirstName
FROM Sales.Customers WITH (FORCESEEK)
WHERE CountryRegionCode = 'US'
  AND CustomerID > 1000;

/* ==============================================================================
   7. COMMON PERFORMANCE ISSUES AND SOLUTIONS
============================================================================== */

-- Problem 1: Implicit Type Conversion
-- ===================================

-- BAD: Comparing string to int causes scan
SELECT CustomerID
FROM Sales.Customers
WHERE CustomerID = '5';  -- String literal

-- GOOD: Matching data types
SELECT CustomerID
FROM Sales.Customers
WHERE CustomerID = 5;  -- Integer literal

-- Problem 2: Excessive JOIN Operations
-- ===================================

-- Check execution plan complexity with multiple joins
SELECT 
    c.CustomerID,
    c.FirstName,
    o.OrderID,
    od.OrderDetailID,
    p.ProductName
FROM Sales.Customers c
INNER JOIN Sales.Orders o ON c.CustomerID = o.CustomerID
INNER JOIN Sales.OrderDetails od ON o.OrderID = od.OrderID
INNER JOIN Production.Products p ON od.ProductID = p.ProductID
WHERE c.CountryRegionCode = 'US'
  AND o.OrderDate >= '2013-01-01';

-- Problem 3: Subquery in WHERE Clause
-- ===================================

-- Potential performance issue with correlated subquery
SELECT c.CustomerID, c.FirstName
FROM Sales.Customers c
WHERE EXISTS (
    SELECT 1
    FROM Sales.Orders o
    WHERE o.CustomerID = c.CustomerID
      AND o.OrderDate >= '2013-01-01'
);

-- Better: Use JOIN
SELECT DISTINCT c.CustomerID, c.FirstName
FROM Sales.Customers c
INNER JOIN Sales.Orders o ON c.CustomerID = o.CustomerID
WHERE o.OrderDate >= '2013-01-01';

-- Problem 4: GROUP BY All Columns
-- ==============================

-- Inefficient: Groups by unnecessary columns
SELECT 
    c.CustomerID,
    c.FirstName,
    c.LastName,
    COUNT(*) as OrderCount
FROM Sales.Customers c
INNER JOIN Sales.Orders o ON c.CustomerID = o.CustomerID
GROUP BY c.CustomerID, c.FirstName, c.LastName;

-- Better: Group by minimal columns
SELECT 
    c.CustomerID,
    COUNT(*) as OrderCount
FROM Sales.Customers c
INNER JOIN Sales.Orders o ON c.CustomerID = o.CustomerID
GROUP BY c.CustomerID;

-- Problem 5: Index Fragmentation
-- ==============================

-- Check fragmentation
SELECT 
    OBJECT_NAME(ips.object_id) AS TableName,
    i.name AS IndexName,
    ips.avg_fragmentation_in_percent,
    ips.page_count
FROM sys.dm_db_index_physical_stats(DB_ID(), NULL, NULL, NULL, 'LIMITED') ips
INNER JOIN sys.indexes i ON ips.object_id = i.object_id 
    AND ips.index_id = i.index_id
WHERE ips.avg_fragmentation_in_percent > 10
  AND ips.page_count > 1000
ORDER BY ips.avg_fragmentation_in_percent DESC;

-- Defragment index (reorganize for < 30%, rebuild for > 30%)
ALTER INDEX idx_Customers_Country_Covering ON Sales.Customers REORGANIZE;
ALTER INDEX idx_Customers_Country_Covering ON Sales.Customers REBUILD;

/* ==============================================================================
   8. BEST PRACTICES FOR QUERY PERFORMANCE
============================================================================== */

/*
   Execution Plan Best Practices:
   ==============================
   
   1. Always use Actual Execution Plan
      - Estimated plans may differ from actual
      - Shows real row counts and timings
      - Key for identifying mismatch between estimates and reality
   
   2. Look for Red Warning Symbols
      - Indicate operations that exceeded threshold
      - Common: Sort with large memory spill, missing index hints
      - Address immediately as these are performance killers
   
   3. Compare Operator Costs
      - Largest bars/percentages are biggest resource consumers
      - Focus optimization efforts on top-cost operations
      - Sometimes small optimization to costly operation helps most
   
   4. Check Estimated vs Actual Row Counts
      - Large discrepancies indicate stale statistics
      - Use UPDATE STATISTICS to refresh
      - Poor estimates lead to poor plan choices
   
   5. Identify Table Scans
      - Every table scan is potential optimization opportunity
      - Add index if single-column filter
      - Verify index design for multi-column filters
   
   6. Check for Key Lookups
      - Indicates non-covering index
      - Add columns to INCLUDE clause
      - One lookup per row can be expensive at scale
   
   7. Verify Index Seek Usage
      - Index Seek is almost always better than Scan
      - Ensure WHERE clause matches index design
      - Avoid functions on indexed columns
   
   8. Monitor Join Order
      - Optimizer chooses join order to minimize cost
      - Typically joins smaller result set first
      - Verify expectations match actual execution
   
   9. Watch for Blocking and Waits
      - Difference between CPU time and elapsed time
      - Indicates other queries blocking this one
      - Check sys.dm_exec_requests for blockers
   
   10. Use Statistics DMVs
       - Identify missing indexes with sys.dm_db_missing_index_*
       - Find unused indexes with sys.dm_db_index_usage_stats
       - Track index fragmentation
       - Monitor query compile time
*/

-- Example: Comprehensive Performance Analysis Query
SELECT TOP 20
    qt.text AS QueryText,
    qs.execution_count,
    qs.total_elapsed_time / 1000 AS TotalElapsedTime_ms,
    qs.avg_elapsed_time / 1000 AS AvgElapsedTime_ms,
    qs.total_physical_reads,
    qs.total_logical_reads
FROM sys.dm_exec_query_stats qs
CROSS APPLY sys.dm_exec_sql_text(qs.sql_handle) qt
WHERE qt.text NOT LIKE '%sys.%'
ORDER BY qs.total_elapsed_time DESC;

-- Clear query cache if needed (use carefully!)
-- DBCC DROPCLEANBUFFERS;
-- DBCC FREEPROCCACHE;