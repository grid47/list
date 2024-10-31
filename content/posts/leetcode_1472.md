
+++
authors = ["Crafted by Me"]
title = "Leetcode 1472: Design Browser History"
date = "2020-10-21"
description = "Solution to Leetcode 1472"
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



---

{{< youtube pvj8WQMPlGY >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

