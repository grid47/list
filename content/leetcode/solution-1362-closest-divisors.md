
+++
authors = ["grid47"]
title = "Leetcode 1362: Closest Divisors"
date = "2024-06-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1362: Closest Divisors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "wx3731P3At4"
youtube_upload_date="2022-08-04"
youtube_thumbnail="https://i.ytimg.com/vi/wx3731P3At4/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/closest-divisors/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> closestDivisors(int num) {
        
        for(int a = sqrt(num + 2); a > 0; a--) {
            if((num + 1) % a == 0) return vector<int>{a, (num + 1) / a};
            if((num + 2) % a == 0) return vector<int>{a, (num + 2) / a};            
        }
        return vector<int>{};
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1362.md" >}}
---
{{< youtube wx3731P3At4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1366: Rank Teams by Votes](https://grid47.xyz/leetcode/solution-1366-rank-teams-by-votes/) |
| --- |