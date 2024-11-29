
+++
authors = ["grid47"]
title = "Leetcode 2678: Number of Senior Citizens"
date = "2024-02-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2678: Number of Senior Citizens in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "l6_wwKzFmVo"
youtube_upload_date="2024-08-01"
youtube_thumbnail="https://i.ytimg.com/vi/l6_wwKzFmVo/maxresdefault.jpg"
comments = true
+++



---
You are given a perfect binary tree with `n` nodes, where each node has a cost associated with it. The tree is numbered from 1 to n, with node 1 as the root. For each node `i`, its left child is `2*i` and its right child is `2*i + 1`. You are allowed to increment the cost of any node by 1 any number of times. Your task is to return the minimum number of increments required to make the total cost of the path from the root to each leaf node equal.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer `n` representing the number of nodes in a perfect binary tree, followed by a list of integers `cost`, where `cost[i]` is the cost of node `i+1`.
- **Example:** `Input: n = 5, cost = [2, 4, 3, 2, 5]`
- **Constraints:**
	- 3 <= n <= 10^5
	- n + 1 is a power of 2
	- cost.length == n
	- 1 <= cost[i] <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a single integer, which represents the minimum number of increments required to make the cost of all root-to-leaf paths equal.
- **Example:** `Output: 4`
- **Constraints:**
	- The result should be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the number of increments required to equalize the path costs.

- Step 1: Starting from the leaf nodes, propagate the required increments up to the root node, ensuring each path has the same total cost.
- Step 2: For each non-leaf node, compare the costs of its left and right children. Increment the smaller one to match the larger one and count the number of increments.
- Step 3: Repeat the process until you reach the root node.
{{< dots >}}
### Problem Assumptions ✅
- The tree is a perfect binary tree, meaning every non-leaf node has exactly two children.
- All nodes have a non-negative cost value.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 5, cost = [2, 4, 3, 2, 5]`  \
  **Explanation:** In this case, the two paths from root to leaves are [2, 4, 5] and [2, 3, 5]. To equalize the path costs, we increment the cost of node 2 to match node 3's cost. This requires 4 increments, so the total increments required are 4.

{{< dots >}}
## Approach 🚀
To solve this problem, we will work our way from the leaf nodes upwards to the root, balancing the path costs by making necessary increments.

### Initial Thoughts 💭
- We need to ensure that the cost of each root-to-leaf path is the same.
- This requires comparing the costs of left and right children of every node and balancing them.
- Starting from the leaf nodes and adjusting the internal nodes' costs seems to be an efficient way to solve this problem.
{{< dots >}}
### Edge Cases 🌐
- The input will always have at least 3 nodes, ensuring a valid binary tree structure.
- The solution must handle up to 10^5 nodes efficiently.
- If the tree already has equal costs for all root-to-leaf paths, the result should be 0 increments.
- Ensure the solution runs in O(n) time complexity to handle the largest inputs.
{{< dots >}}
## Code 💻
```cpp
int countSeniors(vector<string>& details) {
    int count = 0;
    for(auto i : details) {
        if(i[11] - '0' > 6) count++;
        else if (i[11] - '0' == 6 && i[12] - '0' > 0) count++;
    }
    return count;
}
```

The function 'countSeniors' counts the number of seniors from a list of age details. It examines the date of birth of each individual (formatted as a string) and increments the count if the age is greater than or equal to 60.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int countSeniors(vector<string>& details) {
	```
	The function 'countSeniors' is defined with a parameter 'details', which is a vector of strings. Each string represents an individual's details, including their date of birth.

2. **Variable Initialization**
	```cpp
	    int count = 0;
	```
	A variable 'count' is initialized to 0, which will be used to keep track of the number of seniors in the 'details' vector.

3. **Iteration Over Details**
	```cpp
	    for(auto i : details) {
	```
	We loop through each element 'i' in the 'details' vector, where each element is a string containing personal details of an individual.

4. **Check for Senior 1**
	```cpp
	        if(i[11] - '0' > 6) count++;
	```
	The if condition checks if the month of birth (extracted from the string at index 11) is greater than 6 (i.e., born after June), which indicates the person is a senior (60+ years old). If true, 'count' is incremented.

5. **Check for Senior 2**
	```cpp
	        else if (i[11] - '0' == 6 && i[12] - '0' > 0) count++;
	```
	The else-if condition checks if the month is exactly June (index 11), and if the day of the month (index 12) is greater than 0, indicating the person is also a senior. In this case, 'count' is incremented.

6. **Return Result**
	```cpp
	    return count;
	```
	After the loop completes, the function returns the total count of seniors found in the 'details' vector.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) as we only need to traverse the tree once, adjusting costs from the leaves to the root.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space needed for the cost array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-senior-citizens/description/)

---
{{< youtube l6_wwKzFmVo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
