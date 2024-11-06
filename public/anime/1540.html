class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.size() != t.size()) return false;
        int n = s.size();
        vector<int> cnt(n, 0);
        vector<int> frq(26, 0);
        for(int i = 0; i < n; i++) {
            if(t[i] > s[i]) {
                cnt[i] = t[i] - s[i];
            } else if(t[i] < s[i]) {
                cnt[i] = 26 - (s[i] - t[i]);
            }
            // cout << cnt[i] << " ";
            frq[cnt[i] % 26]++;
        }

        for(int i = 1; i < 26; i++) {
            // cout << frq[i] << " ";
            if(frq[i] == 0) continue;
            long net = (long) (i + (frq[i] - 1)  * 26);
            if( net > k) return false;
        }
        
        return true;
    }
};