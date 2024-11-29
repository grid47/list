
+++
authors = ["grid47"]
title = "Leetcode 208: Implement Trie (Prefix Tree)"
date = "2024-10-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 208: Implement Trie (Prefix Tree) in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Design","Trie"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/208.webp"
youtube = "rJRTji53Ggk"
youtube_upload_date="2023-03-17"
youtube_thumbnail="https://i.ytimg.com/vi/rJRTji53Ggk/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/208.webp" 
    alt="A tree structure formed from words, with each node glowing softly, symbolizing the prefix search structure."
    caption="Solution to LeetCode 208: Implement Trie (Prefix Tree) Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Implement a Trie data structure that supports inserting words, searching for exact matches, and checking if any word starts with a given prefix.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a list of operations to perform on the Trie data structure. Each operation corresponds to one of the Trie methods: insert, search, or startsWith.
- **Example:** `[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]`
- **Constraints:**
	- Each string in the Trie has a length between 1 and 2000.
	- All characters in the strings are lowercase English letters.
	- At most 30,000 operations will be performed.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output consists of the results of the operations in the order they are performed. For each 'insert' operation, the output is 'null'. For 'search' and 'startsWith' operations, the output is a boolean value indicating whether the operation was successful.
- **Example:** `[null, null, true, false, true, null, true]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to implement the Trie class and handle the operations insert, search, and startsWith efficiently.

- Use a nested structure where each node contains an array representing child nodes and a boolean flag indicating if the node corresponds to a complete word.
- For 'insert', iterate through each character of the word and create nodes as necessary.
- For 'search', traverse the Trie and check if the entire word exists.
- For 'startsWith', traverse the Trie to check if there exists a word that begins with the given prefix.
{{< dots >}}
### Problem Assumptions ✅
- All input strings contain only lowercase English letters.
- No cycles are present in the Trie.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1`  \
  **Explanation:** In this example, the operations are performed in sequence, with the insertions and searches occurring as expected, demonstrating how the Trie handles prefixes and exact word matches.

- **Input:** `Example 2`  \
  **Explanation:** This example shows how the Trie works with a simple dataset where only the word 'dog' is inserted and then searched for both fully and by prefix.

{{< dots >}}
## Approach 🚀
The approach involves implementing the Trie data structure using a node-based approach where each node holds a collection of child nodes and a flag to indicate if it represents a word.

### Initial Thoughts 💭
- A Trie is ideal for operations like searching and prefix matching due to its tree-like structure.
- We need to efficiently implement the insert, search, and startsWith methods to handle up to 30,000 operations.
{{< dots >}}
### Edge Cases 🌐
- If no words are inserted, all search and startsWith operations should return false.
- Handle cases where strings are of maximum length (2000 characters) and when the number of operations is large (30,000).
- Handle cases where words have overlapping prefixes, like 'app' and 'apple'.
- Ensure that the solution performs efficiently within the given constraints.
{{< dots >}}
## Code 💻
```cpp
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
```

This code implements a Trie data structure with methods to insert, search, and check for a prefix in the Trie. The code demonstrates how to store and retrieve words efficiently using a tree-like structure.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	vector<Node*> chd;
	```
	Create a vector of Node pointers, `chd`, to represent the child nodes of each node in the Trie.

2. **Variable Initialization**
	```cpp
	bool isWord;
	```
	Declare a boolean variable `isWord` to mark whether the current node is the end of a word.

3. **Constructor**
	```cpp
	Node(int n) {
	```
	Constructor for the Node class. It initializes the `chd` vector and sets `isWord` to `false`.

4. **Node Initialization**
	```cpp
	    chd.resize(n, 0);
	```
	Resize the `chd` vector to hold `n` child nodes, initializing each one to `NULL`.

5. **Node Initialization**
	```cpp
	    isWord = false;
	```
	Initialize the `isWord` variable to `false`, indicating that the node does not yet represent the end of a word.

6. **Trie Class Definition**
	```cpp
	class Trie {
	```
	Begin the definition of the Trie class.

7. **Access Specifier**
	```cpp
	public:
	```
	Define the public section of the Trie class, making methods accessible from outside the class.

8. **Variable Declaration**
	```cpp
	Node* root;
	```
	Declare a pointer `root` that will point to the root of the Trie.

9. **Constructor**
	```cpp
	Trie() {
	```
	Constructor for the Trie class. It initializes the `root` node of the Trie.

10. **Node Initialization**
	```cpp
	    root = new Node(26);
	```
	Initialize the root node of the Trie with 26 child nodes (one for each letter of the alphabet).

11. **End Constructor**
	```cpp
	}
	```
	End the constructor for the Trie class.

12. **Insert Method**
	```cpp
	void insert(string word) {
	```
	Define the insert method to add a word to the Trie.

13. **Variable Declaration**
	```cpp
	    Node* node = root;
	```
	Initialize a pointer `node` to the root node of the Trie.

14. **Loop Iteration**
	```cpp
	    for(int i = 0; i < word.size(); i++) {
	```
	Loop through each character in the word to insert it into the Trie.

15. **Conditional Check**
	```cpp
	        if(node->chd[word[i] - 'a'] == NULL)
	```
	Check if the current node does not have a child node for the character. If so, create a new child node.

16. **Node Initialization**
	```cpp
	            node->chd[word[i] - 'a'] = new Node(26);
	```
	Create a new node for the current character and assign it to the corresponding child in the `chd` vector.

17. **Node Update**
	```cpp
	        node = node->chd[word[i] - 'a'];
	```
	Move the `node` pointer to the next child node.

18. **Word Marking**
	```cpp
	    node->isWord = true;
	```
	Mark the current node as the end of a word by setting `isWord` to `true`.

19. **Search Method**
	```cpp
	bool search(string word) {
	```
	Define the search method to check if a word exists in the Trie.

20. **Variable Declaration**
	```cpp
	    Node* node = root;
	```
	Initialize a pointer `node` to the root node of the Trie.

21. **Loop Iteration**
	```cpp
	    for(int i = 0; i < word.size(); i++) {
	```
	Loop through each character in the word to check if it exists in the Trie.

22. **Conditional Check**
	```cpp
	        if(node->chd[word[i] - 'a'] == NULL)
	```
	Check if the current node does not have a child node for the character. If so, return `false`.

23. **Return False**
	```cpp
	            return false;
	```
	Return `false` if any character is not found in the Trie.

24. **Node Update**
	```cpp
	        node = node->chd[word[i] - 'a'];
	```
	Move the `node` pointer to the next child node.

25. **Return Result**
	```cpp
	    return node->isWord;
	```
	Return `true` if the current node marks the end of a word, otherwise `false`.

26. **StartsWith Method**
	```cpp
	bool startsWith(string word) {
	```
	Define the startsWith method to check if any word in the Trie starts with the given prefix.

27. **Variable Declaration**
	```cpp
	    Node* node = root;
	```
	Initialize a pointer `node` to the root node of the Trie.

28. **Loop Iteration**
	```cpp
	    for(int i = 0; i < word.size(); i++) {
	```
	Loop through each character in the word to check if it exists as a prefix in the Trie.

29. **Conditional Check**
	```cpp
	        if(node->chd[word[i] - 'a'] == NULL)
	```
	Check if the current node does not have a child node for the character. If so, return `false`.

30. **Return False**
	```cpp
	            return false;
	```
	Return `false` if the prefix is not found in the Trie.

31. **Node Update**
	```cpp
	        node = node->chd[word[i] - 'a'];
	```
	Move the `node` pointer to the next child node.

32. **Return Result**
	```cpp
	    return true;
	```
	Return `true` if the prefix exists in the Trie.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) for operations on short words or prefixes that are already in the Trie.
- **Average Case:** O(L) where L is the length of the word or prefix being processed.
- **Worst Case:** O(L) for insert, search, and startsWith where L is the length of the longest word or prefix.

Each operation (insert, search, startsWith) depends linearly on the length of the word or prefix being processed.

### Space Complexity 💾
- **Best Case:** O(L), where L is the length of the longest word being inserted or searched.
- **Worst Case:** O(N * L), where N is the number of words and L is the length of the longest word.

The space complexity depends on the number of nodes created for each inserted word and the maximum length of the words.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/implement-trie-prefix-tree/description/)

---
{{< youtube rJRTji53Ggk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
