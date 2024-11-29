
+++
authors = ["grid47"]
title = "Leetcode 2351: First Letter to Appear Twice"
date = "2024-03-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2351: First Letter to Appear Twice in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Bit Manipulation","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "zIFHijNYeCE"
youtube_upload_date="2022-07-24"
youtube_thumbnail="https://i.ytimg.com/vi_webp/zIFHijNYeCE/maxresdefault.webp"
comments = true
+++



---
Given a string s of lowercase English letters, return the first letter that appears twice.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `s` consisting of lowercase English letters.
- **Example:** `Input: s = "axybczab"`
- **Constraints:**
	- 2 <= s.length <= 100
	- s consists of lowercase English letters.
	- s contains at least one repeated letter.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the first letter that appears twice in the string.
- **Example:** `Output: "a"`
- **Constraints:**
	- The string will contain at least one repeated letter.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the first letter that appears twice in the string by tracking each letter's occurrence.

- Iterate through the string and track the occurrence of each character.
- If a character appears again, return it immediately.
- If no character appears twice, the function should return the first character that repeats.
{{< dots >}}
### Problem Assumptions ✅
- The input string will contain at least one repeated letter.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = "axybczab"`  \
  **Explanation:** Here, the letter 'a' is the first to appear twice, so it is returned.

{{< dots >}}
## Approach 🚀
Use a set to track the characters that have been seen as we iterate through the string.

### Initial Thoughts 💭
- The problem is asking for the first repeating letter, so we should stop as soon as we encounter the second occurrence of a letter.
- A set can be used to keep track of characters we've already seen, and we return the first one that repeats.
{{< dots >}}
### Edge Cases 🌐
- The input will always contain at least one repeated letter, so there are no empty inputs.
- The solution should handle input strings up to the length of 100 efficiently.
- If the string contains multiple letters repeating, the first one encountered in the string is the answer.
- Ensure that the solution works for all strings of length between 2 and 100.
{{< dots >}}
## Code 💻
```cpp
char repeatedCharacter(string s) {
    vector<int> v(26);
    for(char c:s){
        v[c-'a']++;
        if(v[c-'a']>1)return c;
    }
    return 'a';
}
```

This code defines a function `repeatedCharacter` which takes a string `s` and returns the first character that repeats. It uses a vector of size 26 to count occurrences of each character in the string.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	char repeatedCharacter(string s) {
	```
	The function `repeatedCharacter` is declared, which accepts a string `s` and returns a character.

2. **Variable Initialization**
	```cpp
	    vector<int> v(26);
	```
	A vector `v` of size 26 is initialized to count the occurrences of each lowercase letter ('a' to 'z').

3. **Loop Start**
	```cpp
	    for(char c:s){
	```
	A loop is initiated to iterate over each character `c` in the string `s`.

4. **Count Character**
	```cpp
	        v[c-'a']++;
	```
	For each character `c`, the corresponding index in the vector `v` is incremented to count the occurrences of that character.

5. **Condition Check**
	```cpp
	        if(v[c-'a']>1)return c;
	```
	If the count of the current character exceeds 1, meaning it has been repeated, the function immediately returns that character.

6. **Return Statement**
	```cpp
	    return 'a';
	```
	If no repeated character is found, the function returns 'a' by default, assuming no repeats are found in the string.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

We only need to iterate through the string once, making the time complexity O(n), where n is the length of the string.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) because we use a set to track the letters we've seen, and the set's size can grow up to the size of the input string.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/first-letter-to-appear-twice/description/)

---
{{< youtube zIFHijNYeCE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
