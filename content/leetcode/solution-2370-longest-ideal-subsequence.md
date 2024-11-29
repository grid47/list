
+++
authors = ["grid47"]
title = "Leetcode 2370: Longest Ideal Subsequence"
date = "2024-03-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2370: Longest Ideal Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "gR1E2oLQYSY"
youtube_upload_date="2024-04-25"
youtube_thumbnail="https://i.ytimg.com/vi/gR1E2oLQYSY/maxresdefault.jpg"
comments = true
+++



---
You are given a string s consisting of lowercase letters and an integer k. A string t is considered ideal if it is a subsequence of s and the absolute difference in the alphabet order of every two adjacent letters in t is less than or equal to k. Your task is to return the length of the longest ideal string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string s and an integer k.
- **Example:** `s = "azbcde", k = 3`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- 0 <= k <= 25
	- s consists of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the longest ideal string that satisfies the given conditions.
- **Example:** `Output: 4`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the longest subsequence that satisfies the condition on the absolute difference between adjacent characters.

- 1. Use dynamic programming to track the length of the longest ideal string that can be formed ending at each character.
- 2. For each character in the string, check for possible valid subsequences by considering the character itself and the preceding ones within a range defined by k.
- 3. Keep updating the maximum length of the ideal subsequence found.
{{< dots >}}
### Problem Assumptions ✅
- The string is non-empty and consists only of lowercase English letters.
- The value of k is valid, i.e., between 0 and 25.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = "azbcde", k = 3`  \
  **Explanation:** In this case, the longest ideal string is "abc", with a length of 3. The absolute difference between adjacent characters is within the given range of k = 3.

- **Input:** `Input: s = "abc", k = 2`  \
  **Explanation:** The longest ideal string is "abc", with a length of 3. The absolute difference between adjacent characters is within the given range of k = 2.

{{< dots >}}
## Approach 🚀
The problem can be solved using dynamic programming to track the longest ideal subsequence and check if adjacent characters meet the condition.

### Initial Thoughts 💭
- The problem can be broken down into tracking the longest subsequence at each index.
- We need to check the possible subsequences by comparing each character with those that came before it.
- Dynamic programming will allow us to efficiently compute the longest subsequence by building up from smaller subsequences.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs as the string s is guaranteed to have at least one character.
- For large inputs, ensure that the dynamic programming approach performs efficiently within the given constraints.
- Special cases might include strings where all characters are the same, or where no valid subsequences can be formed.
- Ensure that the solution handles strings of maximum length (10^5) efficiently.
{{< dots >}}
## Code 💻
```cpp
int longestIdealString(string s, int k) {
    int dp[150] = {}, res = 0;
    for(auto &i: s) {
        for(int j = i - k; j <= i + k; j++)
            dp[i] = max(dp[i], dp[j]);
        res = max(res, ++dp[i]);
    }
    return res;
}
```

This function calculates the length of the longest ideal string that can be formed with the given conditions. It uses dynamic programming (dp) to track the maximum subsequence lengths that adhere to the ideal string constraints.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int longestIdealString(string s, int k) {
	```
	Function definition for finding the longest ideal string. It accepts a string `s` and an integer `k` as input.

2. **Variable Initialization**
	```cpp
	    int dp[150] = {}, res = 0;
	```
	Initializes a dynamic programming array `dp` of size 150 to store the longest subsequence lengths, and a variable `res` to track the maximum length found.

3. **Loop Through String**
	```cpp
	    for(auto &i: s) {
	```
	Iterates through each character `i` in the input string `s`.

4. **Inner Loop**
	```cpp
	        for(int j = i - k; j <= i + k; j++)
	```
	An inner loop that checks possible characters within a range of `k` difference from the current character `i`.

5. **DP Update**
	```cpp
	            dp[i] = max(dp[i], dp[j]);
	```
	Updates the dp value for character `i` by considering the maximum subsequence length that can be formed by including `j`.

6. **Result Update**
	```cpp
	        res = max(res, ++dp[i]);
	```
	Updates the result `res` by considering the longest subsequence formed by the current character `i`.

7. **Return Statement**
	```cpp
	    return res;
	```
	Returns the maximum subsequence length found, which is the length of the longest ideal string.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the string, as we perform a linear scan of the string and update the dp array.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(1)

The space complexity is O(n), as we store the dp array to track the longest ideal subsequence.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-ideal-subsequence/description/)

---
{{< youtube gR1E2oLQYSY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
