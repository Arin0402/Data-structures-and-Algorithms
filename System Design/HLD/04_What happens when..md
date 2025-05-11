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

        2. OS checks its local cache, if found then return

        3. OS asks the Resolver (or Internet Service Provider) server to look up its cache to see if it knows the IP Address, if the Resolver does not know then it asks the root server to ask the .COM TLD (Top Level Domain) server - if your URL ends in .net then the TLD server would be .NET and so on - the TLD server will again check in its cache to see if the requested IP Address is there. 
        
        4. If not, then it will have at least one of the authoritative name servers associated with that URL, and after going to the Name Server, it will return the IP Address associated with your URL. All this was done in a matter of milliseconds WOW!
        
## Step 3: 

    - After the OS has the IP Address and gives it to the browser, it then makes a GET (a type of HTTP Method) to said IP Address. When the request is made the browser again makes the request to the OS which then, in turn, packs the request in the TCP traffic protocol we discussed earlier, and it is sent to the IP Address. 


## Step 4: Establish a TCP Connection TLS Handshake (if HTTPS)

    - On its way, it is checked by both the OS' and the server's firewall to make sure that there are no security violations. And upon receiving the request the server (usually a load balancer that directs traffic to all available servers for that website) sends a response with the IP Address of the chosen server along with the SSL (Secure Sockets Layer) certificate to initiate a secure session (HTTPS). 

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


    