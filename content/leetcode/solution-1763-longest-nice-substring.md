
+++
authors = ["grid47"]
title = "Leetcode 1763: Longest Nice Substring"
date = "2024-05-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1763: Longest Nice Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Divide and Conquer","Bit Manipulation","Sliding Window"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "6WvZrynlCdk"
youtube_upload_date="2021-02-20"
youtube_thumbnail="https://i.ytimg.com/vi/6WvZrynlCdk/maxresdefault.jpg"
comments = true
+++



---
A string is considered nice if every letter that appears in the string appears both in uppercase and lowercase. For example, 'aA' and 'bB' are nice strings, but 'a' and 'B' are not. Given a string s, find the longest nice substring of s. If there are multiple longest nice substrings, return the one that appears first. If no nice substring exists, return an empty string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a string s consisting of uppercase and lowercase English letters.
- **Example:** `Input: s = 'aAAbB'`
- **Constraints:**
	- 1 <= s.length <= 100
	- s consists of uppercase and lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the longest nice substring. If no such substring exists, return an empty string.
- **Example:** `Output: 'aA'`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the longest substring where every letter appears in both its lowercase and uppercase form.

- 1. Iterate through all possible substrings of the given string s.
- 2. For each substring, check if it contains every letter in both uppercase and lowercase.
- 3. Keep track of the longest valid substring found during the iteration.
{{< dots >}}
### Problem Assumptions ✅
- The string contains only alphabetic characters (both uppercase and lowercase).
- There are no special characters or spaces in the string.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = 'YazaAay'`  \
  **Explanation:** The substring 'aAa' is a nice string because both 'A' and 'a' appear. 'aAa' is the longest nice substring.

- **Input:** `Input: s = 'Bb'`  \
  **Explanation:** The entire string 'Bb' is a nice string because both 'B' and 'b' appear.

- **Input:** `Input: s = 'c'`  \
  **Explanation:** There are no nice substrings because 'c' does not have a corresponding uppercase letter.

{{< dots >}}
## Approach 🚀
We can solve the problem by using recursion to check for all substrings, and for each substring, verify if it is nice.

### Initial Thoughts 💭
- A string is nice if it contains all letters in both their uppercase and lowercase forms.
- We need to explore all possible substrings to find the longest nice substring.
- We can approach this by checking each possible substring, but optimize by eliminating invalid substrings early.
{{< dots >}}
### Edge Cases 🌐
- If the input string is empty, return an empty string.
- For larger inputs, the solution should efficiently process the string to find the longest nice substring.
- If the string contains only one type of letter (like 'a' or 'A'), no nice substring will exist.
- The solution should efficiently handle strings with a maximum length of 100.
{{< dots >}}
## Code 💻
```cpp
string longestNiceSubstring(string s, int start = 0, int end = -1) {
    if (end == -1)
        end = s.size();
    int cnt[26][2] = {}, j = start - 1;
    for (auto i = start; i < end; ++i)
        cnt[tolower(s[i]) - 'a'][(bool)islower(s[i])] = 1;
    string res;
    for (auto i = start; i <= end; ++i) {
        int ch = i == end ? -1 : tolower(s[i]) - 'a';
        if (ch == -1 || cnt[ch][0] + cnt[ch][1] == 1) {
            if (j == -1 && ch == -1)
                return s;
            auto res1 = longestNiceSubstring(s.substr(j + 1, i - j - 1));
            if (res1.size() > res.size())
                res = res1;
            j = i;
        }
    }
    return res;
}
```

This function finds the longest substring of a string `s` such that every character in the substring has both its uppercase and lowercase form present. It uses recursion and character tracking for efficient processing.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string longestNiceSubstring(string s, int start = 0, int end = -1) {
	```
	Declares the function that finds the longest nice substring of a given string.

2. **Condition Check**
	```cpp
	    if (end == -1)
	```
	Checks if the end index is unset and initializes it to the string size.

3. **Initialization**
	```cpp
	        end = s.size();
	```
	Sets the end of the substring to the size of the input string if not provided.

4. **Array Initialization**
	```cpp
	    int cnt[26][2] = {}, j = start - 1;
	```
	Initializes a 2D array to track lowercase and uppercase occurrences of characters and a pointer `j` for substring processing.

5. **For Loop**
	```cpp
	    for (auto i = start; i < end; ++i)
	```
	Iterates over the string to populate the character tracking array.

6. **Tracking**
	```cpp
	        cnt[tolower(s[i]) - 'a'][(bool)islower(s[i])] = 1;
	```
	Marks the presence of lowercase or uppercase forms of the current character in the tracking array.

7. **Variable Initialization**
	```cpp
	    string res;
	```
	Initializes an empty string `res` to store the result substring.

8. **For Loop**
	```cpp
	    for (auto i = start; i <= end; ++i) {
	```
	Iterates through the string to identify and process substrings.

9. **Condition Check**
	```cpp
	        int ch = i == end ? -1 : tolower(s[i]) - 'a';
	```
	Gets the character index or sets a sentinel value when the end of the string is reached.

10. **Condition Check**
	```cpp
	        if (ch == -1 || cnt[ch][0] + cnt[ch][1] == 1) {
	```
	Identifies substrings that are not nice due to missing uppercase or lowercase forms.

11. **Edge Case**
	```cpp
	            if (j == -1 && ch == -1)
	```
	Handles the edge case where the entire string is a nice substring.

12. **Return Statement**
	```cpp
	                return s;
	```
	Returns the string if it is a nice substring.

13. **Recursive Call**
	```cpp
	            auto res1 = longestNiceSubstring(s.substr(j + 1, i - j - 1));
	```
	Recursively processes substrings to find the longest nice substring.

14. **Comparison**
	```cpp
	            if (res1.size() > res.size())
	```
	Checks if the current result is longer than the previous best result.

15. **Update Result**
	```cpp
	                res = res1;
	```
	Updates the result with the longer substring.

16. **Pointer Update**
	```cpp
	            j = i;
	```
	Moves the pointer `j` to the current index for the next substring.

17. **Return Statement**
	```cpp
	    return res;
	```
	Returns the longest nice substring found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^3)

The time complexity is driven by the recursive checking of substrings and the verification process for each substring, resulting in O(n^3) in the worst case.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) in the worst case due to the recursion stack and storing the substrings.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-nice-substring/description/)

---
{{< youtube 6WvZrynlCdk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
