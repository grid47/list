
+++
authors = ["grid47"]
title = "Leetcode 211: Design Add and Search Words Data Structure"
date = "2024-10-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 211: Design Add and Search Words Data Structure in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Depth-First Search","Design","Trie"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/design-add-and-search-words-data-structure/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/211.webp" 
    alt="A series of glowing words arranged in a structure, showing efficient searching and adding through soft pathways."
    caption="Solution to LeetCode 211: Design Add and Search Words Data Structure Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Node {
    public:
    bool isWord;
    char val;
    vector<Node*> next;
    Node(char val, bool isWord) {
        this->val = val;
        this->isWord = isWord;
        next.resize(26, NULL);
    }
};
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node(' ', false);
    }
    
    void addWord(string word) {
        Node* node = this->root;
        for(int i = 0; i < word.size(); i++) {
            int code = word[i] - 'a';
            if(node->next[code] == NULL) {
                node->next[code] = new Node(word[i], false);
            }
            node = node->next[code];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        return bt(word, this->root, 0);
    }
    
    bool bt(string word, Node* node, int idx) {
        if(word[idx] == '.') {
            if(idx + 1 == word.size()) {
                int res = false;
                for(int i = 0; i < 26; i++) {
                    if(node->next[i] != NULL)
                        res |= node->next[i]->isWord;
                    if(res) return true;
                }
                return false;
            } else {
                int res = false;
                for(int i = 0; i < 26; i++) {
                    if(node->next[i] != NULL)
                        res |= bt(word, node->next[i], idx+1);
                    if(res) return true;
                }
                return false;                
            }
        } else {
            
            int code = word[idx] - 'a';
            if(node->next[code] == NULL)
                return false;
            node = node->next[code];
            if(idx + 1 == word.size())
                return node->isWord;
            return bt(word, node, idx + 1);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/211.md" >}}
---
{{< youtube 80wUjzYWSV4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #213: House Robber II](https://grid47.xyz/posts/leetcode-213-house-robber-ii-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
