
+++
authors = ["grid47"]
title = "Leetcode 1589: Maximum Sum Obtained of Any Permutation"
date = "2024-06-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1589: Maximum Sum Obtained of Any Permutation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "TyZ_FFGIZgs"
youtube_upload_date="2020-09-19"
youtube_thumbnail="https://i.ytimg.com/vi/TyZ_FFGIZgs/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& req) {
        int n = nums.size();
        long long res = 0;
        vector<long long> cnt(n, 0);
        for(auto& r: req) {
            cnt[r[0]]++;
            if(r[1] + 1 < n)
                cnt[r[1] +1]--;
    }
        
        for(int i = 1; i < n; i++)
            cnt[i] += cnt[i -1];
        sort(nums.begin(), nums.end());
        sort(cnt.begin(), cnt.end());
        for(int i = 0; i < n; i++)
            res +=  ((long long) nums[i] * cnt[i]);
        
        return res % 1000000007;
        }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1589.md" >}}
---
{{< youtube TyZ_FFGIZgs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1590: Make Sum Divisible by P](https://grid47.xyz/leetcode/solution-1590-make-sum-divisible-by-p/) |
| --- |
