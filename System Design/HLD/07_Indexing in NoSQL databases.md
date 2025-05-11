# Indexing in NoSQL databases

    1. Key-Value Stores (e.g., Redis, DynamoDB)
        - The key itself acts as the primary index, enabling O(1) lookups via hash tables.

    2. Document Stores (e.g., MongoDB, Couchbase)   
        - Indexes can be created on any field, including nested or array elements.

    3. Column-Family Stores (e.g., Apache Cassandra, HBase)
        - Partition key distributes data across nodes.

    4. Graph Databases (e.g., Neo4j, Amazon Neptune)    
        - Index properties (e.g., user email) to quickly locate graph entry points.

    https://www.youtube.com/watch?v=mTNkqMDCasI