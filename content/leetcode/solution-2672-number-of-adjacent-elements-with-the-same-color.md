
+++
authors = ["grid47"]
title = "Leetcode 2672: Number of Adjacent Elements With the Same Color"
date = "2024-02-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2672: Number of Adjacent Elements With the Same Color in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "w3L3-aRiNXE"
youtube_upload_date="2023-05-07"
youtube_thumbnail="https://i.ytimg.com/vi_webp/w3L3-aRiNXE/maxresdefault.webp"
comments = true
+++



---
You are given an integer `n`, representing an array of `n` elements where all elements are initially set to 0 (uncolored). You are also given a 2D integer array `queries`, where each query specifies an index and a color. For each query, set the element at the specified index to the given color and then count the number of adjacent pairs of elements in the array that have the same color. Return an array `answer` where each element corresponds to the number of adjacent pairs with the same color after applying the corresponding query.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer `n` representing the size of the array and a 2D array `queries` where each query is a pair of integers: the index of the element to color and the color to set.
- **Example:** `Input: n = 5, queries = [[0,3],[1,2],[2,2],[3,1],[4,3]]`
- **Constraints:**
	- 1 <= n <= 10^5
	- 1 <= queries.length <= 10^5
	- queries[i].length == 2
	- 0 <= index_i <= n - 1
	- 1 <= color_i <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an array `answer` of the same length as `queries`, where `answer[i]` is the number of adjacent pairs with the same color after applying the `i`-th query.
- **Example:** `Output: [0,1,2,2,3]`
- **Constraints:**
	- Each element in the `answer` array represents the number of adjacent pairs with the same color after each query.

{{< dots >}}
### Core Logic 🔍
**Goal:** To efficiently count the number of adjacent pairs with the same color after applying each query.

- Step 1: Initialize an array `colors` of size `n` where all elements are initially set to 0 (uncolored).
- Step 2: Initialize a variable `adj` to keep track of the current number of adjacent pairs with the same color.
- Step 3: For each query, update the color of the specified index and adjust the `adj` count based on the adjacent elements' colors.
- Step 4: After each query, store the current count of adjacent pairs with the same color in the result array `answer`.
{{< dots >}}
### Problem Assumptions ✅
- The array `colors` is initially uncolored (all elements set to 0).
- Each query updates the color of exactly one element in the array.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 5, queries = [[0,3],[1,2],[2,2],[3,1],[4,3]]`  \
  **Explanation:** After the first query, the array becomes [3,0,0,0,0], with 0 adjacent pairs having the same color. After the second query, the array becomes [3,2,0,0,0], and there is 1 adjacent pair with the same color. After the third query, the array becomes [3,2,2,0,0], and there are 2 adjacent pairs with the same color, and so on.

{{< dots >}}
## Approach 🚀
The approach uses an array to represent the colors and a variable to keep track of the number of adjacent pairs with the same color. After each query, the colors are updated and the number of adjacent pairs is recalculated efficiently.

### Initial Thoughts 💭
- We need to maintain an efficient way of counting adjacent pairs with the same color after each query.
- It is important to only update the counts when a query changes the color of a specific index.
- Using an array to store colors and a variable for the count of adjacent pairs will allow us to efficiently track changes with each query.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one query since queries.length >= 1.
- The solution must handle up to 10^5 queries efficiently.
- If an index is updated to the same color as before, the adjacent pairs count should not change.
- Ensure the solution is efficient enough to handle the largest inputs.
{{< dots >}}
## Code 💻
```cpp
vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
int c[100003] = {}, adj = 0;
vector<int> res;
for (const auto &q : queries) {
    int i = q[0] + 1, color_i = q[1];
    if (c[i])
        adj -= (c[i - 1] == c[i]) + (c[i + 1] == c[i]);
    c[i] = color_i;
    adj += (c[i - 1] == c[i]) + (c[i + 1] == c[i]);
    res.push_back(adj);
}
return res;
}
```

The function 'colorTheArray' processes a series of coloring queries on an array and tracks the number of adjacent elements with the same color after each query.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
	```
	The function 'colorTheArray' accepts an integer 'n' (the size of the array) and a list of queries to update the colors of the array.

2. **Array Initialization**
	```cpp
	int c[100003] = {}, adj = 0;
	```
	We initialize an array 'c' of size 100003 to store the color of each element, and an integer 'adj' to track the number of adjacent elements with the same color.

3. **Result Initialization**
	```cpp
	vector<int> res;
	```
	We initialize a vector 'res' to store the result of each query, which is the number of adjacent pairs with the same color.

4. **Query Loop Start**
	```cpp
	for (const auto &q : queries) {
	```
	We start a loop to process each query in the 'queries' vector. Each query contains the index to update and the color to apply.

5. **Query Variables**
	```cpp
	    int i = q[0] + 1, color_i = q[1];
	```
	We extract the index and color from the current query. The index is adjusted by adding 1 to match the array's 1-based indexing, and we store the color to apply.

6. **Condition Check for Existing Color**
	```cpp
	    if (c[i])
	```
	We check if the current position 'i' has a previously assigned color.

7. **Adjust Adjacent Pair Count Before Update**
	```cpp
	        adj -= (c[i - 1] == c[i]) + (c[i + 1] == c[i]);
	```
	If the position already has a color, we decrement the 'adj' count based on whether the adjacent elements have the same color.

8. **Update Color**
	```cpp
	    c[i] = color_i;
	```
	We assign the new color to the current position 'i' in the array.

9. **Adjust Adjacent Pair Count After Update**
	```cpp
	    adj += (c[i - 1] == c[i]) + (c[i + 1] == c[i]);
	```
	After updating the color, we increment the 'adj' count if the adjacent elements now match the new color.

10. **Store Result for Current Query**
	```cpp
	    res.push_back(adj);
	```
	We push the current value of 'adj' to the result vector 'res', representing the number of adjacent pairs with the same color after this query.

11. **Return Result**
	```cpp
	return res;
	```
	After processing all queries, we return the result vector 'res' containing the number of adjacent pairs with the same color after each query.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(n)

The time complexity is O(n) per query because we only need to check adjacent elements when updating the color.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the `colors` array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-adjacent-elements-with-the-same-color/description/)

---
{{< youtube w3L3-aRiNXE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
