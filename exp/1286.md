class CombinationIterator {
public:
    string str;
    int len;
    vector<string> ans;
    map<int, int> mp;
    void bt(int idx, string &tmp) {
        if(tmp.size() == len) {
            ans.push_back(tmp);
            return;
        }
        if(idx == str.size()) {
            return;
        }
        
        for(int i = idx; i < str.size(); i++) {
            tmp += str[i];
            bt(i + 1, tmp);
            tmp.pop_back();
        }
        
    }
    int idx = 0;
    CombinationIterator(string chars, int len) {
        this->len = len;
        sort(chars.begin(), chars.end());
        str = chars;
        string tmp = "";
        bt(0, tmp);
    }
    
    string next() {
        return ans[idx++];
    }
    
    bool hasNext() {
        if(idx < ans.size()) return true;
        return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */