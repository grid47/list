
+++
authors = ["Crafted by Me"]
title = "Leetcode 676: Implement Magic Dictionary"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 676: Implement Magic Dictionary in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Depth-First Search","Design","Trie"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/implement-magic-dictionary/description/)

---

**Code:**

{{< highlight cpp >}}
class MagicDictionary {
    map<string, vector<pair<int, char>>> mp;
public:
    MagicDictionary() {
    }
    
    void buildDict(vector<string> dict) {

        for(string s: dict) {
            int n = s.length();            
            for(int i = 0; i < n; i++) {

                string t = s.substr(0, i) + s.substr(i+1);
                pair<int, char> p(i, s[i]);                
                mp[t].push_back(p);

            }
        }
    }
    
    bool search(string word) {
        
        for(int i = 0; i < word.size(); i++) {
            string key = word.substr(0, i) + word.substr(i+1);

            for(pair<int, char> sk : mp[key])
            if(sk.first == i && sk.second!=word[i])
                return true;             
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/676.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #677: Map Sum Pairs](https://grid47.xyz/posts/leetcode_677) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

