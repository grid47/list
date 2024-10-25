
+++
authors = ["Yasir"]
title = "Leetcode 107: Binary Tree Level Order Traversal II"
date = "2024-07-12"
description = "Solution to Leetcode 107"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/)

---

**Code:**

{{< highlight html >}}
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

