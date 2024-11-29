
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
comments = true
+++



---
Design a number container system that allows inserting or replacing a number at a specific index and finding the smallest index for a given number.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of multiple operations: `change(index, number)` for inserting/replacing a number at a given index, and `find(number)` to find the smallest index containing a particular number.
- **Example:** `Input: ["NumberContainers", "find", "change", "change", "change", "change", "find", "change", "find"]
Input: [[], [10], [2, 10], [1, 10], [3, 10], [5, 10], [10], [1, 20], [10]]`
- **Constraints:**
	- 1 <= index, number <= 10^9
	- At most 10^5 operations in total.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output consists of an array of results corresponding to each operation. For `find(number)`, return the smallest index filled with the given number, or -1 if not found.
- **Example:** `[null, -1, null, null, null, null, 1, null, 2]`
- **Constraints:**
	- The result of `find(number)` will be an integer, either the smallest index or -1 if the number is not found.

{{< dots >}}
### Core Logic 🔍
**Goal:** To track the numbers at specific indices and efficiently find the smallest index for a given number.

- Store the numbers in a map with index as the key.
- Use another map to store sets of indices for each number.
- On inserting or replacing a number at an index, update the map of indices.
- To find the smallest index for a number, return the smallest index from the set of indices for that number.
{{< dots >}}
### Problem Assumptions ✅
- The container system should handle insertions, replacements, and searches efficiently.
- The system should handle large index values (up to 10^9).
{{< dots >}}
## Examples 🧩
- **Input:** `["NumberContainers", "find", "change", "change", "change", "change", "find", "change", "find"]`  \
  **Explanation:** This example shows how the container system works step-by-step, with operations being executed in sequence. Initially, `find(10)` returns -1 because no indices are filled with 10. As we fill the containers at different indices, `find(10)` returns the smallest index where 10 is found.

{{< dots >}}
## Approach 🚀
Use a map to store the number at each index and another map to track the indices for each number.

### Initial Thoughts 💭
- Efficiently storing and retrieving numbers by index and tracking the smallest index for a given number is key.
- We need two maps: one for tracking the numbers at indices, and one for tracking the indices for each number.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs, as every operation requires either an index or a number.
- Ensure that the system can handle up to 10^5 operations efficiently.
- If a number is replaced at an index, the previous number at that index should be removed from the tracking map.
- The approach should ensure efficient time complexity and avoid excessive memory use.
{{< dots >}}
## Code 💻
```cpp
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
```

This class, `NumberContainers`, uses a map to store the index of a number and another map to store indices for each number. It provides two functions: `change()` to update the number at a given index, and `find()` to find the smallest index where a given number exists.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	map<int, int> in;
	```
	Declares a map `in` that associates an index with a number.

2. **Access Modifier**
	```cpp
	public:
	```
	Defines the public access modifier for the class members and methods.

3. **Constructor**
	```cpp
	NumberContainers() {
	```
	The constructor of the `NumberContainers` class. It initializes the internal data structures.

4. **Function Definition**
	```cpp
	void change(int idx, int num) {
	```
	Defines the `change()` function that updates the number at a given index.

5. **Condition Check**
	```cpp
	    if(in.count(idx)) {
	```
	Checks if the index `idx` already exists in the map `in`.

6. **Index Fetch**
	```cpp
	        int x = in[idx];
	```
	Fetches the current number `x` stored at index `idx` from the map `in`.

7. **Remove Index from Previous Map**
	```cpp
	        mp[x].erase(idx);
	```
	Removes the index `idx` from the map `mp` corresponding to the number `x`.

8. **Update Index**
	```cpp
	    in[idx] = num;
	```
	Updates the map `in` to associate the index `idx` with the new number `num`.

9. **Insert into Map**
	```cpp
	    mp[num].insert(idx);
	```
	Inserts the index `idx` into the map `mp` under the corresponding number `num`.

10. **Function Definition**
	```cpp
	int find(int num) {
	```
	Defines the `find()` function to return the smallest index where a given number exists.

11. **Condition Check**
	```cpp
	    if(mp.count(num) && !mp[num].empty()) {
	```
	Checks if the map `mp` contains the number `num` and if the list of indices for that number is not empty.

12. **Return Smallest Index**
	```cpp
	        return *begin(mp[num]);
	```
	Returns the smallest index for the given number `num` by accessing the first element in the set of indices.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(log n)

For most operations, the time complexity is constant. However, finding the smallest index involves searching through a set of indices, which takes logarithmic time.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity depends on the number of distinct indices and numbers, but it remains efficient due to the use of maps and sets.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/design-a-number-container-system/description/)

---
{{< youtube mzU9eVB62hA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
