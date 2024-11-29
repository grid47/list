
+++
authors = ["grid47"]
title = "Leetcode 3136: Valid Word"
date = "2023-12-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3136: Valid Word in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "-sU51QkOwLY"
youtube_upload_date="2024-05-05"
youtube_thumbnail="https://i.ytimg.com/vi_webp/-sU51QkOwLY/maxresdefault.webp"
comments = true
+++



---
You are given a string `word`. The word is considered valid if it satisfies the following conditions:

1. It contains at least 3 characters.
2. It contains only digits (0-9) and English letters (both uppercase and lowercase).
3. It must include at least one vowel ('a', 'e', 'i', 'o', 'u' and their uppercase counterparts).
4. It must include at least one consonant (an English letter that is not a vowel).

Return `true` if the word is valid, otherwise return `false`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string `word` containing English letters, digits, and special characters.
- **Example:** `Example 1:
Input: word = "234Abcd"
Output: true`
- **Constraints:**
	- 1 <= word.length <= 20
	- word consists of English uppercase and lowercase letters, digits, '@', '#', and '$'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return `true` if the word satisfies the conditions for a valid word, otherwise return `false`.
- **Example:** `Example 1:
Input: word = "234Abcd"
Output: true`
- **Constraints:**
	- The result must be either `true` or `false`.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if the word satisfies all the conditions for being a valid word. We need to check the length, the presence of vowels and consonants, and that the word contains only the allowed characters.

- Check if the word length is at least 3.
- Check if the word contains only digits and English letters.
- Check for at least one vowel and at least one consonant in the word.
- Return `true` if all conditions are satisfied, otherwise return `false`.
{{< dots >}}
### Problem Assumptions ✅
- The word contains only the allowed characters (digits, letters, and specified special characters).
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1:`  \
  **Explanation:** The word '234Abcd' satisfies the conditions: it has 7 characters, it contains a vowel ('A'), a consonant ('b'), and only valid characters (digits and letters).

- **Input:** `Example 2:`  \
  **Explanation:** The word 'a3' fails because it has fewer than 3 characters and does not contain a consonant.

- **Input:** `Example 3:`  \
  **Explanation:** The word 'a3$e' fails because it contains an invalid character ('$') and does not have a consonant.

{{< dots >}}
## Approach 🚀
We can solve this problem by iterating through the string and checking each condition: length, allowed characters, presence of vowels, and consonants.

### Initial Thoughts 💭
- The problem requires checking several conditions in a single pass over the string.
- We can use boolean flags to track the presence of vowels, consonants, and other necessary checks as we iterate through the string.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs as the word length is always at least 1.
- The word length will not exceed 20 characters, so the input size is small enough for a simple linear pass.
- The presence of special characters like '@', '#', or '$' should be checked to ensure they are invalid.
- Ensure that the word length is at least 3 and that all characters are valid (only digits and English letters).
{{< dots >}}
## Code 💻
```cpp
bool isValid(string word) {
    set<char> st;
    bool upper = false, lower = false;
    bool vowel = false, conso = false, number = false;
    
    for(char x : word) {
        
        if(x >= 'a' && x <= 'z') lower = true;
        if(x >= 'A' && x <= 'Z') upper = true;
        st.insert(x);
        if(x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U' ||
           x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
                vowel = true;
        else if((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
                conso  = true;
        else if(isdigit(x)) {}
        else    return false;
        
    }
    
    return vowel && conso && st.size() >= 3;
    
}
```

This function `isValid` validates a string based on several conditions: it must contain at least one vowel, one consonant, and at least 3 distinct characters. It also checks for the presence of upper and lower case letters and numbers.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool isValid(string word) {
	```
	Defines the function `isValid`, which takes a string `word` and checks its validity according to specific criteria (presence of vowels, consonants, and distinct characters).

2. **Variable Initialization**
	```cpp
	    set<char> st;
	```
	Initializes a set `st` to store unique characters from the string to check the condition that the string contains at least 3 distinct characters.

3. **Variable Initialization**
	```cpp
	    bool upper = false, lower = false;
	```
	Initializes two boolean variables `upper` and `lower` to track the presence of uppercase and lowercase characters in the string.

4. **Variable Initialization**
	```cpp
	    bool vowel = false, conso = false, number = false;
	```
	Initializes three boolean variables: `vowel` to check for vowels, `conso` for consonants, and `number` to track digits in the string.

5. **Iteration**
	```cpp
	    for(char x : word) {
	```
	Starts a loop to iterate through each character `x` in the string `word`.

6. **Conditional Check**
	```cpp
	        if(x >= 'a' && x <= 'z') lower = true;
	```
	Checks if the character `x` is a lowercase letter and updates the `lower` flag accordingly.

7. **Conditional Check**
	```cpp
	        if(x >= 'A' && x <= 'Z') upper = true;
	```
	Checks if the character `x` is an uppercase letter and updates the `upper` flag accordingly.

8. **Set Insertion**
	```cpp
	        st.insert(x);
	```
	Inserts the character `x` into the set `st` to ensure that only unique characters are considered for the condition of having at least 3 distinct characters.

9. **Conditional Check**
	```cpp
	        if(x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U' ||
	```
	Checks if the character `x` is a vowel (either uppercase or lowercase).

10. **Conditional Check**
	```cpp
	           x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
	```
	Continues the check for vowels, considering both uppercase and lowercase vowels.

11. **Flag Update**
	```cpp
	                vowel = true;
	```
	If the character `x` is a vowel, updates the `vowel` flag to true.

12. **Conditional Check**
	```cpp
	        else if((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
	```
	Checks if the character `x` is a consonant (i.e., a letter that is not a vowel).

13. **Flag Update**
	```cpp
	                conso  = true;
	```
	If the character `x` is a consonant, updates the `conso` flag to true.

14. **Digit Check**
	```cpp
	        else if(isdigit(x)) {}
	```
	Checks if the character `x` is a digit. If it is, it does nothing (as the problem does not require any action for digits).

15. **Invalid Character Check**
	```cpp
	        else    return false;
	```
	If the character `x` is neither a letter nor a digit, returns `false`, indicating an invalid character.

16. **Return Statement**
	```cpp
	    return vowel && conso && st.size() >= 3;
	```
	Returns `true` if the string contains at least one vowel, one consonant, and 3 or more distinct characters. Otherwise, returns `false`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear, where n is the length of the input string.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant since we are using only a few variables to track the conditions.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/valid-word/description/)

---
{{< youtube -sU51QkOwLY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
