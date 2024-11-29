
+++
authors = ["grid47"]
title = "Leetcode 1305: All Elements in Two Binary Search Trees"
date = "2024-06-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1305: All Elements in Two Binary Search Trees in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Search Tree","Sorting","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "B97Hk1H2x2s"
youtube_upload_date="2020-09-05"
youtube_thumbnail="https://i.ytimg.com/vi/B97Hk1H2x2s/hqdefault.jpg?sqp=-oaymwEmCOADEOgC8quKqQMa8AEB-AHUBoAC4AOKAgwIABABGDMgRih_MA8=&rs=AOn4CLC03GCnDEem80J52_RuXkBdpkuQfA"
comments = true
+++



---
Given two binary search trees, root1 and root2, return a list containing all the integers from both trees, sorted in ascending order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** Each tree is represented by its root node, and the nodes of the tree follow the binary search tree property where left child < parent node < right child.
- **Example:** `Input: root1 = [3, 1, 4], root2 = [2, 0, 5]`
- **Constraints:**
	- The number of nodes in each tree is in the range [0, 5000].
	- -105 <= Node.val <= 105

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a sorted list containing all the integers from both trees.
- **Example:** `Output: [0, 1, 2, 3, 4, 5]`
- **Constraints:**
	- The output list will contain the sorted integers from both input trees.

{{< dots >}}
### Core Logic 🔍
**Goal:** To merge the two binary search trees and return the merged list of elements sorted in ascending order.

- Use a two-pointer or stack-based approach to traverse both trees in in-order (left, root, right) fashion.
- Merge the results of both traversals and return the combined sorted list.
{{< dots >}}
### Problem Assumptions ✅
- Both trees are valid binary search trees.
- The solution should be efficient enough to handle trees with up to 5000 nodes.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root1 = [3, 1, 4], root2 = [2, 0, 5]`  \
  **Explanation:** The combined elements from both trees are [3, 1, 4] and [2, 0, 5]. Sorting these values gives [0, 1, 2, 3, 4, 5].

- **Input:** `Input: root1 = [6, null, 10], root2 = [5, 2, 7]`  \
  **Explanation:** The combined elements from both trees are [6, 10] and [5, 2, 7]. Sorting these values gives [2, 5, 6, 7, 10].

{{< dots >}}
## Approach 🚀
The best approach is to perform an in-order traversal of both trees and merge the results as they are traversed in sorted order.

### Initial Thoughts 💭
- Binary search trees store elements in sorted order. This allows us to merge the trees efficiently using in-order traversal.
- We can use stacks to simulate the in-order traversal of both trees, which will allow us to process both trees simultaneously.
{{< dots >}}
### Edge Cases 🌐
- If one of the trees is empty, the solution should simply return the in-order traversal of the other tree.
- For very large trees, the solution should efficiently merge and sort the trees in linear time.
- If the trees contain duplicate values, the duplicates should appear in the result list in sorted order.
- The solution should operate within O(n) time complexity, where n is the total number of nodes across both trees.
{{< dots >}}
## Code 💻
```cpp
vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    stack<TreeNode*> st1, st2;
    vector<int> res;
    while(root1 || root2 || !st1.empty() || !st2.empty()) {
        while(root1) {
            st1.push(root1);
            root1 = root1->left;
        }
        while(root2) {
            st2.push(root2);
            root2 = root2->left;
        }
        if(st2.empty() || (!st1.empty() && st1.top()->val < st2.top()->val)) {
            root1 = st1.top();
            st1.pop();
            res.push_back(root1->val);
            root1 = root1->right;
        } else {
            root2 = st2.top();
            st2.pop();
            res.push_back(root2->val);
            root2 = root2->right;
        }
    }
    return res;
}
```

This function combines the elements from two binary search trees (BSTs) into a single sorted vector using an in-order traversal approach. It uses two stacks to traverse both trees in parallel and ensures that elements are added to the result vector in ascending order.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
	```
	Defines the function 'getAllElements' that takes two root nodes of binary search trees (root1 and root2) as input and returns a vector of integers containing all elements from both trees, sorted in ascending order.

2. **Stack Initialization**
	```cpp
	    stack<TreeNode*> st1, st2;
	```
	Declares two stacks, st1 and st2, to store nodes of both trees during the in-order traversal.

3. **Result Vector Initialization**
	```cpp
	    vector<int> res;
	```
	Declares an empty vector 'res' that will hold the elements from both trees in sorted order.

4. **Main Loop**
	```cpp
	    while(root1 || root2 || !st1.empty() || !st2.empty()) {
	```
	The while loop continues until both trees are fully traversed and both stacks are empty.

5. **Left Subtree Traversal - Root1**
	```cpp
	        while(root1) {
	```
	Traverses the left subtree of tree 1, pushing all nodes onto the stack st1 until a NULL node is encountered.

6. **Push Root1 to Stack**
	```cpp
	            st1.push(root1);
	```
	Pushes the current node (root1) onto the stack st1.

7. **Move to Left Child**
	```cpp
	            root1 = root1->left;
	```
	Moves to the left child of the current node in tree 1.

8. **Left Subtree Traversal - Root2**
	```cpp
	        while(root2) {
	```
	Traverses the left subtree of tree 2, pushing all nodes onto the stack st2 until a NULL node is encountered.

9. **Push Root2 to Stack**
	```cpp
	            st2.push(root2);
	```
	Pushes the current node (root2) onto the stack st2.

10. **Move to Left Child**
	```cpp
	            root2 = root2->left;
	```
	Moves to the left child of the current node in tree 2.

11. **Comparison and Node Selection**
	```cpp
	        if(st2.empty() || (!st1.empty() && st1.top()->val < st2.top()->val)) {
	```
	Compares the top nodes of the stacks to decide which node to pop. If stack st2 is empty or the top node of st1 is smaller than the top node of st2, it selects the node from tree 1.

12. **Pop and Process Node from St1**
	```cpp
	            root1 = st1.top();
	```
	Pops the top node from stack st1 and processes it.

13. **Pop from St1**
	```cpp
	            st1.pop();
	```
	Removes the processed node from stack st1.

14. **Add Value to Result**
	```cpp
	            res.push_back(root1->val);
	```
	Adds the value of the current node from tree 1 to the result vector.

15. **Move to Right Child - Root1**
	```cpp
	            root1 = root1->right;
	```
	Moves to the right child of the current node in tree 1.

16. **Else Clause - Node Selection from St2**
	```cpp
	        } else {
	```
	If the condition is false, it selects the node from tree 2 (either st2 is not empty or the top node of st2 is smaller).

17. **Pop and Process Node from St2**
	```cpp
	            root2 = st2.top();
	```
	Pops the top node from stack st2 and processes it.

18. **Pop from St2**
	```cpp
	            st2.pop();
	```
	Removes the processed node from stack st2.

19. **Add Value to Result**
	```cpp
	            res.push_back(root2->val);
	```
	Adds the value of the current node from tree 2 to the result vector.

20. **Move to Right Child - Root2**
	```cpp
	            root2 = root2->right;
	```
	Moves to the right child of the current node in tree 2.

21. **Return Result**
	```cpp
	    return res;
	```
	Returns the sorted result vector containing all elements from both trees.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) - If both trees are balanced, the traversal and merging will take linear time.
- **Average Case:** O(n) - The traversal and merging will always take linear time relative to the total number of nodes.
- **Worst Case:** O(n) - The worst case occurs when the trees are skewed, but the time complexity remains linear in terms of node count.

The time complexity is O(n), where n is the total number of nodes in both trees.

### Space Complexity 💾
- **Best Case:** O(h) - Even in the best case, the space complexity is determined by the height of the trees.
- **Worst Case:** O(h) - The space complexity is O(h) where h is the height of the taller tree due to the stack space used during traversal.

The space complexity is O(h), where h is the height of the taller tree.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/)

---
{{< youtube B97Hk1H2x2s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
