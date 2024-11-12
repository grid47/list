
+++
authors = ["grid47"]
title = "Leetcode 457: Circular Array Loop"
date = "2024-09-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 457: Circular Array Loop in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/circular-array-loop/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/457.webp" 
    alt="A glowing circular array where elements move in a loop, with each cycle softly illuminated as it repeats."
    caption="Solution to LeetCode 457: Circular Array Loop Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #459: Repeated Substring Pattern](https://grid47.xyz/posts/leetcode-459-repeated-substring-pattern-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
