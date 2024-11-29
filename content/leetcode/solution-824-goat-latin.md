
+++
authors = ["grid47"]
title = "Leetcode 824: Goat Latin"
date = "2024-08-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 824: Goat Latin in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "pTLNHVWiQk0"
youtube_upload_date="2020-03-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/pTLNHVWiQk0/maxresdefault.webp"
comments = true
+++



---
You are given a sentence with words separated by spaces. Each word consists of only lowercase and uppercase letters. Your task is to convert the sentence into a new language called 'Goat Latin' by following the rules below:

1. If a word begins with a vowel ('a', 'e', 'i', 'o', or 'u'), append 'ma' to the end of the word.
2. If a word begins with a consonant, remove the first letter, move it to the end, and add 'ma'.
3. Add one letter 'a' to the end of each word depending on its position in the sentence (1st word gets 'a', 2nd gets 'aa', 3rd gets 'aaa', etc.).

Return the final sentence in Goat Latin.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string, sentence, which contains words separated by spaces.
- **Example:** `Input: sentence = 'The quick brown fox'`
- **Constraints:**
	- 1 <= sentence.length <= 150
	- The sentence consists of English letters and spaces.
	- There are no leading or trailing spaces in the sentence.
	- All words are separated by a single space.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a string representing the sentence after converting it to Goat Latin.
- **Example:** `Output: 'heTmaa uickqmaaa rownbmaaaa oxfmaaaaa'`
- **Constraints:**
	- The output must be a string.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to convert the sentence into Goat Latin according to the specified rules. Each word must be processed based on whether it starts with a vowel or consonant, and the appropriate suffix must be added based on the word's position in the sentence.

- Step 1: Split the input sentence into words.
- Step 2: For each word, check if it starts with a vowel or consonant.
- Step 3: Modify the word accordingly (append 'ma' or move the first letter to the end and append 'ma').
- Step 4: Add the correct number of 'a's to the end of the word based on its position in the sentence.
- Step 5: Join all words back together into a final sentence.
{{< dots >}}
### Problem Assumptions ✅
- All words in the sentence are valid words made up of lowercase and uppercase English letters.
- There are no punctuation marks or special characters in the sentence.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: sentence = 'The quick brown fox'`  \
  **Explanation:** The sentence 'The quick brown fox' would be converted to Goat Latin as 'heTmaa uickqmaaa rownbmaaaa oxfmaaaaa'. The first word starts with a consonant, so 'T' is moved to the end and 'ma' is added. The second word starts with a consonant, so 'q' is moved to the end, 'ma' is added, and one 'a' is appended. This continues for all words in the sentence.

{{< dots >}}
## Approach 🚀
We can solve this problem by iterating through each word in the sentence, applying the Goat Latin rules for vowels and consonants, and adding the appropriate number of 'a's based on the word's index. We then return the modified sentence.

### Initial Thoughts 💭
- The problem is straightforward, with simple string manipulations.
- We need to handle each word based on its initial letter and word position in the sentence. String operations like checking the first letter and modifying words are key here.
{{< dots >}}
### Edge Cases 🌐
- The input will always have at least one word, so empty input is not a concern.
- The sentence length could be up to 150 characters, which is manageable.
- Single-word sentences should be handled correctly.
- Ensure that all the words are correctly modified and that the number of 'a's corresponds to their position in the sentence.
{{< dots >}}
## Code 💻
```cpp
string toGoatLatin(string str) {
    stringstream iss(str), oss;
    set<char> s = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    string word;
    string a;
    while(iss >> word) {
        a.push_back('a');
        if(s.count(word[0])) {
            oss << ' ' << word << "ma" << a;
        } else {
            oss << ' ' << word.substr(1) << word[0]  << "ma" << a;                
        }
    }
    return oss.str().substr(1);
}
```

This function converts a given string to Goat Latin by modifying the string according to specific rules. For each word, it checks if it starts with a vowel or consonant and appends appropriate suffixes.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string toGoatLatin(string str) {
	```
	This line declares the function `toGoatLatin` that takes a string as an argument and returns a string.

2. **Variable Initialization**
	```cpp
	    stringstream iss(str), oss;
	```
	Initializes two stringstreams, `iss` for reading from the input string and `oss` for building the output string.

3. **Set Declaration**
	```cpp
	    set<char> s = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
	```
	Defines a set of characters `s` containing vowels (both lowercase and uppercase) for checking the first letter of each word.

4. **Variable Declaration**
	```cpp
	    string word;
	```
	Declares a string variable `word` to temporarily store each word from the input string.

5. **Variable Declaration**
	```cpp
	    string a;
	```
	Declares a string variable `a` to hold the 'a's appended to the word in the process of converting it to Goat Latin.

6. **Loop**
	```cpp
	    while(iss >> word) {
	```
	Starts a loop that reads each word from the input string using the stringstream `iss`.

7. **String Operation**
	```cpp
	        a.push_back('a');
	```
	Appends an 'a' to the string `a` for each word processed, helping to create the Goat Latin suffix.

8. **Condition Check**
	```cpp
	        if(s.count(word[0])) {
	```
	Checks if the first letter of the word is a vowel by checking membership in the set `s`.

9. **Else Clause**
	```cpp
	        } else {
	```
	If the word does not start with a vowel, process it as follows.

10. **Return Statement**
	```cpp
	    return oss.str().substr(1);
	```
	Returns the output string, removing the first space that was added before the first word.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the number of words in the sentence.
- **Average Case:** O(n), where n is the number of words in the sentence.
- **Worst Case:** O(n), where n is the number of words in the sentence.

The time complexity is linear because we process each word in the sentence once.

### Space Complexity 💾
- **Best Case:** O(n), where n is the number of words in the sentence, for storing the modified words.
- **Worst Case:** O(n), where n is the number of words in the sentence, for storing the modified words.

The space complexity is linear as we need space to store the modified sentence.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/goat-latin/description/)

---
{{< youtube pTLNHVWiQk0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
