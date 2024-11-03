
+++
authors = ["Crafted by Me"]
title = "Leetcode 2096: Step-By-Step Directions From a Binary Tree Node to Another"
date = "2019-02-06"
description = "In-depth solution and explanation for Leetcode 2096: Step-By-Step Directions From a Binary Tree Node to Another in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
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


---


| Next : [LeetCode #2097: Valid Arrangement of Pairs](grid47.xyz/leetcode_2097) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

