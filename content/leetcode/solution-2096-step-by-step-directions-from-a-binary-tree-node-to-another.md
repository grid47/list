
+++
authors = ["grid47"]
title = "Leetcode 2096: Step-By-Step Directions From a Binary Tree Node to Another"
date = "2024-04-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2096: Step-By-Step Directions From a Binary Tree Node to Another in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "JegJNGcwtFg"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:

    bool find(TreeNode* n, int val, string &path) {
        if(n->val == val) return true;
             if (n->left  && find(n->left,  val, path)) path.push_back('L');
        else if (n->right && find(n->right, val, path)) path.push_back('R');
        return !path.empty();
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string sp, dp;
        find(root, startValue, sp);
        find(root,  destValue, dp);
        while(!sp.empty() && !dp.empty() && sp.back() == dp.back()) {
            sp.pop_back();
            dp.pop_back();
        }
        return string(sp.size(), 'U') + string(rbegin(dp), rend(dp));
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2096.md" >}}
---
{{< youtube JegJNGcwtFg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2099: Find Subsequence of Length K With the Largest Sum](https://grid47.xyz/leetcode/solution-2099-find-subsequence-of-length-k-with-the-largest-sum/) |
| --- |
