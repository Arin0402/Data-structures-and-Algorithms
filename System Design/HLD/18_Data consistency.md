#  What is Consistency

    - In a distributed system (like a set of servers), consistency is about how up-to-date and synchronized the data is across all systems.

# Data consistency

    - This describes how in general, consistency is maintained in a distributed transactional system
    - 2 PC
    - https://www.youtube.com/watch?v=m4q7VkgDWrM
    
# Different consistency levels

    - Types

        - Eventual
        - Causal
        - Sequential
        - Strict/Linerizability

# Eventual consistency

    - Weakest form of consistency
    - All replicas will eventually return the same value for read requests but takes some time
    - Ensures high availablty
    - DNS uses eventual consistency
    - Cassandra uses eventual consistency
    - ex: the views on a youtube video

#  Causal consistency

    - “If one change depends on another, people will see them in the correct order.”
    - perserves the order of causally-related(dependent) operations
    - Doesn't ensure the ordering of operations that are non-causal
    - Weak consistency but stronger that eventual consistency
    - ex: Comments. if r2 is the reply of r1, then for all the systems r1 would appear first and then only r2. It won't happen that r2 came and r1 is not there.

# Sequential consistency

    -  "Operations from all users appear in a single global order, and each user sees operations in that same order."

    - But this order doesn’t have to be real-time—it just has to be the same for everyone.

    - Imagine a group chat where people are sending messages. Even if some messages are delayed in delivery for a person, everyone sees the same final sequence of messages, even if it's not exactly the order they were sent in real time.

    - Example:

        Arin sends "Hi"
        You send "Hello"
        Maya sends "What's up?"

    Even if those messages were sent at slightly different times, everyone sees the same order

# Strict consistency

    - Strongest form of consistency
    - Every read operation returns the most recent write, instantly across all the nodes
    - "If I write data, everyone else sees that exact value immediately—no delays, no exceptions."
    - Ex:
        - Password update of bank acoount
        - Amazon aura

    - This is not achievable in most distributed systems due to network latency
    
# But how does password updation works if there is netowork delay and it may happen that I could be able to login using the older value ?

    - 🔄 What Happens During Password Update

        - You change your password.
        - The system writes the new password to the database.
        - Immediately after, you try to log in with the new password.

    - 🏦 Password Update = Strong Consistency Needed

    - Most systems don’t update passwords across all replicas instantly. Instead, they write the update to one strongly consistent, authoritative source, and only allow reads (like login attempts) from that same source until replication catches up.

    🧱 Here's How It Works in Practice:

    1. Designated Master / Primary Node (Single Source of Truth)

        Password updates are written to a primary database node (e.g., master in master-slave setup).

        Reads during sensitive operations (like login) are also directed to that node.

        Other replicas may receive the change later (asynchronously), but they are not used for login during that time.

    2. Synchronous Write Acknowledgement

        When you update your password, the system waits for confirmation from the primary node that the write succeeded.

        Only then does it return a success to the user. 

    3. Failover With Caution
    
        If the primary node fails before the change replicates, a new leader is elected carefully.

        Systems like Raft or Paxos ensure that only nodes with the most recent data can become leaders.

    4. Two-phase Commit


# How Quorum is used in achieving strong consistency

    - Quorum in distributed systems refers to the minimum number of nodes (or replicas) that must agree (respond) to successfully perform a read or write operation.

    -   N = Total number of replicas/nodes
        W = Minimum nodes required to acknowledge a write
        R = Minimum nodes required to respond to a read

    🎯 Condition for Strong Consistency

        To guarantee strong consistency:

        ✅ R + W > N

        This ensures that every read overlaps with every write — at least one node will have the latest data.

    🔄 How Quorum Achieves Strong Consistency

        📌 1. Write Quorum (W)

            A write is only considered successful if it’s written to W nodes.

            Ensures data is replicated to a majority.

        📌 2. Read Quorum (R)

            A read must query R nodes and pick the latest value (based on timestamp or version).

            Even if some nodes are stale, one of them must have the latest write (because R + W > N).

        📌 3. Overlap Guarantees Freshness

            guaranteed to read at least one copy that contains the most recent write.

    🧠 Example (N = 5)

        W = 3 (write to 3 replicas)
        R = 3 (read from 3 replicas)
        R + W = 6 > 5 ✅

        Any read will touch at least one node that got the write, ensuring strong consistency.

    ❗ Important Notes

        Reading from a single node (R = 1) may return stale data ❌

        Quorum is a balance between consistency, availability, and latency

        Higher R and W = stronger consistency, but slower performance

# Note:

    Cassandra by default supports eventual consistency but it can be tuned to support strong consistency via quorum