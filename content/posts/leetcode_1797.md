
+++
authors = ["Crafted by Me"]
title = "Leetcode 1797: Design Authentication Manager"
date = "2019-12-02"
description = "Solution to Leetcode 1797"
tags = [
    
]
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

