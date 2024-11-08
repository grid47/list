class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        
        vector<vector<int>> gph(n);
        vector<int> incnt(n, 0);
        for(int i = 0; i < pre.size(); i++) {
            gph[pre[i][1]].push_back(pre[i][0]);
            incnt[pre[i][0]]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++)
            if(incnt[i] == 0)
                q.push(i);
        vector<int> ans;
        while(!q.empty()) {
            int y = q.front();
            ans.push_back(y);
            q.pop();
            for(auto x: gph[y]) {
                incnt[x]--;
                if(incnt[x] == 0)
                    q.push(x);
            }
        }
        return ans.size() == n? ans: vector<int>();
    }
};