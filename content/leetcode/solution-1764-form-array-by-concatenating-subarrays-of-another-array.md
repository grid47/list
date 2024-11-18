
+++
authors = ["grid47"]
title = "Leetcode 1764: Form Array by Concatenating Subarrays of Another Array"
date = "2024-05-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1764: Form Array by Concatenating Subarrays of Another Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Greedy","String Matching"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "GGdu6E9o7D4"
youtube_upload_date="2021-02-23"
youtube_thumbnail="https://i.ytimg.com/vi/GGdu6E9o7D4/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canChoose(vector<vector<int>>& group, vector<int>& nums) {
        
        int numsIdx = 0, grpIdx = 0;
        
        while(numsIdx < nums.size() && grpIdx < group.size()) {
            

            int matchCnt = 0;
            
            while(numsIdx + matchCnt < nums.size() &&
                 matchCnt < group[grpIdx].size() &&
                 nums[numsIdx + matchCnt] == group[grpIdx][matchCnt])
                    matchCnt++;
            
            if(matchCnt == group[grpIdx].size()) {
                grpIdx++;
                numsIdx += matchCnt;
            } else numsIdx++;

        }
                
        return grpIdx == group.size();
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1764.md" >}}
---
{{< youtube GGdu6E9o7D4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1765: Map of Highest Peak](https://grid47.xyz/leetcode/solution-1765-map-of-highest-peak/) |
| --- |
