class Solution {
public:
    string reorganizeString(string s) {
        int mfq = 0, i = 0;
        
        vector<int> frq(26, 0);
        for(char c: s)
            if (++frq[c - 'a'] > frq[mfq])
                mfq = c - 'a';
        
        // if mfq over bounds return ""
        if(2 * frq[mfq] - 1 > s.size()) return "";
        /*  dist mfq across
            dist rest across */
        while(frq[mfq]) {
            s[i] = 'a' + mfq;
            i += 2;
            frq[mfq]--;
        }

        for(int j = 0; j < 26; j++) {
            while(frq[j]) {
                if(i >= s.size()) i = 1;
                s[i] = 'a' + j;
                frq[j]--;
                i += 2;
            }
        }
        
        return s;
        
    }
};