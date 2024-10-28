class Solution {
public:
    int mod = (int) 1e9 + 7;
    
    
    int numberOfWays(string corridor) {
        int n = corridor.size();
        vector<int> itr;
        for(int i = 0; i < n; i++)
            if(corridor[i] == 'S') 
                itr.push_back(i);
        
        if((itr.size() % 2) || (itr.size() == 0)) return 0;
        
        long long res = 1;
        
        int prv = itr[1];
        
        for(int i = 2; i < itr.size(); i += 2) {
            
            int len = itr[i] - prv;
            
            res = (res * len) % mod;
            
            prv = itr[i + 1];
        }
        return res;
    }
};