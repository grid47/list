
+++
authors = ["grid47"]
title = "Leetcode 1004: Max Consecutive Ones III"
date = "2024-07-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1004: Max Consecutive Ones III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sliding Window","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "HsGKI02yw6M"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/max-consecutive-ones-iii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt[2] = {};
        int res = 0, j = 0;
        for(int i = 0; i < nums.size(); i++) {
            cnt[nums[i]]++;
            while(cnt[0] > k && j <= i) {
                cnt[nums[j]]--;
                j++;
            }
            res = max(res, (i - j + 1));
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1004.md" >}}
---
{{< youtube HsGKI02yw6M >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1005: Maximize Sum Of Array After K Negations](https://grid47.xyz/leetcode/solution-1005-maximize-sum-of-array-after-k-negations/) |
| --- |
