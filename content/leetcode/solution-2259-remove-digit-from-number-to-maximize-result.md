
+++
authors = ["grid47"]
title = "Leetcode 2259: Remove Digit From Number to Maximize Result"
date = "2024-03-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2259: Remove Digit From Number to Maximize Result in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "cinEIxOL0E8"
youtube_upload_date="2022-05-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/cinEIxOL0E8/maxresdefault.webp"
comments = true
+++



---
You are given a string `number` representing a positive integer and a character `digit`. Your task is to remove exactly one occurrence of `digit` from the string `number` such that the resulting number, when interpreted as an integer, is maximized. The test cases are guaranteed to have at least one occurrence of `digit` in the string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `number`, representing a positive integer, and a character `digit`, which is a digit to be removed from the string.
- **Example:** `number = '4598', digit = '5'`
- **Constraints:**
	- 2 <= number.length <= 100
	- number consists of digits from '1' to '9'.
	- digit is a digit from '1' to '9'.
	- digit occurs at least once in number.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the resulting string after removing one occurrence of `digit` such that the value of the resulting string, when interpreted as an integer, is maximized.
- **Example:** `Output: '498'`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to remove one occurrence of the specified `digit` to maximize the integer value of the resulting string.

- Loop through the string to find the first occurrence of `digit` that, when removed, results in a larger number. This can be identified by checking the next character to see if it is larger than `digit`.
- If no such occurrence is found, remove the last occurrence of `digit` to ensure the maximum possible number.
{{< dots >}}
### Problem Assumptions ✅
- The string `number` will contain only digits from '1' to '9', and no leading zeros are allowed.
{{< dots >}}
## Examples 🧩
- **Input:** `number = '4598', digit = '5'`  \
  **Explanation:** After removing the '5' from the string '4598', the result is '498', which is the largest possible integer formed from the remaining digits.

- **Input:** `number = '9871', digit = '1'`  \
  **Explanation:** We can remove the '1' from '9871' to get '987', which is the maximum possible result.

{{< dots >}}
## Approach 🚀
The problem can be approached by iterating over the string to find the optimal digit to remove, ensuring that we maximize the remaining number.

### Initial Thoughts 💭
- We can remove any occurrence of `digit` but should focus on removing the first occurrence that leads to a larger number.
- We should aim to remove the first `digit` whose next character is greater than `digit`. If no such character exists, remove the last occurrence of `digit`.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs as the string is guaranteed to have a length of at least 2.
- The solution should be efficient enough to handle strings with a length of up to 100 characters.
- Ensure that leading zeros are not generated after removing a digit.
- The string length is manageable, and the removal operation should be performed optimally to achieve the best possible result.
{{< dots >}}
## Code 💻
```cpp
string removeDigit(string n, char digit) {
    for (int i = 0; i < n.size() - 1; ++i)
        if (n[i] == digit && n[i + 1] > digit)
            return n.substr(0, i) + n.substr(i + 1);
    int last_d = n.rfind(digit);
    return n.substr(0, last_d) + n.substr(last_d + 1);
}
```

This function removes the first occurrence of a digit from the string `n` such that the remaining digits form the largest possible number. If no such digit exists, it removes the last occurrence of the digit.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string removeDigit(string n, char digit) {
	```
	This is the function signature. The function takes a string `n` and a character `digit` as input and returns a string with one occurrence of `digit` removed.

2. **For Loop Initialization**
	```cpp
	    for (int i = 0; i < n.size() - 1; ++i)
	```
	This loop iterates over the string `n` from the first character to the second last character, checking for the specified `digit`.

3. **Condition Check**
	```cpp
	        if (n[i] == digit && n[i + 1] > digit)
	```
	This condition checks if the current character is the `digit` and if the next character is greater than `digit`. If so, it identifies that this is the optimal place to remove the digit.

4. **Remove Digit**
	```cpp
	            return n.substr(0, i) + n.substr(i + 1);
	```
	If the condition is satisfied, the function removes the `digit` at index `i` and returns the modified string by concatenating the part before and after the digit.

5. **Find Last Occurrence**
	```cpp
	    int last_d = n.rfind(digit);
	```
	If no optimal digit is found in the loop, the function searches for the last occurrence of `digit` in the string using `rfind`.

6. **Remove Last Digit**
	```cpp
	    return n.substr(0, last_d) + n.substr(last_d + 1);
	```
	If no removal occurred in the loop, the function removes the last occurrence of the `digit` by using `substr` to exclude it from the string.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear because we iterate through the string to find the optimal position for removal and perform a string slicing operation.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is linear due to the need to store the modified string.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/description/)

---
{{< youtube cinEIxOL0E8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
