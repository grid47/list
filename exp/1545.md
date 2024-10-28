class Solution {
public:
    char findKthBit(int n, int k) {

        string s = "0";
        
        for(int i = 2; i <= n; i++) {
            string tmp = s;
            s += '1';
            for(int j = tmp.size() - 1; j >= 0; j--) {
                
                s += (tmp[j] == '0') ? '1':'0';
                
            }
        }

        return s[k-1];
    }
};