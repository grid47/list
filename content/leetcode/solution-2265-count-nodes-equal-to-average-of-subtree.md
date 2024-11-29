
+++
authors = ["grid47"]
title = "Leetcode 2265: Count Nodes Equal to Average of Subtree"
date = "2024-03-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2265: Count Nodes Equal to Average of Subtree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "yg9A3yLTcsE"
youtube_upload_date="2022-05-08"
youtube_thumbnail="https://i.ytimg.com/vi_webp/yg9A3yLTcsE/maxresdefault.webp"
comments = true
+++



---
You are given the root of a binary tree. Your task is to return the number of nodes where the value of the node is equal to the average of the values in its entire subtree (including the node itself). The average of a set of values is the sum of the values divided by the number of values, rounded down to the nearest integer.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is the root of a binary tree where each node contains an integer value.
- **Example:** `root = [3, 9, 20, null, null, 15, 7]`
- **Constraints:**
	- The number of nodes in the tree is between 1 and 1000.
	- Node values are between 0 and 1000.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the count of nodes that satisfy the condition of having their value equal to the average of the values in their respective subtree.
- **Example:** `Output: 3`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to traverse the binary tree and calculate the sum and count of nodes for each subtree, comparing each node's value to the average of its subtree.

- Recursively calculate the sum and count of nodes for each subtree starting from the root.
- For each node, check if its value matches the average of its subtree (rounded down).
- Count the number of nodes that satisfy the condition.
{{< dots >}}
### Problem Assumptions ✅
- The binary tree is non-empty, with a size of at least 1 node.
{{< dots >}}
## Examples 🧩
- **Input:** `root = [3, 9, 20, null, null, 15, 7]`  \
  **Explanation:** For the node with value 3: The average of its subtree is (3 + 9 + 20 + 15 + 7) / 5 = 54 / 5 = 10, which is not equal to 3.
For the node with value 9: The average of its subtree is 9 / 1 = 9, which is equal to 9.
For the node with value 20: The average of its subtree is (20 + 15 + 7) / 3 = 42 / 3 = 14, which is not equal to 20.
Thus, 2 nodes satisfy the condition (9 and 15). The result is 3.

- **Input:** `root = [1]`  \
  **Explanation:** For the node with value 1: The average of its subtree is 1 / 1 = 1, which is equal to 1. The result is 1.

{{< dots >}}
## Approach 🚀
We will use a recursive approach to traverse the binary tree. For each node, we will calculate the sum and the number of nodes in its subtree. If the node's value equals the average of its subtree, we will increment the result counter.

### Initial Thoughts 💭
- We need to calculate the sum and node count for each subtree recursively.
- The main challenge is ensuring that we compare each node's value to the average of its subtree, which involves both sum and count.
- Using recursion allows us to explore each node's subtree and compute the required values in a natural and straightforward manner.
{{< dots >}}
### Edge Cases 🌐
- The input tree will not be empty, as the minimum number of nodes is 1.
- The algorithm should efficiently handle up to 1000 nodes in the tree.
- Consider trees with all nodes having the same value, or with extreme values like 0 or 1000.
- The solution should work within the given constraints, ensuring that it efficiently handles trees with 1000 nodes.
{{< dots >}}
## Code 💻
```cpp
int ans = 0;
pair<int,int> solve(TreeNode* root){
    if(root==NULL) return {0,0};
    
    auto left = solve(root->left);
    int l_sum = left.first; // sum of nodes present in left sub tree
    int l_cnt = left.second; // no. of nodes present in left sub tree
    
    auto right = solve(root->right);
    int r_sum = right.first; // sum of nodes present in right sub tree
    int r_cnt = right.second; // no. of nodes present in left sub tree
    
    int sum = root->val + l_sum + r_sum;
    int cnt = l_cnt + r_cnt + 1;
    
    if(root->val == sum/cnt) ans++;
    return {sum,cnt};
}
int averageOfSubtree(TreeNode* root) {
    solve(root);
    return ans;
}
```

This solution calculates the number of nodes in a binary tree where the value of the node equals the average of its subtree. It uses a recursive approach to traverse the tree and computes the sum and count of nodes in each subtree.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int ans = 0;
	```
	The variable `ans` is initialized to 0, which will store the count of nodes whose value equals the average of their subtree.

2. **Recursive Function Declaration**
	```cpp
	pair<int,int> solve(TreeNode* root){
	```
	The function `solve` is a recursive helper function that computes the sum and count of nodes in a subtree. It returns a pair of integers: the sum of node values and the count of nodes in the subtree.

3. **Base Case**
	```cpp
	    if(root==NULL) return {0,0};
	```
	This is the base case of the recursion. If the current node is NULL, it returns a pair of zeros, indicating no nodes and no sum in the subtree.

4. **Recursive Call - Left Subtree**
	```cpp
	    auto left = solve(root->left);
	```
	This recursive call calculates the sum and count of nodes in the left subtree of the current node.

5. **Left Subtree Sum**
	```cpp
	    int l_sum = left.first; // sum of nodes present in left sub tree
	```
	The sum of the nodes in the left subtree is stored in `l_sum`.

6. **Left Subtree Node Count**
	```cpp
	    int l_cnt = left.second; // no. of nodes present in left sub tree
	```
	The number of nodes in the left subtree is stored in `l_cnt`.

7. **Recursive Call - Right Subtree**
	```cpp
	    auto right = solve(root->right);
	```
	This recursive call calculates the sum and count of nodes in the right subtree of the current node.

8. **Right Subtree Sum**
	```cpp
	    int r_sum = right.first; // sum of nodes present in right sub tree
	```
	The sum of the nodes in the right subtree is stored in `r_sum`.

9. **Right Subtree Node Count**
	```cpp
	    int r_cnt = right.second; // no. of nodes present in left sub tree
	```
	The number of nodes in the right subtree is stored in `r_cnt`.

10. **Current Node Sum and Count**
	```cpp
	    int sum = root->val + l_sum + r_sum;
	```
	The sum of the current node's value, the sum of its left subtree, and the sum of its right subtree is calculated and stored in `sum`.

11. **Total Node Count**
	```cpp
	    int cnt = l_cnt + r_cnt + 1;
	```
	The total number of nodes in the current subtree is the sum of the nodes in the left subtree, the nodes in the right subtree, and the current node itself, stored in `cnt`.

12. **Check Average Condition**
	```cpp
	    if(root->val == sum/cnt) ans++;
	```
	If the value of the current node equals the average of its subtree (calculated as `sum/cnt`), the counter `ans` is incremented.

13. **Return Subtree Sum and Count**
	```cpp
	    return {sum,cnt};
	```
	The function returns the sum and count of nodes in the current subtree as a pair.

14. **Main Function Declaration**
	```cpp
	int averageOfSubtree(TreeNode* root) {
	```
	The function `averageOfSubtree` takes the root of the binary tree as input and returns the count of nodes whose value equals the average of their respective subtrees.

15. **Call Recursive Function**
	```cpp
	    solve(root);
	```
	The recursive function `solve` is called to traverse the tree and compute the sum and count for each subtree.

16. **Return Final Answer**
	```cpp
	    return ans;
	```
	The function returns the final count of nodes that satisfy the condition, stored in the variable `ans`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we visit each node once to calculate the sum and count of its subtree.

### Space Complexity 💾
- **Best Case:** O(h)
- **Worst Case:** O(h)

The space complexity is O(h), where h is the height of the tree. This is due to the recursion stack used for tree traversal.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/)

---
{{< youtube yg9A3yLTcsE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
