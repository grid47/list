class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int cnt[26] = {}, m_cnt = 0;
        for (auto ch : s)
            m_cnt = max(m_cnt, ++cnt[ch - 'a']);
        return all_of(begin(cnt), end(cnt), [&m_cnt](int t){ return t == 0 || t == m_cnt; });
    }
};