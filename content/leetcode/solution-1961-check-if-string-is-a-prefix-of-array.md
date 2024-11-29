
+++
authors = ["grid47"]
title = "Leetcode 1961: Check If String Is a Prefix of Array"
date = "2024-04-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1961: Check If String Is a Prefix of Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "msS6F5DL8gQ"
youtube_upload_date="2021-08-08"
youtube_thumbnail="https://i.ytimg.com/vi_webp/msS6F5DL8gQ/maxresdefault.webp"
comments = true
+++



---
You are given a string `s` and an array of strings `words`. Determine if the string `s` can be formed by concatenating the first `k` strings from the array `words`, for some value of `k`, where `1 <= k <= words.length`. Return true if `s` is a prefix of `words`, or false otherwise.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `s` and an array of strings `words`. The string `s` is a potential prefix formed by concatenating the first `k` words from the array `words`.
- **Example:** `s = "hello", words = ["he", "llo"]`
- **Constraints:**
	- 1 <= words.length <= 100
	- 1 <= words[i].length <= 20
	- 1 <= s.length <= 1000
	- words[i] and s consist of only lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a boolean value indicating whether `s` is a prefix formed by concatenating the first `k` words in `words`.
- **Example:** `Output: true`
- **Constraints:**
	- The string `s` must match the prefix formed by the concatenation of the words in `words`.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if the string `s` can be constructed by concatenating the first `k` strings in the array `words`.

- Step 1: Traverse through the strings in `words`, concatenating them one by one.
- Step 2: Compare the concatenated string with `s` at each step.
- Step 3: If the concatenated string matches `s`, return true; otherwise, return false.
{{< dots >}}
### Problem Assumptions ✅
- The array `words` will not contain any empty strings.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = "hello", words = ["he", "llo"]`  \
  **Explanation:** Here, the string `s` can be formed by concatenating the first two words from `words`, i.e., "he" + "llo" = "hello".

{{< dots >}}
## Approach 🚀
The approach is to concatenate the first `k` words from the array `words` and check if the concatenated string matches `s`.

### Initial Thoughts 💭
- The problem can be solved by simply iterating over the array `words` and checking for a match with `s`.
- Efficient string concatenation and comparison are key to solving this problem.
{{< dots >}}
### Edge Cases 🌐
- The string `s` and the array `words` will never be empty.
- Ensure that the solution handles large strings and arrays efficiently.
- Handle cases where `s` matches only a subset of the words in `words`.
- Make sure to respect the length constraints on both `s` and the elements of `words`.
{{< dots >}}
## Code 💻
```cpp
bool isPrefixString(string s, vector<string>& w) {
    int k = 0, l = 0, i = 0;
    for(i = 0; i < s.size() && k < w.size(); i++) {
        
        if(s[i] != w[k][l]) return false;
        
        l++;
        
        if(l == w[k].size()) {
            k++;
            l = 0;
        }
    }
    if(i != s.size()) return false;
    return (l == 0);
}
```

This function checks if a string `s` is a prefix of a series of strings in the vector `w`. It iterates through the characters of `s`, comparing them sequentially with the characters in the current word in `w`. If a complete word is matched, it moves to the next word in the sequence.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	bool isPrefixString(string s, vector<string>& w) {
	```
	Declares the function `isPrefixString` that takes a string `s` and a vector of strings `w`. It will determine if `s` is a prefix of the concatenated strings in `w`.

2. **Variable Initialization**
	```cpp
	    int k = 0, l = 0, i = 0;
	```
	Initializes variables `k`, `l`, and `i` to track the current word index (`k`), character index in the current word (`l`), and the loop index (`i`).

3. **Looping**
	```cpp
	    for(i = 0; i < s.size() && k < w.size(); i++) {
	```
	Starts a loop to iterate over the characters in the string `s` while also making sure that the index `k` is within the bounds of the vector `w`.

4. **Comparison**
	```cpp
	        if(s[i] != w[k][l]) return false;
	```
	Compares the character `s[i]` with the current character `w[k][l]`. If they do not match, the function immediately returns `false`.

5. **Progressing Indexes**
	```cpp
	        l++;
	```
	Increments the index `l` to move to the next character in the current word `w[k]`.

6. **Word Completion Check**
	```cpp
	        if(l == w[k].size()) {
	```
	Checks if the entire current word `w[k]` has been matched. If true, it resets `l` to start comparing the next word.

7. **Word Transition**
	```cpp
	            k++;
	```
	Increments `k` to move to the next word in the vector `w` after successfully matching the current word.

8. **Reset Character Index**
	```cpp
	            l = 0;
	```
	Resets the index `l` to 0 to begin comparing from the start of the next word.

9. **Final Check**
	```cpp
	    if(i != s.size()) return false;
	```
	Checks if all characters of `s` have been matched. If not, it returns `false`.

10. **Return Result**
	```cpp
	    return (l == 0);
	```
	Returns `true` if `l` is 0, meaning the last word was fully matched and the string `s` is a valid prefix. Otherwise, returns `false`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

In the worst case, we iterate through all `n` words and concatenate them, where `n` is the length of the `words` array.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the concatenation of strings from the array `words`.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/description/)

---
{{< youtube msS6F5DL8gQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
