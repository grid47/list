
+++
authors = ["grid47"]
title = "Leetcode 1296: Divide Array in Sets of K Consecutive Numbers"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1296: Divide Array in Sets of K Consecutive Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {

        map<int, int> cnt;
        int n = nums.size();
        for(int num : nums)
            cnt[num]++;
        
        for(auto it : cnt) {
            int frq = it.second;
            if(frq > 0)
            for(int i = 0; i < k; i++) {

                  if(cnt[it.first + i] < frq) return false;
                else cnt[it.first + i] -= frq;

            }
        }
        
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1296.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1297: Maximum Number of Occurrences of a Substring](https://grid47.xyz/posts/leetcode-1297-maximum-number-of-occurrences-of-a-substring-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}