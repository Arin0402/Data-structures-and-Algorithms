# What are HTTP and HTTPS protocols?

# HTTP


    - HyperText Transfer Protocol(HTTP) is an application layer protocol that is used to access and transfer data(text, images, video, multimedia, etc) over the world wide web.

        - HTTP is a client-server protocol that runs on top of the TCP/IP family of protocols and uses the request/response protocol.
        - HTTP uses port number 80. 
        - In HTTP, the client sends a request message to the server. After the client responds, HTTP establishes a TCP connection between the client and the server. HTTP delivers a request to the server, which collects the data that was requested. After the server sends data to the client, the connection will be terminated.
        - If we want something else from the server, we should have to re-establish the connection between client and server.

# Features of HTTP

    - HTTP is connectionless: After serving a single HTTP request, the client-server connection is closed and that same connection is never used again.

    - HTTP is media independent: It means that HTTP can send any sort of data as long as both the client and the server understand how to process the data.

    - HTTP is stateless: The client and server only know about each other during the current request, and when the connection is disconnected, both the client and the server forget about each other.

# HTTPS

    - Hypertext Transfer Protocol Secure is a secure extension or version of HTTP that is used for providing security to the data sent over the world wide web.

        - This protocol allows transferring the data in an encrypted form which is particularly important when users transmit sensitive data such as login credentials.

        - To encrypt communications HTTPS uses an encryption protocol called Transport Layer Security (TLS), formerly known as Secure Sockets Layer (SSL). 

        - HTTPS protocol uses the 443 port number for communicating the data.
