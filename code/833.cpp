class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        /*
        
        string s
        indices - arr of int
        src       arr of str
        tgt       arr of str
        
        */
        
        vector<pair<int, int>> ind;
        
        for(int i = 0; i < indices.size(); i++)
            ind.push_back({indices[i], i});
        
        sort(ind.rbegin(), ind.rend());
        
        for(auto it: ind) {
            string src = sources[it.second], tgt = targets[it.second];
            if(s.substr(it.first, src.size()) == src)
                s = s.substr(0, it.first) + tgt + s.substr(it.first+ src.size());
        }
        
        return s;
    }
};