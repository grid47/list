
+++
authors = ["grid47"]
title = "Leetcode 2295: Replace Elements in an Array"
date = "2024-03-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2295: Replace Elements in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "xiY9ORyGnDk"
youtube_upload_date="2022-06-05"
youtube_thumbnail="https://i.ytimg.com/vi_webp/xiY9ORyGnDk/maxresdefault.webp"
comments = true
+++



---
You are given a list of distinct positive integers, `nums`, and a list of operations. Each operation consists of two elements: `operations[i][0]` and `operations[i][1]`. In each operation, you need to replace the element `operations[i][0]` in `nums` with the new value `operations[i][1]`. The number `operations[i][1]` is guaranteed to not already be in `nums`. After performing all the operations, return the final array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a list `nums` consisting of distinct integers and a list `operations` with each operation consisting of two integers `operations[i][0]` and `operations[i][1]`.
- **Example:** `Input: nums = [10, 20, 30, 40], operations = [[10, 50], [30, 60], [40, 70]]`
- **Constraints:**
	- 1 <= n, m <= 10^5
	- 1 <= nums[i], operations[i][0], operations[i][1] <= 10^6
	- All elements in nums are distinct.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the modified `nums` after applying all the operations in order.
- **Example:** `Output: [50, 20, 60, 70]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to replace elements in the list `nums` based on the given operations, while ensuring no duplication occurs during the replacement process.

- Step 1: Create a mapping of each number in `nums` to its index.
- Step 2: For each operation, find the index of the element to replace and update it with the new value.
- Step 3: After all operations are performed, return the final array.
{{< dots >}}
### Problem Assumptions ✅
- The input list `nums` contains distinct integers.
- Each operation replaces an element that exists in `nums` with a new number that does not exist in the list.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1, 2, 3], operations = [[1, 4], [2, 5], [3, 6]]`  \
  **Explanation:** After the first operation, the list becomes [4, 2, 3]. After the second operation, it becomes [4, 5, 3], and finally, after the third operation, the list becomes [4, 5, 6].

- **Input:** `Input: nums = [100, 200, 300], operations = [[100, 500], [200, 600], [300, 700]]`  \
  **Explanation:** The operations replace 100 with 500, 200 with 600, and 300 with 700, resulting in the final array [500, 600, 700].

{{< dots >}}
## Approach 🚀
We will approach this problem by maintaining a map that tracks the index of each number in `nums` to efficiently replace values during the operations.

### Initial Thoughts 💭
- The replacement operation involves direct lookup and update, so using a map can provide O(1) access time for each replacement.
- The algorithm will perform each operation in constant time, making the overall complexity O(m), where m is the number of operations.
{{< dots >}}
### Edge Cases 🌐
- The input will never be empty as the number of elements in `nums` and the number of operations are both guaranteed to be at least 1.
- For very large inputs (up to 10^5 elements and operations), the solution should ensure that operations are performed efficiently, ideally in O(1) for each operation.
- The constraints guarantee that no element will be replaced by an already existing element in `nums`.
- The size of `nums` and the number of operations will not exceed 10^5, ensuring the approach remains efficient.
{{< dots >}}
## Code 💻
```cpp
vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& ops) {
    
    map<int, int> mp;
    
    int n = nums.size();
    for(int i = 0; i < n; i++)
        mp[nums[i]] = i;
    
    for(auto it: ops) {
        int idx = mp[it[0]];
        mp.erase(it[0]);
        nums[idx] = it[1];
        mp[it[1]] = idx;
    }
    return nums;
}
```

The function `arrayChange` modifies a given vector `nums` by applying a series of operations in `ops`, where each operation replaces an element in `nums` with a new value. A map is used to efficiently track the indices of the elements for quick updates.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& ops) {
	```
	The function `arrayChange` is declared, which takes a reference to a vector of integers `nums` and a reference to a 2D vector `ops` that contains operations to be applied to `nums`. It returns a modified vector of integers.

2. **Map Declaration**
	```cpp
	    map<int, int> mp;
	```
	A map `mp` is declared to store the value of elements from `nums` as keys and their corresponding indices as values. This helps in quick look-up and modification of elements during operations.

3. **Get Array Size**
	```cpp
	    int n = nums.size();
	```
	The size of the input vector `nums` is calculated and stored in the variable `n`.

4. **Loop Through Array**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	A for-loop is initiated to iterate through each element in the `nums` array.

5. **Map Population**
	```cpp
	        mp[nums[i]] = i;
	```
	The map `mp` is populated with each element of `nums` as the key and its index as the value.

6. **Loop Through Operations**
	```cpp
	    for(auto it: ops) {
	```
	A for-loop is initiated to iterate through each operation in the `ops` array, where each operation consists of two values: the old value and the new value.

7. **Find Index of Old Value**
	```cpp
	        int idx = mp[it[0]];
	```
	The index of the element to be replaced (old value) is retrieved from the map `mp` using `it[0]`, the old value in the operation.

8. **Erase Old Value from Map**
	```cpp
	        mp.erase(it[0]);
	```
	The old value is erased from the map `mp` as it is no longer needed.

9. **Update Element in Array**
	```cpp
	        nums[idx] = it[1];
	```
	The element at the found index `idx` in the array `nums` is replaced with the new value `it[1]` from the operation.

10. **Update Map with New Value**
	```cpp
	        mp[it[1]] = idx;
	```
	The map `mp` is updated to associate the new value `it[1]` with the index `idx`.

11. **Return Modified Array**
	```cpp
	    return nums;
	```
	After applying all operations, the modified array `nums` is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m)
- **Average Case:** O(m)
- **Worst Case:** O(m)

The time complexity is O(m) where m is the number of operations, since each operation involves a constant-time map lookup and update.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n), where n is the number of elements in `nums`, due to the map storing the indices of all elements.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/replace-elements-in-an-array/description/)

---
{{< youtube xiY9ORyGnDk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
