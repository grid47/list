
+++
authors = ["grid47"]
title = "Leetcode 949: Largest Time for Given Digits"
date = "2024-08-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 949: Largest Time for Given Digits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "sn6r0ZV_2y4"
youtube_upload_date="2020-09-01"
youtube_thumbnail="https://i.ytimg.com/vi/sn6r0ZV_2y4/hqdefault.jpg?sqp=-oaymwEmCOADEOgC8quKqQMa8AEB-AHUBoAC4AOKAgwIABABGGEgZShHMA8=&rs=AOn4CLCRrVpzGGgx18QwTzZjGamfSnIVlw"
+++



[`Problem Link`](https://leetcode.com/problems/largest-time-for-given-digits/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort(begin(A), end(A), greater<int>());
        do if ((A[0] < 2 || (A[0] == 2 && A[1] < 4)) && A[2] < 6)
            return to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]);
        while(prev_permutation(begin(A), end(A)));
            
        return "";
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/949.md" >}}
---
{{< youtube sn6r0ZV_2y4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #950: Reveal Cards In Increasing Order](https://grid47.xyz/leetcode/solution-950-reveal-cards-in-increasing-order/) |
| --- |
