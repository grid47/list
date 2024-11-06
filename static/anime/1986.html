class Solution {
public:
    vector<int> task;
    // map<int, map<int, int>> memo; map is costly
    int memo[1<<15][16];
    int minSessions(vector<int>& tasks, int sessionTime) {
        this->task = tasks;
        map<int, int> mp;
        int mask = 0;
        int tgt = ~(~0u << task.size());
        memset(memo, -1, sizeof(memo));
        // for(int i = 0; i < task.size(); i++)
        //     tgt |= 1 << i;
        return bt(tgt, 0, sessionTime, mask);
        
    }
    
    int bt(int tgt, int net, int st, int mask) {
        if(tgt == mask) {
            return 1;
        }
        if(memo[mask][net] != -1) return memo[mask][net];
        
        int ans = task.size();
        for(int i = 0; i < task.size(); i++) {
            if((mask >> i) & 1) continue;
            mask |= (1 << i);
            if(net + task[i] > st)
                ans = min(ans, 1 + bt(tgt, task[i], st, mask));
            else
                ans = min(ans, bt(tgt, net + task[i], st, mask));
            mask ^= (1 << i);
        }
        return memo[mask][net] = ans;
    }
    
};