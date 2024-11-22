
+++
authors = ["grid47"]
title = "Leetcode 623: Add One Row to Tree"
date = "2024-09-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 623: Add One Row to Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/623.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/623.webp" 
    alt="A binary tree where a new row is being added, with the new row glowing as it is inserted."
    caption="Solution to LeetCode 623: Add One Row to Tree Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
    TreeNode* addOneRow(TreeNode* root, int val, int d) {
        if (d == 1) {
            TreeNode* newroot = new TreeNode(val);
            newroot->left = root;
            return newroot;
        }
        if (d == 0) {
            TreeNode* newroot = new TreeNode(val);
            newroot->right = root;
            return newroot;
        }

        if(!root) return nullptr;
        else if(d == 2) {
            root->left  = addOneRow(root->left, val, 1);
            root->right = addOneRow(root->right, val, 0);            
            return root;
        } else if(d > 2) {
            root->left  = addOneRow(root->left, val, d - 1);
            root->right = addOneRow(root->right, val,d - 1);            
        }
        return root;
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to add a new row of nodes with a specific value at a given depth in a binary tree. The depth is specified as `d`, and the node values of the new row are set to `val`. There are two possible scenarios:
1. The new row should be inserted at the specified depth `d`, meaning we need to add new nodes between existing nodes at the given depth.
2. If `d` is 1, the new row is inserted at the root level, making the new node the root of the tree.

This problem requires careful manipulation of the binary tree structure, ensuring that new nodes are added in the correct positions at the given depth.

### Approach

To solve the problem, we use a recursive depth-first search (DFS) approach. The basic idea is:
1. If the depth `d` is 1, insert a new root node and adjust the structure accordingly.
2. For any other depth `d`, recursively traverse the tree until we reach the desired depth, adding a new node at each level.
3. When the required depth is reached, we insert the new row by creating new nodes and adjusting the child pointers.

Here is the detailed step-by-step approach:

1. **Base Case - Depth 1:**
   If the given depth `d` is 1, the new row should be inserted at the root level. Therefore, a new node with the value `val` is created, and the current root becomes the left child of this new node. We return the new node as the new root of the tree.

2. **Base Case - Depth 0:**
   If the given depth `d` is 0, a new node is added as the rightmost child of the root.

3. **Recursive Case - For Depths Greater Than 1:**
   For depths greater than 1, we recursively traverse the left and right children of the current node. We adjust the child pointers at the specified depth to insert the new node at that level.

4. **Recursive Function for Subtree Modification:**
   The function `addOneRow` recursively traverses the tree. At each level, it decrements the depth until it reaches the base cases, where the row is added. This function is called on both the left and right children as we go deeper into the tree.

### Code Breakdown (Step by Step)

Let's go through the code implementation step by step:

#### Step 1: Checking for Depth 1
```cpp
if (d == 1) {
    TreeNode* newroot = new TreeNode(val);
    newroot->left = root;
    return newroot;
}
```
- If the desired depth `d` is 1, we need to add a new node at the root. A new node with the value `val` is created, and the current root of the tree becomes the left child of this new node. The new node is returned as the new root.

#### Step 2: Handling Depth 0
```cpp
if (d == 0) {
    TreeNode* newroot = new TreeNode(val);
    newroot->right = root;
    return newroot;
}
```
- If the depth `d` is 0 (or some other base case), we create a new node with the value `val` and set it as the right child of the root.

#### Step 3: Recursive Case for Other Depths
```cpp
if(!root) return nullptr;
else if(d == 2) {
    root->left  = addOneRow(root->left, val, 1);
    root->right = addOneRow(root->right, val, 0);            
    return root;
} else if(d > 2) {
    root->left  = addOneRow(root->left, val, d - 1);
    root->right = addOneRow(root->right, val, d - 1);            
}
return root;
```
- If `d > 2`, we recursively call the `addOneRow` function on the left and right subtrees. In each recursive call, we decrease the depth by 1 (`d - 1`), traversing the tree until we reach the base case where a new row needs to be inserted.
- For depth 2, we handle inserting new nodes specifically for the left and right child pointers at that depth.

#### Step 4: Handling Recursion and Insertion at Deeper Levels
- As the recursion unwinds, it correctly places the new row by adjusting the left and right child pointers of the nodes at the required depth.

### Complexity

#### Time Complexity:
- **O(N):** The function traverses the entire tree once, where `N` is the number of nodes in the tree. At each node, it performs constant-time operations, resulting in an overall time complexity of O(N), where N is the number of nodes in the tree.

#### Space Complexity:
- **O(H):** The space complexity is proportional to the depth of the recursion stack, where `H` is the height of the tree. In the worst case (when the tree is skewed), this will be O(N). However, in a balanced tree, the space complexity would be O(log N).

### Conclusion

This solution efficiently adds a new row of nodes with a specified value at the given depth of a binary tree. By leveraging a recursive approach, we ensure that each level of the tree is processed correctly, and the nodes are inserted at the correct positions. The time complexity of O(N) makes this solution scalable to trees with large numbers of nodes. The use of recursion simplifies the logic, and the function handles edge cases such as adding nodes at the root level or at deeper levels with ease.

This solution is ideal for scenarios where tree structures need to be modified dynamically by adding rows at specific depths, and it performs well within the constraints of typical binary tree problems.

[`Link to LeetCode Lab`](https://leetcode.com/problems/add-one-row-to-tree/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
