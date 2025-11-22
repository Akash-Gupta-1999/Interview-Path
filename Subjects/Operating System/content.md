-   Operating System and its Types
    -   What is an Operating System?
        -   An Operating System (OS) acts as an intermediary between the user and the computer hardware.
        -   Its main goals are:
            -   To provide an environment where users can run programs efficiently and conveniently.
            -   To manage system resources such as CPU, Memory, I/O devices, Files, etc.
            -   To ensure fairness, efficiency, and security while handling multiple tasks.
        -   Based on different use-cases and features, OS are broadly classified into:
            -   Batch OS
            -   Time-Sharing OS
            -   Distributed OS
            -   Network OS
            -   Real-Time OS

    1. Batch Operating System
        -   A Batch OS groups similar jobs into batches using an operator program.
        -   There is no user interaction during execution of a batch.
        -   Key Features
            -   Multiple users submit jobs; OS groups them into batches.
            -   Job completion time is unpredictable.
            -   CPU remains busy; minimal idle time.
            -   Can suffer from the Convoy Effect (slow job blocks faster ones).
        -   Usage Examples: Payroll processing, Bank statements generation

    2. Time-Sharing Operating System
        -   A Time-Sharing OS allows multiple users to interact with the system simultaneously.
        -   Each user gets a small CPU time slice (time quantum).
        -   Key Features
            -   Every user gets equal CPU opportunity.
            -   No user is stuck indefinitely (due to context switching).
            -   Context switching overhead exists.
            -   Examples: Multics, UNIX

    3. Distributed Operating System
        -   A Distributed OS manages multiple independent hardware units (CPUs, memory, I/O), giving the illusion of a single system.
        -   Key Features
            -   Failure in one unit does not affect others.
            -   Faster computation due to resource sharing and parallelism.
            -   Easily scalable by adding more machines.
            -   Supports remote access to resources on other systems.

    4. Network Operating System
        -   A Network OS runs on a server and manages users, data, security, and applications across a network.
        -   These are tightly coupled systems, where users must know the network structure.
        -   Key Features
            -   Centralized management (but single point of failure).
            -   Supports remote access from different locations.
            -   Easy upgrades since changes apply to central server.
            -   Examples: Windows Server, Ubuntu Server, CentOS

    5. Real-Time Operating System
        -   A Real-Time OS (RTOS) executes tasks with strict timing constraints.
        -   Used in mission-critical systems where delays are unacceptable.
        -   Key Features
            -   Maximum utilization and zero downtime.
            -   Domain-specific and optimized for reliability.
            -   Automatic error recovery.
            -   Very predictable response times.
            -   Examples: Defense systems, Robotics, Spacecraft systems, Air-traffic control, Sensor networks

-   Multiprogramming, Multiprocessing & Multithreading
    
    Although these three concepts sound similar and all relate to concurrency, they differ fundamentally in how they achieve it.

    1. Multiprocessing
        -   Multiprocessing uses multiple physical CPUs (or CPU cores) to execute programs in true parallelism.
        -   Key Characteristics
            -   Multiple CPUs/cores exist physically.
            -   True parallel execution of processes.
            -   Higher reliability — if one CPU fails, others continue.
            -   Better performance through horizontal scaling (adding more CPUs instead of upgrading one).
            -   I/O devices can be shared among processors → cost-efficient.
            -   Advantages
                -   Genuine parallel execution
                -   Fault tolerance
                -   High computational throughput

    2. Multiprogramming
        -   Multiprogramming allows multiple programs to reside in memory and share a single CPU.
        -   There is no true parallelism. Instead, the CPU switches rapidly among processes — giving a feeling of concurrency.
        -   How it works
            -   All programs enter a job pool (a queue).
            -   A scheduler selects a process.
            -   CPU executes it until:
                -   Time quantum expires, or
                -   Process requests I/O, or
                -   An interrupt occurs
            -   OS performs a context switch to another process.
        -   Key Characteristics
            -   Only one process executes at a time.
            -   Uses context switching to avoid CPU idle time.
            -   Degree of multiprogramming depends on memory size.

    3. Multithreading
        -   Multithreading refers to multiple threads running within the same process.
        -   Since threads belong to the same process, they share: Code segment, Memory, File descriptors, Resources
        -   But each thread has its own: Stack, Program counter, Execution state, Characteristics
        -   Threads are lightweight processes.
        -   Faster context switching than processes (same PCB used).
        -   Designed for tasks that share data or run concurrently.
        -   Example: Each tab in a web browser is often a separate thread under the same browser process.