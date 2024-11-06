class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> graph(n);
        vector<int> cnt(n, 0);

        // Created graph and dependecy counter
        for(int i = 0; i < pre.size(); i++) {
            graph[pre[i][1]].push_back(pre[i][0]);
            cnt[pre[i][0]]++;
        }

         queue<int> q;

        // Triaged course which does not have any dependency.
        for(int i = 0; i < n; i++)
            if(cnt[i] == 0)
                q.push(i);
       

        while(!q.empty()) {
            int size = q.size();
            while(size-- > 0) {
                int course = q.front();
                q.pop();
                for(int dep: graph[course]) {

                    cnt[dep]--;

                    if(cnt[dep] == 0) {
                        q.push(dep);
                    }
                }                
            }
        }

        for(int i = 0; i < n; i++)
            if(cnt[i] != 0)
                return false;   

        return true;
    }
};