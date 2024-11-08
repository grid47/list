class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int cand) {
        long long cost = 0;
        int n = costs.size();
        int l = cand - 1, r = n - cand; // inclusive
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        if(l >= r) {
            for(int i = 0; i < n; i++)
                pq.push({costs[i], i});
            
            while(k--) {
                cost += pq.top()[0];
                pq.pop();
            }
            return cost;
        }
        
        
        int i = 0;
        while(i <= l) {
            pq.push({costs[i], i});
            i++;
        }
        
        i = n - 1;
        
        while(i >= r) {
            pq.push({costs[i], i});
            i--;
        }
        
        while(k--) {
            auto it = pq.top();
            pq.pop();
            cost += it[0];
            if(it[1] <= l && l < r - 1) {
                l++;
                pq.push({costs[l], l});
            } else if(it[1] >= r && l < r - 1) {
                r--;
                pq.push({costs[r], r});
            }
            
        }
        return cost;
    }
};