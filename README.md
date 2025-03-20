# Simple Redis-like Cache in C++

This is a basic implementation of a Redis-like cache in C++. It supports key-value storage, key expiration, and LRU (Least Recently Used) eviction policy.

## What It Does

- **Store key-value pairs**: You can add and retrieve values using keys.
- **Set expiration for keys**: Keys can be set to expire after a certain number of seconds.
- **LRU eviction**: If the cache reaches its capacity, the least recently used item is removed.
- **Thread-safe**: Uses mutexes to handle concurrent access safely.

## Commands
- **SET `<key>` `<value>`**: Stores a key-value pair in the cache.
- **GET `<key>`**: Retrieves the value associated with the key.
- **EXPIRE `<key>` `<seconds>`**: Sets a time-to-live (TTL) for the key.
- **EXIT**: Exits the CLI.

## How to Use

1. **Compile and run the program**:
   ```bash
   ./compile_and_run.sh
