
+++
authors = ["grid47"]
title = "Leetcode 2914: Minimum Number of Changes to Make Binary String Beautiful"
date = "2024-01-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2914: Minimum Number of Changes to Make Binary String Beautiful in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "mzozXxrB_fk"
youtube_upload_date="2023-10-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/mzozXxrB_fk/maxresdefault.webp"
comments = true
+++



---
You are given a 0-indexed binary string `s` of even length. A string is considered beautiful if it can be divided into substrings where each substring has an even length and contains only '0's or only '1's. You can modify any character in `s` to '0' or '1'. The task is to return the minimum number of changes required to make the string beautiful.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a binary string `s` with even length, where each character is either '0' or '1'.
- **Example:** `s = '1010'`
- **Constraints:**
	- 2 <= s.length <= 10^5
	- s has an even length
	- s[i] is either '0' or '1'

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of changes needed to make the string beautiful.
- **Example:** `For `s = '1010'`, the output is 2.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to transform the given string into a beautiful string by changing the minimum number of characters.

- Iterate over the string in steps of 2.
- For each pair of adjacent characters, check if they are equal.
- If they are not equal, increment the change counter.
- Return the total number of changes.
{{< dots >}}
### Problem Assumptions ✅
- The string length is always even.
- The string contains only '0' and '1'.
{{< dots >}}
## Examples 🧩
- **Input:** `s = '1010'`  \
  **Explanation:** The possible partition is: '10' | '10'. The string is not beautiful because the two substrings are not uniform. We need to change one '0' to '1' and one '1' to '0', resulting in the string '1111'. The minimum number of changes is 2.

- **Input:** `s = '1100'`  \
  **Explanation:** The string '1100' is already beautiful because it can be partitioned into '11' | '00'. No changes are needed.

{{< dots >}}
## Approach 🚀
We need to ensure that every pair of adjacent characters in the string is uniform (either both '0' or both '1'). If they are not, we increment the change counter. The problem requires checking pairs and determining the minimum number of changes.

### Initial Thoughts 💭
- The string must be modified to have consecutive pairs of equal characters.
- The solution requires iterating through the string and checking adjacent characters.
- By checking pairs in the string, we can directly calculate the number of required changes.
{{< dots >}}
### Edge Cases 🌐
- The input will never be empty since the string length is guaranteed to be even and at least 2.
- The solution needs to handle strings with a length of up to 100,000 efficiently.
- When the string consists entirely of '0's or '1's, no changes are needed.
- The string length will always be even.
- All characters in the string will be either '0' or '1'.
{{< dots >}}
## Code 💻
```cpp
// time/space: O(n)/O(1)
int minChanges(string s) {
    int result = 0;
    int n = s.size();
    for (int i = 0; i < n; i += 2) {
        const char& a = s[i];
        const char& b = s[i + 1];
        if (a != b) result++;
    }        
    return result;
}
```

This function calculates the minimum number of changes required to make a string such that every two adjacent characters are the same. It iterates through the string in steps of two and compares each pair of adjacent characters.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minChanges(string s) {
	```
	Defines the function `minChanges` which takes a string `s` as input and returns the minimum number of changes required.

2. **Variable Initialization**
	```cpp
	    int result = 0;
	```
	Initializes the variable `result` to 0. This will hold the count of changes needed.

3. **Variable Initialization**
	```cpp
	    int n = s.size();
	```
	Initializes the variable `n` to store the size of the string `s`.

4. **Loop: Iterate Over String**
	```cpp
	    for (int i = 0; i < n; i += 2) {
	```
	Starts a loop that iterates through the string `s`, incrementing `i` by 2 each time, so it checks every pair of adjacent characters.

5. **Variable Assignment**
	```cpp
	        const char& a = s[i];
	```
	Assigns the character at index `i` of the string `s` to the reference variable `a`.

6. **Variable Assignment**
	```cpp
	        const char& b = s[i + 1];
	```
	Assigns the character at index `i + 1` of the string `s` to the reference variable `b`.

7. **Conditional Check**
	```cpp
	        if (a != b) result++;
	```
	Checks if the characters `a` and `b` are different. If they are, it increments the `result` variable by 1, indicating a change is needed.

8. **Return Statement**
	```cpp
	    return result;
	```
	Returns the final value of `result`, which represents the minimum number of changes needed to make every pair of adjacent characters in the string the same.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we are iterating through the string with a step of 2, which is a linear operation.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since we are only using a constant amount of extra space to keep track of the change count.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/description/)

---
{{< youtube mzozXxrB_fk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
