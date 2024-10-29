
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 415: Add Strings"
date = "2023-09-11"
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/415.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

