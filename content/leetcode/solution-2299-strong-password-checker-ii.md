
+++
authors = ["grid47"]
title = "Leetcode 2299: Strong Password Checker II"
date = "2024-03-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2299: Strong Password Checker II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "0Rn1Lf0mXOI"
youtube_upload_date="2022-06-11"
youtube_thumbnail="https://i.ytimg.com/vi_webp/0Rn1Lf0mXOI/maxresdefault.webp"
comments = true
+++



---
A strong password is defined by the following criteria:
1. It must contain at least 8 characters.
2. It must have at least one lowercase letter.
3. It must have at least one uppercase letter.
4. It must have at least one digit.
5. It must have at least one special character from the set: '!@#$%^&*()-+'.
6. It cannot contain two consecutive identical characters.
Given a string `password`, return `true` if the password satisfies all these conditions. Otherwise, return `false`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `password` containing letters, digits, and special characters from the set: '!@#$%^&*()-+'.
- **Example:** `Input: password = 'Secure123!'`
- **Constraints:**
	- 1 <= password.length <= 100
	- The password consists only of letters, digits, and the special characters '!@#$%^&*()-+'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return `true` if the password is strong according to the conditions outlined. Otherwise, return `false`.
- **Example:** `Output: true`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To verify whether a given password meets all the criteria for being strong.

- Step 1: Check if the password has at least 8 characters.
- Step 2: Verify that the password contains at least one lowercase letter, one uppercase letter, one digit, and one special character from the specified set.
- Step 3: Ensure that no two adjacent characters in the password are the same.
- Step 4: Return `true` if all conditions are met; otherwise, return `false`.
{{< dots >}}
### Problem Assumptions ✅
- The password contains at least one character and does not exceed 100 characters.
- The password includes a mix of letters, digits, and special characters as per the specified set.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: password = 'Password123!'`  \
  **Explanation:** This password meets all the criteria: it has 12 characters, includes lowercase, uppercase, a digit, a special character, and no adjacent identical characters.

- **Input:** `Input: password = '12345abc!'`  \
  **Explanation:** This password fails because it doesn't contain an uppercase letter, though it meets other conditions.

{{< dots >}}
## Approach 🚀
To solve this problem, we can check each condition one by one and return `false` immediately when any condition fails. If we successfully pass all checks, we return `true`.

### Initial Thoughts 💭
- We need to iterate through the password string and check for specific character types, as well as adjacent identical characters.
- The problem can be solved in a single pass through the string with constant time checks for each condition.
{{< dots >}}
### Edge Cases 🌐
- Empty strings are not valid passwords since the length must be at least 1 character.
- The solution should handle passwords of maximum length efficiently (100 characters).
- Passwords that consist of only one type of character (e.g., only digits or only special characters) will fail multiple checks.
- Ensure that all conditions are checked in O(n) time, where n is the length of the password.
{{< dots >}}
## Code 💻
```cpp
bool strongPasswordCheckerII(string p) {
int lo = 0, up = 0, digit = 0, sz = p.size();
for (int i = 0; i < sz; ++i) {
    if (i > 0 && p[i - 1] == p[i])
        return false;
    lo += islower(p[i]) ? 1 : 0;
    up += isupper(p[i]) ? 1 : 0;
    digit += isdigit(p[i]) ? 1 : 0;
}
return sz > 7 && lo && up && digit && (sz - lo - up - digit > 0);
}
```

The function `strongPasswordCheckerII` checks whether a password is strong based on the following criteria: at least one lowercase letter, at least one uppercase letter, at least one digit, and at least 8 characters long. It also ensures that no two consecutive characters are the same.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool strongPasswordCheckerII(string p) {
	```
	The function `strongPasswordCheckerII` is declared, taking a string `p` as the input, which represents the password to check. It returns a boolean value indicating whether the password meets the strength criteria.

2. **Variable Initialization**
	```cpp
	int lo = 0, up = 0, digit = 0, sz = p.size();
	```
	Four variables are initialized: `lo` to count lowercase letters, `up` to count uppercase letters, `digit` to count digits, and `sz` to store the length of the password `p`.

3. **Loop Through Password**
	```cpp
	for (int i = 0; i < sz; ++i) {
	```
	A for-loop is initiated to iterate through each character of the password `p`.

4. **Consecutive Characters Check**
	```cpp
	    if (i > 0 && p[i - 1] == p[i])
	```
	The condition checks if the current character `p[i]` is the same as the previous character `p[i-1]`. If so, the password is invalid and the function returns `false`.

5. **Return False**
	```cpp
	        return false;
	```
	If two consecutive characters are the same, the function immediately returns `false`, indicating the password is not strong.

6. **Lowercase Check**
	```cpp
	    lo += islower(p[i]) ? 1 : 0;
	```
	The `islower` function checks if the current character `p[i]` is a lowercase letter. If true, `lo` is incremented by 1.

7. **Uppercase Check**
	```cpp
	    up += isupper(p[i]) ? 1 : 0;
	```
	The `isupper` function checks if the current character `p[i]` is an uppercase letter. If true, `up` is incremented by 1.

8. **Digit Check**
	```cpp
	    digit += isdigit(p[i]) ? 1 : 0;
	```
	The `isdigit` function checks if the current character `p[i]` is a digit. If true, `digit` is incremented by 1.

9. **Return Password Validity**
	```cpp
	return sz > 7 && lo && up && digit && (sz - lo - up - digit > 0);
	```
	The function returns `true` if the password length is greater than 7, contains at least one lowercase letter, one uppercase letter, one digit, and at least one special character. Otherwise, it returns `false`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the password, since we check each character once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we only use a constant amount of extra space for the flags and previous character tracking.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/strong-password-checker-ii/description/)

---
{{< youtube 0Rn1Lf0mXOI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
