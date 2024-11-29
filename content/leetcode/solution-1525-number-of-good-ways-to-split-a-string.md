
+++
authors = ["grid47"]
title = "Leetcode 1525: Number of Good Ways to Split a String"
date = "2024-06-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1525: Number of Good Ways to Split a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Dynamic Programming","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "lRVpVUC5mQ4"
youtube_upload_date="2020-09-14"
youtube_thumbnail="https://i.ytimg.com/vi/lRVpVUC5mQ4/maxresdefault.jpg"
comments = true
+++



---
You are given a string `s`. You need to determine the number of valid ways to split `s` into two non-empty substrings such that the number of distinct letters in the left and right substrings is the same.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A string `s` consisting of lowercase English letters.
- **Example:** `s = 'abacb'`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- s consists of only lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the total number of valid splits where the number of distinct letters in both substrings is equal.
- **Example:** `For s = 'abacb', the output is 3.`
- **Constraints:**
	- The output is the number of valid splits.

{{< dots >}}
### Core Logic 🔍
**Goal:** Count the number of valid splits based on distinct letters in both substrings.

- Track the distinct letters in the left and right parts of the string.
- For each possible split of the string, compare the distinct letters in the two parts.
- If the distinct letters in both parts are equal, increment the count.
{{< dots >}}
### Problem Assumptions ✅
- The string is not empty and contains at least one character.
{{< dots >}}
## Examples 🧩
- **Input:** `s = 'abacb'`  \
  **Explanation:** The valid splits are ('aba', 'cb'). Both have 2 distinct letters.

- **Input:** `s = 'abcd'`  \
  **Explanation:** The valid split is ('ab', 'cd'), both having 2 distinct letters.

{{< dots >}}
## Approach 🚀
To solve the problem, track the number of distinct letters in both left and right substrings at each split.

### Initial Thoughts 💭
- A split is valid if the distinct letters in both parts are the same.
- We can use two counters to track distinct letters on both sides of the split as we iterate through the string.
{{< dots >}}
### Edge Cases 🌐
- No empty strings are allowed, as the string must have at least one character.
- The solution needs to efficiently handle large inputs up to 10^5 characters.
- All characters in the string are the same.
- The solution should run in linear time relative to the length of the string.
{{< dots >}}
## Code 💻
```cpp
int numSplits(string s) {
    map<char, int> left, right;
    
    int n = s.size();
    for(int i = 0; i < n; i++)
        right[s[i]]++;
    
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        left[s[i]]++;
        right[s[i]]--;
        if(right[s[i]] == 0) right.erase(s[i]);
        if(left.size() == right.size()) cnt++;
    }
    
    return cnt;
}
```

The function `numSplits` counts how many times a string can be split into two non-empty parts such that the number of unique characters in the left and right parts is the same. It uses two maps `left` and `right` to track the frequency of characters in the left and right parts of the split.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int numSplits(string s) {
	```
	This line defines the function `numSplits` which takes a string `s` as input and returns an integer, representing the number of valid splits where the number of unique characters in both parts is the same.

2. **Map Initialization**
	```cpp
	    map<char, int> left, right;
	```
	Two maps `left` and `right` are initialized to store the frequency of characters in the left and right parts of the string during the iterations.

3. **Size Calculation**
	```cpp
	    int n = s.size();
	```
	This line calculates the size of the string `s` and stores it in variable `n`.

4. **Populate Right Map**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	This loop iterates through the string `s`, and in each iteration, it increments the frequency of the character `s[i]` in the `right` map, representing the frequency of characters in the right part.

5. **Increment Right Map**
	```cpp
	        right[s[i]]++;
	```
	Increments the count of character `s[i]` in the `right` map.

6. **Counter Initialization**
	```cpp
	    int cnt = 0;
	```
	The counter `cnt` is initialized to zero. It will store the number of valid splits where the number of unique characters in both left and right parts is the same.

7. **Iterate for Splits**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	This loop iterates through the string again. In each iteration, it updates the `left` and `right` maps to reflect the changes as characters are moved from the right to the left part of the string.

8. **Increment Left Map**
	```cpp
	        left[s[i]]++;
	```
	Increments the frequency of character `s[i]` in the `left` map as the character is considered part of the left substring.

9. **Decrement Right Map**
	```cpp
	        right[s[i]]--;
	```
	Decrements the frequency of character `s[i]` in the `right` map as the character is now considered part of the left substring.

10. **Remove Zero Count from Right**
	```cpp
	        if(right[s[i]] == 0) right.erase(s[i]);
	```
	If the frequency of character `s[i]` in the `right` map becomes zero, it is removed from the map.

11. **Check for Equal Map Sizes**
	```cpp
	        if(left.size() == right.size()) cnt++;
	```
	If the number of unique characters in the left and right parts (i.e., the size of the `left` and `right` maps) is equal, it means this split is valid, and the counter `cnt` is incremented.

12. **Return Result**
	```cpp
	    return cnt;
	```
	Returns the final value of `cnt`, which represents the number of valid splits where the number of unique characters in both parts is equal.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution processes each character once, thus the time complexity is O(n), where n is the length of the string.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required to store the distinct letters for each split.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-good-ways-to-split-a-string/description/)

---
{{< youtube lRVpVUC5mQ4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
