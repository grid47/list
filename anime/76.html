class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> mp;
        for(char x: t) mp[x]++;

        int cnt = t.size();
        int lo, len = s.size() + 1;
        
        int i = 0;
        
        for(int j = 0; j < s.size(); j++) {
            
            if(mp.count(s[j])) {
                mp[s[j]]--;
                if(mp[s[j]] >= 0) cnt--;
            }
            
            while(cnt == 0 && i <= j) {
                if(len > j - i + 1) {
                    lo = i;
                    len = j - i + 1;
                }
                if(mp.count(s[i])) {
                    mp[s[i]]++;
                    if(mp[s[i]] >= 1) cnt++;
                }
                i++;                
            }
        }

        return len == (s.size() + 1)? "" : s.substr(lo, len);
    }
};