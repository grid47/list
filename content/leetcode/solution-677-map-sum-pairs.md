
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
youtube = "GwiKly7UJbQ"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/677.webp"
+++



[`Problem Link`](https://leetcode.com/problems/map-sum-pairs/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/677.webp" 
    alt="A map where sum pairs are found and highlighted with glowing connections."
    caption="Solution to LeetCode 677: Map Sum Pairs Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #678: Valid Parenthesis String](https://grid47.xyz/leetcode/solution-678-valid-parenthesis-string/) |
| --- |
