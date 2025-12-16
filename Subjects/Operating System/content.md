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

-   Introduction to Threads

    -   What Are Threads?
        - A thread is the smallest unit of execution inside a process.  
        - Process = a running program (e.g., Chrome).  
        - Threads = workers inside that program doing tasks (rendering UI, loading a tab, running JS, etc.).  

    -   Why Do We Need Threads?
        1. Parallelism → Run tasks truly in parallel using multiple CPU cores (e.g., video rendering, ML training).  
        2. Concurrency → Handle multiple tasks logically at the same time (e.g., web server serving many requests).  
        3. Responsive Applications → UI thread + background worker threads keep apps smooth.  
        4. Better CPU Utilization → Threads reduce idle CPU time by keeping cores busy.  

    -   How Threads Work
        Each thread has:
        - Program counter → current execution point.  
        - Stack → function calls, local variables.  
        - Registers → CPU state.  
        - Thread-local storage (optional).  

        Threads share:
        - Heap memory  
        - Global variables  
        - File handles  
        - Code  

    -   Types of Threads
        1. User Threads → Managed by program/language runtime (Java threads, Python threads, pthreads).  
        2. Kernel Threads → Managed by OS scheduler (Windows threads, Linux tasks).  
        3. Green Threads → Emulated threads managed by runtime (Golang goroutines, Java virtual threads, Erlang processes).  

    -   Common Problems in Multithreading
        - Race Conditions → Two threads modify shared data simultaneously → corrupted state.  
        - Deadlocks → Thread A waits for B, B waits for A → freeze forever.  
        - Starvation → A thread never gets CPU time.  
        - Context Switching Overhead → Too much switching reduces performance.  

    -   Real-Life Uses of Threads
        - Web Servers → Each request handled by a new thread or thread pool.  
        - Databases → Background compaction, query execution, I/O threads.  
        - Games → Separate threads for physics, rendering, AI.  
        - OS Kernels → Each process may contain multiple threads.  

-   Thread V/S Process
    -   Process
        - A process is an independent program in execution.  
        - It has its own memory and resources.  
    -   Thread
        - A thread is the smallest unit of execution inside a process.  
        - Multiple threads live inside the same process and share its memory.  

    -   Key Differences (Interview Table)

    | Feature          | Process                                      | Thread                                      |------------------------------------------------------------------|---------------------------------------------|
    | Definition       | Independent execution unit (program running) | Lightweight execution unit inside a process |
    | Memory           | Has its own address space (isolated)         | Threads share memory of the process         |
    | Communication    | IPC (Inter-process communication) is slow    | Shared memory → fast communication          |
    | Creation         | Heavy, slow                                  | Light, fast                                 |
    | Context Switching| Slow (more state to save/restore)            | Fast                                        |
    | Crash Impact     | If one process crashes, others live          | If one thread crashes, entire process may crash |
    | Resource Ownership| Owns resources (files, sockets, heap)       | Threads share resources                     |
    | Scheduling       | Done by OS                                   | Also done by OS (kernel threads)            |
    | Use Cases        | Isolated tasks                               | Parallel tasks inside same program          |

    -   Memory Difference (Very Important for Interviews)

        Process Memory Layout
        Each process has separate:
        - Code section  
        - Stack  
        - Heap  
        - Data segment  
        - File descriptors  

        Thread Memory Layout
            Threads share:
            - Code  
            - Heap  
            - Globals  
            - File descriptors  

            But each thread has its own:
            - Stack  
            - Registers  
            - Program counter  

-   User Threads vs Kernel Threads

    Threads can be managed either by:
    - User-level thread library  
    - Operating system kernel

    1. User Threads (ULT)
        - Definition: Threads created and managed in user space by a runtime/library — NOT by the OS.  
        - Examples:  
            - Java green threads (old JVM)  
            - Go goroutines  
            - Python gevent greenlets  
            - Erlang lightweight processes  
            - POSIX ULT implementations  

            🔑 Key Features
            - Kernel does not know these threads exist.  
            - Scheduling is done in user space.  
            - One kernel thread runs many user threads.  

        -   How User Threads Work
            OS Kernel:     [ Kernel Thread ]
            User Space:    [ User Thread 1 ]
                           [ User Thread 2 ]
                           [ User Thread 3 ]
        ➡ All user threads run on a single kernel thread unless mapped differently.

        ⭐ Pros of User Threads
        | Advantage              | Why                          |
        |------------------------|------------------------------|
        | Very fast to create    | No system call needed        |
        | Fast context switching | Done in user space           |
        | Lightweight            | Small stack, cheap           |
        | Highly scalable        | Millions possible (e.g., Go) |

        ❌ Cons of User Threads
        | Limitation                  | Why                                      |
        |-----------------------------|------------------------------------------|
        | No true parallelism         | Only 1 kernel thread is running (no true multiprocessing)          |
        | Blocking system call blocks all | All user threads share one kernel thread |
        | Complex runtime scheduler   | Requires JVM, Go runtime, etc.           |

    2. Kernel Threads (KLT)

        - Definition: Threads created and managed by the OS kernel.  
        - Examples:  
            - Linux threads (each is a task)  
            - Windows threads  
            - POSIX pthreads (1:1 mapping)  
            - Java threads (modern JVM)  
            - C++ `std::thread`  

        🔑 Key Features
            - OS knows each thread.  
            - Each kernel thread can run independently on different CPU cores.  

        -   How Kernel Threads Work
            OS Kernel:     [ Kernel Thread 1 ]
                           [ Kernel Thread 2 ]
                           [ Kernel Thread 3 ]
            User Space:    (User program)
        ➡ Each thread is scheduled like a small process.

        ⭐ Pros of Kernel Threads
        | Advantage                  | Why                                      |
        |----------------------------|------------------------------------------|
        | True parallelism           | Multiple threads run on multiple cores   |
        | Blocking system call blocks only one | Other threads keep running          |
        | Better OS support          | Kernel manages scheduling                |

        ❌ Cons of Kernel Threads
        | Limitation                 | Why                                      |
        |----------------------------|------------------------------------------|
        | Heavier                    | More memory and kernel data structures   |
        | Slower to create/switch    | Requires system calls                    |
        | Limited number             | Not millions like goroutines             |

    -   Hybrid Models (Interview Point)

    Many systems use a mix of user + kernel threads:

    - 1:1 Model → One user thread → one kernel thread  
        - Example: Modern Java, pthreads  

    - N:1 Model → Many user threads → one kernel thread  
        - Example: Old Java green threads  

    - M:N Model → Many user threads → few kernel threads  
        - Example: Go goroutines, Erlang VM, Windows fibers  

-   Process Management – Introduction to Process

    -   What is a Process?
        - A process is a program in execution (active entity).  
        - A program is passive (binary or source code).  
        - Running a program multiple times creates multiple processes (instances).  
        - Example: Compiling C/C++ code → binary program. Running binary → process.

    -   Process in Memory ![alt text](image.png)
        A process consists of:
        - Text Section → Program code + Program Counter (current instruction).  
        - Stack → Temporary data (function parameters, return addresses, local variables).  
        - Data Section → Global variables.  
        - Heap → Dynamically allocated memory during runtime.  


    -   Process States

        Single Tasking (MS-DOS) ![alt text](image-1.png)
        - Only one process runs at a time.  
        - Next process starts only after the previous ends → inefficient.

        Multiprogramming
        - Multiple processes share hardware resources.  
        - Achieves pseudo-parallelism via context switching.  
        - Number of processes depends on memory size.

    -   State Models
        5-State Model: ![alt text](image-2.png)
        1. New → Process created but not yet in memory.  
        2. Ready → Loaded into memory, waiting for CPU.  
        3. Running → Instructions executed by CPU.  
        4. Blocked/Wait → Waiting for I/O or resource.  
        5. Terminated → Process finished, PCB deleted.  

        7-State Model (adds suspension states):![alt text](image-3.png)
        - Suspend Ready → Ready but swapped out to secondary storage.  
        - Suspend Blocked → Blocked process moved to secondary storage.  

    -   Process Control Block (PCB) ![alt text](image-4.png)
        Each process has a PCB containing:
        - Process ID (PID) → Unique identifier.  
        - Process State → Ready, running, blocked, etc.  
        - Program Counter → Next instruction address.  
        - CPU Registers → Accumulator, base, general-purpose registers.  
        - Pointer → Stack pointer for context switching.  
        - Memory Limits → Page tables, segment tables.  
        - Open Files List → Files used by the process.  
        - Scheduling Info → Priority, quantum.  
        - Accounting Info → CPU usage, time limits.  

    -   The process table is an array of PCBs for all active processes.

    -   Context Switching
        - Definition: Saving the context of one process and loading another.  
        - When it happens:  
            1. Higher-priority process becomes ready.  
            2. Interrupt occurs.  
            3. User ↔ Kernel mode switch.  
            4. Preemptive CPU scheduling.  

    -   Context Switch vs Mode Switch
        - Context Switch → CPU switches from one process to another (changes PCB).  
        - Mode Switch → CPU changes privilege level (user mode ↔ kernel mode).  
        - Mode switch may occur without changing the process.  
        - Only the kernel can trigger a context switch.

    -   Kernel Mode vs User Mode (Super Short)
        -   User Mode
            -   Runs apps (Chrome, games).
            -   Limited access → can’t touch hardware directly.
            -   App crash ≠ system crash.

        -   Kernel Mode
            -   Runs OS + drivers.
            -   Full hardware access.
            -   Crash here = system crash.  
    
    -   Process Spawning in Operating Systems

        🔑 Introduction
        - When the system boots, it begins with a single process.  
        - In UNIX-based systems, this is the init process.  
        - The init process spawns other processes until the OS is fully loaded.  
        - Process spawning allows the OS to create and destroy multiple processes during runtime.  

        👉 If process A creates process B:  
        - A = Parent process  
        - B = Child process

        🏷️ Process Identification
        - Each process has a unique Process ID (PID).  
        - Process information (state, resources, etc.) is stored in the process table.  
        - When a process terminates → its entry is deleted from the table.  
    
        🧟 Zombie Process
        - Definition: A process that has finished execution but still has an entry in the process table.  
        - Exists to report its exit status to the parent.  
        - Lifecycle:  
            1. Child terminates → becomes zombie.  
            2. Parent must reap (collect exit status).  
            3. Once reaped → entry removed from process table.  
        - Reason: Parent may be waiting for I/O or sleeping, delaying the reap.  
        - Until reaped → process remains a Zombie.  

        👶 Orphan Process
        - Definition: A child process still running after its parent has terminated.  
        - Causes:  
            - Parent terminates due to error.  
            - Parent doesn’t wait for child to finish.  
        - Handling:  
            - Orphan is adopted by the init process.  
            - Init reaps the orphan once it finishes execution. 

        -   Daemon Process
            Daemon processes are started working when the system will be bootstrapped and terminate only when the system is shutdown. It does not have a controlling terminal. It always runs in the background.

            -   Characteristics of Daemon Processes
                -   Background Operation: Daemons run in the background, performing system-level tasks without direct user intervention.
                -   Long-lived: Daemons are designed to run for extended periods, handling tasks such as system maintenance, network services, or hardware management. 

-   Process Management – Process Scheduling

    🔑 CPU vs I/O Bound Processes
    - CPU-bound → Intensive in CPU operations.  
    - I/O-bound → Intensive in I/O operations.  

    -   Types of Process Schedulers
        1. Long-Term (Job Scheduler)  
            - Brings new processes into the Ready State.  
            - Controls degree of multiprogramming (number of processes in ready state).  
            - Balances CPU-bound and I/O-bound processes.  

        2. Short-Term (CPU Scheduler)  
            - Selects one process from the ready queue for CPU execution.  
            - Dispatcher loads the selected process onto CPU.  
            - Dispatcher tasks:  
                - Context switching  
                - Switching to user mode  
                - Jumping to correct program location  

        3. Medium-Term Scheduler  
            - Suspends/resumes processes.  
            - Performs swapping (move processes between memory and disk).  
            - Used to improve process mix or free memory.  

    -   Multiprogramming
        - Pre-emption → Process forcefully removed from CPU (time-sharing).  
        - Non-pre-emption → Process runs until completion.  
        - Degree of multiprogramming → Max number of processes in ready state.  

    -   Process Queues
        - Ready Queue → Processes in memory waiting for CPU.  
        - Job Queue → New processes waiting for memory allocation.  
        - Waiting (Device) Queue → Processes waiting for I/O devices.  

    -   Scheduler vs Dispatcher

    | Property       | Scheduler                                   | Dispatcher                                      |
    |----------------|---------------------------------------------|------------------------------------------------|
    | Definition | Selects process among ready ones            | Gives CPU control to selected process          |
    | Types      | Long-term, Short-term, Medium-term          | No types (just a code segment)                 |
    | Dependency | Works independently                         | Depends on scheduler                           |
    | Algorithm  | FCFS, SJF, RR, etc.                         | No algorithm                                   |
    | Time Taken | Negligible                                  | Dispatch latency                               |
    | Functions  | Process selection                           | Context switch, mode switch, jump to program   |

    -   Process Timing Metrics
        - Arrival Time (AT) → Time process enters ready queue.  
        - Completion Time (CT) → Time process finishes execution.  
        - Burst Time (BT) → CPU time required.  
        - Turnaround Time (TAT) → CT – AT.  
        - Waiting Time (WT) → TAT – BT.  
        - Response Time (RT) → First CPU allocation – AT.  

        Example (P0):  
        - AT = 1, CT = 6, BT = 3 → TAT = 5, WT = 2, RT = 0.  

    -   Goals of Scheduling Algorithms
        - Max CPU utilization  
        - Max throughput (jobs/unit time)  
        - Min turnaround time  
        - Min waiting time  
        - Min response time  
        - Fair CPU allocation (avoid starvation)  

    -   Scheduling Algorithms

        1. First Come First Serve (FCFS)  
            - Non-preemptive, FIFO queue.  
            - Simple but can cause long waits if first job is large.  

        2. Shortest Job First (SJF)  
            - Non-preemptive, shortest burst time first.  
            - Optimal average waiting time.  
            - Risk of starvation for long jobs.  

        3. Longest Job First (LJF)  
            - Non-preemptive, longest burst time first.  

        4. Shortest Remaining Time First (SRTF)  
            - Preemptive SJF → shortest remaining time first.  
            - Risk of starvation.  

        5. Longest Remaining Time First (LRTF)  
            - Preemptive LJF → longest remaining time first.  

        6. Round Robin (RR)  
            - Time quantum assigned cyclically.  
            - Fair, good for time-sharing.  
            - Large quantum → behaves like FCFS.  

        7. Priority Scheduling (Non-preemptive)  
            - Highest priority first.  
            - Starvation possible.  

        8. Highest Response Ratio Next (HRRN)  
            - Response Ratio = (Waiting Time + Burst Time) / Burst Time.  
            - Avoids starvation.  

        9. Multilevel Queue Scheduling  
            - Processes divided into queues by priority.  
            - Higher queues executed first → starvation possible.  

        10. Multilevel Feedback Queue Scheduling  
            - Processes can move between queues.  
            - CPU-heavy processes moved to lower-priority queues.  

        -   Useful Facts
            - FCFS → Long waits if first job is large.  
            - SJF/SRTF → Optimal average waiting time but risk starvation.  
            - RR → Large quantum ≈ FCFS.  
            - HRRN → Avoids starvation.  

-   Scheduling Algorithms
    
    -   First Come, First Serve (FCFS) Scheduling

        🔹 Definition
        - Non-preemptive scheduling algorithm  
        - Processes are executed in the order they arrive in the ready queue.  
        - Comparable to a queue at a grocery store: first in line gets served first.

        🔹 How FCFS Works
        1. Arrival → Processes enter the ready queue in order of arrival.  
        2. Execution → CPU executes the process at the front until completion.  
        3. Repeat → Next process is taken from the queue.  
        4. Continues until queue is empty.

        🔹 Key Formulas
        - Turnaround Time (TAT) = Completion Time (CT) − Arrival Time (AT)  
        - Waiting Time (WT) = Turnaround Time (TAT) − Burst Time (BT)  
        - Average TAT = Σ(TAT) / n  
        - Average WT = Σ(WT) / n  

        -   Scenario 1: Same Arrival Time
            | Process | AT | BT | CT | TAT | WT |
            |---------|----|----|----|-----|----|
            | P1      | 0  | 5  | 5  | 5   | 0  |
            | P2      | 0  | 3  | 8  | 8   | 5  |
            | P3      | 0  | 8  | 16 | 16  | 8  |

            - Average TAT = (5+8+16)/3 = 9.67  
            - Average WT = (0+5+8)/3 = 4.33

            Gantt Chart:  
            ```
            | P1 |----| P2 |--| P3 |--------|
            0    5    8    16
            ```

            -   Scenario 2: Different Arrival Times
            | Process | AT | BT | CT | TAT | WT |
            |---------|----|----|----|-----|----|
            | P2      | 0  | 3  | 3  | 3   | 0  |
            | P1      | 2  | 5  | 8  | 6   | 1  |
            | P3      | 4  | 4  | 12 | 8   | 4  |

            - Average TAT = (3+6+8)/3 = 5.67  
            - Average WT = (0+1+4)/3 = 1.67

            Gantt Chart:  
            ```
            | P2 |--| P1 |-----| P3 |----|
            0    3    8         12
            ```

        ✅ Advantages
        - Simple and easy to implement.  
        - Fair: processes served in arrival order.  
        - No starvation.  
        - Suitable for batch systems.

        ❌ Disadvantages
        - Convoy Effect: Short jobs wait behind long jobs.  
        - Poor performance in mixed workloads.  
        - High average waiting time compared to other algorithms.  
        - Not suitable for time-sharing systems.

    -   Shortest Job First (SJF) Scheduling

        🔹 Definition
        - SJF (or Shortest Job Next, SJN) selects the process with the smallest burst time for execution.  
        - Can be non-preemptive (once started, runs till completion) or preemptive (Shortest Remaining Time First, SRTF).  
        - Known for minimizing average waiting time compared to other scheduling algorithms.

        🔹 Estimation Formula (Predicting Burst Time)
            When burst time is unknown, we estimate using exponential averaging:

            T_{n+1} = alpha * t_n + (1 - alpha) * T_n

        - T_{n+1}: Predicted burst time for next process  
        - T_n: Previously predicted burst time  
        - t_n: Actual burst time of the previous process  
        - alpha : Smoothing factor (0 ≤ α ≤ 1)  
            👉 This balances recent history t_n with past predictions T_n.

        🔹 Characteristics
        - Optimal in terms of average turnaround time.  
        - Each task is associated with a unit of time to complete.  
        - May cause starvation if short jobs keep arriving (solved via aging).  
        - Works best in batch systems where burst times are known.


        -   Example (Non-Preemptive SJF)

            | Process | AT | BT | CT | TAT | WT |
            |---------|----|----|----|-----|----|
            | P1      | 0  | 6  | 6  | 6   | 0  |
            | P2      | 2  | 8  | 17 | 15  | 7  |
            | P3      | 4  | 3  | 9  | 5   | 2  |

            - Average TAT = (6 + 15 + 5)/3 = 8.6 ms  
            - Average WT = (0 + 7 + 2)/3 = 3 ms

            Gantt Chart:  
            ```
            | P1 |------| P3 |---| P2 |--------|
            0    6      9    17
            ```

            🔹 Implementation Steps
                1. Input number of processes, burst times, and arrival times.  
                2. Sort processes by burst time (if equal, use arrival order).  
                3. Select the shortest job available at current time.  
                4. Compute Completion Time (CT) = Start Time + Burst Time.  
                5. Compute Turnaround Time (TAT) = CT − AT.  
                6. Compute Waiting Time (WT) = TAT − BT.  
                7. Repeat until all processes are executed.  
                8. Calculate averages (TAT, WT).  
                9. Display results with Gantt chart.


        ✅ Advantages
        - Lower average waiting time compared to FCFS.  
        - Optimal for batch jobs with known burst times.  
        - Reduces turnaround time significantly.  
        - Better CPU utilization in predictable workloads.

        ❌ Disadvantages
        - Starvation: Long jobs may wait indefinitely if short jobs keep arriving.  
        - Requires knowledge or estimation of burst times, which is often difficult.  
        - Prediction of burst times can be inaccurate.  
        - Not ideal for interactive/time-sharing systems.

    -   Shortest Remaining Time First (SRTF) Scheduling

        🔹 Definition
        - SRTF is the preemptive version of Shortest Job Next (SJN) / Shortest Job First (SJF).  
        - At any given time, the CPU is allocated to the process with the least remaining burst time.  
        - If a new process arrives with a shorter burst time than the currently running process, the CPU is preempted and given to the new process.  

        👉 Think of it as “always give the CPU to the process that can finish the quickest from now.”

        🔹 Characteristics
        - Requires knowledge (or estimation) of burst times.  
        - More complex than non-preemptive SJF because the OS must continuously monitor the ready queue.  
        - Involves context switching whenever a shorter job arrives.  
        - Works best in batch systems where burst times are predictable.  
        - Provides better average turnaround and waiting times compared to FCFS and non-preemptive SJF.  

        -   Example

            Consider 3 processes:

            | Process | Arrival Time (AT) | Burst Time (BT) |
            |---------|-------------------|-----------------|
            | P1      | 0                 | 8               |
            | P2      | 1                 | 4               |
            | P3      | 2                 | 2               |

            Step-by-step execution:
            - At time 0 → P1 starts (remaining = 8).  
            - At time 1 → P2 arrives (BT=4). Since 4 < 7 (remaining of P1), CPU switches to P2.  
            - At time 2 → P3 arrives (BT=2). Since 2 < 3 (remaining of P2), CPU switches to P3.  
            - P3 runs till completion (time 4).  
            - CPU returns to P2 (remaining 2) → finishes at time 6.  
            - CPU returns to P1 (remaining 7) → finishes at time 13.  

            Gantt Chart:  
            ```
            | P1 |-| P2 |-| P3 |-| P2 |-| P1 |---------|
            0    1   2    4    6    13
            ```

            Calculations:
            - Turnaround Time (TAT) = CT − AT  
            - Waiting Time (WT) = TAT − BT

            | Process | CT | TAT | WT |
            |---------|----|-----|----|
            | P1      | 13 | 13  | 5  |
            | P2      | 6  | 5   | 1  |
            | P3      | 4  | 2   | 0  |

            - Average TAT = (13+5+2)/3 = 6.67  
            - Average WT = (5+1+0)/3 = 2.0


        ✅ Advantages
        - Better average waiting and turnaround times compared to FCFS and non-preemptive SJF.  
        - More responsive to short processes.  
        - Optimal for minimizing average waiting time (theoretically).  

        ❌ Disadvantages
        - High overhead due to frequent context switching.  
        - Requires accurate knowledge or estimation of burst times.  
        - Starvation risk: long processes may be delayed indefinitely if short jobs keep arriving.  
        - Not suitable for interactive/time-sharing systems.  
    
    -   Priority Scheduling

        🔹 Definition
        - Each process is assigned a priority value (based on memory needs, CPU burst, I/O ratio, etc.).  
        - The highest priority process is selected first.  
        - If multiple processes share the same priority → scheduled in FCFS order.  
        - Can be implemented in two ways:
            - Non-Preemptive Priority Scheduling → once a process starts, it runs till completion.  
            - Preemptive Priority Scheduling → CPU can be taken away if a higher-priority process arrives.  

        -   Non-Preemptive Priority Scheduling Example

            | Process | AT | BT | Priority | CT | TAT | WT |
            |---------|----|----|----------|----|-----|----|
            | P1      | 0  | 4  | 2        | 4  | 4   | 0  |
            | P2      | 1  | 2  | 1        | 6  | 5   | 3  |
            | P3      | 2  | 6  | 3        | 12 | 10  | 4  |

            - Average TAT = (4+5+10)/3 = 6.33  
            - Average WT = (0+3+4)/3 = 2.33

            Gantt Chart:  
            ```
            | P1 |----| P2 |--| P3 |------|
            0    4    6    12
            ```

        -    Preemptive Priority Scheduling Example (Same Arrival Time)

            | Process | AT | BT | Priority | CT | TAT | WT |
            |---------|----|----|----------|----|-----|----|
            | P1      | 0  | 7  | 2        | 13 | 13  | 6  |
            | P2      | 0  | 4  | 1        | 17 | 17  | 13 |
            | P3      | 0  | 6  | 3        | 6  | 6   | 0  |

            - Average TAT = (13+17+6)/3 = 12  
            - Average WT = (6+13+0)/3 = 6.33

            Gantt Chart:  
            ```
            | P3 |------| P1 |-------| P2 |----|
            0    6      13   17
            ```

        -   Preemptive Priority Scheduling Example (Different Arrival Times)

            | Process | AT | BT | Priority | CT | TAT | WT |
            |---------|----|----|----------|----|-----|----|
            | P1      | 0  | 6  | 2        | 10 | 10  | 4  |
            | P2      | 1  | 4  | 3        | 5  | 4   | 0  |
            | P3      | 2  | 5  | 1        | 15 | 13  | 8  |

            - Average TAT = (10+4+13)/3 = 9  
            - Average WT = (4+0+8)/3 = 4

            Gantt Chart:  
            ```
            | P1 |-| P2 |----| P1 |----| P3 |-----|
            0    1   5    10   15
            ```

        ✅ Advantages
        - Flexible: can prioritize critical tasks.  
        - More efficient than FCFS in mixed workloads.  
        - Can reduce waiting time for high-priority processes.  

        ❌ Disadvantages
        - Starvation: low-priority processes may never execute if high-priority jobs keep arriving.  
        - Requires accurate assignment of priorities (not always easy).  
        - Preemptive version → high overhead due to frequent context switching.  

        -   Aging (Solution to Starvation)
            - Problem: In Priority Scheduling, low-priority processes may starve if high-priority jobs keep arriving.
            - Solution: Aging gradually increases the priority of waiting processes the longer they stay in the queue.
            - Mechanism:
            - For every unit of waiting time, increase the process’s priority by a small fixed amount.
            - Eventually, even low-priority processes reach a high enough priority to be scheduled.

            👉 Example:
            - Suppose a process has priority = 5 (low).
            - After waiting 10 ms, its priority increases to 7.
            - It can now compete with higher-priority processes and avoid starvation.
    
    -   Round Robin (RR) Scheduling

        🔹 Definition 
        - Preemptive scheduling algorithm.  
        - Each process gets a fixed time slice (quantum) in cyclic order.  
        - Promotes fairness: all processes get equal CPU time.  
        - Ideal for time-sharing systems.

        🔹 How It Works ![alt text](image-5.png)
        1. Arrival → Processes enter the ready queue.  
        2. Time Allocation → Each process gets a fixed quantum.  
        3. Execution → Process runs for quantum or until completion.  
        4. Rotation → If unfinished, process goes to the end of the queue.  
        5. Repeat → CPU cycles through until all processes finish.  

        🔹 Key Formulas
        - Turnaround Time (TAT) = Completion Time (CT) − Arrival Time (AT)  
        - Waiting Time (WT) = Turnaround Time (TAT) − Burst Time (BT)  
        - Average TAT = Σ(TAT)/n  
        - Average WT = Σ(WT)/n  

        -   Scenario 1: Same Arrival Time (Quantum = 2 ms)

            | Process | AT | BT | CT | TAT | WT |
            |---------|----|----|----|-----|----|
            | P1      | 0  | 4  | 8  | 8   | 4  |
            | P2      | 0  | 5  | 12 | 12  | 7  |
            | P3      | 0  | 3  | 11 | 11  | 8  |

            - Avg TAT = (8+12+11)/3 = 10.33 ms  
            - Avg WT = (4+7+8)/3 = 6.33 ms

            Gantt Chart:  
            ```
            | P1 |--| P2 |--| P3 |--| P1 |--| P2 |--| P3 |-| P2 |
            0    2    4    6    8    10   11   12
            ```

        -   Scenario 2: Different Arrival Times (Quantum = 2 ms)

            | Process | AT | BT | CT | TAT | WT |
            |---------|----|----|----|-----|----|
            | P1      | 0  | 5  | 7  | 7   | 2  |
            | P2      | 4  | 2  | 6  | 2   | 0  |
            | P3      | 5  | 4  | 11 | 6   | 2  |

            - Avg TAT = (7+2+6)/3 = 5 ms  
            - Avg WT = (2+0+2)/3 = 1.33 ms

            Gantt Chart:  
            ```
            | P1 |--| P1 |--| P2 |--| P1 |-| P3 |--| P3 |
            0    2    4    6    7    9    11
            ```

        ✅ Advantages
        - Fairness: Every process gets equal CPU share.  
        - Simplicity: Easy to implement.  
        - Responsiveness: Good for interactive/time-sharing systems.  

        ❌ Disadvantages
        - Overhead: Frequent context switching if quantum is too small.  
        - Poor responsiveness if quantum is too large (behaves like FCFS).  
        - Not optimal for minimizing average waiting time compared to SJF/SRTF.  
    
    -   Multilevel Queue (MLQ) Scheduling

        🔹 Definition
        - MLQ Scheduling divides processes into multiple queues, each with its own scheduling policy.  
        - Processes are permanently assigned to a queue based on characteristics such as priority, memory needs, or type (system, interactive, batch).  
        - Each queue has a different scheduling algorithm (e.g., RR, FCFS, SJF).  
        - Higher-priority queues are served first; lower-priority queues run only when higher ones are empty.

        🔹 Characteristics
        - Multiple Queues: Processes grouped by type (system, interactive, batch).  
        - Fixed Priorities: Higher-priority queues always preempt lower ones.  
        - Different Algorithms: Each queue can use a different scheduling method.  
        - No Movement: Once assigned, a process stays in its queue (unlike MLFQ).  
        - Scheduling Among Queues:
            - Fixed Priority Preemptive: Higher queues dominate; lower queues run only if higher ones are empty.  
            - Time Slicing: CPU time is divided among queues (e.g., Q1 = 50%, Q2 = 30%, Q3 = 20%).  

        -   Example
            Suppose we have 3 queues:
            - Queue 1 (System) → Round Robin (RR)  
            - Queue 2 (Interactive) → FCFS  
            - Queue 3 (Batch) → SJF  

            Execution Rules:
            - If all queues have processes → Queue 1 runs first.  
            - If Queue 1 is empty → Queue 2 runs.  
            - If Queue 1 and Queue 2 are empty → Queue 3 runs.  

            👉 This ensures fast response for system/interactive tasks, while batch jobs eventually complete in lower queues.

        ✅ Advantages
        - Organized: Separates processes into distinct queues.  
        - Predictable: Easy to anticipate scheduling behavior.  
        - Fast response for system and interactive processes.  
        - Suitable for systems with diverse workloads.  
        - Ensures critical processes are not delayed behind non-essential tasks.  

        ❌ Disadvantages
        - Rigid: Processes cannot move between queues → inefficiency if workload type changes.  
        - Starvation risk: Lower queues may rarely get CPU time.  
        - Idle CPU: If high-priority queues are underloaded, CPU may stay idle while lower queues wait.  
        - Complexity: Requires more bookkeeping and resources.  
        - Reduced flexibility compared to MLFQ (which allows dynamic movement).  

    -   Multilevel Feedback Queue (MLFQ) Scheduling

        🔹 Definition
        - Extension of Multilevel Queue (MLQ) Scheduling.  
        - Unlike MLQ (where processes are permanently assigned to a queue), MLFQ allows processes to move between queues dynamically based on their behavior.  
        - Designed to balance responsiveness for short jobs and fairness for long jobs.  

        🔹 Characteristics
        - Multiple Queues: Each queue has its own scheduling policy (e.g., RR, FCFS).  
        - Dynamic Priorities: Process priority changes depending on CPU usage and waiting time.  
        - Time-Slicing: Higher-priority queues have smaller time quanta; lower-priority queues have larger quanta.  
        - Feedback Mechanism:  
            - If a process uses up its quantum → moved to a lower-priority queue.  
            - If a process waits too long → boosted to a higher-priority queue (to prevent starvation).  
        - Preemption: Higher-priority processes can preempt lower-priority ones.  

        -   Example Implementation
            - Queue 1 → Round Robin, Quantum = 4  
            - Queue 2 → Round Robin, Quantum = 8  
            - Queue 3 → FCFS  

            Rules:
            1. New processes start in Queue 1.  
            2. If not finished in Queue 1’s quantum → move to Queue 2.  
            3. If not finished in Queue 2’s quantum → move to Queue 3.  
            4. Lower queues run only if higher queues are empty.  
            5. Starvation prevention → periodically boost all processes to Queue 1.  

        -   Example Problem
            Process P requires 40 seconds. Quantum starts at 2, increases by 5 at each level.

            - Queue 1: Runs 2s → shifted to Queue 2.  
            - Queue 2: Runs 7s → shifted to Queue 3.  
            - Queue 3: Runs 12s → shifted to Queue 4.  
            - Queue 4: Runs 17s → shifted to Queue 5.  
            - Queue 5: Runs 2s → completes.  

            👉 Interrupted 4 times, finishes in Queue 5.

        ✅ Advantages
        - Flexible: adapts to process behavior.  
        - Prevents starvation (via priority boosting/aging).  
        - Optimizes turnaround time by favoring short jobs.  
        - Reduces response time for interactive tasks.  

        ❌ Disadvantages
        - Complex to implement.  
        - Requires careful tuning of time quanta and priority rules.  
        - Higher CPU overhead due to frequent monitoring and context switching.  










-   Deadlock in Operating System

    🔹 Definition
    - A deadlock is a situation where a set of processes become permanently blocked because each process is waiting for a resource held by another process.  
    - None of the processes can proceed, leading to a system halt for those tasks.  

    🔹 How Deadlock Occurs
    Typical resource usage sequence:  
    1. Request a resource  
    2. Use the resource  
    3. Release the resource  

    👉 Deadlock arises when processes hold some resources while waiting for others.  

    Example:  
    - P1 holds Resource R1 and requests R2.  
    - P2 holds Resource R2 and requests R1.  
    - Neither can proceed → deadlock.  

    -   Examples of Deadlock
        1. Tape Drives:  
        - System has 2 tape drives.  
        - P0 and P1 each hold one and both request the other → deadlock.  

        2. Semaphores:  
        - Semaphores A and B initialized to 1.  
        - P0 executes `wait(A)` then requests `wait(B)`.  
        - P1 executes `wait(B)` then requests `wait(A)`.  
        - Both block each other → deadlock.  

        3. Memory Allocation:  
        - System has 200 KB free.  
        - P0 requests 80 KB, P1 requests 70 KB.  
        - Then P0 requests 60 KB, P1 requests 80 KB.  
        - Both wait indefinitely → deadlock.  

    -   Necessary Conditions for Deadlock
        Deadlock can occur only if all four conditions hold simultaneously:

        1. Mutual Exclusion  
        - Only one process can use a resource at a time (non-sharable resources).  

        2. Hold and Wait  
        - A process holds at least one resource and waits for additional resources.  

        3. No Preemption  
        - Resources cannot be forcibly taken away; they must be released voluntarily.  

        4. Circular Wait  
        - A set of processes wait for each other in a circular chain.  
        -   Example of Circular Wait:  ![alt text](image-6.png)
            - P1 holds R1, waiting for R2 (held by P2).  
            - P2 holds R2, waiting for R3 (held by P3).  
            - P3 holds R3, waiting for R4 (held by P4).  
            - P4 holds R4, waiting for R1 (held by P1).  
            - Forms a circular dependency → deadlock. 

    -   Handling Deadlocks in Operating Systems
        Deadlock handling methods are strategies used to ensure processes do not remain permanently blocked, maintaining smooth execution and system reliability.

        -   Four Approaches to Deadlock Handling

        1. Deadlock Prevention
        - Idea: Ensure at least one of the four necessary conditions (Mutual Exclusion, Hold & Wait, No Preemption, Circular Wait) never occurs.  
        - Examples:
            - Avoid Hold & Wait → require processes to request all resources at once.  
            - Allow Preemption → forcibly take resources if needed.  
            - Impose ordering of resources → prevent circular wait.  
        - Pros: Guarantees no deadlock.  
        - Cons: May lead to low resource utilization and reduced concurrency.

        2. Deadlock Avoidance
        - Idea: Make dynamic decisions to ensure the system never enters an unsafe state.  
        - Algorithms:
            - Banker’s Algorithm → works with multiple instances of resources; simulates allocation before granting.  
            - Resource Allocation Graph (RAG) → works with single-instance resources; checks for cycles.  
        - Pros: More flexible than prevention; allows higher concurrency.  
        - Cons: Requires advance knowledge of resource needs; overhead in checking safe states.

        3. Deadlock Detection & Recovery
        - Detection: Periodically check for circular waits (e.g., using wait-for graphs).  
        - Recovery Methods:
            - Process Termination → abort one or more processes to break the cycle.  
            - Resource Preemption → temporarily take resources from some processes and reallocate.  
        - Pros: Allows maximum resource utilization (no restrictions upfront).  
        - Cons: Recovery can be costly (lost work, inconsistent states).

        4. Deadlock Ignorance (Ostrich Algorithm)
        - Idea: Assume deadlocks are rare → ignore them.  
        - If deadlock occurs → reboot or restart affected processes.  
        - Pros: Simple, minimal overhead.  
        - Cons: Not suitable for critical systems; risk of data loss.  
        - Common in general-purpose OS (e.g., UNIX, Windows) where deadlocks are rare.

-   Deadlock Prevention

    -   Definition
        -   Deadlock prevention is a strategy used in operating systems to ensure processes do not get permanently stuck waiting for resources.  
        -   Think of it like a traffic system: cars (processes) must move through intersections (resources) without gridlock.

    -   Four Necessary Conditions for Deadlock
        Deadlock occurs only if all four conditions hold simultaneously:
        1. Mutual Exclusion → Resources are non-sharable.  
        2. Hold and Wait → A process holds one resource while waiting for another.  
        3. No Preemption → Resources cannot be forcibly taken away.  
        4. Circular Wait → Processes form a cycle, each waiting for the next.

        👉 Deadlock prevention works by eliminating at least one of these conditions.

    -   Methods of Deadlock Prevention

        1. Eliminate Mutual Exclusion
            - Allow resources to be sharable (e.g., read-only files).  
            - Not possible for inherently non-sharable resources (e.g., printers).  
            - We can use Spooling which is a job queue where process requested is inserted into a queue but that queue can also becomes Full. So spooling can reduce this but not completely Elimenate it.

        2. Eliminate Hold and Wait
            - Option A (Eliminate Wait):  
                - Processes must request all resources in advance.  
                - Example: Process1 requests Resource1 and Resource2 together.  
            - Option B (Eliminate Hold):  
                - Processes must release all held resources before requesting new ones.  
                - Example: Process1 releases Resource2 and Resource3 before requesting Resource1.  

        3. Eliminate No Preemption
            - Allow preemption of resources:  
                - If a process requests unavailable resources, it must release all currently held ones.  
                - Resources can be reallocated to other processes.  
            - Ensures no process can indefinitely block others.  

        4. Eliminate Circular Wait
            - Impose a strict ordering of resources.  
            - Assign each resource a unique number.  
            - Processes can only request resources in increasing order.  
            - Prevents cycles since no process can “go backwards.”  

    ✅ Advantages
    - Guarantees no deadlock.  
    - Provides a systematic way to manage resources.  

    ❌ Disadvantages
    - May lead to low resource utilization.  
    - Reduces concurrency (e.g., requiring all resources upfront).  
    - Can be impractical for non-sharable resources.  

-   Deadlock Avoidance — Banker’s Algorithm

    🔹 Definition
        - Banker’s Algorithm is a resource allocation and deadlock avoidance algorithm.  
        - Ensures the system remains in a safe state by simulating allocations before granting them.  
        - Named after the way a banker lends money: only if they can be sure all loans can eventually be repaid.

    🔹 Key Concepts
    - Safe State: There exists at least one sequence of processes such that each can finish execution without deadlock.  
    - Unsafe State: No guarantee that all processes can finish; deadlock may occur.  

    👉 Deadlock avoidance = never allow unsafe states.

    🔹 Data Structures
        Let n = number of processes, m = number of resource types.

        1. Available → 1D array of size *m*.  
        - Available[j] = k → k instances of resource Rj are free.  

        2. Max → 2D array of size *n × m*.  
        - Max[i, j] = k → process Pi may request at most k instances of Rj.  

        3. Allocation → 2D array of size *n × m*.  
        - Allocation[i, j] = k → Pi currently holds k instances of Rj.  

        4. Need → 2D array of size *n × m*.  
        - Need[i, j] = Max[i, j] − Allocation[i, j].  
        - Remaining resources Pi may still request.  

    🔹 Banker’s Algorithm Components

        1. Safety Algorithm
            Checks if the system is in a safe state.

            Steps:
                1. Initialize:  
                    - Work = Available  
                    - Finish[i] = false (none finished yet)  
                2. Find a process Pi such that:  
                    - Finish[i] = false  
                    - Need[i] ≤ Work  
                3. If found:  
                    - Pretend to allocate → Work = Work + Allocation[i]  
                    - Finish[i] = true  
                    - Repeat step 2  
                4. If all Finish[i] = true → system is safe.  

            👉 Simulates process completion to verify safety.

        2. Resource Request Algorithm
            Decides if a process’s request can be granted safely.

            Steps:
                1. Check if Request[i] ≤ Need[i]. If not → error.  
                2. Check if Request[i] ≤ Available. If not → process waits.  
                3. Temporarily allocate:  
                    - Available = Available − Request[i]  
                    - Allocation[i] = Allocation[i] + Request[i]  
                    - Need[i] = Need[i] − Request[i]  
                4. Run Safety Algorithm:  
                    - If safe → grant request.  
                    - If unsafe → rollback and make process wait.  

    📊 Example (Unsafe State) : https://www.geeksforgeeks.org/operating-systems/bankers-algorithm-in-operating-system-2/
    -   ![alt text](image-7.png)
    -   ![alt text](image-8.png)
    -   ![alt text](image-9.png)
    -   ![alt text](image-10.png)
    -   ![alt text](image-11.png)
    -   ![alt text](image-12.png)
    -   ![alt text](image-13.png)
    -   ![alt text](image-14.png)
    -   ![alt text](image-15.png)

    ✅ Advantages
    - Prevents deadlock by avoiding unsafe states.  
    - Allows higher concurrency than strict prevention.  
    - Flexible resource allocation.  

    ❌ Disadvantages
    - Requires advance knowledge of Max demand.  
    - Computational overhead (simulation for each request).  
    - Complex to implement for large systems. 

-   Deadlock Detection and Recovery
    -   What is Deadlock?
        - A deadlock occurs when two or more processes are permanently blocked, each waiting for resources held by the other.  
        - Analogy: Like cars stuck at a four-way intersection, each blocking the other, none can move.

    -   Deadlock Detection
        Detection involves identifying when processes are stuck waiting for resources.

        1. Single Instance of Resources
        - Use Resource Allocation Graph (RAG).  
        - If a cycle exists → deadlock confirmed.  
        - Example: R1 → P1 → R2 → P2 → R1 (cycle).

        2. Multiple Instances of Resources
        - Cycle detection is necessary but not sufficient.  
        - Algorithms like Banker’s Algorithm can be adapted to periodically check for deadlocks.

        3. Wait-For Graph Algorithm
        - Construct a Wait-For Graph (process-to-process edges).  
        - Detect cycles → indicates deadlock.  
        - Suitable for systems with multiple resource instances.

    -   Deadlock Recovery
        Once detected, the OS must resolve deadlock.

        Methods:
        1. Process Termination
            - Kill all deadlocked processes.  
            - Or kill one at a time until deadlock breaks.  
            - Simple but may cause loss of work.

        2. Process Rollback
            - Roll back processes to a previously saved checkpoint.  
            - Requires checkpointing.  
            - Risk of data loss.

        3. Resource Preemption
            - Temporarily take resources from processes and reallocate.  
            - May cause starvation if repeated.

        4. Concurrency Control
            - Manage access to shared resources to avoid inconsistencies.  
            - Helps prevent deadlocks in concurrent systems.

    -   Prevention vs Detection/Recovery
        - Prevention → avoids deadlocks altogether by breaking one of the four necessary conditions.  
        - Detection/Recovery → allows deadlocks to occur, then detects and resolves them.  

    -   Advantages
        - Improves system stability (avoids indefinite stalls).  
        - Ensures better resource utilization.  
        - Provides insights for better system design.

    -   Disadvantages
        - Performance overhead (regular checks).  
        - Complexity in implementation.  
        - False positives/negatives possible.  
        - Risk of data loss during rollback or termination.

-   Inter-Process Communication (IPC)

    🔹 Definition
    - IPC refers to mechanisms that allow processes to communicate and share data.  
    - Enables concurrent execution of programs in an operating system.  
    - Essential for data consistency, coordination, and resource sharing.

    -   Fundamental Models of IPC
        1. Shared Memory
            - Multiple processes access a common memory region.  
            - Processes read/write directly to this memory.  
            - Fast communication, but requires synchronization (e.g., semaphores).  
            - Analogy: Like global variables, but shared across processes.  

        2. Message Passing
            - Processes exchange data via messages.  
            - One process sends, another receives.  
            - Useful in distributed systems.  
            - Implemented via pipes, sockets, message queues.  

    -   IPC Methods
        -   Pipes: Unidirectional channel between related processes. 
            -   Types: Anonymous & Named.
            -   Parent-child communication
        -   Sockets: Endpoints for communication across networks. 
            -   Supports TCP (reliable) & UDP (fast).
            -   Distributed systems
        -   Shared Memory: Common memory space accessible by multiple processes. 
            -   Fastest IPC method.
            -   High-speed local communication
        -   Semaphores: Synchronization tool to control access to shared resources. 
            -   Prevents corruption.
            -   Critical section handling
        -   Message Queues: Kernel-managed queues for passing structured messages.
            -   Asynchronous communication
        -   RPC (Remote Procedure Call): Allows calling procedures on remote machines as if local.
            -   Distributed computing
        -   RMI (Remote Method Invocation): Java-based, enables invoking methods on remote objects.
            -   Java distributed apps

    -   IPC Across Systems
        - Remote Procedure Calls (RPC) → Abstracts communication, makes distributed systems easier.  
        - Remote Method Invocation (RMI) → Java-specific, allows remote object method calls.  

    ✅ Advantages
    - Enables process cooperation.  
    - Supports distributed systems.  
    - Provides flexibility (different methods for different needs).  

    ❌ Disadvantages
    - Complexity in implementation.  
    - Overhead in synchronization and communication.  
    - Choice of method depends on application requirements (speed, locality, distribution).  

    🎯 Interview Tip
    - Always start with two fundamental models: Shared Memory & Message Passing.  
    - Be ready to explain examples:  
        - Shared Memory → fastest, but needs synchronization.  
        - Message Passing → safer, easier for distributed systems.  
    - Mention RPC vs RMI for cross-system communication.  
    - Compare local IPC (pipes, shared memory) vs distributed IPC (sockets, RPC, RMI).  

-   IPC through Shared Memory

    -   Definition
        - Inter-Process Communication (IPC) allows processes to exchange data and synchronize actions.  
        - Shared Memory IPC → multiple processes access a common memory segment.  
        - Changes made by one process are immediately visible to others.  
        - One of the fastest IPC mechanisms, especially for performance-critical applications.

    -   Why Shared Memory? 
        - Other IPC methods (pipes, FIFO, message queues) require multiple copies of data via the kernel.  
        - Example: Data copied 4 times (server → kernel buffer → client buffer → output).  
        - Shared Memory reduces this to 2 copies (input → shared memory → output).  
        - Hence, low overhead and high speed.

    -   How Shared Memory IPC Works ![alt text](image-16.png)
        1. Creation of Shared Memory Segment  
            - Parent process creates a segment using `shmget()`.  
            - Returns a unique identifier (`shmid`).  

        2. Attaching to Shared Memory  
            - Processes attach using `shmat()`.  
            - Once attached, they can directly read/write.  

        3. Synchronization  
            - Multiple processes can access simultaneously.  
            - Use semaphores/mutexes to prevent race conditions.  

        4. Detaching and Deleting  
            - Detach using `shmdt()`.  
            - Remove segment using `shmctl()` when no longer needed.  

    -   System Calls Used
    | Function | Signature | Description |
    |----------|-----------|-------------|
    | `ftok()` | `key_t ftok()` | Generates a unique key. |
    | `shmget()` | `int shmget(key_t key, size_t size, int shmflg)` | Creates shared memory segment, returns ID. |
    | `shmat()` | `void *shmat(int shmid, void *shmaddr, int shmflg)` | Attaches process to shared memory. |
    | `shmdt()` | `int shmdt(void *shmaddr)` | Detaches process from shared memory. |
    | `shmctl()` | `shmctl(int shmid, IPC_RMID, NULL)` | Removes shared memory segment. |

    ✅ Advantages
    - Speed → direct read/write, faster than message passing.  
    - Low Overhead → fewer copies of data.  
    - Flexibility → supports complex data structures (arrays, linked lists, matrices).  
    - Large Data Transfers → efficient for bulk communication.  

    ❌ Disadvantages
    - Complex Synchronization → requires semaphores/mutexes.  
    - Security Risks → unauthorized processes may access/modify data.  
    - Manual Cleanup → must detach and delete segments properly.  
    - Portability Issues → platform-dependent implementation.  

    -   Example — Producer & Consumer (Bounded Buffer Problem)
        - Producer → generates items, stores in shared buffer.  
        - Consumer → retrieves items from buffer.  
        - Bounded Buffer → buffer has limited size.  
            - If full → Producer waits.  
            - If empty → Consumer waits.  

        Pseudo-code (simplified):
        ```c
        // Shared buffer with size N
        buffer[N];
        in = 0; out = 0;

        // Producer
        while (true) {
            wait(empty);        // check if buffer has space
            wait(mutex);        // enter critical section
            buffer[in] = item;  // produce item
            in = (in + 1) % N;
            signal(mutex);      // exit critical section
            signal(full);       // notify consumer
        }

        // Consumer
        while (true) {
            wait(full);         // check if buffer has items
            wait(mutex);        // enter critical section
            item = buffer[out]; // consume item
            out = (out + 1) % N;
            signal(mutex);      // exit critical section
            signal(empty);      // notify producer
        }
        ```

-   IPC Using Message Queues

    -   Definition
        - Inter-Process Communication (IPC) allows processes to exchange data, control information, or synchronize tasks.  
        - Message Queues are one of the most common IPC mechanisms.  
        - They allow processes to send and receive messages in a queue-like manner, typically managed by the kernel.

    -   What is a Message Queue?
        - A linked list of messages stored in the kernel.  
        - Identified by a message queue identifier.  
        - Supports FIFO (First-In-First-Out) communication, but messages can also be retrieved by type field.  
        - Each message contains:  
            - Type field (positive long integer)  
            - Length (non-negative integer)  
            - Data bytes (actual message content)  

    -   Working of Message Queues ![alt text](image-17.png)
        1. Creating/Accessing a Queue  
            - Use `msgget()` to create a new queue or access an existing one.  

        2. Sending a Message  
            - Use `msgsnd()` to add a message to the queue.  
            - Message includes type and content.  

        3. Receiving a Message  
            - Use `msgrcv()` to retrieve a message.  
            - Can specify type to selectively read messages.  
            - Message is removed once read.  

        4. Deleting a Queue  
            - Use `msgctl()` to remove the queue when no longer needed.  

    -   Example Programs

        Writer (Sender)
        ```c
        include <stdio.h>
        include <sys/ipc.h>
        include <sys/msg.h>
        define MAX 10

        struct mesg_buffer {
            long mesg_type;
            char mesg_text[100];
        } message;

        int main() {
            key_t key;
            int msgid;

            key = ftok("progfile", 65); // generate unique key
            msgid = msgget(key, 0666 | IPC_CREAT); // create queue
            message.mesg_type = 1;

            printf("Write Data : ");
            fgets(message.mesg_text, MAX, stdin);

            msgsnd(msgid, &message, sizeof(message), 0); // send message
            printf("Data sent is : %s\n", message.mesg_text);

            return 0;
        }
        ```

        Reader (Receiver)
        ```c
        include <stdio.h>
        include <sys/ipc.h>
        include <sys/msg.h>

        struct mesg_buffer {
            long mesg_type;
            char mesg_text[100];
        } message;

        int main() {
            key_t key;
            int msgid;

            key = ftok("progfile", 65); // generate unique key
            msgid = msgget(key, 0666 | IPC_CREAT); // access queue

            msgrcv(msgid, &message, sizeof(message), 1, 0); // receive message
            printf("Data Received is : %s\n", message.mesg_text);

            msgctl(msgid, IPC_RMID, NULL); // delete queue
            return 0;
        }
        ```

    -   Functions of Message Queues
        - Message Storage → stores messages until retrieved.  
        - Ordered Communication → ensures delivery order.  
        - Asynchronous Communication → sender and receiver need not be synchronized.  
        - Decoupling of Processes → sender and receiver don’t need to know each other.  
        - Prioritization → messages can be processed based on type/priority.  
        - Error Handling → supports retries, logging of undelivered messages.  

    -   System Calls
        | Function   | Description |
        |------------|-------------|
        | `ftok()`   | Generates a unique key. |
        | `msgget()` | Creates or accesses a message queue. |
        | `msgsnd()` | Sends a message to the queue. |
        | `msgrcv()` | Receives a message from the queue. |
        | `msgctl()` | Performs control operations (e.g., delete queue). |

    ✅ Advantages
    - Simple and robust IPC mechanism.  
    - Supports asynchronous communication.  
    - Decouples processes → improves modularity.  
    - Can handle prioritization and error recovery.  

    ❌ Disadvantages
    - Kernel overhead → messages stored in kernel space.  
    - Limited message size.  
    - Requires explicit cleanup (`msgctl`).  
    - Less efficient than shared memory for large data transfers.  

-   Procedure Call (RPC) in Operating Systems

    🔹 Definition
    - RPC allows a program to execute a function on another computer in a network as if it were local.  
    - The client sends a request with arguments → server executes the function → result is returned.  
    - RPC hides networking details, so developers can think in terms of normal function calls.

    🔹 How RPC Works (Step by Step)
    1. Client Calls Stub → Client calls a local procedure (stub).  
    2. Marshalling → Stub packs parameters into a message.  
    3. Send to Server → Message sent across the network.  
    4. Server Stub → Unpacks message and calls actual server procedure.  
    5. Execution & Return → Server executes and returns result.  
    6. Back to Client → Server stub sends result back, client stub unpacks it.  

    👉 Execution flow alternates between caller and callee, like a query-response model.

    🔹 Types of RPC
    - Callback RPC → Both client and server can act as each other (peer-to-peer, interactive apps).  
    - Broadcast RPC → Client request broadcast to all servers (useful when multiple servers can handle).  
    - Batch-mode RPC → Groups multiple requests, sends together (reduces network overhead).  

    🔹 Key Components
    1. RPC Runtime → Library managing communication (binding, protocols, errors).  
    2. Stub → Helper code hiding complexity.  
        - Client stub → converts calls into messages (marshalling/unmarshalling).  
        - Server stub → provides interface to execute server procedures.  
    3. Binding → Connects client and server.  
        - Naming → Server exports interface.  
        - Locating → Client imports interface before communication.  

    🔹 Call Semantics
    - Retry Request Message → Decide whether to retry if server fails.  
    - Duplicate Filtering → Remove duplicate requests.  
    - Retransmission of Results → Resend lost results without re-executing.  

    ✅ Advantages
    - Easy Communication → Normal procedure calls in high-level languages.  
    - Hidden Complexity → Networking details abstracted.  
    - Flexibility → Works in local and distributed environments.  

    ❌ Disadvantages
    - Limited Parameter Passing → Only by value, no pointers.  
    - Slower Than Local Calls → Network overhead.  
    - Vulnerable to Failures → Depends on network and remote systems.  

    🔹 RPC vs REST
    - RPC → Procedure-oriented, hides networking, good for structured client-server calls.  
    - REST → Resource-oriented, uses HTTP verbs (GET, POST, PUT, DELETE).  
    - Modern RPC → gRPC, DRPC (efficient, widely used).  
    - Choice depends on application requirements (structured calls vs resource-based APIs).  

    🎯 Interview Tip
    - Always explain stub + marshalling/unmarshalling.  
    - Be ready to contrast RPC vs REST.  
    - Mention modern RPC frameworks (gRPC).  
    - Example question: *“How does RPC hide network complexity?”* → Answer: *By using stubs and runtime libraries.*  

-   Process Synchronization in Operating Systems

    -   Definition
        - Process Synchronization is a mechanism used to manage the execution of multiple processes that access shared resources.  
        - Its goals are to:  
            - Ensure data consistency  
            - Prevent race conditions  
            - Avoid deadlocks  

    -   Types of Processes (based on synchronization)
        1. Independent Process  
            - Execution of one process does not affect others.  
        2. Cooperative Process  
            - Execution of one process can affect or be affected by others.  
            - Requires synchronization to avoid conflicts.  

    -   Problems Due to Improper Synchronization
        - Inconsistency → Shared data becomes unreliable when multiple processes update simultaneously.  
        - Loss of Data → One process overwrites another’s update, leading to corruption.  
        - Deadlock → Processes get stuck waiting for each other’s resources.  

    -   Role of Synchronization in IPC (Inter-Process Communication)
        - Prevent Race Conditions → Ensures consistent results.  
        - Mutual Exclusion → Only one process in the critical section at a time.  
        - Process Coordination → Enables producer-consumer relationships.  
        - Deadlock Prevention → Avoids circular waits and indefinite blocking.  
        - Safe Communication → Ensures ordered message passing.  
        - Fairness → Prevents starvation by giving equal resource access.  

    -   Types of Synchronization
        1. Competitive Synchronization  
            - Processes compete for shared resources.  
            - Improper handling → inconsistency or data loss.  

        2. Cooperative Synchronization  
            - Processes depend on each other’s execution.  
            - Improper handling → deadlock.  

        Example (Linux pipeline):  
        ```bash
        ps | grep "chrome" | wc
        ```
        - `ps` → lists processes  
        - `grep` → filters output  
        - `wc` → counts words  
        👉 Cooperative synchronization: processes produce and consume data sequentially.

    -   Conditions That Require Synchronization
        1. Critical Section  
            - Code segment accessing shared variables.  
            - Must allow only one process at a time.  

        2. Race Condition  
            - Output depends on execution order of processes in the critical section.  

        3. Preemption  
            - OS interrupts a process before it finishes using a shared resource.  
            - Without synchronization → inconsistent values may be read.  

-   Critical Section in Synchronization

    🔹 Definition
    - A critical section is a part of a program where shared resources (memory, files, variables, databases) are accessed.  
    - To avoid race conditions and data inconsistency, only one process/thread should execute the critical section at a time.  
    - Synchronization techniques (mutex, semaphore, monitors) ensure safe and predictable execution.

    🔹 Structure of a Critical Section
    1. Entry Section  
        - Process requests permission to enter.  
        - Synchronization tools (mutex, semaphore) control access.  

    2. Critical Section  
        - Actual code accessing/modifying shared resources.  

    3. Exit Section  
        - Process releases lock/semaphore → allows others to enter.  

    4. Remainder Section  
        - Rest of the program not involving shared resources.  

    🔹 Critical Section Problem
    - Occurs when multiple processes access shared resources simultaneously.  
    - Leads to race conditions → final result depends on execution order.  

    Example:  
    Two bank transactions updating the same account balance at the same time → incorrect final balance.

    Pseudo-code:
    ```c
    do {
        flag = 1;
        while(flag);   // entry section
            // critical section
        if (!flag)
            // remainder section
    } while(true);
    ```

    🔹 Requirements of a Solution
    A good solution must ensure:

    1. Mutual Exclusion  
    - Only one process in the critical section at a time.  

    2. Progress  
    - If no process is inside, waiting processes must eventually get access.  
    - Choice of next process should not be postponed indefinitely.  

    3. Bounded Waiting  
    - Limit on how long a process waits before entering.  
    - Prevents starvation.  

    🔹 Solution Approach
    - Use locks (mutex, semaphores, monitors).  
    - Pseudo-code:
    ```c
    acquireLock();
    // critical section
    releaseLock();
    ```
    - Only one thread acquires lock → ensures mutual exclusion.  

    📊 Real-World Examples
    1. Banking System (ATM/Online Banking)  
    - Critical Section: Updating account balance.  
    - Issue: Two withdrawals at once → incorrect balance.  

    2. Ticket Booking System (Airlines/Movies/Trains)  
    - Critical Section: Reserving last available seat.  
    - Issue: Overbooking if two users book simultaneously.  

    3. Print Spooler in Networked Printer  
    - Critical Section: Sending jobs to printer queue.  
    - Issue: Jobs may mix or skip without synchronization.  

    4. Shared Document Editing (Google Docs/MS Word)  
    - Critical Section: Saving/writing shared document.  
    - Issue: Conflicting edits → data loss or version conflicts.  

-   Solutions to Process Synchronization Problems

    🔹 Background
    - In multiprogramming environments, multiple processes compete for shared resources (CPU, memory, files).  
    - Without synchronization → race conditions, inconsistent results, deadlocks.  
    - Over time, solutions evolved from hardware-level tricks to OS-level abstractions.

    🔹 Major Approaches
    1. Interrupt Disable  
    2. Locks (Software & Hardware)  
    3. OS-based Solutions (Mutex, Semaphores, Monitors)  

    1. Interrupt Disable
    - Process disables all hardware interrupts before entering critical section.  
    - Prevents preemption → ensures uninterrupted execution.  

    Problems:
    - Works only in uniprocessor systems.  
    - Dangerous: forgetting to re-enable interrupts → system hang.  
    - Gives too much power to user processes → misuse possible.  
    👉 Rarely used in practice.

    2. Locks
    Locks ensure only one process enters the critical section at a time.

    (a) Software-Based Locks
    - Implemented using shared variables (flags, turn variables, ticket numbers).  
    - Algorithms:  
        - Peterson’s Algorithm → elegant, but only for 2 processes.  
        - Dekker’s Algorithm → early solution, also for 2 processes.  
        - Bakery Algorithm → supports multiple processes (take-a-number system).  

    Problems:
    - Require busy waiting → wastes CPU cycles.  
    - Complex for many processes.  
    - Not suitable for modern multiprocessors.  

    (b) Hardware-Based Locks
    - Modern CPUs provide atomic instructions for lock implementation.  
    - Atomic = indivisible operation → prevents race conditions.  

    Examples:
    - Test-and-Set (TSL) → tests old value & sets lock in one step.  
    - Compare-and-Swap (CAS) → compares memory value, swaps atomically if equal.  
    - Spinlocks → processes busy-wait until lock is free.  

    Limitations:
    - Still involve busy waiting.  
    - No fairness guarantee → starvation possible.  
    - Only solve mutual exclusion, not higher-level coordination.

    2.1 Mutex (Mutual Exclusion Lock)
    - Built on hardware primitives (like spinlocks).  
    - Unlike raw locks, mutex blocks processes instead of busy waiting.  
    - Provides fair scheduling.  
    - Widely used in thread libraries (e.g., Pthreads) and OS kernels.

    3. OS-Based Solutions

    (a) Semaphores
    - Integer variable with two atomic operations:  
    - wait() → decrement, block if < 0.  
    - signal() → increment, wake one waiting process.  
    - Removes busy waiting → blocked processes sleep until resources available.  
    - Useful for producer-consumer problems.

    (b) Monitors
    - High-level construct combining mutual exclusion + condition variables.  
    - Only one process executes in a monitor at a time.  
    - Condition variables (wait, signal) simplify coordination.  
    - Safer and easier to use than raw locks/semaphores.  

    ✅ Advantages of Advanced Solutions
    - Avoid busy waiting → better CPU utilization.  
    - Provide fairness → prevent starvation.  
    - Easier to implement complex synchronization (producer-consumer, readers-writers).  

    ❌ Limitations
    - More complex to implement.  
    - Require OS/kernel support.  
    - Synchronization overhead may affect performance in lightweight tasks.  

-   Peterson’s Algorithm

    🔹 Definition
    - A software-based synchronization algorithm for two processes.  
    - Ensures mutual exclusion, progress, and bounded waiting without hardware support.  
    - Uses two shared variables:  
        1. `flag[i]` → indicates if process *i* wants to enter the critical section.  
        2. `turn` → indicates whose turn it is to enter the critical section.

    🔹 Working
    1. Entry Section  
    - Each process sets its `flag[i] = true` (wants to enter).  
    - Sets `turn = j` (gives priority to the other process).  
    - Waits until either the other process is not interested (`flag[j] = false`) or it’s its own turn.  

    2. Critical Section  
    - Process executes safely on shared resources.  

    3. Exit Section  
    - Sets `flag[i] = false` (done with critical section).  

    4. Remainder Section  
    - Executes rest of the program.  

    🔹 Pseudo-code (for Process i)
    ```c
    do {
        flag[i] = true;          // wants to enter
        turn = j;                // give chance to other
        while (flag[j] && turn == j); // wait if other wants to enter

        // ---- Critical Section ----

        flag[i] = false;         // exit section

        // ---- Remainder Section ----
    } while(true);
    ```

    🔹 Properties
    - Mutual Exclusion → Only one process enters at a time.  
    - Progress → If one process wants to enter, it eventually gets access.  
    - Bounded Waiting → Each process waits for a finite time.  

    ✅ Advantages
    - Simple, elegant solution for two processes.  
    - Does not require hardware support (purely software-based).  
    - Satisfies all three requirements of critical section problem.  

    ❌ Disadvantages
    - Works only for two processes.  
    - Requires busy waiting (CPU cycles wasted).  
    - Not practical for modern multiprocessor systems.  

    📊 Example Use Case
    - Two processes updating a shared variable (e.g., bank balance).  
    - Peterson’s Algorithm ensures only one process updates at a time → prevents race condition.  

-   Semaphores in Process Synchronization

    🔹 Definition
    - A semaphore is an integer variable used to control access to shared resources in concurrent systems.  
    - It ensures that only the allowed number of processes can use a resource at a given time.  
    - Widely used in multiprogramming systems for synchronization and mutual exclusion.

    🔹 Operations
    1. Wait (P / down)  
    - Decrements the semaphore value.  
    - If value < 0 → process is blocked until resource becomes available.  

    2. Signal (V / up)  
    - Increments the semaphore value.  
    - If there are waiting processes → one is unblocked.  

    Workflow:  
    ```c
    wait(S);   // request resource
    // critical section
    signal(S); // release resource
    ```

    🔹 Features of Semaphores
    - Mutual Exclusion → Only one process in critical section at a time.  
    - Process Synchronization → Coordinates execution order.  
    - Resource Management → Controls access to finite resources (e.g., printers).  
    - Reader-Writer Problem → Allows multiple readers but restricts writers.  
    - Deadlock Avoidance → Controls resource allocation order.  

    🔹 Types of Semaphores

    1. Counting Semaphore
        - Value ranges from 0 → N (number of resource instances).  
        - Useful when multiple identical resources exist.  
        - Example: Managing access to 5 printers.  

        Pseudocode:
        ```c
        struct semaphore {
            int count;      // available resources
            queue q;        // waiting processes
        };

        wait(semaphore s) {
            s.count--;
            if (s.count < 0) {
                q.push(p);
                block();
            }
        }

        signal(semaphore s) {
            s.count++;
            if (s.count <= 0) {
                Process p = q.pop();
                wakeup(p);
            }
        }
        ```

    2. Binary Semaphore (Mutex)
        - Value = 0 or 1 → acts like a lock.  
        - Ensures only one process enters critical section.  
        - Example: Managing access to a single file.  

        Pseudocode:
        ```c
        struct semaphore {
            int value; // 0 or 1
            queue q;
        };

        wait(semaphore s) {
            if (s.value == 1) {
                s.value = 0; // acquire lock
            } else {
                q.push(p);
                sleep();
            }
        }

        signal(semaphore s) {
            if (q.empty()) {
                s.value = 1; // release lock
            } else {
                Process p = q.front();
                q.pop();
                wakeup(p);
            }
        }
        ```

    🔹 Example (Two Processes P1 & P2, S initialized to 1)
    - State 1: S = 1, both in non-critical section.  
    - State 2: P1 executes `wait(S)` → S = 0, enters critical section.  
    - State 3: P2 tries `wait(S)` → blocked since S = 0.  
    - State 4: P1 executes `signal(S)` → S = 1, P2 enters.  

    👉 Guarantees mutual exclusion.


    🔹 Limitations of Semaphores
    - Priority Inversion → Low-priority process blocks high-priority one.  
    - Deadlock → Improper use may cause cyclic waiting.  
    - Complexity → Misuse of `wait()`/`signal()` leads to errors.  
    - Busy Waiting → In basic implementations, processes waste CPU cycles checking semaphore value.  

-   Monitors in Process Synchronization

    🔹 Definition
    - A monitor is a high-level synchronization construct that simplifies process/thread synchronization.  
    - Built on top of locks, monitors ensure automatic mutual exclusion.  
    - Unlike semaphores (where programmers explicitly call `wait()` and `signal()`), monitors encapsulate shared data + operations in one structure, making synchronization safer and easier.

    🔹 Key Points
    - A monitor is similar to a class/module grouping shared variables and functions.  
    - Only one thread can execute inside a monitor at a time → automatic mutual exclusion.  
    - In Java, monitors are implemented using `synchronized` methods/blocks (no explicit `monitor` keyword).  
    - Encapsulation: Shared data + operations are bundled together.  
    - Condition variables (`wait()`, `notify()`, `notifyAll()`) provide process coordination.  

    🔹 How Monitors are Implemented
    - Implemented at the programming language level, not directly by the OS.  
    - In Java:  
        - `synchronized` keyword ensures only one thread executes inside the monitor.  
        - Condition variables manage waiting/signaling.  
    - Encapsulation ensures automatic mutual exclusion without explicit semaphore calls.  

    🔹 Condition Variables in Monitors
    - Used inside monitors to control waiting/signaling.  
    - Operations:  
        - `wait()` → releases monitor lock, puts thread to sleep until signaled.  
        - `signal()` → wakes up one waiting thread.  
        - `broadcast()` (in some languages) → wakes up all waiting threads.  

    🔹 Pseudocode Example
    ```java
    class AccountUpdate {
        private int bal;
        condition sufficientFunds;   // condition variable

        void synchronized deposit(int n) {
            bal = bal + n;
            // signal waiting threads that funds are available
        }

        void synchronized withdraw(int n) {
            if (bal < n)
                wait(sufficientFunds);   // wait until funds available
            else
                bal = bal - n;
        }
    }
    ```

    🔹 Java Example (Bank Account Monitor)
    ```java
    class AccountUpdate {
        private int bal;

        void synchronized deposit(int n) {
            bal = bal + n;   // mutual exclusion guaranteed
        }

        void synchronized withdraw(int n) {
            bal = bal - n;   // mutual exclusion guaranteed
        }
    }
    ```

    Explanation:
    - `bal` → shared resource (account balance).  
    - `synchronized` → ensures only one thread executes deposit/withdraw at a time.  
    - Prevents race conditions in concurrent deposits/withdrawals.  

    🔹 Limitations of Monitors
    - Language Dependency → must be built into language/compiler.  
    - Compiler Burden → compiler generates extra code for monitor functionality.  
    - OS Dependency → compiler must interact with OS facilities for critical section handling.  
    - Limited Language Support → supported in Java, C, Ada, Concurrent Euclid, etc.  
    - Reduced Flexibility → tightly coupled with language/compiler → limited portability.  

-   Priority Inversion in Operating Systems

    🔹 Definition
    - Priority Inversion is a scheduling problem where a low-priority task holds a resource needed by a high-priority task, forcing the high-priority task to wait.  
    - Meanwhile, a medium-priority task (not needing the resource) can preempt the low-priority task, delaying the release of the resource further.  
    - Result → The priority order is inverted: medium-priority runs before high-priority, even though high-priority should have precedence.

    🔹 Causes of Priority Inversion
    1. Low-priority task (L) acquires a shared resource.  
    2. High-priority task (H) requests the resource → blocked until L releases it.  
    3. Medium-priority task (M) becomes runnable → preempts L.  
    4. H remains blocked until L eventually resumes and releases the resource.  

    👉 This leads to delays for H, sometimes predictable (bounded) or indefinite (unbounded).

    🔹 Types of Priority Inversion

    1. Bounded Priority Inversion
    - Delay is predictable and limited.  
    - High-priority task (H) waits only for:  
        - Low-priority task (L) to finish its critical section.  
        - Medium-priority task (M) to complete execution.  
    - Example Sequence:  
        - L acquires mutex → enters critical section.  
        - H arrives → blocked.  
        - M preempts L → runs to completion.  
        - L resumes → releases mutex.  
        - H acquires mutex → executes.  
    - Outcome: Delay = L’s critical section time + M’s execution time.

    2. Unbounded Priority Inversion
    - Delay is unpredictable and potentially indefinite.  
    - Happens when medium-priority tasks (M) keep preempting L while L holds the lock.  
    - Since L cannot finish, H remains blocked indefinitely.  
    - Outcome: High-priority task (H) may starve, causing system failure or watchdog timer triggers.  

    🔹 Solutions to Priority Inversion

    1. Priority Inheritance  
    - Temporarily elevates the priority of the low-priority task (L) holding the resource → matches the highest-priority waiting task (H).  
    - Ensures L finishes quickly and releases the resource.  

    2. Priority Ceiling Protocol  
    - Each resource is assigned a maximum priority ceiling.  
    - Prevents lower-priority tasks from acquiring resources needed by higher-priority tasks.  

    3. Avoiding Blocking  
    - Use non-blocking algorithms (e.g., lock-free data structures).  
    - Minimize shared resource usage → reduces chances of inversion.  

    📊 Real-World Example
    - Mars Pathfinder (NASA, 1997) → experienced system resets due to priority inversion.  
    - Solution: Implemented priority inheritance to fix the issue.  

-   How Program Compiled and Run ?

    -   High-Level Steps
    1. Pre-processing (`filename.i`)
    - Removes comments
    - Expands macros (`define`)
    - Expands header files (`include`)
    - Handles conditional compilation (`ifdef`, `ifndef`)
    - Output: Preprocessed source code (`filename.i`)

    2. Compilation (`filename.s`)
    - Converts preprocessed code into assembly instructions
    - Optimizations applied (depending on flags like `-O2`, `-O3`)
    - Output: Assembly code (`filename.s`)

    3. Assembling (`filename.o`)
    - Assembler converts assembly into machine code (binary)
    - Produces relocatable object file (`filename.o`)
    - Function calls (like `printf`) are still unresolved
    - Output: Object file (`filename.o`)

    4. Linking (Executable)
    - Combines object files + libraries
    - Resolves external symbols (e.g., `printf` from `libc`)
    - Adds startup code (e.g., `_start`, environment setup)
    - Output: Executable (`filename` or `a.out`)

    ⚙️ GCC Workflow Example
    ```bash
    gcc -Wall -save-temps filename.c -o filename
    ```

    This generates:
    - `filename.i` → Preprocessed source
    - `filename.s` → Assembly code
    - `filename.o` → Object file
    - `filename` → Final executable


    📊 Visual Diagram

    ```
    filename.c   →   Preprocessor   →   filename.i
    filename.i   →   Compiler       →   filename.s
    filename.s   →   Assembler      →   filename.o
    filename.o   →   Linker         →   filename (executable)
    ```

    🔍 Linking Types
    - Static Linking
        - All library code copied into executable
        - Larger file size, but independent of external libraries
        - Example: `gcc -static filename.c -o filename`

    - Dynamic Linking
        - Only references to shared libraries stored
        - Smaller executable, but depends on system libraries at runtime
        - Default in GCC (`printf` linked dynamically via `libc.so`)

    🧠 Interview Insights
    - Why multiple phases?
        - Separation of concerns → easier debugging & optimization
    - Why dynamic linking by default?
        - Saves space, allows library updates without recompiling
    - How to inspect intermediate files?
        - `gcc -E filename.c` → only preprocessing
        - `gcc -S filename.c` → stop at assembly
        - `gcc -c filename.c` → stop at object file

-   Address Binding in Operating Systems

    🔎 What is Address Binding?
    - Definition: Mapping of logical (virtual) addresses generated by a program to physical addresses in RAM.  
    - Logical Address: Generated by CPU (what the process “sees”).  
    - Physical Address: Actual location in memory (what hardware “uses”).  
    - Role of OS: Handles this mapping transparently via the Memory Management Unit (MMU).

    📍 Why Address Binding is Needed
    - Memory Management: Efficient allocation/deallocation of memory.  
    - Symbol Resolution: Resolves symbolic references (functions, variables) to actual addresses.  
    - Code Relocation: Allows executables to run at different memory locations.  
    - Dynamic Memory Allocation: Supports runtime allocation (`malloc`, `free`).  

    ⚙️ Types of Address Binding

    1. Compile-Time Binding
    - Done by compiler.  
    - Symbolic addresses → fixed physical addresses at compile time.  
    - Pros: Simple, efficient.  
    - Cons: Inflexible (cannot adapt to runtime changes).  
    - Example: Global variables with fixed addresses.  

    2. Load-Time Binding
    - Done by loader when program is loaded into memory.  
    - Addresses assigned based on available memory at load time.  
    - Pros: More flexible than compile-time.  
    - Cons: Still fixed once loaded.  
    - Example: Dynamic libraries resolved at load time.  

    3. Execution-Time (Dynamic) Binding
    - Done by MMU during program execution.  
    - Logical addresses translated to physical addresses dynamically.  
    - Pros: Maximum flexibility (supports relocation, paging, segmentation).  
    - Cons: Requires hardware support (MMU).  
    - Example: Virtual memory systems in Windows/Linux/Unix.  

    📊 Visual Diagram

    ```
    Program → Logical Address → Address Binding → Physical Address
    --------------------------------------------------------------
    Compile-Time   → Fixed at compilation
    Load-Time      → Fixed when loaded
    Execution-Time → Resolved dynamically during execution
    ```

    🧩 Example
    Program P1 instructions:  
    ```
    I1 → 10
    I2 → 20
    I3 → 30
    I4 → 40
    ```
    - Compile-Time: These addresses directly mapped to fixed RAM locations.  
    - Load-Time: Loader decides where to place them in memory.  
    - Execution-Time: MMU translates logical addresses (10, 20, 30, 40) to physical frames dynamically.  

    🎯 Interview Insights
    - Compile vs Load vs Execution Binding: Flexibility increases as we move from compile → load → execution.  
    - Execution-Time Binding = Virtual Memory: Enables paging, segmentation, swapping.  
    - Real-world OS: Windows, Linux, Unix → rely heavily on dynamic binding.  

-   Memory Management in Operating System  
    Memory management is a critical function of an operating system that ensures efficient use of memory resources. It controls how memory is allocated and deallocated to processes, directly impacting performance and stability.

    -   Why Memory Management is Needed
        Before and after process execution, memory must be allocated and freed. The OS keeps track of used and free memory, minimizes fragmentation, ensures proper utilization of main memory, and maintains data integrity during execution.

    📌 Address Spaces
    - Logical Address Space: The set of addresses a process generates via the CPU (process’s view).  
    - Physical Address Space: The actual RAM addresses where data and instructions reside.  

    📌 Loading and Linking
    Processes are loaded into memory by a loader:  
    - Static Loading loads the entire program into a fixed address (requires more space).  
    - Dynamic Loading loads routines only when needed, saving memory.  

    Linking combines object files into executables:  
    - Static Linking merges all modules into one executable (no runtime dependency).  
    - Dynamic Linking uses stubs; routines are loaded at runtime if not already in memory.  

    📌 Swapping
    When memory is limited, processes are swapped between main memory and secondary storage. Lower-priority processes may be swapped out to allow higher-priority ones to run, resuming later when swapped back. Transfer time depends on data size.

    📌 Memory Management Techniques
    -   Monoprogramming (Without Swapping)
    Memory is split into two sections: OS and user program. The OS is often loaded at low memory (due to interrupt vectors) and protected using a fence register.  

    -   Multiprogramming with Fixed Partitions
    Memory is divided into fixed contiguous partitions, each holding one process. The OS maintains a partition table to track allocation:

    | Starting Address | Size  | Status     |  
    |------------------|-------|------------|  
    | 0k               | 200k  | allocated  |  
    | 200k             | 100k  | free       |  
    | 300k             | 150k  | free       |  
    | 450k             | 250k  | allocated  |  

    📌 Allocation Approaches
    - Contiguous Allocation: Each process gets one continuous block of memory.  
    - Non-Contiguous Allocation: Processes are split across different locations:  
        - Paging: Fixed-size pages mapped to frames via page table.  
        - Segmentation: Variable-size segments (code, data, stack) mapped via segment table.  

    📌 Fragmentation
    As processes are loaded/removed, gaps appear:  
    - Internal Fragmentation: Wasted space inside allocated blocks.  
    - External Fragmentation: Free memory exists but is scattered, preventing large allocations.  

    📌 Allocation Strategies
    Efficient allocation is vital for performance:  
    - Fixed Partition Allocation: Memory divided into fixed partitions.  
    - Dynamic Partition Allocation: Variable partitions sized to processes (less waste, more fragmentation).  
    - Placement Algorithms:  
        - *First Fit*: First available block large enough.  
        - *Best Fit*: Smallest block that fits, minimizing waste.  
        - *Worst Fit*: Largest block, leaving biggest leftover space.  
        - *Next Fit*: Like First Fit but search continues from last allocation point.  

-   Fragmentation in Operating System

    1. What is Fragmentation?

    Fragmentation is a condition where memory or storage becomes broken into small, scattered pieces, making it difficult to allocate space efficiently.  
    It usually happens when processes or files are loaded and removed repeatedly, creating gaps (holes) that cannot be used effectively.

    2. What is Fragmentation in an Operating System?

    In OS memory management, fragmentation occurs when free memory is divided into small non-contiguous blocks, and these blocks are too small to satisfy incoming process requests.

    - When processes load/unload, holes are created.  
    - These holes collectively may be enough to fit a process, but individually they are too small.  
    - This leads to wastage of memory and poor allocation efficiency.  

    Thus, fragmentation refers to memory becoming divided and unusable, causing inefficient use of system memory.

    3. Cause of Fragmentation

    Fragmentation happens because:

    - A file or process may be too large for one contiguous block.  
    - Free memory or storage is scattered across the space.  
    - Frequent creation/deletion of files or processes.  
    - Dynamic memory allocation leads to different block sizes being used.  

    The OS must then spend more time searching for available blocks, reducing performance.

    4. Effect of Fragmentation

    - Slower performance because the system must search for multiple fragments.  
    - Longer access time since the disk head jumps between locations.  
    - Higher system load, causing lags and slow applications.  
    - Storage space gets wasted.  
    - Risk of system crashes when the system runs out of usable memory.  
    - Reduced battery life (disk works harder).  
    - In extreme cases → data loss or file corruption.  

    5. Types of Fragmentation

    There are two main types:

        A. Internal Fragmentation

        Occurs inside an allocated block when the OS allocates fixed-size memory blocks, and the process/file doesn't use the entire block.

        Example:
        - Allocated block = 64KB  
        - File size = 40KB  
        - Wasted = 24KB (internal fragmentation)  

        Happens in:
        - Fixed partitioning  
        - Paging (slightly, at the last page)  

        B. External Fragmentation

        Occurs when free memory is scattered into many small non-contiguous blocks, even though the total free memory is enough.

        Example:  
        Free blocks available: 10KB + 12KB + 8KB + 6KB  
        Process requires 30KB → cannot be allocated because memory is not contiguous.  

        Happens in:
        - Variable partitioning  
        - Dynamic memory allocation (malloc, free)  

    6. Fragmentation at Different Levels

    Fragmentation can occur not just in RAM but also in:

        A. File Systems
        Files stored in non-contiguous blocks → slow read/write.  

        B. Memory Management
        Dynamic allocation leaves behind holes → external fragmentation.  

        C. Networks
        Large packets broken into smaller fragments → needs reassembly.  

    7. How Fragmentation Affects System Performance

        1. Slower Disk/Memory Performance
        More movement → more access time → system becomes slow.  

        2. Wasted Disk and Memory Space
        Small holes cannot be used for new files/processes.  

        3. Data Loss Risk
        Severe fragmentation may cause:
        - Write failures  
        - Corrupted files  
        - Out-of-space errors  

        4. System Crashes
        Fragmented memory leads to:
        - Kernel failures  
        - Application crashes  

        5. Reduced Battery Life
        Disk/SSD needs to work harder.  

    8. Role of Fragmentation in Operating System

        Fragmentation impacts:
        - Memory allocation efficiency  
        - System speed  
        - Stability  
        - Disk usage  

        Major role: It reduces performance by increasing read/write and allocation time.  
        Thus, minimizing fragmentation is crucial for smooth system functioning.  

    9. Defragmentation

        Defragmentation is the process of:
        - Rearranging fragments  
        - Making files contiguous  
        - Increasing access speed  

        Modern OS and SSDs handle fragmentation differently, but HDD-based systems still benefit greatly.  

    10. Advantages of Fragmentation

        Although mostly harmful, some side observations:

        ✔ Better use of scattered storage blocks
        A file can be stored even if no single large block is free.  

        ✔ Less rejection of file storage
        Large files can still be saved in smaller scattered blocks.  

        ✔ Easier to store large dynamic files
        Useful when managing many small free blocks.  

    11. Disadvantages of Fragmentation

        ❌ Slower access
        System must read multiple fragments.  

        ❌ Harder file management
        Non-contiguous storage complicates retrieval.  

        ❌ Reduced storage lifespan
        More writes → more wear (especially SSD).  

        ❌ Extra metadata needed
        Information about each file fragment must be tracked.  

        ❌ Lower performance
        Both memory and disk operations slow down significantly.  

    12. Conclusion

        Fragmentation in an OS refers to scattered, unusable memory or storage, leading to:

        - Poor performance  
        - Wastage of space  
        - Slower access  
        - System instability  

        Two main types are:
        - Internal fragmentation → unused space inside allocated blocks  
        - External fragmentation → free memory scattered into small chunks  

        Reducing fragmentation (via compaction or defragmentation) is essential for efficient system performance.   

-   Memory Partitioning in Operating Systems

    Memory partitioning is the technique of dividing main memory into regions for process allocation. It can be broadly classified into Contiguous Allocation and Non‑Contiguous Allocation.

    📌 Contiguous Memory Allocation
    Definition: Each process is allocated a single continuous block of memory. All data for the process resides in adjacent memory locations.  

    -   Fixed Partitioning
        Memory is divided into fixed partitions at system startup.  

        - Equal-Sized Partitions  
            - All partitions have the same size.  
            - ✅ Simple implementation.  
            - ❌ Internal Fragmentation: Small processes waste unused space inside partitions.  
            - ❌ Large processes may not fit if partition size is too small.  

        - Unequal-Sized Partitions  
            - Partitions of varying sizes.  
            - ✅ Better fit for processes of different sizes.  
            - ❌ External Fragmentation: Free partitions may exist but not match process size.  
            - ❌ Still suffers from internal fragmentation if process doesn’t fully use partition.  

        -   Dynamic Partitioning
            Partitions are created at runtime based on process size.  

            - ✅ Reduces internal fragmentation (process gets exactly what it needs).  
            - ❌ External Fragmentation: Free memory becomes scattered into small unusable gaps.  
            - ❌ Allocation depends on placement algorithms (First Fit, Best Fit, Worst Fit, Next Fit). 

            Data Structures for Free Space Management (To check which block is free and which is Assigned)
            - Bitmap
                - Memory divided into small units (e.g., blocks).
                - Each unit represented by a bit: 0 = free, 1 = allocated.
                - ✅ Simple representation, easy to check availability.
                - ❌ Searching for large contiguous free blocks can be slow.
            - Linked List
                - Free and allocated memory blocks maintained in a linked list.
                - Each node stores: starting address, size, and status (free/allocated).
                - ✅ Efficient traversal and merging of free blocks.
                - ❌ Overhead of maintaining pointers and list traversal.
            
            -   Placement (Mapping) Algorithms
                - First Fit
                    - Allocates the first free block large enough for the process.
                    - ✅ Fast, simple.
                    - ❌ May leave small unusable gaps at the beginning.
                - Best Fit 
                    - Allocates the smallest free block that fits the process.
                    - Need to Search All ll nodes to find best fit
                    - ✅ Minimizes wasted space.
                    - ❌ Can cause many small fragments.
                - Worst Fit
                    - Allocates the largest free block available.
                    - ✅ Leaves larger leftover free blocks for future allocations.
                    - ❌ Often wastes memory, poor utilization.
                - Next Fit
                    - Similar to First Fit but continues searching from the last allocated position.(in LL)
                    - ✅ Distributes allocations more evenly.
                    - ❌ Still suffers from fragmentation.
                
                Out of All these First Fit Algo Comes Out tob Best

        -   Compaction
            A technique to reduce external fragmentation by shifting processes to create one large free block.  

            - ✅ Makes large contiguous memory available.  
            - ❌ Costly in time and CPU overhead.  
            - ❌ Not suitable for real-time systems.  

    -    Non‑Contiguous Memory Allocation
        Definition: A process is divided into smaller parts that can be placed in different, non-adjacent memory locations.  

        Paging
        - Memory divided into fixed-size frames; process divided into fixed-size pages.  
        - OS maintains a page table mapping logical pages to physical frames.  
        - ✅ Eliminates external fragmentation.  
        - ❌ Overhead of page table management.  

        Segmentation
        - Process divided into variable-sized segments (code, data, stack).  
        - OS maintains a segment table mapping logical segments to physical memory.  
        - ✅ Matches logical program structure.  
        - ❌ Suffers from external fragmentation.  

        Hybrid Approaches
        - Paged Segmentation: Segments further divided into pages.  
        - ✅ Balances logical structure with reduced fragmentation.  

    📌 Flow Recap
    1. Contiguous Allocation → Fixed (equal/unequal) → Problems (internal/external fragmentation)  
    2. Dynamic Partitioning → Problem (external fragmentation) → Compaction (solution but costly)  
    3. Non‑Contiguous Allocation → Paging (no external fragmentation, overhead) → Segmentation (logical, external fragmentation) → Hybrids  








-   Paging in Operating System

    -   What is Paging?

        Paging is a memory management technique in which:

        - A process is divided into fixed-size blocks called pages.  
        - Physical memory (RAM) is divided into fixed-size blocks called frames.  
        - The page size = frame size.  
        - Pages of a process can be loaded into any available frame, not necessarily contiguous.  

        Key points
        - ✔ Process does NOT need contiguous memory  
        - ✔ Entire process need NOT be in memory at once  
        - ✔ Allows processes larger than physical memory  
        - ✔ Simplifies memory allocation (fixed-size blocks)  

    -   Why is Paging Needed?

        2.1 Solving Fragmentation
        - Memory may not have one large continuous block free.  
        - Paging fits pages into scattered free frames.  

        2.2 Dynamic Process Growth
        - Process size may grow or shrink.  
        - Paging avoids moving the whole process in memory.  

        2.3 Efficient Allocation
        - Fixed-size frames make allocation and replacement simple.  

    -   Logical & Physical Address Spaces

        Logical (Virtual) Address Space
        - Addresses generated by CPU.  
        - Consists of logical pages.  

        Example:  
        If Logical Address Space = 2^27 → addresses need 27 bits.  

        Physical Address Space
        - Actual addresses in RAM.  
        - Consists of physical frames.  

        Example:  
        Physical Address Space = 2^24 → addresses need 24 bits.  

    -   Page Table

        The OS maintains a page table to track where each logical page is stored in physical memory.

        Page Table Functions
        - Maps page number → frame number  
        - Used by the MMU (Memory Management Unit)  
        - Converts logical address → physical address  

        Page Table Entry (PTE) contains:
            - Frame Number → identifies which frame holds the page
            - Valid/Invalid Bit → indicates if the page is currently in main memory  
                - Valid = page is in RAM  
                - Invalid = page is not in RAM (must be fetched from disk)
            - Dirty Bit → shows if the page has been modified while in RAM  
                - If Dirty = 1 → page has been changed, must be written back to disk before replacement  
                - If Dirty = 0 → page is clean, no need to write back (makes system faster)
            - Reference Bit → used for page replacement algorithms (tracks if page was recently accessed)
            - Protection Bits → control access rights (read/write/execute)
 
        Size
        - One entry per page  
        - Page table size = number of pages in logical address space  

        Storage
        - Kept in main memory (not registers, unless very small)  
        - Requires fast lookup → TLB is used  

    -   Address Translation in Paging

    The logical address generated by CPU is split into:

    - Logical Address = p + d  
        - `p` (page number): Index in page table  
        - `d` (offset): Position inside that page  

    - Physical Address = f + d  
        - `f` (frame number): Obtained from page table  
        - `d` (offset): Same offset as in logical address  

    Formula:  
    `Physical Address = (Frame_Number << bits_in_offset) + Offset`  

    -   Step-by-Step Working of Paging ![alt text](image-18.png)

        1. Divide Address Spaces  
            - Logical → pages  
            - Physical → frames  

        2. Allocate Frames  
            - OS loads pages into free frames  
            - Pages can go to any frame  

        3. Build Page Table  
            - For each page, record frame number  

        4. Translate Address  
            - MMU uses page number to find frame number  
            - Append offset → physical address  

        5. Handle Page Fault  
            - If page not in memory → bring it from disk  

        6. Run Program  
            - CPU continuously uses page table during execution  


    -   Numerical Example

        Given:
        - Physical Address = 12 bits → Physical Memory = 4K words  
        - Logical Address = 13 bits → Logical Memory = 8K words  
        - Page size = frame size = 1K words  

        Calculate:
        - Number of Frames = Physical Memory / Frame Size = 4K / 1K = 4 frames = 2²  
        - Number of Pages = Logical Memory / Page Size = 8K / 1K = 8 pages = 2³  

        Thus:
        - Page number → 3 bits  
        - Offset → 10 bits (1K = 1024 = 2¹⁰)  

    -   Hardware Support for Paging ![alt text](image-19.png)

        8.1 MMU (Memory Management Unit)
        - Performs logical → physical translation  
        - Uses page table and TLB  

        8.2 Page Table Storage
        - Can be stored in CPU registers if very small  
        - Otherwise stored in RAM  

        8.3 TLB (Translation Lookaside Buffer)
        The TLB is a:  
            - High-speed associative memory (hardware cache)  
            - Stores recent PTEs  
            - Works like a small, fast page-table cache  

        TLB Entry:  
        - Tag = page number  
        - Value = frame number  

        TLB Workflow:  
        1. CPU generates logical address  
        2. Check TLB  
        3. Hit → Fast translation  
        4. Miss → Access page table in RAM  

    -   Memory Access Time

        Without TLB
        Two accesses needed:  
        - Page table in memory  
        - Actual data in memory  

        Effective access time:  
        `EAT = m (page table access) + m (memory access) = 2m`  
        (Where `m` = one memory access time)  

        With TLB
        If hit ratio = α:  
        `EAT = α * m + (1 - α) * (2m)`  

-   Virtual Memory in Operating System

    1. What is Virtual Memory?

    Virtual memory is a memory management technique that provides an application the illusion of having a large, continuous block of memory, even if the physical RAM is limited.

    Key Idea
    - Programs are divided into pages  
    - Parts of the program not currently needed are moved to disk (swap space)  
    - Required pages are brought back into RAM when needed  

    Benefits
    - Programs larger than physical RAM can run  
    - Only required portions of a program are loaded  
    - Enables efficient multitasking  

    2. Objectives of Virtual Memory
    - A program does not need to be fully loaded in RAM to execute  
    - Programs can be bigger than physical memory  
    - Provides the illusion of a very large memory space  
    - Uses RAM + disk to manage memory  
    - Increases multitasking capability (more programs run at once)  

    3. How Virtual Memory Works
    - Applications use virtual addresses  
    - CPU does not use physical addresses directly  
    - Memory Management Unit (MMU) converts virtual → physical addresses  
    - Pages not in RAM are placed in disk (swap file)  
    - When CPU accesses a missing page → page fault occurs → OS loads the page from disk  

    4. Types of Virtual Memory

        -   Paging
            - Memory is divided into fixed-size blocks:  
            - Page → Virtual memory block  
            - Frame → Physical memory block  
            - Pages not in use are moved to disk (swap file)  
            - Needed pages are swapped back → page swapping

            Page Fault Service Time
            If:
            - Main memory access time = m  
            - Page fault service time = s  
            - Page fault rate = p  

            Then:

            Effective Memory Access Time = p * s + (1-p)* m

            Analogy
            - Page = puzzle piece (virtual)  
            - Frame = location on board (physical)  

            Even large programs can run because their pages map to available frames.  

        -   Segmentation
            - Memory is divided into variable-size segments (code, data, stack, etc.)  
            - Uses a segment table to store:  
                - Base address  
                - Limit  
                - Validity bit  
            - Segment not in use can be stored on disk and loaded when required  

    5. Applications / Uses of Virtual Memory
    - Increases effective memory by extending RAM using disk  
    - Memory isolation: each process has its own virtual address space  
    - Efficient memory use because only required data is loaded  
    - Simplifies development: programmers write code assuming large memory is available  

    6. Management of Virtual Memory (Practical Points)

        1. Adjust Page File Size
        - OS usually manages page file automatically  
        - Advanced users can set custom sizes for performance tuning  

        2. Place Page File on a Fast Drive
        - An SSD improves swap speed  
        - If multiple drives exist, put page file on a separate drive  

        3. Monitor and Optimize Usage
        - Use performance monitoring tools  
        - Uninstall unnecessary background apps to free virtual memory  

        4. Disable Virtual Memory (Only if High RAM)
        - If system has 16GB+ RAM, page file may be reduced or disabled  
        - Must be done carefully — some apps still expect paging  

        5. Optimize System Settings
        - Update drivers  
        - Adjust OS performance settings for better memory efficiency  

    7. Benefits of Virtual Memory
    - ✔ Supports Multiprogramming → multiple processes run at once using demand paging  
    - ✔ Allows Larger Programs → programs bigger than RAM can run  
    - ✔ No Need to Upgrade RAM Immediately → disk acts as backup memory  
    - ✔ Security & Isolation → each process gets its own virtual address space  
    - ✔ Improves CPU & System Performance → smoother multitasking, optimized resource usage  
    - ✔ Better Memory Management → avoids external fragmentation and automates memory movement  

    8. Limitations of Virtual Memory
    - ❌ Slower Performance → disk access slower than RAM  
    - ❌ Risk of Data Loss → swapping during power/disk failure  
    - ❌ Higher OS Complexity → OS must manage mappings, page tables, faults, swapping  

    9. Virtual Memory vs Physical Memory

    | Feature        | Virtual Memory                        | Physical Memory (RAM)            |
    | -------------- | ------------------------------------- | -------------------------------- |
    | Definition | Memory abstraction using disk storage | Real hardware memory used by CPU |
    | Location   | Stored on disk/SSD                    | On motherboard                   |
    | Speed      | Slow (disk I/O)                       | Fast (direct CPU access)         |
    | Capacity   | Large (limited by disk size)          | Limited by installed RAM         |
    | Cost       | Cheap                                 | Expensive                        |
    | Access     | Indirect (paging, swapping)           | Direct CPU access                |
    | Volatility | Non-volatile                          | Volatile (erased on power-off)   |

-   Translation Lookaside Buffer (TLB) in Paging

    Paging is a memory-management technique used in operating systems to implement virtual memory. Every process uses virtual addresses, which must be translated into physical memory addresses. This translation is done using page tables.

    However, page table lookups can be slow, so modern systems use a special high-speed cache called the Translation Lookaside Buffer (TLB).

    -   The Problem: Page Table Lookup Overhead
        When the CPU generates a virtual address:

        A naive paging system does:
        1. Access page table (in main memory) → find the frame number  
        2. Access physical memory → get the actual data  

        ➡️ Each memory access = 2 memory accesses, which slows the system significantly.

        Example:  
        If memory access time = 100 ns → paging causes 200 ns effective access time.

    -   Why Not Store Page Table in CPU Registers?

        Registers are the fastest but also extremely limited:

        - Registers can hold only a few hundred entries (0.5k–1k PTEs)  
        - A full page table for large processes can have hundreds of thousands to millions of entries  

        Example:  
        32-bit virtual address, 4 KB page →  
        Virtual pages = \( \frac{2^{32}}{2^{12}} = 2^{20} = 1,048,576 \) pages  
        → Page table = 1 million entries → far too big for registers  

        ➡️ Therefore, page tables must be kept in main memory.

    -   The Solution: Translation Lookaside Buffer (TLB)

        TLB is a high-speed associative cache (located inside the CPU) that stores recently used page table entries (PTEs).

        Think of it as a mini-cache for page table lookups.

    -   How TLB Works (Step-by-Step) ![alt text](image-20.png)

        -   TLB Hit
            When page number is found in TLB:
            1. CPU generates virtual address  
            2. Page number is checked in TLB  
            3. Found → TLB gives corresponding frame number instantly  
            4. Physical memory is accessed to fetch data  

            ➡️ Only 1 memory access (data access)  
            ➡️ Fast and efficient  

        -   TLB Miss
            When page number is NOT in TLB:
            1. CPU checks TLB → not found  
            2. OS looks up page table entry in main memory  
            3. Gets frame number  
            4. Updates TLB with this new entry  
            5. Accesses physical memory for data  

            ➡️ 2 memory accesses  
            ➡️ Slower than hit, but improved next time  

        If TLB is full, a replacement policy is used:
        - FIFO  
        - LRU (most common)  
        - LFU / MFU  

    -   Effective Memory Access Time (EMAT)

        TLB improves performance, but not all requests hit the TLB.  
        Therefore, effective time is calculated using:

        EMAT = h(c + m) + (1 - h)(c + n * m)

        Where:

        | Symbol | Meaning                                                                |
        | ------ | ---------------------------------------------------------------------- |
        | h  | TLB hit ratio                                                          |
        | c  | TLB lookup time                                                        |
        | m  | Main memory access time                                                |
        | n  | Number of memory accesses needed on miss (usually 2 for simple paging) |

        ➡️ Higher hit ratio (h) → much faster performance  
        ➡️ Even 90–99% hit ratio drastically drops EMAT  

    -   Why TLB Dramatically Improves Performance
        - Reduces extra memory lookup for page table  
        - Only frequently-used PTEs are cached  
        - Most real workloads exhibit locality → high TLB hit ratio  
        - Essential in 64-bit architectures where page tables are huge  

    -   Advantages of TLB
        - ✔ Fast address translation → almost CPU speed during hits  
        - ✔ Lower average memory access time (AMAT)  
        - ✔ Better utilization of locality → frequently accessed pages cached  
        - ✔ Efficient for large address spaces → critical in multi-level or inverted page tables  

    -   Summary Table

        | Feature         | Description                             |
        | --------------- | --------------------------------------- |
        | TLB         | Cache storing recent PTEs               |
        | Purpose     | Speed up virtual → physical translation |
        | Hit         | Fast, single memory access              |
        | Miss        | Page table lookup + TLB update          |
        | Replacement | FIFO, LRU, LFU, MFU                     |
        | Benefit     | Reduces EMAT significantly              |

-   Demand Paging in Operating System

    Demand paging is a core concept of virtual memory where the operating system loads memory pages only when the CPU actually needs them. Instead of loading an entire program into RAM at once, OS loads pages on demand.

    1. What Is Demand Paging?

    Demand paging is a lazy loading technique:

    - A program’s pages stay on disk initially  
    - Pages enter RAM only when the CPU references them  
    - If a referenced page is absent from RAM, a page fault occurs  
    - The OS fetches the page from disk → places it in memory → updates page table → resumes execution  

    ➡️ This gives the illusion that the entire program is in memory while actually only a small portion is.

    2. Pure Demand Paging

    Pure demand paging is a stricter form:

    - No pages are loaded at program start  
    - All pages are initially marked “on disk”  
    - The first instruction itself causes a page fault  
    - Pages load *only as they are accessed*, one by one  

    Benefits
    - Maximum memory savings  
    - Useful for very large programs  

    Drawbacks
    - Many page faults at start (cold start)  
    - Significant overhead if many pages must be loaded quickly  

    3. How Demand Paging Works (Step-by-Step)

        Let’s assume a process P has pages P0, P1, P2, P3.  
        Initially only P1 and P3 are in memory.

        1) Program Execution
        OS loads the program metadata and empty page table structure.

        2) Create Page Table
        Each page is flagged as:
        - Present bit = 1 → page in RAM  
        - Present bit = 0 → page not in RAM (on disk)  

        3) Page Fault Occurs
        When CPU attempts to access a page not in memory:
        - Present bit = 0 → page fault interrupt triggered  

        4) OS Handles Page Fault
        OS:
        - Suspends the process  
        - Checks whether the page exists on disk  
        - Locates free frame in RAM (or triggers replacement)  
        - Reads the required page from disk into that free frame  

        5) Update Page Table
        OS sets:
        - Present bit = 1  
        - Frame number = location in RAM  

        6) Resume Process
        The instruction that caused the fault is executed again—this time the page is present.

        7) Page Replacement (If RAM is full)
        If no free frames exist:
        - OS uses a page replacement algorithm (LRU, FIFO, LFU, etc.) to evict a page and bring in the required one  

        8) Cleanup (On Process Termination)
        - All related frames freed  
        - Page table entries marked invalid  

    4. Effects of Demand Paging on System Performance

        Advantages
        - Efficient memory usage (only needed pages loaded)  
        - More processes fit into memory → high multiprogramming  
        - Faster program startup (no full load needed)  

        Disadvantages
        - Page faults cause large delays (disk ≫ RAM)  
        - Too many faults → thrashing (constant swapping)  
        - Performance sensitive to page replacement algorithms  

        If implemented poorly, it increases:
        - Page fault rate  
        - Disk I/O load  
        - CPU idle time  
        - Overall delay  

    5. Page Replacement Algorithms Used

        When memory is full, OS must pick a page to remove.

        1) FIFO (First-In-First-Out)
        - Removes oldest loaded page  
        - Simple, but can cause Belady’s anomaly and thrashing  

        2) LRU (Least Recently Used) — Most Effective
        - Removes the page not used for the longest time  
        - Good approximation of actual usage  
        - Higher implementation cost  

        3) LFU (Least Frequently Used)
        - Removes the least accessed page  
        - Good for stable workloads  
        - Requires counters for each page  

        4) MRU (Most Recently Used)
        - Removes page used most recently  
        - Useful in stack-like access patterns  

        5) Random
        - Picks any random page  
        - Cheap but unpredictable  

    6. Demand Paging vs Pre-paging

        | Feature         | Demand Paging                  | Pre-Paging                      |
        | --------------- | ------------------------------ | ------------------------------- |
        | When pages load | Only when needed           | Before they are needed      |
        | Initial load    | Minimal                        | Multiple pages upfront          |
        | Memory use      | Very low                       | Higher memory usage             |
        | Delay           | Page faults cause delays       | Reduces early page faults       |
        | Assumption       | Pages needed are unpredictable | Nearby pages likely needed soon |
        | Risk            | High page faults               | Wasted memory (if pages unused) |

        Summary:
        - Demand Paging = Lazy loading → Saves memory but slower during faults  
        - Pre-paging = Prefetching → Faster runtime but may waste memory  

    7. Why Demand Paging Is Used?

        Demand paging helps when:
        - Program size > physical memory  
        - Many processes run concurrently  
        - Workload exhibits locality of reference  
        - Memory is limited (laptops, embedded systems)  

        It enables:
        - Efficient virtual memory  
        - Reduced memory footprint  
        - Smooth multitasking  





-   Thrashing in Operating System

    1. What is Thrashing? ![alt text](image-22.png)

    Thrashing occurs when the OS spends more time swapping pages between RAM and disk than executing actual processes.  
    This leads to:

    - Very high page fault rate  
    - Very low CPU utilization  
    - Excessive disk I/O  
    - Processes making little to no progress  

    🔄 Thrashing Cycle
    1. Too many processes loaded → high degree of multiprogramming  
    2. Insufficient frames per process  
    3. Frequent page replacements → more page faults  
    4. CPU utilization drops  
    5. OS thinks CPU is idle → loads even more processes  
    6. Page faults increase even more → system starts thrashing  

    2. Locality Model (Why Thrashing Happens)

    A locality = set of pages a process actively uses at a time.  
    Examples of localities:
    - A function call  
    - Loop body  
    - Data structure access  

    🧠 Key Insight
    - If frames ≥ locality → few page faults → smooth execution  
    - If frames < locality → frequent faults → thrashing  

    💡 Thrashing occurs when active localities of many processes do NOT fit in RAM simultaneously.

    3. Techniques to Handle Thrashing

        1. Working Set Model

        The working set of a process is the set of pages it accessed in the last Δ references (window size).

        Notation:
        - WSSᵢ = Working set size of process *i*  
        - D = Σ WSSᵢ = Total demand for frames  
        - m = Total available frames  

        Conditions:
        - If D > m → Thrashing occurs  
        - If D ≤ m → No thrashing  

        Choosing Δ:
        - Large Δ → working sets overlap too much  
        - Small Δ → working sets may be incomplete  

        ➡️ This method ensures each process gets enough frames to cover its current locality.

        2. Page Fault Frequency (PFF) ![alt text](image-21.png)

            PFF avoids thrashing by directly monitoring each process’s page fault rate.

            Working:
            1. Define:  
            - Upper bound on acceptable fault rate  
            - Lower bound on acceptable fault rate  

            2. If fault rate > upper limit  
            → Give the process more frames  

            3. If fault rate < lower limit  
            → Take away frames (reclaim them)  

            4. If no free frames are available:  
            → Suspend some processes  
            → Reallocate their frames to active processes  

            ➡️ This dynamically balances memory among processes.

    ⭐ Summary Table

    | Concept                        | Description                                                            |
    | ------------------------------ | ---------------------------------------------------------------------- |
    | Thrashing                  | Excessive paging → low CPU utilization                                 |
    | Cause                      | Frames < locality; too many processes                                  |
    | Working Set Model          | Prevents thrashing by ensuring each process gets locality-sized frames |
    | PFF (Page Fault Frequency) | Regulates frames based on fault rate                                   |

-   Segmentation in Operating System

    1. What is Segmentation?

    Segmentation is a memory-management technique in which a process is divided into variable-sized, logical units called segments.  
    Unlike paging (which divides memory into fixed-size blocks), segmentation follows the user’s logical view of a program such as:

    - Functions  
    - Procedures  
    - Classes  
    - Arrays  
    - Stack  
    - Data sections  

    ➡️ Segmentation is *logical* and *programmer-oriented*, not hardware-oriented.

    2. Key Features of Segmentation

        1. Variable-sized segments
            Each segment has a different size depending on program requirements  
            (e.g., code segment might be 80 KB, stack 16 KB, data 40 KB).

        2. Logical division of memory
            Segments represent meaningful program units → improves organization.

        3. Two-part logical address
            A CPU-generated logical address is:

            Logical Address = ⟨Segment Number (s), Offset (d)⟩

            - Segment number (s) → identifies the segment  
            - Offset (d) → position within that segment  

        4. Protection & Sharing
            Each segment can have independent permissions:
            - Read  
            - Write  
            - Execute  

            Segments like shared libraries can be shared among processes.

        5. No internal fragmentation
        Because segment sizes match logical module sizes.

        6. External fragmentation
        Occurs because free memory becomes scattered into holes of varying sizes.

    3. Types of Segmentation

        1. Simple Segmentation
            - All segments of a process are loaded into memory at runtime  
            - Not necessarily contiguous  
            - Uses one segment table per process  

        2. Virtual Memory Segmentation
            - Segments may be partially loaded  
            - Works with demand segmentation (similar to demand paging)  
            - Used in combination with paging in some systems (e.g., Linux uses segmentation only for protection, not memory allocation)  

    4. Segment Table ![alt text](image-23.png)

        Every process has a segment table that maps logical segments to physical memory.

        Each segment table entry contains:

            1. Base Address
                Starting physical address of the segment in memory.

            2. Limit (Segment Length)
                Size of the segment → helps detect illegal access.

        Memory Lookup:
        Physical Address = Base Address + Offset

        Only valid if:  
        `offset < limit`  
        Otherwise → Segmentation Fault.

    5. Address Translation in Segmentation ![alt text](image-24.png)

        When CPU generates a logical address ⟨s, d⟩:

        1. The OS checks segment number s in segment table  
        2. Retrieves:  
            - Base address  
            - Limit  
        3. Verifies:  
            - If d < limit → valid  
            - Else → segmentation fault  
        4. Computes:  
            - Physical Address = Base + d

    6. Advantages of Segmentation

    - ✔️ Reduced Internal Fragmentation → segment sizes match program requirements  
    - ✔️ Smaller Tables → fewer entries compared to page tables  
    - ✔️ Better CPU Utilization → logical modules load together  
    - ✔️ Matches User’s View → memory division aligns with programmer’s structure  
    - ✔️ Security and Protection → per-segment permissions (R/W/X)  
    - ✔️ Sharing Made Easy → shared code/libraries in shared segments  
    - ✔️ User-Controlled Sizes → programmer defines segment boundaries  

    7. Disadvantages of Segmentation

    - ❌ External Fragmentation → scattered free memory blocks  
    - ❌ Overhead → segment tables require extra memory  
    - ❌ Slower Access → two lookups (segment table + data)  
    - ❌ Complex Management → allocation, deallocation, compaction harder  
    - ❌ Segmentation Faults → errors when accessing outside segment limit  

    8. Segmentation vs Paging (Quick Comparison)

        | Feature       | Segmentation      | Paging                     |
        | ------------- | ----------------- | -------------------------- |
        | Basis         | Logical division  | Physical division          |
        | Size          | Variable          | Fixed                      |
        | Fragmentation | External          | No external (but internal) |
        | Address       | ⟨segment, offset⟩ | ⟨page, offset⟩             |
        | User's View   | Yes               | No                         |
        | Protection    | Per-segment       | Per-page                   |
        | Sharing       | Easy              | Possible but complex       |

-   Segmentation with Paging (Segmented Paging) *(Hybrid Memory Management Technique)*

    Segmentation with Paging combines:

    * Segmentation → logical division of program
    * Paging → physical memory divided into fixed-size frames

    It allows the system to preserve the programmer’s logical view (segments) while solving the fragmentation problems of segmentation.

    1. Why Segmentation with Paging?

        Problems with pure segmentation

        * External fragmentation (segment sizes vary)
        * Hard to fit segments into memory
        * Segment tables vary in size

        Problems with pure paging

        * No logical separation (everything is just pages)
        * All page tables are huge even if parts of memory unused

        Segmented Paging = best of both

        * Logical segmentation is preserved
        * Each segment internally uses paging → no external fragmentation
        * Page tables exist per segment, not per full process → saves memory

    2. How Segmented Paging Works

        A program is divided into logical segments:

        * Code segment
        * Data segment
        * Heap segment
        * Stack segment

        Step 1 — Segmentation

        A process has a segment table, where each entry contains:

        * Base → starting address of the page table for that segment
        * Limit → size/number of pages in that segment

        Step 2 — Paging inside each segment

        Each segment is divided into fixed-size pages (same size as frames).

        Each segment has its own page table.

        Example:

        | Segment | Size  | Pages   |
        | ------- | ----- | ------- |
        | Code    | 12 KB | 3 pages |
        | Data    | 4 KB  | 1 page  |
        | Stack   | 8 KB  | 2 pages |
        | Heap    | 20 KB | 5 pages |

        So, page tables are small and separate for each segment.

    3. Logical Address Format

        A logical address generated by CPU is divided into: < Segment Number | Page Number | Offset > ![alt text](image-25.png)

        Where:

        | Field                  | Meaning                              |
        | ---------------------- | ------------------------------------ |
        | Segment Number (s) | Selects the segment                  |
        | Page Number (p)    | Selects the page inside that segment |
        | Offset (d)         | Byte/word offset inside page         |

    4. Address Translation Workflow (Step-by-Step) ![alt text](image-26.png)

        1. MMU takes the Segment Number (s)
        → Used to index into the Segment Table.

        2. Segment Table entry gives: ![alt text](image-27.png)
            * Base address of segment’s page table
            * Limit (number of pages)

        3. Page Number (p)
        Used to index into that specific segment’s page table.

        4. Page table entry contains:
            * Frame number where the page resides in physical memory

        5. Add Offset (d) to frame base address
        → Final Physical Address

    5. Diagram-Style Representation (Text Version)

        ```
        Logical Address: [ s | p | d ]

        s → Segment Table
            ↓ gives base of page table
        p → Page Table of that segment
            ↓ gives frame number
        d → offset inside that frame
        Final Physical Address = Frame + d
        ```

    6. Advantages of Segmented Paging

        1. Page tables are smaller
            Because:

            * Pages exist per segment, not entire process
            * Unused logical space has no page tables

        2. Programmer’s logical view preserved

            Segments represent:

            * Code
            * Data
            * Stack
            * Heap

            Ideal for protection and sharing.

        3. Less external fragmentation
            Segmentation alone suffers from external fragmentation.
            Paging inside segments removes this.

        4. Supports dynamic-sized segments
            Heap and stack can grow logically
            (because new pages can be allocated as needed).

    7. Disadvantages of Segmented Paging

        1. Internal Fragmentation

            * Paging always causes small waste inside frames.

        2. Extra Hardware Required

            * Requires both segment table + multiple page tables
            * MMU must support two-level translation

        3. More Translation Steps

            * Segmentation first
            * Then paging
            → More memory accesses → higher latency
            (TLB reduces overhead if entries are cached)

        4. External Fragmentation (Modern Systems)

            This point appears contradictory at first — but the meaning is:

            * Although segments are paged, the segment table itself can have variable-sized entries (different number of pages per segment).
            * Some OSes also store segment tables differently.
            * So modern implementations still experience some fragmentation while managing segment metadata.

    8. Summary (Perfect for Exams / Interviews)

        “Segmentation with Paging” =

        Logical segmentation + physical paging inside segments.

        ✔ Segment table → gives base of page table for each segment
        ✔ Page tables → used to find physical frames
        ✔ Logical Address = segment + page + offset

        Advantages

        * Smaller page tables
        * Logical segmentation preserved
        * Eliminates external fragmentation
        * Good protection per segment

        Disadvantages

        * Internal fragmentation (due to pages)
        * More hardware and overhead
        * Multi-step translation increases memory access time

-   System Call in Operating System

    User programs cannot directly access hardware or critical OS resources, because this would:

    - Compromise system stability  
    - Introduce security risks  

    To safely access OS services, system calls act as controlled gateways between user mode and kernel mode.

    1. What is a System Call?

        A system call is a mechanism provided by the operating system that allows user programs to:

        - Request services from the OS kernel  
        - Perform operations on hardware or system resources safely  
        - Transition from user mode to kernel mode for privileged operations  

        Key points:
        - Only the kernel executes in kernel mode  
        - System calls act as the entry points into the kernel  
        - Without them, programs would need direct hardware access → insecure and inconsistent behavior  

    2. Examples of System Calls

        | Operation          | Example System Call            |
        | ------------------ | ------------------------------ |
        | File access        | `open()`, `read()`, `write()`  |
        | Process management | `fork()`, `exec()`, `exit()`   |
        | Memory allocation  | `mmap()`, `brk()`              |
        | Device access      | `ioctl()`, `read()`, `write()` |
        | Printing           | `write()` to stdout            |

        Example in C:
        ```c
        FILE *fp = fopen("file.txt", "r"); 
        // internally uses the open() system call
        ```

    3. How System Calls Work

        1. The user program executes a system call instruction (e.g., `syscall` in Linux, `int 0x80` in x86).  
        2. CPU switches from user mode → kernel mode.  
        3. Kernel identifies the system call number.  
        4. Kernel performs the requested operation:  
            - File access  
            - Process creation  
            - Memory allocation  
            - Device control  
        5. Kernel switches back to user mode.  
        6. The result (success, failure, or data) is returned to the program.  

        Note: System calls are slower than normal function calls because of context switching between user and kernel mode.

    4. Types of System Calls

        System calls are grouped by the type of service they provide:
        -   File System
            -   Operations on files & directories 
            -   `open()`, `close()`, `read()`, `write()`, `unlink()`
        -   Process Control
            -   Manage processes
            -   `fork()`, `exec()`, `exit()`, `wait()`
        -   Memory Management
            -   Allocate or deallocate memory
            -   `malloc()`, `free()`, `mmap()`, `brk()`
        -   Interprocess Communication (IPC)
            -   Exchange data between processes
            -   `pipe()`, `shmget()`, `msgget()`
        -   Device Management
            -   Request or release devices
            -   `ioctl()`, `read()`, `write()`, `close()`

    5. Key Points to Remember

        - System calls are essential for OS services: file I/O, process management, memory management, and device access  
        - They ensure safety and security by controlling access to critical resources  
        - Performance cost: Switching between user mode and kernel mode is expensive (context switch)  
        - They provide a standard interface for programs to interact with OS services  

    -   System Call Flow (User → Kernel → Hardware)

        ```
        +-------------------+
        |   User Program    |   <-- User Mode
        |  (Application)    |
        +-------------------+
                |
                |  System Call (e.g., open(), read(), write())
                v
        +-------------------+
        |   System Call     |
        |   Interface       |
        +-------------------+
                |
                |  Trap Instruction (syscall / int 0x80)
                v
        +-------------------+
        |   OS Kernel       |   <-- Kernel Mode
        |  (Service Layer)  |
        +-------------------+
                |
                |  Executes privileged operation
                v
        +-------------------+
        |   Hardware /      |
        |   Device Access   |
        +-------------------+
                |
                |  Result (data, status, error code)
                v
        +-------------------+
        |   User Program    |
        |   (Resumes Exec)  |
        +-------------------+
        ```

