
+++
authors = ["grid47"]
title = "Leetcode 400: Nth Digit"
date = "2024-09-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 400: Nth Digit in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/nth-digit/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/400.jpeg" 
    alt="A glowing sequence of digits where the nth digit is softly illuminated and revealed."
    caption="Solution to LeetCode 400: Nth Digit Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
typedef long long int lli;
class Solution {
public:
    int findNthDigit(int n) {
        lli len = 1;
        lli cnt = 9;
        lli start = 1;
        while(n > len * cnt) {

            n -= len * cnt;
            
            len++;
            cnt *= 10;
            start *= 10;

        }
        start += (n - 1) / len;
        string s = to_string(start);     
        return s[(n - 1) % len] - '0';
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/400.md" >}}
---
{{< youtube 4QAGxDIVpdM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #402: Remove K Digits](https://grid47.xyz/posts/leetcode-402-remove-k-digits-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
