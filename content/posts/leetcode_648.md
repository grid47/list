
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 648: Replace Words"
date = "2023-01-21"
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

