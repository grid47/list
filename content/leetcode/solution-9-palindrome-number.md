
+++
authors = ["grid47"]
title = "Leetcode 9: Palindrome Number"
date = "2024-11-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 9: Palindrome Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/9.webp"
youtube = "yubRKwixN-U"
youtube_upload_date="2021-08-20"
youtube_thumbnail="https://i.ytimg.com/vi/yubRKwixN-U/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/palindrome-number/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/9.webp" 
    alt="A number with mirrored halves, radiating a soothing glow as it reflects symmetrically."
    caption="Solution to LeetCode 9: Palindrome Number Problem"
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
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long int y = x, z = 0;
        while(x) {
            z = z * 10 + x % 10;
            x /= 10;
        }
        return y == z;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/9.md" >}}
---
{{< youtube yubRKwixN-U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #11: Container With Most Water](https://grid47.xyz/leetcode/solution-11-container-with-most-water/) |
| --- |