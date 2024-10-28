class Solution {
public:
    int minAnagramLength(string s) {
        // 12,  4
        // aaxxbb
        // bbxxaa

        int n = s.size();
        map<char, int> mp;        
        for(char x: s)
            mp[x]++;

        int mn = mp[s[0]];
        for(auto it: mp)
        mn = __gcd(mn, it.second);

        return n / mn;
    }
};