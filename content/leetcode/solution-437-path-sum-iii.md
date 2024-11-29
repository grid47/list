
+++
authors = ["grid47"]
title = "Leetcode 437: Path Sum III"
date = "2024-09-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 437: Path Sum III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/437.webp"
youtube = "Vam9gldRapY"
youtube_upload_date="2020-08-08"
youtube_thumbnail="https://i.ytimg.com/vi/Vam9gldRapY/hqdefault.jpg?sqp=-oaymwEmCOADEOgC8quKqQMa8AEB-AHUBoAC4AOKAgwIABABGGIgZSgsMA8=&rs=AOn4CLByu4Pnq9YHL4GumLlrHVQp65TWqQ"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/437.webp" 
    alt="A tree with nodes lighting up, showing the path sum from a root node to the leaves, highlighting valid paths."
    caption="Solution to LeetCode 437: Path Sum III Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given the root of a binary tree and an integer targetSum. Your task is to count the total number of paths in the tree where the sum of node values along the path equals targetSum. The path does not need to start or end at the root or a leaf, but it must go downwards (from parent to child nodes).
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary tree represented by the root node and an integer targetSum.
- **Example:** `root = [3, 5, -2, 3, 1, null, 4], targetSum = 7`
- **Constraints:**
	- 1 <= number of nodes <= 1000
	- -10^9 <= Node.val <= 10^9
	- -1000 <= targetSum <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of paths in the tree that sum to targetSum.
- **Example:** `2`
- **Constraints:**
	- The output should be a non-negative integer representing the number of valid paths.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to count the number of paths that sum to targetSum while only moving downwards in the tree.

- 1. Perform a Depth-First Search (DFS) traversal of the tree.
- 2. For each node, calculate the sum for all paths starting from that node.
- 3. Recursively check all possible paths for the sum matching the targetSum.
{{< dots >}}
### Problem Assumptions ✅
- The input tree is a valid binary tree.
- The tree is not necessarily balanced.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: [3, 5, -2, 3, 1, null, 4], targetSum = 7`  \
  **Explanation:** There are two paths in the tree that sum to 7: `5 -> 3 -> -2` and `3 -> 1 -> 4`.

- **Input:** `Input: [10, 5, -3, 3, 2, null, 11, 3, -2, null, 1], targetSum = 8`  \
  **Explanation:** The three paths that sum to 8 are: `5 -> 3`, `5 -> 2 -> 1`, and `-3 -> 11`.

{{< dots >}}
## Approach 🚀
The approach uses DFS to explore all possible paths in the binary tree and checks whether the sum of the values along the path equals targetSum.

### Initial Thoughts 💭
- DFS is a suitable approach to explore all potential paths in a binary tree.
- We need to perform DFS starting from each node to explore all paths from that node downwards.
{{< dots >}}
### Edge Cases 🌐
- If the tree is empty (i.e., root is null), return 0.
- Ensure that the algorithm works efficiently for trees with up to 1000 nodes.
- If targetSum is 0, consider paths where the sum of values along the path equals 0.
- Handle large integer values within the specified range of [-10^9, 10^9].
{{< dots >}}
## Code 💻
```cpp
class Solution {
int cnt = 0;
public:
int pathSum(TreeNode* root, int sum) {
    dfs(root, sum);
    return cnt;
}

void dfs(TreeNode* root, long sum) {
    if(root == NULL) return;

    test(root, sum);
    dfs(root->left,  sum);
    dfs(root->right, sum);

}

void test(TreeNode* root, long sum) {
    if  (root     == NULL) return;
    if  (root->val == sum ) cnt++;
    test(root->left,  sum - root->val);
    test(root->right, sum - root->val);
}
```

This implementation calculates the number of paths in a binary tree that sum to a given value using depth-first search (DFS). The 'test' function explores all paths starting from a given node.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Declaration**
	```cpp
	class Solution {
	```
	Declares the Solution class where the methods and variables are defined.

2. **Variable Declaration**
	```cpp
	int cnt = 0;
	```
	Initializes a counter to store the number of valid paths with the desired sum.

3. **Access Specifier**
	```cpp
	public:
	```
	Defines the public section of the class to include accessible methods.

4. **Function Declarations And Calls**
	```cpp
	int pathSum(TreeNode* root, int sum) {
	```
	Declares the main function to calculate the total number of paths that sum to a target value.

5. **Recursive Call**
	```cpp
	    dfs(root, sum);
	```
	Calls the helper function 'dfs' to traverse the tree starting from the root node.

6. **Return At End**
	```cpp
	    return cnt;
	```
	Returns the total count of paths with the desired sum.

7. **Recursive Function Definition**
	```cpp
	void dfs(TreeNode* root, long sum) {
	```
	Defines the DFS function to traverse the binary tree and test each node for valid paths.

8. **Base Condition**
	```cpp
	    if(root == NULL) return;
	```
	Checks if the current node is null to terminate the recursion.

9. **Function Call**
	```cpp
	    test(root, sum);
	```
	Calls the 'test' function to check paths starting from the current node.

10. **Recursive Call**
	```cpp
	    dfs(root->left,  sum);
	```
	Recursively calls 'dfs' for the left child of the current node.

11. **Recursive Call**
	```cpp
	    dfs(root->right, sum);
	```
	Recursively calls 'dfs' for the right child of the current node.

12. **Recursive Function Definition**
	```cpp
	void test(TreeNode* root, long sum) {
	```
	Defines the 'test' function to check all paths starting at the current node for the target sum.

13. **Base Condition**
	```cpp
	    if  (root     == NULL) return;
	```
	Terminates the recursion when the node is null.

14. **Conditional Checks**
	```cpp
	    if  (root->val == sum ) cnt++;
	```
	Increments the counter if the current node value equals the remaining sum.

15. **Recursive Call**
	```cpp
	    test(root->left,  sum - root->val);
	```
	Recursively checks the left subtree for paths with the updated remaining sum.

16. **Recursive Call**
	```cpp
	    test(root->right, sum - root->val);
	```
	Recursively checks the right subtree for paths with the updated remaining sum.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(N), where N is the number of nodes in the tree, if all paths meet the targetSum immediately.
- **Average Case:** O(N^2), where N is the number of nodes, due to the DFS for each node and the exploration of all paths.
- **Worst Case:** O(N^2), where N is the number of nodes, as every node can lead to a path traversal that checks all remaining nodes.

The time complexity involves performing DFS and recursively checking all paths from each node, leading to an overall complexity of O(N^2).

### Space Complexity 💾
- **Best Case:** O(H), for the recursive stack space.
- **Worst Case:** O(H), where H is the height of the tree, due to the recursion stack in DFS.

The space complexity is determined by the recursion depth of the DFS traversal.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/path-sum-iii/description/)

---
{{< youtube Vam9gldRapY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
