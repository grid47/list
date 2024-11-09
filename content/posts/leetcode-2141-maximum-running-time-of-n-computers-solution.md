
+++
authors = ["grid47"]
title = "Leetcode 2141: Maximum Running Time of N Computers"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2141: Maximum Running Time of N Computers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Greedy","Sorting"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-running-time-of-n-computers/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    bool mx(int n, vector<int>& bat, long long mid) {

        long long net = 0;
        for(int i = 0; i < bat.size(); i++) {
            net += min((long long)bat[i], mid);
        }

        return net >= mid * n;
    }
    long long maxRunTime(int n, vector<int>& bat) {
        long long sum = accumulate(bat.rbegin(), bat.rend(), 0L);

        long long l = 0, r = sum / n, ans = 0;
        while(l <= r) {
            long long mid = l + (r - l + 1) / 2;
            if (mx(n, bat, mid)) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2141.md" >}}
---
{{< youtube 3kyUP_jIDoQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2144: Minimum Cost of Buying Candies With Discount](https://grid47.xyz/posts/leetcode-2144-minimum-cost-of-buying-candies-with-discount-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
