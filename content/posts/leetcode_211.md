
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 211: Design Add and Search Words Data Structure"
date = "2024-04-01"
description = "Solution to Leetcode 211"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/design-add-and-search-words-data-structure/description/)

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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

