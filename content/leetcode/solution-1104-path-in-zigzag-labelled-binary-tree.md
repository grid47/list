
+++
authors = ["grid47"]
title = "Leetcode 1104: Path In Zigzag Labelled Binary Tree"
date = "2024-07-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1104: Path In Zigzag Labelled Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given a label representing a node in an infinite binary tree. In this binary tree, each level alternates between left-to-right and right-to-left labeling. Your task is to return the path from the root of the tree to the node with the given label, following the zigzag pattern.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer `label`, which represents the label of a node in the zigzag binary tree.
- **Example:** `label = 10`
- **Constraints:**
	- 1 <= label <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** You should return an array of integers, representing the labels from the root of the tree to the node with the given label, in the correct order.
- **Example:** `[1, 3, 6, 10]`
- **Constraints:**
	- The returned array should be in ascending order from the root to the node.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the path from the root to the node with the given label in the zigzag binary tree.

- Determine the level of the given node by calculating the logarithm of the label.
- Starting from the given node, trace the path back to the root by repeatedly computing the parent of the current node.
- At each level, adjust the calculation based on whether the level is odd or even, to account for the zigzag pattern.
{{< dots >}}
### Problem Assumptions ✅
- The given label is valid and corresponds to a node in the tree.
- The level of the given node can be determined using logarithmic operations.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: label = 10`  \
  **Explanation:** The node with label 10 lies at level 4, and the path from the root to this node is [1, 3, 6, 10]. At level 4, the node is labeled from right to left, so the pattern is followed accordingly.

{{< dots >}}
## Approach 🚀
The goal is to find the path from the root to the given node by working backwards from the label, adjusting the calculation for each level based on whether it is odd or even.

### Initial Thoughts 💭
- The binary tree alternates labeling direction at each level.
- Finding the level of the node helps determine its position in the tree.
- Start from the given label and move upwards to the root, adjusting the label at each level based on the zigzag pattern.
{{< dots >}}
### Edge Cases 🌐
- The input is guaranteed to always be a valid label within the given range.
- The label can be as large as 10^6, so the solution should efficiently handle large inputs.
- The root node is always labeled 1, and the solution should correctly handle this case.
- The tree has infinite depth, so the solution must work efficiently for all labels within the range.
{{< dots >}}
## Code 💻
```cpp
class Solution {

public:
vector<int> pathInZigZagTree(int label) {
    vector<int> res;
    res.push_back(label);
    int level = log2(label);

    while (level != 0) {
        int left = pow(2 , (level - 1));
        int right = pow(2 , level) - 1;
        label = left + ( right- label / 2);

        res.push_back(label);
        level -= 1;
    }

    int num = res.size();
    reverse(res.begin(), res.end());

    return res;
}
```

This is the complete solution to finding the path in a zigzag binary tree given a label. It calculates the path by iterating through the tree from the label up to the root, taking into account the zigzag pattern of the tree.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Declaration**
	```cpp
	class Solution {
	```
	The class declaration for the `Solution` class, which contains the method to solve the problem.

2. **Access Modifier**
	```cpp
	public:
	```
	The access modifier `public` indicates that the members of the class can be accessed from outside the class.

3. **Method Declaration**
	```cpp
	vector<int> pathInZigZagTree(int label) {
	```
	This method `pathInZigZagTree` takes an integer `label` as input and returns a vector of integers representing the path in the zigzag binary tree.

4. **Variable Declaration**
	```cpp
	    vector<int> res;
	```
	A vector `res` is declared to store the path from the label to the root of the tree.

5. **Push to Vector**
	```cpp
	    res.push_back(label);
	```
	The label is added to the `res` vector as the first node in the path.

6. **Level Calculation**
	```cpp
	    int level = log2(label);
	```
	The level of the tree at which the label is located is calculated using the logarithm base 2 of the label.

7. **Loop Start**
	```cpp
	    while (level != 0) {
	```
	A while loop is used to trace the path from the label to the root of the tree. It continues until the root is reached.

8. **Left Node Calculation**
	```cpp
	        int left = pow(2 , (level - 1));
	```
	The leftmost node at the current level is calculated as (2^{	ext{level}-1}).

9. **Right Node Calculation**
	```cpp
	        int right = pow(2 , level) - 1;
	```
	The rightmost node at the current level is calculated as (2^{	ext{level}} - 1).

10. **Label Update**
	```cpp
	        label = left + ( right- label / 2);
	```
	The label is updated based on the current level's nodes. The formula adjusts the label for the zigzag pattern.

11. **Push to Vector**
	```cpp
	        res.push_back(label);
	```
	The updated label is added to the `res` vector.

12. **Level Decrement**
	```cpp
	        level -= 1;
	```
	The level is decremented by 1, moving upwards in the tree.

13. **Reverse Vector**
	```cpp
	    reverse(res.begin(), res.end());
	```
	The vector `res` is reversed because the path was collected from the label to the root and needs to be reversed to show the path from the root to the label.

14. **Return Statement**
	```cpp
	    return res;
	```
	The method returns the vector `res` containing the path from the root to the label in the zigzag tree.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log(label))
- **Average Case:** O(log(label))
- **Worst Case:** O(log(label))

The time complexity is logarithmic in terms of the label, as we are tracing the path back from the node to the root.

### Space Complexity 💾
- **Best Case:** O(log(label))
- **Worst Case:** O(log(label))

The space complexity is also logarithmic because we store the path from the root to the node, which depends on the level of the node.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
