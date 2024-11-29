
+++
authors = ["grid47"]
title = "Leetcode 2049: Count Nodes With the Highest Score"
date = "2024-04-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2049: Count Nodes With the Highest Score in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "4sOMPJvDX_o"
youtube_upload_date="2021-10-24"
youtube_thumbnail="https://i.ytimg.com/vi/4sOMPJvDX_o/maxresdefault.jpg"
comments = true
+++



---
You are given a binary tree with n nodes, where each node is labeled from 0 to n-1. The tree is represented by a 0-indexed array `parents`, where `parents[i]` indicates the parent of node `i`. The root node has no parent, so `parents[0] == -1`.

Each node has a score, calculated as follows:
1. If the node and the edges connected to it are removed, the tree splits into one or more non-empty subtrees.
2. The score of a node is the product of the sizes of all resulting subtrees.

Return the number of nodes with the highest score in the tree.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An integer array `parents` of length `n`, representing the tree structure.
- **Example:** `Input: parents = [-1, 0, 0, 1, 1]`
- **Constraints:**
	- n == parents.length
	- 2 <= n <= 10^5
	- parents[0] == -1
	- 0 <= parents[i] <= n - 1 for i != 0
	- The tree represented by `parents` is valid.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer representing the count of nodes with the highest score.
- **Example:** `Output: 2`
- **Constraints:**
	- The output is a single integer between 1 and n.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine the number of nodes with the maximum score based on the given tree structure.

- Construct the tree using the `parents` array.
- Perform a post-order traversal to calculate the sizes of all subtrees.
- Calculate the score for each node by splitting the tree into subtrees.
- Keep track of the highest score and the count of nodes with that score.
{{< dots >}}
### Problem Assumptions ✅
- The input `parents` array represents a valid binary tree.
- The input is always well-formed, and `parents[0]` is always -1.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: parents = [-1, 0, 0, 1, 1]`  \
  **Explanation:** After removing each node, the highest score is 6, achieved by nodes 1 and 2. Output: 2.

- **Input:** `Input: parents = [-1, 0, 1]`  \
  **Explanation:** Node 0 splits the tree into two subtrees of size 2 and 1. Node 1 splits the tree into two subtrees of size 1 each. Both nodes 0 and 1 achieve the highest score of 2. Output: 2.

- **Input:** `Input: parents = [-1, 0, 0, 2, 2]`  \
  **Explanation:** Node 2 achieves the highest score of 6. Only node 2 has this score. Output: 1.

{{< dots >}}
## Approach 🚀
Utilize a combination of tree traversal and size calculations to determine scores for all nodes and track the highest score.

### Initial Thoughts 💭
- The problem requires efficient tree traversal to calculate scores for each node.
- The subtree sizes can be computed using post-order traversal.
- A post-order traversal will efficiently compute subtree sizes, and a second pass can calculate scores.
{{< dots >}}
### Edge Cases 🌐
- Not applicable, as n >= 2 is guaranteed.
- Handle cases where n is close to 10^5 to ensure the solution is efficient.
- Handle cases where the tree is a straight line (e.g., parents = [-1, 0, 1, 2, ...]).
- Handle cases where the tree is balanced with multiple nodes having the same score.
- Ensure calculations do not exceed the limit for integers.
{{< dots >}}
## Code 💻
```cpp
int countHighestScoreNodes(vector<int>& parents) {
    int n = parents.size();
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i++)
    g[parents[i]].push_back(i);

    vector<int> size(n, 0);
    helper(0, g, size);

    long long cnt = 0, maxi = 0;
    for(int i = 0; i < n; i++) {
        long long pro = 1;
        pro = max(pro, (long long) n - size[i]);
        for(int node : g[i]) {
            pro = pro * size[node];
        }

        if (pro > maxi) {
            maxi = pro;
            cnt = 1;
        }
        else if(pro == maxi) {
            cnt++;
        }
    }
    return cnt;
}

int helper(int src, vector<vector<int>> &gph, vector<int> &size) {
    int ans = 1;
    for(int g: gph[src])
        ans += helper(g, gph, size);
    return size[src] = ans;
}
```

This code defines a function that computes the highest score for each node in a tree structure and counts how many nodes have that highest score. It uses DFS to calculate the subtree sizes and then determines the product of the sizes of the subtrees to find the maximum product.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int countHighestScoreNodes(vector<int>& parents) {
	```
	Defines the function that takes in a vector of parent-child relationships to count the highest score nodes in a tree.

2. **Variable Initialization**
	```cpp
	    int n = parents.size();
	```
	Initializes the variable `n` to store the number of nodes in the tree (size of the `parents` vector).

3. **Data Structure Initialization**
	```cpp
	    vector<vector<int>> g(n);
	```
	Creates a 2D vector `g` to store the adjacency list representation of the tree.

4. **Graph Construction**
	```cpp
	    for(int i = 1; i < n; i++)
	```
	Iterates through the `parents` vector to construct the tree in the adjacency list `g`.

5. **Graph Construction**
	```cpp
	    g[parents[i]].push_back(i);
	```
	For each node, adds it as a child to its corresponding parent node in the adjacency list `g`.

6. **Variable Initialization**
	```cpp
	    vector<int> size(n, 0);
	```
	Initializes a vector `size` to store the size of each subtree, all set to 0 initially.

7. **Helper Function Call**
	```cpp
	    helper(0, g, size);
	```
	Calls the helper function with the root node (index 0) to calculate the size of each subtree in the tree.

8. **Variable Initialization**
	```cpp
	    long long cnt = 0, maxi = 0;
	```
	Initializes `cnt` to count the number of nodes with the highest score and `maxi` to store the maximum score.

9. **Iteration**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Loops through each node to calculate its score.

10. **Score Calculation**
	```cpp
	        long long pro = 1;
	```
	Initializes the variable `pro` to calculate the product of the sizes of the subtrees for each node.

11. **Score Calculation**
	```cpp
	        pro = max(pro, (long long) n - size[i]);
	```
	Calculates the product of the subtree sizes for each node, considering the size of the complementary subtree.

12. **Subtree Traversal**
	```cpp
	        for(int node : g[i]) {
	```
	Traverses each child node of the current node to calculate the product of the subtree sizes.

13. **Subtree Traversal**
	```cpp
	            pro = pro * size[node];
	```
	Multiplies the current product with the size of the child node's subtree.

14. **Score Comparison**
	```cpp
	        if (pro > maxi) {
	```
	If the current product (`pro`) is greater than the maximum score (`maxi`), updates the maximum score and resets the count.

15. **Score Comparison**
	```cpp
	            maxi = pro;
	```
	Sets the new maximum product score.

16. **Score Comparison**
	```cpp
	            cnt = 1;
	```
	Sets the count of nodes with the highest score to 1.

17. **Score Comparison**
	```cpp
	        else if(pro == maxi) {
	```
	If the current product (`pro`) equals the maximum score (`maxi`), increments the count.

18. **Score Comparison**
	```cpp
	            cnt++;
	```
	Increments the count of nodes with the maximum score.

19. **Return Statement**
	```cpp
	    return cnt;
	```
	Returns the count of nodes with the highest score.

20. **Helper Function Body**
	```cpp
	int helper(int src, vector<vector<int>> &gph, vector<int> &size) {
	```
	Defines the `helper` function that performs a DFS traversal to compute the size of each subtree.

21. **Recursive Call**
	```cpp
	    int ans = 1;
	```
	Initializes `ans` to 1, representing the current node itself in the subtree size calculation.

22. **Recursive Call**
	```cpp
	    for(int g: gph[src])
	```
	Loops through each child of the current node.

23. **Recursive Call**
	```cpp
	        ans += helper(g, gph, size);
	```
	Recursively calls the helper function for each child node to calculate the subtree size.

24. **Return Statement**
	```cpp
	    return size[src] = ans;
	```
	Stores the computed subtree size for the current node and returns it.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) for single traversal to compute subtree sizes.
- **Average Case:** O(n) for traversal and score calculation.
- **Worst Case:** O(n) for maximum node count and balanced tree structure.

The algorithm traverses the tree twice, making it linear in time complexity.

### Space Complexity 💾
- **Best Case:** O(n) for adjacency list alone in an iterative implementation.
- **Worst Case:** O(n) for adjacency list and recursive stack.

Space is determined by the adjacency list and recursion depth for post-order traversal.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-nodes-with-the-highest-score/description/)

---
{{< youtube 4sOMPJvDX_o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
