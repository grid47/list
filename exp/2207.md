class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        
        long long cnt1 = 0, cnt2 = 0, res = 0, n = text.length();
        
        for(int i = 0; i < n; i++) {
            if(text[i] == pattern[1]) {
                cnt2++;
                res += cnt1;
            }
            if(text[i] == pattern[0]) cnt1++;
        }

        res += max(cnt1, cnt2);
        
        return res;
    }
};