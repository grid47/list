
+++
authors = ["grid47"]
title = "Leetcode 467: Unique Substrings in Wraparound String"
date = "2024-09-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 467: Unique Substrings in Wraparound String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/467.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/467.webp" 
    alt="A glowing string where unique substrings wrap around and light up as they form distinct patterns."
    caption="Solution to LeetCode 467: Unique Substrings in Wraparound String Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a string `s`, return the number of unique non-empty substrings of `s` that are present in the infinite wraparound string 'abcdefghijklmnopqrstuvwxyz'.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `s`.
- **Example:** `s = 'c'`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- s consists of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of unique substrings of `s` that are found in the infinite wraparound string.
- **Example:** `Output: 1`
- **Constraints:**
	- The output should be an integer representing the count of unique substrings in the wraparound base string.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find all unique substrings of `s` and check if they exist in the infinite wraparound string.

- 1. Traverse the string `s` and find substrings that are contiguous in the wraparound base string.
- 2. Track the maximum length of continuous substrings from `s` that can be matched to substrings in the base string.
- 3. Count the number of unique substrings by leveraging the tracked maximum lengths.
{{< dots >}}
### Problem Assumptions ✅
- The input string `s` is non-empty and contains only lowercase letters.
{{< dots >}}
## Examples 🧩
- **Input:** `s = 'c'`  \
  **Explanation:** The substring 'c' is present in the infinite base string.

- **Input:** `s = 'db'`  \
  **Explanation:** The substrings 'd' and 'b' are both present in the infinite base string.

- **Input:** `s = 'zab'`  \
  **Explanation:** The substrings 'z', 'a', 'b', 'za', 'ab', and 'zab' are all present in the infinite base string.

{{< dots >}}
## Approach 🚀
We solve the problem by finding the substrings of `s` that can be matched in the infinite wraparound string.

### Initial Thoughts 💭
- The problem involves identifying substrings that are continuous in the base string, which requires recognizing circular sequences.
- A key observation is that substrings can be tracked by looking at the maximum length of valid sequences from `s` that match the base string.
{{< dots >}}
### Edge Cases 🌐
- An empty string is not allowed as per the constraints.
- Ensure the solution handles large inputs efficiently, with lengths up to 10^5.
- Consider cases where the string contains repeating characters or sequences, such as 'aaaa'.
- The solution must run in linear time to handle large inputs.
{{< dots >}}
## Code 💻
```cpp
int findSubstringInWraproundString(string p) {
    vector<int> len(26, 0);
    int cur = 1;
    len[p[0] - 'a'] = 1;
    for(int i = 1; i < p.size(); i++) {
        if((p[i] + 26 - p[i - 1]) % 26 == 1) cur++;
        else cur = 1;
        len[p[i] - 'a'] = max(len[p[i] - 'a'], cur);
    }
    return accumulate(len.begin(), len.end(), 0);
}
```

The function `findSubstringInWraproundString` calculates the total number of unique substrings in a circular alphabet string. It tracks the length of substrings that follow a continuous sequence of characters in the alphabet, considering wraparound behavior (i.e., after 'z' comes 'a').

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findSubstringInWraproundString(string p) {
	```
	Defines the function `findSubstringInWraproundString` that takes a string `p` and returns the total count of unique substrings that can be formed in a wraparound string.

2. **Vector Initialization**
	```cpp
	    vector<int> len(26, 0);
	```
	Initializes a vector `len` of size 26 to store the maximum length of substrings ending with each letter of the alphabet, initialized to 0.

3. **Variable Initialization**
	```cpp
	    int cur = 1;
	```
	Initializes the variable `cur` to 1, which keeps track of the current length of the ongoing sequence of consecutive characters in the alphabet.

4. **First Character Handling**
	```cpp
	    len[p[0] - 'a'] = 1;
	```
	Sets the length of the substring ending with the first character of `p` (indexed by `p[0] - 'a'`) to 1, as it forms a single-character substring.

5. **Loop Start**
	```cpp
	    for(int i = 1; i < p.size(); i++) {
	```
	Begins a loop to iterate through the string `p`, starting from the second character, to check for continuous character sequences.

6. **Sequence Check**
	```cpp
	        if((p[i] + 26 - p[i - 1]) % 26 == 1) cur++;
	```
	Checks if the current character `p[i]` and the previous character `p[i-1]` are consecutive in the alphabet, considering wraparound behavior. If they are consecutive, it increments `cur`.

7. **Sequence Reset**
	```cpp
	        else cur = 1;
	```
	If the current character is not consecutive to the previous one, it resets `cur` to 1, starting a new sequence.

8. **Update Lengths**
	```cpp
	        len[p[i] - 'a'] = max(len[p[i] - 'a'], cur);
	```
	Updates the maximum length of the substring ending with the character `p[i]` by comparing the current value in `len` and the ongoing sequence length `cur`.

9. **Final Calculation**
	```cpp
	    return accumulate(len.begin(), len.end(), 0);
	```
	Calculates the sum of all the maximum lengths of substrings ending with each letter of the alphabet using the `accumulate` function, returning the total number of unique substrings.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) since we process each character of the string once.

### Space Complexity 💾
- **Best Case:** O(26)
- **Worst Case:** O(26)

The space complexity is O(26) due to the fixed array used to track the maximum lengths of substrings for each character.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/unique-substrings-in-wraparound-string/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
