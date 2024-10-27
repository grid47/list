
+++
authors = ["Yasir"]
title = "Leetcode 1111: Maximum Nesting Depth of Two Valid Parentheses Strings"
date = "2021-10-13"
description = "Solution to Leetcode 1111"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> groups;
        int d = 0;
        for(char c: seq) {
            bool open = c == '(';
            if(open) d++;
            groups.push_back(d%2);
            if(!open) d--;
        }
        return groups;
    }
};
{{< /highlight >}}

