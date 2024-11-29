
+++
authors = ["grid47"]
title = "Leetcode 1358: Number of Substrings Containing All Three Characters"
date = "2024-06-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1358: Number of Substrings Containing All Three Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
Given a string `s` consisting only of characters 'a', 'b', and 'c', your task is to find the number of substrings that contain at least one occurrence of each of the characters 'a', 'b', and 'c'.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single string `s` containing only the characters 'a', 'b', and 'c'.
- **Example:** `"abacabc"`
- **Constraints:**
	- 3 <= s.length <= 5 x 10^4
	- s only consists of characters 'a', 'b', and 'c'.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an integer representing the number of substrings containing at least one occurrence of 'a', 'b', and 'c'.
- **Example:** `8`
- **Constraints:**
	- The answer should be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** To solve this problem efficiently, use a sliding window technique to track the number of substrings containing at least one of each character.

- Define a helper function `atmost` to calculate the number of substrings with at most 'k' distinct characters.
- Subtract the result of `atmost(s, 2)` from `atmost(s, 3)` to get the number of substrings containing at least one 'a', 'b', and 'c'.
{{< dots >}}
### Problem Assumptions ✅
- The string is guaranteed to contain only the characters 'a', 'b', and 'c'.
- The input will always have a length of at least 3.
{{< dots >}}
## Examples 🧩
- **Input:** `"abacabc"`  \
  **Explanation:** The substrings containing at least one of each character 'a', 'b', and 'c' are 'abc', 'abac', 'bac', 'acb', 'cab', 'abcab', 'bca', and 'cabc'. Thus, the result is 8.

{{< dots >}}
## Approach 🚀
We can use the sliding window technique with two pointers to efficiently calculate the number of substrings with at least one 'a', 'b', and 'c'.

### Initial Thoughts 💭
- The solution involves counting substrings with all three characters, which can be efficiently done using sliding windows.
- This approach avoids the brute-force approach of generating all substrings, making it feasible for large inputs.
- A sliding window will allow us to incrementally check substrings while maintaining efficiency.
{{< dots >}}
### Edge Cases 🌐
- Ensure that the solution handles the smallest input size, where the string length is exactly 3.
- Ensure that the solution performs efficiently for strings of length up to 50,000.
- Test cases where the string contains only one of the three characters.
- Ensure that the solution adheres to the given constraints on time and space complexity.
{{< dots >}}
## Code 💻
```cpp
int numberOfSubstrings(string s) {
    return atmost(s, 3) - atmost(s, 2);
}
int atmost(string s, int k) {
    map<char, int> ma;
    int res = 0, j = 0;
    for(int i = 0; i < s.size(); i++) {
        ma[s[i]]++;
        if(ma[s[i]] == 1) k--;
        while(k < 0) {
            ma[s[j]]--;
            if(ma[s[j]] == 0) k++;
            j++;
        }
        res += (i - j + 1);
    }
    return res;
}
```

This code calculates the number of substrings in a string with at most 3 distinct characters, subtracting the number of substrings with at most 2 distinct characters.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int numberOfSubstrings(string s) {
	```
	The function 'numberOfSubstrings' takes a string 's' as input and calculates the number of substrings with at most 3 distinct characters by calling the 'atmost' function with parameters 3 and 2.

2. **Return Statement**
	```cpp
	    return atmost(s, 3) - atmost(s, 2);
	```
	Returns the difference between the number of substrings with at most 3 distinct characters and those with at most 2 distinct characters, which gives the desired count of substrings with exactly 3 distinct characters.

3. **Function Declaration**
	```cpp
	int atmost(string s, int k) {
	```
	The 'atmost' function calculates the number of substrings in string 's' that contain at most 'k' distinct characters.

4. **Variable Declaration**
	```cpp
	    map<char, int> ma;
	```
	Declares a map 'ma' to store the frequency of characters in the current window.

5. **Variable Initialization**
	```cpp
	    int res = 0, j = 0;
	```
	Initializes 'res' to store the count of valid substrings and 'j' to track the left boundary of the sliding window.

6. **For Loop**
	```cpp
	    for(int i = 0; i < s.size(); i++) {
	```
	A for loop that iterates over each character in the string 's'. The loop variable 'i' represents the right boundary of the sliding window.

7. **Map Update**
	```cpp
	        ma[s[i]]++;
	```
	Increments the frequency of the character at index 'i' in the map 'ma'.

8. **Conditional Check**
	```cpp
	        if(ma[s[i]] == 1) k--;
	```
	Decreases 'k' when a new distinct character is encountered in the current window.

9. **While Loop - Adjusting Window**
	```cpp
	        while(k < 0) {
	```
	If the number of distinct characters exceeds 'k', the while loop adjusts the left boundary of the window by incrementing 'j' until the condition is met.

10. **Map Update**
	```cpp
	            ma[s[j]]--;
	```
	Decrements the frequency of the character at index 'j' as it is being excluded from the window.

11. **Conditional Check**
	```cpp
	            if(ma[s[j]] == 0) k++;
	```
	Increments 'k' when a character's frequency in the window reaches zero, effectively removing it as a distinct character.

12. **Window Adjustment**
	```cpp
	            j++;
	```
	Moves the left boundary of the window to the right by incrementing 'j'.

13. **Result Calculation**
	```cpp
	        res += (i - j + 1);
	```
	For each iteration of the outer loop, adds the number of valid substrings ending at index 'i' to 'res'. The value 'i - j + 1' represents the number of substrings with a valid window.

14. **Return Statement**
	```cpp
	    return res;
	```
	Returns the total count of substrings with at most 'k' distinct characters.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution uses a sliding window, so the time complexity is linear, i.e., O(n), where n is the length of the input string.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we only need a few variables to maintain the sliding window and count distinct characters.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
