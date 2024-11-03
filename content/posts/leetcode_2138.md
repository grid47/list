
+++
authors = ["Crafted by Me"]
title = "Leetcode 2138: Divide a String Into Groups of Size k"
date = "2018-12-26"
description = "In-depth solution and explanation for Leetcode 2138: Divide a String Into Groups of Size k in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res((s.size() + k - 1) / k, string(k, fill));
        for (int i = 0; i < s.size(); ++i)
            res[i / k][i % k] = s[i];
        return res;
    }
};
{{< /highlight >}}


---


"| 2139: Minimum Moves to Reach Target Score |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

