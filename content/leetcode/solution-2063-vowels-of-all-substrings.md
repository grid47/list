
+++
authors = ["grid47"]
title = "Leetcode 2063: Vowels of All Substrings"
date = "2024-04-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2063: Vowels of All Substrings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Dynamic Programming","Combinatorics"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "yVDIm1IfG2c"
youtube_upload_date="2021-11-07"
youtube_thumbnail="https://i.ytimg.com/vi_webp/yVDIm1IfG2c/maxresdefault.webp"
comments = true
+++



---
You are given a string word consisting of lowercase English letters. Your task is to return the total sum of the number of vowels ('a', 'e', 'i', 'o', and 'u') present in every possible substring of word. A substring is any contiguous sequence of characters in the word.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given the following input:
- **Example:** `Input: word = "abcabc"`
- **Constraints:**
	- 1 <= word.length <= 10^5
	- word consists of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a single integer representing the sum of vowels in every substring of the given string word.
- **Example:** `Output: 9`
- **Constraints:**
	- The result may be a large integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the sum of vowels in all substrings of the string word efficiently, considering that the string may be very large.

- 1. Iterate through each character of the string.
- 2. For each vowel encountered, calculate how many substrings it is part of.
- 3. Add the contribution of each vowel to the total sum.
- 4. Return the result.
{{< dots >}}
### Problem Assumptions ✅
- The word consists of lowercase English letters.
- The length of the word is at least 1.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: word = "aba"`  \
  **Explanation:** The possible substrings are: 'a', 'ab', 'aba', 'b', 'ba', 'a'. The vowels are found in substrings 'a', 'ab', 'ba', 'a', 'aba', and contribute 6 vowels in total.

- **Input:** `Input: word = "abc"`  \
  **Explanation:** The possible substrings are: 'a', 'ab', 'abc', 'b', 'bc', and 'c'. Only 'a', 'ab', and 'abc' contain vowels, contributing 3 vowels in total.

- **Input:** `Input: word = "ltcd"`  \
  **Explanation:** There are no vowels in the string 'ltcd', so the total sum of vowels is 0.

{{< dots >}}
## Approach 🚀
The problem can be solved efficiently by calculating the contribution of each vowel to all substrings it appears in. The key observation is that a vowel at position i contributes to all substrings starting from indices 0 to i and ending from i to the end of the string.

### Initial Thoughts 💭
- Each vowel appears in multiple substrings, and the number of such substrings can be calculated directly.
- A brute force approach of generating all substrings would be too slow for large strings.
- The efficient approach avoids generating substrings and directly computes the contribution of each vowel in the string.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs since the length of the string is guaranteed to be at least 1.
- For large inputs (strings up to length 10^5), ensure the algorithm runs in linear time.
- If the word contains no vowels, the result should be 0.
- Ensure the solution handles edge cases such as very short or very long strings efficiently.
{{< dots >}}
## Code 💻
```cpp
long long countVowels(string word) {
    long long res = 0, n = word.size();
    for(int i = 0; i < n; i++)
    if(string("aeiou").find(word[i]) != string::npos)
    res += (i + 1) * (n - i);
    return res;
}
```

This function calculates the number of substrings containing vowels in a given string 'word' by iterating through each character and checking if it is a vowel. It accumulates the count based on the position of vowels within the string.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	long long countVowels(string word) {
	```
	Define the function 'countVowels' which takes a string 'word' as input and returns the total count of substrings containing vowels.

2. **Variable Initialization**
	```cpp
	    long long res = 0, n = word.size();
	```
	Initialize 'res' to 0, which will hold the result, and 'n' to the length of the input string 'word'.

3. **Looping**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Start a loop that iterates over each character in the string 'word'.

4. **Conditional Logic**
	```cpp
	    if(string("aeiou").find(word[i]) != string::npos)
	```
	Check if the current character 'word[i]' is a vowel by looking for it in the string 'aeiou'. If found, the character is a vowel.

5. **Mathematical Operation**
	```cpp
	    res += (i + 1) * (n - i);
	```
	If the character is a vowel, add to 'res' the product of the number of possible substrings starting with the current vowel position.

6. **Return Statement**
	```cpp
	    return res;
	```
	Return the accumulated result 'res' which contains the total count of substrings with vowels.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the word, because we only need to iterate through the string once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1), as the solution only requires a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/vowels-of-all-substrings/description/)

---
{{< youtube yVDIm1IfG2c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
