class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& q) {
        int n = s.length();
        vector<int> left(n, 0), right(n, 0), count(n, 0), ans(q.size(), 0);
        int node = -1;
        int cnt  = 0;
        for(int i = 0; i < n; i++) {
            
            if(s[i] == '|') {

                node = i;
                cnt++;
            }

            left[i]  = node;
            count[i] = cnt;

        }
        
        node = -1;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '|'){
                node = i;
            }
            right[i] = node;
            
        }
        
        int idx = 0;
        for(vector<int> qr : q) {



            int r = left[qr[1]];
            int l = right[qr[0]];
           // int c = count[r] - count[l] + 1;
            
            if (r == -1 || l == -1 || r - l <= 1) {

                ans[idx] = 0;

            } else {
int c = count[r] - count[l] +1;
     ans[idx] = r - l + 1 - c;

            }
            
            idx++;
        }
        return ans;
    }
};