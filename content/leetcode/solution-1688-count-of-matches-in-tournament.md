
+++
authors = ["grid47"]
title = "Leetcode 1688: Count of Matches in Tournament"
date = "2024-05-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1688: Count of Matches in Tournament in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "lslcc0tumpU"
youtube_upload_date="2023-12-05"
youtube_thumbnail="https://i.ytimg.com/vi/lslcc0tumpU/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/count-of-matches-in-tournament/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfMatches(int n) {
        if(n==0) return 0;
        if(n==1) return 0;
        int ans = n / 2;
        if(n & 1)
        ans += numberOfMatches(n/2 + 1);
        else
        ans += numberOfMatches(n/2);
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1688.md" >}}
---
{{< youtube lslcc0tumpU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1690: Stone Game VII](https://grid47.xyz/leetcode/solution-1690-stone-game-vii/) |
| --- |
