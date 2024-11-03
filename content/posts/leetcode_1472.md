
+++
authors = ["Crafted by Me"]
title = "Leetcode 1472: Design Browser History"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1472: Design Browser History in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/design-browser-history/description/)

---

**Code:**

{{< highlight cpp >}}
class BrowserHistory {
    vector<string> fwd, bwd;
public:
    BrowserHistory(string homepage) {
        bwd.push_back(homepage);
        fwd.resize(0);
    }
    
    void visit(string url) {
        bwd.push_back(url);
        fwd.resize(0);
    }
    
    string back(int steps) {
        int x = bwd.size();
        while(steps-- > 0 && bwd.size() > 1) {
            string p = bwd.back();
            fwd.push_back(p);
            bwd.pop_back();
        }
        return bwd.back();
    }
    
    string forward(int steps) {
        int x = fwd.size();
        while(steps-- > 0 && fwd.size() > 0) {
            string p = fwd.back();
            bwd.push_back(p);
            fwd.pop_back();
        }
        return bwd.back();        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1472.md" >}}
---
{{< youtube pvj8WQMPlGY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1473: Paint House III](https://grid47.xyz/posts/leetcode_1473) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

