class Solution {
public:
    map<string, priority_queue<string, vector<string>, greater<string>>> gph;
    list<string> res;
    vector<string> findItinerary(vector<vector<string>>& tcks) {

        gph.clear();
        for(auto it: tcks) {
            gph[it[0]].push(it[1]);
        }
        dfs("JFK");

        vector<string> ans;
        for(auto it: res)
            ans.push_back(it);
        return ans;
    }
    
    void dfs(string from) {

        while(gph.count(from) && !gph[from].empty()) {
            string x = gph[from].top();
            gph[from].pop();
            dfs(x);
        }
        res.push_front(from);        
    }
};