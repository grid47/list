
+++
authors = ["grid47"]
title = "Leetcode 7: Reverse Integer"
date = "2024-11-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 7: Reverse Integer in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/7.webp"
youtube = "HAgLH58IgJQ"
youtube_upload_date="2021-08-18"
youtube_thumbnail="https://i.ytimg.com/vi/HAgLH58IgJQ/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/reverse-integer/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/7.webp" 
    alt="A swirling, translucent number turning in reverse motion, unfolding in a calming spiral."
    caption="Solution to LeetCode 7: Reverse Integer Problem"
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
    int reverse(int x)
    {
        int rev=0, pop;
        while(x != 0)
        {
            pop  = x % 10;
            x   /= 10;

            if( (rev > INT_MAX/10 || (rev == INT_MAX/10 && pop > 7)) || 
                (rev < INT_MIN/10 || (rev == INT_MIN/10 && pop < -8)) )
                return 0;

            rev  = rev * 10 + pop;
        }
        return  rev;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/7.md" >}}
---
{{< youtube HAgLH58IgJQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #8: String to Integer (atoi)](https://grid47.xyz/leetcode/solution-8-string-to-integer-atoi/) |
| --- |