
+++
authors = ["Crafted by Me"]
title = "Leetcode 2337: Move Pieces to Obtain a String"
date = "2018-06-10"
description = "In-depth solution and explanation for Leetcode 2337: Move Pieces to Obtain a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/move-pieces-to-obtain-a-string/description/)

---

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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

