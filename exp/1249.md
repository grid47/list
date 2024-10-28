class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> stk, itk;
        for(int i = 0; i < s.length(); i++) {
            char a = s[i];
                 if(a == '(') { stk.push_back(i); }
            else if(a == ')') {
                     if(stk.size()    == 0)    stk.push_back(i);
                else if(s[stk.back()] == '(')  stk.pop_back();
                else stk.push_back(i);
            }
        }
        string res = "";
        set<int> st(stk.begin(), stk.end());
        for(int i = 0; i < s.length(); i++) {
            if(st.count(i)) continue;
            res += s[i];
        }
        return res;        
    }
};