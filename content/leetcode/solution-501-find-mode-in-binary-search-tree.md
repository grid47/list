
+++
authors = ["grid47"]
title = "Leetcode 501: Find Mode in Binary Search Tree"
date = "2024-09-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 501: Find Mode in Binary Search Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Search Tree","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/501.webp"
youtube = "cHwafswjTlE"
youtube_upload_date="2019-05-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/cHwafswjTlE/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/501.webp" 
    alt="A glowing tree with nodes lighting up to highlight the mode, with the mode’s value softly radiating."
    caption="Solution to LeetCode 501: Find Mode in Binary Search Tree Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given the root of a binary search tree (BST) with possible duplicates, return the mode(s) (i.e., the most frequently occurring element) in the tree. If there are multiple modes, return them in any order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is the root node of a binary search tree (BST), which may contain duplicate values.
- **Example:** `[3, 2, 4, 2, 2, 5, 5]`
- **Constraints:**
	- 1 <= Number of nodes <= 10^4
	- -10^5 <= Node.val <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an array of integers representing the mode(s) of the tree, i.e., the most frequently occurring values.
- **Example:** `[2, 5]`
- **Constraints:**
	- The output array contains the mode(s) from the tree.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to identify the most frequent element(s) in a binary search tree with potential duplicates.

- 1. Perform an in-order traversal of the tree to visit nodes in ascending order.
- 2. Track the frequency of each node's value as you traverse.
- 3. Identify the mode(s) by comparing frequencies and storing the most frequent values.
{{< dots >}}
### Problem Assumptions ✅
- The binary tree is well-formed with valid BST properties.
- The tree may contain duplicate values, which should be handled.
{{< dots >}}
## Examples 🧩
- **Input:** `[3, 2, 4, 2, 2, 5, 5]`  \
  **Explanation:** In this example, the value 2 appears most frequently (3 times), and 5 appears twice, so the modes are [2, 5].

{{< dots >}}
## Approach 🚀
The approach involves performing an in-order traversal of the tree to count the frequency of each element and identify the mode(s).

### Initial Thoughts 💭
- In-order traversal ensures nodes are visited in ascending order.
- As we traverse, we can keep track of the frequency of node values and update the mode accordingly.
- We need to maintain a running frequency count and determine the highest frequency encountered during the traversal.
{{< dots >}}
### Edge Cases 🌐
- The tree will always have at least one node.
- The solution should handle trees with up to 10,000 nodes efficiently.
- The tree may contain nodes with negative values and large values (up to 10^5), which should be handled correctly.
- Ensure that the traversal and frequency count is optimized for large trees.
{{< dots >}}
## Code 💻
```cpp
int maxFreq = 0, currFreq = 0, precursor = INT_MIN;
vector<int> res;

vector<int> findMode(TreeNode *root)
{
    inorderTraversal(root);
    return res;
}

void inorderTraversal(TreeNode *root)
{
    if (root == NULL) return; // Stop condition
    inorderTraversal(root->left); // Traverse left subtree
    if (precursor == root->val) currFreq++;
    else currFreq = 1;
    if (currFreq > maxFreq)
    {// Current node value has higher frequency than any previous visited
        res.clear();
        maxFreq = currFreq;
        res.push_back(root->val);
    }
    else if (currFreq == maxFreq)
    {// Current node value has a frequency equal to the highest of previous visited
        res.push_back(root->val);
    }
    precursor = root->val; // Update the precursor
    inorderTraversal(root->right); // Traverse right subtree
}
```

This code defines a method `findMode` to find all the values in a binary tree that appear the most frequently, using an inorder traversal.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int maxFreq = 0, currFreq = 0, precursor = INT_MIN;
	```
	Initializes variables `maxFreq` to track the highest frequency, `currFreq` to track the current frequency of a node, and `precursor` to store the previous node value during traversal.

2. **Variable Initialization**
	```cpp
	vector<int> res;
	```
	Declares a vector `res` that will hold the values with the highest frequency.

3. **Method Definition**
	```cpp
	vector<int> findMode(TreeNode *root)
	```
	Defines the method `findMode` which takes a binary tree root node `root` and returns a vector of integers that represent the most frequent values in the tree.

4. **Method Call**
	```cpp
	    inorderTraversal(root);
	```
	Calls the helper method `inorderTraversal` to perform an inorder traversal of the tree and update the `res` vector.

5. **Return Statement**
	```cpp
	    return res;
	```
	Returns the vector `res`, which contains the values with the highest frequency in the tree.

6. **Method Definition**
	```cpp
	void inorderTraversal(TreeNode *root)
	```
	Defines the helper method `inorderTraversal` that performs an inorder traversal of the tree to track node frequencies.

7. **Base Case**
	```cpp
	    if (root == NULL) return; // Stop condition
	```
	Checks if the current node is `NULL`. If it is, the function returns, serving as the stop condition for recursion.

8. **Recursive Call**
	```cpp
	    inorderTraversal(root->left); // Traverse left subtree
	```
	Recursively calls `inorderTraversal` on the left child of the current node to traverse the left subtree.

9. **Frequency Check**
	```cpp
	    if (precursor == root->val) currFreq++;
	```
	Checks if the current node's value is equal to the `precursor` (previous node value). If so, increments the current frequency `currFreq`.

10. **Frequency Reset**
	```cpp
	    else currFreq = 1;
	```
	If the current node's value is different from the `precursor`, resets the current frequency `currFreq` to 1.

11. **Frequency Comparison**
	```cpp
	    if (currFreq > maxFreq)
	```
	Compares the current frequency `currFreq` with the maximum frequency `maxFreq`.

12. **Result Update**
	```cpp
	        res.clear();
	```
	Clears the `res` vector to remove previously stored values, as the current node has a higher frequency.

13. **Maximum Frequency Update**
	```cpp
	        maxFreq = currFreq;
	```
	Updates the `maxFreq` to the current frequency `currFreq`.

14. **Result Update**
	```cpp
	        res.push_back(root->val);
	```
	Adds the current node's value to the `res` vector as it now has the highest frequency.

15. **Frequency Comparison**
	```cpp
	    else if (currFreq == maxFreq)
	```
	If the current frequency is equal to the `maxFreq`, add the current node value to the results.

16. **Result Update**
	```cpp
	        res.push_back(root->val);
	```
	Adds the current node's value to the `res` vector, as it matches the maximum frequency.

17. **Update Precursor**
	```cpp
	    precursor = root->val; // Update the precursor
	```
	Updates the `precursor` to the current node's value to be used in the next comparison.

18. **Recursive Call**
	```cpp
	    inorderTraversal(root->right); // Traverse right subtree
	```
	Recursively calls `inorderTraversal` on the right child of the current node to traverse the right subtree.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of nodes in the tree, as each node is visited once during the in-order traversal.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required to store the result list and the recursion stack during the in-order traversal.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-mode-in-binary-search-tree/description/)

---
{{< youtube cHwafswjTlE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
