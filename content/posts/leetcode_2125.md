
+++
authors = ["Yasir"]
title = "Leetcode 2125: Number of Laser Beams in a Bank"
date = "2019-01-03"
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

{{< highlight html >}}
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

