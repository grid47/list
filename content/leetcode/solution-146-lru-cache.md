
+++
authors = ["grid47"]
title = "Leetcode 146: LRU Cache"
date = "2024-10-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 146: LRU Cache in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Linked List","Design","Doubly-Linked List"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/146.webp"
youtube = "7ABFKPK2hD4"
youtube_upload_date="2020-12-21"
youtube_thumbnail="https://i.ytimg.com/vi/7ABFKPK2hD4/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/146.webp" 
    alt="A cache where items are gently shifting in and out, with the most recently used glowing brightly."
    caption="Solution to LeetCode 146: LRU Cache Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Design and implement an LRU (Least Recently Used) cache. The cache should support two operations: `get(key)` and `put(key, value)`. Both operations must run in O(1) time on average. If the cache exceeds its capacity, the least recently used key should be evicted.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a series of operations on the LRUCache. The operations include initializing the cache with a given capacity and executing `get` and `put` commands.
- **Example:** `Input: ['LRUCache', 'put', 'put', 'get', 'put', 'get', 'put', 'get', 'get', 'get'] [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]`
- **Constraints:**
	- The number of operations will be at most 2 * 10^5.
	- Capacity of the cache will be between 1 and 3000.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a list of results corresponding to the `get` operation for each test case.
- **Example:** `Output: [null, null, null, 1, null, -1, null, -1, 3, 4]`
- **Constraints:**
	- The output for each operation is either the return value of `get(key)` or null for `put(key, value)`.

{{< dots >}}
### Core Logic 🔍
**Goal:** Design a data structure that efficiently handles `get` and `put` operations with O(1) average time complexity.

- Use a hash map to store the key-value pairs for O(1) lookups.
- Use a doubly linked list to maintain the order of use of keys, where the most recently used key is at the front and the least recently used is at the back.
- On `put`, add the key-value pair to the cache and move it to the front. If the cache exceeds capacity, evict the least recently used key from the back.
{{< dots >}}
### Problem Assumptions ✅
- The cache will only contain integer keys and values.
- The input operations will be well-formed and within the constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: ['LRUCache', 'put', 'put', 'get', 'put', 'get', 'put', 'get', 'get', 'get'] [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]`  \
  **Explanation:** In this example, the cache is initialized with a capacity of 2. The operations are performed as described, with key-value pairs being added to the cache and the least recently used keys being evicted when necessary.

{{< dots >}}
## Approach 🚀
We can solve this problem using a combination of a hash map and a doubly linked list to maintain the cache and manage eviction of the least recently used key.

### Initial Thoughts 💭
- The most challenging part is ensuring that both `get` and `put` operations run in O(1) time.
- A hash map will provide O(1) access to values, while a doubly linked list will help us manage the order of access.
- The doubly linked list allows us to efficiently add and remove nodes, and the hash map allows for fast lookups.
{{< dots >}}
### Edge Cases 🌐
- Ensure that operations on an empty cache handle edge cases, such as requesting a value that doesn't exist.
- Handle large numbers of operations efficiently within the time and space constraints.
- Ensure that key-value pairs with edge values (e.g., 0, 10^5) are handled properly.
- The solution must meet time and space complexities within the provided constraints.
{{< dots >}}
## Code 💻
```cpp
map<int, list<pair<int, int>>::iterator> mp;
list<pair<int, int>> q;
int cap;
LRUCache(int capacity) {
    cap = capacity;
}

int get(int key) {
    if(!mp.count(key)) return -1;
    auto it = *mp[key];
    q.erase(mp[key]);
    q.push_front(make_pair(key, it.second));
    mp[key] = q.begin();
    return it.second;
}

void put(int key, int value) {
    if(mp.count(key)) {
        q.erase(mp[key]);
        q.push_front(make_pair(key, value));
        mp[key] = q.begin();
    } else {
        q.push_front(make_pair(key, value));
        mp[key] = q.begin();
        if(q.size() > cap) {
            mp.erase(q.back().first);
            q.pop_back();
        }
    }
}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
```

This is an implementation of an LRU Cache using a combination of a hash map and a doubly linked list to maintain the order of access. The cache supports two operations: `get(key)` to retrieve a value and `put(key, value)` to insert or update a value. When the cache exceeds its capacity, the least recently used item is removed.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	map<int, list<pair<int, int>>::iterator> mp;
	```
	Declares a map `mp` that stores iterators to a doubly linked list. This map is used to quickly locate the nodes by their keys.

2. **List Declaration**
	```cpp
	list<pair<int, int>> q;
	```
	Declares a doubly linked list `q` where each node stores a key-value pair. This list maintains the order of access from the most recently used (front) to the least recently used (back).

3. **Variable Declaration**
	```cpp
	int cap;
	```
	Declares an integer `cap` to hold the maximum capacity of the LRU Cache.

4. **Constructor**
	```cpp
	LRUCache(int capacity) {
	```
	Constructor for the LRUCache class, initializing the cache with a given capacity.

5. **Initialize Capacity**
	```cpp
	    cap = capacity;
	```
	Sets the `cap` variable to the provided capacity, which limits the number of items the cache can hold.

6. **Function Definition**
	```cpp
	int get(int key) {
	```
	Defines the `get` function, which retrieves the value associated with the given key if it exists in the cache.

7. **Check If Key Exists**
	```cpp
	    if(!mp.count(key)) return -1;
	```
	Checks if the key exists in the map. If not, returns -1 to indicate the key is not found.

8. **Retrieve Value**
	```cpp
	    auto it = *mp[key];
	```
	Retrieves the iterator to the node in the list corresponding to the given key.

9. **Move Node to Front**
	```cpp
	    q.erase(mp[key]);
	```
	Erases the current node from its position in the list, as it needs to be moved to the front to mark it as recently used.

10. **Reinsert Node**
	```cpp
	    q.push_front(make_pair(key, it.second));
	```
	Inserts the key-value pair at the front of the list to mark it as the most recently used.

11. **Update Map**
	```cpp
	    mp[key] = q.begin();
	```
	Updates the map with the new iterator pointing to the front of the list for the given key.

12. **Return Value**
	```cpp
	    return it.second;
	```
	Returns the value associated with the key.

13. **Function Definition**
	```cpp
	void put(int key, int value) {
	```
	Defines the `put` function, which inserts a key-value pair into the cache, or updates an existing key.

14. **Check If Key Exists**
	```cpp
	    if(mp.count(key)) {
	```
	Checks if the key already exists in the cache.

15. **Update Existing Node**
	```cpp
	        q.erase(mp[key]);
	```
	Erases the old entry for the key from the list.

16. **Reinsert Node**
	```cpp
	        q.push_front(make_pair(key, value));
	```
	Inserts the key-value pair at the front of the list to mark it as the most recently used.

17. **Update Map**
	```cpp
	        mp[key] = q.begin();
	```
	Updates the map with the new iterator pointing to the front of the list for the given key.

18. **Handle New Key**
	```cpp
	    } else {
	```
	If the key does not already exist in the cache, handle it as a new key-value pair.

19. **Insert New Node**
	```cpp
	        q.push_front(make_pair(key, value));
	```
	Inserts the new key-value pair at the front of the list.

20. **Update Map**
	```cpp
	        mp[key] = q.begin();
	```
	Updates the map with the new iterator pointing to the front of the list for the given key.

21. **Evict Least Recently Used**
	```cpp
	        if(q.size() > cap) {
	```
	Checks if the size of the list exceeds the cache's capacity.

22. **Remove Least Recently Used**
	```cpp
	            mp.erase(q.back().first);
	```
	Erases the least recently used item (at the back of the list) from both the list and the map.

23. **Pop Back**
	```cpp
	            q.pop_back();
	```
	Removes the last element from the list, which is the least recently used key-value pair.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

Both `get` and `put` operations will run in constant time due to the use of a hash map for lookups and a doubly linked list for order management.

### Space Complexity 💾
- **Best Case:** O(capacity)
- **Worst Case:** O(capacity)

The space complexity is proportional to the cache's capacity, as each key-value pair takes up space in the cache.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/lru-cache/description/)

---
{{< youtube 7ABFKPK2hD4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
