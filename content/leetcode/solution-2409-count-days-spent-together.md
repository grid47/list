
+++
authors = ["grid47"]
title = "Leetcode 2409: Count Days Spent Together"
date = "2024-03-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2409: Count Days Spent Together in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "D12AShvqNfE"
youtube_upload_date="2022-09-18"
youtube_thumbnail="https://i.ytimg.com/vi/D12AShvqNfE/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/count-days-spent-together/description/)

---
**Code:**

{{< highlight cpp >}}
int md[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Solution {
	// Convert date to respective number in year.
    int td(string s) {
        int m = s[1] - '0' + 10*(s[0] - '0');
        int d = s[4] - '0' + 10*(s[3] - '0');
        --m;
        while (m > 0) {
            d += md[m];
            --m;
        }
        return d;
    }
public:
    int countDaysTogether(string sa1, string sa2, string sb1, string sb2) {
        int a1 = td(sa1), a2 = td(sa2), b1 = td(sb1), b2 = td(sb2);
        int ans = 0;
		// Check all 365 days in year
        for (int i = 0; i < 367; ++i) {
            if (a1 <= i && i <= a2 && b1 <= i && i <= b2) {
                ++ans;
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2409.md" >}}
---
{{< youtube D12AShvqNfE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2410: Maximum Matching of Players With Trainers](https://grid47.xyz/leetcode/solution-2410-maximum-matching-of-players-with-trainers/) |
| --- |