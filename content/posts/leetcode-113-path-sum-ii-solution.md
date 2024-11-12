
+++
authors = ["grid47"]
title = "Leetcode 113: Path Sum II"
date = "2024-10-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 113: Path Sum II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Backtracking","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/path-sum-ii/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/113.webp" 
    alt="A radiant path of numbers, showing multiple possible paths with gentle branches leading to different sums."
    caption="Solution to LeetCode 113: Path Sum II Problem"
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
---
{{< youtube MwLDG-WNOjM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #114: Flatten Binary Tree to Linked List](https://grid47.xyz/posts/leetcode-114-flatten-binary-tree-to-linked-list-solution/) |
| --- |
