
+++
authors = ["grid47"]
title = "Leetcode 2212: Maximum Points in an Archery Competition"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2212: Maximum Points in an Archery Competition in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Backtracking","Bit Manipulation","Enumeration"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2212.md" >}}
---
{{< youtube nnwNXfYz2mo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2215: Find the Difference of Two Arrays](https://grid47.xyz/posts/leetcode-2215-find-the-difference-of-two-arrays-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}