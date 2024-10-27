
+++
authors = ["Yasir"]
title = "Leetcode 1963: Minimum Number of Swaps to Make the String Balanced"
date = "2019-06-14"
description = "Solution to Leetcode 1963"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minSwaps(string s) {
        stack<char> stk;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(s[i] == '[') stk.push(i);
            else if(!stk.empty()) stk.pop();
        }
        
        return (stk.size() + 1) / 2;
    }
};
{{< /highlight >}}

