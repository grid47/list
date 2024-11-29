
+++
authors = ["grid47"]
title = "Leetcode 712: Minimum ASCII Delete Sum for Two Strings"
date = "2024-08-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 712: Minimum ASCII Delete Sum for Two Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/712.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/712.webp" 
    alt="Two strings where the minimum ASCII sum for deletion is calculated, with each deleted character softly glowing."
    caption="Solution to LeetCode 712: Minimum ASCII Delete Sum for Two Strings Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make the two strings equal.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two strings s1 and s2.
- **Example:** `s1 = 'hello', s2 = 'goodbye'`
- **Constraints:**
	- 1 <= s1.length, s2.length <= 1000
	- s1 and s2 consist of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum sum of ASCII values of deleted characters from both strings to make them equal.
- **Example:** `If s1 = 'hello' and s2 = 'goodbye', return 732.`
- **Constraints:**
	- The returned value will be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the minimum ASCII sum of deleted characters that need to be removed from both strings to make them equal.

- Use dynamic programming (DP) to calculate the minimum deletion sum.
- Iterate through both strings and compare characters.
- For each mismatch, calculate the cost of deleting characters from both strings and update the DP table.
{{< dots >}}
### Problem Assumptions ✅
- Both strings will contain only lowercase English letters.
- Both strings are non-empty and have at least one character.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: s1 = 'hello', s2 = 'goodbye'`  \
  **Explanation:** In this example, we calculate the sum of deleted characters from both strings to make them equal. The deletions lead to a sum of 732.

- **Input:** `Example 2: s1 = 'dog', s2 = 'god'`  \
  **Explanation:** Here, no deletions are needed as both strings are already equal, leading to a sum of 0.

{{< dots >}}
## Approach 🚀
We use dynamic programming to efficiently calculate the minimum ASCII sum of deleted characters.

### Initial Thoughts 💭
- The problem can be reduced to finding the longest common subsequence (LCS).
- Once we find the LCS, the characters that are not part of it need to be deleted.
- The solution involves calculating the sum of ASCII values for characters that are not in the LCS.
{{< dots >}}
### Edge Cases 🌐
- If one or both strings are empty, the sum will be the sum of ASCII values of the non-empty string.
- If the strings are large, ensure that the solution handles them within time limits.
- If the strings are already equal, the minimum sum will be 0.
- Ensure that the DP solution does not exceed time and space limits for large inputs.
{{< dots >}}
## Code 💻
```cpp
string s1, s2;
vector<vector<int>> mem;

int dp(int i, int j) {
    if(i == s1.size() || j == s2.size()) return 0;
    
    if(mem[i][j] != -1) return mem[i][j];
    
    int ans = max(dp(i + 1, j), dp(i, j + 1));
    if(s1[i] == s2[j]) {
        ans = max(ans, dp(i + 1, j + 1) + s1[i]);
    }
    
    return mem[i][j] = ans;
}

int minimumDeleteSum(string s1, string s2) {
    
    this->s1 = s1;
    this->s2 = s2;
    
    int ans = 0;
    for(int i = 0; i < s1.size(); i++)
        ans += s1[i];
    for(int i = 0; i < s2.size(); i++)
        ans += s2[i];
    
    mem.resize(s1.size() + 1, vector<int>(s2.size(), -1));
    
    return ans - 2 * dp(0, 0);
    
}
```

Complete function to calculate the minimum delete sum of two strings using dynamic programming.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	string s1, s2;
	```
	Initialize two strings 's1' and 's2' to hold the input strings.

2. **Variable Initialization**
	```cpp
	vector<vector<int>> mem;
	```
	Create a 2D vector 'mem' to store the memoized results of the dynamic programming approach.

3. **Function Declaration**
	```cpp
	int dp(int i, int j) {
	```
	Define the recursive function 'dp' to compute the minimum delete sum between two strings from index i and j.

4. **Base Case**
	```cpp
	    if(i == s1.size() || j == s2.size()) return 0;
	```
	If either string has been fully traversed, return 0 as the base case.

5. **Memoization Check**
	```cpp
	    if(mem[i][j] != -1) return mem[i][j];
	```
	Check if the result has already been computed for the current indices i and j.

6. **Recursive Call**
	```cpp
	    int ans = max(dp(i + 1, j), dp(i, j + 1));
	```
	Recursively calculate the maximum result by either skipping a character from s1 or s2.

7. **Condition Check**
	```cpp
	    if(s1[i] == s2[j]) {
	```
	If the characters at the current indices of s1 and s2 are the same, consider them in the result.

8. **Recursive Call with Match**
	```cpp
	        ans = max(ans, dp(i + 1, j + 1) + s1[i]);
	```
	If characters match, include the character value in the result and recursively call the function for the next indices.

9. **Return Memoized Value**
	```cpp
	    return mem[i][j] = ans;
	```
	Memoize the result for the current indices i and j to avoid redundant calculations.

10. **End of Function**
	```cpp
	}
	```
	End of the 'dp' recursive function.

11. **Function Declaration**
	```cpp
	int minimumDeleteSum(string s1, string s2) {
	```
	Define the function 'minimumDeleteSum' to compute the result for the two input strings.

12. **Variable Initialization**
	```cpp
	    this->s1 = s1;
	```
	Assign the input string 's1' to the class member 's1'.

13. **Variable Initialization**
	```cpp
	    this->s2 = s2;
	```
	Assign the input string 's2' to the class member 's2'.

14. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	Initialize a variable 'ans' to accumulate the sum of ASCII values of characters in both strings.

15. **Loop**
	```cpp
	    for(int i = 0; i < s1.size(); i++)
	```
	Loop through each character in the first string 's1'.

16. **Sum Calculation**
	```cpp
	        ans += s1[i];
	```
	Add the ASCII value of the character in s1 to 'ans'.

17. **Loop**
	```cpp
	    for(int i = 0; i < s2.size(); i++)
	```
	Loop through each character in the second string 's2'.

18. **Sum Calculation**
	```cpp
	        ans += s2[i];
	```
	Add the ASCII value of the character in s2 to 'ans'.

19. **Vector Resize**
	```cpp
	    mem.resize(s1.size() + 1, vector<int>(s2.size(), -1));
	```
	Resize the 'mem' vector to the required size to store the memoization results.

20. **Return Result**
	```cpp
	    return ans - 2 * dp(0, 0);
	```
	Return the minimum delete sum by subtracting twice the result of 'dp(0, 0)' from the sum of all ASCII values.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m + n), where m and n are the lengths of the strings.
- **Average Case:** O(m * n), where m and n are the lengths of the strings.
- **Worst Case:** O(m * n), where m and n are the lengths of the strings.

The time complexity is proportional to the product of the lengths of the two strings.

### Space Complexity 💾
- **Best Case:** O(m * n), where m and n are the lengths of the strings.
- **Worst Case:** O(m * n), where m and n are the lengths of the strings.

The space complexity is proportional to the size of the DP table, which stores the results for all pairs of indices.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
