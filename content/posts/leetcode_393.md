
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 393: UTF-8 Validation"
date = "2023-10-03"
description = "Solution to Leetcode 393"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/utf-8-validation/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int count = 0;
        for(auto c : data) {
            if(count == 0) {
                if((c >> 5) == 0b110) count = 1;
                else if ((c >> 4) == 0b1110) count = 2;
                else if ((c >> 3) == 0b11110) count = 3;
                else if (c >> 7) return false;
            } else {
                if ((c >> 6) != 0b10) return false;
                count--;
            }
        }
        return count == 0;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/393.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

