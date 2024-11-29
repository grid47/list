
+++
authors = ["grid47"]
title = "Leetcode 1347: Minimum Number of Steps to Make Two Strings Anagram"
date = "2024-06-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1347: Minimum Number of Steps to Make Two Strings Anagram in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
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
You are given two strings s and t of the same length. In one step, you can choose any character of t and replace it with another character. Return the minimum number of steps to make t an anagram of s.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two strings, s and t, each containing lowercase English letters.
- **Example:** `For s = 'abc' and t = 'cba', no steps are required as the strings are already anagrams.`
- **Constraints:**
	- 1 <= s.length <= 5 * 10^4
	- s.length == t.length
	- s and t consist of lowercase English letters only.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of operations required to convert string t into an anagram of string s.
- **Example:** `For s = 'abcdef' and t = 'abcfgh', the output is 2 as 'g' and 'h' must be replaced.`
- **Constraints:**
	- The result should be within 10^-5 of the correct value.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine the number of replacements required to make t an anagram of s.

- 1. Count the frequency of each character in both strings s and t.
- 2. Calculate the difference in frequency for each character between s and t.
- 3. Sum the positive differences to get the minimum number of changes required.
{{< dots >}}
### Problem Assumptions ✅
- The strings s and t are always non-empty and have the same length.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: s = 'abc', t = 'cba'`  \
  **Explanation:** Both strings are already anagrams of each other, so no operations are required.

- **Input:** `Example 2: s = 'abcdef', t = 'abcfgh'`  \
  **Explanation:** Two characters ('g' and 'h') need to be replaced to make t an anagram of s.

- **Input:** `Example 3: s = 'hello', t = 'world'`  \
  **Explanation:** Four characters ('w', 'r', 'o', 'd') need to be replaced to make t an anagram of s.

{{< dots >}}
## Approach 🚀
The approach is to compare the frequency of characters in both strings and count how many characters in t need to be replaced to match s.

### Initial Thoughts 💭
- Both strings are of the same length, and we only need to adjust the frequency of characters.
- We can use a frequency counter to track how many characters are overrepresented or underrepresented in string t.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs, as both strings have a length of at least 1.
- The solution must efficiently handle large strings with up to 50,000 characters.
- If the strings are already anagrams, no steps are required.
- Ensure to handle cases where there are multiple instances of the same character in both strings.
{{< dots >}}
## Code 💻
```cpp
int minSteps(string s, string t) {
    vector<int> count(26, 0);
    for(int i = 0; i < s.length(); i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    int step = 0;
    for(int num : count)
        if(num > 0) step += num;
    return step;
}
```

This function calculates the minimum number of steps required to make one string an anagram of another by adding or removing characters. It uses a frequency count of characters to determine the mismatch.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minSteps(string s, string t) {
	```
	Declares a function to calculate the minimum steps to make string `s` an anagram of string `t`.

2. **Initialization**
	```cpp
	    vector<int> count(26, 0);
	```
	Initializes a frequency array `count` to track the differences in character occurrences between `s` and `t`.

3. **Loop to Count Frequency**
	```cpp
	    for(int i = 0; i < s.length(); i++) {
	```
	Iterates through each character in `s` and `t` to calculate frequency differences.

4. **Increment Frequency**
	```cpp
	        count[s[i] - 'a']++;
	```
	Increments the frequency count for the character in `s`.

5. **Decrement Frequency**
	```cpp
	        count[t[i] - 'a']--;
	```
	Decrements the frequency count for the character in `t`.

6. **Variable Declaration**
	```cpp
	    int step = 0;
	```
	Declares a variable `step` to store the total number of steps required.

7. **Iterate Frequency Array**
	```cpp
	    for(int num : count)
	```
	Iterates through the frequency array to calculate the positive mismatches.

8. **Count Mismatches**
	```cpp
	        if(num > 0) step += num;
	```
	Adds the positive mismatches to `step`, representing characters that need to be adjusted.

9. **Return Result**
	```cpp
	    return step;
	```
	Returns the total number of steps required to make the strings anagrams.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear, O(n), where n is the length of the strings.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, O(1), since the space used for character counts is fixed.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
