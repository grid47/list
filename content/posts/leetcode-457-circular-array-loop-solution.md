
+++
authors = ["grid47"]
title = "Leetcode 457: Circular Array Loop"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 457: Circular Array Loop in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/circular-array-loop/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return false;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) continue;

            int j = i, k = getIdx(i, nums);
            while(nums[k] * nums[i] > 0 && nums[getIdx(k, nums)] * nums[i] > 0) {
                if(j == k) {
                    if(j == getIdx(j, nums)) break;
                    return true;
                }
                j = getIdx(j, nums);
                k = getIdx(getIdx(k, nums), nums);
            }

            j = i;
            int val = nums[i];
            while(nums[j] * val > 0) {
                int next = getIdx(j, nums);
                nums[j] = 0;
                j = next;
            }
        }
        return false;
    }

    int getIdx(int i, vector<int> &nums) {
        int n = nums.size();
        return i + nums[i] >= 0? (i + nums[i]) % n: n + ((i + nums[i]) % n);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/457.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #458: Poor Pigs](https://grid47.xyz/posts/leetcode-457-circular-array-loop-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
