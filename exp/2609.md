class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int zr = 0, ans = 0;
        int cnt[2] = {};
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') {
                if(cnt[1]) {
                    cnt[0] = 0;
                    cnt[1] = 0;                    
                }
                cnt[0]++;
            } else {
                if(cnt[1] < cnt[0]) cnt[1]++;
                else {
                    cnt[0] = 0;
                    cnt[1] = 0;
                }
                ans = max(cnt[1] * 2, ans);
            }
        }
        return ans;
    }
};