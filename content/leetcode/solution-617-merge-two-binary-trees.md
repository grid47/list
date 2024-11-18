
+++
authors = ["grid47"]
title = "Leetcode 617: Merge Two Binary Trees"
date = "2024-09-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 617: Merge Two Binary Trees in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "NtHOsOl8zvQ"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/617.webp"
+++



[`Problem Link`](https://leetcode.com/problems/merge-two-binary-trees/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/617.webp" 
    alt="Two binary trees merging together, with each node softly glowing as they combine."
    caption="Solution to LeetCode 617: Merge Two Binary Trees Problem"
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
    TreeNode* mergeTrees(TreeNode* r1, TreeNode* r2) {
        TreeNode* ans = new TreeNode(0);
        if(r1 == NULL && r2 == NULL) return NULL;
        if(r1 != NULL && r2 != NULL)
            ans->val = r1->val + r2->val;
        else if(r1 == NULL)
            ans->val = r2->val;
        else
            ans->val = r1->val;
        ans->left = mergeTrees(r1?r1->left:NULL, r2?r2->left:NULL);
        ans->right = mergeTrees(r1?r1->right:NULL, r2?r2->right:NULL);
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/617.md" >}}
---
{{< youtube NtHOsOl8zvQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #621: Task Scheduler](https://grid47.xyz/leetcode/solution-621-task-scheduler/) |
| --- |
