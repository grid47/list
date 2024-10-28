class Solution {
public:
    long long wonderfulSubstrings(string word) {
        map<int, int> mp;
        mp[0] = 1;
        int msk = 0;
        long long ans = 0;
        for(int i = 0; i < word.size(); i++) {
            
            int idx = word[i] - 'a';
            msk ^= (1 << idx);
            ans += mp[msk];
            for(int j = 0; j < 10; j++) {
                int lf = msk ^ (1 << j);
                ans += mp[lf];
                }
            mp[msk]++;
            }
        
        return ans;
    }
};