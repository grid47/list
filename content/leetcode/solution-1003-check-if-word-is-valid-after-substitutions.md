
+++
authors = ["grid47"]
title = "Leetcode 1003: Check If Word Is Valid After Substitutions"
date = "2024-07-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1003: Check If Word Is Valid After Substitutions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "1ImaQNKTVnw"
youtube_upload_date="2020-07-19"
youtube_thumbnail="https://i.ytimg.com/vi/1ImaQNKTVnw/maxresdefault.jpg"
comments = true
+++



---
You are given a string s consisting of only the characters 'a', 'b', and 'c'. A string is considered valid if it can be formed by repeatedly inserting the substring 'abc' into any position of an empty string. Your task is to determine if s can be a valid string after performing this operation any number of times.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a string s of length n (1 <= n <= 2 * 10^4), consisting of only the characters 'a', 'b', and 'c'.
- **Example:** `s = 'abccba'`
- **Constraints:**
	- 1 <= s.length <= 2 * 10^4
	- s consists of only the characters 'a', 'b', and 'c'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if the string s is valid, otherwise return false.
- **Example:** `Output: true`
- **Constraints:**
	- The output will be a boolean value.

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine if a string can be formed by inserting 'abc' into an empty string any number of times.

- Use a stack to track the characters 'a', 'b', and 'c'.
- Iterate through the string. If a 'c' is encountered, check if the last two characters in the stack are 'b' and 'a', respectively.
- If the stack is valid after processing all characters in s, return true. Otherwise, return false.
{{< dots >}}
### Problem Assumptions ✅
- The input string only contains 'a', 'b', and 'c'.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = 'abcabc'`  \
  **Explanation:** The string 'abcabc' is valid because it can be formed by repeatedly inserting 'abc' into an empty string: '' -> 'abc' -> 'abcabc'.

- **Input:** `Input: s = 'aabcbc'`  \
  **Explanation:** The string 'aabcbc' is valid because it can be formed by inserting 'abc' into the string: '' -> 'abc' -> 'aabcbc'.

- **Input:** `Input: s = 'abccba'`  \
  **Explanation:** The string 'abccba' is invalid because it is impossible to form it by inserting 'abc' into an empty string.

{{< dots >}}
## Approach 🚀
To solve this problem, we can use a stack-based approach where we check for the proper sequence of characters while iterating through the string.

### Initial Thoughts 💭
- The string must follow a strict 'abc' insertion pattern, meaning every 'c' must follow 'b' and 'a'.
- Using a stack will help efficiently track the characters in the correct order.
{{< dots >}}
### Edge Cases 🌐
- If the string is empty, return false since no valid string can be formed.
- Ensure the solution handles strings of maximum length (20,000 characters).
- If the string contains characters other than 'a', 'b', or 'c', return false.
- The solution must be efficient in both time and space to handle large inputs.
{{< dots >}}
## Code 💻
```cpp
bool isValid(string s) {
    vector<char> stk;
    for(char c : s) {
        if(c == 'c') {
            int n = stk.size();
            if(n < 2 ||
              stk[n - 1] != 'b' ||
              stk[n - 2] != 'a' ) 
                return false;
            stk.pop_back();
            stk.pop_back();
        } else stk.push_back(c);
    }
    
    return stk.size() == 0;
}
```

This function checks if the string `s` is valid according to the rule that 'c' must always follow 'a' and 'b' in sequence. It uses a stack to validate the sequence of characters.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool isValid(string s) {
	```
	Defines the function `isValid`, which checks whether the string `s` follows the specific sequence rule: 'a' -> 'b' -> 'c'.

2. **Stack Initialization**
	```cpp
	    vector<char> stk;
	```
	Initializes an empty stack `stk` to help track the sequence of characters in the string.

3. **Iterate Over String**
	```cpp
	    for(char c : s) {
	```
	Iterates through each character `c` in the input string `s`.

4. **Check for 'c'**
	```cpp
	        if(c == 'c') {
	```
	Checks if the current character `c` is 'c'. If it is, it will attempt to verify if it follows the 'a' and 'b' sequence.

5. **Get Stack Size**
	```cpp
	            int n = stk.size();
	```
	Stores the current size of the stack in `n` to check if there are enough characters to form the required sequence.

6. **Check Sequence Validity**
	```cpp
	            if(n < 2 ||
	```
	Checks if the stack has fewer than two characters, which would make it impossible to form the 'a' -> 'b' sequence before 'c'.

7. **Validate Last Characters**
	```cpp
	              stk[n - 1] != 'b' ||
	```
	Ensures the last character in the stack is 'b', which must precede 'c'.

8. **Validate Preceding Character**
	```cpp
	              stk[n - 2] != 'a' ) 
	```
	Ensures that the second-to-last character in the stack is 'a', which must precede 'b' and 'c'.

9. **Return False**
	```cpp
	                return false;
	```
	If the sequence is invalid (either there are not enough characters or the sequence is incorrect), return `false`.

10. **Pop Elements**
	```cpp
	            stk.pop_back();
	```
	Pops the last character ('b') from the stack after confirming the sequence 'a' -> 'b' -> 'c'.

11. **Pop 'a' from Stack**
	```cpp
	            stk.pop_back();
	```
	Pops the second-to-last character ('a') from the stack to complete the valid sequence.

12. **Push Character to Stack**
	```cpp
	        } else stk.push_back(c);
	```
	If the character is not 'c', it is added to the stack for future validation.

13. **Return Stack Validity**
	```cpp
	    return stk.size() == 0;
	```
	Checks if the stack is empty at the end, which would indicate that all characters were successfully processed according to the rule. If the stack is not empty, the sequence is invalid.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we iterate through the string once, where n is the length of the string.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the stack used to track the characters.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/description/)

---
{{< youtube 1ImaQNKTVnw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
