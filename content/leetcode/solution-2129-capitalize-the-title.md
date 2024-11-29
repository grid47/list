
+++
authors = ["grid47"]
title = "Leetcode 2129: Capitalize the Title"
date = "2024-04-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2129: Capitalize the Title in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "LDlUaEaunY0"
youtube_upload_date="2022-01-08"
youtube_thumbnail="https://i.ytimg.com/vi_webp/LDlUaEaunY0/maxresdefault.webp"
comments = true
+++



---
You are given a string consisting of multiple words separated by spaces. For each word, you need to change the capitalization based on the length of the word. If the word has 1 or 2 letters, it should be entirely in lowercase. If the word has 3 or more letters, the first letter should be uppercase and the remaining letters should be lowercase. Return the modified string with the updated capitalization for each word.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string where words are separated by a single space. Each word is a sequence of English letters with no leading or trailing spaces.
- **Example:** `title = 'hello World this IS an EXample'`
- **Constraints:**
	- 1 <= title.length <= 100
	- The string consists of words separated by a single space without any leading or trailing spaces.
	- Each word contains only uppercase and lowercase English letters and is non-empty.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the string with each word capitalized as per the given rules. Each word with a length of 1 or 2 letters will be lowercase, and the first letter of words with a length of 3 or more letters will be uppercase with the rest in lowercase.
- **Example:** `Input: title = 'hello World this IS an EXample' Output: 'Hello World This Is an Example'`
- **Constraints:**
	- Ensure that the title is processed correctly for each word based on its length.

{{< dots >}}
### Core Logic 🔍
**Goal:** To modify the capitalization of each word based on its length, we need to iterate through the string and apply the capitalization rules accordingly.

- Split the string into individual words.
- For each word, check its length.
- If the length is 1 or 2, convert all letters to lowercase.
- If the length is 3 or more, capitalize the first letter and convert the rest to lowercase.
- Join the words back together with a single space separating them.
- Return the resulting string.
{{< dots >}}
### Problem Assumptions ✅
- The string will always contain at least one word.
- Words are separated by exactly one space and no extra spaces exist.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: title = 'hello World this IS an EXample'`  \
  **Explanation:** The string contains five words. After processing each word based on its length, the result is 'Hello World This Is an Example'. Words with length 3 or more have their first letter capitalized, while shorter words are entirely in lowercase.

- **Input:** `Input: title = 'a quick Brown fox'`  \
  **Explanation:** Here, 'a' is a word with length 1 and is kept lowercase. 'quick' and 'Brown' have 3 or more letters, so their first letters are capitalized, and 'fox' is similarly processed. The result is 'a Quick Brown Fox'.

{{< dots >}}
## Approach 🚀
The approach to solving this problem involves iterating through each word in the string, applying the capitalization rules based on the word's length, and then combining the words back into a single string.

### Initial Thoughts 💭
- The main task is to process each word individually and change its capitalization according to its length.
- We need to be mindful of how spaces are handled when splitting and rejoining the string.
{{< dots >}}
### Edge Cases 🌐
- The problem statement guarantees that the input will not be empty, so this case does not need handling.
- Ensure that the solution handles strings with the maximum allowed length of 100 characters efficiently.
- Words of length 1 or 2 should remain lowercase, and words of length 3 or more should follow the capitalization rule.
- The solution must efficiently handle up to 100 characters in the input string.
{{< dots >}}
## Code 💻
```cpp
string capitalizeTitle(string s) {
    for (int i = 0, j = 0; i <= s.size(); ++i) {
        if (i == s.size() || s[i] == ' ') {
            if (i - j > 2)
                s[j] = toupper(s[j]);
            j = i + 1;
        }
        else
            s[i] = tolower(s[i]);
    }
    return s;
}
```

This function capitalizes the first letter of each word in a string, provided the word length is greater than two characters. All other letters are converted to lowercase.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string capitalizeTitle(string s) {
	```
	This line defines the function 'capitalizeTitle' that takes a string 's' as input and returns the string with each word capitalized according to the specified rule.

2. **Loop Initialization**
	```cpp
	    for (int i = 0, j = 0; i <= s.size(); ++i) {
	```
	This line initializes a for loop with two variables: 'i' (to iterate through each character of the string) and 'j' (to mark the beginning of each word). The loop continues until the end of the string.

3. **Condition Check**
	```cpp
	        if (i == s.size() || s[i] == ' ') {
	```
	This line checks if the current character is the end of the string or a space, indicating the end of a word.

4. **Word Length Check**
	```cpp
	            if (i - j > 2)
	```
	This line checks if the length of the current word (from 'j' to 'i') is greater than two characters. Only words longer than two characters will have their first letter capitalized.

5. **Capitalization**
	```cpp
	                s[j] = toupper(s[j]);
	```
	This line capitalizes the first letter of the current word (i.e., the character at position 'j').

6. **Update Word Start**
	```cpp
	            j = i + 1;
	```
	This line updates the value of 'j' to mark the start of the next word after the space or end of the string.

7. **Lowercase Else**
	```cpp
	        else
	```
	This line handles the case where the current character is part of a word that is not at the start. The characters in these positions will be converted to lowercase.

8. **Lowercasing**
	```cpp
	            s[i] = tolower(s[i]);
	```
	This line converts the current character at position 'i' to lowercase, ensuring that non-initial letters of words are always in lowercase.

9. **Return Statement**
	```cpp
	    return s;
	```
	This line returns the modified string 's', with all words properly capitalized according to the rules.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we iterate through each character in the string, where n is the length of the input string.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) because we store the words in an array temporarily during processing, where n is the length of the input string.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/capitalize-the-title/description/)

---
{{< youtube LDlUaEaunY0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
