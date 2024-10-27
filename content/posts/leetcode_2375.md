
+++
authors = ["Yasir"]
title = "Leetcode 2375: Construct Smallest Number From DI String"
date = "2018-04-28"
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

{{< highlight html >}}
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

