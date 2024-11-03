
+++
authors = ["Crafted by Me"]
title = "Leetcode 6: Zigzag Conversion"
date = "2024-10-27"
description = "In-depth solution and explanation for Leetcode 6: Zigzag Conversion in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/6.md" >}}
---
{{< youtube 2NMMVnxV6lo >}}

"| 7: Reverse Integer |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

