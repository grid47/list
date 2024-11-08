class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& eqn, vector<double>& val, vector<vector<string>>& q) {
        map<string, vector<pair<string, double>>> graph;
        
        for(int i = 0; i < eqn.size(); i++) {
            double w = val[i];
            graph[eqn[i][0]].push_back(make_pair(eqn[i][1], w));
            if (w == 0) continue;
            graph[eqn[i][1]].push_back(make_pair(eqn[i][0], 1 / w));
        }
        
        vector<double> ans;
        
        for(int i = 0; i < q.size(); i++) {
            set<string> vis;
            double res = dfs(q[i][0], q[i][1], vis, graph);
            if(res < 0) res = -1;
            ans.push_back(res);
        }
        return ans;
    }
    
    double dfs(string start, string end, set<string> &vis, map<string, vector<pair<string, double>>> &gph) {
        
        if(start == end) return gph.count(start)? 1: -1;
        vis.insert(start);
        double ans = -1;
        for(pair<string, double> x: gph[start]) {
            if(vis.count(x.first)) continue;

            double res = x.second * dfs(x.first, end, vis, gph);
            if(res < 0) continue;
            return res;
        }
        return ans;
    }
};