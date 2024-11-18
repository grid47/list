
+++
authors = ["grid47"]
title = "Leetcode 357: Count Numbers with Unique Digits"
date = "2024-10-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 357: Count Numbers with Unique Digits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = ""
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/357.webp"
+++



[`Problem Link`](https://leetcode.com/problems/count-numbers-with-unique-digits/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/357.webp" 
    alt="A sequence of numbers with each unique digit softly illuminated, showing how many unique digits are present."
    caption="Solution to LeetCode 357: Count Numbers with Unique Digits Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        
        int res = 10;
        int available = 9;
        int unqNums = 9;
        
        while(n-- > 1 && available > 0) {
            unqNums = unqNums * available;
            res += unqNums;
            available--;
        }
        return res;
    }
}
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/357.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #365: Water and Jug Problem](https://grid47.xyz/leetcode/solution-365-water-and-jug-problem/) |
| --- |
