
+++
authors = ["Crafted by Me"]
title = "Leetcode 455: Assign Cookies"
date = "2022-08-04"
description = "Solution to Leetcode 455"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/assign-cookies/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i = 0, j=0;
        while(i<g.size() && j<s.size()){
            if(s[j]>=g[i])
                i++; // when the child get the cookie, foward child by 1
            j++;
        }
        return i;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/455.md" >}}
---
{{< youtube AXaPmVMkVAE >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

