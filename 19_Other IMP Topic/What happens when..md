# What happens when user enters google.com in the browser

## Step 1: Browser Checks Cache (Local Lookup)

    - Before making a network request, the browser checks if it has a cached copy of the page:

        1. Browser Cache → Has the page been visited recently?
        2. DNS Cache → Is the IP address for google.com already stored?
        3. Operating System Cache → Does the OS have a cached DNS entry?
        4. Router Cache → Is there a cached DNS entry in the router?

    ✅ If found in cache → Page loads instantly.
    ❌ If not found → Proceed to DNS resolution.

## Step 2: DNS Resolution (Domain to IP Translation)

    - The browser needs to translate "google.com" into an IP address

        1. Browser asks the OS for google.com's IP
        2. OS checks its local cache
        3. OS queries the configured DNS server (usually provided by ISP, Google DNS 8.8.8.8, Cloudflare 1.1.1.1)
        4. DNS server responds with Google's IP address (e.g., 142.250.183.14)

## Step 3: Establish a TCP Connection (3-Way Handshake)

    - Now that the browser has Google’s IP, it establishes a connection using TCP (Transmission Control Protocol):

        1. Client (your browser) sends SYN (synchronize) packet
        2. Server (Google) responds with SYN-ACK (synchronize-acknowledge) packet
        3. Client replies with ACK (acknowledge) packet

    ✅ Connection established!

## Step 4: TLS Handshake (if HTTPS)

    - Since google.com uses HTTPS, a TLS (Transport Layer Security) handshake happens to establish a secure connection:

    1. Client sends "Client Hello" → Advertises supported encryption methods
    2. Server responds with "Server Hello" → Chooses encryption method and sends certificate
    3. Client verifies the certificate (issued by a trusted CA like DigiCert)
    4. Key Exchange & Session Encryption → Both sides agree on a secret key

    ✅ Secure HTTPS connection established!

## Step 5: Sending an HTTP Request

    - Now, the browser sends an HTTP GET request to fetch the page:

    This request includes:

        Host: google.com (to tell the server which site you want)

        User-Agent: Info about your browser

        Cookies: (if you’re logged in, etc.)

## Step 6: Server Processes the Request

    - Google’s Load Balancer receives the request and forwards it to an available server in a nearby data center. The server:

        1. Checks if the request is valid (e.g., security checks)
        2. Retrieves the homepage (index.html)
        3. Gathers other resources (JavaScript, CSS, images, etc.)
        4. Returns the response

## Step 7: Browser Receives Response

    - Google’s server sends back an HTTP Response:  

        1. Status Code 200 OK → Success
        2. HTML Content → The page structure
        3. Other Headers → Cache control, security headers, etc.

## Step 8: Browser Renders the Page

    - Now, the browser:

        1. Parses the HTML → Builds the DOM (Document Object Model)
        2. Loads CSS → Styles the page
        3. Loads JavaScript → Runs scripts for interactivity
        4. Fetches additional resources (e.g., images, fonts)                                        

## Step 9: Displaying the Page

    - Once everything is loaded:

        1. The Google homepage is displayed
        2. JavaScript may load dynamic content (e.g., search suggestions)
        3. The browser keeps an open connection for new requests (like search queries)

## Step 10: User Interaction & Further Requests

    - When you type a search query, a new XHR (AJAX) request is sent, updating the page without a full reload.        

## Optimizations That Speed Up the Process

    - CDNs (Content Delivery Networks) → Serve assets from nearby locations
    - HTTP/2 Multiplexing → Multiple requests in a single connection
    - Caching → Reduces redundant requests
    - Preloading & Prefetching → Anticipates user actions

## Summary of Steps

    1️⃣ Cache Check (Browser, OS, Router)
    2️⃣ DNS Resolution (google.com → 142.250.183.14)
    3️⃣ TCP Handshake (SYN, SYN-ACK, ACK)
    4️⃣ TLS Handshake (Secure HTTPS connection)
    5️⃣ HTTP Request Sent (GET /)
    6️⃣ Server Processes Request
    7️⃣ Server Responds (200 OK)
    8️⃣ Browser Renders the Page
    9️⃣ User Interacts, Further Requests Sent


    