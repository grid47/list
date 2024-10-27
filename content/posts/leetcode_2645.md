
+++
authors = ["Yasir"]
title = "Leetcode 2645: Minimum Additions to Make Valid String"
date = "2017-08-01"
description = "Solution to Leetcode 2645"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-additions-to-make-valid-string/description/)

---

**Code:**

{{< highlight html >}}
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

