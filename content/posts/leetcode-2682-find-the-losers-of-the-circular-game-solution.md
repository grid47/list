
+++
authors = ["grid47"]
title = "Leetcode 2682: Find the Losers of the Circular Game"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2682: Find the Losers of the Circular Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-losers-of-the-circular-game/description/)

---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2682.md" >}}
---
{{< youtube bNZuwqt1pg0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2683: Neighboring Bitwise XOR](https://grid47.xyz/posts/leetcode-2682-find-the-losers-of-the-circular-game-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
