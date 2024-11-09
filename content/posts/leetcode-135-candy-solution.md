
+++
authors = ["grid47"]
title = "Leetcode 135: Candy"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 135: Candy in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/candy/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int candy(vector<int>& rate) {
        int size = rate.size();

        if(size <= 1) return size;

        vector<int> num(size, 1);

        for(int i = 1; i < size; i++)
            if(rate[i] > rate[i - 1])
            num[i] = num[i - 1] + 1;

        for(int i = size - 1; i > 0; i--)
            if(rate[i - 1] > rate[i])
            num[i - 1] = max(num[i - 1], num[i] + 1);

        int res = 0;
        for(int i = 0; i < size; i++)
            res += num[i];

        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/135.md" >}}
---
{{< youtube _l9N_LcplLs >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #136: Single Number](https://grid47.xyz/posts/leetcode-135-candy-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
