
+++
authors = ["grid47"]
title = "Leetcode 1530: Number of Good Leaf Nodes Pairs"
date = "2024-06-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1530: Number of Good Leaf Nodes Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "f_epkBeS1LQ"
youtube_upload_date="2024-07-18"
youtube_thumbnail="https://i.ytimg.com/vi/f_epkBeS1LQ/maxresdefault.jpg"
comments = true
+++



---
You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes is considered good if the shortest path between them is less than or equal to the given distance. The task is to return the number of such good leaf node pairs in the tree.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary tree with nodes containing integer values, and an integer distance.
- **Example:** `root = [1, 2, 3, null, 4], distance = 3`
- **Constraints:**
	- 1 <= Node.val <= 100
	- 1 <= distance <= 10
	- The number of nodes in the tree is in the range [1, 210].

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of good leaf node pairs in the tree, where the shortest path between the pair is less than or equal to the given distance.
- **Example:** `For root = [1, 2, 3, null, 4] and distance = 3, the output is 1.`
- **Constraints:**
	- The output is the number of good leaf node pairs in the tree.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to count the good leaf node pairs in the binary tree.

- Traverse the tree and for each leaf node, calculate the distance to other leaf nodes.
- For each pair of leaf nodes, check if the distance between them is less than or equal to the given distance.
- Count the number of such pairs.
{{< dots >}}
### Problem Assumptions ✅
- The tree contains at least one node.
- The leaf nodes are at the deepest levels of the tree.
{{< dots >}}
## Examples 🧩
- **Input:** `root = [1, 2, 3, null, 4], distance = 3`  \
  **Explanation:** The leaf nodes 3 and 4 are the only good pair, as the shortest path between them is 3.

- **Input:** `root = [1, 2, 3, 4, 5, 6, 7], distance = 3`  \
  **Explanation:** The good pairs are [4, 5] and [6, 7] with shortest path 2. Pair [4, 6] is not good due to a distance of 4.

{{< dots >}}
## Approach 🚀
To solve the problem, a depth-first search (DFS) approach can be used to traverse the tree and calculate distances between leaf nodes.

### Initial Thoughts 💭
- We need to calculate the shortest paths between pairs of leaf nodes.
- Using DFS, we can explore the tree and collect the depths of leaf nodes, then compare the distances between them.
{{< dots >}}
### Edge Cases 🌐
- No empty tree inputs as the tree contains at least one node.
- Ensure the solution works efficiently for trees with up to 210 nodes.
- Handle trees with only one leaf node.
- The tree structure should be a valid binary tree.
{{< dots >}}
## Code 💻
```cpp
int ans = 0;
int countPairs(TreeNode* root, int dist) {
    dfs(root, dist);
    return ans;
}

vector<int> dfs(TreeNode* root, int dist) {
    if(!root) {
        vector<int> res(dist + 1, 0);
        return res;
    }
    
    if(root->left == NULL && root->right == NULL) {
        vector<int> res(dist + 1, 0);
        res[1]++;
        return res;
    }
    vector<int> left = dfs(root->left, dist);
    vector<int> right = dfs(root->right, dist);
    for(int i = 1; i <= dist - 1; i++) {
        for(int j = dist - 1; j >= 1; j--) {
            if(i + j <= dist)
            ans += left[i] * right[j];
        }
    }
    vector<int> res(dist + 1, 0);
    for(int i = 1; i <= dist - 2; i++ ) {
        res[i + 1] = left[i] + right[i];
    }
    return res;
}

```

The `countPairs` function calculates the number of good leaf node pairs in a binary tree. The `dfs` function is a depth-first search that recursively traverses the tree, calculates distances for each subtree, and counts the pairs that satisfy the distance constraint.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int ans = 0;
	```
	The variable `ans` is initialized to zero. This will store the total number of valid leaf node pairs that satisfy the distance condition.

2. **Function Declaration**
	```cpp
	int countPairs(TreeNode* root, int dist) {
	```
	This is the declaration of the `countPairs` function. It takes a pointer to the root of the binary tree and the maximum allowed distance between the leaf nodes and returns the number of valid leaf node pairs.

3. **DFS Call**
	```cpp
	    dfs(root, dist);
	```
	The `dfs` function is called to traverse the tree and calculate the distances for each node. It also counts the pairs that meet the distance constraint.

4. **Return Result**
	```cpp
	    return ans;
	```
	After the traversal, the total count of valid leaf node pairs is returned.

5. **DFS Function Declaration**
	```cpp
	vector<int> dfs(TreeNode* root, int dist) {
	```
	This is the declaration of the `dfs` function. It takes a pointer to the current tree node and the maximum allowed distance and returns a vector of integers representing the counts of leaf nodes at each distance.

6. **Base Case for Null Node**
	```cpp
	    if(!root) {
	```
	If the current node is null, an empty vector with `dist + 1` elements, all set to zero, is returned. This serves as the base case for the recursion.

7. **Initialize Result Vector**
	```cpp
	        vector<int> res(dist + 1, 0);
	```
	A vector `res` of size `dist + 1` is initialized with zeros. This vector will store the count of leaf nodes at each distance.

8. **Return Result for Null Node**
	```cpp
	        return res;
	```
	The function returns the initialized result vector when the node is null.

9. **Leaf Node Check**
	```cpp
	    if(root->left == NULL && root->right == NULL) {
	```
	If the current node is a leaf node (both left and right children are null), the function proceeds to count it as a valid leaf node at distance 1.

10. **Initialize Leaf Result**
	```cpp
	        vector<int> res(dist + 1, 0);
	```
	A new result vector `res` is initialized to store the count of leaf nodes at each distance for the current leaf node.

11. **Increment Leaf Distance**
	```cpp
	        res[1]++;
	```
	Since this is a leaf node, the count for distance 1 is incremented by 1.

12. **Return Leaf Node Result**
	```cpp
	        return res;
	```
	The result vector is returned for the leaf node.

13. **Recursive DFS Call for Left Subtree**
	```cpp
	    vector<int> left = dfs(root->left, dist);
	```
	The `dfs` function is recursively called for the left subtree of the current node, and the result is stored in the vector `left`.

14. **Recursive DFS Call for Right Subtree**
	```cpp
	    vector<int> right = dfs(root->right, dist);
	```
	The `dfs` function is recursively called for the right subtree of the current node, and the result is stored in the vector `right`.

15. **Pair Count Calculation**
	```cpp
	    for(int i = 1; i <= dist - 1; i++) {
	```
	This loop iterates through possible distances from the left subtree.

16. **Nested Pair Count Calculation**
	```cpp
	        for(int j = dist - 1; j >= 1; j--) {
	```
	This nested loop iterates through possible distances from the right subtree.

17. **Add Valid Pairs to Answer**
	```cpp
	            if(i + j <= dist)
	```
	If the sum of the current distances from both subtrees is less than or equal to the maximum distance `dist`, the product of the counts of nodes at these distances is added to the `ans` variable.

18. **Increment Answer with Pairs**
	```cpp
	            ans += left[i] * right[j];
	```
	The result from the pair calculation is added to the global `ans` variable.

19. **Initialize Result Vector for Distances**
	```cpp
	    vector<int> res(dist + 1, 0);
	```
	A new result vector `res` is initialized to store the updated counts of leaf nodes at each distance after processing both subtrees.

20. **Combine Left and Right Subtree Results**
	```cpp
	    for(int i = 1; i <= dist - 2; i++ ) {
	```
	This loop combines the results from the left and right subtrees for each distance.

21. **Update Combined Result Vector**
	```cpp
	        res[i + 1] = left[i] + right[i];
	```
	The count for each distance is updated by adding the counts from the left and right subtrees.

22. **Return Combined Result**
	```cpp
	    return res;
	```
	The combined result vector, representing the updated counts of leaf nodes at each distance, is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n^2)

The worst-case time complexity is O(n^2) when comparing all pairs of leaf nodes.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the recursive DFS stack and storing leaf nodes.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/)

---
{{< youtube f_epkBeS1LQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
