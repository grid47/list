
+++
authors = ["grid47"]
title = "Leetcode 2309: Greatest English Letter in Upper and Lower Case"
date = "2024-03-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2309: Greatest English Letter in Upper and Lower Case in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "C37FoUne7gc"
youtube_upload_date="2022-06-19"
youtube_thumbnail="https://i.ytimg.com/vi_webp/C37FoUne7gc/maxresdefault.webp"
comments = true
+++



---
Given a string s consisting of both uppercase and lowercase English letters, return the greatest letter that appears as both a lowercase and uppercase letter in the string. The returned letter should be in uppercase. If no such letter exists, return an empty string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string s containing both uppercase and lowercase English letters.
- **Example:** `s = 'aBcDeFg'`
- **Constraints:**
	- 1 <= s.length <= 1000
	- s consists of lowercase and uppercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the greatest English letter that appears as both a lowercase and uppercase letter, in uppercase form. If no such letter exists, return an empty string.
- **Example:** `For s = 'aBcDeFg', the output is 'F'.`
- **Constraints:**
	- Return the greatest letter in uppercase.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the letter that appears both in uppercase and lowercase, and return the greatest one in uppercase.

- Iterate through the string s and track the occurrence of each letter in both lowercase and uppercase.
- Start from the greatest possible letter ('Z') and check if both the lowercase and uppercase versions are present in the string.
- Return the first such letter found in uppercase, or an empty string if no such letter exists.
{{< dots >}}
### Problem Assumptions ✅
- The input string contains only English letters and may include both uppercase and lowercase versions of letters.
{{< dots >}}
## Examples 🧩
- **Input:** `s = 'aBcDeFg'`  \
  **Explanation:** The letter 'F' is the greatest letter that appears as both 'f' and 'F'. The function returns 'F'.

{{< dots >}}
## Approach 🚀
The approach to solving this problem involves checking for the presence of each letter as both lowercase and uppercase, then returning the greatest one.

### Initial Thoughts 💭
- We need to efficiently find a letter that appears as both lowercase and uppercase.
- Starting from the largest possible letter ('Z'), we can check each letter for both cases. If found, return that letter in uppercase.
{{< dots >}}
### Edge Cases 🌐
- Empty strings are not possible according to the constraints.
- Handle strings of length up to 1000 efficiently.
- If no letter appears in both uppercase and lowercase, return an empty string.
- Ensure that the output is the letter in uppercase if both cases are found.
{{< dots >}}
## Code 💻
```cpp
string greatestLetter(string s) {
    int cnt[128] = {};
    for (auto ch : s)
        ++cnt[ch];
    for (auto ch = 'Z'; ch >= 'A'; --ch)
        if (cnt[ch] && cnt[ch + 'a' - 'A'])
            return string(1, ch);
    return "";
}
```

This function finds the greatest letter (in uppercase) that appears both in uppercase and lowercase in a given string. It first counts the occurrences of each character in the string, then checks from 'Z' to 'A' to find the greatest matching letter.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string greatestLetter(string s) {
	```
	Define the function `greatestLetter` that takes a string `s` as input and returns a string containing the greatest letter (uppercase) that appears both in uppercase and lowercase.

2. **Array Initialization**
	```cpp
	    int cnt[128] = {};
	```
	Initialize an array `cnt` of size 128 to store the frequency of each character in the input string. The size 128 ensures that all ASCII characters are accounted for.

3. **Loop Through String**
	```cpp
	    for (auto ch : s)
	```
	Iterate through each character `ch` in the input string `s`.

4. **Character Count**
	```cpp
	        ++cnt[ch];
	```
	Increment the corresponding count for the character `ch` in the `cnt` array.

5. **Descending Check**
	```cpp
	    for (auto ch = 'Z'; ch >= 'A'; --ch)
	```
	Start a loop that checks each uppercase letter from 'Z' to 'A'. This ensures we find the greatest possible letter first.

6. **Matching Check**
	```cpp
	        if (cnt[ch] && cnt[ch + 'a' - 'A'])
	```
	Check if both the uppercase character `ch` and its corresponding lowercase character `ch + 'a' - 'A'` appear in the string.

7. **Return Result**
	```cpp
	            return string(1, ch);
	```
	If both uppercase and lowercase characters are found, return the uppercase letter as a string.

8. **Return Empty String**
	```cpp
	    return "";
	```
	If no matching pair of uppercase and lowercase letters is found, return an empty string.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where n is the length of the input string, as we only iterate through the string once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we only use a constant amount of space for tracking the occurrences of each letter.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/description/)

---
{{< youtube C37FoUne7gc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
