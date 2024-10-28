class Solution {
public:
    int maxConsecutiveAnswers(string key, int k) {
        int ans = 1;
        int fidx = 0, tidx = 0, fcnt = 0, tcnt = 0;
        for(int i = 0; i < key.size(); i++) {
            if(key[i] == 'F') fcnt++;
            else tcnt++;
            while(fcnt > k) {
                if(key[tidx] == 'F') fcnt--;
                tidx++;
            }
            ans = max(ans, i - tidx + 1);
            while(tcnt > k) {
                if(key[fidx] == 'T') tcnt--;
                fidx++;
            }
            ans = max(ans, i - fidx + 1);            
        }
        return ans;
    }
};