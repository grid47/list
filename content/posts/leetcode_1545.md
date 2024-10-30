
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1545: Find Kth Bit in Nth Binary String"
date = "2020-08-08"
description = "Solution to Leetcode 1545"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description/)

---
{{< youtube 34QYE5HAFy4 >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    char findKthBit(int n, int k) {

        string s = "0";
        
        for(int i = 2; i <= n; i++) {
            string tmp = s;
            s += '1';
            for(int j = tmp.size() - 1; j >= 0; j--) {
                
                s += (tmp[j] == '0') ? '1':'0';
                
            }
        }

        return s[k-1];
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

