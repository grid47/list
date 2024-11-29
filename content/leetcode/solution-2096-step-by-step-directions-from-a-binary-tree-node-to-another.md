
+++
authors = ["grid47"]
title = "Leetcode 2096: Step-By-Step Directions From a Binary Tree Node to Another"
date = "2024-04-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2096: Step-By-Step Directions From a Binary Tree Node to Another in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "JegJNGcwtFg"
youtube_upload_date="2024-07-16"
youtube_thumbnail="https://i.ytimg.com/vi/JegJNGcwtFg/maxresdefault.jpg"
comments = true
+++



---
You are given a binary tree where each node has a unique value between 1 and n. You are also given a start node and a destination node, each represented by their values. Your task is to find the shortest path from the start node to the destination node in terms of directions. The directions should be represented by a string using the characters 'L', 'R', and 'U', where 'L' means left child, 'R' means right child, and 'U' means moving to the parent node.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the root of the binary tree and two integers representing the start and destination nodes.
- **Example:** `root = [8, 3, 10, 1, 6, null, 14, null, null, 4, 7], startValue = 1, destValue = 7`
- **Constraints:**
	- The number of nodes in the tree is between 2 and 10^5.
	- Each node's value is unique.
	- The startValue and destValue are different.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a string representing the directions from the start node to the destination node, using 'L', 'R', and 'U' characters.
- **Example:** `Output: 'UUR'`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the shortest path between the start and destination nodes in terms of directions.

- First, find the path from the root to the start node and the path from the root to the destination node.
- Compare the two paths and remove the common part from the end of both paths.
- For the remaining part of the start path, replace each step with 'U' to move upwards to the common ancestor.
- For the remaining part of the destination path, leave the steps as they are, which will be moving downwards to the destination.
{{< dots >}}
### Problem Assumptions ✅
- The tree is not empty.
- Both startValue and destValue are valid and exist in the tree.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: root = [8, 3, 10, 1, 6, null, 14, null, null, 4, 7], startValue = 1, destValue = 7`  \
  **Explanation:** The shortest path from 1 to 7 is: 1 → 3 → 6 → 7. The directions are 'UUR'.

- **Input:** `Example 2: root = [1, 2], startValue = 1, destValue = 2`  \
  **Explanation:** The shortest path from 1 to 2 is directly down the left child. The direction is 'L'.

{{< dots >}}
## Approach 🚀
The approach involves finding the paths from the root to both the start and destination nodes, comparing them, and extracting the necessary directions for the shortest path.

### Initial Thoughts 💭
- We need to traverse the tree to find the paths to the start and destination nodes.
- Once we have the paths, we can easily determine the shortest path by removing the common portion and adjusting the directions accordingly.
{{< dots >}}
### Edge Cases 🌐
- There are no empty input cases as the tree is guaranteed to contain at least two nodes.
- The solution should handle trees with up to 10^5 nodes efficiently.
- The start and destination nodes are distinct and valid, ensuring there are no circular paths.
- The tree is not empty, and both nodes are within the valid range.
{{< dots >}}
## Code 💻
```cpp

bool find(TreeNode* n, int val, string &path) {
    if(n->val == val) return true;
         if (n->left  && find(n->left,  val, path)) path.push_back('L');
    else if (n->right && find(n->right, val, path)) path.push_back('R');
    return !path.empty();
}

string getDirections(TreeNode* root, int startValue, int destValue) {
    string sp, dp;
    find(root, startValue, sp);
    find(root,  destValue, dp);
    while(!sp.empty() && !dp.empty() && sp.back() == dp.back()) {
        sp.pop_back();
        dp.pop_back();
    }
    return string(sp.size(), 'U') + string(rbegin(dp), rend(dp));
}
```

This code defines two functions. The first, 'find', searches for a node in a binary tree and records the path from the root to the node. The second, 'getDirections', finds the directions to go from one node to another in the tree, moving up ('U') to a common ancestor and then down ('L' or 'R') to the destination.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Start of find function**
	```cpp
	bool find(TreeNode* n, int val, string &path) {
	```
	Defines the 'find' function, which searches for a node with a specific value in a binary tree and records the path to that node.

2. **Base Case Check**
	```cpp
	    if(n->val == val) return true;
	```
	Checks if the current node's value matches the target value. If so, it returns true, indicating the node has been found.

3. **Left Subtree Search**
	```cpp
	         if (n->left  && find(n->left,  val, path)) path.push_back('L');
	```
	If the left child exists, recursively searches the left subtree. If the value is found, 'L' is added to the path indicating a left move.

4. **Right Subtree Search**
	```cpp
	    else if (n->right && find(n->right, val, path)) path.push_back('R');
	```
	If the right child exists, recursively searches the right subtree. If the value is found, 'R' is added to the path indicating a right move.

5. **Return Condition**
	```cpp
	    return !path.empty();
	```
	Returns true if a path has been found (i.e., the path vector is not empty), indicating the target node exists in the tree.

6. **Start of getDirections function**
	```cpp
	string getDirections(TreeNode* root, int startValue, int destValue) {
	```
	Defines the 'getDirections' function, which calculates the directions from the start node to the destination node in a binary tree.

7. **Initialize Path Variables**
	```cpp
	    string sp, dp;
	```
	Declares two string variables, 'sp' and 'dp', to store the paths from the root to the start node and the destination node, respectively.

8. **Find Start Node Path**
	```cpp
	    find(root, startValue, sp);
	```
	Finds the path from the root to the start node using the 'find' function, storing the result in 'sp'.

9. **Find Destination Node Path**
	```cpp
	    find(root,  destValue, dp);
	```
	Finds the path from the root to the destination node using the 'find' function, storing the result in 'dp'.

10. **Common Ancestor Check**
	```cpp
	    while(!sp.empty() && !dp.empty() && sp.back() == dp.back()) {
	```
	This loop checks for the common ancestor by comparing the last characters of both paths. If the characters are the same, it means both paths lead to the same node, so both characters are removed from the paths.

11. **Remove Matching Steps from Start Path**
	```cpp
	        sp.pop_back();
	```
	Removes the last character from the 'sp' path, indicating that the current step matches the destination path up to the common ancestor.

12. **Remove Matching Steps from Destination Path**
	```cpp
	        dp.pop_back();
	```
	Removes the last character from the 'dp' path, indicating that the current step matches the start path up to the common ancestor.

13. **Construct Final Direction String**
	```cpp
	    return string(sp.size(), 'U') + string(rbegin(dp), rend(dp));
	```
	Constructs the final direction string by concatenating 'U' (up steps) for the start path and the reverse of the destination path to go down ('L' or 'R').

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we need to traverse the entire tree to find both paths to the start and destination nodes.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) because we need to store the paths from the root to both nodes.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/)

---
{{< youtube JegJNGcwtFg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
