
+++
authors = ["grid47"]
title = "Leetcode 853: Car Fleet"
date = "2024-08-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 853: Car Fleet in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Sorting","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Pr6T-3yB9RM"
youtube_upload_date="2021-10-18"
youtube_thumbnail="https://i.ytimg.com/vi/Pr6T-3yB9RM/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/car-fleet/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& v) {
        map<int, double> t;
        for(int i = 0; i < pos.size(); i++) {
            t[-pos[i]] = (double) (target-pos[i]) / v[i];
        }
        
        int fleet = 0;
        double cur = 0;
        
        for(auto it: t) {
            if(it.second > cur) fleet++, cur = it.second;
        }
        return fleet;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/853.md" >}}
---
{{< youtube Pr6T-3yB9RM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #855: Exam Room](https://grid47.xyz/leetcode/solution-855-exam-room/) |
| --- |
