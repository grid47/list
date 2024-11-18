
+++
authors = ["grid47"]
title = "Leetcode 962: Maximum Width Ramp"
date = "2024-08-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 962: Maximum Width Ramp in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "3pTEJ1vzgSI"
youtube_upload_date="2024-10-10"
youtube_thumbnail="https://i.ytimg.com/vi/3pTEJ1vzgSI/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/maximum-width-ramp/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> s;
        for(int i = 0; i < nums.size(); i++)
            if(s.empty() || nums[s.top()] > nums[i])
                s.push(i);
        
        int res = 0;
        for(int i = nums.size() - 1; i >= 0; i--)
            while(!s.empty() && nums[s.top()] <= nums[i])
                res = max(res, i - s.top()), s.pop();
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/962.md" >}}
---
{{< youtube 3pTEJ1vzgSI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #963: Minimum Area Rectangle II](https://grid47.xyz/leetcode/solution-963-minimum-area-rectangle-ii/) |
| --- |
