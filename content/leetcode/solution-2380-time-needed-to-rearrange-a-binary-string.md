
+++
authors = ["grid47"]
title = "Leetcode 2380: Time Needed to Rearrange a Binary String"
date = "2024-03-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2380: Time Needed to Rearrange a Binary String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "fP5kg4ETjUc"
youtube_upload_date="2022-08-20"
youtube_thumbnail="https://i.ytimg.com/vi_webp/fP5kg4ETjUc/maxresdefault.webp"
comments = true
+++



---
You are given a binary string `s`. In one second, all occurrences of the substring '01' are simultaneously replaced with '10'. This process repeats until no occurrences of '01' exist in the string. The task is to return the number of seconds required to complete this process.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary string `s` where each character is either '0' or '1'.
- **Example:** `s = '0101011'`
- **Constraints:**
	- 1 <= s.length <= 1000
	- s[i] is either '0' or '1'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of seconds required to ensure that no occurrences of '01' exist in the string.
- **Example:** `Output: 3`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to simulate the process of replacing all occurrences of '01' with '10' and count the number of seconds until no such occurrences remain.

- 1. Traverse the string and look for occurrences of '01'.
- 2. Swap every occurrence of '01' to '10'.
- 3. Count each second where at least one swap occurs.
- 4. Repeat until no '01' substrings remain in the string.
{{< dots >}}
### Problem Assumptions ✅
- The input string is valid and consists only of '0' and '1'.
- The number of operations will not exceed the time limit for strings of length up to 1000.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = '0101011'`  \
  **Explanation:** After one second, the string becomes '1010110'. After another second, it becomes '1101100'. Finally, after the third second, the string becomes '1111000'. The process requires 3 seconds in total.

- **Input:** `Input: s = '11100'`  \
  **Explanation:** No occurrence of '01' exists in the string, so no swaps are needed, and the process takes 0 seconds.

{{< dots >}}
## Approach 🚀
We can simulate the process of replacing all occurrences of '01' with '10' using a loop. After each iteration, we count the number of swaps that occurred and repeat the process until no more '01' substrings are found.

### Initial Thoughts 💭
- This problem involves repetitive operations on a string, making it suitable for simulation.
- We can solve the problem efficiently by counting the occurrences of '01' in each iteration and performing swaps until no occurrences are left.
{{< dots >}}
### Edge Cases 🌐
- The input string will never be empty.
- For large strings, ensure that the solution is optimized to avoid unnecessary recomputations.
- If the string already contains no '01' substrings, the answer will be 0.
- Ensure the solution can handle strings of length up to 1000 efficiently.
{{< dots >}}
## Code 💻
```cpp
int secondsToRemoveOccurrences(string s) {
    int seconds = 0;
    bool changed = true;
    while(changed) {
        changed = false;
        for(int i = 0; i < s.size() - 1; i++) {
            if(s[i] == '0' && s[i + 1] == '1') {
                swap(s[i], s[i + 1]);
                changed = true;
                i++;
            }
        }
        seconds += changed;
    }
    return seconds;
}
```

This function counts the minimum number of seconds required to remove all occurrences of '01' in the string `s`. In each second, all consecutive '01' pairs are swapped to '10', and the process continues until no more swaps are possible.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int secondsToRemoveOccurrences(string s) {
	```
	Defines the function `secondsToRemoveOccurrences` that takes a string `s` containing '0' and '1' characters. The function returns the number of seconds needed to remove all occurrences of '01' by swapping them into '10'.

2. **Variable Initialization**
	```cpp
	    int seconds = 0;
	```
	Initializes the `seconds` variable to track the number of seconds (or iterations) taken to remove all '01' pairs in the string `s`.

3. **Flag Initialization**
	```cpp
	    bool changed = true;
	```
	Initializes the `changed` flag to `true` to start the while loop, which will continue iterating as long as there are swaps performed.

4. **While Loop Start**
	```cpp
	    while(changed) {
	```
	Starts the `while` loop that continues as long as any swap occurs in the current iteration (i.e., as long as `changed` is `true`).

5. **Flag Reset**
	```cpp
	        changed = false;
	```
	Resets the `changed` flag to `false` at the beginning of each iteration to track whether any swap happens in this cycle.

6. **For Loop Start**
	```cpp
	        for(int i = 0; i < s.size() - 1; i++) {
	```
	Starts a for loop to iterate over each character in the string `s`, up to the second-to-last character, checking for '01' pairs.

7. **Condition Check for '01' Pair**
	```cpp
	            if(s[i] == '0' && s[i + 1] == '1') {
	```
	Checks if the current character `s[i]` is '0' and the next character `s[i + 1]` is '1', indicating a '01' pair that can be swapped.

8. **Swap '01' to '10'**
	```cpp
	                swap(s[i], s[i + 1]);
	```
	Swaps the '0' and '1' characters in the pair, changing '01' to '10'.

9. **Flag Set**
	```cpp
	                changed = true;
	```
	Sets the `changed` flag to `true` to indicate that a swap has been performed, and another iteration will be needed.

10. **Skip Next Character**
	```cpp
	                i++;
	```
	Increments `i` by an extra step to skip the next character, as it has already been swapped and does not need to be checked again in this cycle.

11. **Increment Seconds**
	```cpp
	        seconds += changed;
	```
	If any swap was made during the current iteration, the `seconds` counter is incremented by 1.

12. **Return Result**
	```cpp
	    return seconds;
	```
	Returns the total number of seconds (iterations) taken to remove all '01' pairs in the string.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity remains O(n) even in the worst case, as each pass through the string only requires linear time to detect and replace occurrences of '01'.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we are modifying the string in place and using only a few extra variables for counting and controlling the loop.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/description/)

---
{{< youtube fP5kg4ETjUc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
