
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
+++



---
**Code:**

{{< highlight cpp >}}
class SnapshotArray {
public:

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
 */
{{< /highlight >}}
---


### Problem Statement
The "Snapshot Array" problem involves creating a data structure that allows you to efficiently store and retrieve snapshots of an array at various points in time. This data structure should support the following operations:
1. **set(index, val)**: Sets the value of an element at a given index in the array.
2. **snap()**: Takes a snapshot of the array and returns a unique `snap_id`.
3. **get(index, snap_id)**: Retrieves the value of the element at the specified index from the snapshot with the given `snap_id`.

The objective is to create a data structure that can handle multiple snapshots efficiently without the need to store each version of the entire array.

### Approach
This implementation of `SnapshotArray` uses a hash map combined with a nested ordered map to efficiently handle the snapshots:
1. **Outer Hash Map** (`unordered_map<int, map<int, int>> snaps`): Maps each index in the array to a time-sorted map (`map<int, int>`), which stores the values of that index across different snapshots.
2. **Inner Ordered Map** (`map<int, int>`): Stores the snapshot IDs as keys and the corresponding values at that index as values. Using an ordered map ensures that we can efficiently find the most recent snapshot value for a given `snap_id`.

The structure of this data structure allows for fast retrieval of values for specific snapshots without duplicating the entire array at each snapshot. Each index only stores the updates it has received, making the approach both memory- and time-efficient.

### Code Breakdown (Step by Step)

Here’s a step-by-step breakdown of the code:

```cpp
class SnapshotArray {
public:
    unordered_map<int, map<int, int>> snaps;
    int snap_id = 0;
```
- **Lines 1-4**: The `SnapshotArray` class is defined. The variable `snaps` is an `unordered_map` where each key represents an index in the array, and the value is an ordered `map` that tracks snapshot IDs and values for that index. `snap_id` keeps track of the current snapshot ID, starting at 0.

```cpp
    SnapshotArray(int length) {
        for(int i = 0; i < length; i++) {
            map<int, int> mp;
            mp[0] = 0;
            snaps[i] = mp;
        }
    }
```
- **Lines 5-10**: The constructor initializes the array. For each index, an ordered map is created with an initial snapshot ID of `0` and a value of `0`. This ensures that every index starts with a default value of `0` in snapshot `0`.

```cpp
    void set(int index, int val) {
        snaps[index][snap_id] = val;
    }
```
- **Lines 11-13**: The `set` method updates the value at a specified `index` in the array. It assigns the value `val` for the current `snap_id`, indicating that `index` should have this value in the current snapshot.

```cpp
    int snap() {
        snap_id++;
        return snap_id - 1;
    }
```
- **Lines 14-17**: The `snap` method increments the `snap_id` to create a new snapshot, then returns the previous `snap_id` as the ID of the snapshot that was just taken.

```cpp
    int get(int index, int snid) {
        auto it = snaps[index].upper_bound(snid);
        it--;
        return it->second;
    }
};
```
- **Lines 18-22**: The `get` method retrieves the value at `index` for a specified `snap_id` (`snid`). Using `upper_bound`, it locates the smallest snapshot ID greater than `snid`. The iterator is decremented (`it--`) to access the snapshot at or before `snid`. The retrieved value, `it->second`, represents the value at `index` for `snid`.

### Complexity
- **Time Complexity**:
  - **set**: \( O(\log S) \), where \( S \) is the number of snapshots taken for a specific index, because of insertion into an ordered map.
  - **snap**: \( O(1) \), since it only increments the snapshot ID.
  - **get**: \( O(\log S) \), where \( S \) is the number of snapshots at the given index. The `upper_bound` operation takes \( O(\log S) \).

- **Space Complexity**: \( O(n + k) \), where \( n \) is the number of indices and \( k \) is the total number of updates across snapshots. This space complexity accounts for the storage of only modified values for each index.

### Conclusion
This C++ implementation of the `SnapshotArray` class offers an efficient way to store and retrieve array states across snapshots. By using a hash map of ordered maps, the solution ensures fast retrieval for specific snapshots without duplicating the array at each snapshot. The design is optimal for scenarios requiring frequent snapshots and updates to individual elements, making it a powerful solution for managing time-versioned data in applications like undo functionality, version control, or real-time state tracking.


[`Link to LeetCode Lab`](https://leetcode.com/problems/snapshot-array/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
