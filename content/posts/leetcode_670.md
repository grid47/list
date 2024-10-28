
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 670: Maximum Swap"
date = "2022-12-29"
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

{{< highlight cpp >}}
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

