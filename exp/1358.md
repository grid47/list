class Solution {
public:
    int numberOfSubstrings(string s) {
        return atmost(s, 3) - atmost(s, 2);
    }
    int atmost(string s, int k) {
        map<char, int> ma;
        int res = 0, j = 0;
        for(int i = 0; i < s.size(); i++) {
            ma[s[i]]++;
            if(ma[s[i]] == 1) k--;
            while(k < 0) {
                ma[s[j]]--;
                if(ma[s[j]] == 0) k++;
                j++;
            }
            res += (i - j + 1);
        }
        return res;
    }
};