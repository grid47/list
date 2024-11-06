class Solution {
public:
    string removeDuplicateLetters(string s) {

        vector<int> frq(26, 0), lidx(26, 0);

        for (int i = 0; i < s.size(); i++) {
            char x = s[i];
            frq[x - 'a']++;
            lidx[x - 'a'] = i;
        }

        vector<bool> seen(26, false);
        stack<char> st;

        for(int i = 0; i < s.size(); i++) {

            int cur = s[i] - 'a';            
            if(seen[cur]) continue;

            while(st.size() > 0 && st.top() > s[i] && i < lidx[st.top() - 'a']) {
                seen[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(s[i]);
            seen[cur] = true;
        }

        string ans = "";
        while(st.size() > 0) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};