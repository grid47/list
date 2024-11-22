
+++
authors = ["grid47"]
title = "Leetcode 2349: Design a Number Container System"
date = "2024-03-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2349: Design a Number Container System in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Design","Heap (Priority Queue)","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "mzU9eVB62hA"
youtube_upload_date="2022-07-23"
youtube_thumbnail="https://i.ytimg.com/vi_webp/mzU9eVB62hA/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class NumberContainers {
    map<int, set<int>> mp;
    map<int, int> in;
public:
    NumberContainers() {
        
    }
    
    void change(int idx, int num) {
        if(in.count(idx)) {
            
            int x = in[idx];
            mp[x].erase(idx);


        } 
        in[idx] = num;
        mp[num].insert(idx);
         
    }
    
    int find(int num) {
        if(mp.count(num) && !mp[num].empty()) {
            return *begin(mp[num]);
        } return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
{{< /highlight >}}
---

### Problem Statement

The problem involves implementing a container system that supports two main operations:
1. **Change Operation**: Change the number stored at a given index.
2. **Find Operation**: Find the smallest index that stores a specific number.

We need to design a data structure that allows these operations to be performed efficiently. Each container holds a number at an index, and we are tasked with supporting the following operations:
- **change(int idx, int num)**: This operation changes the number at index `idx` to `num`. If a number already exists at `idx`, the previous number should be removed.
- **find(int num)**: This operation finds the smallest index that stores the number `num`. If there is no index storing `num`, it should return `-1`.

### Approach

To solve this problem efficiently, we can use a combination of two data structures:
1. **Map of Sets (`mp`)**: This will map each number to a set of indices where that number is stored. The use of a set ensures that we have efficient lookups, insertions, and deletions of indices.
2. **Map of Integers (`in`)**: This will store the current number at each index. This ensures we know which number is currently stored at each index for performing the `change` operation.

The idea is that:
- For the `change(idx, num)` operation, we first check if the number at the given index has changed. If it has, we remove the old number from the set and insert the new number at that index.
- For the `find(num)` operation, we can directly access the set of indices associated with the number `num` and return the smallest index.

### Code Breakdown (Step by Step)

#### 1. **Data Structure Initialization**
```cpp
map<int, set<int>> mp;
map<int, int> in;
```
- `mp`: This map associates each number with a set of indices that store that number. This ensures that for any given number, we can quickly access the indices where that number is stored. A set is used because we are interested in the smallest index, and sets are naturally ordered.
- `in`: This map stores the number at each index. It allows us to easily find the current number at a specific index, which is necessary for the `change` operation.

#### 2. **Constructor**
```cpp
NumberContainers() {
}
```
- The constructor is empty because there is no specific initialization needed apart from initializing the maps `mp` and `in`, which happens automatically.

#### 3. **Change Operation**
```cpp
void change(int idx, int num) {
    if(in.count(idx)) {
        int x = in[idx];
        mp[x].erase(idx);
    } 
    in[idx] = num;
    mp[num].insert(idx);
}
```
- **Step 1**: We first check if the index `idx` already has a number stored in it by using `in.count(idx)`. If it does, we remove the index from the set of indices associated with the old number (`x`), which is stored in `in[idx]`. This ensures that we are removing the old number from the set before updating.
- **Step 2**: We then update the number at index `idx` in the `in` map to the new number `num`.
- **Step 3**: After updating the number at index `idx`, we insert the index `idx` into the set corresponding to the new number in `mp[num]`. This ensures that the new number is associated with the correct index.

#### 4. **Find Operation**
```cpp
int find(int num) {
    if(mp.count(num) && !mp[num].empty()) {
        return *begin(mp[num]);
    } 
    return -1;
}
```
- **Step 1**: We first check if the number `num` exists in the map `mp` and whether the associated set is non-empty. This ensures that there is at least one index storing the number `num`.
- **Step 2**: If the set for `num` is non-empty, we return the smallest index in the set by using `*begin(mp[num])`. This takes advantage of the fact that sets are ordered, and `begin()` gives us the smallest element.
- **Step 3**: If the number `num` is not found in the map `mp` or if the set is empty, we return `-1` to indicate that no index stores that number.

### Complexity

#### Time Complexity:
- **Change Operation (`change(idx, num)`)**:  
  - Inserting and erasing elements in a set takes `O(log N)` time, where `N` is the number of elements in the set.
  - The `in[idx] = num` operation is a simple `O(1)` operation.
  - Overall, the time complexity for `change` is `O(log N)` where `N` is the number of indices associated with a number.
  
- **Find Operation (`find(num)`)**:  
  - Finding an element in the map `mp` takes `O(log M)` where `M` is the number of unique numbers in `mp`.  
  - Accessing the smallest element in the set takes `O(1)` time due to the ordering property of sets.
  - The overall time complexity for `find` is `O(log M)`, where `M` is the number of unique numbers in the container.

#### Space Complexity:
- **O(N + M)**:  
  - `N` is the number of indices (which can be as large as the number of elements in `in`), and `M` is the number of unique numbers (which can be as large as the number of unique numbers in `mp`).  
  - The `in` map stores `N` elements, and the `mp` map stores up to `M` sets. Hence, the space complexity is `O(N + M)`.

### Conclusion

This solution efficiently handles the `change` and `find` operations using a combination of maps and sets. The `change` operation ensures that the number at each index is updated properly, while the `find` operation quickly finds the smallest index storing a specific number. The use of maps and sets allows these operations to be performed efficiently, even for large inputs.

The time complexity of both operations is logarithmic in terms of the number of elements, ensuring that the solution can handle a wide range of inputs efficiently. This approach is highly optimized for scenarios where frequent updates and queries are required, making it suitable for real-time systems or interactive applications where performance is critical.

[`Link to LeetCode Lab`](https://leetcode.com/problems/design-a-number-container-system/description/)

---
{{< youtube mzU9eVB62hA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
