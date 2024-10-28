
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1869: Longer Contiguous Segments of Ones than Zeros"
date = "2019-09-17"
description = "Solution to Leetcode 1869"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkZeroOnes(string s) {
        int z = 0, o = 0, gz = 0, oz = 0, res = 1;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') z++;
            else z = 0;
            if(s[i] == '1') o++;
            else o = 0;
            gz = max(gz, z);
            oz = max(oz, o);
        }
        return oz > gz;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

