
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2102: Sequentially Ordinal Rank Tracker"
date = "2019-01-28"
description = "Solution to Leetcode 2102"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sequentially-ordinal-rank-tracker/description/)

---

**Code:**

{{< highlight cpp >}}
class CmpMn {
    public:
    bool operator()(pair<int, string> &a, pair<int, string> &b) {
        bool ans = false;
        if(a.first != b.first) ans = a.first < b.first;
        else ans = a.second > b.second;
        return !ans;
    }
};

class CmpMx {
    public:
    bool operator()(pair<int, string> &a, pair<int, string> &b) {
        if(a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    }
};

class SORTracker {
public:

    int i = 1;
    priority_queue<pair<int, string>, vector<pair<int, string>>, CmpMx> mx;
    priority_queue<pair<int, string>, vector<pair<int, string>>, CmpMn> mn;

    SORTracker() {
    }

    void add(string name, int score) {
        mx.push({score, name});
        mn.push(mx.top());
        mx.pop();
        if (mn.size() > i) {
            mx.push(mn.top());
            mn.pop();
        }
    }

    string get() {
        // cout<< mn.top().first << " ";
        while(mn.size() < i) {
            mn.push(mx.top());
            mx.pop();
        }
        i++;
        return mn.top().second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
