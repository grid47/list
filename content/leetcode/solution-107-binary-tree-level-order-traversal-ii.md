
+++
authors = ["grid47"]
title = "Leetcode 107: Binary Tree Level Order Traversal II"
date = "2024-10-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 107: Binary Tree Level Order Traversal II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/107.webp"
youtube = "6e4pmYyr_1o"
youtube_upload_date="2021-01-20"
youtube_thumbnail="https://i.ytimg.com/vi/6e4pmYyr_1o/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/107.webp" 
    alt="A tree with soft concentric circles, each level glowing and expanding outward from the center."
    caption="Solution to LeetCode 107: Binary Tree Level Order Traversal II Problem"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #109: Convert Sorted List to Binary Search Tree](https://grid47.xyz/leetcode/solution-109-convert-sorted-list-to-binary-search-tree/) |
| --- |