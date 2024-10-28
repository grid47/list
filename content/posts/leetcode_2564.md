
+++
authors = ["Yasir"]
title = "Leetcode 2564: Substring XOR Queries"
date = "2017-10-22"
description = "Solution to Leetcode 2564"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/substring-xor-queries/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    
    string str(int n) {
        string ans = "";
        if(n == 0) return "0";
        while(n) {
            if(n & 1) {
                ans = "1" + ans;
            } else {
                ans = "0" + ans;
            }
            n >>= 1;
        }
        return ans;
    }
    
    vector<int> substr(string m, string s) {
        if(m.size() < s.size()) return vector<int>{-1, -1};
        for(int i = 0; i < m.size(); i++) {
            int j = 0;
            while(j < s.size() && i + j < m.size() && m[i + j] == s[j]) j++;
            if(j == s.size()) return vector<int>{i, i + j - 1};
        }
        return vector<int>{-1, -1};
    }
    
    vector<vector<int>> substringXorQueries(string m, vector<vector<int>>& q) {
        int n = q.size();

        map<int, vector<int>> mp;
        int k = m.size();
        for(int j = 0; j < k; j++) {
            if(m[j] == '0') {
                if(!mp.count(0)) mp[0] = {j, j};
                continue;
            }
            int num = 0;
            for(int i = j; i <= min(j + 31, k - 1); i++) {
                num = (num << 1) + (m[i] - '0');
                if(!mp.count(num)) mp[num] = {j, i};
            }
        }
        vector<vector<int>> ans(n, vector<int>{-1, -1});
        for(int i = 0; i < n; i++) {
            int num = (q[i][0] ^ q[i][1]);
            if(mp.count(num))
            ans[i] = mp[num];
        }        
        return ans;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

