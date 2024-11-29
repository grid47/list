
+++
authors = ["grid47"]
title = "Leetcode 2027: Minimum Moves to Convert String"
date = "2024-04-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2027: Minimum Moves to Convert String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "hCuwkDkAXYM"
youtube_upload_date="2021-10-03"
youtube_thumbnail="https://i.ytimg.com/vi/hCuwkDkAXYM/maxresdefault.jpg"
comments = true
+++



---
You are given a string `s` consisting of `n` characters, where each character is either 'X' or 'O'. A move consists of selecting three consecutive characters in the string and converting them all to 'O'. If a character is already 'O', it remains unchanged. Determine the minimum number of moves required to convert all the characters of `s` to 'O'.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `s` containing only the characters 'X' and 'O'.
- **Example:** `s = "XXOX"`
- **Constraints:**
	- 3 <= s.length <= 1000
	- s[i] is either 'X' or 'O'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of moves required to convert all the characters of `s` to 'O'.
- **Example:** `Output: 2`
- **Constraints:**
	- The result is the minimum number of operations needed.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to count how many moves are needed to convert all 'X's in the string to 'O's by selecting consecutive blocks of three characters.

- 1. Traverse the string from left to right.
- 2. Whenever you encounter an 'X', increment the move count and skip the next two characters (as we can change three consecutive characters in one move).
- 3. Continue this process until the end of the string is reached.
{{< dots >}}
### Problem Assumptions ✅
- The string `s` contains only the characters 'X' and 'O'.
{{< dots >}}
## Examples 🧩
- **Input:** `s = "XXX"`  \
  **Explanation:** We can convert all 'X's to 'O's in one move, resulting in 'OOO'.

- **Input:** `s = "XXOX"`  \
  **Explanation:** In the first move, we convert 'XXX' to 'OOO', yielding 'OOOX'. In the second move, we convert 'OOX' to 'OOO'.

- **Input:** `s = "OOOO"`  \
  **Explanation:** Since the string already consists of only 'O's, no moves are required.

{{< dots >}}
## Approach 🚀
The problem can be solved by iterating over the string and performing a move whenever an 'X' is encountered. After each move, skip the next two characters since they have been converted to 'O'.

### Initial Thoughts 💭
- The minimum number of moves corresponds to the number of non-overlapping consecutive 'X' blocks of length 3.
- A greedy approach can be applied: for each 'X' encountered, immediately make a move and move ahead by 3 characters.
{{< dots >}}
### Edge Cases 🌐
- Not applicable, as the string length is at least 3.
- Ensure that the solution runs efficiently even for the maximum input size (1000 characters).
- If the string contains only 'O's, no moves are needed.
- The approach should work within the time limits for the maximum input size.
{{< dots >}}
## Code 💻
```cpp
int minimumMoves(string s) {
    int i = 0, n = s.length(), count = 0;
    while (i < n) {
        if (s[i] == 'O')
            i++;
        else
            count++, i += 3;
    }
    return count;
}
```

This function computes the minimum number of moves required to convert a string containing 'X' and 'O' into a string of all 'O's. Each move involves changing up to three consecutive 'X's to 'O's.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minimumMoves(string s) {
	```
	This defines the function 'minimumMoves' which takes a string 's' containing 'X' and 'O' and returns the minimum number of moves required to convert all 'X's to 'O's.

2. **Variable Initialization**
	```cpp
	    int i = 0, n = s.length(), count = 0;
	```
	Here, three variables are initialized: 'i' for the current index, 'n' for the length of the string, and 'count' to keep track of the number of moves.

3. **Loop Start**
	```cpp
	    while (i < n) {
	```
	This starts a while loop that iterates over the string until all characters are processed.

4. **Condition Check**
	```cpp
	        if (s[i] == 'O')
	```
	This checks if the current character is 'O'. If it is, we simply move to the next character without making any changes.

5. **Index Increment**
	```cpp
	            i++;
	```
	If the current character is 'O', we increment 'i' to move to the next character.

6. **Condition Else**
	```cpp
	        else
	```
	If the current character is 'X', we need to make a move.

7. **Move Calculation**
	```cpp
	            count++, i += 3;
	```
	In this case, we increment the move count by 1 and move the index 'i' forward by 3 to simulate changing up to three 'X's to 'O's in one move.

8. **Return Statement**
	```cpp
	    return count;
	```
	This returns the total number of moves calculated to convert all 'X's in the string to 'O's.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution involves a single traversal of the string, making it O(n) in all cases.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as the algorithm only requires a few variables for counting and indexing.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-moves-to-convert-string/description/)

---
{{< youtube hCuwkDkAXYM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
