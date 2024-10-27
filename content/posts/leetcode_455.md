
+++
authors = ["Yasir"]
title = "Leetcode 455: Assign Cookies"
date = "2023-07-31"
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

{{< highlight html >}}
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

