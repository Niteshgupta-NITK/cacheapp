# Cache++

Cache++ is a blazing-fast, distributed, in-memory caching system built from scratch in C++ — inspired by systems like Redis and Memcached. It’s designed to explore low-level systems programming, concurrency, distributed design patterns, and memory-efficient storage.

---

## Core Features

- 🧠 **In-Memory LRU Cache** with O(1) get/set
- 🔗 **Multi-threaded TCP Server** using POSIX sockets
- 🧵 **Thread Pool** for concurrent client handling
- 🔄 **Consistent Hashing** for distributed key sharding
- 🔐 **Thread-Safe** access with mutexes and safe data structures
- 💾 (Optional) **Write-Ahead Logging** for persistence
- 📡 (WIP) **Leader-Follower Replication** for fault tolerance

---

##  Architecture Overview

```mermaid
graph TD;
    A[Client 1] -->|GET key| B[Cache Node A]
    A2[Client 2] -->|SET key| B
    A3[Client 3] -->|GET key| C[Cache Node B]
    
    subgraph Cluster
        B -- Sync --> C
        B -- Sync --> D[Cache Node C]
    end

    B --> E[Consistent Hash Ring]
    C --> E
    D --> E

    E -->|Locate Node| B

