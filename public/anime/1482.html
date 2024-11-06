class Solution {
public:
    int isValid(vector<int> &bloom, int m, int mid, int k) {
        int bough = 0, cnt = 0;
        
        for(int i = 0; i < bloom.size(); i++) {
            if(bloom[i] > mid) {
                cnt = 0;
            } else if(++cnt >= k) {
                cnt = 0;
                bough++;
            }
        }
        if(bough >= m) return true;
        else return false;
    }
    
    int minDays(vector<int>& bloom, int m, int k) {
        int n = bloom.size();
        if((long)m * k > n) return -1;
        
        int l = 1, r = (int) 1e9, result;
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(isValid(bloom, m, mid, k)) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return result;
        
    }
};