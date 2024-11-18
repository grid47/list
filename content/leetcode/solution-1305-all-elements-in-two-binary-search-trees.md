
+++
authors = ["grid47"]
title = "Leetcode 1305: All Elements in Two Binary Search Trees"
date = "2024-06-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1305: All Elements in Two Binary Search Trees in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Search Tree","Sorting","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "B97Hk1H2x2s"
youtube_upload_date="2020-09-05"
youtube_thumbnail="https://i.ytimg.com/vi/B97Hk1H2x2s/hqdefault.jpg?sqp=-oaymwEmCOADEOgC8quKqQMa8AEB-AHUBoAC4AOKAgwIABABGDMgRih_MA8=&rs=AOn4CLC03GCnDEem80J52_RuXkBdpkuQfA"
+++



[`Problem Link`](https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/)

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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> st1, st2;
        vector<int> res;
        while(root1 || root2 || !st1.empty() || !st2.empty()) {
            while(root1) {
                st1.push(root1);
                root1 = root1->left;
            }
            while(root2) {
                st2.push(root2);
                root2 = root2->left;
            }
            if(st2.empty() || (!st1.empty() && st1.top()->val < st2.top()->val)) {
                root1 = st1.top();
                st1.pop();
                res.push_back(root1->val);
                root1 = root1->right;
            } else {
                root2 = st2.top();
                st2.pop();
                res.push_back(root2->val);
                root2 = root2->right;
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1305.md" >}}
---
{{< youtube B97Hk1H2x2s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1306: Jump Game III](https://grid47.xyz/leetcode/solution-1306-jump-game-iii/) |
| --- |
