
+++
authors = ["grid47"]
title = "Leetcode 2609: Find the Longest Balanced Substring of a Binary String"
date = "2024-02-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2609: Find the Longest Balanced Substring of a Binary String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "_nyH2TA95yY"
youtube_upload_date="2023-04-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/_nyH2TA95yY/maxresdefault.webp"
comments = true
+++



---
You are given a binary string consisting of only '0's and '1's. A substring of this binary string is considered balanced if it contains equal numbers of '0's and '1's, and all the '0's come before the '1's. Your task is to find the length of the longest balanced substring.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a binary string s. The string consists only of '0's and '1's.
- **Example:** `s = "11010010"`
- **Constraints:**
	- 1 <= s.length <= 50
	- s consists only of '0' and '1'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the longest balanced substring. A balanced substring is one where the count of '0's equals the count of '1's, and all '0's come before the '1's.
- **Example:** `Output: 4`
- **Constraints:**
	- The output is a single integer representing the length of the longest balanced substring.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the longest balanced substring where the number of '0's equals the number of '1's and '0's come before '1's.

- Initialize counters for '0's and '1's as you traverse the string.
- If a '0' is encountered, increase the '0' counter, and reset the '1' counter.
- If a '1' is encountered, check if it can balance the '0's in the substring. If so, update the answer with the longest balanced substring length found.
{{< dots >}}
### Problem Assumptions ✅
- The string contains only '0' and '1'.
{{< dots >}}
## Examples 🧩
- **Input:** `s = "01000111"`  \
  **Explanation:** In this case, the longest balanced substring is '000111' which has length 6. It contains 3 '0's followed by 3 '1's.

- **Input:** `s = "00111"`  \
  **Explanation:** The longest balanced substring is '0011', which has length 4, with 2 '0's followed by 2 '1's.

- **Input:** `s = "111"`  \
  **Explanation:** There is no balanced substring except for the empty one, so the output is 0.

{{< dots >}}
## Approach 🚀
We aim to find the longest balanced substring where the number of '0's equals the number of '1's, and the '0's come before the '1's.

### Initial Thoughts 💭
- The binary string contains only '0's and '1's, which makes it easier to check if a substring is balanced.
- A potential approach is to traverse the string while keeping track of the number of '0's and '1's. Each time the numbers are balanced, we check if the length of the current balanced substring is the longest found so far.
{{< dots >}}
### Edge Cases 🌐
- An empty string should return 0 since there is no balanced substring.
- For larger input strings, ensure the solution runs efficiently within the constraints.
- Strings containing only '0's or only '1's should return 0 as they cannot form a balanced substring.
- Handle strings of length 1 properly and consider all possible substrings.
{{< dots >}}
## Code 💻
```cpp
int findTheLongestBalancedSubstring(string s) {
    int zr = 0, ans = 0;
    int cnt[2] = {};
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '0') {
            if(cnt[1]) {
                cnt[0] = 0;
                cnt[1] = 0;                    
            }
            cnt[0]++;
        } else {
            if(cnt[1] < cnt[0]) cnt[1]++;
            else {
                cnt[0] = 0;
                cnt[1] = 0;
            }
            ans = max(cnt[1] * 2, ans);
        }
    }
    return ans;
}
```

This function computes the length of the longest balanced substring of 0's and 1's. A balanced substring has equal number of 0's followed by 1's.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function**
	```cpp
	int findTheLongestBalancedSubstring(string s) {
	```
	The function begins by initializing two variables zr (zero count) and ans (the maximum balanced substring length).

2. **Variable Initialization**
	```cpp
	    int zr = 0, ans = 0;
	```
	zr tracks the zeroes in the substring, while ans holds the maximum balanced substring length found.

3. **Array Initialization**
	```cpp
	    int cnt[2] = {};
	```
	An array cnt[2] is used to track counts of '0's and '1's encountered in the substring.

4. **Loop**
	```cpp
	    for(int i = 0; i < s.size(); i++) {
	```
	Iterates through the string 's' to process each character.

5. **Conditional**
	```cpp
	        if(s[i] == '0') {
	```
	Checks if the current character is '0'.

6. **Inner Conditional**
	```cpp
	            if(cnt[1]) {
	```
	If there are any '1's counted, reset the counts of both '0's and '1's.

7. **Reset Counts**
	```cpp
	                cnt[0] = 0;
	```
	Reset count of '0's.

8. **Reset Counts**
	```cpp
	                cnt[1] = 0;                    
	```
	Reset count of '1's.

9. **Increment Count**
	```cpp
	            cnt[0]++;
	```
	Increment the count of '0's in the current substring.

10. **Else Conditional**
	```cpp
	        } else {
	```
	If the current character is '1', execute the following logic.

11. **Conditional**
	```cpp
	            if(cnt[1] < cnt[0]) cnt[1]++;
	```
	If there are fewer '1's than '0's, increment the count of '1's.

12. **Else Block**
	```cpp
	            else {
	```
	If the count of '1's equals or exceeds '0's, reset the counts.

13. **Reset Counts**
	```cpp
	                cnt[0] = 0;
	```
	Reset count of '0's.

14. **Reset Counts**
	```cpp
	                cnt[1] = 0;
	```
	Reset count of '1's.

15. **Update Answer**
	```cpp
	            ans = max(cnt[1] * 2, ans);
	```
	Update the maximum balanced substring length by comparing the current balanced substring's length (2 * cnt[1]) with ans.

16. **Return Statement**
	```cpp
	    return ans;
	```
	Return the maximum balanced substring length.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear in the size of the string, as the algorithm iterates over the string once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, as only a few variables are used to track the balanced substring length.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-longest-balanced-substring-of-a-binary-string/description/)

---
{{< youtube _nyH2TA95yY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
