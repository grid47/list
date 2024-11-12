
+++
authors = ["grid47"]
title = "Leetcode 842: Split Array into Fibonacci Sequence"
date = "2024-08-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 842: Split Array into Fibonacci Sequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/split-array-into-fibonacci-sequence/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> splitIntoFibonacci(string num) {
        vector<int> res;
        split(0, res, num);
        return res;
    }

    bool split(int idx, vector<int> &res, string num) {
        if(idx == num.size() && res.size() >= 3) return true;
        for(int i = idx; i < num.size(); i++) {
            if(num[idx] == '0' && i > idx) break;
            int sz = i - idx+1;
            long n = stol("0" + num.substr(idx, sz));
            if(n > INT_MAX) break;
                     
            if(res.size() <= 1 || (n == (long)res.back() + res[res.size() -2])) {
                res.push_back(n);
                if(split(i + 1, res, num))
                    return true;
                res.pop_back();
            }

        }
        return false;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/842.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #844: Backspace String Compare](https://grid47.xyz/posts/leetcode-844-backspace-string-compare-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
