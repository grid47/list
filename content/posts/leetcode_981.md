
+++
authors = ["Crafted by Me"]
title = "Leetcode 981: Time Based Key-Value Store"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 981: Time Based Key-Value Store in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Hash Table","String","Binary Search","Design"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/time-based-key-value-store/description/)

---

**Code:**

{{< highlight cpp >}}
class TimeMap {
public:
    map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(make_pair(timestamp, value));
    }
    
    string get(string key, int ts) {
        if(!mp.count(key)) return "";
        // vector<pair<int, string>> v = &mp[key];
        int l = 0, r = mp[key].size() - 1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(ts > mp[key][m].first) {
                if(m == r || ts < mp[key][m + 1].first)
                    return mp[key][m].second;
                l = m + 1;
            } else if(ts < mp[key][m].first)
                r = m - 1;
            else return mp[key][m].second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/981.md" >}}
---
{{< youtube eVi4gDimCoo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #982: Triples with Bitwise AND Equal To Zero](https://grid47.xyz/posts/leetcode_982) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

