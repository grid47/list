
+++
authors = ["Crafted by Me"]
title = "Leetcode 648: Replace Words"
date = "2022-01-23"
description = "Solution to Leetcode 648"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/replace-words/description/)

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

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

