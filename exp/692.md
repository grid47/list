using tup_t = tuple<int, string>;
class cmp {
public:
    bool operator() (const tup_t &p1, const tup_t &p2) {
        if(get<0>(p1) == get<0>(p2)) return get<1>(p1) > get<1>(p2);
        else return get<0>(p1) < get<0>(p2);
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(string str: words)
            mp[str]++;

        priority_queue<tup_t, vector<tup_t>, cmp> pq;
        for(auto it: mp) {
            auto tp = make_tuple(it.second, it.first);
            pq.push(tp);
        }
        vector<string> ans;
        while(k-- > 0) {
            auto e = pq.top();
            ans.push_back(get<1>(e));
            pq.pop();
        }
        return ans;
    }
};