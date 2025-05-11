# What is SSL/TLS

    - SSL = Secure Sockets Layer
    - TSL = Transport Layer security

    - SSL is the predecessor to the modern TLS encryption used today.
    - A website that implements SSL/TLS has "HTTPS" in its URL instead of "HTTP."

# How does SSL/TLS work?

    - In order to provide a high degree of privacy, SSL encrypts data that is transmitted across the web. This means that anyone who tries to intercept this data will only see a garbled mix of characters that is nearly impossible to decrypt.

    - SSL initiates an authentication process called a handshake between two communicating devices to ensure that both devices are really who they claim to be.

    - SSL also digitally signs data in order to provide data integrity, verifying that the data is not tampered with before reaching its intended recipient.

    - There have been several iterations of SSL, each more secure than the last. In 1999 SSL was updated to become TLS.

# What is an SSL certificate?

    - SSL and TLS certificate are the same thing, it is just that the SSL has a lot name recognition so that's why refer it as SSl certificate but in reality it is TLS certificate
    
    - TLS evolved from a previous encryption protocol called Secure Sockets Layer (SSL), which was developed by Netscape. TLS version 1.0 actually began development as SSL version 3.1, but the name of the protocol was changed before publication in order to indicate that it was no longer associated with Netscape. Because of this history, the terms TLS and SSL are sometimes used interchangeably.

    - SSL can only be implemented by websites that have an SSL certificate (technically a "TLS certificate"). An SSL certificate is like an ID card or a badge that proves someone is who they say they are. SSL certificates are stored and displayed on the Web by a website's or application's server.

    - One of the most important pieces of information in an SSL certificate is the website's public key. The public key makes encryption and authentication possible. A user's device views the public key and uses it to establish secure encryption keys with the web server. Meanwhile the web server also has a private key that is kept secret; the private key decrypts data encrypted with the public key.

    - Certificate authorities (CA) are responsible for issuing SSL certificates.

# What are the types of SSL certificates?


    - There are several different types of SSL certificates. One certificate can apply to a single website or several websites, depending on the type:

        - Single-domain: A single-domain SSL certificate applies to only one domain (a "domain" is the name of a website, like www.cloudflare.com).

        - Wildcard: Like a single-domain certificate, a wildcard SSL certificate applies to only one domain. However, it also includes that domain's subdomains. For example, a wildcard certificate could cover www.cloudflare.com, blog.cloudflare.com, and developers.cloudflare.com, while a single-domain certificate could only cover the first.

        - Multi-domain: As the name indicates, multi-domain SSL certificates can apply to multiple unrelated domains.

# What does TLS do? 

    - There are three main components to what the TLS protocol accomplishes

        Encryption: hides the data being transferred from third parties.
        Authentication: ensures that the parties exchanging information are who they claim to be.
        Integrity: verifies that the data has not been forged or tampered with.

# What is a TLS certificate?
    
    - For a website or application to use TLS, it must have a TLS certificate installed on its origin server (the certificate is also known as an "SSL certificate" because of the naming confusion described above). A TLS certificate is issued by a certificate authority to the person or business that owns a domain. The certificate contains important information about who owns the domain, along with the server's public key, both of which are important for validating the server's identity.

# How TLS work?

    - https://www.youtube.com/watch?v=0yw-z6f7Mb4

    - Three elements

        - client
        - Server
        - Hacker (Man in the middle)

    1. solution

        - We encrypt the data using symmetric key (same key is used for encrytoptin and decryption). Client encrytps the data and sends the data along with the key to the server
        
        - problem
            - Hacker can also store the key and encrypt the data

        - What should be done then?

            - both the client and server shoud have the key ans it should not be shared over the network

    2. We use asymmetric encryption for this. We use public and private key for this matter

        - public key is used for encryption and private key is used for decryption

        - There are three types of keys
            - Public key
            - Private key
            - the key that is used for enctypting the data. It is known as "session key"

        - Goal
            - To securely send the session key to the server

        - Approach

            - server sends it's public key to the client
            - client encodes the session key using public k. of the server
            - server decytps it using private key
            
        - How it solves the problem
            
            - Hacker won't be able to see the session key bcz it does not have the private key

    3. Problem in above solution

        - Hacker can act as a proxy between the client and the server
        - Hacker sniffs the public key of server and stores it.
        - hacker sends his own public key to the client
        - client enctypts the data
        - Hacker decrptys it using his own private key
        - Hacker got the session key
        - Hacker once again encrpyts the session key using server's public key and sends to the server
        - This way hacker got the session key

    4. Now the need of SSl certificate arises

        - Consider a certificate issuer "Let's encrpyt"

            - This asks for the domain name of the server and the public k. of the server
            - Let's encrpyt has it's own public and private key
            - Let's encrpyt creates the certificate

                - This certificate has three components
                    - domain name
                    - Server's pub k
                    - expiry date
                    - other metadata
                    - Signature

                - This signature = Encrypted hash of the certificate's data
                
                - Specifically:

                    - The CA takes the certificate’s data (like:

                        domain name
                        public key
                        expiry date
                        other metadata)

                    - Computes a hash (e.g. SHA-256)

                    - Then encrypts that hash using the CA’s private key

                    - That encrypted hash = the digital signature.           

            🔐 How is the Signature Encrypted?                    

                - The CA’s private key is used to encrypt the hash.
                - This is asymmetric encryption.
                - Only the CA’s public key (which everyone trusts) can decrypt this hash.

            🧪 How is the Signature Verified by the User (Client)?
                
                1. Gets the SSL Certificate from the server

                    Includes:
                        - Site’s public key
                        - Signature (from CA)
                        - Info about the CA that signed it

                2. Browser computes its own hash of the certificate contents (using SHA-256)
                3. Browser uses CA’s public key (stored in its trust store) to decrypt the signature (i.e., the encrypted hash)

                4. Compares the decrypted hash with its own hash
                    ✅ If they match → Signature is valid → Certificate trusted
                    ❌ If they don't match → Browser shows ⚠️ Certificate error

# A question that can arise

    - When server gets the ssl certificate from the issuer, can't hacker come in between as a proxy and pass his own public key to the issuer. and in the same case  hacker can act as a proxy bw the client and  the certificate issuer ?

        - This usually can't happen

            1. Domain Ownership Must Be Verified
                
                When a server requests a certificate, the CA doesn’t just blindly sign it. It verifies that the requester controls the domain name (like yourdomain.com) using one of these:

                    - Email challenge (send a code to admin@yourdomain.com)
                    - DNS challenge (you add a TXT record)
                    - HTTP challenge (you host a file at http://yourdomain.com/.well-known/...)

                ✅ So unless the hacker controls the domain, the CA will not issue the certificate.     


