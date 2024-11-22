
+++
authors = ["grid47"]
title = "Leetcode 530: Minimum Absolute Difference in BST"
date = "2024-09-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 530: Minimum Absolute Difference in BST in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Search Tree","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/530.webp"
youtube = "NttA_NC_ZhI"
youtube_upload_date="2024-06-25"
youtube_thumbnail="https://i.ytimg.com/vi_webp/NttA_NC_ZhI/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/530.webp" 
    alt="A binary search tree where nodes light up showing the minimum absolute difference between node values."
    caption="Solution to LeetCode 530: Minimum Absolute Difference in BST Problem"
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
    int getMinimumDifference(TreeNode* root) {
        TreeNode* prv = NULL; int ans = INT_MAX;
        stack<TreeNode*> stk;
        while(!stk.empty() || root) {
            if(root) {
                stk.push(root);
                root = root->left;
            } else {
                root = stk.top();
                stk.pop();
                if(prv != NULL) {
                    ans = min(ans, root->val - prv->val);
                }
                prv = root;
                root = root->right;
            }
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

Given a binary search tree (BST), the task is to find the minimum absolute difference between the values of any two nodes. This difference must be as small as possible. 

### Approach

The structure of a BST ensures that for any given node, all nodes in its left subtree have values less than the node’s value, while nodes in its right subtree have values greater. Thus, performing an in-order traversal (visiting nodes in ascending order) allows us to sequentially access the node values in sorted order. 

In this solution, we use an in-order traversal to examine consecutive node values and calculate the differences. The smallest of these differences is the answer.

### Code Breakdown (Step by Step)

#### Step 1: Initialize Variables

```cpp
TreeNode* prv = NULL; int ans = INT_MAX;
stack<TreeNode*> stk;
```

- `prv`: A pointer to track the previously visited node during traversal. We initialize it to `NULL` as there is no "previous node" before the traversal starts.
- `ans`: An integer to store the minimum difference. It's initialized to `INT_MAX`, which is the largest possible integer, ensuring any actual difference will be smaller.
- `stk`: A stack to facilitate iterative in-order traversal of the tree, as recursion could be replaced with stack usage in iterative approaches.

#### Step 2: Start the In-Order Traversal Loop

```cpp
while(!stk.empty() || root) {
    if(root) {
        stk.push(root);
        root = root->left;
    } else {
        root = stk.top();
        stk.pop();
        if(prv != NULL) {
            ans = min(ans, root->val - prv->val);
        }
        prv = root;
        root = root->right;
    }
}
```

- This loop handles in-order traversal iteratively.
    - If `root` is not `NULL`, it means we have not yet reached the leftmost node in the current subtree. We push `root` onto the stack and move to `root->left`.
    - If `root` is `NULL`, it means we have reached the leftmost node of the subtree or completed processing the left subtree of a node.
        - We set `root` to the top of the stack, representing the current node we are visiting.
        - We then pop this node from the stack as we are about to process it.
        
- We compute the difference between the current node’s value (`root->val`) and the previous node’s value (`prv->val`) only if `prv` is not `NULL`.
    - Update `ans` with the minimum of `ans` and this difference.
- After processing the current node, `prv` is updated to the current `root`, and `root` is moved to `root->right` to continue the in-order traversal on the right subtree.

#### Step 3: Return the Result

```cpp
return ans;
```

- The minimum difference computed, stored in `ans`, is returned as the final answer.

### Complexity

- **Time Complexity**: `O(n)`, where `n` is the number of nodes in the binary search tree. This is because each node is visited once during the traversal.
- **Space Complexity**: `O(h)`, where `h` is the height of the tree. In the worst case (for a completely unbalanced tree), this can be `O(n)` if the tree is a linked list. For a balanced tree, it is `O(log n)`.

### Conclusion

This solution provides an efficient way to find the minimum absolute difference between values in a BST using in-order traversal. By leveraging BST properties, we only compare consecutive nodes in sorted order, which minimizes unnecessary comparisons and optimizes the process. The approach effectively handles even large BSTs due to its `O(n)` time complexity and efficient memory use.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/)

---
{{< youtube NttA_NC_ZhI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
