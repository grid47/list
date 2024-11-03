
+++
authors = ["Crafted by Me"]
title = "Leetcode 2645: Minimum Additions to Make Valid String"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2645: Minimum Additions to Make Valid String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-additions-to-make-valid-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int addMinimum(string word) {
        int exp = 0, res = 0;
        int n = word.size();
        for(int i = 0; i < n; i++) {
            if(exp == (word[i] - 'a')) {
                exp = (exp + 1) % 3;
                continue;
            }
            while(exp != (word[i] - 'a')) {
                res++;
                exp = (exp + 1) % 3;
            }
            exp = (exp + 1) % 3;            
            // cout << i << " " << res << " " << exp << "\n";
        }
        if(word[n - 1] == 'a') res += 2;
        if(word[n - 1] == 'b') res += 1;
        return res;
    }
};
{{< /highlight >}}


---
{{< youtube 7IAA0sdeACw >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2646: Minimize the Total Price of the Trips](https://grid47.xyz/posts/leetcode_2646) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

