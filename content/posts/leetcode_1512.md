
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1512: Number of Good Pairs"
date = "2020-09-10"
description = "Solution to Leetcode 1512"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-good-pairs/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numIdenticalPairs(vector<int>& A) {
        int res = 0;
        unordered_map<int, int> count;
        for (int a: A) {
            res += count[a]++;
        }
        return res;   
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

