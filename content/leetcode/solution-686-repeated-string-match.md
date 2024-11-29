
+++
authors = ["grid47"]
title = "Leetcode 686: Repeated String Match"
date = "2024-08-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 686: Repeated String Match in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","String Matching"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/686.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/686.webp" 
    alt="A string repeated multiple times, with the matching part glowing softly as it’s found."
    caption="Solution to LeetCode 686: Repeated String Match Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given two strings, `a` and `b`. You need to find the minimum number of times you should repeat string `a` so that string `b` becomes a substring of the repeated `a`. If it is impossible, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two strings `a` and `b` consisting of lowercase English letters.
- **Example:** `a = 'xyz', b = 'yzxyz'`
- **Constraints:**
	- 1 <= a.length, b.length <= 10^4
	- a and b consist of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of times string `a` should be repeated such that string `b` becomes a substring of it. If not possible, return -1.
- **Example:** `For a = 'xyz' and b = 'yzxyz', the output is 2.`
- **Constraints:**
	- The output should be an integer representing the minimum number of times string `a` should be repeated.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the minimum number of repetitions of string `a` that contains string `b` as a substring.

- 1. Start by iterating over string `a` and try matching its substring with string `b`.
- 2. If the substring of repeated `a` matches `b`, return the number of repetitions.
- 3. If no such match is found, return -1.
{{< dots >}}
### Problem Assumptions ✅
- Both strings are not empty and contain only lowercase letters.
{{< dots >}}
## Examples 🧩
- **Input:** `a = 'xyz', b = 'yzxyz'`  \
  **Explanation:** Repeating string `a` two times gives 'xyzxyz', which contains 'yzxyz' as a substring.

- **Input:** `a = 'ab', b = 'ababab'`  \
  **Explanation:** Repeating string `a` three times gives 'ababab', which is exactly string `b`.

{{< dots >}}
## Approach 🚀
The approach is to iterate through possible repetitions of string `a` and check if string `b` is a substring of the repeated string.

### Initial Thoughts 💭
- We need to repeat string `a` multiple times to check if string `b` can fit within it as a substring.
- We can start from the smallest repetition and gradually increase until we find a match or exhaust all possibilities.
{{< dots >}}
### Edge Cases 🌐
- There will always be non-empty strings, so no need to handle empty strings.
- The solution should handle large strings efficiently (up to length 10^4).
- When `a` is exactly equal to `b`, the answer is 1.
- The time complexity should be efficient enough to handle the largest inputs within the given constraints.
{{< dots >}}
## Code 💻
```cpp
int repeatedStringMatch(string a, string b) {
    for(int i = 0, j = 0; i < a.size(); i++) {
        for(j = 0; j < b.size() && a[(i + j) % a.size()] == b[j]; j++);
        if(j == b.size())
            return (j + i - 1)/ a.size() + 1;
        
    }
    return -1;
}
```

This method checks if string 'b' can be obtained by repeatedly concatenating string 'a'. It finds the minimum number of repetitions needed for 'a' to contain 'b' as a substring. If it's not possible, it returns -1.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int repeatedStringMatch(string a, string b) {
	```
	Define the method 'repeatedStringMatch' that takes two strings, 'a' and 'b', and returns the minimum number of times 'a' must be repeated to contain 'b' as a substring.

2. **Loop Initialization**
	```cpp
	    for(int i = 0, j = 0; i < a.size(); i++) {
	```
	Start an outer loop to iterate through string 'a'. Initialize two indices, 'i' for 'a' and 'j' for 'b'.

3. **Inner Loop**
	```cpp
	        for(j = 0; j < b.size() && a[(i + j) % a.size()] == b[j]; j++);
	```
	Start an inner loop to check if the substring of 'a' starting from index 'i' matches the string 'b'. The modulo operator ensures that the loop wraps around to the start of 'a' if necessary.

4. **Substring Match Check**
	```cpp
	        if(j == b.size())
	```
	If the entire string 'b' has been matched within 'a', the condition is true.

5. **Return Calculation**
	```cpp
	            return (j + i - 1)/ a.size() + 1;
	```
	If a match is found, calculate the number of repetitions of 'a' needed to include 'b'. This is done by dividing the total length by the length of 'a' and adding 1.

6. **Return -1**
	```cpp
	    return -1;
	```
	If no valid match is found after all iterations, return -1 to indicate that it's not possible to form 'b' by repeating 'a'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of string b
- **Average Case:** O(n * m), where n is the length of string a and m is the length of string b
- **Worst Case:** O(n * m), where n is the length of string a and m is the length of string b

The time complexity depends on how many times we need to repeat string `a` and check if `b` is a substring.

### Space Complexity 💾
- **Best Case:** O(n), if we use efficient substring matching techniques.
- **Worst Case:** O(n * m), where n is the length of string a and m is the length of string b

The space complexity is dependent on the string storage and substring checking process.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/repeated-string-match/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
