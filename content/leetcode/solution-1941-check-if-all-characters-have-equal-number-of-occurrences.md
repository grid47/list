
+++
authors = ["grid47"]
title = "Leetcode 1941: Check if All Characters Have Equal Number of Occurrences"
date = "2024-04-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1941: Check if All Characters Have Equal Number of Occurrences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "PG9qfNf5vLw"
youtube_upload_date="2021-07-24"
youtube_thumbnail="https://i.ytimg.com/vi/PG9qfNf5vLw/maxresdefault.jpg"
comments = true
+++



---
Given a string s, determine if it is a 'good' string. A string is considered good if every character in it appears the same number of times.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A single string s containing lowercase English letters.
- **Example:** `s = "abbcaa"`
- **Constraints:**
	- 1 <= s.length <= 1000
	- s consists of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if the string is good, or false otherwise.
- **Example:** `Output: true`
- **Constraints:**
	- Output is a boolean value.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if all characters in the string have the same frequency.

- Count the frequency of each character in the string.
- Check if all the frequencies are the same.
{{< dots >}}
### Problem Assumptions ✅
- The string s is non-empty and consists of only lowercase letters.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: s = "abbcaa"`  \
  **Explanation:** In this case, both 'a', 'b', and 'c' appear twice in the string. Hence, all characters have the same frequency, and the output is true.

- **Input:** `Example 2: s = "aabbbcc"`  \
  **Explanation:** In this case, 'a' appears twice, 'b' appears three times, and 'c' appears twice. The frequencies are not all the same, so the output is false.

{{< dots >}}
## Approach 🚀
To solve the problem, the approach is to count the frequency of each character in the string and check if all characters have the same frequency.

### Initial Thoughts 💭
- If all characters have the same frequency, the string is good.
- We need to count character occurrences and compare them to determine if they are all the same.
{{< dots >}}
### Edge Cases 🌐
- An empty string would trivially be a good string, but this case is not valid based on constraints.
- Handle strings near the upper constraint limit (1000 characters).
- Strings where all characters are the same will always return true.
- Check for strings with a small number of characters to ensure the logic handles both small and large inputs efficiently.
{{< dots >}}
## Code 💻
```cpp
bool areOccurrencesEqual(string s) {
    int cnt[26] = {}, m_cnt = 0;
    for (auto ch : s)
        m_cnt = max(m_cnt, ++cnt[ch - 'a']);
    return all_of(begin(cnt), end(cnt), [&m_cnt](int t){ return t == 0 || t == m_cnt; });
}
```

This code checks if all characters in the input string `s` have the same frequency.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool areOccurrencesEqual(string s) {
	```
	Declare the function `areOccurrencesEqual` which takes a string `s` as input.

2. **Variable Initialization**
	```cpp
	    int cnt[26] = {}, m_cnt = 0;
	```
	Initialize an array `cnt` of size 26 to store the frequency of each character in the string, and `m_cnt` to track the maximum frequency of any character.

3. **For Loop (Character Iteration)**
	```cpp
	    for (auto ch : s)
	```
	Iterate through each character `ch` in the string `s`.

4. **Max Frequency Update**
	```cpp
	        m_cnt = max(m_cnt, ++cnt[ch - 'a']);
	```
	Update `m_cnt` to the maximum of the current `m_cnt` and the updated count of the character `ch` in `cnt`.

5. **Final Check**
	```cpp
	    return all_of(begin(cnt), end(cnt), [&m_cnt](int t){ return t == 0 || t == m_cnt; });
	```
	Return `true` if all character counts are either 0 or equal to the maximum frequency `m_cnt`; otherwise, return `false`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the string.
- **Average Case:** O(n), since we need to iterate through the string once to count frequencies.
- **Worst Case:** O(n), since checking frequencies requires a single pass through the string.

The time complexity is linear in the length of the string due to the need to iterate over the string and count character occurrences.

### Space Complexity 💾
- **Best Case:** O(26), as we only store the frequency counts of each character.
- **Worst Case:** O(26), since there are at most 26 unique lowercase English letters.

The space complexity is constant because we only need to store the frequency of 26 characters.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/description/)

---
{{< youtube PG9qfNf5vLw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
