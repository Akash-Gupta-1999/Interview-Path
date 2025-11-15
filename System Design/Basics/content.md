-   Scalability : Scalability is the ability of a system to handle increasing workload or demand by adding resources without compromising performance.
    -   Verical Scaling : Increasing the capacity of a single machine (like adding more CPU, RAM, or storage) to improve system performance.
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