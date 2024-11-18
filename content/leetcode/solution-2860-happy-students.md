
+++
authors = ["grid47"]
title = "Leetcode 2860: Happy Students"
date = "2024-01-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2860: Happy Students in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "dDse65NWFt8"
youtube_upload_date="2023-09-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/dDse65NWFt8/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/happy-students/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:

    int countWays(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0, n = nums.size();
        int selected = 0;
        if(nums[0]!=0) ans = 1; // Not Selecting AnyOne
        for(int i=0;i<n;i++) {
            selected++;
            if(selected>nums[i]) {  // No. of Selected Students is strictly greater than nums[i].
                if(i+1<n && selected<nums[i+1]) // Considering from (i+1) to n Students is not Selected.
                    ans++; 
                else if(i+1==n) ans++;  // Last Student
            }
        }
        return ans;
    }

};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2860.md" >}}
---
{{< youtube dDse65NWFt8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2861: Maximum Number of Alloys](https://grid47.xyz/leetcode/solution-2861-maximum-number-of-alloys/) |
| --- |
