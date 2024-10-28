class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string, string> mp;
        for(auto e: knowledge)
        mp[e[0]] = e[1];
        string res = "";
        int i = 0;
        while(i < s.size()) {
            if(s[i] == '(') {
                i++;
                string key = "";
                while(s[i] != ')') {
                    key += s[i];
                    i++;
                }

                if(mp.count(key)) {
                    res += mp[key];
                    // mp.erase(key);
                }
                else res += '?';
                i++;
            } else res += s[i++];
        }
        return res;
    }
};