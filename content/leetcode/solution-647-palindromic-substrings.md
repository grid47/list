
+++
authors = ["grid47"]
title = "Leetcode 647: Palindromic Substrings"
date = "2024-09-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 647: Palindromic Substrings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/647.webp"
youtube = "EU5xSa5ZHGY"
youtube_upload_date="2023-06-21"
youtube_thumbnail="https://i.ytimg.com/vi/EU5xSa5ZHGY/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/647.webp" 
    alt="A string where palindromic substrings glow softly, each valid palindrome softly illuminated."
    caption="Solution to LeetCode 647: Palindromic Substrings Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a string s, return the number of palindromic substrings in it. A palindrome is a string that reads the same forward and backward. A substring is a contiguous sequence of characters within the string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string s, which contains lowercase English letters.
- **Example:** `s = "abc"`
- **Constraints:**
	- 1 <= s.length <= 1000
	- s consists of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of palindromic substrings in the given string s.
- **Example:** `3`
- **Constraints:**
	- The result will be a single integer representing the count of palindromic substrings.

{{< dots >}}
### Core Logic 🔍
**Goal:** Count the number of palindromic substrings in the string.

- 1. Initialize a dynamic programming (DP) table to store whether a substring is a palindrome.
- 2. Iterate over all possible substrings and use the DP table to check if they are palindromes.
- 3. Count the palindromes by summing up the number of valid palindromic substrings.
{{< dots >}}
### Problem Assumptions ✅
- The string is not empty.
- The solution must handle strings up to length 1000 efficiently.
{{< dots >}}
## Examples 🧩
- **Input:** `s = "abc"`  \
  **Explanation:** The palindromic substrings are: 'a', 'b', 'c'. Hence, the total count is 3.

{{< dots >}}
## Approach 🚀
The approach uses dynamic programming (DP) to efficiently count all palindromic substrings by building up from smaller substrings.

### Initial Thoughts 💭
- A palindrome substring must have the same first and last characters, and the substring excluding the first and last characters must also be a palindrome.
- By using dynamic programming, we can efficiently keep track of which substrings are palindromes and count them.
{{< dots >}}
### Edge Cases 🌐
- The input string will always have at least one character.
- Ensure that the solution can handle strings of length up to 1000 efficiently.
- Consider strings where all characters are the same or strings with no palindromic substrings.
- Efficiently handle large inputs with a time complexity of O(n^2).
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> mem;
string s;
int dp(int i, int j) {
    if(i >= j) return 1;
    if(mem[i][j] != -1) return mem[i][j];
    return mem[i][j] = (s[i] == s[j])? dp(i + 1, j - 1): 0;
}

int countSubstrings(string s) {
    this->s = s;
    int n = s.size();
    mem.resize(n, vector<int>(n, -1));
    int ans = 0;
    for(int i = 0; i < s.size(); i++)
    for(int j = i; j < s.size(); j++)
        ans += dp(i, j);        
    return ans;
}
```

This solution finds the number of palindromic substrings in a given string using dynamic programming and memoization.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	vector<vector<int>> mem;
	```
	Declares a 2D vector 'mem' to store the results of subproblems for memoization. This will be used to avoid redundant calculations of the palindrome checks.

2. **Variable Initialization**
	```cpp
	string s;
	```
	Declares a string 's' to store the input string for which the number of palindromic substrings will be counted.

3. **Recursive Function Definition**
	```cpp
	int dp(int i, int j) {
	```
	Defines the recursive function 'dp' that checks whether the substring from index 'i' to 'j' is a palindrome. It returns 1 if the substring is a palindrome, otherwise 0.

4. **Base Case**
	```cpp
	    if(i >= j) return 1;
	```
	Checks if the substring length is 1 or 0 (i.e., i >= j), in which case it is a palindrome by definition, so it returns 1.

5. **Memoization Check**
	```cpp
	    if(mem[i][j] != -1) return mem[i][j];
	```
	Checks if the result for the substring from 'i' to 'j' has already been computed (stored in 'mem'). If it has, it returns the stored result.

6. **Recursion**
	```cpp
	    return mem[i][j] = (s[i] == s[j])? dp(i + 1, j - 1): 0;
	```
	Recursively checks if the substring is a palindrome. If the characters at positions 'i' and 'j' are equal, it calls 'dp' on the next inner substring. If not, it returns 0.

7. **Function Definition**
	```cpp
	int countSubstrings(string s) {
	```
	Defines the main function 'countSubstrings' which takes the string 's' and returns the total number of palindromic substrings.

8. **Input Assignment**
	```cpp
	    this->s = s;
	```
	Assigns the input string 's' to the class member variable 's'.

9. **Variable Initialization**
	```cpp
	    int n = s.size();
	```
	Stores the size of the string 's' in the variable 'n'.

10. **Memoization Setup**
	```cpp
	    mem.resize(n, vector<int>(n, -1));
	```
	Resizes the 'mem' vector to a 2D array of size n x n, initializing all values to -1. This will be used to store results of the 'dp' function.

11. **Result Initialization**
	```cpp
	    int ans = 0;
	```
	Initializes the variable 'ans' to 0, which will store the total count of palindromic substrings.

12. **Outer Loop**
	```cpp
	    for(int i = 0; i < s.size(); i++)
	```
	Starts an outer loop to iterate through each character of the string 's'.

13. **Inner Loop**
	```cpp
	    for(int j = i; j < s.size(); j++)
	```
	Starts an inner loop to consider all substrings starting at index 'i' and ending at index 'j'.

14. **Counting Palindromes**
	```cpp
	        ans += dp(i, j);        
	```
	Calls the 'dp' function to check if the substring from 'i' to 'j' is a palindrome. Adds the result (1 or 0) to 'ans'.

15. **Final Return**
	```cpp
	    return ans;
	```
	Returns the final count of palindromic substrings stored in 'ans'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is O(n^2) due to the nested loops used to check each substring.

### Space Complexity 💾
- **Best Case:** O(n^2)
- **Worst Case:** O(n^2)

The space complexity is O(n^2) due to the DP table storing results for all substrings.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/palindromic-substrings/description/)

---
{{< youtube EU5xSa5ZHGY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
