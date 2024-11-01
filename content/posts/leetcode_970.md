
+++
authors = ["Crafted by Me"]
title = "Leetcode 970: Powerful Integers"
date = "2022-03-08"
description = "Solution to Leetcode 970"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/powerful-integers/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> s;
        for(int i = 1; i <= bound; i *= x) {
            for(int j = 1; i + j <= bound; j *= y) {
                s.insert(i + j);
                if(y == 1) break;
            }
            if(x == 1) break;
        }
        return vector<int>(s.begin(), s.end());
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/970.md" >}}
- by gpt
        
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

