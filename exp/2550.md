class Solution {
public:
    int mod = (int) 1e9 + 7;
    
    int power(int a, int n) {
        if(n == 0) return 1;
        long long res = power(a, n/2) % mod;

        long long y = (res * res) %mod;
        // cout << (int) y << " " ;
        if(n & 1) {
            y = (a * y) % mod;
            return y;            
        }
        return y % mod;
    }
    
    int monkeyMove(int n) {
        
        int res = power(2, n);
        
        return (res - 2)<0? mod - res:res-2 ;
    }
};