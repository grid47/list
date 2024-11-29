
+++
authors = ["grid47"]
title = "Leetcode 2582: Pass the Pillow"
date = "2024-02-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2582: Pass the Pillow in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "oVvmwsm2dKY"
youtube_upload_date="2023-03-05"
youtube_thumbnail="https://i.ytimg.com/vi_webp/oVvmwsm2dKY/maxresdefault.webp"
comments = true
+++



---
You are given the root of a binary tree and a positive integer `k`. The level sum in the tree is the sum of the node values that lie at the same level. Return the `k`th largest level sum in the tree. If there are fewer than `k` levels, return -1. Nodes are on the same level if they are at the same distance from the root.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the root of a binary tree and a positive integer `k`.
- **Example:** `For example, `root = [5, 8, 9, 2, 1, 3, 7, 4, 6], k = 2`.`
- **Constraints:**
	- 2 <= n <= 10^5
	- 1 <= Node.val <= 10^6
	- 1 <= k <= n

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer representing the `k`th largest level sum in the tree, or -1 if there are fewer than `k` levels.
- **Example:** `For input `root = [5, 8, 9, 2, 1, 3, 7, 4, 6], k = 2`, the output is `13`.`
- **Constraints:**
	- The result will always be a valid integer or -1.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the `k`th largest level sum in the tree. We need to traverse the tree, calculate the level sums, and then find the kth largest value.

- 1. Traverse the tree level by level using a breadth-first search (BFS).
- 2. Calculate the sum of node values at each level.
- 3. Sort the level sums in descending order.
- 4. Return the `k`th largest level sum, or -1 if there are fewer than `k` levels.
{{< dots >}}
### Problem Assumptions ✅
- The input tree is valid and contains no cycles.
{{< dots >}}
## Examples 🧩
- **Input:** `For `root = [5, 8, 9, 2, 1, 3, 7, 4, 6], k = 2``  \
  **Explanation:** The level sums are [5, 17, 13, 10]. The 2nd largest sum is 13.

{{< dots >}}
## Approach 🚀
The approach is to use a breadth-first search (BFS) to traverse the tree level by level and compute the sum of node values at each level. Once all level sums are calculated, we sort them and return the `k`th largest sum.

### Initial Thoughts 💭
- We need to process each level of the tree and calculate the sum of node values at that level.
- Using BFS will allow us to traverse the tree level by level efficiently.
{{< dots >}}
### Edge Cases 🌐
- No empty tree inputs will be given.
- The solution should handle large trees efficiently, with up to 100,000 nodes.
- If `k` is larger than the number of levels, the solution should return -1.
- The tree will have at least 2 nodes, and `k` will always be a valid integer between 1 and the number of levels.
{{< dots >}}
## Code 💻
```cpp
    int passThePillow(int n, int time) {
        return n - abs(n - 1 - time % (n * 2 - 2));
    }
```

This function calculates the position of the person holding the pillow after a given amount of time in a game, considering the total number of participants `n`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	    int passThePillow(int n, int time) {
	```
	Define the function `passThePillow`, which takes two arguments: `n` (the number of participants) and `time` (the number of seconds elapsed).

2. **Calculation**
	```cpp
	        return n - abs(n - 1 - time % (n * 2 - 2));
	```
	Return the position of the person holding the pillow after `time` seconds, adjusting for the cyclic nature of the game. The formula accounts for the alternating movement back and forth between participants.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is O(n log n) due to the sorting step, where n is the number of levels in the tree.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) for storing the level sums.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/pass-the-pillow/description/)

---
{{< youtube oVvmwsm2dKY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
