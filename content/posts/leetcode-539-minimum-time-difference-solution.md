
+++
authors = ["grid47"]
title = "Leetcode 539: Minimum Time Difference"
date = "2024-09-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 539: Minimum Time Difference in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-time-difference/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/539.webp" 
    alt="A series of times, with the minimum time difference glowing softly between the times."
    caption="Solution to LeetCode 539: Minimum Time Difference Problem"
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
    int findMinDifference(vector<string>& time) {
        
        sort(time.begin(), time.end());
        
        int n = time.size(), mindiff = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            
            int diff = abs(timeDiff(time[(i - 1 +n)%n], time[i]));
            
            diff = min(diff, 1440 - diff); // 1440 = 24h in minutes
            mindiff = min(mindiff, diff);
        }
        
        return mindiff;
    }
    
    int timeDiff(string t1, string t2) {
        // cout << t1 << t2;
        int h1 = stoi(t1.substr(0, 2));
        int m1 = stoi(t1.substr(3, 2));
        int h2 = stoi(t2.substr(0, 2));
        int m2 = stoi(t2.substr(3, 2));
        return (h2 - h1) * 60 + (m2 - m1);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/539.md" >}}
---
{{< youtube LVBDzeUmNIQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #540: Single Element in a Sorted Array](https://grid47.xyz/posts/leetcode-540-single-element-in-a-sorted-array-solution/) |
| --- |
