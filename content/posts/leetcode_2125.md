
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2125: Number of Laser Beams in a Bank"
date = "2019-01-04"
description = "Solution to Leetcode 2125"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
    public:
    int numberOfBeams(vector<string> bank) {

        int res = 0, m = bank.size(), n = bank[0].size();

        int cnt = 0, prv = 0;
        for (auto b : bank) 
        {
            cnt = 0;
            for(int i = 0; i < n; i++)
                if (b[i] == '1') cnt++;
            if(cnt > 0) {
                res += prv * cnt;
                prv = cnt;
            }
        }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

