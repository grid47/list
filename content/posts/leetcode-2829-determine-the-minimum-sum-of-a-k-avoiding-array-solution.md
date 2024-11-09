
+++
authors = ["grid47"]
title = "Leetcode 2829: Determine the Minimum Sum of a k-avoiding Array"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2829: Determine the Minimum Sum of a k-avoiding Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/determine-the-minimum-sum-of-a-k-avoiding-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumSum(int n, int k) {
        int sum = 0;
        vector<int> vis(51, 0);
        int i = 1;
        while(n > 0 && i <= k) {
            if(!vis[i] && !vis[k - i]) {
                n--;                
                sum += i;
                vis[i] = true;
            }
            i++;
        }
        while(n--) {
            sum += i++;
        }
        return sum;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2829.md" >}}
---
{{< youtube EimziJ7mVdE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2830: Maximize the Profit as the Salesman](https://grid47.xyz/posts/leetcode-2830-maximize-the-profit-as-the-salesman-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
