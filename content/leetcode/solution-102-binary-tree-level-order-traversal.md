
+++
authors = ["grid47"]
title = "Leetcode 102: Binary Tree Level Order Traversal"
date = "2024-10-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 102: Binary Tree Level Order Traversal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/102.webp"
youtube = "6ZnyEApgFYg"
youtube_upload_date="2021-03-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/6ZnyEApgFYg/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/binary-tree-level-order-traversal/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/102.webp" 
    alt="A tree with soft, glowing rings representing each level, expanding outward."
    caption="Solution to LeetCode 102: Binary Tree Level Order Traversal Problem"
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
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            vector<int> res;
            while(sz--) {
                TreeNode* tmp = q.front();
                res.push_back(tmp->val);
                q.pop();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            ans.push_back(res);
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/102.md" >}}
---
{{< youtube 6ZnyEApgFYg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #103: Binary Tree Zigzag Level Order Traversal](https://grid47.xyz/leetcode/solution-103-binary-tree-zigzag-level-order-traversal/) |
| --- |
