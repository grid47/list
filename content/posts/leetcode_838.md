
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 838: Push Dominoes"
date = "2022-07-15"
description = "Solution to Leetcode 838"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/push-dominoes/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string pushDominoes(string d) {
        d = 'L' + d + 'R';
        string res = "";
        for(int i = 0, j = 1; j < d.length(); j++) {
            if(d[j] == '.') continue;
            int middle = j - i - 1;
            if(i > 0) 
                res += d[i];
            if(d[i] == d[j])
                res += string(middle, d[i]);
            else if (d[i] == 'L' && d[j] == 'R')
                res += string(middle, '.');
            else 
                res += string(middle/2, 'R') + string(middle%2, '.') + string(middle/2, 'L');
            i = j;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/838.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
