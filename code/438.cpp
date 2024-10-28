class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pc(26, 0), sc(26, 0);
        for(char x: p)
            pc[x-'a']++;
        
        vector<int> ans;
        for(int i = 0; i < s.size(); i++) {
            if(i >= p.size()) {
                sc[s[i - p.size()] - 'a']--;
            }
            sc[s[i]-'a']++;
            if(sc == pc) ans.push_back(i - p.size() +1);
        }
        return ans;
    }
};