
+++
authors = ["grid47"]
title = "Leetcode 2768: Number of Black Blocks"
date = "2024-02-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2768: Number of Black Blocks in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "qnbzbMmLK8Q"
youtube_upload_date="2023-07-08"
youtube_thumbnail="https://i.ytimg.com/vi/qnbzbMmLK8Q/maxresdefault.jpg"
comments = true
+++



---
Given an m x n grid with some black cells specified by a coordinates list, determine how many 2x2 blocks contain exactly 0, 1, 2, 3, or 4 black cells.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of integers m, n, and a 2D integer array coordinates.
- **Example:** `Input: m = 4, n = 4, coordinates = [[1, 1]]`
- **Constraints:**
	- 2 <= m, n <= 10^5
	- 0 <= coordinates.length <= 10^4
	- 0 <= coordinates[i][0] < m
	- 0 <= coordinates[i][1] < n
	- Each coordinate pair is distinct.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of size 5 where the i-th entry is the number of blocks containing exactly i black cells.
- **Example:** `Output: [9, 3, 0, 0, 0] for m = 4, n = 4, coordinates = [[1, 1]].`
- **Constraints:**
	- Output should be a list of integers of size 5.

{{< dots >}}
### Core Logic 🔍
**Goal:** To efficiently count the number of blocks containing exactly i black cells for i = 0 to 4.

- Use a hash map to count how many black cells each block contains.
- Iterate through each black cell and update the counts for all blocks it contributes to.
- Aggregate the counts to produce the final output array.
{{< dots >}}
### Problem Assumptions ✅
- Coordinates are pairwise distinct.
- Blocks outside the bounds of the grid do not exist.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: m = 4, n = 4, coordinates = [[1, 1]]`  \
  **Explanation:** There are 9 blocks with 0 black cells and 3 blocks with 1 black cell. Blocks with >1 black cell do not exist.

- **Input:** `Input: m = 3, n = 3, coordinates = [[0, 0], [1, 1], [0, 2]]`  \
  **Explanation:** 2 blocks have 1 black cell, 2 blocks have 2 black cells, and no blocks have 0, 3, or 4 black cells.

{{< dots >}}
## Approach 🚀
The approach involves iterating through black cell coordinates and updating a hash map to track black cell counts for each block.

### Initial Thoughts 💭
- Each black cell contributes to at most 4 blocks.
- The problem can be solved efficiently using a hash map.
- Focus on sparse updates to minimize computational overhead.
{{< dots >}}
### Edge Cases 🌐
- No black cells (coordinates = []).
- Grids with maximum size (m, n = 10^5) and sparse black cells.
- Black cells at the edges or corners of the grid.
- Ensure memory usage is efficient for large grid dimensions.
{{< dots >}}
## Code 💻
```cpp
vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
    unordered_map<long long, int> cnt;
    vector<long long> res = {(n - 1L) * (m - 1), 0, 0, 0, 0};
    for (auto& c: coordinates)
        for (int i = c[0]; i < c[0] + 2; ++i)
            for (int j = c[1]; j < c[1] + 2; ++j)
                if (0 < i && i < m && 0 < j && j < n) {
                    res[cnt[i * 100000L + j]]--;
                    cnt[i * 100000L + j]++;
                    res[cnt[i * 100000L + j]]++;
                }
    return res;
}
```

This function calculates how many 2x2 black blocks are formed by a set of given coordinates, returning the result as a vector of counts of black blocks.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
	```
	Defines the function `countBlackBlocks`, which takes the dimensions of the grid (`m` and `n`) and a list of coordinates representing the positions of black blocks. It returns a vector containing the counts of how many 2x2 blocks are formed.

2. **Initialize Map**
	```cpp
	    unordered_map<long long, int> cnt;
	```
	Initializes an unordered map `cnt` that will store the frequency of occurrences of each 2x2 block (using a unique key formed by the coordinates).

3. **Initialize Result Vector**
	```cpp
	    vector<long long> res = {(n - 1L) * (m - 1), 0, 0, 0, 0};
	```
	Initializes the result vector `res` with five elements, where the first element stores the total number of possible 2x2 blocks (calculated by `(n-1) * (m-1)`). The other four elements are set to 0 and will be used for the counts of blocks with 0, 1, 2, and 3 black cells.

4. **Iterate Over Coordinates**
	```cpp
	    for (auto& c: coordinates)
	```
	Starts a loop to iterate over each coordinate in the input `coordinates` array.

5. **Iterate Over Rows**
	```cpp
	        for (int i = c[0]; i < c[0] + 2; ++i)
	```
	Starts an inner loop to iterate over the two rows of the 2x2 block, starting from the current coordinate `c[0]`.

6. **Iterate Over Columns**
	```cpp
	            for (int j = c[1]; j < c[1] + 2; ++j)
	```
	Starts another inner loop to iterate over the two columns of the 2x2 block, starting from the current coordinate `c[1]`.

7. **Check Boundary Conditions**
	```cpp
	                if (0 < i && i < m && 0 < j && j < n) {
	```
	Checks if the current cell (`i, j`) is within the bounds of the grid (i.e., 1 <= i < m and 1 <= j < n).

8. **Update Result Vector**
	```cpp
	                    res[cnt[i * 100000L + j]]--;
	```
	Decreases the count of the current 2x2 block configuration stored in the result vector `res`. The key `i * 100000L + j` represents the unique index for the current cell.

9. **Update Map**
	```cpp
	                    cnt[i * 100000L + j]++;
	```
	Increments the count of the current 2x2 block in the `cnt` map for the corresponding cell.

10. **Update Result Vector Again**
	```cpp
	                    res[cnt[i * 100000L + j]]++;
	```
	Increments the count of the updated 2x2 block configuration in the result vector `res`.

11. **Return Result**
	```cpp
	    return res;
	```
	Returns the result vector `res`, which contains the counts of black blocks formed by the given coordinates.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(k)
- **Average Case:** O(k)
- **Worst Case:** O(k)

k = number of black cells in coordinates.

### Space Complexity 💾
- **Best Case:** O(k)
- **Worst Case:** O(k)

Hash map space depends on the number of unique blocks affected by black cells.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-black-blocks/description/)

---
{{< youtube qnbzbMmLK8Q >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
