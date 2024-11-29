
+++
authors = ["grid47"]
title = "Leetcode 676: Implement Magic Dictionary"
date = "2024-08-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 676: Implement Magic Dictionary in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Depth-First Search","Design","Trie"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/676.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/676.webp" 
    alt="A glowing dictionary where each word is stored and retrieved, with each word softly glowing as it’s found."
    caption="Solution to LeetCode 676: Implement Magic Dictionary Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Design a data structure that supports searching for words that can be matched by changing exactly one character.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You will be given a list of distinct words to initialize the MagicDictionary, and you need to search for words that can match by changing exactly one character.
- **Example:** `["abc", "abd", "bbc"]`
- **Constraints:**
	- 1 <= dictionary.length <= 100
	- 1 <= dictionary[i].length <= 100
	- All words in the dictionary are distinct.
	- 1 <= searchWord.length <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if you can change exactly one character in the searchWord to match any word in the dictionary. Otherwise, return false.
- **Example:** `true`
- **Constraints:**
	- The output will always be a boolean value.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine whether exactly one character in the search word can be changed to match any word from the dictionary.

- 1. Store the words from the dictionary in a way that makes checking for a possible one-character change efficient.
- 2. For each character position in the search word, check if changing that character makes the word match any dictionary word.
{{< dots >}}
### Problem Assumptions ✅
- The dictionary will be built only once, and search operations will be performed after the dictionary is built.
{{< dots >}}
## Examples 🧩
- **Input:** `["hello", "leetcode"]`  \
  **Explanation:** In this case, searching for the word 'hhllo' should return true, as changing the second 'h' to 'e' matches the word 'hello'.

- **Input:** `["abc", "abd", "bbc"]`  \
  **Explanation:** Here, searching for 'abc' should return true since it matches with the dictionary word 'abd' by changing the second 'c' to 'd'.

{{< dots >}}
## Approach 🚀
We will create a dictionary where we store each word with possible one-character changes for efficient searching.

### Initial Thoughts 💭
- We need to consider all possible words that can be made by changing one character in the search word.
- The efficient way to store and check possible matches is to store substrings of each word where one character has been removed, then use this for searching.
{{< dots >}}
### Edge Cases 🌐
- This problem doesn't deal with empty dictionaries or search words as they are constrained to have at least one character.
- Ensure the dictionary and search word sizes can be handled efficiently, even with the maximum constraints.
- If the dictionary contains identical words or the search word is already in the dictionary, it should return false.
- Efficient storage of dictionary words is key to handling the maximum input size within time limits.
{{< dots >}}
## Code 💻
```cpp
public:
MagicDictionary() {
}

void buildDict(vector<string> dict) {

    for(string s: dict) {
        int n = s.length();            
        for(int i = 0; i < n; i++) {

            string t = s.substr(0, i) + s.substr(i+1);
            pair<int, char> p(i, s[i]);                
            mp[t].push_back(p);

        }
    }
}

bool search(string word) {
    
    for(int i = 0; i < word.size(); i++) {
        string key = word.substr(0, i) + word.substr(i+1);

        for(pair<int, char> sk : mp[key])
        if(sk.first == i && sk.second!=word[i])
            return true;             
    }
    return false;
}
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
```

This code defines a MagicDictionary class with two primary methods: buildDict, which builds the dictionary of words by storing modified versions of each word, and search, which checks if a word can be formed by modifying exactly one character from an existing word in the dictionary.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	public:
	```
	This marks the start of the public section of the class definition, indicating the access specifier for the methods and variables that follow.

2. **Constructor**
	```cpp
	MagicDictionary() {
	```
	This is the constructor of the `MagicDictionary` class. It initializes the object, though in this case, there is no explicit initialization logic.

3. **Function Definition**
	```cpp
	void buildDict(vector<string> dict) {
	```
	This defines the `buildDict` function, which takes a vector of strings (`dict`) and processes each word to store its modified versions.

4. **For Each Word**
	```cpp
	    for(string s: dict) {
	```
	This loop iterates through each word in the dictionary (`dict`).

5. **Length of Word**
	```cpp
	        int n = s.length();            
	```
	Here, we store the length of the current word `s` in the variable `n`.

6. **Loop Through Word Characters**
	```cpp
	        for(int i = 0; i < n; i++) {
	```
	This inner loop iterates over each character of the word `s`, allowing us to create modified versions of the word by removing one character at a time.

7. **Create Modified Word**
	```cpp
	            string t = s.substr(0, i) + s.substr(i+1);
	```
	This creates a modified version of the word `s` by removing the character at index `i`. The modified word is stored in `t`.

8. **Create Pair**
	```cpp
	            pair<int, char> p(i, s[i]);                
	```
	We create a pair `p` consisting of the index `i` and the character `s[i]` that was removed in the modified word.

9. **Store in Map**
	```cpp
	            mp[t].push_back(p);
	```
	The modified word `t` is used as the key, and the pair `p` is pushed into the corresponding vector in the map `mp`. This helps track the modified versions of each word.

10. **Function Definition**
	```cpp
	bool search(string word) {
	```
	This defines the `search` function, which takes a word as input and checks if it can be formed by modifying exactly one character of an existing word in the dictionary.

11. **Loop Through Word Characters**
	```cpp
	    for(int i = 0; i < word.size(); i++) {
	```
	This loop iterates through each character of the input word `word`.

12. **Create Modified Word**
	```cpp
	        string key = word.substr(0, i) + word.substr(i+1);
	```
	This creates a modified version of the input word `word` by removing the character at index `i`.

13. **Loop Through Modified Words in Map**
	```cpp
	        for(pair<int, char> sk : mp[key])
	```
	This loop iterates through the list of modified words stored in the map for the generated `key`.

14. **Check Character Mismatch**
	```cpp
	        if(sk.first == i && sk.second!=word[i])
	```
	If the character at position `i` in the modified word is different from the character in the input word, we have found a valid match.

15. **Return True**
	```cpp
	            return true;             
	```
	If a valid match is found, return `true`, indicating that the word can be formed by modifying exactly one character.

16. **Return False**
	```cpp
	    return false;
	```
	If no valid match is found after checking all modifications, return `false`.

17. **Class End**
	```cpp
	};
	```
	End of the `MagicDictionary` class definition.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity for searching is O(n) where n is the number of words in the dictionary.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n * m)

The space complexity is O(n * m) where n is the number of words in the dictionary and m is the average word length.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/implement-magic-dictionary/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
