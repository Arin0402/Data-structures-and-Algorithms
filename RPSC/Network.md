# Data link layer (class 19) (pg 61)

    (these notes are not available in pdf)

    - responsibilities
        - framing
        - physical addressing
        - flow control
        - error control
        - media access control

    Note - Data link layer does Flow control and error control Hop to Hop/ Point to point   whereas Transport layer does the same thing process to process

    - two sub types
        
        - LLC layer
            - Logical link control layer

        - MAC layer
            - Media Access Layer

    - protocols used

        - HDLC (High level data link control)
        - SDLC (Synchronous data link control)
        - PPP (Point to point control)
        - SLIP (Serial line internet protocol)
        - NCP (Network control protocol)
        - LCP (Link control protocol)
        - LAP (Link access protocol)

    - Frame consists of three parts
        - header
        - payload(data) (packet that comes from network layer)
        - tailer
    
    - continue in notes (class 20) (pg 63)    


# Pg 85, class 25, date 25-05-2024

    - Acknowledgement in GBN (Go back N)
    - two types
        - Independent ack.
        - Commutative ack.

    - efficiency of GBN

        n = (2^m - 1) / (1 + 2a)

                or
            
        n = ws / (1 + 2a)

            where ws is window size

    NOTE: if efficiency is 100% then n would be 1
    
        so ws = 1 + 2a

    - ex at 21:54, class 25

# pg 163, class 42

    the answer for the question is here 
    (watch the video first)
    https://www.youtube.com/watch?v=8gZBEDNpC0s

    https://www.geeksforgeeks.org/questions/gate-gate-cs-2014-set-3-question-36/

# Transport layer protocol 

    - TCP
    - UDP - User datagram p.
    - SCTP - stream control transmission p.
    - DCCP - datagram congestion p.


    - Tcp is a byte oriented protocol
    - Tcp is a connection oriented protocol
    - Tcp uses three way handshaking    

        - syn           (first hand shake)
        - syn + ack     (second hand shake)
        - ack           (third hand shake)
    
    - Tcp provides reliability 

    - pg 192
        - properties of tcp

# TCP header

    - class 50

# classes

    A = 0 - 127
    B = 128 - 191
    C = 192 - 223
    D = 224 - 239
    E = 240 - 255


# Index

    - Bridge = pg 41
    - Error methods = pg 95
    - Media access control (MAC) = pg 113
    - IPv4 = pg 134 , 166
    - GBN ARQ - pg 82
    - Network Layer = 131