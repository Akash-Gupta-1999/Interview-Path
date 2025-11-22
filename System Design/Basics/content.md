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