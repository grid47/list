
+++
authors = ["grid47"]
title = "Leetcode 481: Magical String"
date = "2024-09-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 481: Magical String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/481.webp"
youtube = "-iFDu2kaCpY"
youtube_upload_date="2024-02-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/-iFDu2kaCpY/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/481.webp" 
    alt="A sequence where the magical string gradually forms, with each step softly glowing as the pattern emerges."
    caption="Solution to LeetCode 481: Magical String Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
A magical string consists of only '1' and '2' and follows a special rule: the number of consecutive occurrences of characters '1' and '2' generates the string itself. Given an integer `n`, return the number of '1's in the first `n` characters of the magical string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer `n`, the length of the desired substring of the magical string.
- **Example:** `n = 7`
- **Constraints:**
	- 1 <= n <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of '1's in the first `n` characters of the magical string.
- **Example:** `Output: 4`
- **Constraints:**
	- The result will be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Generate the magical string up to `n` characters and count the number of '1's.

- 1. Start with the base string '122'.
- 2. Generate the magical string by adding segments based on the number of previous occurrences.
- 3. For each segment, append the opposite digit (either '1' or '2') based on the previous occurrence.
- 4. Once the string is generated up to `n` characters, count the number of '1's in the substring.
{{< dots >}}
### Problem Assumptions ✅
- The value of `n` will always be within the given range.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 7`  \
  **Explanation:** The first 7 characters of the magical string are '1221121'. This string has four '1's, so the output is 4.

- **Input:** `n = 3`  \
  **Explanation:** The first 3 characters of the magical string are '122'. This string has two '1's, so the output is 2.

{{< dots >}}
## Approach 🚀
The approach involves constructing the magical string by iterating through the number of occurrences of '1' and '2' and generating the corresponding sequence.

### Initial Thoughts 💭
- We can generate the magical string by appending based on the previous occurrences of '1' and '2'.
- The string grows gradually, so we can stop once we have the first `n` elements.
- We need to efficiently construct the magical string and keep track of the occurrences of '1's.
{{< dots >}}
### Edge Cases 🌐
- The input will always have at least 1 element (n >= 1).
- For large values of `n`, the algorithm should handle constructing the string efficiently up to 10^5 characters.
- When `n = 1`, the string is just '1', so the output will be 1.
- The solution should be able to handle up to 10^5 elements in the magical string.
{{< dots >}}
## Code 💻
```cpp
int magicalString(int n) {
    string s = "122";
    int i = 2;
    while(s.size() < n)
    s += string(s[i++] - '0', s.back() ^ 3);
    return count(s.begin(), s.begin() + n, '1');
}
```

The `magicalString` function generates a magical string where each new number is derived by inverting the last number of the string, and it repeats based on the value of the preceding element. The function counts the number of '1's in the string up to the `n`th position.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int magicalString(int n) {
	```
	Defines the `magicalString` function, which generates a magical string up to the `n`th character and counts the number of '1's.

2. **String Initialization**
	```cpp
	    string s = "122";
	```
	Initializes the string `s` with the value "122". This is the base case for the magical string.

3. **Variable Initialization**
	```cpp
	    int i = 2;
	```
	Initializes the variable `i` to 2. This will be used to track the current index in the string while constructing new elements.

4. **Loop**
	```cpp
	    while(s.size() < n)
	```
	Starts a `while` loop that continues to run until the size of the string `s` reaches or exceeds the given number `n`.

5. **String Manipulation**
	```cpp
	    s += string(s[i++] - '0', s.back() ^ 3);
	```
	Appends new characters to the string `s`. The number of new characters is determined by the value of the current character at index `i`. The new characters are the inverse of the last character in the string.

6. **Return Statement**
	```cpp
	    return count(s.begin(), s.begin() + n, '1');
	```
	Returns the count of '1's in the string `s` from the beginning up to the `n`th position.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we generate the magical string up to `n` characters and count the number of '1's in the first `n` elements.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we store the magical string up to `n` characters.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/magical-string/description/)

---
{{< youtube -iFDu2kaCpY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
