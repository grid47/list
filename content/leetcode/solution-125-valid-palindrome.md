
+++
authors = ["grid47"]
title = "Leetcode 125: Valid Palindrome"
date = "2024-10-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 125: Valid Palindrome in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/125.webp"
youtube = "jJXJ16kPFWg"
youtube_upload_date="2021-10-11"
youtube_thumbnail="https://i.ytimg.com/vi/jJXJ16kPFWg/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/valid-palindrome/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/125.webp" 
    alt="A string of letters that glow in perfect symmetry, forming a calm and balanced palindrome."
    caption="Solution to LeetCode 125: Valid Palindrome Problem"
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
    
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i <= j) {
            if(!isalnum(s[i])) {
                i++; continue;
            }
            if(!isalnum(s[j])) {
                j--; continue;
            }
            if(tolower(s[i]) == tolower(s[j])) {
                i++, j--;
            } else return false;
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/125.md" >}}
---
{{< youtube jJXJ16kPFWg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #128: Longest Consecutive Sequence](https://grid47.xyz/leetcode/solution-128-longest-consecutive-sequence/) |
| --- |