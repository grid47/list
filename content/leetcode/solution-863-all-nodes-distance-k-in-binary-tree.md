
+++
authors = ["grid47"]
title = "Leetcode 863: All Nodes Distance K in Binary Tree"
date = "2024-08-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 863: All Nodes Distance K in Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "g1R3yEtHT8E"
youtube_upload_date="2021-02-02"
youtube_thumbnail="https://i.ytimg.com/vi/g1R3yEtHT8E/maxresdefault.jpg"
comments = true
+++



---
Given a binary tree, a target node within the tree, and a non-negative integer k, determine all the nodes that are exactly k edges away from the target node. Return these node values as a list in any order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input includes the root of a binary tree, a target node within the tree, and an integer k.
- **Example:** `root = [1,2,3,4,5,null,6], target = 2, k = 1`
- **Constraints:**
	- The binary tree has between 1 and 500 nodes.
	- All node values are unique and in the range [0, 500].
	- The target node is guaranteed to exist in the tree.
	- 0 <= k <= 1000.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of all node values that are k edges away from the target node.
- **Example:** `Output: [4, 5, 1]`
- **Constraints:**
	- Output can be in any order.
	- If no nodes are at distance k, return an empty list.

{{< dots >}}
### Core Logic 🔍
**Goal:** Identify all nodes exactly k edges away from the given target node in the binary tree.

- Store parent-child relationships of all nodes using a map.
- Perform a breadth-first search (BFS) or depth-first search (DFS) starting from the target node.
- Track visited nodes to avoid revisiting and looping.
- Stop the search when the depth equals k and collect the values of nodes at this depth.
{{< dots >}}
### Problem Assumptions ✅
- The binary tree is finite with no cyclic references.
- Node values are distinct.
- The tree includes the specified target node.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [1,2,3,4,5,null,6], target = 2, k = 1`  \
  **Explanation:** Nodes at distance 1 from target node 2 are nodes 4, 5, and 1. Output: [4, 5, 1].

- **Input:** `Input: root = [7], target = 7, k = 3`  \
  **Explanation:** The tree contains only one node, so no nodes are at distance 3. Output: [].

{{< dots >}}
## Approach 🚀
Use a combination of DFS to track parent-child relationships and BFS to find nodes at a specified distance.

### Initial Thoughts 💭
- The problem requires traversing the tree in both directions: parent-to-child and child-to-parent.
- Using BFS will efficiently find nodes at a specific distance.
- Start by mapping parent relationships for all nodes.
- Perform a level-order traversal (BFS) from the target node to collect nodes at the required depth.
{{< dots >}}
### Edge Cases 🌐
- Tree is empty (should not occur per constraints).
- Tree contains the maximum number of nodes, k is very large (e.g., k > tree height).
- Tree has only one node, k > 0.
- Ensure k = 0 returns the value of the target node.
{{< dots >}}
## Code 💻
```cpp
class Solution {
map<TreeNode*, TreeNode*> mp;
set<TreeNode*> st;
vector<int> ans;

void parents(TreeNode* node) {
    if(!node) return;
    if(node->left) {
        mp[node->left] = node;
        parents(node->left);
    }

    if(node->right) {
        mp[node->right] = node;
        parents(node->right);
    }
}
public:
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    if(!root) return {};
    parents(root);

    dfs(target, k);
    return ans;
}

void dfs(TreeNode* node, int k) {
    if(st.count(node)) return;
    st.insert(node);

    if(k == 0) {
        ans.push_back(node->val);
        return;
    }

    if(node->left) dfs(node->left, k - 1);
    if(node->right) dfs(node->right, k - 1);
    if(mp[node]) dfs(mp[node], k - 1);
}

```

This code defines a class Solution that finds all nodes at a distance k from a target node in a binary tree. It utilizes depth-first search (DFS) and a helper function for tracking parent nodes to traverse the tree.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class Solution {
	```
	Define the class 'Solution' to solve the problem of finding nodes at a distance 'k' from a target node in a binary tree.

2. **Variable Declaration**
	```cpp
	map<TreeNode*, TreeNode*> mp;
	```
	Declare a map 'mp' to store each node's parent node.

3. **Variable Declaration**
	```cpp
	set<TreeNode*> st;
	```
	Declare a set 'st' to track the visited nodes to avoid cycles.

4. **Variable Declaration**
	```cpp
	vector<int> ans;
	```
	Declare a vector 'ans' to store the values of nodes that are at a distance 'k' from the target.

5. **Method Definition**
	```cpp
	void parents(TreeNode* node) {
	```
	Define a helper method to traverse the tree and record each node's parent in the 'mp' map.

6. **Conditional Check**
	```cpp
	    if(!node) return;
	```
	Check if the current node is null. If so, return to prevent further traversal.

7. **Conditional Check**
	```cpp
	    if(node->left) {
	```
	Check if the current node has a left child.

8. **Map Operation**
	```cpp
	        mp[node->left] = node;
	```
	Store the left child and its parent in the 'mp' map.

9. **Recursive Call**
	```cpp
	        parents(node->left);
	```
	Recursively call the 'parents' method on the left child.

10. **Conditional Check**
	```cpp
	    if(node->right) {
	```
	Check if the current node has a right child.

11. **Map Operation**
	```cpp
	        mp[node->right] = node;
	```
	Store the right child and its parent in the 'mp' map.

12. **Recursive Call**
	```cpp
	        parents(node->right);
	```
	Recursively call the 'parents' method on the right child.

13. **Public Method**
	```cpp
	public:
	```
	Declare the following methods as public members of the class.

14. **Method Definition**
	```cpp
	vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
	```
	Define the main method 'distanceK' that returns the values of nodes at a distance 'k' from the target.

15. **Base Case Check**
	```cpp
	    if(!root) return {};
	```
	Check if the root node is null, and if so, return an empty vector.

16. **Helper Method Call**
	```cpp
	    parents(root);
	```
	Call the 'parents' method to record the parent-child relationships.

17. **DFS Call**
	```cpp
	    dfs(target, k);
	```
	Call the 'dfs' method to perform depth-first search and find all nodes at distance 'k' from the target.

18. **Return Statement**
	```cpp
	    return ans;
	```
	Return the 'ans' vector containing the values of nodes at the specified distance.

19. **Method Definition**
	```cpp
	void dfs(TreeNode* node, int k) {
	```
	Define the 'dfs' method to perform a depth-first search on the tree.

20. **Set Check**
	```cpp
	    if(st.count(node)) return;
	```
	Check if the node has already been visited by checking the 'st' set. If yes, return to avoid processing it again.

21. **Set Operation**
	```cpp
	    st.insert(node);
	```
	Add the node to the 'st' set to mark it as visited.

22. **Base Case Check**
	```cpp
	    if(k == 0) {
	```
	Check if the current depth 'k' is zero.

23. **Action on Base Case**
	```cpp
	        ans.push_back(node->val);
	```
	If 'k' is zero, add the node's value to the 'ans' vector.

24. **Return Statement**
	```cpp
	        return;
	```
	Return to exit the current function call once the node's value is added to 'ans'.

25. **Closing Brace**
	```cpp
	    }
	```
	End the block for the base case check.

26. **Recursive DFS Calls**
	```cpp
	    if(node->left) dfs(node->left, k - 1);
	```
	If the node has a left child, recursively call 'dfs' on the left child with a reduced value of 'k'.

27. **Recursive DFS Calls**
	```cpp
	    if(node->right) dfs(node->right, k - 1);
	```
	If the node has a right child, recursively call 'dfs' on the right child with a reduced value of 'k'.

28. **Recursive DFS Call**
	```cpp
	    if(mp[node]) dfs(mp[node], k - 1);
	```
	If a parent node exists in the 'mp' map, recursively call 'dfs' on the parent with a reduced value of 'k'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(N), where N is the number of nodes in the tree.
- **Average Case:** O(N), since each node and edge is visited once.
- **Worst Case:** O(N), if k equals the tree height or the tree is skewed.

The complexity is dominated by traversing the tree and performing BFS.

### Space Complexity 💾
- **Best Case:** O(1), if only the target node exists.
- **Worst Case:** O(N), due to the parent map and BFS queue.

Space usage depends on the map for parent references and BFS queue.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/)

---
{{< youtube g1R3yEtHT8E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
