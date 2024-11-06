
+++
authors = ["Crafted by Me"]
title = "Leetcode 146: LRU Cache"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 146: LRU Cache in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Linked List","Design","Doubly-Linked List"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/lru-cache/description/)

---

**Code:**

{{< highlight cpp >}}
class LRUCache {
public:
    map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int, int>> q;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        auto it = *mp[key];
        q.erase(mp[key]);
        q.push_front(make_pair(key, it.second));
        mp[key] = q.begin();
        return it.second;
    }
    
    void put(int key, int value) {
        if(mp.count(key)) {
            q.erase(mp[key]);
            q.push_front(make_pair(key, value));
            mp[key] = q.begin();
        } else {
            q.push_front(make_pair(key, value));
            mp[key] = q.begin();
            if(q.size() > cap) {
                mp.erase(q.back().first);
                q.pop_back();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/146.md" >}}
---
{{< youtube 7ABFKPK2hD4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #147: Insertion Sort List](https://grid47.xyz/posts/leetcode_147) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

