
+++
authors = ["grid47"]
title = "Leetcode 97: Interleaving String"
date = "2024-10-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 97: Interleaving String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/97.webp"
youtube = "3Rw3p9LrgvE"
youtube_upload_date="2021-06-22"
youtube_thumbnail="https://i.ytimg.com/vi/3Rw3p9LrgvE/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/97.webp" 
    alt="Two glowing strings weaving together in an intricate, peaceful interleaving pattern."
    caption="Solution to LeetCode 97: Interleaving String Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given three strings s1, s2, and s3, determine whether s3 can be formed by interleaving s1 and s2. An interleaving is a way of combining s1 and s2 such that the characters of s1 and s2 maintain their relative order in the final string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given three strings s1, s2, and s3.
- **Example:** `Input: s1 = 'abc', s2 = 'def', s3 = 'adbcef'`
- **Constraints:**
	- 0 <= s1.length, s2.length <= 100
	- 0 <= s3.length <= 200
	- s1, s2, and s3 consist of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if s3 is formed by interleaving s1 and s2. Otherwise, return false.
- **Example:** `Output: true`
- **Constraints:**
	- Return true if s3 is an interleaving of s1 and s2, otherwise false.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if s3 can be formed by interleaving s1 and s2 while maintaining the relative order of characters in both strings.

- Start from the beginning of s1, s2, and s3.
- Check if the current character of s1 or s2 matches the current character of s3.
- Recursively verify the remaining characters in s1 and s2 to see if they can form the rest of s3.
{{< dots >}}
### Problem Assumptions ✅
- The input strings s1, s2, and s3 are valid and follow the given constraints.
- The function should efficiently handle the interleaving check for strings with lengths up to the maximum limits.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s1 = 'abc', s2 = 'def', s3 = 'adbcef'`  \
  **Explanation:** In this case, s3 is an interleaving of s1 and s2 because we can alternate characters from s1 and s2 while maintaining their order to form s3.

- **Input:** `Input: s1 = 'abc', s2 = 'def', s3 = 'abcdef'`  \
  **Explanation:** In this case, it is not possible to form s3 by interleaving s1 and s2, as the characters from s2 need to maintain their order after s1's characters.

{{< dots >}}
## Approach 🚀
The approach uses dynamic programming to check if s3 can be formed by interleaving s1 and s2 while preserving their order. A 2D table is used to store intermediate results, which helps in efficiently checking all combinations.

### Initial Thoughts 💭
- Both s1 and s2 must be used entirely to form s3.
- We need to check the characters from both s1 and s2 one by one to form s3, while preserving their order.
- We can use dynamic programming to break down the problem into smaller subproblems, checking whether each prefix of s1 and s2 can form a corresponding prefix of s3.
{{< dots >}}
### Edge Cases 🌐
- If all strings are empty (s1 = '', s2 = '', s3 = ''), the answer is true.
- When the lengths of s1 and s2 are near the upper limit (100), the algorithm should handle it efficiently using dynamic programming.
- If s1 or s2 is empty, the solution depends solely on whether s3 matches the other string.
- Ensure the solution works within the provided constraints (maximum length of 100 for s1 and s2, 200 for s3).
{{< dots >}}
## Code 💻
```cpp
string s1, s2, s3;
vector<vector<int>> memo;
bool dp(int i, int j) {
    if(i == s1.size() && j == s2.size()) return true;

    if(memo[i][j] != -1) return memo[i][j];
    int ans = 0;
    int k = i + j;
    if(i < s1.size() && s1[i] == s3[k])
        ans |= dp(i + 1, j);
    
    if(j < s2.size() && s2[j] == s3[k])
        ans |= dp(i, j + 1);
    
    return memo[i][j] = ans;
}

bool isInterleave(string s1, string s2, string s3) {
    this->s1 = s1;
    this->s2 = s2;
    this->s3 = s3;
    if(s1.size() + s2.size() != s3.size()) return false;
    memo.resize(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    return dp(0, 0);
}
```

This code determines if a string s3 is an interleaving of two other strings s1 and s2 using a dynamic programming approach.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	string s1, s2, s3;
	```
	Declares three string variables to store the input strings.

2. **Array Initialization**
	```cpp
	vector<vector<int>> memo;
	```
	Initializes a 2D vector `memo` to store the results of subproblems, using memoization to avoid redundant calculations.

3. **Function Declaration**
	```cpp
	bool dp(int i, int j) {
	```
	Declares a recursive function `dp` to check if the substring `s1[i:]` and `s2[j:]` can interleave to form `s3[i+j:]`.

4. **Base Case**
	```cpp
	    if(i == s1.size() && j == s2.size()) return true;
	```
	If we've reached the end of both `s1` and `s2`, it means we've successfully interleaved them, so return `true`.

5. **Memoization**
	```cpp
	    if(memo[i][j] != -1) return memo[i][j];
	```
	Checks if the result for the current `i` and `j` is already stored in the memoization table. If so, return the stored value.

6. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	Initializes a variable `ans` to store the result of the current subproblem.

7. **Calculation**
	```cpp
	    int k = i + j;
	```
	Calculates the index `k` in `s3` corresponding to the current positions in `s1` and `s2`.

8. **Conditional Check**
	```cpp
	    if(i < s1.size() && s1[i] == s3[k])
	```
	Checks if the current character in `s1` matches the corresponding character in `s3`.

9. **Recursive Call**
	```cpp
	        ans |= dp(i + 1, j);
	```
	Recursively checks if the remaining substrings of `s1` and `s2` can interleave to form the remaining part of `s3`.

10. **Conditional Check**
	```cpp
	    if(j < s2.size() && s2[j] == s3[k])
	```
	Checks if the current character in `s2` matches the corresponding character in `s3`.

11. **Recursive Call**
	```cpp
	        ans |= dp(i, j + 1);
	```
	Recursively checks if the remaining substrings of `s1` and `s2` can interleave to form the remaining part of `s3`.

12. **Memoization Update**
	```cpp
	    return memo[i][j] = ans;
	```
	Stores the result of the current subproblem in the memoization table and returns it.

13. **Variable Assignment**
	```cpp
	    this->s1 = s1;
	```
	Assigns the input string `s1` to the class member variable `s1`.

14. **Variable Assignment**
	```cpp
	    this->s2 = s2;
	```
	Assigns the input string `s2` to the class member variable `s2`.

15. **Variable Assignment**
	```cpp
	    this->s3 = s3;
	```
	Assigns the input string `s3` to the class member variable `s3`.

16. **Condition Check**
	```cpp
	    if(s1.size() + s2.size() != s3.size()) return false;
	```
	Checks if the sum of lengths of `s1` and `s2` is equal to the length of `s3`. If not, it's impossible to interleave, so return `false`.

17. **Array Initialization**
	```cpp
	    memo.resize(s1.size() + 1, vector<int>(s2.size() + 1, -1));
	```
	Resizes the `memo` vector to store results for all possible substrings of `s1` and `s2`.

18. **Function Call**
	```cpp
	    return dp(0, 0);
	```
	Calls the `dp` function to check if the entire `s1` and `s2` can interleave to form `s3`, starting from the beginning of each string.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * m)
- **Average Case:** O(n * m)
- **Worst Case:** O(n * m)

Where n is the length of s1 and m is the length of s2. The worst-case time complexity occurs when we need to fill the entire memo table.

### Space Complexity 💾
- **Best Case:** O(n * m)
- **Worst Case:** O(n * m)

The space complexity is O(n * m) due to the memo table storing the results for subproblems.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/interleaving-string/description/)

---
{{< youtube 3Rw3p9LrgvE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
