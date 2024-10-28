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