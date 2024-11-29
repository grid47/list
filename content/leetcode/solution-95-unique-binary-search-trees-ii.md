
+++
authors = ["grid47"]
title = "Leetcode 95: Unique Binary Search Trees II"
date = "2024-10-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 95: Unique Binary Search Trees II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming","Backtracking","Tree","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/95.webp"
youtube = "m907FlQa2Yc"
youtube_upload_date="2023-08-05"
youtube_thumbnail="https://i.ytimg.com/vi/m907FlQa2Yc/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/95.webp" 
    alt="A sequence of elegant trees gently forming in various, unique shapes."
    caption="Solution to LeetCode 95: Unique Binary Search Trees II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer n, return all structurally unique binary search trees (BSTs) that can be constructed using the integers from 1 to n. Each tree should be a unique arrangement of nodes where each node contains a unique value from the set {1, 2, ..., n}.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a single integer n, where 1 <= n <= 8, representing the number of nodes in the binary search tree.
- **Example:** `Input: n = 3`
- **Constraints:**
	- 1 <= n <= 8

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of all structurally unique binary search trees that can be constructed using the integers from 1 to n. The output trees should be returned in any order.
- **Example:** `Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]`
- **Constraints:**
	- The output must include all unique BSTs without duplicates.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to generate all possible unique BSTs for a given number n, where each BST is formed by placing integers 1 to n as nodes in a valid binary search tree structure.

- Recursively fix a root node and divide the remaining numbers into left and right subtrees.
- Generate all possible left and right subtrees for each choice of root node.
- Combine each left and right subtree with the current root and add them to the result list.
{{< dots >}}
### Problem Assumptions ✅
- The input number n is valid and within the specified range.
- The binary search tree properties (left children < root and right children > root) must hold for all trees.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 3`  \
  **Explanation:** For n = 3, the unique BSTs can be formed by choosing each number as the root once, and then generating the corresponding left and right subtrees. The output consists of 5 unique BSTs.

- **Input:** `Input: n = 1`  \
  **Explanation:** For n = 1, there is only one possible BST: a single node tree with value 1.

{{< dots >}}
## Approach 🚀
To generate all unique BSTs for a given n, we can recursively fix a root and generate all possible left and right subtrees. We combine these subtrees to create the unique trees.

### Initial Thoughts 💭
- Binary search trees have unique properties, so each choice of root will generate different subtree configurations.
- We can approach this problem recursively by fixing a root, then recursively generating possible left and right subtrees for all numbers smaller and greater than the root.
- This problem requires a recursive strategy where we divide the problem into smaller subproblems by selecting a root and constructing the left and right subtrees for each choice.
{{< dots >}}
### Edge Cases 🌐
- If n = 0, there are no trees to generate.
- When n = 8, there are many possible unique BSTs to generate. Ensure the solution can handle the large number of trees efficiently.
- When n = 1, only one BST is possible, which is a single node tree.
- The solution should work efficiently for n values up to the maximum of 8.
{{< dots >}}
## Code 💻
```cpp
vector<TreeNode*> run(int l, int r) {
    vector<TreeNode*> ans, left, right;
    if(l >= r) {
        if(l == r) ans.push_back(new TreeNode(l));
        else ans.push_back(NULL);
        return ans;
    }
    for(int i = l; i <= r; i++) {
        left = run(l, i - 1);
        right= run(i + 1, r);
        
        for(int j = 0; j < left.size(); j++) {
            for(int k = 0; k < right.size(); k++) {
                TreeNode* node = new TreeNode(i);
                node->left = left[j];
                node->right = right[k];
                ans.push_back(node);
            }
        }
    }
    return ans;
}

vector<TreeNode*> generateTrees(int n) {
    /*
    
    This is a small light weight problem
    my mind is not ready to think about this problem
    
    bst is sorted array
    we can fix a root and get a 
    array of left trees
    and array of right trees
    integrate them then add to result
    
    */        
    vector<TreeNode*> ans, left, right;
    
    for(int i = 1; i <= n; i++) {
        left = run(1, i - 1);
        right= run(i + 1, n);
        
        for(int j = 0; j < left.size(); j++) {
            for(int k = 0; k < right.size(); k++) {
                TreeNode* node = new TreeNode(i);
                node->left = left[j];
                node->right = right[k];
                ans.push_back(node);
            }
        }
    }
    return ans;
}
```

This code generates all unique binary search trees for given values by using recursion to construct left and right subtrees and combining them with different root nodes.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Recursive Function**
	```cpp
	vector<TreeNode*> run(int l, int r) {
	```
	Defines a recursive function to generate trees for the range [l, r].

2. **Variable Initialization**
	```cpp
	    vector<TreeNode*> ans, left, right;
	```
	Initializes vectors to store results, left subtrees, and right subtrees.

3. **Conditional Check**
	```cpp
	    if(l >= r) {
	```
	Handles the base case where the range is invalid or a single node remains.

4. **Node Creation**
	```cpp
	        if(l == r) ans.push_back(new TreeNode(l));
	```
	Creates a single node when l equals r and adds it to the results.

5. **Null Insertion**
	```cpp
	        else ans.push_back(NULL);
	```
	Handles cases where there are no valid trees by adding a null tree.

6. **Return Statement**
	```cpp
	        return ans;
	```
	Returns the generated trees for the current range.

7. **Loop Start**
	```cpp
	    for(int i = l; i <= r; i++) {
	```
	Iterates through possible root values in the range [l, r].

8. **Recursive Call**
	```cpp
	        left = run(l, i - 1);
	```
	Recursively generates left subtrees for the current root.

9. **Recursive Call**
	```cpp
	        right= run(i + 1, r);
	```
	Recursively generates right subtrees for the current root.

10. **Nested Loop**
	```cpp
	        for(int j = 0; j < left.size(); j++) {
	```
	Iterates through all left subtrees.

11. **Nested Loop**
	```cpp
	            for(int k = 0; k < right.size(); k++) {
	```
	Iterates through all right subtrees.

12. **Node Creation**
	```cpp
	                TreeNode* node = new TreeNode(i);
	```
	Creates a new root node with the current value.

13. **Tree Integration**
	```cpp
	                node->left = left[j];
	```
	Attaches a left subtree to the root node.

14. **Tree Integration**
	```cpp
	                node->right = right[k];
	```
	Attaches a right subtree to the root node.

15. **Result Addition**
	```cpp
	                ans.push_back(node);
	```
	Adds the constructed tree to the results.

16. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the list of trees generated for the given range.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(2^n)
- **Average Case:** O(2^n)
- **Worst Case:** O(2^n)

The time complexity is exponential, as we generate all possible BSTs for the given n.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n^2)

The space complexity is O(n^2) in the worst case due to the recursion stack and storage for trees.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/unique-binary-search-trees-ii/description/)

---
{{< youtube m907FlQa2Yc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
