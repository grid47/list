
+++
authors = ["grid47"]
title = "Leetcode 676: Implement Magic Dictionary"
date = "2024-08-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 676: Implement Magic Dictionary in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Depth-First Search","Design","Trie"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/676.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



[`Problem Link`](https://leetcode.com/problems/implement-magic-dictionary/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/676.webp" 
    alt="A glowing dictionary where each word is stored and retrieved, with each word softly glowing as it’s found."
    caption="Solution to LeetCode 676: Implement Magic Dictionary Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #677: Map Sum Pairs](https://grid47.xyz/leetcode/solution-677-map-sum-pairs/) |
| --- |