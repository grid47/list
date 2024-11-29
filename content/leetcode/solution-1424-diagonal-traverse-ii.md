
+++
authors = ["grid47"]
title = "Leetcode 1424: Diagonal Traverse II"
date = "2024-06-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1424: Diagonal Traverse II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "k4YsQgeJBt0"
youtube_upload_date="2020-04-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/k4YsQgeJBt0/maxresdefault.webp"
comments = true
+++



---
You are given a 2D array `nums`, where each sub-array represents a row in the grid. Your task is to return all the elements of `nums` in diagonal order, starting from the top-left to bottom-right diagonals, where the sum of the row and column indices is constant.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 2D array `nums` where each sub-array represents a row in the grid.
- **Example:** `[[1, 2, 3], [4, 5, 6], [7, 8, 9]]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i].length <= 10^5
	- 1 <= sum(nums[i].length) <= 10^5
	- 1 <= nums[i][j] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a list of integers representing the elements of `nums` traversed in diagonal order.
- **Example:** `[1, 4, 2, 7, 5, 3, 8, 6, 9]`
- **Constraints:**
	- The output contains the elements of `nums` in the diagonal order.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to collect the elements of `nums` in diagonal order, where diagonals are formed by elements with the same sum of row and column indices.

- Step 1: Group the elements of `nums` by the sum of their row and column indices.
- Step 2: Traverse the diagonals in reverse order to maintain the required diagonal pattern.
- Step 3: Collect the elements in the desired order and return them.
{{< dots >}}
### Problem Assumptions ✅
- The input grid is non-empty, and each sub-array represents a valid row of elements.
{{< dots >}}
## Examples 🧩
- **Input:** `[[1, 2, 3], [4, 5, 6], [7, 8, 9]]`  \
  **Explanation:** The elements are collected diagonally starting from the top-left corner: 1, 4, 2, 7, 5, 3, 8, 6, 9.

- **Input:** `[[1, 2, 3, 4, 5], [6, 7], [8], [9, 10, 11], [12, 13, 14, 15, 16]]`  \
  **Explanation:** The elements are collected diagonally starting from the top-left: 1, 6, 2, 8, 7, 3, 9, 4, 12, 10, 5, 13, 11, 14, 15, 16.

{{< dots >}}
## Approach 🚀
The approach to solving this problem involves grouping the elements by their diagonal indices and then processing the diagonals from top-left to bottom-right.

### Initial Thoughts 💭
- Each diagonal consists of elements where the sum of their row and column indices is constant.
- To achieve the diagonal order, we can utilize a map to store the diagonals and process them accordingly.
- We can utilize a hashmap to group the diagonals and then traverse them in reverse order to achieve the desired output.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs since the length of the grid is at least 1.
- For large inputs, ensure that the solution handles up to the maximum allowed grid size efficiently.
- Ensure the solution handles cases where the grid has rows of varying lengths.
- The space complexity should be managed to handle up to the maximum allowed input size.
{{< dots >}}
## Code 💻
```cpp
vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    int m = nums.size(), n = nums[0].size(), mx = 0;
    unordered_map<int, vector<int>> mp;

    for(int i = 0; i < nums.size(); i++)
    for(int j = 0; j < nums[i].size(); j++) {
        mp[i + j].push_back(nums[i][j]);
        mx = max(mx, i + j);
    }

    vector<int> ans;
    for(int i = 0; i <= mx; i++) {
        for(auto x = mp[i].rbegin(); x != mp[i].rend(); x++)
        ans.push_back(*x);
    }
    return ans;
}
};

/*
Primary attempt can redirect to two pointer simulation
But right attempt is, queueing over a map which shares same diagonals
```

The `findDiagonalOrder` function takes a 2D vector `nums` as input and returns a vector containing the diagonal elements in a specific order. It maps the diagonal sums using a map, then retrieves the elements by reversing the order of elements for each diagonal to get the correct diagonal traversal.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
	```
	Defines the `findDiagonalOrder` function which takes a 2D vector of integers `nums` and returns a 1D vector of integers representing the diagonal order.

2. **Variable Initialization**
	```cpp
	    int m = nums.size(), n = nums[0].size(), mx = 0;
	```
	Initializes variables `m` (number of rows), `n` (number of columns), and `mx` (to track the maximum diagonal index) for further processing.

3. **Data Structure Initialization**
	```cpp
	    unordered_map<int, vector<int>> mp;
	```
	Declares an unordered map `mp` where each key corresponds to a diagonal index and the value is a vector of integers that stores the diagonal elements.

4. **Loop Constructs**
	```cpp
	    for(int i = 0; i < nums.size(); i++)
	```
	Begins a loop that iterates over the rows of the `nums` vector.

5. **Loop Constructs**
	```cpp
	    for(int j = 0; j < nums[i].size(); j++) {
	```
	Nested loop that iterates over the columns of the current row `i` of `nums`.

6. **Map Operations**
	```cpp
	        mp[i + j].push_back(nums[i][j]);
	```
	Inserts the current element `nums[i][j]` into the map `mp` under the key `i + j`, which represents the diagonal index.

7. **Variable Update**
	```cpp
	        mx = max(mx, i + j);
	```
	Updates the `mx` variable to track the maximum diagonal index encountered so far.

8. **Vector Initialization**
	```cpp
	    vector<int> ans;
	```
	Declares a vector `ans` that will hold the final result of the diagonal traversal.

9. **Loop Constructs**
	```cpp
	    for(int i = 0; i <= mx; i++) {
	```
	Begins a loop that iterates over each diagonal index from `0` to `mx`.

10. **Loop Constructs**
	```cpp
	        for(auto x = mp[i].rbegin(); x != mp[i].rend(); x++)
	```
	Iterates over the elements of each diagonal in reverse order using a reverse iterator (`rbegin` to `rend`).

11. **Vector Operations**
	```cpp
	        ans.push_back(*x);
	```
	Adds each element `*x` from the current diagonal to the `ans` vector.

12. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the `ans` vector, which contains the elements of the matrix in diagonal order.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the total number of elements in the grid.
- **Average Case:** O(n), as we process each element once and traverse the diagonals.
- **Worst Case:** O(n), as we process each element and diagonal once.

The time complexity is linear in relation to the number of elements in the grid.

### Space Complexity 💾
- **Best Case:** O(n), since we store the elements in the hashmap based on their diagonal indices.
- **Worst Case:** O(n), where n is the total number of elements in the grid.

The space complexity is linear, as we store the elements based on their diagonals.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/diagonal-traverse-ii/description/)

---
{{< youtube k4YsQgeJBt0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
