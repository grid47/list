
+++
authors = ["Yasir"]
title = "Leetcode 208: Implement Trie (Prefix Tree)"
date = "2024-04-02"
description = "Solution to Leetcode 208"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/implement-trie-prefix-tree/description/)

---

**Code:**

{{< highlight html >}}
class Node {
    public:
    vector<Node*> chd;
    bool isWord;
    Node(int n) {
        chd.resize(n, 0);
        isWord = false;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node(26);
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(node->chd[word[i] - 'a'] == NULL)
                node->chd[word[i] - 'a'] = new Node(26);
            node = node->chd[word[i] - 'a'];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(node->chd[word[i] - 'a'] == NULL)
                return false;
            node = node->chd[word[i] - 'a'];
        }
        return node->isWord;        
    }
    
    bool startsWith(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(node->chd[word[i] - 'a'] == NULL)
                return false;
            node = node->chd[word[i] - 'a'];
        }
        return true;        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
{{< /highlight >}}

