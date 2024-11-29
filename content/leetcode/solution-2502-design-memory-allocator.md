
+++
authors = ["grid47"]
title = "Leetcode 2502: Design Memory Allocator"
date = "2024-03-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2502: Design Memory Allocator in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Design","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ARhX-jazvSY"
youtube_upload_date="2022-12-11"
youtube_thumbnail="https://i.ytimg.com/vi_webp/ARhX-jazvSY/maxresdefault.webp"
comments = true
+++



---
Design a memory allocator class with functions to allocate and free blocks of memory. The allocator should efficiently handle consecutive memory requests and be able to free blocks based on their identifiers.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a series of operations that initialize the allocator and perform memory allocations and deallocations. The first operation initializes the allocator with a specified size. Each subsequent operation is either an allocate or free operation.
- **Example:** `["Allocator", "allocate", "allocate", "allocate", "free", "allocate", "allocate", "allocate", "free", "allocate", "free"]`
- **Constraints:**
	- 1 <= n, size, mID <= 1000
	- At most 1000 calls will be made to allocate and free.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should contain the results of the allocate and free operations. For allocate, return the starting index of the allocated block or -1 if no space is available. For free, return the number of units freed.
- **Example:** `[null, 0, 1, 2, 1, 3, 1, 6, 3, -1, 0]`
- **Constraints:**
	- Output should match the expected values as described in the examples.

{{< dots >}}
### Core Logic 🔍
**Goal:** To allocate memory blocks of a specified size and to free them efficiently based on the given mID.

- Initialize a memory array of size n with all elements set to 0 (free).
- For each allocate request, find the first consecutive free memory block of the requested size and mark those blocks as allocated.
- For each free request, free all memory blocks that were allocated with the specified mID.
{{< dots >}}
### Problem Assumptions ✅
- The allocator should be able to handle both large and small allocation requests efficiently.
- Freeing an mID will only free the blocks allocated with that specific mID.
{{< dots >}}
## Examples 🧩
- **Input:** `["Allocator", "allocate", "allocate", "allocate", "free", "allocate", "allocate", "allocate", "free", "allocate", "free"]`  \
  **Explanation:** In this example, we start with an allocator of size 10, perform allocations of size 1 for mIDs 1, 2, and 3, and free some of the memory as specified. We observe the allocation and freeing processes, and track the memory usage and results for each operation.

{{< dots >}}
## Approach 🚀
The solution uses an array to represent the memory and a map to track memory allocations by mID. For allocation, we find the first free block of the required size. For deallocation, we use the map to free all blocks associated with the given mID.

### Initial Thoughts 💭
- Efficient searching for free memory blocks is crucial.
- Memory allocation should be quick, but freeing memory may require scanning the entire array.
- We can implement this using a greedy approach to find the first available block for each allocation.
{{< dots >}}
### Edge Cases 🌐
- What if no allocation requests are made?
- Ensure that the allocator can handle up to 1000 operations efficiently.
- Handle cases where an allocation size exceeds the available free memory.
- The allocator should not perform inefficient operations even when the memory is full or almost full.
{{< dots >}}
## Code 💻
```cpp
vector<int> mem;
map<int, vector<vector<int>>> mp;
Allocator(int n) {
    mem.resize(n, 0);
    
}

int allocate(int size, int mID) {
    int idx = 0;
    int cnt = 0;
    while(idx < mem.size()) {
        int j = idx;
        while(j < mem.size() && mem[j] == 0 && cnt < size) {
            cnt++;
            j++;
        }
        if(cnt == size) {
            for(int i = idx; i < idx + size; i++)
                mem[i] = 1;
            mp[mID].push_back({idx, size});
            return idx;
        }
        while(j < mem.size() && mem[j] == 1) j++;
        cnt = 0;
        idx = j;
    }
    return -1;
}

int free(int mID) {
    int cnt = 0;
    for(int i = 0; i < mp[mID].size(); i++) {
        auto it = mp[mID][i];
        for(int j = it[0]; j < it[0] + it[1]; j++) {
            mem[j] = 0;                
            cnt++;
        }
    }
    mp.erase(mID);
    return cnt;
}
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
```

This is the implementation of a memory allocator system, where memory blocks are allocated and freed based on the given size and memory ID. The allocator uses an array `mem` to track allocated and free spaces, and a map `mp` to store the allocation details for each memory ID.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	vector<int> mem;
	```
	Initializes a vector `mem` to track the memory allocation status. Each element represents a memory block, where 0 indicates a free block and 1 indicates an allocated block.

2. **Variable Initialization**
	```cpp
	map<int, vector<vector<int>>> mp;
	```
	Declares a map `mp` to store the memory allocation details for each memory ID. The key is the memory ID, and the value is a list of pairs representing the starting index and size of each allocated block.

3. **Constructor**
	```cpp
	Allocator(int n) {
	```
	Constructor that initializes the memory allocator with `n` blocks, where each block is initially set to 0 (free).

4. **Memory Initialization**
	```cpp
	    mem.resize(n, 0);
	```
	Resizes the `mem` vector to `n` blocks, initializing all blocks to 0 (free).

5. **Function Definition**
	```cpp
	int allocate(int size, int mID) {
	```
	Defines the `allocate` function, which attempts to allocate a block of memory of the given `size` to the memory ID `mID`.

6. **Variable Initialization**
	```cpp
	    int idx = 0;
	```
	Initializes the index `idx` to 0, which will be used to track the current position in the memory vector.

7. **Variable Initialization**
	```cpp
	    int cnt = 0;
	```
	Initializes the counter `cnt` to 0, which will be used to track the number of consecutive free blocks found.

8. **Loop Structure**
	```cpp
	    while(idx < mem.size()) {
	```
	Begins a while loop that iterates through the `mem` vector to find available memory blocks for allocation.

9. **Variable Initialization**
	```cpp
	        int j = idx;
	```
	Initializes the variable `j` to the current index `idx`, which will be used to check consecutive free blocks.

10. **Loop Structure**
	```cpp
	        while(j < mem.size() && mem[j] == 0 && cnt < size) {
	```
	Inner loop that checks for consecutive free blocks starting from the index `idx`. It increments the counter `cnt` as long as free blocks are found.

11. **Variable Update**
	```cpp
	            cnt++;
	```
	Increments the counter `cnt` as a free block is found.

12. **Variable Update**
	```cpp
	            j++;
	```
	Increments `j` to check the next memory block.

13. **Conditional Check**
	```cpp
	        if(cnt == size) {
	```
	Checks if the required number of consecutive free blocks (`size`) has been found.

14. **Memory Allocation**
	```cpp
	            for(int i = idx; i < idx + size; i++)
	```
	Iterates over the `mem` vector from index `idx` to allocate memory for the given `size`.

15. **Memory Allocation**
	```cpp
	                mem[i] = 1;
	```
	Marks the blocks as allocated by setting them to 1 in the `mem` vector.

16. **Data Structure Manipulation**
	```cpp
	            mp[mID].push_back({idx, size});
	```
	Records the memory allocation details in the `mp` map for the given memory ID `mID`.

17. **Return Statement**
	```cpp
	            return idx;
	```
	Returns the starting index `idx` of the allocated memory block.

18. **Loop Structure**
	```cpp
	        while(j < mem.size() && mem[j] == 1) j++;
	```
	Moves the index `j` to the next available free block by skipping over allocated blocks.

19. **Variable Update**
	```cpp
	        cnt = 0;
	```
	Resets the counter `cnt` to 0 as the loop moves to the next potential free block sequence.

20. **Variable Update**
	```cpp
	        idx = j;
	```
	Updates `idx` to `j` to continue searching from the next free block.

21. **Return Statement**
	```cpp
	    return -1;
	```
	Returns -1 if no suitable block of free memory is found.

22. **Function Definition**
	```cpp
	int free(int mID) {
	```
	Defines the `free` function, which frees the memory blocks previously allocated for the given memory ID `mID`.

23. **Variable Initialization**
	```cpp
	    int cnt = 0;
	```
	Initializes a counter `cnt` to 0, which will be used to track the number of freed blocks.

24. **Loop Structure**
	```cpp
	    for(int i = 0; i < mp[mID].size(); i++) {
	```
	Iterates over the list of allocated blocks for the given memory ID `mID`.

25. **Variable Initialization**
	```cpp
	        auto it = mp[mID][i];
	```
	Gets the allocation details (starting index and size) for the current block.

26. **Loop Structure**
	```cpp
	        for(int j = it[0]; j < it[0] + it[1]; j++) {
	```
	Frees the memory blocks by iterating over the range of indices allocated to the current memory ID.

27. **Memory Deallocation**
	```cpp
	            mem[j] = 0;
	```
	Sets the memory block to 0 (free).

28. **Variable Update**
	```cpp
	            cnt++;
	```
	Increments the counter `cnt` for each freed block.

29. **Memory Deallocation**
	```cpp
	    mp.erase(mID);
	```
	Removes the entry for the given memory ID `mID` from the map `mp`.

30. **Return Statement**
	```cpp
	    return cnt;
	```
	Returns the total number of freed blocks.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) for a quick allocation or deallocation.
- **Average Case:** O(n) for finding a free block and deallocating memory.
- **Worst Case:** O(n) for allocating or freeing memory in the worst case.

The worst-case time complexity occurs when searching for memory blocks or freeing large blocks of memory.

### Space Complexity 💾
- **Best Case:** O(n) for storing the memory array and tracking allocations by mID.
- **Worst Case:** O(n) for storing the memory array and tracking allocations by mID.

Space complexity is linear in terms of the number of memory units, as we store the memory array and allocation information.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/design-memory-allocator/description/)

---
{{< youtube ARhX-jazvSY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
