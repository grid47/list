
+++
authors = ["grid47"]
title = "Leetcode 560: Subarray Sum Equals K"
date = "2024-09-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 560: Subarray Sum Equals K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/560.webp"
youtube = "fFVZt-6sgyo"
youtube_upload_date="2021-06-16"
youtube_thumbnail="https://i.ytimg.com/vi/fFVZt-6sgyo/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/subarray-sum-equals-k/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/560.webp" 
    alt="An array where subarrays that sum to `k` are highlighted, each valid sum softly glowing as it is found."
    caption="Solution to LeetCode 560: Subarray Sum Equals K Problem"
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
    int subarraySum(vector<int>& nums, int k) {
        
        int res = 0;
        
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0, cnt = 0;
        
        for(int i = 0; i < nums.size(); i++) {

            sum += nums[i];
            if(mp.count(sum - k)) cnt += mp[sum - k];
            mp[sum] += 1;
        }

        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/560.md" >}}
---
{{< youtube fFVZt-6sgyo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #565: Array Nesting](https://grid47.xyz/leetcode/solution-565-array-nesting/) |
| --- |
