
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
+++



---
**Code:**

{{< highlight cpp >}}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
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
    
};
{{< /highlight >}}
---

### Problem Statement

The task is to count the number of good leaf node pairs in a binary tree. A pair of leaf nodes is considered "good" if their distance (the number of edges between them) is less than or equal to a given distance `dist`. The function should return the total count of such good leaf pairs.

### Approach

To solve this problem, we will use a depth-first search (DFS) approach. The key idea is to traverse the binary tree and, at each node, collect the distances of its leaf nodes. We will maintain a count of how many leaf nodes are at each distance from the current node. For every pair of distances from the left and right subtrees, we will check if their sum is less than or equal to `dist`. If it is, we add to our total count of good leaf pairs.

Here's a breakdown of the approach:

1. **DFS Traversal**: We perform a DFS starting from the root of the tree. At each node, we will compute the counts of leaf nodes at different distances.
  
2. **Base Cases**:
   - If the current node is `NULL`, we return a vector initialized to zero counts for each distance.
   - If the current node is a leaf (both left and right children are `NULL`), we return a vector with the count of leaf nodes at distance 1 (the current leaf).

3. **Count Pairs**:
   - For every node, we combine the results from its left and right subtrees to count good leaf pairs. We do this by iterating through all possible distances from the left and right subtrees and checking if their sum is within the allowed distance `dist`.

4. **Result Compilation**: We compile the results into a vector that holds the counts of leaf nodes at each distance and return this vector to the parent call.

### Code Breakdown (Step by Step)

Here's the provided code explained step by step:

```cpp
class Solution {
public:
    int ans = 0;  // To store the total count of good leaf pairs

    int countPairs(TreeNode* root, int dist) {
        dfs(root, dist);  // Start DFS from the root
        return ans;  // Return the total count
    }
```
- We define a class `Solution` with a public method `countPairs` that initializes the DFS traversal.
- We maintain a variable `ans` to count the number of good leaf pairs.

```cpp
    vector<int> dfs(TreeNode* root, int dist) {
        if(!root) {
            vector<int> res(dist + 1, 0);  // Return a zeroed vector for a null node
            return res;
        }
```
- The `dfs` function takes the current node and the maximum distance as arguments.
- If the current node is `NULL`, we return a zeroed vector of size `dist + 1`.

```cpp
        if(root->left == NULL && root->right == NULL) {
            vector<int> res(dist + 1, 0);  // For a leaf node
            res[1]++;  // There is one leaf at distance 1
            return res;
        }
```
- If we encounter a leaf node, we create a vector `res` initialized to zero and increment the count of leaf nodes at distance 1 before returning it.

```cpp
        vector<int> left = dfs(root->left, dist);  // Recur for left subtree
        vector<int> right = dfs(root->right, dist);  // Recur for right subtree
```
- We recursively call `dfs` on the left and right children of the current node, storing the results in vectors `left` and `right`.

```cpp
        for(int i = 1; i <= dist - 1; i++) {
            for(int j = dist - 1; j >= 1; j--) {
                if(i + j <= dist)
                    ans += left[i] * right[j];  // Count good pairs
            }
        }
```
- Here, we iterate through the counts of leaf nodes from both subtrees.
- For every combination of distances from the left (`i`) and right (`j`), we check if their sum is less than or equal to `dist`. If it is, we update `ans` by multiplying the counts from both sides.

```cpp
        vector<int> res(dist + 1, 0);  // Prepare result vector for current node
        for(int i = 1; i <= dist - 2; i++ ) {
            res[i + 1] = left[i] + right[i];  // Combine counts of leaf nodes at distances
        }
        return res;  // Return the counts to parent call
    }
};
```
- We prepare a result vector `res` to store counts of leaf nodes at each distance from the current node.
- We populate this vector based on the counts from the left and right subtrees and return it to the parent call.

### Complexity

#### Time Complexity
- The time complexity of this algorithm is \(O(N \cdot D)\), where \(N\) is the number of nodes in the tree, and \(D\) is the maximum distance (or depth) we are considering. Each node may contribute to pair counts based on its distance from the leaf nodes in its subtrees.

#### Space Complexity
- The space complexity is \(O(D)\) due to the recursive stack and the vectors used to store counts of leaf nodes at different distances. In the worst case, this could be proportional to the depth of the tree.

### Conclusion

This solution efficiently counts good leaf node pairs in a binary tree using a recursive depth-first search approach. By collecting leaf node counts at various distances from each node and then combining these counts appropriately, we can achieve the desired result. This method is particularly effective due to its straightforward recursive structure, making it easy to implement and understand.

**Key Takeaways**:
- **Recursive DFS Traversal**: Utilizing recursion allows for an elegant and clear traversal of the binary tree.
- **Dynamic Counting**: The solution dynamically counts distances, enabling the efficient counting of good leaf pairs.
- **Handling Edge Cases**: The implementation correctly handles cases of leaf nodes and null nodes, ensuring robustness.

This approach is not only efficient but also serves as a good example of applying DFS in tree problems, which is a common technique in data structure and algorithm challenges.

[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/)

---
{{< youtube f_epkBeS1LQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
