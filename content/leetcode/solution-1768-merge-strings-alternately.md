
+++
authors = ["grid47"]
title = "Leetcode 1768: Merge Strings Alternately"
date = "2024-05-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1768: Merge Strings Alternately in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "oFuFTMu2Tgg"
youtube_upload_date="2023-04-18"
youtube_thumbnail="https://i.ytimg.com/vi/oFuFTMu2Tgg/maxresdefault.jpg"
comments = true
+++



---
You are given two strings `word1` and `word2`. Merge the two strings by alternating their letters, starting with the first letter of `word1`. If one string is longer, append the remaining characters of the longer string to the end of the merged string. Return the resulting merged string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two strings `word1` and `word2`, both containing lowercase English letters.
- **Example:** `word1 = 'cat', word2 = 'dog'`
- **Constraints:**
	- 1 <= word1.length, word2.length <= 100
	- word1 and word2 consist of lowercase English letters

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the merged string where the characters from `word1` and `word2` alternate. If one string is longer than the other, append the remaining characters from the longer string.
- **Example:** `Output: 'cadtog'`
- **Constraints:**
	- The merged string must respect the alternating character pattern.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to merge two strings by alternating their characters, starting with the first character of `word1`, and append any remaining characters from the longer string at the end.

- Initialize two pointers, one for each string.
- Alternate between adding characters from `word1` and `word2` to the result string.
- After one string is exhausted, append the remaining characters from the longer string.
{{< dots >}}
### Problem Assumptions ✅
- Both `word1` and `word2` are non-empty strings.
{{< dots >}}
## Examples 🧩
- **Input:** `word1 = 'cat', word2 = 'dog'`  \
  **Explanation:** The strings have the same length, so the merged string alternates the characters from both strings: 'c', 'a', 't', 'd', 'o', 'g'.

- **Input:** `word1 = 'hello', word2 = 'worlds'`  \
  **Explanation:** Here, `word2` is longer, so after alternating characters, the remaining 's' from `word2` is appended to the end of the merged string.

{{< dots >}}
## Approach 🚀
The problem can be solved by alternating between the characters of both strings while keeping track of the current position in each string. Once one string is exhausted, we append the remaining characters from the other string.

### Initial Thoughts 💭
- We need to alternate characters from both strings while ensuring that we handle cases where the strings have different lengths.
- By using two pointers (one for each string), we can easily alternate characters from both strings.
{{< dots >}}
### Edge Cases 🌐
- The input strings will not be empty, as per the problem constraints.
- The solution should work efficiently for strings of length up to 100.
- If both strings are of equal length, the merged string should alternate characters from both strings evenly.
- The strings will always contain lowercase English letters and will be at least 1 character long.
{{< dots >}}
## Code 💻
```cpp
string mergeAlternately(string w1, string w2) {
    string res = "";
    int i = 0, j = 0;
    while(i < w1.size() || j < w2.size()) {
        if(i < w1.size()) {
            res += w1[i];
            i++;
        }
        if(j < w2.size()) {
            res += w2[j];
            j++;
        }
    }
    return res;
}
```

This function alternates between two strings, `w1` and `w2`, merging them together character by character. It handles different string lengths gracefully by continuing to append characters from the longer string after the shorter one is fully traversed.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string mergeAlternately(string w1, string w2) {
	```
	The function `mergeAlternately` is defined, which takes two strings, `w1` and `w2`, as input and will return the merged result.

2. **Variable Initialization**
	```cpp
	    string res = "";
	```
	A string variable `res` is initialized to store the merged result of the two strings.

3. **Variable Initialization**
	```cpp
	    int i = 0, j = 0;
	```
	Two integer variables `i` and `j` are initialized to keep track of the current index in strings `w1` and `w2`, respectively.

4. **Loop Initialization**
	```cpp
	    while(i < w1.size() || j < w2.size()) {
	```
	A while loop begins, running until both strings have been fully traversed. It continues as long as there are characters left in either `w1` or `w2`.

5. **Conditional Check**
	```cpp
	        if(i < w1.size()) {
	```
	This condition checks if there are remaining characters in string `w1` (i.e., `i` is less than the size of `w1`).

6. **String Manipulation**
	```cpp
	            res += w1[i];
	```
	If there are characters remaining in `w1`, the next character (`w1[i]`) is appended to `res`.

7. **Variable Update**
	```cpp
	            i++;
	```
	The index `i` is incremented to move to the next character in `w1`.

8. **Conditional Check**
	```cpp
	        if(j < w2.size()) {
	```
	This condition checks if there are remaining characters in string `w2` (i.e., `j` is less than the size of `w2`).

9. **String Manipulation**
	```cpp
	            res += w2[j];
	```
	If there are characters remaining in `w2`, the next character (`w2[j]`) is appended to `res`.

10. **Variable Update**
	```cpp
	            j++;
	```
	The index `j` is incremented to move to the next character in `w2`.

11. **Return Statement**
	```cpp
	    return res;
	```
	Return the merged string `res` as the result of the function.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution iterates through each character of both strings once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We use additional space for the result string, which can have a length equal to the sum of the lengths of both input strings.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/merge-strings-alternately/description/)

---
{{< youtube oFuFTMu2Tgg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
