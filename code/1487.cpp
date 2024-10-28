class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        map<string, int> mp;
        
        for(int i = 0; i < names.size(); i++) {
            
            if(mp.count(names[i])) {
                int k = mp[names[i]];
                while(mp.count(names[i] + "(" + to_string(k) + ")")) {
                    k++;
                    mp[names[i]]++;
                }
                mp[names[i]]++;
                names[i] = names[i] + "(" + to_string(k) + ")";
            }

            mp[names[i]] = 1;
        }
        return names;
    }
};