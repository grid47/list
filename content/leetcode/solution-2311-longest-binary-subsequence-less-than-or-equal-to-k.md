
+++
authors = ["grid47"]
title = "Leetcode 2311: Longest Binary Subsequence Less Than or Equal to K"
date = "2024-03-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2311: Longest Binary Subsequence Less Than or Equal to K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Greedy","Memoization"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "xgpPuMjET9c"
youtube_upload_date="2022-06-19"
youtube_thumbnail="https://i.ytimg.com/vi/xgpPuMjET9c/maxresdefault.jpg"
comments = true
+++



---
You are given a binary string s and a positive integer k. Your task is to find the length of the longest subsequence of s that represents a binary number less than or equal to k when converted to decimal.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary string s and an integer k.
- **Example:** `s = '1101011', k = 6`
- **Constraints:**
	- 1 <= s.length <= 1000
	- 1 <= k <= 10^9
	- s[i] is either '0' or '1'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the longest subsequence of s that forms a binary number less than or equal to k.
- **Example:** `For s = '1101011', k = 6, the output is 5.`
- **Constraints:**
	- The subsequence should form a binary number less than or equal to k.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the longest subsequence of binary digits that represents a number less than or equal to k.

- Start from the rightmost character in the string and traverse towards the left.
- Maintain a running total of the binary number formed and the length of the subsequence.
- For each '1', add its value to the running total and increment the subsequence length if the number is still less than or equal to k.
- Include all the '0's in the subsequence as they don't affect the binary value.
- Stop when you can no longer include '1's without exceeding k.
{{< dots >}}
### Problem Assumptions ✅
- The input string contains only '0's and '1's.
{{< dots >}}
## Examples 🧩
- **Input:** `s = '1101011', k = 6`  \
  **Explanation:** The longest subsequence of s that forms a binary number less than or equal to 6 is '00010', which is 2 in decimal. The length of the subsequence is 5.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to find the longest subsequence of binary digits that does not exceed the value of k when converted to decimal.

### Initial Thoughts 💭
- We need to track both the length of the subsequence and the value of the binary number formed as we traverse the string.
- Starting from the least significant bit (rightmost), we can check whether adding the current '1' keeps the number within bounds.
{{< dots >}}
### Edge Cases 🌐
- The string will never be empty as per the problem constraints.
- Handle inputs of up to 1000 characters efficiently.
- If k is very large, ensure that we don't exceed it by adding bits.
- Ensure that the subsequence's value does not exceed k.
{{< dots >}}
## Code 💻
```cpp
int longestSubsequence(string s, int k) {
    int val = 0, cnt = 0, pow = 1;
    for(int i = s.size() - 1; i >= 0 && val + pow <= k; i--) {
        if(s[i] == '1') {
            ++cnt;
            val += pow;
        }
        pow <<= 1;
    }
    return count(s.begin(), s.end(), '0') + cnt;  
}
```

This function calculates the length of the longest subsequence of binary digits that, when interpreted as a binary number, is less than or equal to a given value `k`. The function counts the number of zeros and the number of selected ones from the string.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int longestSubsequence(string s, int k) {
	```
	Define the function `longestSubsequence` which takes a binary string `s` and an integer `k` as input. The function returns an integer representing the length of the longest subsequence whose binary value is less than or equal to `k`.

2. **Variable Initialization**
	```cpp
	    int val = 0, cnt = 0, pow = 1;
	```
	Initialize three variables: `val` to store the current value of the selected binary digits, `cnt` to count the number of selected '1' digits, and `pow` to represent the current power of 2 for the binary number.

3. **For Loop**
	```cpp
	    for(int i = s.size() - 1; i >= 0 && val + pow <= k; i--) {
	```
	Start a loop from the last character of the string `s` and move towards the beginning. Continue the loop as long as the current value `val` plus the next power of 2 does not exceed `k`.

4. **If Condition Check**
	```cpp
	        if(s[i] == '1') {
	```
	Check if the current character in the string is '1'. If it is, include this '1' in the subsequence.

5. **Increment Count**
	```cpp
	            ++cnt;
	```
	Increment the counter `cnt` to account for the '1' that is selected as part of the subsequence.

6. **Update Value**
	```cpp
	            val += pow;
	```
	Add the current power of 2 (`pow`) to the value `val` to update the total value of the subsequence.

7. **Shift Power of 2**
	```cpp
	        pow <<= 1;
	```
	Shift the power of 2 (`pow`) left by 1 (equivalent to multiplying by 2) to account for the next bit in the binary number.

8. **Return Statement**
	```cpp
	    return count(s.begin(), s.end(), '0') + cnt;  
	```
	Return the sum of the count of '0' characters in the string `s` (using `count` function) and the count of '1' characters that were selected for the subsequence.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where n is the length of the string, as we traverse the string once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we only use a constant amount of space to store the binary number value and subsequence length.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/description/)

---
{{< youtube xgpPuMjET9c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
