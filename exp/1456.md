class Solution {
public:
    int vowels[26] = {  1,0,0,0,1, 0,0,0,1,0, 
                        0,0,0,0,1, 0,0,0,0,0, 
                        1,0,0,0,0, 0 };
    int maxVowels(string s, int k) {
        int mx = 0;
        for(int i = 0, cur = 0; i < s.size(); i++) {
            cur += vowels[s[i] - 'a'];
            if(i >= k) cur -= vowels[s[i-k] - 'a'];
            mx = max(cur, mx);
        }
        return mx;
    }
};