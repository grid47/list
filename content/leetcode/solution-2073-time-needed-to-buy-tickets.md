
+++
authors = ["grid47"]
title = "Leetcode 2073: Time Needed to Buy Tickets"
date = "2024-04-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2073: Time Needed to Buy Tickets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Queue","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "cVmS9N6kf2Y"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/time-needed-to-buy-tickets/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int timeRequiredToBuy(vector<int>& nums, int k) {
        int res = 0, key = nums[k];
        for(int i = 0; i < nums.size(); i++) {
          res += min(key - (i > k), nums[i]);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2073.md" >}}
---
{{< youtube cVmS9N6kf2Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2075: Decode the Slanted Ciphertext](https://grid47.xyz/leetcode/solution-2075-decode-the-slanted-ciphertext/) |
| --- |
