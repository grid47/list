class Solution {
public:
    bool queryString(string s, int n) {
        for(int i = n; i > n / 2; i--) {
            string b = bitset<32>(i).to_string();
            if(s.find(b.substr(b.find('1'))) == string::npos)
                return false;
        }
        return true;
    }
};