class Solution {
public:
    string maximumOddBinaryNumber(string s) {
    int i = 0, sz = s.size();
    for(int j = 0;j < sz - 1; ++j) {
        if(s[j] == '1') {
            swap(s[j], s[i]);
            ++i;
        } 
    }
    
    if(s.back() != '1') 
        swap(s[sz - 1], s[i - 1]);
    return s;
    }
};