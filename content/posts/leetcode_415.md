
+++
authors = ["Yasir"]
title = "Leetcode 415: Add Strings"
date = "2023-09-08"
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

{{< highlight html >}}
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

