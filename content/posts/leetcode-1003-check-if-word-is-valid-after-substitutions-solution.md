
+++
authors = ["grid47"]
title = "Leetcode 1003: Check If Word Is Valid After Substitutions"
date = "2024-07-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1003: Check If Word Is Valid After Substitutions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isValid(string s) {
        vector<char> stk;
        for(char c : s) {
            if(c == 'c') {
                int n = stk.size();
                if(n < 2 ||
                  stk[n - 1] != 'b' ||
                  stk[n - 2] != 'a' ) 
                    return false;
                stk.pop_back();
                stk.pop_back();
            } else stk.push_back(c);
        }
        
        return stk.size() == 0;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1003.md" >}}
---
{{< youtube 1ImaQNKTVnw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #1004: Max Consecutive Ones III](https://grid47.xyz/posts/leetcode-1004-max-consecutive-ones-iii-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
