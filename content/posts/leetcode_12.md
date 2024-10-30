
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 12: Integer to Roman"
date = "2024-10-19"
description = "Solution to Leetcode 12"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/integer-to-roman/description/)

---
{{< youtube Rsq1ObYg6ak >}}
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

