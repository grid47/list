
+++
authors = ["grid47"]
title = "Leetcode 1248: Count Number of Nice Subarrays"
date = "2024-07-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1248: Count Number of Nice Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Sliding Window","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-number-of-nice-subarrays/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
    
    int atmost(vector<int> &nums, int k) {
        int cnt[2] = {};
        int res = 0, j = 0;
        for(int i = 0; i < nums.size(); i++) {
            cnt[nums[i]%2]++;
            while(cnt[1] > k) {
                cnt[nums[j]%2]--;
                j++;
            }
            res += (i - j + 1);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1248.md" >}}
---
{{< youtube 4zNK0rhFfcA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1249: Minimum Remove to Make Valid Parentheses](https://grid47.xyz/posts/leetcode-1249-minimum-remove-to-make-valid-parentheses-solution/) |
| --- |
