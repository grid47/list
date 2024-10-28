class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        for(int i = 0; i < tasks.size(); i++)
            tasks[i].push_back(i);
        
        sort(tasks.begin(), tasks.end());
        
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        long i = 0, time = 0;
        while(i < tasks.size() || pq.size()) {

            if(pq.empty()) {
                time = max(time, (long) tasks[i][0]);
            }
            
            while(i < tasks.size() && tasks[i][0] <= time) {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }
            
            auto [pro, idx] = pq.top();
            pq.pop();
            time += pro;
            ans.push_back(idx);

        }

        return ans;
    }
};