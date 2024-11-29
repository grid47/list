
+++
authors = ["grid47"]
title = "Leetcode 2002: Maximum Product of the Length of Two Palindromic Subsequences"
date = "2024-04-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2002: Maximum Product of the Length of Two Palindromic Subsequences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Backtracking","Bit Manipulation","Bitmask"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "aoHbYlO8vDg"
youtube_upload_date="2021-09-12"
youtube_thumbnail="https://i.ytimg.com/vi/aoHbYlO8vDg/maxresdefault.jpg"
comments = true
+++



---
Given a string s, find two disjoint palindromic subsequences such that the product of their lengths is maximized. The two subsequences are disjoint if they do not both pick a character at the same index.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string s. The string is composed of lowercase English letters only.
- **Example:** `s = "abbacddc"`
- **Constraints:**
	- 2 <= s.length <= 12
	- s consists of lowercase English letters only

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum product of the lengths of two disjoint palindromic subsequences.
- **Example:** `9`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find two palindromic subsequences of maximum length whose product is the highest. The subsequences must be disjoint and must each form a palindrome.

- 1. Iterate over the string to form all possible subsequences.
- 2. Check if each subsequence is palindromic.
- 3. Calculate the product of the lengths of two disjoint palindromic subsequences.
- 4. Keep track of the maximum product encountered.
{{< dots >}}
### Problem Assumptions ✅
- The string will always have a length between 2 and 12 characters.
- The solution will need to check multiple subsequences to find the optimal answer.
{{< dots >}}
## Examples 🧩
- **Input:** `s = "abbacddc"`  \
  **Explanation:** An optimal solution is to pick 'abba' and 'cdc', as both are palindromes and their product of lengths (4 * 3 = 9) is the maximum.

- **Input:** `s = "aa"`  \
  **Explanation:** The best solution is picking 'a' from both subsequences, which results in a product of 1 * 1 = 1.

- **Input:** `s = "xyzyx"`  \
  **Explanation:** An optimal solution is to choose the entire string 'xyzyx' for both subsequences, resulting in a product of 5 * 5 = 25.

{{< dots >}}
## Approach 🚀
The problem is solved by finding all possible subsequences of the string that are palindromes. Then, the lengths of these subsequences are used to calculate the maximum possible product of their lengths when they are disjoint.

### Initial Thoughts 💭
- We need to efficiently check for palindromic subsequences in the string.
- The product of two disjoint subsequences can be maximized by ensuring their lengths are as large as possible.
- The problem can be approached by using dynamic programming or brute force to generate subsequences, and then checking each for being palindromic.
{{< dots >}}
### Edge Cases 🌐
- An empty string is not allowed according to the constraints.
- Although the string length is small (up to 12 characters), we need to efficiently check all subsequences to avoid excessive computation time.
- Strings with repeated characters may have multiple palindromic subsequences.
- Ensure the subsequences are disjoint (they do not share any characters at the same indices).
{{< dots >}}
## Code 💻
```cpp
int n;
string p;

bool pal(string &s) {
    int i = 0, j = s.size() - 1;
    while(i <= j) {
        if(s[i] != s[j]) return false;
        i++; j--;
    }
    return true;
}

int dp(int idx, string &s1, string &s2) {
    if(idx == n) {
        if(pal(s1) && pal(s2)) {
            return s1.size() * s2.size();
        }
        return 0;
    }

    s1.push_back(p[idx]);
    int ans = dp(idx + 1, s1, s2);
    s1.pop_back();        
    
    s2.push_back(p[idx]);        
    ans = max(ans, dp(idx + 1, s1, s2));
    s2.pop_back();        
    
    ans = max(ans, dp(idx + 1, s1, s2));
    
    // return mp[idx][s1][s2] = ans;
    return ans;        
}


int maxProduct(string s) {
    p = s;
    n = s.size();
    string s1 = "", s2 = "";
    return dp(0, s1, s2);
}
```

The function calculates the maximum product of the lengths of two palindromic substrings in a given string. It uses dynamic programming and a helper function to check whether substrings are palindromes.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	int n;
	```
	Declares an integer `n` to store the length of the input string `s`.

2. **Variable Declaration**
	```cpp
	string p;
	```
	Declares a string `p` to store the input string `s`.

3. **Helper Function Definition**
	```cpp
	bool pal(string &s) {
	```
	Defines a helper function `pal` that checks if the given string `s` is a palindrome.

4. **Pointer Initialization**
	```cpp
	    int i = 0, j = s.size() - 1;
	```
	Initializes two pointers, `i` at the beginning and `j` at the end of the string `s`.

5. **Palindrome Check**
	```cpp
	    while(i <= j) {
	```
	Starts a while loop to compare characters from both ends of the string.

6. **Character Comparison**
	```cpp
	        if(s[i] != s[j]) return false;
	```
	If the characters at positions `i` and `j` do not match, the function returns `false`, indicating that the string is not a palindrome.

7. **Pointer Movement**
	```cpp
	        i++; j--;
	```
	Moves the pointers `i` and `j` inward to continue comparing the next characters.

8. **Return Statement**
	```cpp
	    return true;
	```
	If no mismatched characters are found, the string is a palindrome, and the function returns `true`.

9. **Dynamic Programming Function Definition**
	```cpp
	int dp(int idx, string &s1, string &s2) {
	```
	Defines the recursive dynamic programming function `dp` that explores possible ways to split the input string into two palindromic substrings.

10. **Base Case**
	```cpp
	    if(idx == n) {
	```
	Checks if the end of the string has been reached.

11. **Palindrome Check for Substrings**
	```cpp
	        if(pal(s1) && pal(s2)) {
	```
	If both substrings `s1` and `s2` are palindromes, proceeds to calculate the product of their lengths.

12. **Product Calculation**
	```cpp
	            return s1.size() * s2.size();
	```
	Returns the product of the lengths of the two palindromic substrings `s1` and `s2`.

13. **Return for Non-Palindromes**
	```cpp
	        }
	```
	Ends the palindrome check block.

14. **Return for Invalid Case**
	```cpp
	        return 0;
	```
	If either `s1` or `s2` is not a palindrome, return 0 as no valid palindromic substrings can be formed.

15. **Recursive Exploration**
	```cpp
	    s1.push_back(p[idx]);
	```
	Adds the current character from the string `p` to the substring `s1`.

16. **Recursive Call**
	```cpp
	    int ans = dp(idx + 1, s1, s2);
	```
	Recursively calls `dp` to explore the next index with the updated substring `s1`.

17. **Backtrack for s1**
	```cpp
	    s1.pop_back();
	```
	Removes the last character added to `s1` to backtrack and explore other possibilities.

18. **Add to s2**
	```cpp
	    s2.push_back(p[idx]);
	```
	Adds the current character from `p` to the substring `s2`.

19. **Recursive Call for s2**
	```cpp
	    ans = max(ans, dp(idx + 1, s1, s2));
	```
	Recursively calls `dp` to explore the next index with the updated substring `s2` and stores the maximum product in `ans`.

20. **Backtrack for s2**
	```cpp
	    s2.pop_back();
	```
	Removes the last character added to `s2` to backtrack and explore other possibilities.

21. **Final Recursive Call**
	```cpp
	    ans = max(ans, dp(idx + 1, s1, s2));
	```
	Makes a final recursive call without modifying `s1` or `s2` to explore the next index.

22. **Final Answer**
	```cpp
	    return ans;
	```
	Returns the maximum product found.

23. **Main Function Definition**
	```cpp
	int maxProduct(string s) {
	```
	Defines the main function `maxProduct` that initializes variables and calls the dynamic programming function `dp`.

24. **Variable Initialization**
	```cpp
	    p = s;
	```
	Initializes the string `p` with the input string `s`.

25. **Variable Initialization**
	```cpp
	    n = s.size();
	```
	Initializes the integer `n` with the size of the input string `s`.

26. **String Initialization**
	```cpp
	    string s1 = "", s2 = "";
	```
	Initializes two empty strings `s1` and `s2` to store potential palindromic substrings.

27. **Final Call to dp**
	```cpp
	    return dp(0, s1, s2);
	```
	Calls the dynamic programming function `dp` with the starting index `0` and the empty substrings `s1` and `s2`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^3)
- **Worst Case:** O(2^n * n^2)

The worst case occurs when we have to generate all subsequences and check each for being palindromic. The number of subsequences is exponential in n, and checking each for palindrome takes linear time.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(2^n)

The space complexity is dominated by the number of subsequences we need to store, which is O(2^n) in the worst case.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/description/)

---
{{< youtube aoHbYlO8vDg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
