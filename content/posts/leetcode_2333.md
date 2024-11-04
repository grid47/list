
+++
authors = ["Crafted by Me"]
title = "Leetcode 2333: Minimum Sum of Squared Difference"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2333: Minimum Sum of Squared Difference in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-sum-of-squared-difference/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {

        int n = nums1.size();
        vector<long long> diff(n, 0);
        for(int i = 0; i < n; i++)
        diff[i] = abs(nums1[i] - nums2[i]);

        long long m = *max_element(diff.begin(), diff.end());
        int k = k1 + k2;

        vector<long long> bck(m + 1, 0);
        for(int i = 0; i < n; i++)
            bck[diff[i]]++;

        for(int i = m; i > 0; i--)
            if (bck[i] > 0) {
                long long num     = min(bck[i], (long long) k);
                bck[i]     -= num;
                bck[i - 1] += num;
                k -= num;
                if (k == 0) break;
            }

        long long res = 0;
        for(long long i = 0; i < m + 1; i++)
         res += bck[i] * (i * i);

        return res;
    }
};
{{< /highlight >}}


---
{{< youtube wp8lV0aP6aU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2334: Subarray With Elements Greater Than Varying Threshold](https://grid47.xyz/posts/leetcode_2334) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

