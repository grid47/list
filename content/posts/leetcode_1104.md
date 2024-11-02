
+++
authors = ["Crafted by Me"]
title = "Leetcode 1104: Path In Zigzag Labelled Binary Tree"
date = "2020-10-24"
description = "Solution to Leetcode 1104"
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

