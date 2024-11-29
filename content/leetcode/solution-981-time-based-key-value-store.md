
+++
authors = ["grid47"]
title = "Leetcode 981: Time Based Key-Value Store"
date = "2024-07-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 981: Time Based Key-Value Store in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Binary Search","Design"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "eVi4gDimCoo"
youtube_upload_date="2021-01-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/eVi4gDimCoo/maxresdefault.webp"
comments = true
+++



---
Design a time-based key-value data structure that stores multiple values for the same key at different timestamps and supports retrieving the value at a specific timestamp.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a series of `set` and `get` operations on a `TimeMap` object.
- **Example:** `["TimeMap", "set", "get", "get", "set", "get", "get"] [[], ["user1", "apple", 1], ["user1", 1], ["user1", 3], ["user1", "banana", 4], ["user1", 4], ["user1", 5]]`
- **Constraints:**
	- 1 <= key.length, value.length <= 100
	- key and value consist of lowercase English letters and digits.
	- 1 <= timestamp <= 10^7
	- All timestamps for `set` calls are strictly increasing.
	- At most 2 * 10^5 calls will be made to `set` and `get`.

{{< dots >}}
### Output Specifications 📤
- **Output:** For each `get` operation, return the value corresponding to the key at or before the given timestamp, or an empty string if no such value exists.
- **Example:** `[null, null, "apple", "apple", null, "banana", "banana"]`
- **Constraints:**
	- The output for each `get` operation should be a string.

{{< dots >}}
### Core Logic 🔍
**Goal:** Implement a time-based key-value store with efficient retrieval for a given timestamp.

- Use a map to store key-value pairs along with timestamps.
- For each `set` operation, append the timestamp and value pair to the list of values for the given key.
- For each `get` operation, perform binary search to find the value with the largest timestamp less than or equal to the given timestamp.
{{< dots >}}
### Problem Assumptions ✅
- The data structure supports efficient insertion and retrieval operations.
{{< dots >}}
## Examples 🧩
- **Input:** `["TimeMap", "set", "get", "get", "set", "get", "get"] [[], ["user1", "apple", 1], ["user1", 1], ["user1", 3], ["user1", "banana", 4], ["user1", 4], ["user1", 5]]`  \
  **Explanation:** The example demonstrates the behavior of the `TimeMap` class, where values are stored with timestamps and can be retrieved by the closest timestamp at or before a given time.

{{< dots >}}
## Approach 🚀
We will use a map to store key-value pairs along with their timestamps, and binary search to efficiently retrieve the value for the closest timestamp.

### Initial Thoughts 💭
- The key-value pairs are stored with increasing timestamps.
- Binary search can be applied to find the latest value for a given timestamp.
- We need to balance the efficiency of `set` and `get` operations to handle large input sizes.
{{< dots >}}
### Edge Cases 🌐
- Handling an empty map when no `set` operations have been called yet.
- Efficient handling of large numbers of `set` and `get` operations.
- If no value exists for a given key and timestamp, return an empty string.
- The `set` operations are guaranteed to have strictly increasing timestamps.
{{< dots >}}
## Code 💻
```cpp
map<string, vector<pair<int, string>>> mp;
TimeMap() {
    
}

void set(string key, string value, int timestamp) {
    mp[key].push_back(make_pair(timestamp, value));
}

string get(string key, int ts) {
    if(!mp.count(key)) return "";
    // vector<pair<int, string>> v = &mp[key];
    int l = 0, r = mp[key].size() - 1;
    while(l <= r) {
        int m = l + (r - l) / 2;
        if(ts > mp[key][m].first) {
            if(m == r || ts < mp[key][m + 1].first)
                return mp[key][m].second;
            l = m + 1;
        } else if(ts < mp[key][m].first)
            r = m - 1;
        else return mp[key][m].second;
    }
    return "";
}
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
```

This code defines a class `TimeMap` for storing key-value pairs with a timestamp. It has two main methods: `set` for storing the values, and `get` for retrieving the most recent value at a given timestamp using binary search.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Data Structure Initialization**
	```cpp
	map<string, vector<pair<int, string>>> mp;
	```
	Defines a map `mp` that maps each key (string) to a vector of pairs, where each pair contains a timestamp (int) and a value (string). This structure allows for efficient retrieval of the most recent value at a specific timestamp.

2. **Constructor Definition**
	```cpp
	TimeMap() {
	```
	Defines the constructor of the `TimeMap` class. The constructor does not perform any specific initialization in this case.

3. **Set Method**
	```cpp
	void set(string key, string value, int timestamp) {
	```
	Defines the `set` method, which stores the `value` associated with the `key` and the given `timestamp` in the map `mp`.

4. **Push Value to Map**
	```cpp
	    mp[key].push_back(make_pair(timestamp, value));
	```
	Adds a pair containing the `timestamp` and `value` to the vector associated with the `key` in the map `mp`. If the key does not exist, it will be created.

5. **Get Method**
	```cpp
	string get(string key, int ts) {
	```
	Defines the `get` method, which retrieves the most recent value associated with `key` at or before the given timestamp `ts`.

6. **Key Not Found**
	```cpp
	    if(!mp.count(key)) return "";
	```
	Checks if the `key` exists in the map `mp`. If the key is not found, the method returns an empty string.

7. **Binary Search Initialization**
	```cpp
	    int l = 0, r = mp[key].size() - 1;
	```
	Initializes two pointers, `l` and `r`, to perform a binary search on the vector of pairs for the given `key`.

8. **Binary Search Loop**
	```cpp
	    while(l <= r) {
	```
	Starts a while loop to perform the binary search on the vector of pairs associated with the `key`.

9. **Calculate Middle Index**
	```cpp
	        int m = l + (r - l) / 2;
	```
	Calculates the middle index `m` between `l` and `r` for binary search.

10. **Check Timestamp Greater Than Middle**
	```cpp
	        if(ts > mp[key][m].first) {
	```
	Checks if the `timestamp` `ts` is greater than the timestamp at the middle index `m`.

11. **Check If Next Value Is Better**
	```cpp
	            if(m == r || ts < mp[key][m + 1].first)
	```
	Checks if the current value is the most recent value available for the given `timestamp`.

12. **Return Value**
	```cpp
	                return mp[key][m].second;
	```
	Returns the value associated with the timestamp at the middle index `m`.

13. **Adjust Left Pointer**
	```cpp
	            l = m + 1;
	```
	Adjusts the left pointer `l` to continue the search in the right half of the vector.

14. **Check Timestamp Less Than Middle**
	```cpp
	        } else if(ts < mp[key][m].first)
	```
	Checks if the `timestamp` `ts` is less than the timestamp at the middle index `m`.

15. **Adjust Right Pointer**
	```cpp
	            r = m - 1;
	```
	Adjusts the right pointer `r` to continue the search in the left half of the vector.

16. **Return Value at Exact Match**
	```cpp
	        else return mp[key][m].second;
	```
	Returns the value at the middle index `m` if the `timestamp` exactly matches the timestamp at index `m`.

17. **Return Empty String**
	```cpp
	    return "";
	```
	Returns an empty string if no valid value is found for the given `timestamp`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log n) for `get` due to binary search, O(1) for `set`.
- **Average Case:** O(log n) for `get` due to binary search, O(1) for `set`.
- **Worst Case:** O(log n) for `get` due to binary search, O(1) for `set`.

The `get` operation requires binary search over the list of timestamp-value pairs for a key, while `set` operates in constant time.

### Space Complexity 💾
- **Best Case:** O(1) if no `set` operations have been performed.
- **Worst Case:** O(n) for the space required to store all the timestamp-value pairs for all keys.

The space complexity is linear in the number of `set` operations performed, as each key will store a list of timestamp-value pairs.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/time-based-key-value-store/description/)

---
{{< youtube eVi4gDimCoo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
