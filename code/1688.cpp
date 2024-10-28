class Solution {
public:
    int numberOfMatches(int n) {
        if(n==0) return 0;
        if(n==1) return 0;
        int ans = n / 2;
        if(n & 1)
        ans += numberOfMatches(n/2 + 1);
        else
        ans += numberOfMatches(n/2);
        return ans;
    }
};