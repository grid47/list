
+++
authors = ["grid47"]
title = "Leetcode 2348: Number of Zero-Filled Subarrays"
date = "2024-03-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2348: Number of Zero-Filled Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "1Y_QfTQmfKg"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/number-of-zero-filled-subarrays/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        for(int i = 0, j = 0; i < nums.size(); i++) {
            if(nums[i] != 0)
            j = i +1;
            res += i + 1 - j;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2348.md" >}}
---
{{< youtube 1Y_QfTQmfKg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2349: Design a Number Container System](https://grid47.xyz/leetcode/solution-2349-design-a-number-container-system/) |
| --- |
