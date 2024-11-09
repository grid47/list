
+++
authors = ["grid47"]
title = "Leetcode 1797: Design Authentication Manager"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1797: Design Authentication Manager in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Linked List","Design","Doubly-Linked List"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/design-authentication-manager/description/)

---
**Code:**

{{< highlight cpp >}}
class AuthenticationManager {
public:
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    map<string, int> mp;
    int ttl;
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        while(!pq.empty() && currentTime >= pq.top().first) {
            mp[pq.top().second]--;
            if(mp[pq.top().second] == 0) mp.erase(pq.top().second);
            pq.pop();
        }
        pq.push({currentTime + ttl, tokenId});
        mp[tokenId]++;
    }
    
    void renew(string tokenId, int currentTime) {
        while(!pq.empty() && currentTime >= pq.top().first) {
            mp[pq.top().second]--;
            if(mp[pq.top().second] == 0) mp.erase(pq.top().second);
            pq.pop();
        }
        if(mp.count(tokenId)) {
            pq.push({currentTime + ttl, tokenId});            
            mp[tokenId]++;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        while(!pq.empty() && currentTime >= pq.top().first) {
            mp[pq.top().second]--;
            if(mp[pq.top().second] == 0) mp.erase(pq.top().second);
            pq.pop();
        }
        return mp.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1797.md" >}}
---
{{< youtube IG6X2CXMdKw >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1798: Maximum Number of Consecutive Values You Can Make](https://grid47.xyz/posts/leetcode-1797-design-authentication-manager-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
