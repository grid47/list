
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1601: Maximum Number of Achievable Transfer Requests"
date = "2020-06-11"
description = "Solution to Leetcode 1601"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& req) {
        
        // vector<vector<int>> grid(n, vector<int>(n, 0));
        


        int ans = 0;
        
        for(int msk = 1; msk < (1 << req.size()); msk++) {
            vector<int> in(n, 0), out(n, 0);
            int idx = 0;
            int m = msk;
            while(m > 0) {
                if(m & 1) {
                    in[req[idx][0]]++;
                    out[req[idx][1]]++;                    
                }
                m >>= 1;
                idx++;
            }
            if(in == out) ans = max(ans, __builtin_popcount(msk));
        }
        return ans;
    }

};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

