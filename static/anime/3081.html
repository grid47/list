class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> frq(26, 0), taken;

        int n = s.size();
        for(char c: s) if(c != '?') frq[c - 'a']++;

        for(int i = 0; i < n; i++) {
            if(s[i] != '?') continue;

            int mn = 0;
            for(int j = 0; j < 26; j++)
                if(frq[j] < frq[mn]) mn = j;

            taken.push_back(mn);
            frq[mn]++;
        }

        sort(taken.begin(), taken.end());

        int idx = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '?')
            s[i] = taken[idx++] + 'a';
        }

        return s;
    }
};