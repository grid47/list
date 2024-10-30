
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 113: Path Sum II"
date = "2024-07-10"
description = "Solution to Leetcode 113"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/path-sum-ii/description/)

---
{{< youtube MwLDG-WNOjM >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > paths;
        vector<int> path;
        findPaths(root, sum, path, paths);
        return paths;  
    }

    void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths) {

        if (!node) return;

        path.push_back(node -> val);

        if (!(node -> left) && !(node -> right) && sum == node -> val)
            paths.push_back(path);

        findPaths(node -> left, sum - node -> val, path, paths);
        findPaths(node -> right, sum - node -> val, path, paths);

        path.pop_back();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/113.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

