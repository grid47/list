
+++
authors = ["Crafted by Me"]
title = "Leetcode 2096: Step-By-Step Directions From a Binary Tree Node to Another"
date = "2019-02-05"
description = "Solution to Leetcode 2096"
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

