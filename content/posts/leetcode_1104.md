
+++
authors = ["Crafted by Me"]
title = "Leetcode 1104: Path In Zigzag Labelled Binary Tree"
date = "2021-10-25"
description = "In-depth solution and explanation for Leetcode 1104: Path In Zigzag Labelled Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {

public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        res.push_back(label);
        int level = log2(label);

        while (level != 0) {
            int left = pow(2 , (level - 1));
            int right = pow(2 , level) - 1;
            label = left + ( right- label / 2);

            res.push_back(label);
            level -= 1;
        }

        int num = res.size();
        reverse(res.begin(), res.end());

        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1104.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1105: Filling Bookcase Shelves](https://grid47.xyz/posts/leetcode_1105) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

