
+++
authors = ["grid47"]
title = "Leetcode 1328: Break a Palindrome"
date = "2024-06-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1328: Break a Palindrome in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "B5v5rDR7c9A"
youtube_upload_date="2021-02-13"
youtube_thumbnail="https://i.ytimg.com/vi/B5v5rDR7c9A/maxresdefault.jpg"
comments = true
+++



---
Given a string `palindrome` that is a palindrome, you need to replace exactly one character with any lowercase English letter such that the resulting string is no longer a palindrome. The resulting string should be the lexicographically smallest string possible. If it is not possible to change the string to make it non-palindromic, return an empty string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `palindrome` which is guaranteed to be a palindrome and consists of only lowercase English letters.
- **Example:** `For palindrome = 'abba', the string is a palindrome and needs to be modified to be non-palindromic.`
- **Constraints:**
	- 1 <= palindrome.length <= 1000
	- palindrome consists of only lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the modified string that is no longer a palindrome and is the lexicographically smallest possible result. If no such modification is possible, return an empty string.
- **Example:** `For palindrome = 'abba', the output could be 'aaba'.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To break the palindrome by replacing one character to make the string non-palindromic, while ensuring the result is the lexicographically smallest possible.

- 1. Traverse the string from left to right up to the midpoint.
- 2. If a character is not 'a', replace it with 'a' and return the modified string.
- 3. If no modification is made, change the last character to 'b' if possible.
- 4. If the length of the string is 1, return an empty string as no modification is possible.
{{< dots >}}
### Problem Assumptions ✅
- The input string is guaranteed to be a palindrome.
{{< dots >}}
## Examples 🧩
- **Input:** `For palindrome = 'abccba', the output is 'aaccba'.`  \
  **Explanation:** By changing the first 'b' to 'a', the string is no longer a palindrome and the result is lexicographically the smallest.

- **Input:** `For palindrome = 'a', the output is an empty string.`  \
  **Explanation:** Since a single character string cannot be modified to become non-palindromic, the function returns an empty string.

{{< dots >}}
## Approach 🚀
The solution uses a greedy approach to replace characters in the palindrome. The algorithm first checks if a character can be replaced with 'a' to minimize the string lexicographically. If no replacement is possible, the last character is changed to 'b' to break the palindrome.

### Initial Thoughts 💭
- The palindrome property can be exploited by checking each character from left to right.
- We need to consider edge cases where the string is too short or already in the form where no modification is possible.
{{< dots >}}
### Edge Cases 🌐
- An empty string will not be provided as input, based on the problem constraints.
- The algorithm should efficiently handle strings with up to 1000 characters.
- If the string is of length 1, return an empty string.
- The solution must handle strings that are palindromes and only contain lowercase English letters.
{{< dots >}}
## Code 💻
```cpp
string breakPalindrome(string palindrome) {
    int n = palindrome.size();
    for(int i = 0; i < n / 2; i++) {
        if(palindrome[i] != 'a') {
            palindrome[i] = 'a';
            return palindrome;
        }
    }
    palindrome[n - 1] = 'b';
    return n < 2 ? "" : palindrome;
}
```

This function takes a palindrome string and breaks it by changing one character to make it not a palindrome, ensuring that the string remains lexicographically as small as possible. If the string has fewer than two characters, it returns an empty string.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string breakPalindrome(string palindrome) {
	```
	The function 'breakPalindrome' is declared. It takes a string 'palindrome' as input and returns a string as the output after breaking the palindrome.

2. **String Length Calculation**
	```cpp
	    int n = palindrome.size();
	```
	The size of the input string 'palindrome' is calculated and stored in variable 'n'. This is used to determine the length of the string and guide the loop for processing.

3. **Loop Setup**
	```cpp
	    for(int i = 0; i < n / 2; i++) {
	```
	A loop is initiated to iterate over the first half of the string. The loop ensures that the palindrome is checked from the left side, as the second half is symmetric.

4. **Check for Non-'a' Character**
	```cpp
	        if(palindrome[i] != 'a') {
	```
	Inside the loop, the function checks if the current character is not 'a'. If it is not 'a', the character will be changed to 'a' to make the string lexicographically smaller.

5. **Character Replacement**
	```cpp
	            palindrome[i] = 'a';
	```
	If the current character is not 'a', it is replaced with 'a', and the function immediately returns the modified string, effectively breaking the palindrome.

6. **Return Modified String**
	```cpp
	            return palindrome;
	```
	The function returns the modified string after making the change to break the palindrome.

7. **Replace Last Character**
	```cpp
	    palindrome[n - 1] = 'b';
	```
	If no non-'a' character was found, the function replaces the last character of the palindrome with 'b' to break the palindrome.

8. **Return Result**
	```cpp
	    return n < 2 ? "" : palindrome;
	```
	If the string length is less than 2, it returns an empty string (as it’s impossible to break a single character palindrome). Otherwise, it returns the modified palindrome.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

In all cases, the algorithm iterates through the string once, which results in a time complexity of O(n), where n is the length of the string.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(1) for the in-place modification of the string, but if a new string is created, it would require O(n) space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/break-a-palindrome/description/)

---
{{< youtube B5v5rDR7c9A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
