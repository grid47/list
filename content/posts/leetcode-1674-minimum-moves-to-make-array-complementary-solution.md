
+++
authors = ["grid47"]
title = "Leetcode 1674: Minimum Moves to Make Array Complementary"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1674: Minimum Moves to Make Array Complementary in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-moves-to-make-array-complementary/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minMoves(vector<int>& num, int lmt) {
        int n = num.size();
        vector<int> dp(2*lmt +2,0);
        for(int i = 0; i < n/2; i++) {
            int a = num[i];
            int b = num[n-1-i];
            dp[2] += 2;
            dp[min(a,b)+1] -= 1;
            dp[a+b] -= 1;
            dp[a+b+1] += 1;
            dp[max(a,b) + lmt +1] += 1;
            
            }
        //for(int i = 1; i < n; i++)
           // dp[i] += dp[i - 1];
        
        int cur = 0, res = 2* n;
        for(int i = 2; i < 2 * lmt + 1; i++) {
            cur += dp[i];
            res = min(res, cur);
            }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1674.md" >}}
---
{{< youtube uyV0p6zy9DU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1675: Minimize Deviation in Array](https://grid47.xyz/posts/leetcode-1675-minimize-deviation-in-array-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}