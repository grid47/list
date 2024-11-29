
+++
authors = ["grid47"]
title = "Leetcode 520: Detect Capital"
date = "2024-09-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 520: Detect Capital in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/520.webp"
youtube = "TIJRBKK1gXE"
youtube_upload_date="2023-01-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/TIJRBKK1gXE/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/520.webp" 
    alt="A word where the capital letters are detected, glowing softly as the word is analyzed."
    caption="Solution to LeetCode 520: Detect Capital Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
We define the correct usage of capital letters in a word as either all letters being capitalized, all letters being lowercase, or only the first letter being capitalized while the rest are lowercase. Given a string word, return true if the word follows one of these patterns, and false otherwise.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `word` which is composed of English alphabet letters.
- **Example:** `word = 'HELLO'`
- **Constraints:**
	- 1 <= word.length <= 100
	- The word contains only uppercase and lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if the capital usage in the word is correct, otherwise return false.
- **Example:** `true, false`
- **Constraints:**
	- The output should be a boolean indicating whether the word follows the correct capitalization rules.

{{< dots >}}
### Core Logic 🔍
**Goal:** Check if the capitalization pattern of the word matches one of the valid patterns.

- 1. Check if the word is completely uppercase.
- 2. Check if the word is completely lowercase.
- 3. Check if only the first letter is uppercase and the rest are lowercase.
{{< dots >}}
### Problem Assumptions ✅
- The word contains only English alphabet characters.
- The length of the word is between 1 and 100 characters.
{{< dots >}}
## Examples 🧩
- **Input:** `word = 'HELLO'`  \
  **Explanation:** The word is all in uppercase, which is valid.

- **Input:** `word = 'FlaG'`  \
  **Explanation:** The word has an incorrect capitalization pattern (only the first letter is uppercase and the rest are lowercase), which is invalid.

{{< dots >}}
## Approach 🚀
The approach is to verify the capitalization pattern of the word by checking each of the possible valid patterns.

### Initial Thoughts 💭
- We need to check the word against the three valid capitalization patterns.
- A simple check on the word can verify the capitalization pattern.
{{< dots >}}
### Edge Cases 🌐
- If the word length is 1, it is always valid since a single character is either uppercase or lowercase.
- The algorithm must handle words of length up to 100 efficiently.
- All uppercase or all lowercase words should always return true.
- Ensure the algorithm efficiently handles all inputs within the constraints.
{{< dots >}}
## Code 💻
```cpp
bool detectCapitalUse(string word) {
    for(int i = 1; i < word.size(); i++) {
        if(isupper(word[1]) != isupper(word[i]) ||
          islower(word[0]) && isupper(word[i])) 
            return false;
    }
    return true;
}
```

This function checks whether a given word uses capital letters correctly based on certain capitalization rules.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool detectCapitalUse(string word) {
	```
	This defines the `detectCapitalUse` function that checks the capitalization of a given word.

2. **Loop**
	```cpp
	    for(int i = 1; i < word.size(); i++) {
	```
	A loop starts at index 1 to iterate through each character of the word, starting from the second character.

3. **Condition Check**
	```cpp
	        if(isupper(word[1]) != isupper(word[i]) ||
	```
	Check if the current character's case (upper or lower) matches the second character's case. If not, or if it violates other capitalization rules, return false.

4. **Condition Check**
	```cpp
	          islower(word[0]) && isupper(word[i])) 
	```
	Additionally, check if the first character is lowercase while a later character is uppercase, which would be an invalid capitalization pattern.

5. **Return False**
	```cpp
	            return false;
	```
	If any capitalization rules are violated, return false immediately.

6. **Return True**
	```cpp
	    return true;
	```
	If all checks pass without returning false, return true, meaning the capitalization use is correct.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) where n is the length of the word.
- **Average Case:** O(n) where n is the length of the word.
- **Worst Case:** O(n) where n is the length of the word.

The time complexity is O(n) because we only need to check the word once.

### Space Complexity 💾
- **Best Case:** O(1), no additional space required.
- **Worst Case:** O(1), since we only need a constant amount of space.

The space complexity is O(1) because we do not need any additional space beyond the input.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/detect-capital/description/)

---
{{< youtube TIJRBKK1gXE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
