
+++
authors = ["grid47"]
title = "Leetcode 2576: Find the Maximum Number of Marked Indices"
date = "2024-02-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2576: Find the Maximum Number of Marked Indices in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "NlsyXR7GOJE"
youtube_upload_date="2023-02-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/NlsyXR7GOJE/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/find-the-maximum-number-of-marked-indices/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    bool can(int k, vector<int> &nums) {
        int ridx = k - 1;
        int lidx = nums.size() - k;
        
        for(int i = 0; i < k; i++)
            if(nums[i] * 2 > nums[nums.size() - k + i]) return false;
        
        return true;
        
    }
    
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 1, r = n/2, ans = 0;
        while(l <= r) {
            
            int mid = l + (r - l + 1) / 2;
            if(can(mid, nums)) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;

        }
        return ans * 2;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2576.md" >}}
---
{{< youtube NlsyXR7GOJE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2578: Split With Minimum Sum](https://grid47.xyz/leetcode/solution-2578-split-with-minimum-sum/) |
| --- |