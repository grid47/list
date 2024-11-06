
+++
authors = ["Crafted by Me"]
title = "Leetcode 1396: Design Underground System"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1396: Design Underground System in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Design"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/design-underground-system/description/)

---

**Code:**

{{< highlight cpp >}}
struct Node {
    int time;
    string station;
};

class UndergroundSystem {
public:
    map<string, map<string, double>> cnt, sum;
    map<int, Node> user;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string name, int t) {
        Node n;
        n.time = t;
        n.station = name;
        user[id] = n;
    }
    
    void checkOut(int id, string name, int t) {
        Node entry = user[id];
        cout << user[id].station;
        user.erase(id);
        cnt[entry.station][name]++;
        sum[entry.station][name]+= t - entry.time;
    }
    
    double getAverageTime(string start, string end) {
        return sum[start][end] / cnt[start][end];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1396.md" >}}
---
{{< youtube W5QOLqXskZM >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1397: Find All Good Strings](https://grid47.xyz/posts/leetcode_1397) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
