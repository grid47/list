
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1722: Minimize Hamming Distance After Swap Operations"
date = "2020-02-13"
description = "Solution to Leetcode 1722"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
    vector<int> parent, rnk;
public:
    int minimumHammingDistance(vector<int>& src, vector<int>& dst, vector<vector<int>>& swp) {
        int n = src.size();
        parent.resize(n, 0);
        rnk.resize(n, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for(vector<int> s: swp) {
            int x = find(s[0]);
            int y = find(s[1]);
            if(rnk[x] < rnk[y]) {
                parent[x] = y;
                rnk[y]++;
            } else {
                parent[y] = x;
                rnk[x]++;                
            }
        }
        
        unordered_map<int, unordered_map<int, int>> mp;
        
        for(int i = 0; i < n; i++) {
            int p = find(i);
            auto &m = mp[p];
            m[src[i]]++;
        }
        
        int res = 0;
        
        for(int i = 0; i < n; i++) {
            int p = find(i);
            auto &m = mp[p];
            if((m[dst[i]]--) <= 0) {
                res += 1;
            }
        }
        
        return res;
        
    }
    
    int find(int x) {
        int y = parent[x];
        if(y != x) {
            parent[x] = find(y);
        }
        return parent[x];
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

