
+++
authors = ["Crafted by Me"]
title = "Leetcode 2111: Minimum Operations to Make the Array K-Increasing"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2111: Minimum Operations to Make the Array K-Increasing in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size(), longest = 0;
        for(int i = 0; i < k; i++) {
            vector<int> lis;
            for(int j = i; j < n; j += k) {
                if(lis.empty() || lis.back() <= arr[j])
                    lis.push_back(arr[j]);
                else *upper_bound(lis.begin(), lis.end(), arr[j]) = arr[j];
            }
            longest += lis.size();
        }
        return n - longest;
    }
};
{{< /highlight >}}


---
{{< youtube HIpZ5Jz0O_g >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2112: The Airport With the Most Traffic](https://grid47.xyz/posts/leetcode_2112) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

