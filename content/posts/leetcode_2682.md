
+++
authors = ["Yasir"]
title = "Leetcode 2682: Find the Losers of the Circular Game"
date = "2017-06-25"
description = "Solution to Leetcode 2682"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-losers-of-the-circular-game/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> rcvd(n, 0);
        int i = 0;
        int cnt = 1;
        rcvd[0] = 1;
        while(rcvd[i] == 1) {
            i = (i + cnt * k) % n;            
            if(rcvd[i] == 1) break;
            rcvd[i] = 1;
            cnt++;
        }
        vector<int> ans;
        for(int j = 0; j < n; j++) {
            // cout << rcvd[j] << " ";
            if(rcvd[j] == 0) ans.push_back(j + 1);            
        }

        return ans;
    }
};
{{< /highlight >}}

