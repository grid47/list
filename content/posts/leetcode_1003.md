
+++
authors = ["Crafted by Me"]
title = "Leetcode 1003: Check If Word Is Valid After Substitutions"
date = "2022-02-03"
description = "In-depth solution and explanation for Leetcode 1003: Check If Word Is Valid After Substitutions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1004: Max Consecutive Ones III](https://grid47.xyz/posts/leetcode_1004) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

