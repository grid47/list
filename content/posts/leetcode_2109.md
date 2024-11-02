
+++
authors = ["Crafted by Me"]
title = "Leetcode 2109: Adding Spaces to a String"
date = "2018-01-23"
description = "Solution to Leetcode 2109"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/adding-spaces-to-a-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int i = 0;
        string res = "";
        for(int idx : spaces) {
            while(i < idx) res += s[i++];
            if(i == idx) res += ' ';
        }
        while(i < s.size()) res += s[i++];        
        return res;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

