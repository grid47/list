
+++
authors = ["grid47"]
title = "Leetcode 1234: Replace the Substring for Balanced String"
date = "2024-07-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1234: Replace the Substring for Balanced String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Sliding Window"]
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
You are given a string containing only four kinds of characters: 'Q', 'W', 'E', and 'R'. The string is balanced if each character appears exactly n/4 times, where n is the length of the string. The task is to find the minimum length of a substring that can be replaced to make the string balanced.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a string 's' of length n (where n is a multiple of 4) containing only characters 'Q', 'W', 'E', and 'R'.
- **Example:** `s = 'QQWE'`
- **Constraints:**
	- 4 <= n <= 10^5
	- n is a multiple of 4
	- s contains only 'Q', 'W', 'E', and 'R'

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer representing the minimum length of the substring that can be replaced to make the string balanced.
- **Example:** `1`
- **Constraints:**
	- The output should be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the minimum length of a substring that can be replaced to balance the string.

- Count the occurrences of each character in the string.
- If the string is already balanced, return 0.
- Use a sliding window to find the smallest substring that, when replaced, will balance the string.
{{< dots >}}
### Problem Assumptions ✅
- The input string is always valid, containing only 'Q', 'W', 'E', and 'R'.
- The length of the string is a multiple of 4.
{{< dots >}}
## Examples 🧩
- **Input:** `s = 'QQWE'`  \
  **Explanation:** The string has 2 'Q's and 1 each of 'W' and 'E'. To balance the string, we can replace one 'Q' with 'R'. The result is 1.

- **Input:** `s = 'QQQW'`  \
  **Explanation:** The string has 3 'Q's and 1 'W'. To balance the string, we can replace two 'Q's with 'E' and 'R'. The result is 2.

{{< dots >}}
## Approach 🚀
The approach involves counting the occurrences of each character and then using a sliding window to find the smallest substring that can be replaced to balance the string.

### Initial Thoughts 💭
- The string should be balanced when each character appears exactly n/4 times.
- We can use a sliding window approach to efficiently solve the problem.
- We should track the number of each character and adjust the window until the string becomes balanced.
{{< dots >}}
### Edge Cases 🌐
- Not applicable, as the input will always have at least 4 characters.
- Ensure that the solution works efficiently with strings of length up to 10^5.
- Consider cases where the string is already balanced.
- The string is guaranteed to be of length a multiple of 4.
{{< dots >}}
## Code 💻
```cpp
int balancedString(string s) {
    map<char, int> ma;
    for(int i = 0; i < s.size(); i++) {
        ma[s[i]]++;
    }
    int k = s.size() / 4, j = 0, res = s.size();
    for(int i = 0; i < s.size(); i++) {
        ma[s[i]]--;
    while(j < s.size() && ma['Q'] <= k && ma['W'] <= k && ma['E'] <= k && ma['R'] <= k) {
            ma[s[j]]++;
            res = min(res, i - j + 1);
            j++;
        }
    }
    return res;
}
```

This function aims to find the length of the minimum substring that needs to be replaced to balance the frequencies of 'Q', 'W', 'E', and 'R' in the given string `s`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int balancedString(string s) {
	```
	This is the function definition for `balancedString`, which takes a string `s` and returns the length of the minimum substring that must be replaced to balance the characters 'Q', 'W', 'E', and 'R'.

2. **Variable Initialization**
	```cpp
	    map<char, int> ma;
	```
	A map `ma` is initialized to store the frequency of each character in the string `s`.

3. **Character Frequency Count**
	```cpp
	    for(int i = 0; i < s.size(); i++) {
	```
	A loop is started to iterate through the string `s`.

4. **Updating Character Count**
	```cpp
	        ma[s[i]]++;
	```
	For each character in the string `s`, its frequency is incremented in the map `ma`.

5. **Calculation of Target Frequency**
	```cpp
	    int k = s.size() / 4, j = 0, res = s.size();
	```
	The target frequency for each character is calculated as `k = s.size() / 4`, assuming the balanced string will have equal frequencies for 'Q', 'W', 'E', and 'R'. The variables `j` (start of the sliding window) and `res` (minimum length of substring) are also initialized.

6. **Iterating Over String**
	```cpp
	    for(int i = 0; i < s.size(); i++) {
	```
	A loop is started to iterate through the string `s` again, this time for checking the sliding window of characters.

7. **Decreasing Character Count**
	```cpp
	        ma[s[i]]--;
	```
	The frequency of the character at position `i` in the string is decremented in the map `ma` as part of the sliding window process.

8. **Sliding Window Check**
	```cpp
	    while(j < s.size() && ma['Q'] <= k && ma['W'] <= k && ma['E'] <= k && ma['R'] <= k) {
	```
	A while loop is used to check if all character frequencies ('Q', 'W', 'E', 'R') are less than or equal to the target frequency `k`. If true, the window is valid.

9. **Updating Frequency and Result**
	```cpp
	            ma[s[j]]++;
	```
	The character at position `j` is added back to the map `ma` as part of the sliding window.

10. **Updating Minimum Result**
	```cpp
	            res = min(res, i - j + 1);
	```
	The variable `res` is updated to the minimum of its current value and the length of the current valid window `i - j + 1`.

11. **Incrementing Window Start**
	```cpp
	            j++;
	```
	The starting point of the sliding window, `j`, is incremented to shrink the window.

12. **Return Result**
	```cpp
	    return res;
	```
	The function returns the value of `res`, which is the length of the minimum substring that needs to be replaced to balance the characters 'Q', 'W', 'E', and 'R'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution iterates through the string a few times, making it linear in complexity.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, as we only need a few variables to track character counts.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/replace-the-substring-for-balanced-string/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
