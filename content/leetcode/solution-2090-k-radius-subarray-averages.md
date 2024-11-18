
+++
authors = ["grid47"]
title = "Leetcode 2090: K Radius Subarray Averages"
date = "2024-04-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2090: K Radius Subarray Averages in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "rdKE6yZ_D3A"
youtube_upload_date="2021-11-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/rdKE6yZ_D3A/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/k-radius-subarray-averages/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> psum(n, 0);
        vector<int> avg(n, 0);
        psum[0] = nums[0];
        for(int i = 1; i < n; i++)
            psum[i] = psum[i - 1] + nums[i];
        
        for(int i = 0; i < n; i++) {
            if(i - k < 0 || i + k >= n) {
                avg[i] = -1;
            } else {
                avg[i] = (psum[i + k] - ((i - k) == 0? 0: psum[i - k - 1])) / (2 * k + 1);
            }
        }
        return avg;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2090.md" >}}
---
{{< youtube rdKE6yZ_D3A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2091: Removing Minimum and Maximum From Array](https://grid47.xyz/leetcode/solution-2091-removing-minimum-and-maximum-from-array/) |
| --- |
