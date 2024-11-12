
+++
authors = ["grid47"]
title = "Leetcode 2670: Find the Distinct Difference Array"
date = "2024-02-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2670: Find the Distinct Difference Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-distinct-difference-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        map<int, int> l, r;
        for(int i = 0; i < n; i++) {
            r[nums[i]]++;
        }

        for(int i = 0; i < n; i++) {
            r[nums[i]]--;
            if(r[nums[i]] == 0) r.erase(nums[i]);
            l[nums[i]]++;
            ans[i] = l.size() - r.size();
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2670.md" >}}
---
{{< youtube ikDNBcVaq6Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2672: Number of Adjacent Elements With the Same Color](https://grid47.xyz/posts/leetcode-2672-number-of-adjacent-elements-with-the-same-color-solution/) |
| --- |
