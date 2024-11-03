
+++
authors = ["Crafted by Me"]
title = "Leetcode 1903: Largest Odd Number in String"
date = "2019-08-18"
description = "In-depth solution and explanation for Leetcode 1903: Largest Odd Number in String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-odd-number-in-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string largestOddNumber(string num) {
        string res = "";
        for(int i = num.size(); i >= 0; i--) {
            if((num[i] - '0') % 2)
              return num.substr(0, i + 1);
        }
        return string();
    }
};
{{< /highlight >}}


---
{{< youtube IIt_ARZzclY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1904: The Number of Full Rounds You Have Played](https://grid47.xyz/posts/leetcode_1904) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

