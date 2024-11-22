
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
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/211.webp"
youtube = "80wUjzYWSV4"
youtube_upload_date="2023-03-19"
youtube_thumbnail="https://i.ytimg.com/vi/80wUjzYWSV4/maxresdefault.jpg"
+++


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
---

### 🚀 Problem Statement

The task is to implement a **WordDictionary** class that allows adding words and searching for them, including supporting the use of the wildcard character `.`. This wildcard matches any letter, making searches more flexible by allowing patterns instead of exact matches. The operations required are:

1. **addWord(word)** - Adds a word to the dictionary.
2. **search(word)** - Searches for a word, where `.` can represent any letter in the word.

---

### 🧠 Approach

This problem is a perfect candidate for a **Trie (Prefix Tree)**, a data structure designed for efficient word storage and retrieval. A Trie allows us to store words character by character, making it easy to search for exact words and handle wildcard matches.

To support the `.` wildcard, we use a **Depth-First Search (DFS)** approach. The `.` wildcard can match any character, so we recursively explore all possible paths in the Trie for each wildcard occurrence.

#### Key Steps:
1. **Trie Structure**: 
   - Each **Node** in the Trie represents a character.
   - **isWord**: A flag to mark the end of a valid word.
   - **next**: An array of 26 pointers, each corresponding to a letter of the alphabet (`a` to `z`), pointing to the next character node.

2. **addWord(word)**: 
   - We iterate over each character in the word, creating nodes for new characters as needed.
   - We mark the last node as the end of a word.

3. **search(word)**:
   - For exact matches, we traverse the Trie.
   - For wildcard matches (`.`), we recursively try all possible paths at that position and continue the search.

---

### 🔨 Step-by-Step Code Breakdown

Let's dive into the code to understand the implementation!

```cpp
class Node {
public:
    bool isWord;   // Indicates if the node is the end of a word
    char val;      // Stores the character at the node
    vector<Node*> next;  // Pointers to the next nodes (for each character a-z)
    
    Node(char val, bool isWord) {
        this->val = val;
        this->isWord = isWord;
        next.resize(26, NULL);  // Initialize with NULL for all 26 letters
    }
};
```

- **Node Class**: Represents a single character in the Trie. Each node stores:
  - **val**: The character at this node.
  - **isWord**: A flag marking whether the node represents the end of a valid word.
  - **next**: A vector that holds pointers to the next possible characters.

---

```cpp
class WordDictionary {
public:
    Node* root;  // The root node of the Trie

    WordDictionary() {
        root = new Node(' ', false);  // Initialize with a dummy root node
    }
    
    void addWord(string word) {
        Node* node = this->root;
        for(int i = 0; i < word.size(); i++) {
            int code = word[i] - 'a';  // Map character to index (0-25)
            if(node->next[code] == NULL) {
                node->next[code] = new Node(word[i], false);  // Create new node if needed
            }
            node = node->next[code];  // Move to the next node
        }
        node->isWord = true;  // Mark the end of the word
    }
```

- **addWord(word)**: Adds a word to the Trie by creating nodes for each character. We map each character to an index using `word[i] - 'a'`, and create new nodes if they don't already exist.

---

```cpp
    bool search(string word) {
        return bt(word, this->root, 0);  // Start recursive search from root
    }
```

- **search(word)**: Begins the search by calling a helper function `bt()` to handle both exact and wildcard matches.

---

```cpp
    bool bt(string word, Node* node, int idx) {
        if(word[idx] == '.') {  // Handle the wildcard '.'
            if(idx + 1 == word.size()) {
                int res = false;
                for(int i = 0; i < 26; i++) {
                    if(node->next[i] != NULL)
                        res |= node->next[i]->isWord;  // Check if any branch leads to a valid word
                    if(res) return true;  // Return true if a valid word is found
                }
                return false;  // No valid word found
            } else {
                int res = false;
                for(int i = 0; i < 26; i++) {
                    if(node->next[i] != NULL)
                        res |= bt(word, node->next[i], idx+1);  // Recursively check each branch
                    if(res) return true;  // If found, return true
                }
                return false;  // No valid word found
            }
        } else {
            int code = word[idx] - 'a';  // Get index for character
            if(node->next[code] == NULL)
                return false;  // If no matching node, return false
            node = node->next[code];  // Move to next node
            if(idx + 1 == word.size())
                return node->isWord;  // If last character, check if it marks the end of a word
            return bt(word, node, idx + 1);  // Recursively check the next character
        }
    }
};
```

- **bt(word, node, idx)**: A helper function that performs the DFS search:
  - For a wildcard (`.`), it explores all possible branches of the Trie at that position.
  - For exact characters, it follows the corresponding node.
  - It returns `true` if a valid word is found, and `false` otherwise.

---

### 📈 Complexity Analysis

- **Time Complexity**:
  - **addWord(word)**: O(L), where `L` is the length of the word. Each character is inserted into the Trie.
  - **search(word)**: O(L * 26) in the worst case. For each character (up to length `L`), if it's a wildcard (`.`), we check all 26 possible branches.

- **Space Complexity**:
  - **addWord(word)**: O(L), where `L` is the length of the word. This space is used to store the nodes in the Trie.
  - **search(word)**: O(1), aside from the recursive call stack, which can go as deep as the length of the word.

---

### 🏁 Conclusion

By leveraging a **Trie** data structure, we efficiently handle word storage and searches. The solution also supports **wildcard matching** using a **Depth-First Search (DFS)**, making it flexible and powerful. Whether it's exact or pattern matching, this approach offers fast insertions and searches, even when dealing with wildcards.

### 🌟 Key Takeaways:
- **Trie** is a great data structure for prefix-based search problems.
- **DFS** allows efficient handling of wildcards.
- The solution balances time and space complexity well for large inputs.



[`Link to LeetCode Lab`](https://leetcode.com/problems/design-add-and-search-words-data-structure/description/)

---
{{< youtube 80wUjzYWSV4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
