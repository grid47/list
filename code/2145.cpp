class Solution {
public:
    int numberOfArrays(vector<int>& diff, long lower, long upper) {
        // last - fist of n + 1 seq
        
        long mn = 0, mx = 0, x = 0;

        for(int k : diff) {
            x += k;
            mx = max(mx, x);
            mn = min(mn, x);
        }
        
        int sum = mx - mn;
        if (upper - lower < sum)
            return 0;
        else {
            
            return (int)(upper - lower) - sum + 1;
            
        }
        
    }
};