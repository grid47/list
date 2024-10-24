
+++
authors = ["Yasir"]
title = "Leetcode 6: Zigzag Conversion"
date = "2024-10-19"
description = "Solution to Leetcode 6"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/zigzag-conversion/description/)

---

**Code:**

{{< highlight html >}}
#include <string>
#include <vector>
#include <iostream>
class Solution {
public:
    string convert(string str, int n) {

        int len = str.size();
        
        if(n == 1) return str;
        
        vector<string> s(n, "");

        bool down = true; int ridx = 1;
        for (int i = 0; i < len; i++) {

            s[ridx - 1] += str[i];
            if (down) ridx++;
            else      ridx--;

            if ( (ridx == n) || 
                 (ridx == 1) ) 
                down = !down;
            
        }
        string res = "";
        for(int i = 0; i < n; i++)
            res += s[i];
        return res;
    }
};
{{< /highlight >}}

