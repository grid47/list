
+++
authors = ["grid47"]
title = "Leetcode 1400: Construct K Palindrome Strings"
date = "2024-06-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1400: Construct K Palindrome Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Greedy","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given a string `s` and an integer `k`. Your task is to determine whether it's possible to use all the characters in the string `s` to construct exactly `k` palindromic strings.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `s` and an integer `k`.
- **Example:** `["civic", 2]`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- s consists of lowercase English letters.
	- 1 <= k <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a boolean value indicating whether it is possible to construct exactly `k` palindromic strings from the characters in `s`.
- **Example:** `true`
- **Constraints:**
	- The output is `true` if it's possible, `false` otherwise.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine if the characters of the string can be rearranged to form `k` palindromes.

- Count the frequency of each character in the string.
- To form a palindrome, characters must appear in pairs (even frequency), with at most one character allowed to appear an odd number of times for a single palindrome.
- The number of odd character frequencies should be less than or equal to `k`.
{{< dots >}}
### Problem Assumptions ✅
- The string `s` consists of lowercase English letters only.
- The number of palindromes `k` must be a valid integer within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: ["civic", 2]`  \
  **Explanation:** In this example, we can form two palindromes using the characters in 'civic'.

- **Input:** `Input: ["abcde", 2]`  \
  **Explanation:** In this example, it is impossible to form two palindromes with the characters in 'abcde'.

{{< dots >}}
## Approach 🚀
The approach involves counting the frequency of each character and determining if it's possible to form the required number of palindromes. The key condition is that the number of odd frequencies should not exceed `k`.

### Initial Thoughts 💭
- Palindromes can only be formed if the number of characters with odd frequencies is less than or equal to the number of palindromes.
- Consider the problem as checking if the distribution of character frequencies allows for `k` palindromes.
{{< dots >}}
### Edge Cases 🌐
- What if the string is empty?
- Ensure the solution can handle inputs up to 10^5 characters efficiently.
- What if `k` is 1 or equal to the length of the string?
- The solution must be efficient enough to handle the maximum constraint sizes.
{{< dots >}}
## Code 💻
```cpp
bool canConstruct(string s, int k) {
    bitset<26> odd;
    for(char c: s)
    odd.flip(c - 'a');
    return odd.count() <= k && k <= s.size();
}
```

This code defines the `canConstruct` function, which checks if a string `s` can be rearranged such that no more than `k` characters appear an odd number of times.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method Definition**
	```cpp
	bool canConstruct(string s, int k) {
	```
	Defines the `canConstruct` function which takes a string `s` and an integer `k` as parameters.

2. **Variable Initialization**
	```cpp
	    bitset<26> odd;
	```
	Declares a bitset `odd` to track the parity (odd or even count) of each letter in the alphabet.

3. **Loop Operation**
	```cpp
	    for(char c: s)
	```
	Iterates over each character `c` in the string `s`.

4. **Bitset Operation**
	```cpp
	    odd.flip(c - 'a');
	```
	Flips the corresponding bit in the `odd` bitset based on the character `c`. This operation toggles the bit to reflect whether the character appears an odd or even number of times.

5. **Return Statement**
	```cpp
	    return odd.count() <= k && k <= s.size();
	```
	Returns `true` if the number of odd counts is less than or equal to `k` and `k` is less than or equal to the length of the string `s`. Otherwise, returns `false`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) where n is the length of the string (if there are no odd frequencies).
- **Average Case:** O(n) as counting frequencies requires a single scan of the string.
- **Worst Case:** O(n) where n is the length of the string (this is the same as average case because we only need to count frequencies).



### Space Complexity 💾
- **Best Case:** O(1) since the number of characters is constant (26 possible characters).
- **Worst Case:** O(1) as we are only using a fixed number of counters for character frequencies (26 letters).



**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/construct-k-palindrome-strings/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
