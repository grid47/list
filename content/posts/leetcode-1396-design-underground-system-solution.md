
+++
authors = ["grid47"]
title = "Leetcode 1396: Design Underground System"
date = "2024-06-20"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #1400: Construct K Palindrome Strings](https://grid47.xyz/posts/leetcode-1400-construct-k-palindrome-strings-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
