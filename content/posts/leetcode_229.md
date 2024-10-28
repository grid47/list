
+++
authors = ["Yasir"]
title = "Leetcode 229: Majority Element II"
date = "2024-03-14"
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

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

