
+++
authors = ["grid47"]
title = "Leetcode 3026: Maximum Good Subarray Sum"
date = "2024-01-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3026: Maximum Good Subarray Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "v-IFLS8-Haw"
youtube_upload_date="2024-02-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/v-IFLS8-Haw/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/maximum-good-subarray-sum/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        long long ans = LLONG_MIN;

        int n = nums.size();
        map<int, int> mp;
        vector<long long> pre;
        pre.push_back(0);
        for(int i = 0; i < n; i++) {
            pre.push_back(pre.back() + nums[i]);
            if(mp.count(nums[i] - k)) ans = max(ans, pre[i + 1] - pre[mp[nums[i] - k]]);
            if(mp.count(nums[i] + k)) ans = max(ans, pre[i + 1] - pre[mp[nums[i] + k]]);
            auto it = mp.find(nums[i]);
            if(it == mp.end() || pre[i] - pre[it->second] <= 0) mp[nums[i]] = i;
        }
        return ans == LLONG_MIN? 0: ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3026.md" >}}
---
{{< youtube v-IFLS8-Haw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #3042: Count Prefix and Suffix Pairs I](https://grid47.xyz/leetcode/solution-3042-count-prefix-and-suffix-pairs-i/) |
| --- |