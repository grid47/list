
+++
authors = ["Yasir"]
title = "Leetcode 113: Path Sum II"
date = "2024-07-06"
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

**Code:**

{{< highlight html >}}
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

