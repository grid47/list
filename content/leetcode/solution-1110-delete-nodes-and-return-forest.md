
+++
authors = ["grid47"]
title = "Leetcode 1110: Delete Nodes And Return Forest"
date = "2024-07-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1110: Delete Nodes And Return Forest in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "UhKu0q1yXHY"
youtube_upload_date="2024-07-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/UhKu0q1yXHY/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/delete-nodes-and-return-forest/description/)

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
    vector<TreeNode*> ans;
    set<int> to_del;
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int i: to_delete) to_del.insert(i);
        helper(root, true);
        return ans;
    }

    TreeNode* helper(TreeNode* root, bool is_root) {
        if(root == NULL) return NULL;
        bool del = to_del.find(root->val) != to_del.end();
        if(is_root && !del) ans.push_back(root);
        root->left = helper(root->left, del);
        root->right = helper(root->right, del);
        return del? NULL : root;
    }

};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1110.md" >}}
---
{{< youtube UhKu0q1yXHY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1111: Maximum Nesting Depth of Two Valid Parentheses Strings](https://grid47.xyz/leetcode/solution-1111-maximum-nesting-depth-of-two-valid-parentheses-strings/) |
| --- |