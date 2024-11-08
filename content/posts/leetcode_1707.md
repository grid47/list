
+++
authors = ["grid47"]
title = "Leetcode 1707: Maximum XOR With an Element From Array"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1707: Maximum XOR With an Element From Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation","Trie"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-xor-with-an-element-from-array/description/)

---
**Code:**

{{< highlight cpp >}}
class TrieNode {

    TrieNode* bin[2] = {};
    int prefixVal;

public:

    void add(int num) {
        TrieNode* cur = this;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(cur->bin[bit] == nullptr) cur->bin[bit] = new TrieNode();
            cur = cur->bin[bit];
        }
        cur->prefixVal = num;
    }
    
    int max(int num) {
        TrieNode* cur = this;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(cur->bin[1 - bit] != nullptr)
                 cur = cur->bin[1- bit];
            else cur = cur->bin[bit];
        }
        return cur->prefixVal ^ num;
    }

};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& q) {

        int n = nums.size();

        int sz = q.size();
        vector<array<int, 3>> tmp(sz);
        for(int i = 0; i < sz; i++)
        tmp[i] = { q[i][0], q[i][1], i };

        sort(nums.begin(), nums.end());
        sort(tmp.begin(), tmp.end(), [](array<int, 3> a, array<int, 3> b) { return a[1] < b[1]; });
        
        vector<int> res(sz, 0);
        TrieNode* root = new TrieNode();        
        int idx = 0;
        for(array<int, 3> qu : tmp) {
            while(idx < n && nums[idx] <= qu[1]) {
                root->add(nums[idx]);
                idx++;
            }

            int ans = -1;
            if(idx != 0)
            ans = root->max(qu[0]);
            
            res[qu[2]] = ans;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1707.md" >}}
---
{{< youtube s647rX6tn4g >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1712: Ways to Split Array Into Three Subarrays](https://grid47.xyz/posts/leetcode_1712) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
