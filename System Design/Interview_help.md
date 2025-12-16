-   How to approach a system design interview question ?
    1.  Outline use cases, constraints, and assumptions
        Gather requirements and scope the problem. Ask questions to clarify use cases and constraints. Discuss assumptions.

        Who is going to use it?
        How are they going to use it?
        How many users are there?
        What does the system do?
        What are the inputs and outputs of the system?
        How much data do we expect to handle?
        How many requests per second do we expect?
        What is the expected read to write ratio?
    
    2.  Create a high level design
        
        Outline a high level design with all important components.

        -   Sketch the main components and connections
        -   Justify your ideas

    3.  Design core components
        Dive into details for each core component. For example, if you were asked to design a url shortening service, discuss:
        
        -   Generating and storing a hash of the full url
            -   MD5 and Base62
            -   Hash collisions
            -   SQL or NoSQL
            -   Database schema
        -   Translating a hashed url to the full url
            -   Database lookup
        -   API and object-oriented design

    4.  Scale the design
        Identify and address bottlenecks, given the constraints. For example, do you need the following to address scalability issues?

        Load balancer
        Horizontal scaling
        Caching
        Database sharding
    
        Discuss potential solutions and trade-offs. Everything is a trade-off. Address bottlenecks using principles of scalable system design.

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

------  continue further in sd primer links