
+++
authors = ["grid47"]
title = "Leetcode 516: Longest Palindromic Subsequence"
date = "2024-09-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 516: Longest Palindromic Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/516.webp"
youtube = "v6Ous7ofbMs"
youtube_upload_date="2023-04-15"
youtube_thumbnail="https://i.ytimg.com/vi/v6Ous7ofbMs/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/516.webp" 
    alt="A string where the longest palindromic subsequence is highlighted, glowing as it mirrors itself."
    caption="Solution to LeetCode 516: Longest Palindromic Subsequence Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a string `s`, return the length of the longest palindromic subsequence in `s`. A subsequence is a sequence derived by deleting some or no elements without changing the order of the remaining elements.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a string `s` consisting of lowercase English letters.
- **Example:** `s = "aabca"`
- **Constraints:**
	- 1 <= s.length <= 1000
	- s consists only of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an integer representing the length of the longest palindromic subsequence in `s`.
- **Example:** `3`
- **Constraints:**
	- The output should be a single integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the length of the longest subsequence in `s` that is a palindrome.

- 1. Use dynamic programming to store intermediate results.
- 2. For each pair of indices `i` and `j`, check if the characters match.
- 3. If the characters match, consider the longest subsequence between `i+1` and `j-1`, and add 2.
- 4. If the characters don't match, take the maximum value between `dp(i + 1, j)` and `dp(i, j - 1)`. 
{{< dots >}}
### Problem Assumptions ✅
- The string `s` is not empty unless specified.
- The input string contains only lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `s = "aabca"`  \
  **Explanation:** The longest palindromic subsequence in the string 'aabca' is 'aba', which has a length of 3.

- **Input:** `s = "abcde"`  \
  **Explanation:** Since no characters repeat, the longest palindromic subsequence is any single character, with a length of 1.

{{< dots >}}
## Approach 🚀
The approach uses dynamic programming to calculate the longest palindromic subsequence.

### Initial Thoughts 💭
- Dynamic programming is an effective way to store and reuse previously computed results.
- The solution needs to compare characters from the string and compute intermediate results for subsequences.
- We can use a table to store the lengths of palindromic subsequences for different indices in the string.
{{< dots >}}
### Edge Cases 🌐
- If the string is empty, the longest palindromic subsequence length is 0.
- The algorithm should efficiently handle strings with lengths up to 1000 characters.
- If all characters in the string are the same, the entire string is a palindrome.
- The string length should be between 1 and 1000.
{{< dots >}}
## Code 💻
```cpp
string str;
vector<vector<int>> memo;
int dp(int i, int j) {
    if(i == j) return 1;
    if(i == j - 1) return str[i] == str[j]? 2: 1;
    
    if(memo[i][j] != -1) return memo[i][j];
    
    int ans = 0;
    if(str[i] == str[j]) {
        ans = 2 + dp(i + 1, j - 1);
    } else {
        ans = max(dp(i + 1, j), dp(i, j - 1));
    }
    return memo[i][j] = ans;
}

int longestPalindromeSubseq(string s) {
    str = s;
    int n = s.size();
    memo.resize(n, vector<int>(n, -1));
    return dp(0, n - 1);
}
```

This function computes the length of the longest palindromic subsequence in a given string using dynamic programming. It recursively calculates the longest subsequence by considering both matching and non-matching characters at each position.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **String Initialization**
	```cpp
	string str;
	```
	Declares a string variable `str` that will store the input string for the longest palindromic subsequence problem.

2. **Memoization Table Initialization**
	```cpp
	vector<vector<int>> memo;
	```
	Declares a 2D vector `memo` to store the intermediate results of subproblems. This table will help avoid redundant calculations by storing already computed values.

3. **Recursive Function Definition**
	```cpp
	int dp(int i, int j) {
	```
	Defines the recursive function `dp`, which takes two indices `i` and `j` and returns the length of the longest palindromic subsequence between the substring `str[i...j]`.

4. **Base Case 1**
	```cpp
	    if(i == j) return 1;
	```
	Base case: If the indices `i` and `j` point to the same character, the longest palindromic subsequence has length 1.

5. **Base Case 2**
	```cpp
	    if(i == j - 1) return str[i] == str[j]? 2: 1;
	```
	Base case: If `i` and `j` are adjacent characters, the longest palindromic subsequence is 2 if the characters match, otherwise it is 1.

6. **Memoization Check**
	```cpp
	    if(memo[i][j] != -1) return memo[i][j];
	```
	Checks if the result for the substring `str[i...j]` has already been computed and stored in the `memo` table. If yes, returns the cached result.

7. **Recursive Calculation Initialization**
	```cpp
	    int ans = 0;
	```
	Initializes a variable `ans` to store the result of the longest palindromic subsequence for the current substring `str[i...j]`.

8. **Matching Characters Case**
	```cpp
	    if(str[i] == str[j]) {
	```
	Checks if the characters at indices `i` and `j` are equal. If they are, the subsequence can be extended by 2, along with the result of the remaining substring.

9. **Recursive Call for Matching Characters**
	```cpp
	        ans = 2 + dp(i + 1, j - 1);
	```
	If the characters match, the longest palindromic subsequence increases by 2 (including the matching characters), and the recursive function is called for the substring `str[i+1...j-1]`.

10. **Non-Matching Characters Case**
	```cpp
	    } else {
	```
	Handles the case where the characters at indices `i` and `j` do not match.

11. **Recursive Call for Non-Matching Characters**
	```cpp
	        ans = max(dp(i + 1, j), dp(i, j - 1));
	```
	If the characters do not match, the longest palindromic subsequence is the maximum of the results of the two possible substrings: `str[i+1...j]` and `str[i...j-1]`.

12. **Memoization Step**
	```cpp
	    return memo[i][j] = ans;
	```
	Stores the computed result `ans` in the `memo` table to reuse it in future calls.

13. **Main Function Definition**
	```cpp
	int longestPalindromeSubseq(string s) {
	```
	Defines the main function `longestPalindromeSubseq`, which takes the input string `s` and returns the length of the longest palindromic subsequence.

14. **Assign Input String**
	```cpp
	    str = s;
	```
	Assigns the input string `s` to the global string `str` used in the recursive function.

15. **Initialize Memoization Table**
	```cpp
	    int n = s.size();
	```
	Calculates the length `n` of the input string `s`.

16. **Resize Memoization Table**
	```cpp
	    memo.resize(n, vector<int>(n, -1));
	```
	Resizes the `memo` table to store results for all substrings of length `n`. Initially, all values are set to `-1`, indicating that they have not been computed yet.

17. **Final Recursive Call**
	```cpp
	    return dp(0, n - 1);
	```
	Makes the first call to the `dp` function to compute the longest palindromic subsequence for the entire string `s`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is O(n^2) due to the need to compute all pairs of indices in the string.

### Space Complexity 💾
- **Best Case:** O(n^2)
- **Worst Case:** O(n^2)

The space complexity is O(n^2) due to the storage of the dynamic programming table.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-palindromic-subsequence/description/)

---
{{< youtube v6Ous7ofbMs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
