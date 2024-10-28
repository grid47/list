class Solution {
public:
    long long reverse(long long n, int skip) {
        long long res = 0;
        for(n = skip?n/10: n; n > 0; n/=10)
            res = res * 10 + n % 10;
        return res;
    }
    
    vector<long long> kthPalindrome(vector<int>& queries, int sz) {
        vector<long long> ans;
        long long start = pow(10, (sz + 1)/2-1), end = pow(10, (sz + 1)/2), mul= pow(10, sz/2);
        for(auto q: queries)
            if(start + q > end)
                ans.push_back(-1);
            else {
                long long res = (start + q - 1) * mul + reverse(start + q - 1, sz % 2);
                ans.push_back(res);
            }
        
        return ans;
    }
};