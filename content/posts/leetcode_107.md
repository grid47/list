
+++
authors = ["Crafted by Me"]
title = "Leetcode 107: Binary Tree Level Order Traversal II"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 107: Binary Tree Level Order Traversal II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        vector<vector<int>> ans;        
        queue<TreeNode*> q;
        if(root == NULL) return ans;
        
        q.push(root);        
        stack<vector<int>> stk;
                
        while(!q.empty())
        {
            vector<int> ans;
            int sz = q.size();

            while(sz--) {
                TreeNode* tmp = q.front();
                q.pop();
                ans.push_back(tmp->val);

                if(tmp->left)   q.push(tmp->left);
                if(tmp->right)  q.push(tmp->right);                
            }
            stk.push(ans);
        }

        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }

        return ans;      
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/107.md" >}}
---
{{< youtube 6e4pmYyr_1o >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #108: Convert Sorted Array to Binary Search Tree](https://grid47.xyz/posts/leetcode_108) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
