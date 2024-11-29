
+++
authors = ["grid47"]
title = "Leetcode 1662: Check If Two String Arrays are Equivalent"
date = "2024-05-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1662: Check If Two String Arrays are Equivalent in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "ejBwc2oE7ck"
youtube_upload_date="2023-12-01"
youtube_thumbnail="https://i.ytimg.com/vi/ejBwc2oE7ck/maxresdefault.jpg"
comments = true
+++



---
You are given two string arrays `word1` and `word2`. Return `true` if these two arrays represent the same string when their elements are concatenated in order, otherwise return `false`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two arrays of strings, `word1` and `word2`.
- **Example:** `word1 = ["hello", "world"], word2 = ["hell", "oworld"]`
- **Constraints:**
	- 1 <= word1.length, word2.length <= 10^3
	- 1 <= word1[i].length, word2[i].length <= 10^3
	- 1 <= sum(word1[i].length), sum(word2[i].length) <= 10^3
	- word1[i] and word2[i] consist of lowercase letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return `true` if the two arrays represent the same string, otherwise return `false`.
- **Example:** `true`
- **Constraints:**
	- The output will be a boolean value.

{{< dots >}}
### Core Logic 🔍
**Goal:** Check if the concatenated strings from `word1` and `word2` are equal.

- Concatenate all strings in `word1` into a single string `str1`.
- Concatenate all strings in `word2` into a single string `str2`.
- Compare the two resulting strings and return `true` if they are equal, otherwise return `false`.
{{< dots >}}
### Problem Assumptions ✅
- The arrays `word1` and `word2` will only contain lowercase letters.
{{< dots >}}
## Examples 🧩
- **Input:** `word1 = ["hello", "world"], word2 = ["hell", "oworld"]`  \
  **Explanation:** Both `word1` and `word2` form the string "helloworld" when concatenated, so the answer is `true`.

- **Input:** `word1 = ["abc", "def"], word2 = ["abcd", "ef"]`  \
  **Explanation:** The strings formed by `word1` and `word2` are "abcdef" and "abcde", respectively, which are not equal. Therefore, return `false`.

{{< dots >}}
## Approach 🚀
We need to compare the concatenated strings from `word1` and `word2` and check if they are identical.

### Initial Thoughts 💭
- We can solve this by converting both arrays into strings and then comparing them.
- Iterate through both arrays, concatenate their elements into two separate strings, and compare the results.
{{< dots >}}
### Edge Cases 🌐
- If either `word1` or `word2` is empty, return `false` if the other is not empty.
- The solution should efficiently handle arrays with a total length of up to 1000 characters.
- If the strings formed from both arrays are the same, return `true`.
- The total length of the strings in both arrays will not exceed 1000 characters.
{{< dots >}}
## Code 💻
```cpp
bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    string a,b;
    for(auto x:word1)
        a += x;
    for(auto x:word2)
        b += x;
   
    if(a == b)
        return 1;
    
    return 0;
}
```

This function checks if two arrays of strings, when concatenated, form the same string. It constructs full strings for each array and compares them for equality.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
	```
	Defines the function `arrayStringsAreEqual` that takes two arrays of strings and returns a boolean indicating if their concatenated forms are equal.

2. **Variable Initialization**
	```cpp
	    string a,b;
	```
	Initializes two strings `a` and `b` to store concatenated results of the arrays `word1` and `word2`.

3. **Looping**
	```cpp
	    for(auto x:word1)
	```
	Iterates through each string in `word1` to construct the concatenated string `a`.

4. **String Concatenation**
	```cpp
	        a += x;
	```
	Appends the current string `x` from `word1` to the concatenated string `a`.

5. **Looping**
	```cpp
	    for(auto x:word2)
	```
	Iterates through each string in `word2` to construct the concatenated string `b`.

6. **String Concatenation**
	```cpp
	        b += x;
	```
	Appends the current string `x` from `word2` to the concatenated string `b`.

7. **Condition Check**
	```cpp
	    if(a == b)
	```
	Checks if the concatenated strings `a` and `b` are equal.

8. **Return**
	```cpp
	        return 1;
	```
	Returns `true` (1) if the concatenated strings are equal.

9. **Return**
	```cpp
	    return 0;
	```
	Returns `false` (0) if the concatenated strings are not equal.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) since we concatenate and compare strings, where n is the total number of characters across both arrays.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of concatenated strings.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/)

---
{{< youtube ejBwc2oE7ck >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
