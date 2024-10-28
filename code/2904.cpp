class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        
        int n = s.size();
        string ans = "";
        int j = 0, cnt = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1') cnt++;

            while( j < n && cnt == k )
            {
                string tmp = s.substr(j, i - j + 1);

                if(ans.size()==0 || tmp.size() < ans.size()) ans = tmp;
                else if(tmp.size() == ans.size()) ans = min(ans, tmp);

                if(s[j] == '1') cnt--;

                j++;
            }
        }

        return ans;        
        
    }
};