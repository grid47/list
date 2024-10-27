
+++
authors = ["Yasir"]
title = "Leetcode 838: Push Dominoes"
date = "2022-07-13"
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

{{< highlight html >}}
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

