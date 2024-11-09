
+++
authors = ["grid47"]
title = "Leetcode 2555: Maximize Win From Two Segments"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2555: Maximize Win From Two Segments in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximize-win-from-two-segments/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximizeWin(vector<int>& pos, int k) {
        
        int n = pos.size(), res = 0;
        
        vector<int> dp(n + 1, 0);
        
        int j = 0;
        for(int i = 0; i < n; i++) {
            while(pos[j] < pos[i] - k) j++;
            dp[i + 1] = max(dp[i], i - j + 1);
            res = max(res, i - j + 1+ dp[j]);
        }
        
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2555.md" >}}
---
{{< youtube trj4pn5uzZ0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2556: Disconnect Path in a Binary Matrix by at Most One Flip](https://grid47.xyz/posts/leetcode-2555-maximize-win-from-two-segments-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
