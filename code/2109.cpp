class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int i = 0;
        string res = "";
        for(int idx : spaces) {
            while(i < idx) res += s[i++];
            if(i == idx) res += ' ';
        }
        while(i < s.size()) res += s[i++];        
        return res;
    }
};