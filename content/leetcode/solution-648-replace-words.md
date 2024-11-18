
+++
authors = ["grid47"]
title = "Leetcode 648: Replace Words"
date = "2024-09-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 648: Replace Words in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Trie"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/648.webp"
youtube = "5liJnc8iNeY"
youtube_upload_date="2020-06-19"
youtube_thumbnail="https://i.ytimg.com/vi/5liJnc8iNeY/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/replace-words/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/648.webp" 
    alt="A string where words are replaced with their corresponding replacements, glowing softly as replacements are made."
    caption="Solution to LeetCode 648: Replace Words Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class TrieNode {
    public:
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for(int i = 0; i < 26; i++)
            child[i]= NULL;
    }
};

class Solution {
    TrieNode* root;
public:

    void insert(string w) {
        TrieNode* st = root;
        for(char c: w) {
            if(!st->child[c - 'a']) st->child[c - 'a'] = new TrieNode();
            st = st->child[c - 'a'];
        }
        st->isEnd = true;
    }

    string check(string w) {
        TrieNode* st = root;
        string s = "";
        for(char c: w) {
            if(st->child[c - 'a']) st = st->child[c - 'a'];
            else break;
            s += c;
            if(st->isEnd) return s;
        }
        return w;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new TrieNode();
        for(auto w: dictionary) insert(w);

        istringstream ss(sentence);
        string word = "", ans = "";

        for(; ss>>word;) {
            ans += check(word);
            ans += ' ';
        }

        ans.pop_back();
        return ans;

    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/648.md" >}}
---
{{< youtube 5liJnc8iNeY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #649: Dota2 Senate](https://grid47.xyz/leetcode/solution-649-dota2-senate/) |
| --- |
