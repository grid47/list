class Solution {
public:
    int largestVariance(string s) {
        
        int ans = 0;
        unordered_set<int> num(s.begin(), s.end());
        
        for(char a: num)
        for(char b: num) {
            int var = 0, first_b = 0, has_b = 0;
            for(char c: s) {
                
                var += c == a;
                
                if(c == b) {
                    has_b = true;
                    if(first_b && var >= 0)
                        first_b = false;
                    else if(--var < 0) {
                        var = -1;
                        first_b = true;
                    }
                }
                ans = max(ans, has_b? var: 0);                
            }

        }
        return ans;
        
    }
};