
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 135: Candy"
date = "2024-06-17"
description = "Solution to Leetcode 135"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/candy/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int candy(vector<int>& rate) {
        int size = rate.size();

        if(size <= 1) return size;

        vector<int> num(size, 1);

        for(int i = 1; i < size; i++)
            if(rate[i] > rate[i - 1])
            num[i] = num[i - 1] + 1;

        for(int i = size - 1; i > 0; i--)
            if(rate[i - 1] > rate[i])
            num[i - 1] = max(num[i - 1], num[i] + 1);

        int res = 0;
        for(int i = 0; i < size; i++)
            res += num[i];

        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/135.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
