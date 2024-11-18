
+++
authors = ["grid47"]
title = "Leetcode 523: Continuous Subarray Sum"
date = "2024-09-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 523: Continuous Subarray Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/523.webp"
youtube = "OKcrLfR-8mE"
youtube_upload_date="2022-03-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/OKcrLfR-8mE/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/continuous-subarray-sum/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/523.webp" 
    alt="An array where the sum of a continuous subarray is highlighted with glowing elements."
    caption="Solution to LeetCode 523: Continuous Subarray Sum Problem"
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
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            sum %= k;
            if (mp.count(sum))
            {
                if (i - mp[sum] > 1) 
                    return true;
            }
            else mp[sum] = i;
        }
        return false;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/523.md" >}}
---
{{< youtube OKcrLfR-8mE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #524: Longest Word in Dictionary through Deleting](https://grid47.xyz/leetcode/solution-524-longest-word-in-dictionary-through-deleting/) |
| --- |
