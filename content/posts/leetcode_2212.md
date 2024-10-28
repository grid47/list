
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2212: Maximum Points in an Archery Competition"
date = "2018-10-09"
description = "Solution to Leetcode 2212"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-points-in-an-archery-competition/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> bob, alice;
    int n;
    int mask;
    int ans;
    
    void dp(int idx, int rm, int pts, int msk) {
        // cout << idx << " " << rm << " " << pts << "\n";
        if((rm <= 0) || (idx == n)){
            if(ans < pts) {
                ans = pts;
                mask = msk;
            }
            return;
        }        
        dp(idx + 1, rm, pts, msk);        
        if(rm > alice[idx]) {
            msk |= (1 << idx);
            dp(idx + 1, rm - alice[idx] - 1, pts + idx, msk);            
        }
    }
    
    vector<int> maximumBobPoints(int net, vector<int>& alice) {
        n = alice.size();
        this->alice = alice;
        bob.resize(n, 0);
        int idx = 0;
        int pts = 0;
        mask = 0;
        ans = 0;
        dp(idx, net, pts, 0);
        
        for(int i = n - 1; i >= 0; i--) {
            if((mask >> i) & 1) {
                bob[i] = alice[i] + 1;
                net -= bob[i];
            }
        }
        
        if(net > 0) bob[0] += net;
        
        return bob;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

