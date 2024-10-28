class Solution {
public:
    string removeOccurrences(string s, string part) {
        string x = s;
        int m = part.size(), n = s.size(), i, j;
        for(i = 0, j = 0; i < n; i++) {
            x[j++] = s[i];
            if (j >= m && x.substr(j - m, m) == part)
                j -= m;
        }
        return x.substr(0, j);
    }
};