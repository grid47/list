
+++
authors = ["grid47"]
title = "Leetcode 2595: Number of Even and Odd Bits"
date = "2024-02-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2595: Number of Even and Odd Bits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Bit Manipulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "SMk2dF8hReg"
youtube_upload_date="2023-03-19"
youtube_thumbnail="https://i.ytimg.com/vi_webp/SMk2dF8hReg/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/number-of-even-and-odd-bits/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> evenOddBit(int n) {
        int a=0,b=0;
        int c=0;
        while(n>0)
        {
            if(c%2==0)
            {
                if(n%2==1)
                {
                    a++;
                }
            }
            else
            {
                if(n%2==1) b++;
            }
            n=n/2;
            c++;
            
        }
        return {a,b};
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2595.md" >}}
---
{{< youtube SMk2dF8hReg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2596: Check Knight Tour Configuration](https://grid47.xyz/leetcode/solution-2596-check-knight-tour-configuration/) |
| --- |
