
+++
authors = ["grid47"]
title = "Leetcode 100: Same Tree"
date = "2024-10-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 100: Same Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/100.webp"
youtube = "jK6XXYezw2g"
youtube_upload_date="2024-04-08"
youtube_thumbnail="https://i.ytimg.com/vi/jK6XXYezw2g/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/same-tree/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/100.webp" 
    alt="Two trees glowing in harmony, showing perfect symmetry and balance."
    caption="Solution to LeetCode 100: Same Tree Problem"
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        int ans = p->val == q->val;
        ans &= isSameTree(p->left, q->left);
        ans &= isSameTree(p->right, q->right);
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/100.md" >}}
---
{{< youtube jK6XXYezw2g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #102: Binary Tree Level Order Traversal](https://grid47.xyz/leetcode/solution-102-binary-tree-level-order-traversal/) |
| --- |