
+++
authors = ["Yasir"]
title = "Leetcode 842: Split Array into Fibonacci Sequence"
date = "2022-07-08"
description = "Solution to Leetcode 842"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/split-array-into-fibonacci-sequence/description/)

---

**Code:**

{{< highlight html >}}
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

