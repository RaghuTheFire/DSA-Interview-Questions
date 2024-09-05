/************************************************
Implement a Least Recently Used (LRU) cache.
Example:
Input: LRUCache(2); put(1, 1); put(2, 2); get(1); put(3, 3);
get(2); put(4, 4); get(1); get(3); get(4)
Output: [1, -1, -1, 3, 4]
Explanation:
LRU operations and evictions.
*************************************************/
#include <iostream>
#include <unordered_map>
#include <list>

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        // Move the accessed item to the front of the list
        touch(key);
        return cache[key]->second;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Update the value and move to front
            cache[key]->second = value;
            touch(key);
        } else {
            if (cache.size() == capacity) {
                // Remove the least recently used item
                int lru_key = order.back();
                order.pop_back();
                cache.erase(lru_key);
            }
            // Insert the new item
            order.push_front(key);
            cache[key] = order.begin();
            values[key] = value;
        }
    }

private:
    int capacity;
    std::list<int> order; // List to maintain the order of keys
    std::unordered_map<int, std::list<int>::iterator> cache; // Key to iterator mapping
    std::unordered_map<int, int> values; // Key to value mapping

    void touch(int key) {
        order.erase(cache[key]);
        order.push_front(key);
        cache[key] = order.begin();
    }
};

int main() {
    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    std::cout << lru.get(1) << std::endl; // returns 1
    lru.put(3, 3); // evicts key 2
    std::cout << lru.get(2) << std::endl; // returns -1 (not found)
    lru.put(4, 4); // evicts key 1
    std::cout << lru.get(1) << std::endl; // returns -1 (not found)
    std::cout << lru.get(3) << std::endl; // returns 3
    std::cout << lru.get(4) << std::endl; // returns 4
    return 0;
}

