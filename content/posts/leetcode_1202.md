
+++
authors = ["grid47"]
title = "Leetcode 1202: Smallest String With Swaps"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1202: Smallest String With Swaps in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Depth-First Search","Breadth-First Search","Union Find","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-string-with-swaps/description/)

---
**Code:**

{{< highlight cpp >}}
class UF {
public:
    vector<int> parent;
    UF(int n) {
        parent.resize(n, 0);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    bool join(int i, int j) {
        int x = find(i);
        int y = find(j);
        
        if(x != y) {
            parent[x] = y;

            return true;
        }
        
        return false;
    }

    int find(int x) {
        int r = parent[x];
        if(r != x)
        parent[x] = find(r);
        return parent[x];
    }

    vector<vector<int>> pairs() {
        map<int, vector<int>> res;
        for(int i = 0; i < parent.size(); i++)
            res[find(i)].push_back(i);

        
        vector<vector<int>> ans;
        for(auto t: res)
            ans.push_back(t.second);
        return ans;
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        UF uf = UF(n);
        for(vector<int> each: pairs)
            uf.join(each[0], each[1]);
        
        vector<vector<int>> grps = uf.pairs();
        vector<char> ans(n, '-');
        
        for(vector<int> grp : grps) {

            sort(grp.begin(), grp.end());
            vector<char> chr;
            for(int g : grp) chr.push_back(s[g]);
            sort(chr.begin(), chr.end(), [](unsigned char c1, unsigned char c2){ return std::tolower(c1) < std::tolower(c2); });
            int i = 0;
            for(int x: grp)
                ans[x] = chr[i++];
        }
        
        string ret(ans.begin(), ans.end());
        return ret;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1202.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1203: Sort Items by Groups Respecting Dependencies](https://grid47.xyz/posts/leetcode_1203) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
