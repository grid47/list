
+++
authors = ["grid47"]
title = "Leetcode 2564: Substring XOR Queries"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2564: Substring XOR Queries in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/substring-xor-queries/description/)

---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2564.md" >}}
---
{{< youtube 0J1aVGfArWs >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2566: Maximum Difference by Remapping a Digit](https://grid47.xyz/posts/leetcode_2566) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
