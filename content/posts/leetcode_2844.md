
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2844: Minimum Operations to Make a Special Number"
date = "2017-01-16"
description = "Solution to Leetcode 2844"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-operations-to-make-a-special-number/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumOperations(string num) {
        bool fivefound = false;
        bool zerofound = false;
        for (int i =num.size()-1; i >=0;i--) {
            
            if (zerofound && num[i]=='0') return num.size()-2-i;
            if (zerofound && num[i]=='5') return num.size()-2-i;
            if (fivefound && num[i]=='2') return num.size()-2-i;
            if (fivefound && num[i]=='7') return num.size()-2-i;
            if (num[i]=='5') fivefound = true;
            if (num[i]=='0') zerofound = true;
            
        }
        if (zerofound) return num.size()-1;
        return num.size();
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

