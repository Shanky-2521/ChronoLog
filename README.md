# ChronoLog

A distributed key-value store implementation featuring Raft consensus and LSM-Tree storage.

## Overview

ChronoLog is a distributed database system that combines several key technologies:

- **LSM-Tree Storage**: Write-optimized storage engine with in-memory memtables and persistent SSTables
- **Raft Consensus**: Distributed consensus algorithm for leader election and log replication
- **Write-Ahead Logging**: Crash recovery and durability guarantees
- **Multi-node Clustering**: Fault-tolerant distributed deployment

## Architecture

The system is built in layers:

1. **Storage Layer**: LSM-Tree implementation with memtables and SSTables
2. **Consensus Layer**: Raft algorithm for distributed coordination
3. **Durability Layer**: Write-ahead logging for crash recovery
4. **Network Layer**: HTTP-based RPC for inter-node communication
5. **Client Layer**: Smart client with leader discovery

## Building

Requirements:
- C++17 compatible compiler
- CMake 3.16+
- POSIX-compliant system

```bash
mkdir build && cd build
cmake ..
make
```

## Running Tests

```bash
cd build
make test
```

## Usage

Start a single node:
```bash
./storage_node_demo node1
```

Start a cluster:
```bash
# Terminal 1
./storage_node_demo node1 cluster.json

# Terminal 2
./storage_node_demo node2 cluster.json

# Terminal 3
./storage_node_demo node3 cluster.json
```

Use the client:
```bash
./chronolog_cli cluster.json put key1 value1
./chronolog_cli cluster.json get key1
```