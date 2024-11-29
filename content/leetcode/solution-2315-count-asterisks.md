
+++
authors = ["grid47"]
title = "Leetcode 2315: Count Asterisks"
date = "2024-03-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2315: Count Asterisks in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "tpgDi9Saq_s"
youtube_upload_date="2022-06-25"
youtube_thumbnail="https://i.ytimg.com/vi_webp/tpgDi9Saq_s/maxresdefault.webp"
comments = true
+++



---
You are given a string s, where every two consecutive vertical bars '|' form a pair. Count the number of '*' in s, excluding the '*' between each pair of '|'.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string s which contains lowercase English letters, vertical bars '|', and asterisks '*'.
- **Example:** `s = '|*a|*b*|c*|'`
- **Constraints:**
	- 1 <= s.length <= 1000
	- s contains only lowercase English letters, '|', and '*' characters.
	- s contains an even number of vertical bars '|'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of '*' characters in the string, excluding those between the vertical bars '|'.
- **Example:** `For s = '|*a|*b*|c*|', the output is 2.`
- **Constraints:**
	- Only '*' characters outside of the '|' pairs should be counted.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to iterate through the string and count the asterisks '*' outside the pairs of vertical bars '|'.

- 1. Traverse the string and track when you encounter a vertical bar '|'.
- 2. When a vertical bar is encountered, skip counting asterisks that appear between this bar and the next one.
- 3. Count the asterisks that are outside these pairs.
{{< dots >}}
### Problem Assumptions ✅
- The input string contains at least one vertical bar and may contain other characters, including asterisks.
{{< dots >}}
## Examples 🧩
- **Input:** `s = '|*a|*b*|c*|'`  \
  **Explanation:** In this example, asterisks inside the vertical bars are excluded. The valid asterisks are those outside the bars, which are counted to give a result of 2.

{{< dots >}}
## Approach 🚀
The approach involves traversing the string and counting the asterisks that are outside the paired vertical bars '|'.

### Initial Thoughts 💭
- We need to iterate over the string and keep track of whether we are inside a pair of vertical bars '|'.
- Each time we encounter a '|', we flip the sign to track whether we are inside a pair of bars, and count the asterisks outside.
{{< dots >}}
### Edge Cases 🌐
- The string will not be empty as per the problem constraints.
- Handle strings up to 1000 characters efficiently.
- Consider strings where there are no asterisks or where all asterisks are inside vertical bars.
- The string will always contain an even number of vertical bars.
{{< dots >}}
## Code 💻
```cpp
int countAsterisks(string s) {
    int res = 0, sign = 1;
    for (char& c : s)
        if ((sign ^= c == '|') && c == '*')
            res++;
    return res;
}
```

This function counts the number of asterisks '*' in a string `s` that are outside of vertical bars '|'. The function uses the XOR operator to toggle a 'sign' variable each time a vertical bar '|' is encountered, ensuring that asterisks are counted only when they are not enclosed by bars.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int countAsterisks(string s) {
	```
	Define the function `countAsterisks` which takes a string `s` and returns an integer representing the number of asterisks '*' in the string that are outside of vertical bars '|'.

2. **Variable Initialization**
	```cpp
	    int res = 0, sign = 1;
	```
	Initialize two variables: `res` to store the count of asterisks and `sign` to track whether we are inside or outside a vertical bar. The `sign` is toggled each time a '|' character is encountered.

3. **For Loop**
	```cpp
	    for (char& c : s)
	```
	Iterate through each character `c` in the string `s` using a range-based for loop.

4. **If Condition Check**
	```cpp
	        if ((sign ^= c == '|') && c == '*')
	```
	Check if the current character is an asterisk '*' and if the `sign` is toggled by encountering a '|' character. The XOR operation toggles `sign` whenever a '|' is found. If the character is '*' and `sign` is correctly positioned, the asterisk is counted.

5. **Increment Count**
	```cpp
	            res++;
	```
	If the condition is met (the character is '*' and not inside '|'), increment the `res` counter by 1.

6. **Return Statement**
	```cpp
	    return res;
	```
	Return the total count of asterisks outside the vertical bars, stored in the `res` variable.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the string, as we iterate through the string once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1), as we use a constant amount of extra space for tracking the result and sign.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-asterisks/description/)

---
{{< youtube tpgDi9Saq_s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
