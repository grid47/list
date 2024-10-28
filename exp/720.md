class Solution {
public:
    string longestWord(vector<string>& words) {
    
        sort(words.begin(),words.end());
        unordered_set<string> mp;
        string res="";
        
        for(string w: words){
            if(w.size() == 1 || mp.count(w.substr(0, w.size() -1))) {
                res = w.size()>res.size()? w:res;
                mp.insert(w);
            }
        }
        return res;
    }

};