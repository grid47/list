
+++
authors = ["grid47"]
title = "Leetcode 103: Binary Tree Zigzag Level Order Traversal"
date = "2024-10-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 103: Binary Tree Zigzag Level Order Traversal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/103.webp" 
    alt="A glowing zigzag path moving through tree levels, creating a calming, fluid motion."
    caption="Solution to LeetCode 103: Binary Tree Zigzag Level Order Traversal Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #104: Maximum Depth of Binary Tree](https://grid47.xyz/posts/leetcode-104-maximum-depth-of-binary-tree-solution/) |
| --- |
