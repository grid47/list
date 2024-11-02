
+++
authors = ["Crafted by Me"]
title = "Leetcode 943: Find the Shortest Superstring"
date = "2022-04-04"
description = "Solution to Leetcode 943"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-shortest-superstring/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int calc(string &a, string &b) {
        for(int i = 0; i < a.size(); i++) {
            if(b.rfind(a.substr(i), 0) == 0) {
                return b.size() - a.size() + i;
            }
        }
        return b.size();
    }
    
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> grid(n, vector<int>(n, 0));
        
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            grid[i][j] = calc(words[i], words[j]);
            grid[j][i] = calc(words[j], words[i]);
        }
        
        vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX)), path(1 << n, vector<int>(n, 0));
        
        int last = 1, mn = INT_MAX;
        
        for(int i = 1; i < (1 << n); i++) {
            
            for(int j = 0; j < n; j++) {
                if((i & (1 << j)) > 0) {
                    int prv = i - (1 << j);
                    if(prv == 0) {
                        dp[i][j] = words[j].size();
                    } else {
                        for(int k = 0; k < n; k++) {
                            if( dp[prv][k] < INT_MAX && (dp[prv][k] + grid[k][j]) < dp[i][j]) {
                                dp[i][j] = dp[prv][k] + grid[k][j];
                                path[i][j] = k;
                            }
                        }
                    }
                }
                if((i == ((1 << n) -1)) && dp[i][j] < mn) {
                    mn = dp[i][j];
                    last = j;
                }
            }
        }
        
        
        int cur = (1 << n) - 1;
        stack<int> stk;
        while( cur > 0 ) {
            stk.push(last);
            int tmp = cur;
            cur -= (1 << last);
            last = path[tmp][last];
        }
        
        int i = stk.top();
        stk.pop();
        string res = words[i];
        while(!stk.empty()) {
            int j = stk.top();
            stk.pop();
            // cout << words[j].size() << " " << grid[i][j] << "\n";
            res += words[j].substr(words[j].size() - grid[i][j]);
            i = j;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/943.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

