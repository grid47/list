
+++
authors = ["grid47"]
title = "Leetcode 208: Implement Trie (Prefix Tree)"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 208: Implement Trie (Prefix Tree) in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Design","Trie"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/implement-trie-prefix-tree/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/208.jpeg" 
    alt="A tree structure formed from words, with each node glowing softly, symbolizing the prefix search structure."
    caption="Solution to LeetCode 208: Implement Trie (Prefix Tree) Problem"
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/208.md" >}}
---
{{< youtube rJRTji53Ggk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #209: Minimum Size Subarray Sum](https://grid47.xyz/posts/leetcode-209-minimum-size-subarray-sum-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}