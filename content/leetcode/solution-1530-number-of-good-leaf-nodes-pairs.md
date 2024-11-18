
+++
authors = ["grid47"]
title = "Leetcode 1530: Number of Good Leaf Nodes Pairs"
date = "2024-06-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1530: Number of Good Leaf Nodes Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "f_epkBeS1LQ"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/)

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
    int ans = 0;
    int countPairs(TreeNode* root, int dist) {
        dfs(root, dist);
        return ans;
    }
    
    vector<int> dfs(TreeNode* root, int dist) {
        if(!root) {
            vector<int> res(dist + 1, 0);
            return res;
        }
        
        if(root->left == NULL && root->right == NULL) {
            vector<int> res(dist + 1, 0);
            res[1]++;
            return res;
        }
        vector<int> left = dfs(root->left, dist);
        vector<int> right = dfs(root->right, dist);
        for(int i = 1; i <= dist - 1; i++) {
            for(int j = dist - 1; j >= 1; j--) {
                if(i + j <= dist)
                ans += left[i] * right[j];
            }
        }
        vector<int> res(dist + 1, 0);
        for(int i = 1; i <= dist - 2; i++ ) {
            res[i + 1] = left[i] + right[i];
        }
        return res;
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1530.md" >}}
---
{{< youtube f_epkBeS1LQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1535: Find the Winner of an Array Game](https://grid47.xyz/leetcode/solution-1535-find-the-winner-of-an-array-game/) |
| --- |
