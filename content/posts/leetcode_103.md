
+++
authors = ["Crafted by Me"]
title = "Leetcode 103: Binary Tree Zigzag Level Order Traversal"
date = "2024-07-22"
description = "In-depth solution and explanation for Leetcode 103: Binary Tree Zigzag Level Order Traversal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> tmp;
        queue<TreeNode*> q;

        if(root == NULL) return ans;
        q.push(root);

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                TreeNode* it = q.front();
                q.pop();
                tmp.push_back(it->val);
                if(it->left  != NULL) q.push(it->left);
                if(it->right != NULL) q.push(it->right);
            }
            ans.push_back(tmp);
            tmp.clear();
        }
        return ans;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans = levelOrder(root);
        for(int i = 1; i < ans.size(); i += 2)
        {
            vector<int> tmp = ans[i];
            reverse(tmp.begin(), tmp.end());
            ans[i] = tmp;
        }
        return ans;

    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/103.md" >}}
---
{{< youtube igbboQbiwqw >}}

"| 104: Maximum Depth of Binary Tree |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

