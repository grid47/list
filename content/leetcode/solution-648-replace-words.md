
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
comments = true
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
In English, certain words can be formed by adding a suffix to a root word. Given a list of root words and a sentence, replace every word in the sentence that is a derivative of any root word with the shortest root. If a word can be formed by more than one root, replace it with the shortest root.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of root words (dictionary) and a sentence, both represented as strings.
- **Example:** `dictionary = ["dog", "cat", "rat"], sentence = "the dogs were caught by the rats"`
- **Constraints:**
	- 1 <= dictionary.length <= 1000
	- 1 <= dictionary[i].length <= 100
	- dictionary[i] consists of only lowercase letters.
	- 1 <= sentence.length <= 10^6
	- sentence consists of only lowercase letters and spaces.
	- The number of words in sentence is in the range [1, 1000].
	- Each word in sentence has a length in the range [1, 1000].
	- There are no leading or trailing spaces in the sentence.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a sentence with all derivative words replaced by the shortest corresponding root word.
- **Example:** `the dog were caught by the rat`
- **Constraints:**
	- The output will be a string with words separated by spaces, and no leading or trailing spaces.

{{< dots >}}
### Core Logic 🔍
**Goal:** Replace each word in the sentence with the shortest root word it can be derived from.

- 1. Build a Trie data structure to store all root words.
- 2. For each word in the sentence, attempt to find the shortest prefix that exists in the Trie.
- 3. Replace the word with its root if a match is found.
{{< dots >}}
### Problem Assumptions ✅
- The dictionary is non-empty.
- The sentence contains words that are potentially derivatives of roots.
{{< dots >}}
## Examples 🧩
- **Input:** `dictionary = ["dog", "cat", "rat"], sentence = "the dogs were caught by the rats"`  \
  **Explanation:** The words 'dogs' and 'rats' are derivatives of 'dog' and 'rat' respectively, so they are replaced with these shorter roots.

{{< dots >}}
## Approach 🚀
We use a Trie data structure to efficiently store and check the prefixes of words in the sentence to replace them with the shortest root.

### Initial Thoughts 💭
- Trie is a good choice because it allows efficient prefix matching.
- We need to handle the large input efficiently by ensuring that the lookup and insertion in the Trie are fast.
{{< dots >}}
### Edge Cases 🌐
- The sentence is guaranteed to have at least one word.
- Handle cases where the sentence is large (up to 10^6 characters).
- Consider cases where no words in the sentence are derivatives of the roots.
- Ensure that the solution efficiently handles the large input constraints.
{{< dots >}}
## Code 💻
```cpp
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
```

The code defines a class `Solution` with methods to insert words into a trie, check for word replacements using the trie, and replace words in a sentence based on a given dictionary.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class Solution {
	```
	The class `Solution` is defined, which will contain methods for inserting words into a trie and checking and replacing words in a sentence.

2. **Trie Node Initialization**
	```cpp
	TrieNode* root;
	```
	A pointer `root` is declared that will point to the root of the trie structure used to store words.

3. **Access Modifier**
	```cpp
	public:
	```
	The `public` access modifier allows the methods `insert`, `check`, and `replaceWords` to be accessible from outside the class.

4. **Method Definition**
	```cpp
	void insert(string w) {
	```
	The `insert` method is defined to insert a word into the trie.

5. **Trie Node Traversal**
	```cpp
	    TrieNode* st = root;
	```
	A temporary pointer `st` is initialized to the root of the trie. This pointer will be used to traverse the trie as we insert characters of the word.

6. **Character Insertion**
	```cpp
	    for(char c: w) {
	```
	This loop iterates over each character in the word `w` to insert it into the trie.

7. **Trie Node Creation**
	```cpp
	        if(!st->child[c - 'a']) st->child[c - 'a'] = new TrieNode();
	```
	If the current character’s corresponding child node does not exist, a new trie node is created for that character.

8. **Traverse to Next Node**
	```cpp
	        st = st->child[c - 'a'];
	```
	After ensuring the child node exists, `st` is moved to the next node in the trie corresponding to the current character.

9. **Mark Word End**
	```cpp
	    st->isEnd = true;
	```
	After all characters are inserted, the last node in the trie is marked as the end of a valid word.

10. **Method Definition**
	```cpp
	string check(string w) {
	```
	The `check` method is defined to search for the shortest prefix of the word `w` in the trie.

11. **Trie Node Traversal**
	```cpp
	    TrieNode* st = root;
	```
	A temporary pointer `st` is initialized again to the root of the trie to start searching for the word’s prefix.

12. **Prefix Accumulation**
	```cpp
	    string s = "";
	```
	A string `s` is initialized to store the prefix that matches a word in the trie.

13. **Character Search**
	```cpp
	    for(char c: w) {
	```
	The loop iterates over each character in the word `w` to check for matching prefixes in the trie.

14. **Traverse Trie**
	```cpp
	        if(st->child[c - 'a']) st = st->child[c - 'a'];
	```
	If the current character exists in the trie, the pointer `st` moves to the corresponding child node.

15. **Exit Condition**
	```cpp
	        else break;
	```
	If a character is not found in the trie, the loop breaks as no valid prefix exists.

16. **Prefix Building**
	```cpp
	        s += c;
	```
	The current character is added to the string `s`, building the prefix.

17. **End of Word Check**
	```cpp
	        if(st->isEnd) return s;
	```
	If the current node is the end of a valid word in the trie, the prefix `s` is returned.

18. **Return Word**
	```cpp
	    return w;
	```
	If no valid prefix is found, the original word `w` is returned.

19. **Method Definition**
	```cpp
	string replaceWords(vector<string>& dictionary, string sentence) {
	```
	The `replaceWords` method is defined to replace words in a sentence based on the dictionary, using the trie structure.

20. **Initialize Trie**
	```cpp
	    root = new TrieNode();
	```
	A new root node is created for the trie to store the dictionary words.

21. **Insert Words into Trie**
	```cpp
	    for(auto w: dictionary) insert(w);
	```
	Each word from the dictionary is inserted into the trie using the `insert` method.

22. **Split Sentence**
	```cpp
	    istringstream ss(sentence);
	```
	The sentence is split into words using a string stream.

23. **Variable Initialization**
	```cpp
	    string word = "", ans = "";
	```
	Two strings `word` and `ans` are initialized. `word` stores the current word from the sentence, and `ans` accumulates the result.

24. **Process Each Word**
	```cpp
	    for(; ss>>word;) {
	```
	The loop processes each word in the sentence one by one.

25. **Word Replacement**
	```cpp
	        ans += check(word);
	```
	For each word, the `check` method is called to find its replacement (prefix), which is appended to `ans`.

26. **Add Space**
	```cpp
	        ans += ' ';
	```
	A space is added after each word to separate them in the final sentence.

27. **Remove Trailing Space**
	```cpp
	    ans.pop_back();
	```
	The trailing space is removed from the final result.

28. **Return Final Sentence**
	```cpp
	    return ans;
	```
	The final sentence, with all words replaced, is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n + m)
- **Worst Case:** O(n * m)

The time complexity is O(n * m) where n is the number of words in the sentence, and m is the length of the longest word. The best case occurs when no words are derivatives.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n * m)

The space complexity is O(n * m) where n is the number of words in the sentence and m is the length of the longest word, due to the storage of the Trie structure.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/replace-words/description/)

---
{{< youtube 5liJnc8iNeY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
