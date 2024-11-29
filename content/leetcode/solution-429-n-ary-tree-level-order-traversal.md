
+++
authors = ["grid47"]
title = "Leetcode 429: N-ary Tree Level Order Traversal"
date = "2024-09-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 429: N-ary Tree Level Order Traversal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/429.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/429.webp" 
    alt="An N-ary tree with nodes being traversed in level order, with each level softly illuminated as it's visited."
    caption="Solution to LeetCode 429: N-ary Tree Level Order Traversal Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an n-ary tree where each node contains a value and a list of its children. Your task is to return the level order traversal of the tree's nodes. Nodes are grouped by their level, with the root node at level 0. Each node’s children are separated by a null value in the level order serialization.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is serialized as a list where each node’s value is followed by its children, and groups of children are separated by null values.
- **Example:** `root = [10, null, 20, 30, 40, null, 50, 60]`
- **Constraints:**
	- The total number of nodes is between [0, 104].
	- The height of the tree is less than or equal to 1000.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a list of lists where each sublist represents the nodes at a particular level.
- **Example:** `[[10], [20, 30, 40], [50, 60]]`
- **Constraints:**
	- The output should group nodes by their levels.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to perform a level order traversal and group the nodes at each level into separate lists.

- 1. Initialize an empty result list to hold the groups of nodes.
- 2. Traverse the tree level by level, using a queue to store nodes at each level.
- 3. For each node, add its value to the corresponding level’s group in the result list.
- 4. Continue the traversal until all nodes are processed.
{{< dots >}}
### Problem Assumptions ✅
- The tree structure is a valid n-ary tree.
- Each node can have any number of children.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [1, null, 2, 3, 4, 5, null, null, 6, 7, null, 8, 9, 10, null, null, 11, null, 12, null, 13, null, null, 14]`  \
  **Explanation:** The tree structure is divided into levels. At each level, we group nodes together, starting with the root node at level 0. The children of each node are grouped at the next level.

{{< dots >}}
## Approach 🚀
We will perform a level order traversal using a queue. The key is to handle the nodes at each level and collect their values separately in the result list.

### Initial Thoughts 💭
- A level order traversal ensures that we process each level of nodes one by one.
- Using a queue will allow us to process nodes level by level, ensuring we capture the correct ordering.
{{< dots >}}
### Edge Cases 🌐
- An empty tree should return an empty list.
- Large trees with up to 10,000 nodes should be handled efficiently.
- Ensure correct behavior with nodes having no children (leaf nodes).
- The solution should handle edge cases such as an empty tree or a tree with only one node.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> levelOrder(Node* root) {
    if(!root) return {};
    vector<vector<int>> ans;
    levelOrderT(root, 0, ans);
    return ans;
}

void levelOrderT(Node* node, int level, vector<vector<int>> &ans) {
    if(level == size(ans)) {
        ans.push_back({node->val});
    } else {
        ans[level].push_back(node->val);
    }

    for(Node* child: node->children) {
        levelOrderT(child, level+1, ans);
    }
}
```

This function performs a level-order traversal of an n-ary tree, grouping nodes by their levels into a 2D vector.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<vector<int>> levelOrder(Node* root) {
	```
	Declares the main function for level-order traversal, returning a 2D vector containing nodes grouped by level.

2. **Base Condition**
	```cpp
	    if(!root) return {};
	```
	Handles the edge case where the tree is empty, returning an empty result.

3. **Variable Initialization**
	```cpp
	    vector<vector<int>> ans;
	```
	Initializes a 2D vector to store the traversal result grouped by levels.

4. **Recursive Function Call**
	```cpp
	    levelOrderT(root, 0, ans);
	```
	Starts the recursive level-order traversal from the root node.

5. **Return Result**
	```cpp
	    return ans;
	```
	Returns the final 2D vector containing the level-order traversal result.

6. **Recursive Function Declaration**
	```cpp
	void levelOrderT(Node* node, int level, vector<vector<int>> &ans) {
	```
	Declares the recursive helper function for level-order traversal.

7. **Conditional Check**
	```cpp
	    if(level == size(ans)) {
	```
	Checks if the current level exists in the 2D vector; if not, creates a new level.

8. **Push**
	```cpp
	        ans.push_back({node->val});
	```
	Adds the current node's value to a new level in the result vector.

9. **Else Condition**
	```cpp
	    } else {
	```
	Handles the case where the level already exists in the result vector.

10. **Push**
	```cpp
	        ans[level].push_back(node->val);
	```
	Appends the current node's value to the existing level in the result vector.

11. **Condition End**
	```cpp
	    }
	```
	Ends the conditional block for checking the level.

12. **Loop**
	```cpp
	    for(Node* child: node->children) {
	```
	Iterates through all children of the current node to process them recursively.

13. **Recursive Call**
	```cpp
	        levelOrderT(child, level+1, ans);
	```
	Calls the helper function for each child, incrementing the level.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the total number of nodes in the tree.
- **Average Case:** O(n), since we process each node once.
- **Worst Case:** O(n), since we must visit all nodes.

The time complexity is linear with respect to the total number of nodes.

### Space Complexity 💾
- **Best Case:** O(n), since we store all nodes in the queue for processing.
- **Worst Case:** O(n), where n is the total number of nodes.

Space complexity is linear, as we store nodes at each level during traversal.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
