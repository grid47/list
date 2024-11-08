
+++
authors = ["grid47"]
title = "Leetcode 2554: Maximum Number of Integers to Choose From a Range I"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2554: Maximum Number of Integers to Choose From a Range I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int n;
    unordered_map<int, bool> mp;
    
    int maxCount(vector<int>& ban, int n, int mxS) {
        // this->n = n;
        for(int x: ban)
            mp[x] = true;

        // memset(memo, -1, sizeof(memo));
        // memo.resize(n + 1);
        // return dp(1, mxS);
        int cnt = 0;
        for(int i = 1; i < n + 1; i++) {
            if(!mp.count(i) && mxS >= i) {
                cnt++;
                mxS -= i;
            }
            if(mxS < 0) break;
        }
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2554.md" >}}
---
{{< youtube iLU7ZBtjc-k >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2555: Maximize Win From Two Segments](https://grid47.xyz/posts/leetcode_2555) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
