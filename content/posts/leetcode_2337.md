
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2337: Move Pieces to Obtain a String"
date = "2018-06-08"
description = "Solution to Leetcode 2337"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/move-pieces-to-obtain-a-string/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canChange(string start, string target) {
        queue<pair<int, int>> ss, ts;

        for(int i = 0; i < start.size(); i++)
        if(start[i] != '_') ss.push({start[i], i});

        for(int i = 0; i < target.size(); i++)
        if(target[i] != '_') ts.push({target[i], i});

        if(ss.size() != ts.size()) return false;

        while(!ss.empty()) {
            auto s = ss.front();
            auto t = ts.front();
            ss.pop();
            ts.pop();
            if(s.first != t.first) return false;

            if(s.first == 'L' && t.second > s.second)
            return false;
            if(t.first == 'R' && t.second < s.second)
            return false;
        }

        return true;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

