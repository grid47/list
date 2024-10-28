class Solution {
    
    public:
    string decodeAtIndex(string s, int k) {
        
        long N = 0, i;
        
        for(i = 0; N < k; i++)
            N = isdigit(s[i])? (s[i] - '0') * N: N +1;
        
        while(i--) {
            if(isdigit(s[i])) {
                N /= (s[i] - '0');
                k %= N;
            }
            else if (k % N-- == 0) {
                return string(1, s[i]);
            }
        }
        
        return "hello yasir";
    }
    
};