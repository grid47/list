class Solution {
public:
    
    int minCost(string colors, vector<int>& cost) {
        
        int res = 0, sum, mx;
        
        int i = 1, n = cost.size();
        
        while(i < n) {
            int e = i;
            sum = cost[e - 1];
            mx = cost[e - 1];
            
            while(e < n && colors[e] == colors[e-1]) {
                sum += cost[e];
                mx = max(mx, cost[e]);
                e++;
            }
            
            res += (sum-mx);
            
            i = e + 1;
        }
        return res;
    }
};