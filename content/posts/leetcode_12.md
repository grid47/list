
+++
authors = ["Crafted by Me"]
title = "Leetcode 12: Integer to Roman"
date = "2024-10-21"
description = "In-depth solution and explanation for Leetcode 12: Integer to Roman in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/integer-to-roman/description/)

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

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

