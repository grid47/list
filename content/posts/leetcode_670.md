
+++
authors = ["Yasir"]
title = "Leetcode 670: Maximum Swap"
date = "2022-12-27"
description = "Solution to Leetcode 670"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-swap/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int maximumSwap(int num) {

        vector<int> idx(10, 0);

        string nm = to_string(num);
        for(int i = 0; i < nm.size(); i++) idx[nm[i] - '0'] = i;

        for(int i = 0; i < nm.size(); i++)
        for(int j = 9; j > nm[i] - '0'; j--) {
            if(idx[j] > i) {
                swap(nm[idx[j]], nm[i]);
                return stoi(nm);
            }
        }

        return num;
    }
};
{{< /highlight >}}

