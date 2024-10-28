
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2246: Longest Path With Different Adjacent Characters"
date = "2018-09-05"
description = "Solution to Leetcode 2246"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-path-with-different-adjacent-characters/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int longestPath(vector<int>& par, string s) {
        int mx = 1;

        int n = s.size();
        vector<int> memo(n, -1), in(n, 0);

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(par[i] != -1) {
                in[par[i]]++;
            }
        }
        for(int i = 0; i < n; i++) {
            if(in[i] == 0) {
                q.push(i);
                memo[i] = 1;
            }
        }
        
        while(!q.empty()) {
            int idx = q.front();
            q.pop();
            if(idx == 0) continue;
            if(s[idx] != s[par[idx]]) {
                if(memo[par[idx]] != -1) {
                    mx = max(mx, memo[par[idx]] + memo[idx]);                    
                }
                if(memo[par[idx]] == -1) {
                    if(memo[idx] == -1) cout << "Yes";
                    memo[par[idx]] = 1 + memo[idx];
                } else if(memo[par[idx]] < 1 + memo[idx]) {
                    memo[par[idx]] = 1 + memo[idx];
                }
                mx = max(mx, memo[par[idx]]);                

            }
                in[par[idx]]--;
                if(in[par[idx]] == 0) {
                    q.push(par[idx]);
                    if(memo[par[idx]] == -1)
                        memo[par[idx]] = 1;
                }

                
        }
        
        return mx;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

