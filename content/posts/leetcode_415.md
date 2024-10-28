
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 415: Add Strings"
date = "2023-09-10"
description = "Solution to Leetcode 415"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/add-strings/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
   string addStrings(string num1, string num2) {
        int carry=0,i=num1.length()-1,j=num2.length()-1;
        string ans="";
        while(i>=0||j>=0||carry>0){
            if(i>=0){
                carry=carry+num1[i]-'0';
                i--;
            }
            if(j>=0){
                carry=carry+num2[j]-'0';
                j--;
            }
            
             ans += char(carry % 10 + '0');
            carry =carry/ 10;
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

