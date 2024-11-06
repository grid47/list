
+++
authors = ["Crafted by Me"]
title = "Leetcode 2465: Number of Distinct Averages"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2465: Number of Distinct Averages in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-distinct-averages/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        map<long, int> mp;
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        while(i < j){
            int a = nums[j--];
            int b = nums[i++];
            long c = a + b;
            mp[c] = 1;
        }
        return mp.size();
    }
};
{{< /highlight >}}


---
{{< youtube 2sWoLnBzuKw >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2466: Count Ways To Build Good Strings](https://grid47.xyz/posts/leetcode_2466) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
