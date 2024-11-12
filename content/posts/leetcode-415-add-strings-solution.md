
+++
authors = ["grid47"]
title = "Leetcode 415: Add Strings"
date = "2024-09-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 415: Add Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/add-strings/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/415.webp" 
    alt="Two strings being added together, with each character gently illuminating to show the sum."
    caption="Solution to LeetCode 415: Add Strings Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
---
{{< youtube XbPJhrkROfI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #416: Partition Equal Subset Sum](https://grid47.xyz/posts/leetcode-416-partition-equal-subset-sum-solution/) |
| --- |
