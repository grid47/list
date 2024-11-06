
+++
authors = ["Crafted by Me"]
title = "Leetcode 415: Add Strings"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 415: Add Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Simulation"]
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
---
{{< youtube XbPJhrkROfI >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #416: Partition Equal Subset Sum](https://grid47.xyz/posts/leetcode_416) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
