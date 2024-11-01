
+++
authors = ["Crafted by Me"]
title = "Leetcode 229: Majority Element II"
date = "2024-03-18"
description = "Solution to Leetcode 229"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/majority-element-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
            std::vector<int> result;
    int n = nums.size();

    if (n == 0) return result;

    int cnt1 = 0, cnt2 = 0;
    int cnd1 = 0, cnd2 = 0;

    for (int i = 0; i < n; i++) {
        int val = nums[i];

        if (val == cnd1) cnt1++;
        else if (val == cnd2) cnt2++;
        else if (cnt1 == 0) { cnt1 = 1; cnd1 = val; }
        else if (cnt2 == 0) { cnt2 = 1; cnd2 = val; }
        else { cnt1--; cnt2--; }
    }

    cnt1 = 0;
    cnt2 = 0;

    for (int i = 0; i < n; i++) {
        int val = nums[i];

        if (val == cnd1) cnt1++;
        else if (val == cnd2) cnt2++;
    }

    n = n / 3;

    if (cnt1 > n) result.push_back(cnd1);
    if (cnt2 > n) result.push_back(cnd2);

    return result;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/229.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

