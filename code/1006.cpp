class Solution {
public:
    int clumsy(int n) {
        
        int ans = n;
        int j = n - 1;
        vector<int> stk;
        
        for(int i = 1; i < n; i++) {
            
                 if(i % 4 == 1) ans *= j--;
            else if(i % 4 == 2) ans /= j--;
            else {
                
                stk.push_back(ans);
                
                if(i % 4 == 3) ans = j--;
                        else   ans = (-1 * j--);
                
            }
            
        }
        
        int sum = 0;
        for(int i = 0; i < stk.size(); i++)
            sum += stk[i];
        
        return sum + ans;
        
    }
};