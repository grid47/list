
+++
authors = ["grid47"]
title = "Leetcode 677: Map Sum Pairs"
date = "2024-08-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 677: Map Sum Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Design","Trie"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/map-sum-pairs/description/)

---
**Code:**

{{< highlight cpp >}}
class TrieNode {
    vector<TrieNode*> next;
    int sum = 0;
    string s;
public:
    TrieNode() {
        s = "";
        sum = 0;
        next.resize(26, NULL);
    }
    void add(string key, int val) {
        TrieNode* root = this;
        for(int i = 0; i < key.size(); i++) {
            int idx = key[i] - 'a';
            if(root->next[idx] == NULL)
                root->next[idx] = new TrieNode();
            root = root->next[idx];
            root->sum += val;
        }
        root->s = key;
    }
    
    int val(string key) {
        TrieNode* root = this;
        for(int i = 0; i < key.size(); i++) {
            int idx = key[i] - 'a';
            if(root->next[idx] == NULL)
                return 0;
            root = root->next[idx];
        }        
        return root->sum;
    }
};

class MapSum {
    TrieNode* root;
    map<string, int> store;
public:
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        int x = val;
        if(store[key] > 0)
            val = val - store[key];
            
        root->add(key, val);
        store[key] = x;
    }
    
    int sum(string prefix) {
        return root->val(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/677.md" >}}
---
{{< youtube GwiKly7UJbQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #678: Valid Parenthesis String](https://grid47.xyz/posts/leetcode-678-valid-parenthesis-string-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
