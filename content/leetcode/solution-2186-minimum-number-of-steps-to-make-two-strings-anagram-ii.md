
+++
authors = ["grid47"]
title = "Leetcode 2186: Minimum Number of Steps to Make Two Strings Anagram II"
date = "2024-04-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2186: Minimum Number of Steps to Make Two Strings Anagram II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "U7tKTEdd0Lw"
youtube_upload_date="2022-02-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/U7tKTEdd0Lw/maxresdefault.webp"
comments = true
+++



---
You are given two strings, s and t. In each step, you can append any character to either s or t. Your task is to determine the minimum number of steps required to make s and t anagrams of each other.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two strings s and t.
- **Example:** `Input: s = 'listen', t = 'silent'`
- **Constraints:**
	- 1 <= s.length, t.length <= 2 * 10^5
	- s and t consist of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of steps required to make s and t anagrams of each other.
- **Example:** `Output: 0`
- **Constraints:**
	- Both s and t consist only of lowercase English letters.

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the number of steps to make s and t anagrams by appending characters.

- Count the frequency of each character in s and t.
- Calculate the difference in frequencies for each character.
- Sum up the absolute differences in frequencies to determine the minimum steps.
{{< dots >}}
### Problem Assumptions ✅
- Both strings contain only lowercase letters.
- The strings s and t are not empty.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = 'listen', t = 'silent'`  \
  **Explanation:** The two strings are already anagrams, so no additional steps are required. Thus, the output is 0.

- **Input:** `Input: s = 'abc', t = 'def'`  \
  **Explanation:** The characters 'a', 'b', 'c' need to be removed from s and 'd', 'e', 'f' need to be removed from t. Thus, 6 steps (3 from each string) are required.

{{< dots >}}
## Approach 🚀
We will count the frequency of characters in both strings, then compare these frequencies to calculate how many characters need to be added or removed to balance them.

### Initial Thoughts 💭
- If the strings are already anagrams, no steps are needed.
- The key idea is to count character occurrences and calculate the differences to figure out how many operations are required.
{{< dots >}}
### Edge Cases 🌐
- If either string is empty, the result is the length of the other string, since we need to add all its characters.
- The solution must efficiently handle strings with lengths up to 200,000.
- Strings that are already anagrams will require 0 steps.
- The solution should efficiently compute the result without excessive time complexity.
{{< dots >}}
## Code 💻
```cpp
int minSteps(string s, string t) {
    vector<int> tsk(26, 0);
    for(char c: s)
    tsk[c - 'a']++;
    for(char c: t)
    tsk[c - 'a']--;

    int ans = 0;
    for(int a: tsk) ans += abs(a);
    return ans;
}
```

This function calculates the minimum number of steps required to transform string `s` into string `t`. The steps involve modifying characters in `s` to match those in `t`, counting the total number of changes needed.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minSteps(string s, string t) {
	```
	This defines the function `minSteps`, which takes two input strings, `s` and `t`, and calculates the minimum steps to convert `s` into `t` by modifying the characters.

2. **Vector Initialization**
	```cpp
	    vector<int> tsk(26, 0);
	```
	A vector `tsk` of size 26 is initialized to store the frequency difference of each character between the two strings. Each index corresponds to a letter from 'a' to 'z'.

3. **Loop through String `s`**
	```cpp
	    for(char c: s)
	```
	This loop iterates through each character `c` in the string `s`.

4. **Update Frequency for `s`**
	```cpp
	    tsk[c - 'a']++;
	```
	For each character `c` in `s`, the corresponding frequency count in the `tsk` vector is incremented, where the index is calculated by subtracting 'a' from `c`.

5. **Loop through String `t`**
	```cpp
	    for(char c: t)
	```
	This loop iterates through each character `c` in the string `t`.

6. **Update Frequency for `t`**
	```cpp
	    tsk[c - 'a']--;
	```
	For each character `c` in `t`, the corresponding frequency count in the `tsk` vector is decremented.

7. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	The variable `ans` is initialized to 0. It will hold the total number of character modifications needed to transform string `s` into string `t`.

8. **Summing Absolute Differences**
	```cpp
	    for(int a: tsk) ans += abs(a);
	```
	This loop sums the absolute values of the differences in character frequencies stored in the `tsk` vector. Each non-zero value in `tsk` indicates the number of steps needed for that character.

9. **Return Result**
	```cpp
	    return ans;
	```
	The function returns the total number of modifications (`ans`) required to convert string `s` into string `t`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the strings, since we are counting characters in each string and then summing the differences.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1), as we only need a constant amount of extra space to store character frequencies.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/description/)

---
{{< youtube U7tKTEdd0Lw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
