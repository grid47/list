class Solution {
public:
    string addBinary(string a, string b) {
        
        int cr = 0;
        string res = "";
        while(!a.empty() || !b.empty() || cr) {
            if(!a.empty()) {
                cr += a.back() - '0';
                a.pop_back();
            }
            if(!b.empty()) {
                cr += b.back() - '0';
                b.pop_back();
            }
            
            res = to_string(cr % 2) + res;
            cr /= 2;
        }
        return res;
    }
};