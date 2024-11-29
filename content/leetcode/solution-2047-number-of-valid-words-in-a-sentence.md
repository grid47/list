
+++
authors = ["grid47"]
title = "Leetcode 2047: Number of Valid Words in a Sentence"
date = "2024-04-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2047: Number of Valid Words in a Sentence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "sl4thQAqnJg"
youtube_upload_date="2021-10-24"
youtube_thumbnail="https://i.ytimg.com/vi_webp/sl4thQAqnJg/maxresdefault.webp"
comments = true
+++



---
A sentence consists of lowercase letters ('a' to 'z'), digits ('0' to '9'), hyphens ('-'), punctuation marks ('!', '.', and ','), and spaces (' ') only. A token is any sequence of characters separated by spaces. A token is considered a valid word if all the following conditions are met:

1. It does not contain any digits.
2. It contains at most one hyphen ('-'), and if present, the hyphen must be surrounded by lowercase letters.
3. It contains at most one punctuation mark, and if present, the punctuation mark must be at the end of the token.

Given a sentence, count the number of tokens that are valid words.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A string `sentence` consisting of lowercase English letters, digits, spaces, hyphens, and punctuation marks.
- **Example:** `Input: sentence = "hello world! test-case 1234, valid-word."`
- **Constraints:**
	- 1 <= sentence.length <= 1000
	- sentence contains at least one token.
	- Sentence characters are limited to 'a'-'z', '0'-'9', '-', '!', '.', ',', and ' '.

{{< dots >}}
### Output Specifications 📤
- **Output:** An integer representing the count of valid words in the sentence.
- **Example:** `Output: 2`
- **Constraints:**
	- The output is always a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine the number of valid words in the given sentence.

- Split the sentence into tokens based on spaces.
- For each token, check if it satisfies the conditions for being a valid word.
- Count the tokens that are valid words.
{{< dots >}}
### Problem Assumptions ✅
- The input sentence always contains at least one token.
- Characters are limited to the defined set of letters, digits, and special characters.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: sentence = "word1 -a invalid! valid-word."`  \
  **Explanation:** The valid words are "valid-word.". Other tokens fail due to digits, improper hyphen usage, or invalid punctuation placement. Output: 1.

- **Input:** `Input: sentence = "a-b test valid! example."`  \
  **Explanation:** The valid words are "a-b", "test", "valid!", and "example.". Output: 4.

{{< dots >}}
## Approach 🚀
Use a helper function to validate tokens according to the rules and iterate through the tokens of the sentence to count valid words.

### Initial Thoughts 💭
- A token is valid if it adheres to strict rules regarding digits, hyphens, and punctuation marks.
- Each token can be evaluated independently of others.
- The solution can efficiently process the sentence by splitting it into tokens and checking each token's validity using a helper function.
{{< dots >}}
### Edge Cases 🌐
- No empty input cases as the sentence is guaranteed to have at least one token.
- Sentences with maximum length (1000 characters).
- Tokens with only special characters like '---' or '...'.
- Tokens with mixed valid and invalid combinations like 'a--b' or 'a,b.'
- Ensure proper handling of edge cases like multiple spaces or trailing/leading spaces.
{{< dots >}}
## Code 💻
```cpp
class Solution {
bool valid(string &s) {
    int hyphen = 0, N = s.size();
    for (int i = 0; i < N; ++i) {
        if (isdigit(s[i])) return false; // no digit
        if (isalpha(s[i])) continue; // skip letters
        if (s[i] == '-') {
            if (++hyphen > 1) return false; // at most one hyphen allowed
            if (i - 1 < 0 || !isalpha(s[i - 1]) || i + 1 >= N || !isalpha(s[i + 1])) return false; // hyphen must be surrounded by letters
        } else if (i != N - 1) return false; // punctuation, if any, must be the last character of token
    }
    return true;
}
public:
int countValidWords(string s) {
    string w;
    istringstream ss(s);
    int ans = 0;
    while (ss >> w) ans += valid(w);
    return ans;
}
```

This code defines a solution for counting the number of valid words in a given string. A valid word is one that does not contain digits, has at most one hyphen that is surrounded by letters, and may have punctuation only as the last character.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class Solution {
	```
	This defines the `Solution` class, which contains the method `countValidWords` to solve the problem of counting valid words in a string.

2. **Helper Function Declaration**
	```cpp
	bool valid(string &s) {
	```
	This declares the `valid` helper function that checks if a given string `s` is a valid word.

3. **Variable Initialization**
	```cpp
	    int hyphen = 0, N = s.size();
	```
	Initializes `hyphen` to count the number of hyphens and `N` to store the size of the string `s`.

4. **Loop Start**
	```cpp
	    for (int i = 0; i < N; ++i) {
	```
	This loop iterates through each character of the string `s`.

5. **Digit Check**
	```cpp
	        if (isdigit(s[i])) return false; // no digit
	```
	Checks if the current character is a digit. If so, returns `false` because digits are not allowed in valid words.

6. **Alpha Check**
	```cpp
	        if (isalpha(s[i])) continue; // skip letters
	```
	If the character is a letter, it is valid, so the loop continues to the next character.

7. **Hyphen Check**
	```cpp
	        if (s[i] == '-') {
	```
	Checks if the current character is a hyphen.

8. **Hyphen Count Check**
	```cpp
	            if (++hyphen > 1) return false; // at most one hyphen allowed
	```
	If there is more than one hyphen in the word, returns `false` since only one hyphen is allowed.

9. **Hyphen Surrounding Check**
	```cpp
	            if (i - 1 < 0 || !isalpha(s[i - 1]) || i + 1 >= N || !isalpha(s[i + 1])) return false; // hyphen must be surrounded by letters
	```
	Checks if the hyphen is properly surrounded by letters (both before and after). If not, returns `false`.

10. **Punctuation Check**
	```cpp
	        } else if (i != N - 1) return false; // punctuation, if any, must be the last character of token
	```
	If the character is not a letter or hyphen and it is not the last character, returns `false` because punctuation should only appear at the end of the word.

11. **Return True**
	```cpp
	    return true;
	```
	Returns `true` if the string `s` passed all validity checks, indicating it is a valid word.

12. **Public Section**
	```cpp
	public:
	```
	Marks the beginning of the public section of the class where the main solution method resides.

13. **Main Function Declaration**
	```cpp
	int countValidWords(string s) {
	```
	This is the declaration of the `countValidWords` function that counts the valid words in the given string `s`.

14. **String Initialization**
	```cpp
	    string w;
	```
	Initializes the string `w`, which will be used to store individual words as the string `s` is processed.

15. **Stream Initialization**
	```cpp
	    istringstream ss(s);
	```
	Initializes an input string stream `ss` to process the input string `s` word by word.

16. **Result Initialization**
	```cpp
	    int ans = 0;
	```
	Initializes the integer `ans` to store the count of valid words.

17. **Loop Through Words**
	```cpp
	    while (ss >> w) ans += valid(w);
	```
	This loop extracts words from the string stream `ss` and adds to `ans` the number of valid words using the `valid` function.

18. **Return Result**
	```cpp
	    return ans;
	```
	Returns the total count of valid words.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the number of characters in the sentence.
- **Average Case:** O(n), where n is the number of characters in the sentence.
- **Worst Case:** O(n), where n is the number of characters in the sentence.

Each token is processed in linear time relative to its length, and all tokens are processed sequentially.

### Space Complexity 💾
- **Best Case:** O(1) if token processing is done in place.
- **Worst Case:** O(n) for storing tokens.

Space is used for splitting the sentence into tokens and temporary storage during validation.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-valid-words-in-a-sentence/description/)

---
{{< youtube sl4thQAqnJg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
