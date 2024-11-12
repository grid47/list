
+++
authors = ["grid47"]
title = "Leetcode 229: Majority Element II"
date = "2024-10-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 229: Majority Element II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/majority-element-ii/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/229.webp" 
    alt="A sequence of numbers with one element glowing brightly, signifying the majority element."
    caption="Solution to LeetCode 229: Majority Element II Problem"
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
{{< youtube Eua-UrQ_ANo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #230: Kth Smallest Element in a BST](https://grid47.xyz/posts/leetcode-230-kth-smallest-element-in-a-bst-solution/) |
| --- |
