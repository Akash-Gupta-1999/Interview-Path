-   Basic Terminologies
    -   Basic Terms
        -   Server: Provides services like web pages, files, APIs.
        -   Client: Requests services from a server (e.g., browser).
        -   Host: Any device with an IP address in a network.
        -   Node: Any device participating in network communication (switch, router, PC, etc.) All hosts are nodes, but not all nodes are hosts.
    -   Network Devices
        -   Switch
            -   Connects devices within a LAN and forwards data based on MAC addresses
            -   Layer 2 (Data Link). Maintains MAC Address Table.
        -   Router
            -   Connects different networks and forwards data based on IP addresses
            -   Layer 3 (Network). Maintains Routing Table.
        -   Modem
            -   Converts ISP signal → digital network signal for your router
            -   “Modulate / Demodulate” → converts signals.
        -   Hub
            -   Broadcasts data to all connected devices.
            -   No intelligence; mostly outdated.
        -   Access Point (AP)
            -   Provides Wi-Fi connectivity.
            -   Works like a wireless switch.
        -   Firewall
            -   Filters network traffic based on rules.
            -   Protects against unauthorized access.
        -   Gateway
            -   Entry/exit point between different networks or protocols.
            -   Your router acts as a gateway between LAN ↔ internet.

    -   Addressing & Identification
        -   IP Address
            -   Logical address of a device (e.g., 192.168.0.12).
            -   Used for routing.
        -   MAC Address
            -   Physical hardware address (e.g., A4:6E:11:BC:33:99).
            -   Used inside local networks (LAN).
        -   Subnet
            -   Logical division of network to reduce broadcast range.
        -   DNS
            -   Converts domain names → IP addresses.
            -   Example: google.com → 142.250.x.x.

    -   Data Transmission Terms
        -   Packet
            -   Unit of data at network layer.
            -   Contains header + payload.
        -   Frame
            -   Unit of data at data link layer.
            -   Uses MAC addresses.
        -   Routing Table
            -   Router’s internal map of where to send packets next.
        -   NAT (Network Address Translation)
            -   Converts private IP ↔ public IP at router.
            -   Allows multiple devices to share one public IP.

    -   Cloud / System Design Terms
        -   Load Balancer
            -   Distributes load across multiple servers.
            -   Helps in scaling & fault tolerance.
        -   CDN (Content Delivery Network)
            -   Delivers content from servers closer to users.
            -   Reduces latency (e.g., Netflix, YouTube).
        -   Reverse Proxy
            -   Sits between clients and backend servers.
            -   Common example: Nginx / HAProxy.
        -   API Gateway
            -   Central entry point for microservices.
            -   Handles authentication, routing, rate limits.

    -   Quick Differences
        -   Switch vs Router
            -   Switch → MAC addresses (LAN).
            -   Router → IP addresses (connects networks).
        -   Hub vs Switch
            -   Hub → sends data to all devices.
            -   Switch → sends data only to target device.
        -   Public vs Private IP
            -   Public → visible to internet.
            -   Private → used only within local network.

-   Why Layers Needed?
    -   Layering ensures every protocol works independently in its own layer, without worrying about how other layers send, route, or deliver data.
        -   Example flow:
            -   Application Protocol (HTTP) → formats data
            -   Transport Protocol (TCP/UDP) → handles reliability & port-level delivery
            -   Network Protocol (IP) → handles routing & addressing
            -   Link Layer Protocol (Ethernet/Wi-Fi) → handles frame transmission
            -   Each protocol trusts the layer below to do its job.
    -   To divide complexity into manageable parts.
    -   To allow independent updates (change one layer without affecting others).
    -   To standardize communication so different systems can work together.
    -   To simplify troubleshooting by isolating issues layer-wise.

-   OSI Model
    -   The OSI model is a conceptual framework that divides network communication into 7 layers.
Each layer has a specific role and communicates only with the layer above and below it.
    -   This helps make networking organized, modular, and easier to understand and troubleshoot.
    -   It is not used in Real life
    -   The OSI model is mainly a conceptual framework; real-world networks use the simpler TCP/IP model because it is practical, widely implemented, and more efficient.

    1. Physical Layer
        -   Responsible for actual physical transmission of data.
        -   Converts bits ↔ electrical/optical/radio signals.
        -   Handles:
            -   Bit synchronization (clock)
            -   Bit-rate control (bits per second)
            -   Physical topology (bus, star, ring)
            -   Transmission mode: simplex / half-duplex / full-duplex

    2. Data Link Layer
        -   Responsible for Node-to-Node delivery.
        -   Converts packets → frames.
        -   Handles:
            -   Physical addressing (MAC)
            -   Framing
            -   Error detection & correction
            -   Flow control
        -   Uses ARP to map IP → MAC address.

    3. Network Layer
        -   Responsible for Logical Addressing and Routing.
        -   Determines the best path for packet delivery.
        -   Uses:
            -   IP (IPv4/IPv6) for addressing
            -   Routing algorithms/protocols (e.g., OSPF, BGP)
        -   Chooses next-hop device in routing path.

    4. Transport Layer
        -   Responsible for End-to-End delivery
        -   Segmentation & Reassembly (splitting/joining packets) — especially when exceeding MTU.
        -   Multiplexing / De-multiplexing using port numbers.
        -   Protocols:
            -   TCP → reliable, connection-oriented
            -   UDP → fast, connectionless

    5. Session Layer
        -   Manages sessions between systems.
        -   Handles:
            -   Establishment
            -   Maintenance
            -   Termination
            -   Authentication & Security
            -   Synchronization (checkpoints → useful for resume after disconnection)
            -   Dialog control (manages turns when multiple systems communicate)

    6. Presentation Layer
        -   Responsible for data formatting and representation.
        -   Handles:
            -   Translation (e.g., ASCII ↔ EBCDIC)
            -   Encryption / Decryption (security)
            -   Compression / Decompression (performance)
        -   E.x. SSL/TLS, JPEG, MP3

    7. Application Layer
        -   Closest layer to the user.
        -   Provides application-specific protocols to produce and access data.
        -   Examples: HTTP, HTTPS, FTP, SMTP/IMAP, DNS
        -   Interfaces directly with software like web browsers, messaging apps, VoIP apps.
    
    -   How Layers Work Together
        -   When sending data: It starts from the Application Layer and goes down the layers → gets encapsulated.
        -   When received, it moves up the layers → gets de-encapsulated.
        -   Each layer adds its own header describing how to handle the data.

-   TCP/IP Model
    -   Real-world practical networking model, widely used in the Internet.
    -   Divides communication into 4 layers:
        1. Network Interface (Link) → Physical & Data Link tasks (Ethernet, Wi-Fi)
        2. Internet → Logical addressing & routing (IP)
        3. Transport → End-to-end delivery (TCP/UDP, ports)
        4. Application → Application-specific protocols (HTTP, FTP, DNS, SMTP)
    -   Key Point: Unlike OSI, TCP/IP combines some OSI layers (e.g., OSI’s Physical + Data Link → Link Layer).
    -   Unlike OSI, this model was built after protocol introduced

-   Data Link Layer
    -   Primary Role: Provides reliable node-to-node communication over a physical medium.
    -   Position: Sits above Physical Layer and below Network Layer.
    -   Data Link layer is handled by the NIC (Network Interface Card) and device drivers of host machines.
    -   Encapsulation: Receives packets from Network Layer and encapsulates them into frames.
    -   2 Major Layer : Logical Link Control, Media Access Control

    The functions of the Data Link layer are :
    1. Framing
        -   Converts raw bits from the physical layer into structured frames.
        -   Each frame typically contains: Header + Payload + Trailer.
        -   Stuffing Techniques:
            -   Bit Stuffing: Inserts a 0 after a sequence of consecutive 1s to avoid frame boundary confusion (HDLC).
                -   Example:
                    -   Frame Flag: 01111110
                    -   Original Data: 111110111111101
                    -   Final Frame with Flags : 01111110 1111100111110101 01111110
                -   If data itself is frame flag then just repeat twice
            -   Byte Stuffing: Inserts a escape characters frame in data to distinguish frame delimiters (PPP).(Most Used and Practical)

    2. Physical Addressing (MAC)
        -   Uses hardware (MAC) addresses to identify devices in the same LAN.
        -   Ensures frames reach the correct device.
        -   Address Resolution: Uses ARP to map IP addresses → MAC addresses.

    3. Error Detection & Control
        -   Detects and corrects errors introduced by the physical layer.
        -   Techniques:
            -   Parity Check: Simple error detection using even/odd parity.
            -   Checksum: Sum of data bytes; receiver verifies correctness.
            -   CRC (Cyclic Redundancy Check): Polynomial division for highly reliable detection.
        -   May request retransmission if errors are found.

    4. Flow Control
        -   Ensures sender does not overwhelm receiver.
        -   Algorithms:
            -   Stop-and-Wait: Sender waits for acknowledgment before sending next frame (simple, but slow).
            -   Sliding Window: Multiple frames sent before acknowledgment; increases efficiency.
            -   Variants: Go-Back-N, Selective Repeat.

    5. Access Control / Media Access
        -   Manages who can transmit on a shared medium.
        -   Techniques(only in case switch is not there in LAN):
            -   FDMA (Frequency Division Multiple Access): Assigns frequency bands → rarely used in LANs.
            -   TDMA (Time Division Multiple Access): Assigns time slots → impractical for fast LANs.
            -   CSMA/CD (Carrier Sense Multiple Access with Collision Detection):
                -   Used in wired Ethernet.
                -   Devices sense the channel; if idle → transmit; if collision → backoff & retry.
            -   CSMA/CA (Carrier Sense Multiple Access with Collision Avoidance):
                -   Used in Wi-Fi.
                -   Devices signal before sending to avoid collisions; includes acknowledgment to confirm receipt.

    - Devices Operating at Data Link Layer
        -   Switch: Forwards frames based on MAC addresses; builds MAC address table dynamically.
        -   Bridge: Connects two LAN segments, filters frames, reduces collision domains.

    - Common Protocols
        -   Ethernet (IEEE 802.3): Wired LANs.
        -   Wi-Fi (IEEE 802.11): Wireless LANs.
        -   PPP (Point-to-Point Protocol): Direct serial links.
        -   Frame Relay, ATM: WAN protocols (enterprise/legacy).

    -   Key Insights
        -   Ensures reliable delivery within a single network segment.
        -   Handles framing, addressing, error detection, flow control, and access control.
        -   Simplifies the Network Layer’s job, because the Data Link Layer guarantees delivery within the LAN.

-   Transmition and Propogation Delay

    -   In packet-switched networks, the total time for a packet to reach its destination includes four main types of delay:

    1. Transmission Delay
    2. Propagation Delay
    3. Queuing Delay
    4. Processing Delay

    -   Transmission Delay (Time to push bits onto the link)
        - Definition: Time required to place all packet bits onto the communication link.
        - Depends on: Packet size (L) and link bandwidth (B).
        - Formula:  
            Transmission Delay = L / B   (seconds)
    -   Propagation Delay (Time for bits to travel)
        -   Definition: Time taken for the first bit to travel from sender to receiver.
        -   Depends on: Distance (d) and propagation speed (s).
        -   Formula:
                PropagationDelay=d/s
    -   Queuing Delay
        -   Definition: Time a packet waits in a queue before being processed.
        -   Depends on: Network congestion, number of packets in queue, and bandwidth.
        -   Formula (average queuing delay):
                QueuingDelay=(N−1)∗L/(2∗R)

                N = number of packets
                L = packet size
                R = link bandwidth
    -   Processing Delay
        -   Definition: Time routers take to process the packet header, perform error checking, and decide forwarding.
        -   Typical Value: Microseconds in high-speed routers.
        -   Simplified: Time to process packets.
    -   Total End-to-End Delay
        -   Single packet, single hop:
            TotalDelay=TransmissionDelay+PropagationDelay+QueuingDelay+ProcessingDelay
        -   Multiple hops (M) and multiple packets (N):
            TotalDelay=M∗(Transmission+Propagation)+(M−1)∗(Processing+Queuing)+(N−1)∗Transmission
        -   Interpretation:
            -   Transmission + Propagation occurs per hop.
            -   Processing + Queuing occurs at intermediate routers.
            -   Extra transmission accounts for subsequent packets.

-   Stop and Wait ARQ (Automatic Repeat Request)
    -   Characteristics
        - Used in connection-oriented communication.
        - Provides both error control and flow control.
        - Implemented in Data Link Layer and Transport Layer.
        - Based on Sliding Window Protocol with Window Size = 1.
        - Uses only two sequence numbers: `0` and `1`.

    -   Useful Terms
    | Term | Meaning |
    |------|---------|
    | Propagation Delay | Time taken by a signal to physically travel from sender to receiver. |
    | Propagation Delay Formula | `Propagation Delay = Distance / Signal Speed` |
    | RTT (Round Trip Time) | Time taken for a signal to go from sender to receiver and back. `RTT = 2 × Propagation Delay` |
    | Timeout (TO) | Time after which sender retransmits if no ACK received. `TO = 2 × RTT` |
    | Time To Live (TTL) | Maximum survival time of a packet. `TTL = 2 × TO (Max = 180 seconds)` |

    -   Simple Stop and Wait (Without ARQ)
        -   Sender Rules:
            1. Sends one packet at a time.
            2. Sends the next packet only after ACK for previous packet.
        -   Receiver Rules:
            1. Sends acknowledgement after receiving each packet.
            2. Ensures flow control by sending ACK only after processing the packet.

    -   Problems in Simple Stop and Wait
        1. Lost Data Packet
        2. Lost Acknowledgement
        3. Delayed Acknowledgement — may get misinterpreted as ACK for another packet.

    -   Stop and Wait ARQ (Automatic Repeat Request)
        -   How It Solves Problems:
            -   Lost Data -> Timeout triggers retransmission. |![alt text](image.png)
            -   Duplicate Frames -> Sequence Numbers (0 and 1) differentiate frames. |![alt text](image-1.png)
            -   Delayed ACK -> ACKs also carry sequence numbers (expected frame number). |![alt text](image-2.png)
                -   Working
                    1. Sender sends packet with sequence number 0.
                    2. Receiver receives packet → sends ACK with sequence number 1 (next expected).
                    3. Sender sends next packet with sequence number 1, and so on.

    -   Characteristics of Stop and Wait ARQ
        - Works on half-duplex links.
        - Throughput = 1 data packet per RTT.
        - Performs poorly when Bandwidth × Delay product is high.
        - Efficient for short distance (LAN); poor performance for long distance (WAN/Satellite).
    
    -    Performance Consideration
        - Stop and Wait ARQ ensures reliability, but its transmission efficiency is low.
        - The sender must wait for ACK before sending the next packet, even if it already has more packets ready.
        - This becomes a major issue when:
            - Bandwidth is high, and
            - Propagation delay is large,  
            e.g., communication across countries or satellite networks.
        - In such cases, the link remains under-utilized, causing poor throughput.

    -   Where Stop and Wait Works Well
        - Works efficiently when propagation delay is very small, such as in LAN (Local Area Network) environments.
        - Performs poorly in MAN/WAN/Satellite networks due to large propagation delays.

    -   Key Efficiency Note
        - Stop and Wait is simple and reliable, but efficiency is low because:
            - Sender sends only one packet per RTT.
            - If ACK is lost or delayed, sender retransmits → further reducing efficiency.

-   Go Back-N ARQ
    -   Go-Back-N is a Sliding Window Protocol where the sender can transmit multiple frames at once (up to window size N) without waiting for acknowledgements. However, if an error is detected, the sender retransmits the lost/damaged frame and all frames after it, hence the name *Go-Back-N*.

    -   Characteristics
        - Pipeline (continuous) sending: Sender can send up to N frames before needing an ACK.
        - Sender Window Size = N
        - Receiver Window Size = 1  
        (Receiver only accepts frames in correct order; out-of-order frames are discarded.)
        - Uses cumulative ACKs:  
            - A single ACK acknowledges all frames up to a certain sequence number.
        - If a frame is lost or corrupted, sender goes back and retransmits that frame and all subsequent frames.
        - More efficient than Stop-and-Wait, especially when Bandwidth × Delay product is high.

    -   Working Example ![alt text](image-3.png)
        1. Sender transmits `Frame 0, 1, 2, ..., N` continuously.
        2. Suppose Frame 2 is lost.
        3. Receiver discards Frame 3, 4, ... since Frame 2 is missing.
        4. Receiver sends ACK 2 (meaning: "I am expecting Frame 2 next").
        5. Sender retransmits Frame 2, 3, 4, ....

    -   Relationship Between Window Size and Sequence Numbers in Go-Back-N (Simple Explanation)

        -   In Go-Back-N ARQ, the sender can send multiple packets at once, up to a limit called the sender window size (N). Each packet has a sequence number. These sequence numbers repeat (wrap around), so we must be careful to avoid confusing new packets with old retransmitted packets.

        -   To avoid this confusion, the number of sequence numbers available must always be N + 1.
            So:

            -   If window size = N
            -   Minimum sequence numbers required = N + 1
            -   This ensures correct identification of new vs. old packets.
            
            Why Do We Need the Extra Sequence Number?
            Consider window size = 4.
            So sender can send packets numbered: 0, 1, 2, 3
            
            What happens without an extra sequence number? ![alt text](image-4.png)
            Sender sends packets: 0, 1, 2, 3.
            Receiver receives them correctly and expects next packet = 0 again (since numbering wraps back).
            But suppose the ACK from receiver is lost.
            Sender times out and retransmits packets 0, 1, 2, 3.
            Receiver now receives packets 0, 1, 2, 3 again.
            Receiver cannot tell whether these packets are:
            The old duplicates being retransmitted, or the new cycle of packets.Because the sequence numbers are the same.
            So receiver accepts duplicates, causing wrong data at the application layer.

            How Does Using N + 1 Sequence Numbers Fix This? ![alt text](image-5.png)
            If window size = 4, use 5 sequence numbers: 0, 1, 2, 3, 4
            Now:
            After receiver receives packets 0, 1, 2, 3, it will expect next packet = 4, not 0.
            So when sender retransmits packets 0, 1, 2, 3 due to timeout:
            Receiver sees that it is currently expecting packet 4
            So it rejects packets 0, 1, 2, 3 as duplicates
            Thus, no confusion occurs.

            -   Final Points (In Simple Words)
                -   Sender Window Size = N
                -   Minimum sequence numbers must be = N + 1
                -   Otherwise, receiver can get confused and accept duplicate data.
                -   This prevents errors when ACKs are lost and packets are retransmitted.   
                -   Sender Window Size + Receiver Window Size = 2ⁿ (In General for All)
                    -   in case of go back N. receiver WS is 1 so sender side = (2^n)-1
                    -   incase of selective repeat: WS of sender = WS of receiver. WS = 2^(n-1)

    -   Advantages
        - Higher channel utilization than Stop-and-Wait.
        - Better suited for high bandwidth and high latency networks.
        - Reduces idle waiting time because sender can continue sending multiple frames.

    -   Disadvantages
        - Wasteful retransmission:  
        If one frame is lost, all subsequent frames in window are retransmitted, even if they were correctly received.
        - Requires more memory to store multiple outstanding frames.
        - Receiver cannot buffer out-of-order frames, so frames may be discarded unnecessarily.

    -   Where Go-Back-N Works Well
        - Networks where error rate is low, so retransmissions are rare.
        - Networks with high bandwidth-delay product (e.g., WAN).
        - Situations where simplicity is preferred over maximum efficiency.

    -   Comparison with Stop-and-Wait

    | Feature | Stop-and-Wait | Go-Back-N |
    |--------|---------------|------------|
    | Window Size | 1 | N (>1) |
    | Channel Utilization | Low | Much Higher |
    | ACK Type | Per-frame | Cumulative |
    | Performance | Good only in LAN | Good in LAN, MAN, WAN |
    | Lost Frame Handling | Retransmit same frame | Retransmit that frame + all after it |

-   Selective Repeat ARQ
    -   Why Selective Repeat Protocol?
        The go-back-n protocol works well if errors are less, but if the line is poor it wastes a lot of bandwidth on retransmitted frames. An alternative strategy, the selective repeat protocol, is to allow the receiver to accept and buffer the frames following a damaged or lost one.

    -   Selective Repeat attempts to retransmit only those packets that are actually lost (due to errors) :
        -   Receiver must be able to accept packets out of order.
        -   Since receiver must release packets to higher layer in order, the receiver must be able to buffer some packets.

    -   Retransmission requests :
        -   Implicit - The receiver acknowledges every good packet, packets that are not ACKed before a time-out are assumed lost or in error.Notice that this approach must be used to be sure that every packet is eventually received.
        -   Explicit - An explicit NAK (selective reject) can request retransmission of just one packet. This approach can expedite the retransmission but is not strictly needed.
        -   One or both approaches are used in practice.

    -   Selective Repeat Protocol (SRP) : ![alt text](image-6.png)
        This protocol(SRP) is mostly identical to GBN protocol, except that buffers are used and the receiver, and the sender, each maintains a window of size. SRP works better when the link is very unreliable. Because in this case, retransmission tends to happen more frequently, selectively retransmitting frames is more efficient than retransmitting all of them. SRP also requires a full-duplex link. Backward acknowledgements are also in progress.

        -   Sender's Windows ( Ws) = Receiver's Windows ( Wr).
        -   Window size should be less than or equal to half the sequence number in SR protocol. This is to avoid packets being recognized incorrectly. If the size of the window is greater than half the sequence number space, then if an ACK is lost, the sender may send new packets that the receiver believes are retransmissions.
        -   Sender can transmit new packets as long as their number is with W of all unpacked packets.
        -   Sender retransmit un-ACKed packets after a timeout – Or upon a NAK if NAK is employed.
        -   Receiver ACKs all correct packets.
        -   Receiver stores correct packets until they can be delivered in order to the higher layer.
        -   In Selective Repeat ARQ, the size of the sender and receiver window must be at most one-half of 2^m.

-   Imp for ARQ Algorithms
    -   Comparison : ![alt text](image-7.png)
    -   Generally, Stop and Wait mostly used in Data Link layer as the propogation delay is very small.
    -   Go back N and selective Repeat are used in Transport Layer Because propogation delay is huge and Bandwidth is High

