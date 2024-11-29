
+++
authors = ["grid47"]
title = "Leetcode 777: Swap Adjacent in LR String"
date = "2024-08-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 777: Swap Adjacent in LR String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/777.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/777.webp" 
    alt="A string where adjacent characters are swapped, glowing softly with each swap."
    caption="Solution to LeetCode 777: Swap Adjacent in LR String Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a string start and a string result composed of the characters 'L', 'R', and 'X'. A move consists of either replacing an occurrence of 'XL' with 'LX', or replacing an occurrence of 'RX' with 'XR'. Return true if it is possible to transform start into result by applying a sequence of these moves.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two strings: start and result. Both strings are composed of characters 'L', 'R', and 'X'.
- **Example:** `Input: start = 'XRRXXLRX', result = 'XRRLXXRX'`
- **Constraints:**
	- 1 <= start.length <= 10^4
	- start.length == result.length
	- Both strings consist only of the characters 'L', 'R', and 'X'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if it is possible to transform start into result through a series of valid moves, otherwise return false.
- **Example:** `Output: true`
- **Constraints:**
	- The output must be either true or false based on the possibility of transformation.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if a sequence of moves can transform the start string into the result string.

- First, ensure that both the start and result strings contain the same number of 'L' and 'R' characters.
- Then, compare the positions of 'L' and 'R' in the start and result strings.
- Finally, verify that no illegal swaps (such as moving 'L' after 'R' in the wrong direction) are attempted.
{{< dots >}}
### Problem Assumptions ✅
- The input strings will be of equal length and consist only of 'L', 'R', and 'X'.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: Input: start = 'XRRXXLRX', result = 'XRRLXXRX'`  \
  **Explanation:** The transformation is possible in one step: XRRXXLRX → XRRLXXRX.

- **Input:** `Example 2: Input: start = 'LR', result = 'RL'`  \
  **Explanation:** No sequence of moves can transform 'LR' to 'RL', so the result is false.

{{< dots >}}
## Approach 🚀
The approach is to simulate the moves by checking the positions of 'L' and 'R' in both the start and result strings. If any invalid moves are detected (such as moving 'L' after 'R' in the wrong direction), return false.

### Initial Thoughts 💭
- We need to check if the relative positions of 'L' and 'R' in the start string can be matched in the result string.
- By checking the relative positions and ensuring no invalid moves are attempted, we can determine if the transformation is possible.
{{< dots >}}
### Edge Cases 🌐
- The input strings will always have at least one character.
- The solution should efficiently handle strings with up to 10^4 characters.
- If both the start and result strings are already the same, the answer should be true.
- Both strings will always consist of 'L', 'R', and 'X'.
{{< dots >}}
## Code 💻
```cpp
bool canTransform(string start, string end) {
    int n = start.size();
    string s1, s2;
    for (int i = 0; i < n; ++i) 
        if (start[i] != 'X') s1 += start[i];
    for (int i = 0; i < n; ++i) 
        if (end[i] != 'X') s2 += end[i];
    if (s1 != s2) return false;

    int p1 = 0, p2 = 0;
    while(p1 < start.size() && p2 < end.size()) {
        while(p1 < start.size() && start[p1] == 'X') p1++;
        while(p2 < end.size()   && end[p2]   == 'X') p2++;

        if(p1 == start.size() && p2 == end.size()) return true;
        if(p1 == start.size() || p2 == end.size()) return false;

        if(start[p1] != end[p2]) return false;

        if(start[p1] == 'L' && p2 > p1) return false;
        if(start[p1] == 'R' && p2 < p1) return false;
        p1++;
        p2++;
    }
    return true;
}
```

This function determines if one string can be transformed into another by moving 'L' and 'R' characters and ignoring 'X' characters. The logic ensures that 'L' and 'R' move in specific directions based on their positions.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool canTransform(string start, string end) {
	```
	Define the function to check if one string can be transformed into another while following specific movement rules for 'L', 'R', and 'X'.

2. **Variable Initialization**
	```cpp
	    int n = start.size();
	```
	Initialize 'n' to store the length of the 'start' string.

3. **Variable Declaration**
	```cpp
	    string s1, s2;
	```
	Declare two strings 's1' and 's2' that will store characters from 'start' and 'end' respectively, excluding 'X' characters.

4. **Loop Start (start string)**
	```cpp
	    for (int i = 0; i < n; ++i) 
	```
	Start a loop to iterate through the 'start' string.

5. **Character Filtering (start string)**
	```cpp
	        if (start[i] != 'X') s1 += start[i];
	```
	If the current character in 'start' is not 'X', append it to 's1'.

6. **Loop Start (end string)**
	```cpp
	    for (int i = 0; i < n; ++i) 
	```
	Start a loop to iterate through the 'end' string.

7. **Character Filtering (end string)**
	```cpp
	        if (end[i] != 'X') s2 += end[i];
	```
	If the current character in 'end' is not 'X', append it to 's2'.

8. **String Comparison**
	```cpp
	    if (s1 != s2) return false;
	```
	If the filtered strings 's1' and 's2' are not the same, return false, as transformation is not possible.

9. **Pointer Initialization**
	```cpp
	    int p1 = 0, p2 = 0;
	```
	Initialize two pointers 'p1' and 'p2' to traverse through the 'start' and 'end' strings.

10. **While Loop Start**
	```cpp
	    while(p1 < start.size() && p2 < end.size()) {
	```
	Start a loop that continues as long as there are characters left in both 'start' and 'end'.

11. **Skip 'X' in start**
	```cpp
	        while(p1 < start.size() && start[p1] == 'X') p1++;
	```
	Move the pointer 'p1' forward while it points to 'X' characters in the 'start' string.

12. **Skip 'X' in end**
	```cpp
	        while(p2 < end.size() && end[p2] == 'X') p2++;
	```
	Move the pointer 'p2' forward while it points to 'X' characters in the 'end' string.

13. **Pointer Comparison**
	```cpp
	        if(p1 == start.size() && p2 == end.size()) return true;
	```
	If both pointers have reached the end of their respective strings, return true, as the transformation is complete.

14. **Pointer End Check**
	```cpp
	        if(p1 == start.size() || p2 == end.size()) return false;
	```
	If one pointer reaches the end of its string while the other does not, return false, indicating an incomplete transformation.

15. **Character Comparison**
	```cpp
	        if(start[p1] != end[p2]) return false;
	```
	If the characters at the current positions of 'p1' and 'p2' do not match, return false.

16. **Leftward Movement Check**
	```cpp
	        if(start[p1] == 'L' && p2 > p1) return false;
	```
	If the character is 'L' in 'start' and its pointer 'p2' is ahead of 'p1', return false, as 'L' can only move left.

17. **Rightward Movement Check**
	```cpp
	        if(start[p1] == 'R' && p2 < p1) return false;
	```
	If the character is 'R' in 'start' and its pointer 'p2' is behind 'p1', return false, as 'R' can only move right.

18. **Pointer Increment**
	```cpp
	        p1++;
	```
	Increment the 'p1' pointer to check the next character in the 'start' string.

19. **Pointer Increment**
	```cpp
	        p2++;
	```
	Increment the 'p2' pointer to check the next character in the 'end' string.

20. **Return Statement**
	```cpp
	    return true;
	```
	Return true, indicating that the transformation is possible.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the input strings.
- **Average Case:** O(n), since we are iterating through the strings once.
- **Worst Case:** O(n), as we only perform a linear scan through both strings.

The time complexity is linear because we only iterate through the strings once.

### Space Complexity 💾
- **Best Case:** O(1), since we only need a few extra variables.
- **Worst Case:** O(1), as the space required is constant beyond the input strings.

The space complexity is constant as no additional space is required except for a few variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/swap-adjacent-in-lr-string/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
