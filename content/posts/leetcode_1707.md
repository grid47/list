
+++
authors = ["Yasir"]
title = "Leetcode 1707: Maximum XOR With an Element From Array"
date = "2020-02-26"
description = "Solution to Leetcode 1707"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-xor-with-an-element-from-array/description/)

---

**Code:**

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

