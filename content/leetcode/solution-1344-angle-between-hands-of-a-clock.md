
+++
authors = ["grid47"]
title = "Leetcode 1344: Angle Between Hands of a Clock"
date = "2024-06-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1344: Angle Between Hands of a Clock in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "evs3Po8Km7c"
youtube_upload_date="2020-07-15"
youtube_thumbnail="https://i.ytimg.com/vi/evs3Po8Km7c/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/angle-between-hands-of-a-clock/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    double angleClock(int h, int minutes) {
        
        double mn = 360 *(double)minutes/60;
        
        double hrs = 360 * ((double)(h == 12? 0: h) / 12) + 30* ((double)minutes/60);
        cout << mn << " " << hrs;
            
        return min(abs(mn - hrs), 360 - (abs(mn - hrs)));
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1344.md" >}}
---
{{< youtube evs3Po8Km7c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1347: Minimum Number of Steps to Make Two Strings Anagram](https://grid47.xyz/leetcode/solution-1347-minimum-number-of-steps-to-make-two-strings-anagram/) |
| --- |
