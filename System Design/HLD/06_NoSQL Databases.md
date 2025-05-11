# NoSQL Databases

    - In terms of scalability, relational databases (RDBMS) and NoSQL databases face different challenges and have different strengths. Here’s a breakdown of the problems relational databases face compared to NoSQL databases when it comes to scaling:

    1. Horizontal vs Vertical Scaling

        Relational Databases (RDBMS):

            - Typically scale vertically (i.e., adding more CPU, RAM, storage to a single server).

            - This approach has limits, as the hardware resources on a single machine are finite, and scaling up can become expensive and inefficient after a certain point.

            - Vertical scaling leads to single points of failure (if that one server goes down, the entire database is unavailable).

        NoSQL Databases:

            - Designed to scale horizontally (i.e., adding more machines/servers to distribute the load).

            - Horizontal scaling is more flexible and cost-effective because you can add more servers as the workload increases. This is especially important for handling large-scale web applications or big data.

            - NoSQL systems are built to distribute data across multiple servers or nodes and are designed to handle high availability and fault tolerance.

    2. Data Model and Schema

        Relational Databases (RDBMS):

            - Use a fixed schema (tables with predefined columns).

            - Changing the schema, especially when scaling out (horizontally), can be complex and time-consuming.

            - The need for joins and ACID transactions complicates scaling because relational databases need to maintain consistency and integrity across multiple tables and rows.

            - Sharding or splitting the data across multiple servers can be difficult, as related data often needs to stay together (due to the relational nature), which requires complex handling.

        NoSQL Databases:

            - Use flexible schema or schema-less models (e.g., key-value, document, column-family, graph).

            - NoSQL databases can handle unstructured or semi-structured data easily, which makes them more scalable for modern, dynamic applications.

            - Many NoSQL databases distribute data easily across multiple nodes because they don’t require the complex relationships (joins) that relational databases do.

            - They often support eventual consistency, which helps scale systems faster but without full ACID guarantees.

    3. Scaling with Joins and Transactions

        Relational Databases (RDBMS):

            - Relational databases often use joins to combine multiple tables, which can degrade performance as the dataset grows.

            - ACID (Atomicity, Consistency, Isolation, Durability) properties are crucial in ensuring data integrity, but they can create bottlenecks when scaling because they require all nodes to stay in sync and consistent.

            - Transactional overhead: Ensuring transactional consistency can be expensive when scaling horizontally across distributed systems.

        NoSQL Databases:

            - Most NoSQL databases avoid joins and don’t rely on complex transactional processing.

            - This simplicity allows NoSQL databases to scale out more easily without being burdened by transaction management across distributed nodes.

            - NoSQL databases use techniques like eventual consistency or tunable consistency to provide flexibility and reduce the overhead of maintaining strict consistency.

    4. Data Distribution and Sharding

        Relational Databases (RDBMS):

            - Sharding (splitting data across multiple servers) is difficult and often requires custom logic to partition data while ensuring data integrity.

            - Traditional relational databases are not designed for distributed environments, so managing data consistency across multiple nodes while still supporting ACID transactions can be challenging.

            - Replication in relational databases can be slow and requires careful configuration.

        NoSQL Databases:

            - Sharding is built into many NoSQL databases, making it easier to automatically partition data across nodes.

            - NoSQL systems can efficiently distribute the load of large datasets across multiple machines, and many NoSQL databases come with automatic replication, ensuring data availability and fault tolerance.

    5. Handling High Throughput and Large Volumes of Data
    
        Relational Databases (RDBMS):

            - As data grows, relational databases can struggle to handle high throughput, especially when scaling writes and reads.

            - RDBMS requires careful indexing and optimization to handle large datasets, and maintaining high availability while also scaling can be difficult.

            - Lock contention and deadlocks may occur in transactional systems when scaling up.

        NoSQL Databases:

            - NoSQL databases are designed to handle high throughput and large volumes of data, making them ideal for applications like big data, IoT, and real-time analytics.

            - They are optimized for quick reads/writes and can scale easily to handle large volumes of data without significant degradation in performance.

# 💡 Why Do NoSQL Databases Scale Better?

    - Flexibility in data model (schema-less, dynamic data).
    - Distributed nature with automatic sharding and replication.
    - Eventual consistency allows for faster data writes and higher availability.
    - No complex joins required, simplifying the data distribution and access across multiple servers.

# 📊 Conclusion:

    - Relational Databases are great for structured data and transactions with strong consistency needs, but they face challenges when scaling horizontally due to their reliance on ACID, fixed schema, and complex joins.

    - NoSQL Databases are optimized for scalability, flexibility, and high-throughput workloads, making them better suited for modern, large-scale applications that can tolerate eventual consistency.

    - In NoSQL, ACID is often limited to local scopes (e.g., per document or partition).

    - Global ACID across a cluster is harder due to performance and availability trade-offs (as explained by the CAP theorem).

# Introduction to NoSQL databases

    - https://www.youtube.com/watch?v=xQnIN9bW0og

# Types of NoSQL databases

    -  1. Document-Based Databases

        - Stores data as JSON-like documents (key-value pairs, nested structure).
        - Best for semi-structured data, content management, user profiles.
        - MongoDB, CouchDB, Firebase Firestore

        ✅ Flexible schema
        ✅ Good for hierarchical data

    - 2. 2. Key-Value Stores

        - Stores data as simple key–value pairs.
        - Best for fast lookups, session management, caching.

        Examples:
            Redis, Riak, Amazon DynamoDB

        ✅ Extremely fast
        ✅ Easy to scale

    - 3. Column-Family Stores

        - Stores data in rows and columns, like RDBMS, but grouped by column families.
        - Best for large-scale analytics, time-series data.

        Examples:
            Apache Cassandra, HBase, ScyllaDB

        ✅ High write throughput
        ✅ Good for distributed big data systems

    - 4. Graph Databases

        - Stores data as nodes and edges (relationships).
        - Best for complex relationships: social networks, recommendation engines.

        Examples:
            Neo4j, Amazon Neptune, ArangoDB, OrientDB

        ✅ Powerful relationship queries
        ✅ Efficient traversal

# What is the difference between key value and document based databases if they both store data as key-value pair

    - Basically, the main difference is that in a key-value store the "value" of each record is treated as an opaque string; the database doesn't care what it contains.

    - This gives a document-oriented database two main advantages:

        - You can do more complex and fine-grained operations than just reading or writing an entire value at once.

        - The database can index fields of a document, allowing you to do queries based on those indexed fields, instead of having to always use the single key that was specified up front.

        - Key-Value does not have any specfic schema whereas document databaeses have

    🔑 In Short:

        Key-Value: Just like a dictionary → { "user123": "some data" }
        (you can't search inside "some data")

        Document Store: JSON-like → { "user123": { "name": "Arin", "age": 23 } }
        (you can query: find where name = "Arin")

# How do noSql Databases work?

    - https://www.youtube.com/watch?v=0buKQHokLK8

# In case of analythics query, comparision bw RDBMS and NoSQL


    - If data is small to medium → RDBMS is typically better optimized for analytical queries due to SQL and indexing.

    - If data is huge and distributed → NoSQL (like MongoDB, Cassandra) can outperform due to horizontal scalability, if proper indexes are used.

    📌 For heavy analytics, some companies:

        - Use NoSQL for storage (fast ingestion)
        - ETL data into RDBMS or OLAP systems (like BigQuery, ClickHouse) for analytics

# What happens in case of Large Bank servers

    - Do banks use Sharding ?

    ✅ Yes, but typically in controlled ways, and not for everything.

    - Sharding in Banks database is challeging due to ACID consstraints
    
    🔹 What Do Banks Use Instead of Pure RDBMS Sharding?

        - High-end distributed RDBMS systems (e.g., Oracle RAC, IBM DB2)
        - Data partitioning (logical separation) within a monolithic RDBMS
        - ETL to data lakes or OLAP systems for analysis
        - Message queues + microservices to isolate data and scale

    ✅ In Summary:

        Yes, large banks do use sharding, but carefully, often combining:

            Vertical scaling (big powerful servers),
            Partitioning within RDBMS,
            Distributed caching,
            Hybrid use of NoSQL for non-critical data (e.g., logs, analytics).
            
# How Banks Mitigate the SPOF(Single point of failure) Risk in Vertical Scaling:

    - A standby server is ready to take over if the primary fails.
    - Multiple servers act as one logical DB; failover is automatic.
    - Distributed system is used

#  What is a Distributed RDBMS?

    - A Distributed Relational Database Management System (Distributed RDBMS) is a database system where data is stored across multiple physical machines, but it appears as a single logical database to users and applications.

    - So instead of one big server (vertical scaling), the database is spread over many servers (horizontal scaling), while still preserving ACID properties and SQL capabilities.

    - Data is replicated across nodes → if one fails, others take over.
    
    - You can add more machines to scale horizontally.

    - Data can be partitioned (sharded) and accessed in parallel.

    - Distributed systems can be updated node by node with no full downtime.

    - Nodes can be located in different regions → useful for global apps.

    - ex:

        - Cockroach db
        - Amazon Aurora
    
# So what is the difference bw Sharding and distributed system

    - Sharding is a technique used inside a distributed system.

    - A distributed RDBMS may use sharding + replication + coordination to scale and stay reliable.

    - Distributed systems solve more than just data size — they also handle availability, consistency, and fault-tolerance.

    - Why Are Banks Still Using Traditional SQL Databases instead of Dsitributed sysytem?   

        - Core banking systems were built decades ago with Oracle, DB2, etc. Migrating them is risky, costly, and time-consuming.
        - Traditional RDBMS have been battle-tested for years. Banks value stability and predictability over innovation.
        - Applications are tightly coupled to the underlying database structure — moving would require redesigning core logic.

# How Banks scale Traditional databases

    - Banks scale traditional databases using read replicas, vertical scaling, app-level sharding, and smart caching, but it comes at the cost of increased complexity and operational overhead.

    - But using read replicas can also have consistecy issue, what if updates are not propgated to the read replica db yet ?

        - Yes it is true, here is how bank handles it

            - Any read that follows a write (e.g., showing your updated balance after a fund transfer) is routed to the primary DB. This ensures you're always seeing the latest committed data.

            - Once a user performs a write, all reads from that user session are routed to the same primary for some time. This avoids hitting a replica that may be behind.

            - Non-critical reads (like monthly statements, summaries, or dashboards) are offloaded to replicas, where eventual consistency is acceptable.
            
            - Some modern banks and fintechs (like Nubank, or newer parts of traditional banks) use distributed SQL databases like Google Spanner or CockroachDB which provide:

                - Horizontal scaling with strong consistency
                - Synchronous replication and global transactions