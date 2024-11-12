
+++
authors = ["grid47"]
title = "Leetcode 12: Integer to Roman"
date = "2024-11-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 12: Integer to Roman in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/integer-to-roman/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/12.webp" 
    alt="Roman numerals glowing softly, forming a delicate arc of timeless symbols."
    caption="Solution to LeetCode 12: Integer to Roman Problem"
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
    string intToRoman(int num) {
        vector<int> nums = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        vector<string> chrs = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

        int idx = 0;
        string res = "";
        while(num > 0)
        {
            while(num >= nums[idx])
            {
                num -= nums[idx];
                res += chrs[idx];
            }
            idx++;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/12.md" >}}
---
{{< youtube Rsq1ObYg6ak >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #13: Roman to Integer](https://grid47.xyz/posts/leetcode-13-roman-to-integer-solution/) |
| --- |
