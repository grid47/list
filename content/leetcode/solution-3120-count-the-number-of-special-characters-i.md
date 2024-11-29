
+++
authors = ["grid47"]
title = "Leetcode 3120: Count the Number of Special Characters I"
date = "2023-12-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3120: Count the Number of Special Characters I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "VV4TTRQ5l0s"
youtube_upload_date="2024-04-21"
youtube_thumbnail="https://i.ytimg.com/vi_webp/VV4TTRQ5l0s/maxresdefault.webp"
comments = true
+++



---
You are given a string `word`. A letter is considered special if it appears both in its lowercase and uppercase form in the string. Return the number of special letters in `word`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `word` of length n.
- **Example:** `word = "aAAbcdBC"`
- **Constraints:**
	- 1 <= word.length <= 50
	- word consists of only lowercase and uppercase English letters

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of special letters in the string `word`.
- **Example:** `Output: 3`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Identify letters that appear in both lowercase and uppercase in the string and count them.

- 1. Create a set to store unique characters in `word`.
- 2. Loop through each letter in the alphabet ('a' to 'z').
- 3. For each letter, check if both the lowercase and uppercase forms exist in the set.
- 4. Count and return the total number of special letters.
{{< dots >}}
### Problem Assumptions ✅
- The input string will only contain lowercase and uppercase English letters.
- The string will have a length between 1 and 50 characters.
{{< dots >}}
## Examples 🧩
- **Input:** `word = "aAAbcdBC"`  \
  **Explanation:** The special characters are 'a', 'b', and 'c', as they appear in both uppercase and lowercase in `word`.

- **Input:** `word = "abcdef"`  \
  **Explanation:** No special characters exist in this string, as no letter appears in both uppercase and lowercase.

- **Input:** `word = "AbBcC"`  \
  **Explanation:** The special characters are 'b' and 'c', as they appear both in lowercase and uppercase.

{{< dots >}}
## Approach 🚀
We can solve the problem by using a set to store all the letters in the string and then check if both the lowercase and uppercase versions of each letter exist in the set.

### Initial Thoughts 💭
- We need to check for each letter if both its lowercase and uppercase forms exist in the string.
- By iterating through all the letters in the string, we can efficiently find special letters using a set.
{{< dots >}}
### Edge Cases 🌐
- The string will always have at least one character as per the constraints.
- The solution should efficiently handle strings with lengths up to 50 characters.
- If the string contains only lowercase or only uppercase letters, the output should be 0.
- The string is constrained to only contain lowercase and uppercase English letters.
{{< dots >}}
## Code 💻
```cpp
int numberOfSpecialChars(string word) {
    set<char> ch;
    for(char x: word)
            ch.insert(x);
    int cnt = 0;
    for(int i = 0; i < 26; i++) {
        if(ch.count('a' + i) && ch.count('A' + i))
            cnt++;
    }
    return cnt;
}
```

This function calculates the number of special characters in the string `word`, where a special character is defined as a pair of lowercase and uppercase letters present in the string.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int numberOfSpecialChars(string word) {
	```
	Defines the function `numberOfSpecialChars` that takes a string `word` as input and returns the count of special characters, where a special character is a pair of the same letter in both lowercase and uppercase.

2. **Set Initialization**
	```cpp
	    set<char> ch;
	```
	Initializes a set `ch` to store unique characters from the input string `word`. Using a set ensures that each character is only stored once.

3. **Loop Through String**
	```cpp
	    for(char x: word)
	```
	Iterates through each character `x` in the string `word`.

4. **Insert Character into Set**
	```cpp
	            ch.insert(x);
	```
	Inserts the character `x` into the set `ch`, ensuring that only unique characters are stored.

5. **Counter Initialization**
	```cpp
	    int cnt = 0;
	```
	Initializes the counter variable `cnt` to 0, which will be used to count the number of special characters (pairs of lowercase and uppercase letters).

6. **Loop Over Alphabet**
	```cpp
	    for(int i = 0; i < 26; i++) {
	```
	Starts a `for` loop that iterates over the 26 letters of the alphabet (from 'a' to 'z').

7. **Check Pair of Letters**
	```cpp
	        if(ch.count('a' + i) && ch.count('A' + i))
	```
	Checks if both the lowercase and uppercase versions of the letter (corresponding to `i`) are present in the set `ch`.

8. **Increment Counter**
	```cpp
	            cnt++;
	```
	If both the lowercase and uppercase characters are found, increments the counter `cnt` to account for one special character.

9. **Return Result**
	```cpp
	    return cnt;
	```
	Returns the value of `cnt`, which represents the total number of special characters in the string `word`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the string, since we only loop through the string once and check for each character's presence in the set.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since we only store a constant number of unique characters (26 lowercase and 26 uppercase letters).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-the-number-of-special-characters-i/description/)

---
{{< youtube VV4TTRQ5l0s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
