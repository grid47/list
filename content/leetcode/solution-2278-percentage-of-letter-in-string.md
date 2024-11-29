
+++
authors = ["grid47"]
title = "Leetcode 2278: Percentage of Letter in String"
date = "2024-03-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2278: Percentage of Letter in String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "aVeeYs2bSzY"
youtube_upload_date="2022-05-22"
youtube_thumbnail="https://i.ytimg.com/vi_webp/aVeeYs2bSzY/maxresdefault.webp"
comments = true
+++



---
You are given a string `s` and a character `letter`. Your task is to determine the percentage of characters in `s` that are equal to `letter`, rounding down to the nearest whole percent.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string `s` and a character `letter` where `s` consists of lowercase English letters and `letter` is a lowercase English letter.
- **Example:** `Input: s = "hello", letter = "l"`
- **Constraints:**
	- 1 <= s.length <= 100
	- s consists of lowercase English letters.
	- letter is a lowercase English letter.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the percentage of characters in `s` that are equal to `letter`, rounded down to the nearest whole percent.
- **Example:** `Output: 40`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the percentage of occurrences of `letter` in the string `s` and return it as an integer.

- Count how many times `letter` appears in the string `s`.
- Calculate the percentage by dividing the count by the length of the string and multiplying by 100.
- Return the integer part of the percentage.
{{< dots >}}
### Problem Assumptions ✅
- The string `s` is not empty.
- The character `letter` exists within the alphabet.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = "hello", letter = "l"`  \
  **Explanation:** In this case, the letter 'l' appears 2 times out of 5 characters in the string 'hello'. The percentage is 2 / 5 * 100 = 40%, so the output is 40.

- **Input:** `Input: s = "abcabc", letter = "a"`  \
  **Explanation:** The letter 'a' appears 2 times out of 6 characters in the string 'abcabc'. The percentage is 2 / 6 * 100 = 33.33%. When rounded down, the result is 33.

{{< dots >}}
## Approach 🚀
To solve this problem, we will count how many times the letter appears in the string, calculate the percentage, and return the rounded down value.

### Initial Thoughts 💭
- The percentage is calculated by dividing the count of the letter by the length of the string and multiplying by 100.
- Rounding down is equivalent to using integer division in many programming languages.
- The problem is straightforward and involves basic counting and arithmetic operations.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs, as the length of the string is guaranteed to be at least 1.
- The solution should work for strings with a length of up to 100 characters.
- If the letter does not appear in the string, the percentage will be 0.
- The solution must handle up to 100 characters efficiently.
{{< dots >}}
## Code 💻
```cpp
int percentageLetter(string s, char letter) {
    return 100 * count(begin(s), end(s), letter) / s.size();
}
```

This function calculates the percentage of occurrences of a specific letter in the string `s`. It uses the `count` function to find how many times `letter` appears in the string, then divides that by the total length of the string `s` and multiplies by 100 to get the percentage.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int percentageLetter(string s, char letter) {
	```
	This is the function header for `percentageLetter`, which takes a string `s` and a character `letter` as inputs. The function returns an integer representing the percentage of times `letter` appears in the string `s`.

2. **Return Statement**
	```cpp
	    return 100 * count(begin(s), end(s), letter) / s.size();
	```
	The function uses the `count` function to determine how many times `letter` appears in the string `s`. It then multiplies this count by 100 and divides it by the total size of the string `s` to calculate the percentage of the letter's occurrences in the string.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the string `s`, because we need to iterate through the string to count the occurrences of `letter`.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we are using only a few variables to store the result.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/percentage-of-letter-in-string/description/)

---
{{< youtube aVeeYs2bSzY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
