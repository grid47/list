class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        
        map<int, int> h;
        for(int i = 0; i < target.size(); i++)
            h[target[i]] = i;
        
        vector<int> stk;
        for(int num: arr) {
            
            if(!h.count(num)) continue;
            
            if(stk.size() == 0 || h[num] > stk.back()) {
                stk.push_back(h[num]);
                continue;
            }
            
            int l = 0, r = stk.size() - 1;
            
            while(l < r) {
                int mid = l + (r - l) / 2;
                
                if(stk[mid] < h[num])
                    l = mid + 1;
                else r = mid;
            }
            
            stk[l] = h[num];

        }
        
        return target.size() - stk.size();
    }
};