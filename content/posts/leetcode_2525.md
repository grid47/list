
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2525: Categorize Box According to Criteria"
date = "2017-12-02"
description = "Solution to Leetcode 2525"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/categorize-box-according-to-criteria/description/)

---
{{< youtube dIciftyQXHo >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool bulky = false, heavy = false;
        double v = (double) length * width * height;
        if(length >= 10000 || width >= 10000 || 
           height >= 10000 || v >= 1000000000)
            bulky = true;
        if(mass >= 100)
            heavy = true;
        string category;
            if(bulky && heavy)
                category = "Both";
            else if (!bulky && !heavy)
                category = "Neither";
            else if (bulky)
                category = "Bulky";
            else if (heavy)
                category = "Heavy";
        return category;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

