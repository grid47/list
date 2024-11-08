class Solution {
public:
    
    bool isPossible(long long mx, long long div1, long long div2, long long unq1, long long unq2) {
        long long a = mx / div1;
        long long a_ = mx - a;
        long long b = mx / div2;
        long long b_ = mx - b;
        long long aib = mx / (long long)lcm(div1, div2);
        long long aub = a + b - aib;
        long long a_ib_ = mx - aub;
        long long neededA = (a_ - a_ib_ >= unq1) ? 0: unq1 - (a_ - a_ib_);
        long long neededB = (b_ - a_ib_ >= unq2) ? 0: unq2 - (b_ - a_ib_);        
        
        return a_ib_ >= neededA + neededB;
    }
    
    int minimizeSet(int div1, int div2, int unq1, int unq2) {
        
        long long l = 1, r = (long long) pow(10, 17), ans = 1;
        
        
        while(l <= r) {
            long long mid = l + (r - l + 1) / 2;
            if(isPossible(mid, div1, div2, unq1, unq2)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return ans;
    }
};