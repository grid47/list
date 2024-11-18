
+++
authors = ["grid47"]
title = "Leetcode 881: Boats to Save People"
date = "2024-08-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 881: Boats to Save People in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "FygGZScawYs"
youtube_upload_date="2023-04-03"
youtube_thumbnail="https://i.ytimg.com/vi/FygGZScawYs/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/boats-to-save-people/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int lo = 0, hi = people.size() - 1;
        int boats = 0;
        while(lo <= hi) {
            
            if(people[lo] + people[hi] <= limit) {
                lo += 1;
                hi -= 1;
            } else hi -= 1;
            
            boats++;
        }
        
        return boats;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/881.md" >}}
---
{{< youtube FygGZScawYs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #885: Spiral Matrix III](https://grid47.xyz/leetcode/solution-885-spiral-matrix-iii/) |
| --- |
