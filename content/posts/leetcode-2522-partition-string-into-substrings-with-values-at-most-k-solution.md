
+++
authors = ["grid47"]
title = "Leetcode 2522: Partition String Into Substrings With Values at Most K"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2522: Partition String Into Substrings With Values at Most K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string str;
    vector<map<int, int>> mem;
    
    int dp(int idx, int k, int num) {
        
        if(idx == str.size()) return 1;
        
        if(mem[idx].count(num)) return mem[idx][num];

        int ans = 1 + dp(idx + 1, k, str[idx] - '0');

        long long net = (long long)num * 10 + (str[idx] - '0');
        if(net <= k) {
            ans = min(ans, dp(idx + 1, k, net));
        }

        return mem[idx][num] = ans;
    }
    
    int minimumPartition(string s, int k) {
        str = s;
        for(char x: s)
            if(x - '0' > k) return -1;
        mem.resize(s.size());
        int ans = dp(0, k, 0);
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2522.md" >}}
---
{{< youtube XQh9V8PEIiI >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2523: Closest Prime Numbers in Range](https://grid47.xyz/posts/leetcode-2523-closest-prime-numbers-in-range-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}