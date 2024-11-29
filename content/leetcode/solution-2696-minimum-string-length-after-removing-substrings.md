
+++
authors = ["grid47"]
title = "Leetcode 2696: Minimum String Length After Removing Substrings"
date = "2024-02-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2696: Minimum String Length After Removing Substrings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "8SD0rcmgFMU"
youtube_upload_date="2023-05-21"
youtube_thumbnail="https://i.ytimg.com/vi_webp/8SD0rcmgFMU/maxresdefault.webp"
comments = true
+++



---
You are given a string `s` consisting of only uppercase English letters. You can repeatedly remove any occurrence of the substrings 'AB' or 'CD' from `s`. Each operation removes one of these substrings and shortens the string. After performing the operations, return the minimum possible length of the resulting string. Note that removing substrings can create new occurrences of 'AB' or 'CD', which can be removed in further operations.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string `s` which contains only uppercase English letters.
- **Example:** `Input: s = 'ABDCACDB'`
- **Constraints:**
	- 1 <= s.length <= 100
	- s consists only of uppercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum possible length of the string after applying the operations.
- **Example:** `Output: 3`
- **Constraints:**
	- The output should be a single integer representing the length of the resulting string after all possible operations.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to remove the substrings 'AB' or 'CD' as much as possible to minimize the length of the string.

- Step 1: Initialize a variable `res` to store the length of the string.
- Step 2: Loop through the string to find occurrences of 'AB' or 'CD'.
- Step 3: Remove each occurrence by marking the characters as 'X' (or any placeholder).
- Step 4: After removing a substring, check the new string for additional occurrences of 'AB' or 'CD'.
- Step 5: Continue removing substrings until no more 'AB' or 'CD' substrings can be found.
- Step 6: Return the length of the string after all possible removals.
{{< dots >}}
### Problem Assumptions ✅
- The string is not empty.
- The string contains only uppercase English letters.
- The string can be modified multiple times as long as 'AB' or 'CD' substrings are present.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = 'ABDCACDB'`  \
  **Explanation:** We can remove 'AB' from the string, resulting in 'DCACDB'. Then, remove 'DC' and 'CD' to get 'AC'. Finally, remove 'AC' to get an empty string. The minimum length is 3.

- **Input:** `Input: s = 'AABBCCDD'`  \
  **Explanation:** We can remove 'AB' and 'CD' twice to get 'CC'. The final string has a length of 2.

{{< dots >}}
## Approach 🚀
The approach involves iterating through the string and repeatedly removing substrings 'AB' or 'CD' until no such substrings are left.

### Initial Thoughts 💭
- We need to keep checking for 'AB' or 'CD' substrings and remove them.
- The string can be dynamically modified as substrings are removed.
- A greedy approach can be used where we continuously remove the substrings 'AB' and 'CD' until none remain.
{{< dots >}}
### Edge Cases 🌐
- An empty string is not possible based on constraints but if it were, the length would be 0.
- For strings close to the upper limit of length 100, ensure the approach handles the string efficiently.
- If no 'AB' or 'CD' substrings exist, the length of the string will remain unchanged.
- The string length is guaranteed to be between 1 and 100, so the algorithm should perform efficiently within these bounds.
{{< dots >}}
## Code 💻
```cpp
int minLength(string s) {
    int n = s.size();
    int res = n;
    for(int i = 0; i < n - 1; i++) {
        int p = i, q = i + 1;
        while((p >= 0 && q < n && s[p] == 'A' && s[q] == 'B') ||
           (p >= 0 && q < n && s[p] == 'C' && s[q] == 'D') ) {
            s[p] = 'X';
            s[q] = 'X';                
            res -= 2;
            while(q < n && s[q] == 'X') q++;
            while(p >= 0&& s[p] == 'X') p--;                
        }
    }
    return res;
}
```

This function `minLength` computes the minimal length of a string after repeatedly removing adjacent pairs of characters ('A', 'B') or ('C', 'D'). It uses a greedy approach to remove these pairs and return the final string length.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minLength(string s) {
	```
	This line defines the function `minLength` that takes a string `s` as input and returns an integer representing the minimal length of the string after removal of certain character pairs.

2. **String Size Calculation**
	```cpp
	    int n = s.size();
	```
	The variable `n` stores the length of the input string `s`.

3. **Initialization**
	```cpp
	    int res = n;
	```
	The variable `res` is initialized to `n`, representing the initial length of the string before any pairs are removed.

4. **Outer Loop Initialization**
	```cpp
	    for(int i = 0; i < n - 1; i++) {
	```
	A loop is initiated to iterate through each character in the string, excluding the last character (as we are checking pairs).

5. **Pointer Setup**
	```cpp
	        int p = i, q = i + 1;
	```
	Two pointers `p` and `q` are initialized, where `p` points to the current character and `q` points to the next character.

6. **Pair Checking**
	```cpp
	        while((p >= 0 && q < n && s[p] == 'A' && s[q] == 'B') ||
	```
	The while loop checks if the characters at positions `p` and `q` form a valid pair ('A' and 'B').

7. **Pair Checking**
	```cpp
	           (p >= 0 && q < n && s[p] == 'C' && s[q] == 'D') ) {
	```
	This condition checks if the characters at positions `p` and `q` form the pair ('C' and 'D'). The loop continues if either pair is found.

8. **Character Replacement**
	```cpp
	            s[p] = 'X';
	```
	The character at position `p` is replaced with 'X' to indicate that the pair has been removed.

9. **Character Replacement**
	```cpp
	            s[q] = 'X';                
	```
	The character at position `q` is also replaced with 'X', marking it as removed.

10. **Result Update**
	```cpp
	            res -= 2;
	```
	The length of the string is decreased by 2, as two characters have been removed.

11. **Pointer Adjustment**
	```cpp
	            while(q < n && s[q] == 'X') q++;
	```
	The pointer `q` is moved forward to skip over any 'X' characters (those marked as removed).

12. **Pointer Adjustment**
	```cpp
	            while(p >= 0&& s[p] == 'X') p--;                
	```
	Similarly, the pointer `p` is moved backward to skip over any 'X' characters.

13. **Return Result**
	```cpp
	    return res;
	```
	The function returns the final length of the string after all possible pair removals.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n^2)

The time complexity is O(n) in the best case when no removals are necessary, but may reach O(n^2) in the worst case when multiple passes through the string are required.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the string during processing.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/)

---
{{< youtube 8SD0rcmgFMU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
