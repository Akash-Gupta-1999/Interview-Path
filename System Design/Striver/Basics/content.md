-   Scalability : Scalability is the ability of a system to handle increasing workload or demand by adding resources without compromising performance.
    -   Vertical Scaling : Increasing the capacity of a single machine (like adding more CPU, RAM, or storage) to improve system performance.
    -   Horizontal Scaling : Adding more machines or servers to a system so it can handle greater loads in parallel.

    -   Pro's and con's
        1.  HS requires load balancer for requests while VS not.
        2.  VS is single point of failure while HS is resilient
        3.  VS will be fast as there will be interprocess communication while HS will be bit slow due to network calls between servers (Remote Procedure Calls)
        4.  Data Consistency is Issue in HS while in VS is not
        5.  VS has a hardware limit to which we can increase while HS can be scaled to a larger extent.

-   Estimation Questions

    1.  How much Data needed by youtube in a day ?
        -   No. of Users -> 1 Billion
        -   Ratio of uploaders : users -> 1:1000
        -   No. of Uploaders = 1B/1000 = 1M
        -   AVG length of Video -> 10 Min
        -   Total Upload Video -> 10 * 1M = 10M minutes

        -   2hr Movie avg size -> 4gb
        -   optimized codec and compression size = 90%
        -   2hr youtube video avg size -> 4/10 = 0.4 GB
        -   1 Minute youtube avg video size -> 0.4/120 GB = 3 MB

        -   Answer : Total video size = 10M * 3MB = 30 TB

        Note : need replica of db for reseleinece and cdn, also think about Various resolution of videos to store

    2.  Estimate Cache Requirements for Video Metadata
        Metadata in cache will be those which will be visible to users : thumbnail,description,image
        we will think about image as that will only be costly
        -   1MB each image -> to store compress it to 10Kb
        -   number of videos will be last 90 day video + popular video
            10kb * 90 * 1M = 1TB RAM
        -   1 Node with 16gb we take so we need approx 64 nodes for ITB RAM
        -   we need replication, and resilience = 64*3*2 = approx 500 nodes
    
    3.  Estimate number of processors requires to process Videos
        -   1 Million videos per day with avg 10 min length
        -   10^7 minutes per day ==> 10^4 gb per day (Assuming 1hr video to be 1gb) ==> approx 40 mb/sec
        -   for processing => u need to read+process+write
        -   bump 40 mb/sec to 400mb/sec for cdn,resilience
        -   assume 10millisecond for read and double to write, for processing to be 20ms
        -   Total ==> 10+20+20 = 50ms for 1MB of Data
        -   400 * 50 * 10^-3 sec/sec ==> need 20 second per second -> need parallel 20 computers
        -   bump to 40 for efficiency and localization

-   HTTP vs HTTPS
    -   HTTP (HyperText Transfer Protocol)
        -   Application layer protocol used to access and transfer data (text, images, videos, etc.) on the web.
        -   Works on a client–server model using the request/response mechanism.
        -   Runs over TCP and uses port 80.
        -   In HTTP, the client sends a request message to the server. After the client responds, HTTP establishes a TCP connection between the client and the server. HTTP delivers a request to the server, which collects the data that was requested. After the server sends data to the client, the connection will be terminated.
        -   If we want something else from the server, we should have to re-establish the connection between client and server.
        -   Connectionless: Each request opens and closes its own connection.
        -   Stateless: Server doesn't retain information about previous requests.
        -   Media independent: Can transfer any type of data understood by client & server.

    -   HTTPS (HyperText Transfer Protocol Secure)
        -   Secure version of HTTP.
        -   Encrypts data using TLS (formerly SSL) to protect sensitive information (credentials, payments, etc.).
        -   Ensures confidentiality, integrity, and authentication.
        -   Uses port 443 for communication.

-   Layers of TCP/IP Model
    1. Physical Layer
        -   Converts bits into signals for transmission.
        -   Signal types depend on media:
            -   Electrical (copper cables)
            -   Light (optical fibers)
            -   Radio waves (wireless)
        -   Defines:
            -   Topology: bus, star, hybrid, mesh, ring
            -   Line configuration: point-to-point, multipoint
            -   Transmission modes: simplex, half-duplex, full-duplex

    2. Data Link Layer (DLL)
        -   Subdivided into MAC and LLC.
        -   MAC (Media Access Control)
            -   Responsible for framing IP packets into frames.
            -   Adds:
                -   Header → source & destination MAC addresses
                -   Trailer → error-check bits
        -   LLC (Logical Link Control)
            -   Flow control – prevents sender from overwhelming receiver.
            -   Error control – detects transmission errors using trailer bits.

    3. Network Layer
        -   Adds IP address (logical address) to data to create IP packets.
        -   Finds best possible path for packet delivery.
        -   Key Protocols
            -   IP (Internet Protocol):
                -   Routes packets using destination IP.
                -   Handles fragmentation & reassembly.
                -   Unreliable (no guarantee of delivery or error checking).
            -   ARP (Address Resolution Protocol):
                -   Resolves IP address → MAC address.
            -   ICMP (Internet Control Message Protocol):
                -   Handles error reporting.

    4. Transport Layer
        -   Provides end-to-end communication, flow control, and error handling.
        -   TCP (Transmission Control Protocol)
            -   Connection-oriented.
            -   Breaks data into segments and assigns sequence numbers.
            -   Reliable: retransmissions, ordering, error detection.
        -   UDP (User Datagram Protocol)
            -   Connectionless.
            -   No error checking, or recovery.
            -   Faster but less reliable.

    5. Application Layer (Combines OSI’s application, presentation, and session layers.)
        -   Interface for users to access network services.
        -   Common Protocols
            -   HTTP – Access web content.
            -   DNS – Converts domain names to IP addresses.
            -   SMTP – Sends emails.
            -   FTP – Transfers files.
            -   TELNET – Remote terminal access.

-   What are Relational Databases? (Concise)

    A relational database is a type of database that stores data in tables (relations) consisting of rows and columns. It uses primary keys, foreign keys, and relationships to maintain data integrity. Relational databases support SQL for querying and allow efficient storage, retrieval, and manipulation of structured data.

    Examples: MySQL, PostgreSQL, Oracle, SQL Server.

    NOTE : Bigquery is columnar db not traditional rdbms as it uses some features of rdbms, columnar db are generally used for anlytics for higher scaling as data stored in column rather than rows. in rdbms it is stored in rows so it is called oltp and bigquery is called olap

-   What are NoSQL Databases?

    NoSQL (Not Only SQL) refers to a group of databases that do not follow the traditional relational model.
    They are designed for:
        High scalability
        Distributed systems
        Handling big data
        Flexible schema (schema-less or semi-structured)

    Unlike SQL databases that use tables and strict schemas, NoSQL allows storing data in flexible formats like documents, key-value pairs, wide columns, graphs, etc.

    NoSQL vs SQL: Advantages & Disadvantages

    ✔ Advantages of NoSQL over SQL
    1. Horizontal Scalability
        -   Designed for distributed clusters
        -   Add more machines → instantly increase capacity
        -   Ideal for massive data systems (Google, Facebook, Netflix)

    2. Flexible Schema
        -   No fixed tables or schema
        -   Store JSON, key-value, nested objects
        -   Easy to evolve features without migrations

    3. High Performance
        -   Reads/writes distributed across nodes
        -   Low latency due to data partitioning & replication

    4. Handles Big Data Efficiently
        -   Supports very large volumes (TB → PB)
        -   Optimized for high write throughput

    5. Fault Tolerance
        -   Replication across multiple nodes/data centers
        -   System stays functional even if nodes fail

    ✘ Disadvantages of NoSQL
    1. Weaker ACID Guarantees
        -   Supports eventual consistency instead of strict consistency
        -   Transactions are limited (no JOINs, foreign keys)

    2. Limited Querying
        -   No JOINs
        -   Complex queries harder
        -   Querying depends on DB type (key-value, document, etc.)

    3. Less Standardization
        -   SQL is universal; NoSQL APIs differ widely
        -   Harder learning curve across databases

    4. Data Duplication
        -   Due to denormalization
        -   Developer must handle consistency
    NOTE: Reads are slower compared to RDBMS in cases. but it largely varies on types of NoSQL

    -   4 Major Types of NoSQL:

    1. Key–Value Stores
        -   Simple NoSQL type where data is stored as: key → value
        -   The value is usually opaque (JSON, binary, string, etc.).
        -   When to Use: Ultra-fast reads/writes, Caching, Session data, Real-time lookups
        -   Strengths:
            -   Extremely fast (O(1) lookups)
            -   Very easy to scale horizontally
            -   Good for large workloads
        -   Weaknesses:
            -   No complex querying
            -   No relationships
        -   Examples: Redis, Amazon DynamoDB, Memcached

    2. Document Databases
        -   Store semi-structured data as documents (usually JSON/BSON).
        -   Example:
            {
            "user_id": 7,
            "name": "Akash",
            "games": ["Elden Ring", "Cyberpunk 2077"],
            "address": { "city": "Pune", "pin": 411001 }
            }
        -   When to Use:
            -   When your data is flexible (schema changes often)
            -   Nested data
            -   Content management, product catalogs, user profiles
        -   Strengths
            -   Flexible schema
            -   Hierarchical data fits naturally
            -   Powerful indexing and aggregations
        -   Weaknesses
            -   Complex ACID transactions can be limited
            -   Joins are difficult (denormalization required)
        -   Examples: MongoDB, Couchbase, Amazon DocumentDB

    3. Wide-Column (Column-Family) Stores
        -   Inspired by Google BigTable.
        -   Data is stored in tables → column families → rows, but columns can vary per row.
            Column Family
            └── Rows
                └── Columns (key → value pairs)
            Think of a column family as a table, but with a major difference: 
                -   Each row can have a different set of columns
                -   Rows are not required to have the same columns like in SQL.
        -   Typical schema:
            Column Family: user_login_events
            Row key: user_id
                user_123:
                    1710000101: "login"
                    1710000300: "logout"
                    1710000450: "login"
                user_897:
                    1710000200: "login"
        -   When to Use
            -   Write-heavy workloads
            -   Time-series data
            -   IoT data at scale
            -   Logging, analytics
        -   Strengths
            -   Very high write throughput
            -   Horizontally scalable
            -   Tunable consistency (ex: Cassandra quorum)
        -   Weaknesses
            -   Not suitable for ad-hoc queries
            -   Requires modeling based on query patterns
        -   Examples: Apache Cassandra, HBase, Google Bigtable

    4. Graph Databases
        -   Represent data as nodes → edges → relationships.
        -   Example: (Akash) - follows -> (Gaming Channel)
        -   When to Use
            -   Social networks
            -   Recommendation systems
            -   Fraud detection
            -   Knowledge graphs
        -   Strengths
            -   Fast traversal of relationships
            -   Natural modeling of complex graphs
        -   Weaknesses
            -   Not good for large analytical queries
            -   Harder to scale horizontally than Cassandra or Dynamo
        -   Examples: Neo4j, Amazon Neptune, ArangoDB

-   A CaseStudy of Cassandra DB as a column-wide NoSQL DB:

    -   Problem Scenario:
        A large-scale application (e.g., an e-commerce analytics platform) needs:
        -   Very high write throughput (millions of events/min)
        -   Zero downtime (24×7)
        -   Linear scalability across data centers
        -   Tunable consistency
        -   Fast time-series lookups
        Cassandra is chosen because of its distributed, decentralized, highly available design.

    1. Cassandra Cluster Architecture
        -   Distributed Ring Architecture
            -   All nodes are arranged logically in a ring.
            -   Each node is responsible for part of the data, determined by consistent hashing.
            -   No central coordinator or master.
                Node A ── Node B ── Node C ── Node D ── Node E (Ring)
        -   No Master Node
            -   Every node is equal.
            -   No single point of failure.
            -   Any node can handle reads/writes.
        -   Data Partitioning
            -   Cassandra uses consistent hashing to map a row key to a token range.
            -   Example:
                Row key: user_103
                Mapped to hash(token) → stored on Node C
        -   Replication Across Nodes
            -   Replication Factor (RF) determines how many nodes store each row.
            -   RF = 3 → data is stored on 3 different nodes.
            -   This ensures:
                High availability
                Fault tolerance
                Geographic resilience (with multi-DC replication)

    2. Cassandra Write Path (High Write Performance)
        Step-by-Step Write Flow:
        -   Client sends a write request to any node
            → This node becomes the Coordinator for the request.
        -   Coordinator writes the data to the Commit Log
            Durable, sequential disk write.
            Protects data from crashes.
        -   Data also goes to Memtable (in-memory structure)
            Acts like an in-memory sorted table.
        -   When Memtable fills → flushed to SSTables
            SSTables = immutable disk files. (Sorted String Table)
            Organized for fast sequential reads.
        -   Background Compaction
            Merges SSTables to reduce fragmentation.

        Result:
            Cassandra achieves very fast writes since it uses:
            -   append-only commit logs
            -   in-memory memtables
            -   no read-before-write

    3. Cassandra Read Path
        Step-by-Step Read Flow:
        -   Client sends read to a Coordinator node.
        -   Coordinator checks in this order:
            -   Memtable
            -   SSTable indexes
            -   Bloom filters (to skip SSTables that don’t contain the row)
            -   Partition index + data file
        -   Data from multiple SSTables is merged to return final result.

        Why reads are efficient:
        -   Bloom filters eliminate unnecessary disk I/O.
        -   Data is indexed per partition.
        -   Memtable often contains recent writes.

    4. Replication Model
        Assume: Replication Factor RF = 3
        This means:
        -   Each row is stored on 3 different nodes.
        -   These nodes are chosen based on token ranges around the ring.

        Example:
        Row Key HASH → Primary Node B
        Replicas → Node C, Node D

        This ensures:
        -   A single node failure does NOT cause data loss.
        -   Reads/Writes still succeed with remaining replicas.

    5. Cassandra Quorum Consistency
        Cassandra supports tunable consistency.
        You can choose how many nodes must ACK a read/write.

        For RF = 3:

        Write QUORUM
            -   Requires 2 out of 3 replicas to confirm.
            -   Ensures write is propagated to a majority.

        Read QUORUM
            -   Requires 2 out of 3 nodes to respond.
            -   Coordinator merges results & picks latest timestamp version.

    6. Consistency Rule: R + W > RF
        To achieve strong consistency: R + W > RF

        Example:
        Read QUORUM = R = 2
        Write QUORUM = W = 2
        Replication Factor = RF = 3

        Check rule:

        2 + 2 > 3   → TRUE
        ✔ Strong consistency achieved

        This means:
            A write is guaranteed to be visible for a QUORUM read.
            No stale reads.

    7. End-to-End Example (Mini Case Study)
        Use Case: User Activity Logging
        You store user page views with schema: PRIMARY KEY (user_id, timestamp)
        
        Flow of an Insert (Write)
            User "A123" visits page:

            INSERT INTO user_events (user_id, ts, page)
            VALUES ('A123', 1710000011, '/cart');

            Write steps:
                -   Client sends to Node X
                -   Node X → coordinator
                -   Write to commit log
                -   Write to memtable
                -   Replicate to 2 more nodes (because RF=3)
                -   Write considered successful when 2 nodes ACK (QUORUM)

        Flow of a Read
            Query all events of user A123:

            SELECT * FROM user_events WHERE user_id='A123';

            Read steps:
                -   Coordinator asks 2 replicas (QUORUM)
                -   They return their latest SSTable/Memtable data
                -   Coordinator reconciles timestamps
                -   Client gets strongly consistent answer

    8. Why Cassandra Works Well for This Case
        ✔ Zero downtime: Even if 1–2 nodes fail, QUORUM still works.
        ✔ High write throughput: Suitable for time-series/logs.
        ✔ Linear horizontal scalability: Add more nodes → system gets faster.
        ✔ Tunable consistency
            Choose:
            -   QUORUM for accuracy
            -   ONE for speed
            -   ALL for strict consistency
        ✔ Geographical replication: Multi-datacenter support is native.

-   What is Indexing in DB?
    An index is like a book index. Instead of searching the whole book. You look at the index → instantly find page number
    Same for databases:
        Without index → scan entire table (slow)
        With index → jump directly to data (fast)

    -   Indexing in SQL Databases (RDBMS):
        SQL databases follow a strict schema and store data in tables.
        ✔ How a SQL Index Works:
        -   SQL uses B-Tree / B+Tree indexes.
            Sorted Tree
            ├── 10
            ├── 20
            └── 30
        
        -  Scenario:
            CREATE TABLE users (
                id INT PRIMARY KEY,
                name VARCHAR(50),
                email VARCHAR(100)
            );

            CREATE INDEX idx_email ON users(email);
            You now have an index on the email column.

            🟩 What happens in the background
            1. Index Creation
                -   The database creates a B-Tree (or B+Tree) for the email column.
                -   Each node of the tree contains:
                    -   The email value
                    -   A pointer to the actual row location on disk (row ID / primary key reference)
                    -   B-Tree Example:
                        "k@example.com"
                        /           \
                    "b@example.com"  "z@example.com"
                -   The tree is sorted by email.
                -   Leaf nodes point to the actual data in the users table.

            2. Inserting a New Row
                INSERT INTO users (id, name, email) VALUES (1, 'Akash', 'a@example.com');
                Steps:
                -   Insert row into table data on disk.
                -   Insert email into B-Tree index:
                    -   Traverse B-Tree to correct leaf node.
                    -   Add a pointer to the new row.
                -   Maintain tree balance (split nodes if necessary).

                ✅ Result: Index allows fast search by email without scanning the entire table.

            3. Searching by Email
                SELECT * FROM users WHERE email = 'a@example.com';
                Steps:
                -   SQL engine checks B-Tree index first.
                -   Navigates through tree nodes (O(log n) search).
                -   Finds pointer to row in table.
                -   Fetches the full row data from table.
                ✅ Result: No full table scan, fast retrieval.

            4. Updating Email
                UPDATE users SET email='b@example.com' WHERE id=1;
                Steps:
                -   Update value in the table row.
                -   Remove old value from index.
                -   Insert new value in index at correct position.
                ✅ Result: Index remains consistent with table data.

            5. Deleting a Row
                DELETE FROM users WHERE id=1;
                Steps:
                -   Remove row from table.
                -   Remove corresponding entry from B-Tree index.
    
        -   SQL Indexes Are Strong Because:
            -   Relation: Indexes help join tables quickly
            -   Range queries: B-tree supports min–max efficiently
            -   Complex queries: Optimizer uses multiple indexes
            -   ACID: Index changes are fully consistent
    
    -   Indexing in NoSQL
        NoSQL databases have different types and indexing support depends on the model.

    1. Key-Value Stores
        -   Examples: Redis, Riak, DynamoDB
        -   Indexing Support: Limited / optional (Not needed as much as they used for key-value only for faster lookups like hashmap)

    2. Document Stores
        -   Examples: MongoDB, Couchbase
        -   Indexing Support: Yes
        -   How it Works:
            -   Primary index: _id field (default) → allows fast document retrieval.
            -   Secondary index: user-defined fields → B-Tree or similar structures.
            -   Supports compound indexes (Index multiple fields together to optimize queries involving more than one field), text indexes, geospatial indexes.
        -   Notes: Reads are faster for indexed fields; write performance can slightly degrade due to index updates.

    3. Column-Family Stores
        -   Examples: Cassandra, HBase
        -   Indexing Support: Yes (primary & secondary indexes)
        -   How it Works:
            -   Primary key(also known as partition key): data partitioned across nodes via hashing → direct access.
            -   Secondary index(clustering key): separate hidden index tables mapping column value → primary key.
            -   Queries on indexed columns first consult the index table.
        -   Notes: Optimized for write-heavy workloads; secondary indexes add read overhead in distributed setups.

    4. Graph Databases
        -   Examples: Neo4j, JanusGraph
        -   Indexing Support: Yes (node & edge properties)
        -   How it Works:
            -   Uses B-Trees or Lucene-based indexes for node/edge property lookup.
            -   Traversals leverage adjacency lists rather than full graph scan.
        -   Notes: Indexing improves lookup speed but graph traversal is still key for relationships.

-   Cache
    A cache is a high-speed storage layer that stores a subset of data, typically transient, so that future requests for that data can be served faster than accessing the primary storage (e.g., database or disk).
    -   Acts as a temporary memory between the CPU/application and slower storage.
    -   Reduces latency and improves system performance.

    -   Purpose of Caching
        -   Speed up data access: Frequently used data can be retrieved quickly.
        -   Reduce load: Minimizes repeated expensive operations (like database queries or API calls).
        -   Enhance scalability: Helps handle more requests efficiently.
    
    -   Principle: Locality of Reference
        -   Caches exploit the locality of reference, which comes in two types:
            -   Temporal Locality: Recently accessed data is likely to be accessed again soon.
                Example: Accessing the same database row multiple times in a session.
            -   Spatial Locality: Data near recently accessed data is likely to be accessed soon.
                Example: Sequential reading of array elements or files on disk.
        -   Locality allows caches to predict which data to store for faster access.

    -   Cache Filling (How Data Gets Into Cache)
        -   On-demand / Lazy Loading:
            -   Data is loaded into cache only when requested (cache miss).
        -   Prefetching / Speculative Loading:
            -   Data is loaded before it’s requested based on patterns or locality.
            -   Useful when sequential access is expected (spatial locality).
        -   Write Policies (for caches that handle writes)
            -   Write-through: Data is written to cache and main storage simultaneously.
            -   Write-back: Data is written to cache first and committed to storage later.
            -   Write-around: Data is written directly to storage, bypassing cache.

    -   Where Cache Exists
        -   CPU Cache (L1, L2, L3) – Very fast memory near the CPU.
        -   Application Cache – Redis, Memcached storing frequently used DB results.
        -   Web Cache – Browser cache or CDN caching website assets.
        -   Database Cache – Query results or table rows cached to reduce DB hits.

    -   Cache Mechanisms
        -   In-Memory Cache: Stored in RAM, very fast (Redis, Memcached).
        -   Disk Cache: Stored on SSD/HDD, slower than memory but faster than original source.
        -   Distributed Cache: Shared cache across multiple servers to scale applications.
    
    -   Cache Policies
        -   Cache Hit: Requested data is found in cache → served quickly.
        -   Cache Miss: Data not in cache → fetch from source, store in cache for future.

    -   Eviction Policies (When Cache is Full):
        -   LRU (Least Recently Used): Remove the least recently accessed item.
        -   LFU (Least Frequently Used): Remove the least accessed item over time.
        -   FIFO (First In, First Out): Remove the oldest cached item.

    -   Examples
        -   Redis caching API responses.
        -   Browser storing images/scripts for faster page reloads.
        -   CPU L1 cache storing instructions and frequently used data.

-   what is Thrashing?
    Thrashing is a situation in an operating system where the CPU spends most of its time swapping pages in and out of memory rather than executing actual processes.

    It occurs when there is insufficient physical memory (RAM) to handle active processes efficiently. Leads to dramatic performance degradation.

    -   How Thrashing Happens
        -   Processes require more memory than physically available.
        -   Pages are frequently swapped between RAM and disk (page faults occur continuously).
        -   CPU utilization drops because it waits for I/O operations instead of executing processes.
        -   Key idea: High page fault rate → excessive paging → CPU spends time managing memory instead of doing useful work.

    -   Causes of Thrashing
        -   Overcommitment of memory: Too many processes running simultaneously.
        -   Large working sets: Processes require more pages than available in RAM.
        -   Poor page replacement strategy: Inefficient algorithms cause frequent swapping.
        -   Sudden spike in memory demand by one or more processes.

    -   Symptoms of Thrashing
        -   Low CPU utilization despite high system activity.
        -   High disk I/O (hard disk constantly active).
        -   Processes run extremely slowly.
        -   System appears unresponsive or sluggish.

    -   Avoiding Thrashing
        -   Working Set Model: Keep the working set (set of actively used pages) of each process in memory.
        -   Load Control: Limit the number of processes admitted to the system to match memory capacity.
        -   Better Page Replacement Algorithms: Use LRU or LFU to keep frequently used pages in memory.
        -   Increase Physical Memory: Add more RAM to reduce page faults.
        -   Program Optimization: Reduce memory footprint of processes.

    -   Summary: Thrashing = too much paging → low CPU productivity → system slowdown.

-   what are Threads ?
    A thread is the smallest unit of execution within a process.
    -   Multiple threads can exist within a single process, sharing process resources like memory and files.
    -   Threads are sometimes called lightweight processes because they have their own execution context but share most of the process resources.

    -   Components of a Thread
        Each thread has its own:
        -   Program Counter (PC) – tracks the next instruction to execute
        -   Registers – thread-specific CPU registers
        -   Stack – stores local variables, function calls, etc.
        Shared among all threads in a process:
        -   Code Segment – program instructions
        -   Data Segment – global/static variables
        -   Heap Memory – dynamically allocated memory

    -   Advantages of Threads
        -   Responsiveness – if one thread is blocked (I/O), others can continue executing.
        -   Resource Sharing – threads share memory and resources of the parent process, reducing overhead.
        -   Economical – creating threads is cheaper than creating separate processes.
        -   Scalable – multi-threaded programs can exploit multiprocessing/multi-core CPUs for parallel execution.

    -   Thread Types
        -   User-Level Threads (ULT)
            -   Managed by thread library at user level.
            -   OS kernel does not know about these threads.
            -   Fast to create and manage, but if one thread blocks, all threads in that process may block.
        -   Kernel-Level Threads (KLT)
            -   Managed directly by the OS kernel.
            -   Each thread is recognized by the OS scheduler.
            -   Slower to create/manage but can run independently on multiple CPUs.
    
    -   Examples of Thread Usage
        -   Web browsers: Each tab runs as a thread within the browser process.
        -   Servers: Each client request handled by a separate thread.
        -   Video games: Rendering, physics, and AI can run in separate threads simultaneously.

    -   Thread vs Process
        -   Resource Sharing: Shares memory, files with other threads ::: Separate memory and resources
        -   Creation Overhead: Low :::: High
        -   Context Switching:	Fast :::: Slower
        -   Execution: Part of process :::: Independent