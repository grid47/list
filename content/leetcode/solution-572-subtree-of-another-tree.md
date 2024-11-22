
+++
authors = ["grid47"]
title = "Leetcode 572: Subtree of Another Tree"
date = "2024-09-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 572: Subtree of Another Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","String Matching","Binary Tree","Hash Function"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/572.webp"
youtube = "Qk7_vGWUMMQ"
youtube_upload_date="2022-06-28"
youtube_thumbnail="https://i.ytimg.com/vi/Qk7_vGWUMMQ/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/572.webp" 
    alt="A tree being checked for its subtree, with the subtree softly glowing as it is found."
    caption="Solution to LeetCode 572: Subtree of Another Tree Problem"
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(match(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) ||
                isSubtree(root->right, subRoot);
    }
    
    bool match(TreeNode* r1, TreeNode* r2) {
        if(!r1 && !r2) return true;
        if(!r1 || !r2) return false;
        if(r1->val != r2->val) return false;
        return match(r1->left, r2->left) &&
            match(r1->right, r2->right);
    }
};
{{< /highlight >}}
---

### Problem Statement:
The problem asks us to determine whether a binary tree `subRoot` is a subtree of another binary tree `root`. A subtree of a binary tree is a tree that consists of a node in the original tree along with all of its descendants. The task is to check if there exists a node in `root` such that the subtree rooted at that node is identical to `subRoot`.

For example:
- `root = [3, 4, 5, 1, 2]`
- `subRoot = [4, 1, 2]`

The function should return `true` since the subtree rooted at node 4 in `root` is identical to `subRoot`.

### Approach:
This problem can be solved using a **depth-first search (DFS)** approach. The basic idea is to traverse the tree `root` and, for each node, check whether the subtree rooted at that node is identical to `subRoot`. If we find a match, we return `true`. If no match is found after traversing the entire tree, we return `false`.

To check if two trees are identical, we can use a helper function that compares the two trees recursively. If both trees are empty, they are identical. If one is empty and the other is not, they are not identical. If the values of the current nodes are the same, we recursively compare the left and right subtrees.

### Code Breakdown (Step by Step):

#### Step 1: Main Function (`isSubtree`)

```cpp
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root) return false;  // If the main tree is empty, return false
    if (match(root, subRoot)) return true;  // If the current node matches the subtree, return true
    // Recursively check the left and right children of the current node
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
```

- The function `isSubtree` checks whether the subtree `subRoot` exists in the binary tree `root`.
- If `root` is `nullptr`, it returns `false`, meaning there's no subtree in an empty tree.
- We then check whether the subtree starting at the current node matches `subRoot` by calling the helper function `match`. If it matches, we return `true`.
- If the current node does not match, we recursively check the left and right subtrees of `root` to see if `subRoot` exists in either.

#### Step 2: Helper Function (`match`)

```cpp
bool match(TreeNode* r1, TreeNode* r2) {
    if (!r1 && !r2) return true;  // Both nodes are null, so they match
    if (!r1 || !r2) return false;  // One of the nodes is null, so they don't match
    if (r1->val != r2->val) return false;  // The values of the nodes don't match
    // Recursively check the left and right children
    return match(r1->left, r2->left) && match(r1->right, r2->right);
}
```

- The function `match` checks whether two binary trees rooted at `r1` and `r2` are identical.
- If both trees are empty (`nullptr`), they are considered identical.
- If one of the trees is empty but the other is not, they are not identical.
- If the values of the current nodes `r1->val` and `r2->val` are different, we return `false` as the trees are not identical.
- If the current nodes match, we recursively check their left and right children to see if the entire trees match.

#### Step 3: Termination

After calling `isSubtree`, the recursion will eventually return `true` when it finds a subtree in `root` that matches `subRoot`. If no such match is found, the function will return `false` after traversing the entire tree.

### Complexity:

#### Time Complexity:
- **O(n * m):** In the worst case, we need to check every node in `root` to see if it matches `subRoot`. For each node in `root`, we call the `match` function to check if the subtree rooted at that node matches `subRoot`. The time complexity of `match` is O(m), where `m` is the number of nodes in `subRoot` (since we might need to check all the nodes in `subRoot` for every node in `root`). Therefore, the overall time complexity is O(n * m), where `n` is the number of nodes in `root` and `m` is the number of nodes in `subRoot`.

#### Space Complexity:
- **O(h):** The space complexity is determined by the recursion depth of the DFS traversal. In the worst case, the recursion depth is proportional to the height of the tree, which is O(h), where `h` is the height of the tree `root`. In a balanced binary tree, the height is O(log n), but in the worst case (e.g., a skewed tree), the height can be O(n).

### Conclusion:
This solution efficiently checks if a binary tree `subRoot` is a subtree of another binary tree `root` using a depth-first search (DFS) approach. The key idea is to recursively traverse `root` and compare each node with `subRoot` using the `match` helper function. The solution works in O(n * m) time, where `n` is the size of `root` and `m` is the size of `subRoot`, and it uses O(h) space for the recursion stack, where `h` is the height of the tree. This approach is optimal for problems involving subtree matching and provides an intuitive and efficient way to solve the problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/subtree-of-another-tree/description/)

---
{{< youtube Qk7_vGWUMMQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
