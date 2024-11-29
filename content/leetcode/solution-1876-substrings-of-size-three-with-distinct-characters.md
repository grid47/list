
+++
authors = ["grid47"]
title = "Leetcode 1876: Substrings of Size Three with Distinct Characters"
date = "2024-05-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1876: Substrings of Size Three with Distinct Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sliding Window","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "QIyWjKNstAA"
youtube_upload_date="2021-05-29"
youtube_thumbnail="https://i.ytimg.com/vi_webp/QIyWjKNstAA/maxresdefault.webp"
comments = true
+++



---
You are given a string `s`, and your task is to find the number of substrings of length 3 that contain no repeated characters. A substring is considered 'good' if all its characters are unique. Note that if a 'good' substring appears more than once, it should be counted multiple times.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string `s` which consists of lowercase English letters.
- **Example:** `For s = "abcabc".`
- **Constraints:**
	- 1 <= s.length <= 100
	- s consists of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of 'good' substrings of length 3 in the string `s`.
- **Example:** `For the input s = "abcabc", the output is 4.`
- **Constraints:**
	- The output should be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** We need to find all substrings of length 3 and count those that have no repeated characters.

- Iterate through the string from index 0 to n - 3.
- For each position, extract the substring of length 3 and check if all characters are unique.
- Count the valid substrings where all characters are distinct.
{{< dots >}}
### Problem Assumptions ✅
- The string `s` contains at least one substring of length 3.
{{< dots >}}
## Examples 🧩
- **Input:** `For the input s = "abcabc".`  \
  **Explanation:** The substrings of length 3 are: 'abc', 'bca', 'cab', and 'abc'. All of these are 'good' substrings since they contain unique characters.

- **Input:** `For the input s = "aababcabc".`  \
  **Explanation:** The substrings of length 3 are: 'aab', 'aba', 'bab', 'abc', 'bca', 'cab', 'abc'. The 'good' substrings are 'abc', 'bca', and 'cab'.

{{< dots >}}
## Approach 🚀
To solve this problem, we can iterate over the string and extract all substrings of length 3. Then, we check whether all the characters in the substring are unique.

### Initial Thoughts 💭
- We need to consider substrings of fixed length 3.
- We can efficiently check for uniqueness using a set.
- Checking each substring for uniqueness will take O(1) time using a set, and iterating through the string will take O(n).
{{< dots >}}
### Edge Cases 🌐
- Not applicable as the string length is at least 1.
- The algorithm should handle strings of length up to 100.
- Test strings with repeated characters only, such as 'aaa'.
- Ensure that only substrings of exactly length 3 are considered.
{{< dots >}}
## Code 💻
```cpp
int countGoodSubstrings(string s) {
    
    int cnt = 0;
    for(int i = 2; i < s.size(); i++)
        if(s[i] != s[i - 1] && s[i - 1] != s[i - 2] && s[i - 2] != s[i]) cnt++;

        return cnt;

}
```

This code counts the number of substrings of size 3 in the input string where all characters are distinct.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Initialization**
	```cpp
	int countGoodSubstrings(string s) {
	```
	Define a function to count substrings of size 3 with unique characters.

2. **Initialization**
	```cpp
	    int cnt = 0;
	```
	Initialize a counter to track the number of valid substrings.

3. **Loop**
	```cpp
	    for(int i = 2; i < s.size(); i++)
	```
	Iterate through the string starting from the third character.

4. **Condition**
	```cpp
	        if(s[i] != s[i - 1] && s[i - 1] != s[i - 2] && s[i - 2] != s[i]) cnt++;
	```
	Check if the current substring of size 3 has distinct characters; if yes, increment the counter.

5. **Return**
	```cpp
	        return cnt;
	```
	Return the total count of valid substrings after processing the string.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

We iterate through the string once and check each substring of length 3, which takes O(n) time.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as we only use a set to check the uniqueness of characters in each substring.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/description/)

---
{{< youtube QIyWjKNstAA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
