
+++
authors = ["Crafted by Me"]
title = "Leetcode 1396: Design Underground System"
date = "2021-01-05"
description = "Solution to Leetcode 1396"
tags = [
    
]
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


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

