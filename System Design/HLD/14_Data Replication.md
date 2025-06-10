# Data replication

    - https://www.youtube.com/watch?v=GeGxgmPTe4c

🔹 What is Sharding?

    Sharding means splitting data into parts ("shards"), where each shard is stored and managed by a different node in the system.

    👉 You don’t store the whole dataset on every machine — each machine is responsible for just a piece of it.

📦 Real-World Analogy:

    Imagine a library split into sections:

    Room A has books A–F
    Room B has books G–L
    Room C has books M–Z

    That’s sharding.

🔁 So How Does Sharding Relate to Multi-Master and Consensus?

    Let’s look at how these concepts play together:

    🧱 1. Sharding with One Master per Shard
        Each shard has its own master node (responsible for that part of the data).

        This is like having mini master-slave systems per shard.

        Good for scalability.

        📌 Example: MongoDB sharded cluster

    🤝 2. Sharding with Multi-Master Setup


        Multiple nodes may write to different shards.

        You must still ensure consistency inside each shard.

        If two nodes try to write to the same shard, you may need consensus or conflict resolution.

        📌 Example: Amazon DynamoDB, Cassandra

    📡 3. Sharding with Distributed Consensus

        In systems like Google Spanner or CockroachDB, data is sharded, and each shard is managed by a consensus group (Raft or Paxos).

        Each shard elects a leader (master) via consensus.

        So now, every shard has its own mini consensus group.

    ✅ This gives:

        Scalability via sharding
        Consistency via consensus
        Fault-tolerance via replication