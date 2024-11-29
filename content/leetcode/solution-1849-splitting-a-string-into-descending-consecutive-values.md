
+++
authors = ["grid47"]
title = "Leetcode 1849: Splitting a String Into Descending Consecutive Values"
date = "2024-05-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1849: Splitting a String Into Descending Consecutive Values in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "eDtMmysldaw"
youtube_upload_date="2021-05-02"
youtube_thumbnail="https://i.ytimg.com/vi/eDtMmysldaw/maxresdefault.jpg"
comments = true
+++



---
Given a string s consisting of digits, check if it is possible to split it into two or more non-empty substrings such that the numerical values of the substrings are in strictly descending order and the difference between the values of adjacent substrings is exactly 1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string s made up of digits.
- **Example:** `"5432"`
- **Constraints:**
	- 1 <= s.length <= 20
	- s consists only of digits

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if it is possible to split the string into substrings satisfying the conditions; otherwise, return false.
- **Example:** `true`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To find a valid way to split the string into substrings that meet the conditions.

- Start by iterating through the string and attempting to split it into substrings.
- For each split, check if the substrings' numerical values are in strictly descending order with a difference of exactly 1 between adjacent values.
- Return true if a valid split is found, otherwise return false.
{{< dots >}}
### Problem Assumptions ✅
- The input string will always contain at least one character.
{{< dots >}}
## Examples 🧩
- **Input:** `"1000001"`  \
  **Explanation:** The string can be split into the substrings ['1', '00000', '1'], which correspond to the values [1, 0, 1]. These values are in descending order with a difference of 1, so the split is valid.

{{< dots >}}
## Approach 🚀
We will attempt to split the string in different ways and check if any of those splits satisfy the conditions of strictly descending values and adjacent differences of exactly 1.

### Initial Thoughts 💭
- We need to check all possible ways of splitting the string and validate if the split satisfies the numerical conditions.
- We can approach this problem using a recursive backtracking method, where we try different splits and check if they meet the criteria.
{{< dots >}}
### Edge Cases 🌐
- The input string will never be empty, as the length is guaranteed to be at least 1.
- The string length will not exceed 20, so efficiency for large inputs is not a concern.
- Consider cases where the string consists of repeating digits or where it starts with zeros.
- The solution should handle strings with lengths from 1 to 20 efficiently.
{{< dots >}}
## Code 💻
```cpp
string s;
bool splitString(string s) {
    this->s = s;
    double tmp = 0;
    for(int i = 0; i < s.size() - 1; i++) {
        tmp = tmp * 10 + (s[i] - '0');
        if(bt(i + 1, tmp)) return true;
    }
    return false;
}

bool bt(int idx, double prv) {

    if(idx == s.size()) return true;
    
    double tmp = 0;
    for(int i = idx; i < s.size(); i++) {
        tmp = tmp * 10 + (s[i] - '0');
        if(tmp - prv > -1) break;
        if(tmp - prv == -1) {
            if(bt(i + 1, tmp))
                return true;
        }
    }
    return false;
}
```

This code defines a function `splitString` that checks if a given string `s` can be split into a sequence of numbers where each consecutive number differs by exactly 1. It uses a backtracking helper function `bt` to explore possible splits and returns true if such a split exists.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	string s;
	```
	Declares a string variable `s` which will hold the input string to be split.

2. **Function Definition**
	```cpp
	bool splitString(string s) {
	```
	Defines the `splitString` function, which takes a string `s` as input and returns a boolean indicating whether it can be split into a sequence of numbers with a difference of 1 between consecutive numbers.

3. **Assignment**
	```cpp
	    this->s = s;
	```
	Assigns the input string `s` to the member variable `this->s`.

4. **Variable Initialization**
	```cpp
	    double tmp = 0;
	```
	Initializes a temporary variable `tmp` of type double to store the value of the current number being formed during the iteration.

5. **Loop Initialization**
	```cpp
	    for(int i = 0; i < s.size() - 1; i++) {
	```
	Starts a loop that iterates through the string `s`, except for the last character. The loop is used to form numbers from the string.

6. **String to Number Conversion**
	```cpp
	        tmp = tmp * 10 + (s[i] - '0');
	```
	Forms a number by converting the current character `s[i]` to its integer value and updating `tmp`.

7. **Backtracking Function Call**
	```cpp
	        if(bt(i + 1, tmp)) return true;
	```
	Calls the backtracking function `bt` with the next index `i + 1` and the current value of `tmp` to check if the string can be split starting from that index.

8. **Return Statement**
	```cpp
	    return false;
	```
	If no valid split is found, the function returns false, indicating that the string cannot be split into the desired sequence.

9. **Backtracking Function Definition**
	```cpp
	bool bt(int idx, double prv) {
	```
	Defines the helper function `bt` (backtracking), which attempts to find a valid split starting at index `idx` and with the previous number `prv`.

10. **Base Case**
	```cpp
	    if(idx == s.size()) return true;
	```
	Checks if the current index has reached the end of the string. If so, it returns true, indicating a successful split.

11. **Variable Initialization**
	```cpp
	    double tmp = 0;
	```
	Initializes a temporary variable `tmp` to store the current number formed from the string.

12. **Loop Initialization**
	```cpp
	    for(int i = idx; i < s.size(); i++) {
	```
	Starts a loop that iterates from the current index `idx` to the end of the string `s`. It attempts to form the next possible number.

13. **String to Number Conversion**
	```cpp
	        tmp = tmp * 10 + (s[i] - '0');
	```
	Forms a number by converting the current character `s[i]` to its integer value and updating `tmp`.

14. **Backtracking Pruning**
	```cpp
	        if(tmp - prv > -1) break;
	```
	Prunes the search space. If the difference between the current number `tmp` and the previous number `prv` is greater than -1, it breaks the loop because the sequence cannot continue.

15. **Backtracking Condition**
	```cpp
	        if(tmp - prv == -1) {
	```
	Checks if the difference between the current number `tmp` and the previous number `prv` is exactly -1, which is the condition for a valid split.

16. **Recursive Call**
	```cpp
	            if(bt(i + 1, tmp))
	```
	Makes a recursive call to `bt` with the next index `i + 1` and the current value of `tmp` to check if the rest of the string can be split.

17. **Return True**
	```cpp
	                return true;
	```
	If the recursive call returns true, indicating a valid split, the function returns true.

18. **Return False**
	```cpp
	    return false;
	```
	If no valid split is found, the function returns false.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is quadratic in terms of the length of the string because we check all possible splits and validate each one.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of the intermediate substrings during the split process.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/description/)

---
{{< youtube eDtMmysldaw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
