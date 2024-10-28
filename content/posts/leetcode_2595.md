
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2595: Number of Even and Odd Bits"
date = "2017-09-21"
description = "Solution to Leetcode 2595"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-even-and-odd-bits/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> evenOddBit(int n) {
        int a=0,b=0;
        int c=0;
        while(n>0)
        {
            if(c%2==0)
            {
                if(n%2==1)
                {
                    a++;
                }
            }
            else
            {
                if(n%2==1) b++;
            }
            n=n/2;
            c++;
            
        }
        return {a,b};
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

