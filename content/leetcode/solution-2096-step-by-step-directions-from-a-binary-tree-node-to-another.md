
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:

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
};
{{< /highlight >}}
---

### Problem Statement

The problem requires finding the path between two nodes in a binary tree, given the values of the two nodes. The path is defined by directions: "L" for left, "R" for right, and "U" for moving up to the parent node. The objective is to return a string that represents the path from the start node to the destination node, including any necessary moves up the tree to reach a common ancestor before proceeding down to the destination node.

### Approach

To solve this problem, we will take the following steps:

1. **Traverse the Tree**: We need to locate both the start node and the destination node in the binary tree. This can be accomplished through a depth-first search (DFS) that explores the tree recursively.

2. **Record Paths**: As we traverse the tree, we will build paths for both the start and destination nodes. We will store these paths in strings (`sp` for the start node and `dp` for the destination node) where each character represents a direction taken during the traversal.

3. **Identify the Lowest Common Ancestor (LCA)**: After obtaining both paths, we need to determine the point where the two paths diverge. This point will indicate the lowest common ancestor of the two nodes. We will do this by comparing the characters in both strings from the end until they differ.

4. **Construct the Final Path**: Once the divergence point is found, the final path from the start node to the destination node will consist of moving up to the LCA (using 'U' for each move) followed by moving down to the destination node (using the characters from the path to the destination node).

5. **Return the Result**: The final path string will be returned as the output.

This approach efficiently handles the tree traversal and path construction using simple recursion, yielding a clean solution to the problem.

### Code Breakdown (Step by Step)

Let’s break down the provided code to understand how it implements the above approach:

1. **TreeNode Structure**:
   ```cpp
   struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   };
   ```
   The `TreeNode` struct defines a node in the binary tree, containing an integer value (`val`) and pointers to the left and right child nodes.

2. **Solution Class**:
   ```cpp
   class Solution {
   public:
   ```

3. **Find Function**:
   ```cpp
       bool find(TreeNode* n, int val, string &path) {
           if(n->val == val) return true;
           if (n->left && find(n->left, val, path)) path.push_back('L');
           else if (n->right && find(n->right, val, path)) path.push_back('R');
           return !path.empty();
       }
   ```
   - The `find` function is a helper function that searches for a node with the specified value (`val`) starting from the current node (`n`).
   - If the current node's value matches `val`, the function returns `true`.
   - If not, the function checks the left and right children recursively.
   - If a node is found in either subtree, it appends 'L' or 'R' to the `path` string to record the direction taken.
   - The function returns `true` if a path was found and updates the `path` string accordingly.

4. **Get Directions Function**:
   ```cpp
       string getDirections(TreeNode* root, int startValue, int destValue) {
           string sp, dp;
           find(root, startValue, sp);
           find(root, destValue, dp);
   ```
   - The `getDirections` function initializes two strings, `sp` and `dp`, to store the paths to the start and destination nodes, respectively.
   - It calls the `find` function twice to populate these paths.

5. **Identifying the Lowest Common Ancestor (LCA)**:
   ```cpp
           while(!sp.empty() && !dp.empty() && sp.back() == dp.back()) {
               sp.pop_back();
               dp.pop_back();
           }
   ```
   - This while loop continues as long as the last characters of both path strings are equal, indicating that both paths are still moving up the tree towards the common ancestor.
   - When the characters differ, it means we have reached the divergence point. The remaining characters in `sp` will represent the moves up to the LCA, while `dp` will contain the moves down to the destination node.

6. **Constructing the Final Path**:
   ```cpp
           return string(sp.size(), 'U') + string(rbegin(dp), rend(dp));
       }
   };
   ```
   - The final string is constructed by creating a string of 'U' characters for the number of moves needed to reach the LCA from the start node (`sp.size()`).
   - It then appends the reversed path from the LCA to the destination node (`dp`), using `rbegin` and `rend` to reverse the order of the characters.
   - The complete path string is returned as the output of the function.

### Complexity

The time complexity of this solution is O(n), where `n` is the number of nodes in the binary tree. This complexity arises from the need to traverse the tree potentially twice (once for each node). The space complexity is O(h), where `h` is the height of the tree, which accounts for the recursion stack used during the depth-first search.

### Conclusion

In conclusion, the solution effectively determines the path between two nodes in a binary tree by leveraging depth-first search to find paths to both nodes and subsequently identifying their lowest common ancestor. This approach is both efficient and straightforward, providing a clear method for navigating binary trees. Understanding how to construct paths and manage tree traversals is crucial for solving similar problems in data structures and algorithms, making this solution an important technique for developers and computer scientists.

[`Link to LeetCode Lab`](https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/)

---
{{< youtube JegJNGcwtFg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
