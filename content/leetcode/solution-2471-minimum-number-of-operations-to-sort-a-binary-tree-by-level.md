
+++
authors = ["grid47"]
title = "Leetcode 2471: Minimum Number of Operations to Sort a Binary Tree by Level"
date = "2024-03-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2471: Minimum Number of Operations to Sort a Binary Tree by Level in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "yi_h_UMHD7s"
youtube_upload_date="2022-11-13"
youtube_thumbnail="https://i.ytimg.com/vi_webp/yi_h_UMHD7s/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/description/)

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
        
    int minimumOperations(TreeNode* root) {
        int cnt = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            vector<int> arr, idx(sz);
            while(sz--) {
                auto it = q.front();
                q.pop();
                arr.push_back(it->val);
                if(it->left != NULL) q.push(it->left);
                if(it->right!= NULL) q.push(it->right);
            }
            // cout << sz << " ";
            iota(idx.begin(), idx.end(), 0);
            sort(idx.begin(), idx.end(), [&](int i, int j) { return arr[i] < arr[j]; });
            for(int i = 0; i < idx.size(); i++)
                for(; idx[i] != i; cnt++)
                    swap(idx[i], idx[idx[i]]);
        }
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2471.md" >}}
---
{{< youtube yi_h_UMHD7s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2475: Number of Unequal Triplets in Array](https://grid47.xyz/leetcode/solution-2475-number-of-unequal-triplets-in-array/) |
| --- |