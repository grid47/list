
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
comments = true
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
You are tasked with creating a data structure that allows adding words and checking if a word matches any previously added word, with support for the wildcard '.' character.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of calls to the WordDictionary constructor, addWord method, and search method. Words can include lowercase letters and the wildcard '.' character.
- **Example:** `[[], ["hello"], ["world"], ["hell"], ["hell"], ["hello"], ["h.ll"], ["wo.ld"]]`
- **Constraints:**
	- 1 <= word.length <= 25
	- Words consist of lowercase English letters in addWord and lowercase English letters or '.' in search.
	- At most 10^4 calls to addWord and search.

{{< dots >}}
### Output Specifications 📤
- **Output:** For each search query, return true if a matching word exists, otherwise return false.
- **Example:** `For input ["search('hell')"] after adding 'hello' and 'hell', the output will be true.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Implement a data structure that supports efficient addition and search of words, with the ability to match patterns using the '.' wildcard.

- Use a Trie (prefix tree) to store added words.
- For search, use a backtracking approach to explore all possible matching words, considering '.' as a wildcard.
{{< dots >}}
### Problem Assumptions ✅
- The input will contain lowercase letters and the wildcard '.' character only.
- The system should efficiently handle large numbers of addWord and search calls.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1`  \
  **Explanation:** After adding 'hello', 'world', and 'hell', searching for 'hell' returns true because 'hell' is an exact match. Searching for 'h.ll' also returns true because 'hello' matches the pattern.

{{< dots >}}
## Approach 🚀
We can solve this problem using a Trie for storing words and backtracking for searching with patterns containing '.'

### Initial Thoughts 💭
- The Trie is an efficient data structure for storing words based on their prefixes.
- Backtracking can be used for searching, especially with the wildcard '.' character.
- We will need to recursively explore all possible matches when encountering a dot in the search string.
{{< dots >}}
### Edge Cases 🌐
- If no words are added, any search will return false.
- The solution should handle cases with large numbers of words and search queries efficiently.
- Search queries containing '.' should match any character in the corresponding position.
- Optimize for time complexity to handle up to 10^4 operations.
{{< dots >}}
## Code 💻
```cpp
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
```

This code defines a WordDictionary class that supports adding words and searching for them, where the search allows for wildcards (represented by '.') in the word.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	bool isWord;
	```
	The 'isWord' variable indicates if the current node represents the end of a word.

2. **Variable Initialization**
	```cpp
	char val;
	```
	The 'val' variable stores the character that the node represents in the trie structure.

3. **Vector Insertion**
	```cpp
	vector<Node*> next;
	```
	The 'next' vector holds pointers to the next nodes in the trie, with each position corresponding to a character from 'a' to 'z'.

4. **Constructor**
	```cpp
	Node(char val, bool isWord) {
	```
	Constructor for initializing a node with a character and a boolean value indicating if it's a valid word.

5. **Assignment Operation**
	```cpp
	    this->val = val;
	```
	Assigns the character 'val' to the node.

6. **Assignment Operation**
	```cpp
	    this->isWord = isWord;
	```
	Sets the 'isWord' flag to determine if this node represents a complete word.

7. **Vector Initialization**
	```cpp
	    next.resize(26, NULL);
	```
	Initializes the 'next' vector with 26 null pointers, one for each letter of the alphabet.

8. **Class Declaration**
	```cpp
	class WordDictionary {
	```
	Declares the WordDictionary class, which will hold the root node of the trie and methods to add and search for words.

9. **Public Access Modifier**
	```cpp
	public:
	```
	Access modifier that allows the methods and variables below to be accessed outside the class.

10. **Variable Initialization**
	```cpp
	Node* root;
	```
	A pointer to the root node of the trie.

11. **Constructor**
	```cpp
	WordDictionary() {
	```
	Constructor for the WordDictionary class that initializes the root node.

12. **Memory Allocation**
	```cpp
	    root = new Node(' ', false);
	```
	Allocates memory for the root node with a space character and 'isWord' set to false.

13. **Method Definition**
	```cpp
	void addWord(string word) {
	```
	Defines the addWord method, which inserts a word into the trie.

14. **Variable Initialization**
	```cpp
	    Node* node = this->root;
	```
	Initializes a node pointer to the root node of the trie.

15. **Loop Iteration**
	```cpp
	    for(int i = 0; i < word.size(); i++) {
	```
	Iterates through each character in the word to add it to the trie.

16. **Arithmetic Operation**
	```cpp
	        int code = word[i] - 'a';
	```
	Converts the character to an index in the 'next' vector (0 for 'a', 1 for 'b', etc.).

17. **Conditional Statement**
	```cpp
	        if(node->next[code] == NULL) {
	```
	Checks if the node at the corresponding position in the trie is null.

18. **Memory Allocation**
	```cpp
	            node->next[code] = new Node(word[i], false);
	```
	Allocates a new node at the position corresponding to the current character.

19. **Assignment Operation**
	```cpp
	        node = node->next[code];
	```
	Moves the pointer to the next node in the trie corresponding to the current character.

20. **Assignment Operation**
	```cpp
	    node->isWord = true;
	```
	Marks the node as the end of a valid word.

21. **Method Definition**
	```cpp
	bool search(string word) {
	```
	Defines the search method, which searches for a word in the trie.

22. **Function Call**
	```cpp
	    return bt(word, this->root, 0);
	```
	Calls the helper function 'bt' to perform a recursive search.

23. **Method Definition**
	```cpp
	bool bt(string word, Node* node, int idx) {
	```
	Defines the recursive helper function 'bt' used by the search method.

24. **Conditional Statement**
	```cpp
	    if(word[idx] == '.') {
	```
	Checks if the current character in the word is a wildcard ('.').

25. **Recursive Call**
	```cpp
	        if(idx + 1 == word.size()) {
	```
	Checks if we've reached the end of the word.

26. **Conditional Statement**
	```cpp
	            int res = false;
	```
	Initializes a variable 'res' to keep track of the search result.

27. **Loop Iteration**
	```cpp
	            for(int i = 0; i < 26; i++) {
	```
	Loops through each possible character in the trie.

28. **Conditional Statement**
	```cpp
	                if(node->next[i] != NULL)
	```
	Checks if the node at position 'i' is not null.

29. **Logical Operation**
	```cpp
	                    res |= node->next[i]->isWord;
	```
	Checks if any of the next nodes leads to a valid word.

30. **Return Statement**
	```cpp
	                if(res) return true;
	```
	If a valid word is found, return true.

31. **Return Statement**
	```cpp
	            return false;
	```
	If no valid word is found, return false.

32. **Block Termination**
	```cpp
	        }
	```
	Ends the conditional statement for checking the end of the word.

33. **Recursive Call**
	```cpp
	        else {
	```
	If the current character is a wildcard, we recursively search for the rest of the word.

34. **Recursive Call**
	```cpp
	            for(int i = 0; i < 26; i++) {
	```
	Loops through all possible next nodes for the wildcard.

35. **Recursive Call**
	```cpp
	                if(node->next[i] != NULL)
	                    res |= bt(word, node->next[i], idx+1);
	```
	Recursively calls 'bt' on each next node.

36. **Return Statement**
	```cpp
	        return false;
	```
	If no match is found, returns false.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m), where m is the length of the word being searched.
- **Average Case:** O(m), assuming an average branching factor for the Trie.
- **Worst Case:** O(m * 26^k), where k is the number of '.' characters in the search query and 26 is the number of possible letters for each dot.

In the worst case, we may need to explore all possible combinations for the dots in the query.

### Space Complexity 💾
- **Best Case:** O(n), where n is the number of words, assuming each word has a constant length.
- **Worst Case:** O(n * m), where n is the number of words and m is the average length of each word.

The space complexity is mainly determined by the Trie structure, which stores all words and their corresponding characters.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/design-add-and-search-words-data-structure/description/)

---
{{< youtube 80wUjzYWSV4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
