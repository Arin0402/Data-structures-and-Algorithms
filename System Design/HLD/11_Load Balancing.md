# Load balancing

    - ✅ What is Load Balancing?

        - Load balancing is the process of distributing incoming network traffic or requests across multiple servers or resources to ensure:

            - No single server is overwhelmed
            - High availability
            - Better performance
            - Fault tolerance

        - There are various strategies like Round Robin, Least Connections, and IP Hashing. But these can break or become inefficient when servers (nodes) are added or removed frequently — which is where consistent hashing comes in.
    
    🔄 Where Does Consistent Hashing Come In?

        - Consistent hashing is a technique often used in distributed systems and load balancing to handle dynamic scaling of nodes (adding/removing servers) with minimal disruption.

    🎯 Problem with Traditional Hashing:

        - In naive hashing:

            serverIndex = hash(requestKey) % totalServers

        - If you add/remove a server, the value of totalServers changes.

        - As a result, almost all keys get remapped to different servers — causing a lot of cache misses or redistributions in systems like databases or load balancers.

    - What is meant by cache miss is that it would happeing that the server would be storing data related to certin users in the cache. This is the data of the users for which requests were coming to this server. Now when the new server is added, then it might happen the request for this user would go to another server because of change in index number and because of this, the data stored in the cache would be useless

    - Watch this to get better understanding
        
        https://www.youtube.com/watch?v=K0Ta65OqQkY

# What is consistent hashing and how it solves the problem
    
    - https://www.youtube.com/watch?v=zaRkONvyGr8