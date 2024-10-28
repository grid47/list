
+++
authors = ["Yasir"]
title = "Leetcode 146: LRU Cache"
date = "2024-06-05"
description = "Solution to Leetcode 146"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/lru-cache/description/)

---

**Code:**

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

