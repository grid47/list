
+++
authors = ["Crafted by Me"]
title = "Leetcode 2375: Construct Smallest Number From DI String"
date = "2017-05-02"
description = "Solution to Leetcode 2375"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/construct-smallest-number-from-di-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string smallestNumber(string ptn) {
        string res, stk;
        int n = ptn.size();
        for(int i = 0; i <= n; i++) {
            stk.push_back(i + '1');
            if(i == n || ptn[i] == 'I') {
                while(!stk.empty()) {
                    res.push_back(stk.back());
                    stk.pop_back();
                }
            }
        }
        return res;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

