
+++
authors = ["grid47"]
title = "Leetcode 3110: Score of a String"
date = "2024-01-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3110: Score of a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "imbrLFL20tQ"
youtube_upload_date="2024-06-01"
youtube_thumbnail="https://i.ytimg.com/vi/imbrLFL20tQ/maxresdefault.jpg"
comments = true
+++



---
You are given a string s. The score of a string is defined as the sum of the absolute difference between the ASCII values of adjacent characters. Return the score of the string s.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string s of length n.
- **Example:** `s = "abc"`
- **Constraints:**
	- 2 <= s.length <= 100
	- s consists only of lowercase English letters

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the score of the string s.
- **Example:** `Output: 3`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the score of the string by summing the absolute differences between ASCII values of adjacent characters.

- 1. Initialize a variable to store the sum of absolute differences.
- 2. Loop through the string, comparing each pair of adjacent characters.
- 3. For each pair, compute the absolute difference in ASCII values and add it to the sum.
- 4. Return the total sum as the score.
{{< dots >}}
### Problem Assumptions ✅
- The input will always contain at least two characters.
- The string will only contain lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `s = "abc"`  \
  **Explanation:** The ASCII values of the characters are: 'a' = 97, 'b' = 98, 'c' = 99. The score is |97 - 98| + |98 - 99| = 3.

- **Input:** `s = "zyx"`  \
  **Explanation:** The ASCII values of the characters are: 'z' = 122, 'y' = 121, 'x' = 120. The score is |122 - 121| + |121 - 120| = 6.

{{< dots >}}
## Approach 🚀
To solve this problem, we can iterate through the string, calculate the absolute differences between ASCII values of adjacent characters, and sum them.

### Initial Thoughts 💭
- The problem asks for a simple iteration over the string and calculation of differences.
- By iterating through the string and summing the absolute differences of ASCII values, we can compute the score efficiently.
{{< dots >}}
### Edge Cases 🌐
- The input will always contain at least two characters, as per the constraints.
- The solution should efficiently handle strings of length up to 100 characters.
- When the string consists of repeated characters (e.g., "aaaa"), the score will be 0.
- The solution must handle strings of length between 2 and 100.
{{< dots >}}
## Code 💻
```cpp
int scoreOfString(string s) {
    int sum=0;
    for(int i=0;i<s.size()-1;i++){
        sum+=abs(s[i]-s[i+1]);
    }
    return sum;        
}
```

This function calculates the score of a string based on the absolute differences between each consecutive character's ASCII values.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int scoreOfString(string s) {
	```
	Defines the function `scoreOfString` that takes a string `s` and returns the total score as an integer. The score is calculated based on the absolute differences between consecutive characters.

2. **Variable Initialization**
	```cpp
	    int sum=0;
	```
	Initializes the variable `sum` to 0. This variable will hold the total score of the string as the absolute differences between consecutive characters are accumulated.

3. **For Loop Setup**
	```cpp
	    for(int i=0;i<s.size()-1;i++){
	```
	Starts a `for` loop that iterates through each character in the string `s`, except for the last character (since it's compared with the next one).

4. **Score Calculation**
	```cpp
	        sum+=abs(s[i]-s[i+1]);
	```
	For each consecutive pair of characters, calculates the absolute difference of their ASCII values using `abs(s[i] - s[i+1])`, and adds the result to `sum`.

5. **Return Statement**
	```cpp
	    return sum;        
	```
	Returns the final value of `sum`, which represents the total score of the string based on the absolute differences of consecutive characters.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the string. We need to iterate through the string once to calculate the score.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since we only use a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/score-of-a-string/description/)

---
{{< youtube imbrLFL20tQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
