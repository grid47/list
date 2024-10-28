class Solution {
public:
    bool isValid(string s) {
        vector<char> stk;
        for(char c : s) {
            if(c == 'c') {
                int n = stk.size();
                if(n < 2 ||
                  stk[n - 1] != 'b' ||
                  stk[n - 2] != 'a' ) 
                    return false;
                stk.pop_back();
                stk.pop_back();
            } else stk.push_back(c);
        }
        
        return stk.size() == 0;
    }
};