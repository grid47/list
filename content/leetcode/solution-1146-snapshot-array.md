
+++
authors = ["grid47"]
title = "Leetcode 1146: Snapshot Array"
date = "2024-07-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1146: Snapshot Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Design"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You need to implement a data structure that captures snapshots of an array and allows retrieving the value at any given index at a specific snapshot.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of several commands that invoke methods on the SnapshotArray class. The array is initialized with a given length and the following methods are used: 'set', 'snap', and 'get'.
- **Example:** `["SnapshotArray", "set", "snap", "get"]
[[4], [2, 10], [], [2, 0]]`
- **Constraints:**
	- 1 <= length <= 5 * 10^4
	- 0 <= index < length
	- 0 <= val <= 10^9
	- 0 <= snap_id < (the total number of times we call snap())
	- At most 5 * 10^4 calls will be made to set, snap, and get.

{{< dots >}}
### Output Specifications 📤
- **Output:** For each command, the output is specified in the order of the commands: 'null' for methods that do not return anything and the result of 'snap' and 'get' for the respective method calls.
- **Example:** `[null, null, 0, 10]`
- **Constraints:**
	- The output corresponds to the results of the respective methods called in the input.

{{< dots >}}
### Core Logic 🔍
**Goal:** Implement the SnapshotArray class with methods set, snap, and get to manipulate an array and capture its state over time.

- Initialize the array with zeros.
- Implement set to store the current value at the specified index for the current snapshot.
- Implement snap to take a snapshot and return the current snap_id.
- Implement get to retrieve the value at the specified index at the time of the given snap_id.
{{< dots >}}
### Problem Assumptions ✅
- All elements in the array are initially set to 0.
- Each snap_id is unique and increments each time snap() is called.
{{< dots >}}
## Examples 🧩
- **Input:** `["SnapshotArray", "set", "snap", "set", "get"]
[[3], [0, 5], [], [0, 6], [0, 0]]`  \
  **Explanation:** This example initializes a SnapshotArray with length 3, performs a set operation, takes a snapshot, performs another set operation, and finally retrieves the value of index 0 at snap_id 0.

{{< dots >}}
## Approach 🚀
The solution involves using a map to track the history of changes for each index in the array, while maintaining the current snapshot ID.

### Initial Thoughts 💭
- The array needs to store historical changes for each index to support the snapshot functionality.
- Using a map of maps can help track changes at each snap_id.
- To optimize get operations, it's essential to maintain a way to efficiently fetch the value at any given snap_id for an index.
{{< dots >}}
### Edge Cases 🌐
- Handle the case where no set or snap operations are called.
- Efficiently handle cases where the length of the array is large, up to 50,000.
- Handle large values of val up to 10^9.
- The solution must ensure that all operations are performed within the provided time limits.
{{< dots >}}
## Code 💻
```cpp

unordered_map<int, map<int, int>> snaps;
int snap_id = 0;

SnapshotArray(int length) {
    for(int i = 0; i < length; i++) {
        map<int, int> mp;
        mp[0] = 0;
        snaps[i] = mp;
    }
}

void set(int index, int val) {
    snaps[index][snap_id] = val;
}

int snap() {
    snap_id++;
    return snap_id - 1;
}

int get(int index, int snid) {
    auto it = snaps[index].upper_bound(snid);
    it--;
    return it->second;
}
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
```

This solution uses a `SnapshotArray` class to implement a snapshot-based data structure where each element in the array can be updated, and the state can be snapshotted for future access. It uses an unordered map for efficient storage of snapshots.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	unordered_map<int, map<int, int>> snaps;
	```
	A map to store the snapshots, with the key being the index of the array and the value being another map storing the snapshot ids and their corresponding values.

2. **Variable Initialization**
	```cpp
	int snap_id = 0;
	```
	A counter to track the number of snapshots taken.

3. **Constructor**
	```cpp
	SnapshotArray(int length) {
	```
	Constructor definition to initialize a SnapshotArray object.

4. **Looping & Initialization**
	```cpp
	    for(int i = 0; i < length; i++) {
	```
	Loop through each index in the array to initialize the map for each.

5. **Map Initialization**
	```cpp
	        map<int, int> mp;
	```
	Initialize a map to store the snapshot values for the current index.

6. **Default Value**
	```cpp
	        mp[0] = 0;
	```
	Set the default snapshot value to 0 for the initial snapshot.

7. **Storing Snapshots**
	```cpp
	        snaps[i] = mp;
	```
	Store the initialized map of snapshots for the current index in the main snapshot map.

8. **Method Definition**
	```cpp
	void set(int index, int val) {
	```
	Define the `set` method, which allows setting the value at a specific index.

9. **Snapshot Storage**
	```cpp
	    snaps[index][snap_id] = val;
	```
	Store the value at the given index under the current snapshot id.

10. **Method Definition**
	```cpp
	int snap() {
	```
	Define the `snap` method, which increments the snapshot id and returns the previous one.

11. **Snap Id Increment**
	```cpp
	    snap_id++;
	```
	Increment the snapshot id counter.

12. **Return Snapshot Id**
	```cpp
	    return snap_id - 1;
	```
	Return the snapshot id before the increment.

13. **Method Definition**
	```cpp
	int get(int index, int snid) {
	```
	Define the `get` method, which returns the value for a given index at a specific snapshot.

14. **Finding Snapshot**
	```cpp
	    auto it = snaps[index].upper_bound(snid);
	```
	Find the snapshot at the given snapshot id using upper bound.

15. **Decrement Iterator**
	```cpp
	    it--;
	```
	Decrement the iterator to get the correct snapshot value.

16. **Return Value**
	```cpp
	    return it->second;
	```
	Return the value corresponding to the found snapshot.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) for snap and set operations.
- **Average Case:** O(log k) for get operations, where k is the number of snapshots.
- **Worst Case:** O(log k) for get operations, where k is the number of snapshots.

The time complexity is optimal due to the use of binary search on maps.

### Space Complexity 💾
- **Best Case:** O(n) where no snapshots are taken.
- **Worst Case:** O(n * k) where n is the number of array elements and k is the number of snapshots.

The space complexity depends on the number of elements in the array and the number of snapshots taken.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/snapshot-array/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
