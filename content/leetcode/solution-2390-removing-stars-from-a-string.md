
+++
authors = ["grid47"]
title = "Leetcode 2390: Removing Stars From a String"
date = "2024-03-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2390: Removing Stars From a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Qln1aXh2kvQ"
youtube_upload_date="2023-04-11"
youtube_thumbnail="https://i.ytimg.com/vi/Qln1aXh2kvQ/maxresdefault.jpg"
comments = true
+++



---
You are given a string `s` that contains lowercase English letters and stars (`*`). In each operation, you can choose a star in `s`, remove the closest non-star character to its left, and remove the star itself. Perform this operation until all stars are removed and return the resulting string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `s` that contains lowercase English letters and stars (`*`).
- **Example:** `Input: s = 'abc*def*gh*'`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- s consists of lowercase English letters and stars `*`.
	- The operation above can be performed on s.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the string after all stars have been removed by performing the operation as described.
- **Example:** `Output: 'abgh'`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to remove the closest character to each star from left to right until all stars are removed.

- 1. Traverse the string and for each star, remove the closest non-star character to its left.
- 2. After each removal, adjust the string accordingly and continue the operation.
- 3. Repeat the process until all stars are removed.
{{< dots >}}
### Problem Assumptions ✅
- There will always be a non-star character to remove before each star.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = 'abc*def*gh*'`  \
  **Explanation:** In the first operation, remove 'c' before the first star, resulting in 'ab*def*gh*'. Then remove 'f' before the second star, resulting in 'abdef*gh*'. Finally, remove 'g' before the last star, leaving 'abgh'.

- **Input:** `Input: s = 'abc*****'`  \
  **Explanation:** In this case, all characters are removed sequentially one by one before each star, resulting in an empty string.

{{< dots >}}
## Approach 🚀
We will iterate through the string, maintain a pointer for the current position, and simulate the removal of the closest characters before each star.

### Initial Thoughts 💭
- We need to efficiently track the position of each star and remove the correct character from left to right.
- A stack-like approach would be useful to track the characters as we traverse through the string. When encountering a star, we can pop the last added character.
{{< dots >}}
### Edge Cases 🌐
- If the input string is empty, return an empty string.
- Ensure the solution can handle the maximum input size efficiently (up to 100,000 characters).
- Handle cases where stars are placed at the beginning or end of the string.
- Make sure the solution works within the time limits for large inputs.
{{< dots >}}
## Code 💻
```cpp
string removeStars(string s) {
    int j = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != '*') s[j++] = s[i];
        else {
            j--;
        }
    }
    return s.substr(0, j);
}
```

This function removes all '*' characters from the input string `s`, handling the removal by using a pointer `j` that tracks the position of the remaining valid characters.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string removeStars(string s) {
	```
	Function declaration that takes a string `s` and returns a modified string with all '*' characters removed.

2. **Variable Initialization**
	```cpp
	    int j = 0;
	```
	Initialize an integer `j` to track the position where valid characters should be placed in the string.

3. **Loop**
	```cpp
	    for(int i = 0; i < s.size(); i++) {
	```
	Loop through the string `s`, from the beginning to the end, using `i` as the index.

4. **Character Check**
	```cpp
	        if(s[i] != '*') s[j++] = s[i];
	```
	If the current character is not '*', copy it to the position `j` and increment `j` to the next valid position.

5. **Star Removal**
	```cpp
	        else {
	```
	If the current character is a '*', enter the else block to handle its removal.

6. **Pointer Adjustment**
	```cpp
	            j--;
	```
	Decrement `j` to overwrite the last valid character, effectively removing the '*' character.

7. **Return Substring**
	```cpp
	    return s.substr(0, j);
	```
	Return the modified string by extracting the substring from the beginning up to the position `j`, which contains all valid characters.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) where n is the length of the string.
- **Average Case:** O(n) where n is the length of the string.
- **Worst Case:** O(n) where n is the length of the string.

The algorithm processes each character exactly once, resulting in a time complexity of O(n).

### Space Complexity 💾
- **Best Case:** O(n) for storing the intermediate results in the stack.
- **Worst Case:** O(n) for storing the intermediate results in the stack.

The space complexity is O(n) due to the storage needed for the stack that holds the resulting characters.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/removing-stars-from-a-string/description/)

---
{{< youtube Qln1aXh2kvQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
