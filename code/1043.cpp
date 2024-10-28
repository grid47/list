class Solution {
public:
    vector<int> memo;
    vector<int> arr;
    int k;
    int dp(int i) {
        if(i == arr.size()) return 0;
        if(memo[i] != -1) return memo[i];
        int res = 0, mx = 0;
        for(int j = i; j < min((int)arr.size(), i + k); j++) {
            mx = max(mx, arr[j]);
            res = max(res, mx * (j - i + 1) + dp(j + 1));
        }
        return memo[i] = res;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        this->arr = arr;
        this->k = k;
        memo.resize(arr.size(), -1);
        return dp(0);
    }
};