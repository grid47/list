
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



[`Problem Link`](https://leetcode.com/problems/subtree-of-another-tree/description/)
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/572.md" >}}
---
{{< youtube Qk7_vGWUMMQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #576: Out of Boundary Paths](https://grid47.xyz/leetcode/solution-576-out-of-boundary-paths/) |
| --- |
