class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& pos) {
        sort(pos.begin(), pos.end());
        
        int low = INT_MAX;
        int j = 0, n = pos.size();
        for(int i = 0; i < n; i++) {
            while(pos[i] - pos[j] + 1 > n) j++;
            
            int cnt = i - j + 1;
            
            if(cnt == n - 1 && pos[i] - pos[j] + 1 == n - 1)
                low = min(low, 2);
            else low = min(low, n - cnt);
        }
        return vector<int>{low, max(pos[n - 1] - pos[1] + 1 - (n - 1), pos[n - 2] - pos[0] + 1 - (n - 1))};
    }
};