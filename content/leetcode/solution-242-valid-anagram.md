
+++
authors = ["grid47"]
title = "Leetcode 242: Valid Anagram"
date = "2024-10-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 242: Valid Anagram in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/242.webp"
youtube = "QMXliZEU9dU"
youtube_upload_date="2022-06-26"
youtube_thumbnail="https://i.ytimg.com/vi/QMXliZEU9dU/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/242.webp" 
    alt="Two strings gently transforming into each other, with letters rearranging to form valid anagrams."
    caption="Solution to LeetCode 242: Valid Anagram Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given two strings, s and t. Determine if t is an anagram of s. Two strings are considered anagrams if they contain the exact same characters, but possibly in a different order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two strings, s and t, both containing lowercase English letters.
- **Example:** `Input: s = "listen", t = "silent"`
- **Constraints:**
	- 1 <= s.length, t.length <= 5 * 10^4
	- s and t consist of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if t is an anagram of s, otherwise return false.
- **Example:** `Output: true`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to verify if both strings contain the same frequency of characters.

- 1. Initialize an array to track the frequency of characters in both strings.
- 2. Increment the count for characters in string s.
- 3. Decrement the count for characters in string t.
- 4. If all counts are zero, return true. Otherwise, return false.
{{< dots >}}
### Problem Assumptions ✅
- The input strings are case-sensitive and consist only of lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = "listen", t = "silent"`  \
  **Explanation:** Both strings contain the same characters with the same frequency. Therefore, they are anagrams, and the output is true.

- **Input:** `Input: s = "rat", t = "car"`  \
  **Explanation:** The characters in the two strings are different, so the output is false.

- **Input:** `Input: s = "a", t = "a"`  \
  **Explanation:** Both strings are identical, hence they are anagrams of each other. The output is true.

{{< dots >}}
## Approach 🚀
To check if two strings are anagrams, we can use a frequency count of characters from both strings. If both strings have identical frequency distributions for all characters, they are anagrams.

### Initial Thoughts 💭
- The solution involves comparing the character counts from both strings.
- A direct comparison of character counts is efficient and will help identify if the strings are anagrams.
{{< dots >}}
### Edge Cases 🌐
- If both strings are empty, return true as they are trivially anagrams.
- The solution must efficiently handle strings of lengths up to 50,000 characters.
- Handle cases where the strings are identical or differ by only one character.
- Ensure that only lowercase letters are considered when counting characters.
{{< dots >}}
## Code 💻
```cpp
bool isAnagram(string s, string t) {
    vector<int> ch(26, 0);
    for(char x: s) ch[x - 'a']++;
    for(char x: t) ch[x - 'a']--;
    for(int x: ch) if(x != 0) return false;
    return true;
}
```

This function checks if two strings, `s` and `t`, are anagrams of each other by comparing the frequency of characters in both strings. It uses a vector `ch` to track the character frequencies, ensuring both strings have the same characters in the same counts.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool isAnagram(string s, string t) {
	```
	Defines the function `isAnagram`, which takes two strings, `s` and `t`, and returns a boolean indicating whether the strings are anagrams of each other.

2. **Character Frequency Vector Initialization**
	```cpp
	    vector<int> ch(26, 0);
	```
	Initializes a vector `ch` of size 26, which will be used to store the frequency count of each character in the alphabet (assuming the strings consist only of lowercase English letters).

3. **Increment Character Frequency for String s**
	```cpp
	    for(char x: s) ch[x - 'a']++;
	```
	Iterates through each character `x` in string `s` and increments the corresponding position in the `ch` vector based on the character's ASCII value (adjusted by subtracting `'a'`).

4. **Decrement Character Frequency for String t**
	```cpp
	    for(char x: t) ch[x - 'a']--;
	```
	Iterates through each character `x` in string `t` and decrements the corresponding position in the `ch` vector. This balances the frequency counts of characters in `s` and `t`.

5. **Check for Frequency Mismatch**
	```cpp
	    for(int x: ch) if(x != 0) return false;
	```
	Iterates through the `ch` vector to check if all character counts are zero. If any count is non-zero, it means the strings are not anagrams, so the function returns `false`.

6. **Return True for Anagrams**
	```cpp
	    return true;
	```
	If all character counts are zero, the strings are anagrams, so the function returns `true`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear in the size of the input strings, where n is the length of the strings.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant since we only need a fixed-size array (of size 26) to count character frequencies.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/valid-anagram/description/)

---
{{< youtube QMXliZEU9dU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
