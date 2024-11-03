
+++
authors = ["Crafted by Me"]
title = "Leetcode 2120: Execution of All Suffix Instructions Staying in a Grid"
date = "2019-01-13"
description = "In-depth solution and explanation for Leetcode 2120: Execution of All Suffix Instructions Staying in a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& st, string s) {
        int m = s.size(), h = m + n, v = m + n;
        vector<int> hor((h + m) * 2, m), ver((h +m) * 2, m), res(m);
        for(int i = m - 1; i >= 0; i--) {
            hor[h] = ver[v] = i;
            h += s[i] == 'L' ? 1 : s[i] == 'R'? -1 : 0;
            v += s[i] == 'U' ? 1 : s[i] == 'D'? -1 : 0;
            res[i] = min({  m, hor[h - st[1] - 1], hor[h - st[1] + n],
                               ver[v - st[0] - 1], ver[v - st[0] + n]  }) - i;
        }
        return res;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2121: Intervals Between Identical Elements](https://grid47.xyz/posts/leetcode_2121) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

