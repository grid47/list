
+++
authors = ["grid47"]
title = "Leetcode 1805: Number of Different Integers in a String"
date = "2024-05-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1805: Number of Different Integers in a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "1vZ2c92YgOc"
youtube_upload_date="2021-03-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/1vZ2c92YgOc/maxresdefault.webp"
comments = true
+++



---
You are given a string `word` consisting of digits and lowercase English letters. Replace every non-digit character with a space and count how many distinct integers are formed after the replacement.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single string `word` that contains both digits and lowercase letters.
- **Example:** `word = 'a456b789c456'`
- **Constraints:**
	- 1 <= word.length <= 1000
	- word consists of digits and lowercase English letters

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of distinct integers after performing the replacement operations on `word`.
- **Example:** `Output: 2`
- **Constraints:**
	- The integers are compared based on their value, ignoring leading zeros.

{{< dots >}}
### Core Logic 🔍
**Goal:** To count how many distinct integers can be formed after replacing non-digit characters with spaces.

- Replace every non-digit character in `word` with a space.
- Extract all sequences of digits from the string.
- Remove any leading zeros from each sequence and count distinct values.
{{< dots >}}
### Problem Assumptions ✅
- The string `word` will always contain at least one character.
{{< dots >}}
## Examples 🧩
- **Input:** `word = 'a456b789c456'`  \
  **Explanation:** After replacing non-digit characters, the string becomes ' 456 789  456'. There are two distinct integers: '456' and '789'.

{{< dots >}}
## Approach 🚀
The approach uses string manipulation to replace non-digit characters and count distinct integers by removing leading zeros.

### Initial Thoughts 💭
- We need to replace non-digit characters and ensure leading zeros do not affect the comparison of integers.
- Using a set to store the distinct integers (after removing leading zeros) ensures we only count unique integers.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one character in the input string.
- For large input strings, ensure that the solution is efficient, as the length of `word` can be up to 1000.
- Consider cases where the string contains many consecutive non-digit characters, or where all characters are digits.
- The solution should handle up to 1000 characters and large inputs efficiently.
{{< dots >}}
## Code 💻
```cpp
int numDifferentIntegers(string w) {
    unordered_set<string> s{""};    
    for (int i = 0, j = 0; j <= w.size(); ++j) {
        if (j < w.size() && isdigit(w[j]))
            i += i < j && w[i] == '0';
        else {
            s.insert(w.substr(i, j - i));
            i = j + 1;
        }
    }
    return s.size() - 1;
}
```

The function `numDifferentIntegers` extracts unique integer strings from a given string `w`, ensuring leading zeros are discarded, and returns the number of distinct integers.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int numDifferentIntegers(string w) {
	```
	Define the function `numDifferentIntegers` which takes a string `w` as input and returns an integer representing the number of distinct integer values.

2. **Variable Initialization**
	```cpp
	    unordered_set<string> s{""};
	```
	Initialize an unordered set `s` to store unique integer substrings found in the input string `w`.

3. **Loop and Recursion**
	```cpp
	    for (int i = 0, j = 0; j <= w.size(); ++j) {
	```
	Start a loop with two variables `i` and `j`, where `i` tracks the start of a number, and `j` iterates over each character in the string `w`.

4. **Conditionals**
	```cpp
	        if (j < w.size() && isdigit(w[j]))
	```
	Check if the character at position `j` is a digit and if `j` is within the bounds of the string.

5. **Mathematical Operations**
	```cpp
	            i += i < j && w[i] == '0';
	```
	If a leading zero is encountered at position `i`, adjust `i` to skip over it and start from the next digit.

6. **Flow Control**
	```cpp
	        else {
	```
	If the current character is not a digit, proceed with the following actions.

7. **Set Insertion**
	```cpp
	            s.insert(w.substr(i, j - i));
	```
	Insert the substring of `w` from index `i` to `j` into the set `s`, which ensures only unique numbers are stored.

8. **Variable Initialization**
	```cpp
	            i = j + 1;
	```
	Update `i` to the next index after `j` to start searching for the next potential number.

9. **Return**
	```cpp
	    return s.size() - 1;
	```
	Return the size of the set `s` (number of unique integer substrings) minus one to exclude the empty string.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where n is the length of the input string, as we perform a single pass over the string and extract distinct integers.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) to store the integers in the set.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-different-integers-in-a-string/description/)

---
{{< youtube 1vZ2c92YgOc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
