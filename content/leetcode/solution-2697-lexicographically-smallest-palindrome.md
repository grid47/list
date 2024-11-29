
+++
authors = ["grid47"]
title = "Leetcode 2697: Lexicographically Smallest Palindrome"
date = "2024-02-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2697: Lexicographically Smallest Palindrome in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "EzAjKrEQLFs"
youtube_upload_date="2023-05-21"
youtube_thumbnail="https://i.ytimg.com/vi_webp/EzAjKrEQLFs/maxresdefault.webp"
comments = true
+++



---
You are given a string `s` consisting of lowercase English letters. You can perform operations on this string where in each operation, you replace a character in `s` with another lowercase English letter. The goal is to make `s` a palindrome using the minimum number of operations possible. If there are multiple ways to achieve the same minimum number of operations, return the lexicographically smallest palindrome string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string `s` consisting only of lowercase English letters.
- **Example:** `Input: s = 'hckvh'`
- **Constraints:**
	- 1 <= s.length <= 1000
	- s consists only of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the lexicographically smallest palindrome that can be obtained using the minimum number of operations.
- **Example:** `Output: 'hvchv'`
- **Constraints:**
	- The output should be a palindrome string with the minimum number of character replacements.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to modify the string to be a palindrome with the fewest changes, while ensuring the result is lexicographically smallest.

- Step 1: Initialize two pointers, one at the start (i) and one at the end (j) of the string.
- Step 2: Compare the characters at positions i and j. If they are different, replace the character at the higher lexicographical position with the one at the lower position.
- Step 3: Move the pointers inward and repeat until i >= j.
- Step 4: Return the modified string as the result.
{{< dots >}}
### Problem Assumptions ✅
- The string contains only lowercase English letters.
- The string has a length between 1 and 1000, so the solution should be efficient.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = 'hckvh'`  \
  **Explanation:** The string is 'hckvh'. By replacing 'k' with 'v' and 'c' with 'h', the resulting palindrome is 'hvchv', which is lexicographically smaller than any other palindrome obtained with 2 operations.

- **Input:** `Input: s = 'abcda'`  \
  **Explanation:** The string is 'abcda'. Replacing 'b' with 'a' and 'd' with 'a' results in the palindrome 'abcba', which is the smallest lexicographically possible palindrome with the minimum number of operations.

{{< dots >}}
## Approach 🚀
The approach to solving the problem involves iterating through the string and ensuring that for each character pair (i, n-i-1), the smaller character is chosen to form a palindrome. This minimizes the number of operations and ensures lexicographical order.

### Initial Thoughts 💭
- The problem is straightforward if we consider each pair of characters from the start and end of the string.
- For each character pair, we only need to make one change if they differ, and we aim for the lexicographically smaller character.
- We can solve this problem efficiently in O(n) time by scanning the string from both ends.
{{< dots >}}
### Edge Cases 🌐
- Empty string is not possible based on constraints but if it were, the output would be an empty string.
- For strings close to the upper limit of length 1000, ensure the solution is efficient and handles the maximum input size within time limits.
- If the string is already a palindrome, the output will be the string itself without any modifications.
- The string length is guaranteed to be between 1 and 1000.
{{< dots >}}
## Code 💻
```cpp
string makeSmallestPalindrome(string s) {
    int n = s.size();
    int i = 0, j = n - 1;
    
    while(i < j) {
        char tmp = min(s[i], s[j]);
        s[i] = s[j] = tmp;
        i++;
        j--;
    }
    return s;
}
```

The function `makeSmallestPalindrome` takes a string `s` and returns the lexicographically smallest palindrome that can be formed by modifying the string.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string makeSmallestPalindrome(string s) {
	```
	This line defines the function `makeSmallestPalindrome`, which takes a string `s` as input and returns a new string that is the lexicographically smallest palindrome possible.

2. **String Size Calculation**
	```cpp
	    int n = s.size();
	```
	The variable `n` stores the length of the string `s`.

3. **Pointer Initialization**
	```cpp
	    int i = 0, j = n - 1;
	```
	Two pointers `i` and `j` are initialized to the start and end of the string, respectively.

4. **While Loop**
	```cpp
	    while(i < j) {
	```
	A while loop is started, which continues as long as the pointers `i` and `j` do not cross each other.

5. **Minimum Character Selection**
	```cpp
	        char tmp = min(s[i], s[j]);
	```
	The variable `tmp` is assigned the lexicographically smaller of the two characters at positions `i` and `j`.

6. **Character Replacement**
	```cpp
	        s[i] = s[j] = tmp;
	```
	The characters at positions `i` and `j` are replaced with the smaller character `tmp` to form the palindrome.

7. **Pointer Update**
	```cpp
	        i++;
	```
	Pointer `i` is incremented to move towards the middle of the string.

8. **Pointer Update**
	```cpp
	        j--;
	```
	Pointer `j` is decremented to move towards the middle of the string.

9. **Return Statement**
	```cpp
	    return s;
	```
	The modified string `s`, which is now the smallest lexicographically palindrome, is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) since we only need to iterate through the string once, comparing and possibly modifying each character pair.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we are modifying the string in-place, and the space required for the input string is proportional to its length.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/lexicographically-smallest-palindrome/description/)

---
{{< youtube EzAjKrEQLFs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
