
+++
authors = ["grid47"]
title = "Leetcode 146: LRU Cache"
date = "2024-10-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 146: LRU Cache in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Linked List","Design","Doubly-Linked List"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/lru-cache/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/146.webp" 
    alt="A cache where items are gently shifting in and out, with the most recently used glowing brightly."
    caption="Solution to LeetCode 146: LRU Cache Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #150: Evaluate Reverse Polish Notation](https://grid47.xyz/leetcode/solution-150-evaluate-reverse-polish-notation/) |
| --- |
