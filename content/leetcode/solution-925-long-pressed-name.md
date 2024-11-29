
+++
authors = ["grid47"]
title = "Leetcode 925: Long Pressed Name"
date = "2024-08-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 925: Long Pressed Name in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
Your friend is typing their name on a keyboard. Sometimes, while typing, a key might be long pressed, causing the character to be typed multiple times. Given the name and the typed string, determine if it is possible that the typed string could have been the result of long pressing some characters while typing the name.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two strings: 'name' representing your friend's name and 'typed' representing the characters typed on the keyboard.
- **Example:** `Input: name = "emma", typed = "eemmaa"`
- **Constraints:**
	- 1 <= name.length, typed.length <= 1000
	- Both 'name' and 'typed' consist of only lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return True if the 'typed' string could have been the result of long pressing characters from the 'name'. Otherwise, return False.
- **Example:** `Output: True`
- **Constraints:**
	- The strings 'name' and 'typed' will always contain only lowercase letters.

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine if the typed string could be derived from the name with some characters possibly being long pressed.

- Traverse both the 'name' and 'typed' strings simultaneously.
- If characters in 'typed' match the current character in 'name', continue.
- If a character in 'typed' matches the previous character, it can be considered a result of long pressing.
- If there is a mismatch and the previous character in 'typed' isn't the same as the current character, return False.
- At the end, check if all characters from 'name' have been matched correctly.
{{< dots >}}
### Problem Assumptions ✅
- The input strings contain only lowercase English letters.
- The typed string is potentially longer than the name due to long presses.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: name = "alison", typed = "aalliiison"`  \
  **Explanation:** The typed string has multiple instances of the 'l', 'i', and 's' characters, which could have been long pressed. Hence, the output is True.

- **Input:** `Input: name = "joan", typed = "jooaann"`  \
  **Explanation:** The second 'o' in the typed string doesn't match any subsequent character in the name, so the output is False.

{{< dots >}}
## Approach 🚀
The approach involves scanning both strings character by character to ensure the typed string could match the name with possible long presses.

### Initial Thoughts 💭
- The 'typed' string may contain repeated characters which could indicate long presses.
- We need to verify that characters in 'typed' are either exactly matching 'name' or are a result of long pressing.
- Using two pointers to traverse 'name' and 'typed' should efficiently solve this problem in linear time.
{{< dots >}}
### Edge Cases 🌐
- There will be no empty inputs for this problem since the input strings are guaranteed to have at least one character.
- Ensure that the solution works efficiently for input sizes up to 1000 characters.
- If 'name' is a prefix of 'typed', ensure that long presses of the last character in 'name' are correctly handled.
- The 'typed' string can only contain repeated characters from the 'name'.
{{< dots >}}
## Code 💻
```cpp
    bool isLongPressedName(string name, string typed) {
    int i = 0, m = name.length(), n = typed.length();
    for (int j = 0; j < n; ++j)
        if (i < m && name[i] == typed[j])
            ++i;
        else if (!j || typed[j] != typed[j - 1])
            return false;
    return i == m;
}
```

The function 'isLongPressedName' checks if the typed string is a valid long-pressed version of the given name string. It does so by comparing characters in both strings and ensuring that extra characters in the typed string are valid repetitions of the previous character.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	    bool isLongPressedName(string name, string typed) {
	```
	Define the function 'isLongPressedName' that takes two strings, 'name' and 'typed', and returns a boolean indicating whether 'typed' is a valid long-pressed version of 'name'.

2. **Variable Initialization**
	```cpp
	    int i = 0, m = name.length(), n = typed.length();
	```
	Initialize two integer variables, 'i' to track the index of 'name', and 'm' and 'n' to store the lengths of 'name' and 'typed', respectively.

3. **For Loop**
	```cpp
	    for (int j = 0; j < n; ++j)
	```
	Start a loop to iterate through the characters of the 'typed' string using the index variable 'j'.

4. **Character Comparison**
	```cpp
	        if (i < m && name[i] == typed[j])
	```
	Check if the current character in 'typed' matches the current character in 'name'. If it does, move to the next character in 'name' by incrementing 'i'.

5. **Increment Index**
	```cpp
	            ++i;
	```
	If the characters match, increment 'i' to move to the next character in 'name'.

6. **Long Press Validation**
	```cpp
	        else if (!j || typed[j] != typed[j - 1])
	```
	If the characters do not match, check if the current character in 'typed' is not the same as the previous one, or if it is the first character. If this condition is met, it means 'typed' contains an invalid sequence.

7. **Return False**
	```cpp
	            return false;
	```
	If an invalid sequence is detected, return false immediately, as 'typed' cannot be a valid long-pressed version of 'name'.

8. **Final Validation**
	```cpp
	    return i == m;
	```
	After iterating through 'typed', return true if all characters in 'name' have been matched. If 'i' equals 'm', it means the entire 'name' string was successfully matched.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the 'typed' string, as we traverse 'typed' and 'name' only once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1), as we are only using a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/long-pressed-name/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
