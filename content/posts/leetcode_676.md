
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 676: Implement Magic Dictionary"
date = "2022-12-24"
description = "Solution to Leetcode 676"
tags = [
    
]
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
