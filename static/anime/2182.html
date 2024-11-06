class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for(char ch: s) freq[ch - 'a']++;
        priority_queue<pair<char, int>> pq;

        for(int i = 0; i < 26; i++)
        if(freq[i] > 0) pq.push(make_pair((char) 'a' + i, freq[i]));

        string ans = "";
        while(!pq.empty()) {
            pair<char, int> p = pq.top();
            pq.pop();
            int cnt = p.second;
            for(int i = 0; i < repeatLimit && cnt-- > 0; i++) ans.push_back(p.first);

            if(cnt > 0 && !pq.empty()) {
                pair<char, int> sp = pq.top();
                pq.pop();
                ans.push_back(sp.first);
                if(sp.second > 1) {
                    sp.second--;
                    pq.push(sp);
                }
                p.second = cnt;
                pq.push(p);
            }
        }
        return ans;
    }
};