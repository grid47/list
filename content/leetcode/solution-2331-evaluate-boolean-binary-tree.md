
+++
authors = ["grid47"]
title = "Leetcode 2331: Evaluate Boolean Binary Tree"
date = "2024-03-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2331: Evaluate Boolean Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "9a_cP54jn8Q"
youtube_upload_date="2024-05-16"
youtube_thumbnail="https://i.ytimg.com/vi/9a_cP54jn8Q/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/evaluate-boolean-binary-tree/description/)

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
    bool evaluateTree(TreeNode* root) {
        if(!root) return false;
        if(!root->left && !root->right) return root->val;
        
        if(root->val == 2)
            return evaluateTree(root->left) || evaluateTree(root->right);
      else

return evaluateTree(root->left) && evaluateTree(root->right);        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2331.md" >}}
---
{{< youtube 9a_cP54jn8Q >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2332: The Latest Time to Catch a Bus](https://grid47.xyz/leetcode/solution-2332-the-latest-time-to-catch-a-bus/) |
| --- |