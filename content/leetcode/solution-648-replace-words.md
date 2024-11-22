
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
---

### Problem Statement

The problem asks us to replace words in a given sentence with the shortest possible prefix from a dictionary. For each word in the sentence, if a prefix exists in the dictionary, we should replace the word with this prefix. If no prefix is found in the dictionary, we leave the word as is.

### Approach

We will approach this problem by using a **Trie** (prefix tree) data structure, which is well-suited for problems involving prefix matching. A Trie allows efficient insertion and search operations, making it a perfect fit for this problem where we need to check whether a prefix exists for each word in the sentence.

Here's the step-by-step breakdown of the approach:

1. **Trie Data Structure**:
   - A Trie is a tree-like data structure where each node represents a character of a word. The nodes are connected to form a prefix of the words stored in the Trie.
   - For this problem, we need a **TrieNode** class that holds an array of pointers (`child[26]`) representing the 26 lowercase English characters, and a boolean `isEnd` to mark if a node represents the end of a word.

2. **Inserting Words into the Trie**:
   - For each word in the dictionary, we insert it into the Trie character by character. If a character is not already present in the Trie, we create a new node for it. Once we reach the end of the word, we mark that node as an end of a word (`isEnd = true`).

3. **Checking for Prefix in Trie**:
   - For each word in the sentence, we check if a prefix of the word exists in the Trie. Starting from the root of the Trie, we attempt to traverse the characters of the word. If at any point we encounter a character that doesn't exist in the Trie, we stop and return the original word.
   - If we find a prefix that exists in the Trie (i.e., we reach a node where `isEnd = true`), we return that prefix as the replacement for the word.

4. **Building the Final Sentence**:
   - After checking each word, we build the final sentence by replacing each word with the corresponding prefix (or the original word if no prefix is found).

### Code Breakdown (Step by Step)

Let's break down the code into its key components:

#### 1. **TrieNode Class**:
```cpp
class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for(int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};
```
- The `TrieNode` class represents a single node in the Trie.
- `child[26]` is an array of pointers to other TrieNodes. Each index in the array represents a character from 'a' to 'z'.
- `isEnd` is a boolean that indicates whether the current node marks the end of a valid word.

#### 2. **Insert Function**:
```cpp
void insert(string w) {
    TrieNode* st = root;
    for(char c: w) {
        if(!st->child[c - 'a']) st->child[c - 'a'] = new TrieNode();
        st = st->child[c - 'a'];
    }
    st->isEnd = true;
}
```
- The `insert` function inserts a word into the Trie.
- For each character in the word `w`, we traverse down the Trie. If the character is not already present, we create a new node for it.
- After inserting all characters, we mark the last node of the word as the end of a valid word (`isEnd = true`).

#### 3. **Check Function**:
```cpp
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
```
- The `check` function tries to find the shortest prefix of the word `w` that exists in the Trie.
- Starting from the root, we attempt to traverse down the Trie character by character.
- If we reach a node where `isEnd = true`, we return the prefix formed so far.
- If we don't find any valid prefix, we return the original word.

#### 4. **ReplaceWords Function**:
```cpp
string replaceWords(vector<string>& dictionary, string sentence) {
    root = new TrieNode();
    for(auto w: dictionary) insert(w);  // Insert all dictionary words into the Trie

    istringstream ss(sentence);
    string word = "", ans = "";

    for(; ss >> word;) {  // Iterate over each word in the sentence
        ans += check(word);  // Replace the word with the prefix (if any)
        ans += ' ';  // Add space between words
    }

    ans.pop_back();  // Remove the last space
    return ans;
}
```
- The `replaceWords` function is the main function that replaces the words in the sentence with their corresponding prefixes from the dictionary.
- First, we insert all dictionary words into the Trie.
- Then, we iterate over each word in the sentence, replace it using the `check` function, and build the resulting sentence.
- Finally, we return the modified sentence.

### Complexity

#### Time Complexity:
- **Insertion of a word into the Trie**: For each word in the dictionary, we perform an insertion that takes `O(m)` time, where `m` is the length of the word. If there are `n` words in the dictionary, the total time for insertion is `O(n * m)`, where `m` is the average length of the words.
- **Checking each word in the sentence**: For each word in the sentence, we perform a check operation that takes `O(m)` time, where `m` is the length of the word. If there are `k` words in the sentence, the total time for checking all words is `O(k * m)`.
- Therefore, the overall time complexity is **O(n * m + k * m)**, where `n` is the number of words in the dictionary, `k` is the number of words in the sentence, and `m` is the average length of the words.

#### Space Complexity:
- **Trie Storage**: The space required to store the Trie is proportional to the number of nodes in the Trie. The maximum number of nodes is `O(n * m)`, where `n` is the number of words in the dictionary and `m` is the maximum length of a word.
- **Other Variables**: The additional space for variables like `ss`, `word`, and `ans` is negligible compared to the space used by the Trie.

Thus, the space complexity is **O(n * m)**.

### Conclusion

This solution efficiently replaces words in a sentence with the shortest prefix from a dictionary using a Trie data structure. The Trie allows us to quickly check for the existence of prefixes, making the solution both time and space-efficient for this type of problem.

By leveraging Trie-based prefix matching, we ensure that the algorithm scales well with larger dictionaries and sentences. This solution is optimal for problems where prefix matching and efficient word replacement are required, making it a great example of how Trie-based data structures can solve real-world text processing tasks.

[`Link to LeetCode Lab`](https://leetcode.com/problems/replace-words/description/)

---
{{< youtube 5liJnc8iNeY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
