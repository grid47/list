
+++
authors = ["grid47"]
title = "Leetcode 2299: Strong Password Checker II"
date = "2024-03-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2299: Strong Password Checker II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "0Rn1Lf0mXOI"
youtube_upload_date="2022-06-11"
youtube_thumbnail="https://i.ytimg.com/vi_webp/0Rn1Lf0mXOI/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/strong-password-checker-ii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool strongPasswordCheckerII(string p) {
    int lo = 0, up = 0, digit = 0, sz = p.size();
    for (int i = 0; i < sz; ++i) {
        if (i > 0 && p[i - 1] == p[i])
            return false;
        lo += islower(p[i]) ? 1 : 0;
        up += isupper(p[i]) ? 1 : 0;
        digit += isdigit(p[i]) ? 1 : 0;
    }
    return sz > 7 && lo && up && digit && (sz - lo - up - digit > 0);
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2299.md" >}}
---
{{< youtube 0Rn1Lf0mXOI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2300: Successful Pairs of Spells and Potions](https://grid47.xyz/leetcode/solution-2300-successful-pairs-of-spells-and-potions/) |
| --- |