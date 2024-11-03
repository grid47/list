
+++
authors = ["Crafted by Me"]
title = "Leetcode 2212: Maximum Points in an Archery Competition"
date = "2018-10-13"
description = "In-depth solution and explanation for Leetcode 2212: Maximum Points in an Archery Competition in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2213: Longest Substring of One Repeating Character](https://grid47.xyz/posts/leetcode_2213) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

