class Solution {
public:
    int takeCharacters(string s, int k) {
        
        map<char, int> mp;
        for(int i = 0; i < s.size(); i++)
            mp[s[i]]++;
        if(mp['a'] < k || mp['b'] < k || mp['c'] < k) return -1;
        
        int j = 0, mx = 0;
        for(int i = 0; i < s.size(); i++) {
            // select max window which does not decrements frq below k;
            mp[s[i]]--;
            while(j <= i && mp[s[i]] < k) {
                mp[s[j]]++;
                j++;
            }
            mx = max(mx, i - j + 1);
        }
        return s.size() - mx;
    }
};