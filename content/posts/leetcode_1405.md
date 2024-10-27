
+++
authors = ["Yasir"]
title = "Leetcode 1405: Longest Happy String"
date = "2020-12-23"
description = "Solution to Leetcode 1405"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-happy-string/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        priority_queue<pair<int, char>, vector<pair<int, char>>, less<pair<int, char>>> pq;
        if(a > 0)
        pq.push({a, 'a'});
        if(b > 0)
        pq.push({b, 'b'});
        if(c > 0)
        pq.push({c, 'c'});
        
        string res = "";
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            res += string(min(2, it.first), it.second);
            it.first -= min(2, it.first);
            
            if(pq.empty()) break;
            auto it2 = pq.top();
            pq.pop();
            res += string(min(it.first > it2.first? 1: 2, it2.first), it2.second);
            it2.first -= min(it.first > it2.first? 1: 2, it2.first);
            
            if(it.first > 0) pq.push(it);
            if(it2.first > 0) pq.push(it2);
        }
        
        return res;
    }
};
{{< /highlight >}}

