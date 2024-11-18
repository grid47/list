
+++
authors = ["grid47"]
title = "Leetcode 1590: Make Sum Divisible by P"
date = "2024-06-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1590: Make Sum Divisible by P in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "tZXsLAyE0SE"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/make-sum-divisible-by-p/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        map<int, int> mp;
        mp[0] = -1;
        int n = nums.size(), res = n, cur = 0, need = 0, want = 0;   
        
        for(int a : nums)
            need = (need + a) % p;

        for(int i = 0; i < n; i++) {

            cur = (cur + nums[i]) % p;
            mp[cur] = i;
            want = (cur - need + p) % p;

            if (mp.count(want))
            res = min(res, i - mp[want]);

        }

        return res < n? res : -1;
    }

};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1590.md" >}}
---
{{< youtube tZXsLAyE0SE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1593: Split a String Into the Max Number of Unique Substrings](https://grid47.xyz/leetcode/solution-1593-split-a-string-into-the-max-number-of-unique-substrings/) |
| --- |
