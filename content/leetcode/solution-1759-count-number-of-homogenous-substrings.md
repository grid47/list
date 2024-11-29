
+++
authors = ["grid47"]
title = "Leetcode 1759: Count Number of Homogenous Substrings"
date = "2024-05-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1759: Count Number of Homogenous Substrings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "I3BzhnS9MwA"
youtube_upload_date="2021-02-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/I3BzhnS9MwA/maxresdefault.webp"
comments = true
+++



---
Given a string `s` consisting of lowercase letters, your task is to find the total number of homogenous substrings in `s`. A homogenous substring is a substring where all characters are the same. Since the result could be very large, return the total modulo 10^9 + 7.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `s` made up of lowercase alphabetic characters.
- **Example:** `Input: s = 'aabbbcc'`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- s consists only of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the total number of homogenous substrings modulo 10^9 + 7.
- **Example:** `Output: 10`
- **Constraints:**
	- The result should be modulo 10^9 + 7.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to efficiently count the number of homogenous substrings in the given string `s`.

- 1. Traverse the string and identify consecutive characters that are the same.
- 2. For each sequence of `k` consecutive identical characters, the number of homogenous substrings is the sum of the first `k` integers, which is `k * (k + 1) / 2`.
- 3. Accumulate this count for each sequence of homogenous characters found in the string.
- 4. Return the total number of substrings modulo 10^9 + 7.
{{< dots >}}
### Problem Assumptions ✅
- The string `s` is not empty and consists only of lowercase letters.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = 'aabbbcc'`  \
  **Explanation:** The homogenous substrings are 'a', 'a', 'b', 'b', 'b', 'bb', 'bbb', 'c', 'c', and 'cc'. Total: 10.

- **Input:** `Input: s = 'abc'`  \
  **Explanation:** The homogenous substrings are 'a', 'b', and 'c'. Total: 3.

{{< dots >}}
## Approach 🚀
The approach involves traversing the string, identifying consecutive identical characters, and counting the number of homogenous substrings using the sum of the first `k` integers formula.

### Initial Thoughts 💭
- The number of homogenous substrings for a group of `k` consecutive characters is the sum of the first `k` integers.
- We need to identify sequences of consecutive identical characters and compute the number of homogenous substrings for each sequence.
{{< dots >}}
### Edge Cases 🌐
- If the input string is empty, return 0.
- For very large inputs, ensure the solution runs in linear time, O(n), where n is the length of the string.
- If all characters are the same, the count of homogenous substrings will be the sum of the first `n` integers.
- The solution should handle strings of length up to 10^5 efficiently.
{{< dots >}}
## Code 💻
```cpp
int countHomogenous(string s) {
    long long j = 0, cnt = 0, n = s.size();
    int mod = (int) 1e9 + 7;
    
    for(int i = 0; i < n; i++) {
        if(s[j] == s[i]) continue;
        else {
            long long len = i - j;
            cnt += len * (len + 1) / 2;
            j = i;                
        }
    }
    long long len = n - j;
    cnt += len * (len + 1) / 2; 
    return cnt % mod;
}
```

The function calculates the number of contiguous substrings with all identical characters by iterating through the string and summing the count for each homogenous segment.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int countHomogenous(string s) {
	```
	Declares the function to count contiguous substrings with identical characters.

2. **Variable Initialization**
	```cpp
	    long long j = 0, cnt = 0, n = s.size();
	```
	Initializes variables to track the start of a segment, the total count, and the length of the string.

3. **Constant Initialization**
	```cpp
	    int mod = (int) 1e9 + 7;
	```
	Defines a modulo constant to prevent overflow in the result.

4. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Iterates through the string to identify homogenous segments.

5. **Condition Check**
	```cpp
	        if(s[j] == s[i]) continue;
	```
	Checks if the current character is part of the ongoing homogenous segment.

6. **Condition Else Block**
	```cpp
	        else {
	```
	Handles the case when a new segment starts.

7. **Segment Length Calculation**
	```cpp
	            long long len = i - j;
	```
	Calculates the length of the completed homogenous segment.

8. **Count Update**
	```cpp
	            cnt += len * (len + 1) / 2;
	```
	Updates the total count by adding the number of substrings for the segment.

9. **Index Update**
	```cpp
	            j = i;
	```
	Moves the segment start index to the current character.

10. **Final Segment Length Calculation**
	```cpp
	    long long len = n - j;
	```
	Calculates the length of the final homogenous segment.

11. **Final Count Update**
	```cpp
	    cnt += len * (len + 1) / 2; 
	```
	Adds the substrings count for the last segment to the total.

12. **Return Statement**
	```cpp
	    return cnt % mod;
	```
	Returns the result modulo the defined constant to ensure it fits within standard bounds.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the string.
- **Average Case:** O(n), as each character is checked once.
- **Worst Case:** O(n), where n is the length of the string.

The time complexity is linear because we only traverse the string once.

### Space Complexity 💾
- **Best Case:** O(1), as the space used is constant.
- **Worst Case:** O(1), since no extra space is needed except for counters.

The space complexity is constant, O(1), since only a few variables are used for counting.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-number-of-homogenous-substrings/description/)

---
{{< youtube I3BzhnS9MwA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
