
+++
authors = ["grid47"]
title = "Leetcode 2767: Partition String Into Minimum Beautiful Substrings"
date = "2024-02-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2767: Partition String Into Minimum Beautiful Substrings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Dynamic Programming","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "xV-TA-TtiAg"
youtube_upload_date="2023-07-08"
youtube_thumbnail="https://i.ytimg.com/vi/xV-TA-TtiAg/maxresdefault.jpg"
comments = true
+++



---
Given a binary string 's', partition it into substrings such that each substring represents a power of 5 in binary form and does not contain leading zeros. Return the minimum number of such partitions, or -1 if impossible.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single binary string 's'.
- **Example:** `Input: s = '1101'`
- **Constraints:**
	- 1 <= s.length <= 15
	- s[i] is either '0' or '1'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of partitions such that each substring meets the specified criteria. If no valid partition exists, return -1.
- **Example:** `Output: 2 for Input: s = '1101'`
- **Constraints:**
	- Output must be an integer, representing the minimum number of partitions or -1 if invalid.

{{< dots >}}
### Core Logic 🔍
**Goal:** To minimize the number of substrings while ensuring each substring represents a power of 5 and does not have leading zeros.

- Iterate through the binary string and check all possible substrings.
- For each substring, check if it is a valid binary representation of a power of 5.
- Use dynamic programming to track the minimum partitions for each prefix of the string.
{{< dots >}}
### Problem Assumptions ✅
- All substrings must represent numbers greater than zero.
- Leading zeros in substrings invalidate them.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = '1101'`  \
  **Explanation:** The string can be split into ['110', '1'], where both parts are valid binary representations of powers of 5.

- **Input:** `Input: s = '0001'`  \
  **Explanation:** The string cannot be partitioned into valid substrings as all parts have leading zeros.

{{< dots >}}
## Approach 🚀
Dynamic programming approach to minimize partitions while validating binary substrings as powers of 5.

### Initial Thoughts 💭
- Binary strings can be parsed into integers to check if they are powers of 5.
- Leading zeros are invalid, so such substrings are not considered.
- Dynamic programming can efficiently find the minimum number of valid partitions.
{{< dots >}}
### Edge Cases 🌐
- The constraints ensure the input string is not empty.
- The maximum length of the string is 15, so edge cases with maximum length must be handled efficiently.
- Strings with only zeros ('0000') or invalid patterns should return -1.
- The binary string must be partitioned into contiguous, valid substrings.
{{< dots >}}
## Code 💻
```cpp
    int minimumBeautifulSubstrings(string s) {
    int n = s.length();
    vector<int> dp(n + 1, n + 1);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') continue;
        for (int j = i, cur = 0; j < n; j++) {
            cur = cur * 2 + s[j] - '0';
            if (15625 % cur == 0)
                dp[j + 1] = min(dp[j + 1], dp[i] + 1);
        }
    }
    return dp[n] > n ? -1 : dp[n];
}
```

This function calculates the minimum number of beautiful substrings (binary substrings divisible by 15625). It uses dynamic programming to track the minimum number of splits needed to form these substrings.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	    int minimumBeautifulSubstrings(string s) {
	```
	Defines the function `minimumBeautifulSubstrings`, which takes a binary string `s` and returns the minimum number of beautiful substrings or `-1` if it's impossible.

2. **Calculate String Length**
	```cpp
	    int n = s.length();
	```
	Calculates the length of the input string `s` and stores it in the variable `n`.

3. **Initialize DP Array**
	```cpp
	    vector<int> dp(n + 1, n + 1);
	```
	Initializes a dynamic programming (DP) array `dp` of size `n + 1` where each entry represents the minimum number of beautiful substrings up to that position in the string. Initially, all values are set to `n + 1`.

4. **Base Case**
	```cpp
	    dp[0] = 0;
	```
	Sets the base case: `dp[0]` is 0, indicating no substrings are needed for an empty string.

5. **Iterate Over String**
	```cpp
	    for (int i = 0; i < n; i++) {
	```
	Starts a loop to iterate over each character in the input string `s`.

6. **Skip Zeros**
	```cpp
	        if (s[i] == '0') continue;
	```
	If the current character is '0', skips the rest of the loop and moves to the next character.

7. **Inner Loop**
	```cpp
	        for (int j = i, cur = 0; j < n; j++) {
	```
	Starts an inner loop to iterate from the current position `i` to the end of the string, calculating the binary value of the substring starting at `i`.

8. **Update Current Value**
	```cpp
	            cur = cur * 2 + s[j] - '0';
	```
	Updates the current binary value `cur` by shifting it left by one bit (multiply by 2) and adding the current character (`s[j]`) to it. The subtraction of `'0'` converts the character to its integer value (0 or 1).

9. **Check Divisibility**
	```cpp
	            if (15625 % cur == 0)
	```
	Checks if the current binary value `cur` is divisible by 15625 (the divisor for beautiful substrings).

10. **Update DP Array**
	```cpp
	                dp[j + 1] = min(dp[j + 1], dp[i] + 1);
	```
	If the current binary value is divisible by 15625, updates the DP array at index `j + 1` to reflect the minimum number of beautiful substrings by adding 1 to the DP value at index `i`.

11. **Return Result**
	```cpp
	    return dp[n] > n ? -1 : dp[n];
	```
	Returns the minimum number of beautiful substrings, which is stored in `dp[n]`. If no valid result is found (i.e., `dp[n]` is greater than `n`), it returns `-1`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

Iterating through substrings and checking validity contributes to the quadratic complexity.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

Space complexity is dominated by the dp array storing results for substrings.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/partition-string-into-minimum-beautiful-substrings/description/)

---
{{< youtube xV-TA-TtiAg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
