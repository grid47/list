
+++
authors = ["grid47"]
title = "Leetcode 1797: Design Authentication Manager"
date = "2024-05-11"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1798: Maximum Number of Consecutive Values You Can Make](https://grid47.xyz/posts/leetcode-1798-maximum-number-of-consecutive-values-you-can-make-solution/) |
| --- |
