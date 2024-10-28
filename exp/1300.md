class Solution {
public:
    int findBestValue(vector<int>& A, int target) {
        sort(A.begin(), A.end());
        
        int n = A.size(), i = 0;
        while(i < n && target > A[i] * (n - i)) {
            target -= A[i++];
        }
        
        if (i == n) return A[n - 1];
        
        int res = target / (n - i);
        
        if (target - res * (n - i) > (res + 1) * (n - i) - target)
            res++;
        return res;
    }
};