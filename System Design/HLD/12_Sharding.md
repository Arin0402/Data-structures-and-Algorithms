# What is Sharding
    
    https://www.youtube.com/watch?v=5faMjKuB9bc

    - Sharding is a database partitioning technique where data is horizontally split across multiple databases (or servers), called shards, so that each shard holds only a subset of the data.

    - Instead of putting all data into a single database, we divide it based on some shard key (e.g., user ID, region, account number).

    - If you have 100 million users:

        - Instead of storing all users in one database,
        - You split users across 5 shards using a rule like:

            shard = hash(user_id) % 5

    - Master Slave architecture is implemented for each shard for fault tolerance and efficiency

    - Load balancing can be implemented among the replica set for read operations. For write operations, the requests always go to a primary node and then replication happens from that node.
    
    - In case of primary node fails, then one of the read repilca becomes the primary node