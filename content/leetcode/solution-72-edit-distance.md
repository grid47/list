
+++
authors = ["grid47"]
title = "Leetcode 72: Edit Distance"
date = "2024-10-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 72: Edit Distance in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/72.webp"
youtube = "XYi2-LPrwm4"
youtube_upload_date="2021-05-08"
youtube_thumbnail="https://i.ytimg.com/vi/XYi2-LPrwm4/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/72.webp" 
    alt="Two strings gently transforming into one another, symbolizing subtle edits."
    caption="Solution to LeetCode 72: Edit Distance Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given two strings str1 and str2, your task is to determine the minimum number of operations required to transform str1 into str2. The allowed operations are: Insert a character, Delete a character, and Replace a character.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two strings str1 and str2.
- **Example:** `str1 = 'kitten', str2 = 'sitting'`
- **Constraints:**
	- 0 <= str1.length, str2.length <= 500
	- str1 and str2 consist of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of operations needed to transform str1 into str2.
- **Example:** `3`
- **Constraints:**
	- The output should be a single integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the minimum number of operations needed.

- Use dynamic programming to store the results of subproblems.
- For each pair of indices (i, j), consider the operations: insert, delete, or replace.
- Build the solution iteratively using the recurrence relation.
{{< dots >}}
### Problem Assumptions ✅
- The input strings are non-empty.
- Both strings contain only lowercase alphabets.
{{< dots >}}
## Examples 🧩
- **Input:** `str1 = 'kitten', str2 = 'sitting'`  \
  **Explanation:** We need 3 operations to convert 'kitten' into 'sitting': 1) Replace 'k' with 's', 2) Replace 'e' with 'i', 3) Insert 'g'.

- **Input:** `str1 = 'flaw', str2 = 'lawn'`  \
  **Explanation:** We need 2 operations to convert 'flaw' into 'lawn': 1) Remove 'f', 2) Insert 'n'.

{{< dots >}}
## Approach 🚀
The problem can be solved using dynamic programming, where we calculate the minimum number of operations to transform substrings of str1 into substrings of str2.

### Initial Thoughts 💭
- The problem can be broken down into smaller subproblems.
- We can use dynamic programming to solve this efficiently.
- Use a 2D array to store intermediate results.
{{< dots >}}
### Edge Cases 🌐
- If either str1 or str2 is empty, the minimum operations are the length of the other string.
- Handle the case when both strings are of maximum length (500).
- Consider cases where str1 and str2 are already equal, in which case the answer is 0.
- Ensure the solution is optimized for the problem's constraints.
{{< dots >}}
## Code 💻
```cpp
string a, b;
vector<vector<int>> memo;

int dp(int i, int j) {
    if(i == a.size() && j == b.size()) return 0;
    if(i == a.size()) return b.size() - j;
    if(j == b.size()) return a.size() - i;
    if(memo[i][j] != -1) return memo[i][j];
    int ans = 0;
    if(a[i] != b[j]) {
        ans = min({dp(i+1,j), dp(i,j+1), dp(i+1,j+1)}) + 1;
    } else {
        ans = dp(i + 1, j+ 1);
    }
    return memo[i][j] = ans;
}

int minDistance(string word1, string word2) {
    this->a = word1;
    this->b = word2;
    memo.resize(a.size(), vector<int>(b.size(), -1));
    return dp(0, 0);
}
```

This code calculates the minimum number of operations required to convert one word into another using insertion, deletion, or substitution operations.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	string a, b;
	```
	Declares two string variables `a` and `b` to store the input words.

2. **Array Initialization**
	```cpp
	vector<vector<int>> memo;
	```
	Declares a 2D vector `memo` to store memoized results for the `dp` function.

3. **Function Declaration**
	```cpp
	int dp(int i, int j) {
	```
	Declares a recursive function `dp` to calculate the minimum edit distance between two substrings starting at indices `i` and `j`.

4. **Base Case**
	```cpp
	    if(i == a.size() && j == b.size()) return 0;
	```
	Base case: If both strings are exhausted, the edit distance is 0.

5. **Base Case**
	```cpp
	    if(i == a.size()) return b.size() - j;
	```
	Base case: If `a` is exhausted, the remaining edit distance is the length of `b`.

6. **Base Case**
	```cpp
	    if(j == b.size()) return a.size() - i;
	```
	Base case: If `b` is exhausted, the remaining edit distance is the length of `a`.

7. **Memoization**
	```cpp
	    if(memo[i][j] != -1) return memo[i][j];
	```
	Checks if the result for the current `i` and `j` is already memoized.

8. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	Initializes `ans` to store the minimum edit distance.

9. **Conditional**
	```cpp
	    if(a[i] != b[j]) {
	```
	Checks if the current characters at indices `i` and `j` are different.

10. **Min Calculation**
	```cpp
	        ans = min({dp(i+1,j), dp(i,j+1), dp(i+1,j+1)}) + 1;
	```
	If the characters are different, calculates the minimum edit distance by considering insertion, deletion, and substitution operations.

11. **Conditional**
	```cpp
	    } else {
	```
	If the characters are the same.

12. **Recursive Call**
	```cpp
	        ans = dp(i + 1, j+ 1);
	```
	If the characters are the same, move to the next characters in both strings.

13. **Memoization**
	```cpp
	    return memo[i][j] = ans;
	```
	Stores the calculated minimum edit distance in the memoization table and returns it.

14. **Function Declaration**
	```cpp
	int minDistance(string word1, string word2) {
	```
	Declares the main function `minDistance` to calculate the minimum edit distance between two words.

15. **Variable Assignment**
	```cpp
	    this->a = word1;
	```
	Assigns the input word1 to the class member variable `a`.

16. **Variable Assignment**
	```cpp
	    this->b = word2;
	```
	Assigns the input word2 to the class member variable `b`.

17. **Array Initialization**
	```cpp
	    memo.resize(a.size(), vector<int>(b.size(), -1));
	```
	Initializes the `memo` array with -1 to indicate uncalculated values.

18. **Function Call**
	```cpp
	    return dp(0, 0);
	```
	Calls the `dp` function to calculate the minimum edit distance starting from the beginning of both words.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

Where m and n are the lengths of str1 and str2, respectively.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

We need to store the dp array of size m * n.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/edit-distance/description/)

---
{{< youtube XYi2-LPrwm4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
