
+++
authors = ["grid47"]
title = "Leetcode 844: Backspace String Compare"
date = "2024-08-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 844: Backspace String Compare in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Stack","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "TOwf2xKKfJ8"
youtube_upload_date="2020-04-09"
youtube_thumbnail="https://i.ytimg.com/vi_webp/TOwf2xKKfJ8/maxresdefault.webp"
comments = true
+++



---
You are given an integer array `arr`. A mountain array is an array where the elements first strictly increase to a peak and then strictly decrease after that peak. Your task is to find the length of the longest mountain subarray in the given array. If no such subarray exists, return 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array 'arr' where the elements are non-negative integers.
- **Example:** `Input: arr = [3, 2, 5, 6, 4, 3, 1]`
- **Constraints:**
	- 1 <= arr.length <= 10^4
	- 0 <= arr[i] <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the longest mountain subarray in the given array. If no such subarray exists, return 0.
- **Example:** `Output: 5`
- **Constraints:**
	- The array must have at least 3 elements to form a mountain.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the longest subarray that first strictly increases and then strictly decreases.

- Step 1: Traverse through the array and find all potential peaks where the element is greater than its neighbors.
- Step 2: For each peak, expand to the left and right to determine the length of the mountain.
- Step 3: Keep track of the longest mountain found during the traversal.
{{< dots >}}
### Problem Assumptions ✅
- The array is not empty.
- You are working with integer values only.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: [3, 2, 5, 6, 4, 3, 1]`  \
  **Explanation:** The longest mountain is [5, 6, 4, 3], which has length 5.

- **Input:** `Input: [1, 2, 3, 4]`  \
  **Explanation:** There is no mountain because the array only increases.

- **Input:** `Input: [9, 8, 7]`  \
  **Explanation:** There is no mountain because the array only decreases.

{{< dots >}}
## Approach 🚀
The approach involves scanning through the array to find peaks and expanding from those peaks to check for valid mountains. This can be done in a single pass with careful checking of elements before and after the peak.

### Initial Thoughts 💭
- The problem requires finding subarrays with a specific structure (strictly increasing and then strictly decreasing).
- We can utilize a two-pointer or sliding window technique to efficiently check for the longest mountain.
- A linear pass through the array could be sufficient if we check each element to see if it's a peak, and then expand outwards to find the boundaries of the mountain.
{{< dots >}}
### Edge Cases 🌐
- The input cannot be empty as the array must contain at least 3 elements.
- Ensure that the solution handles large inputs efficiently, especially when the array length is at the upper constraint of 10^4.
- Arrays with all elements the same do not form a mountain.
- Arrays that strictly increase or strictly decrease will not form a valid mountain.
- Arrays with fewer than 3 elements cannot form a valid mountain.
{{< dots >}}
## Code 💻
```cpp
bool backspaceCompare(string S, string T) {
    int i = S.length() - 1, j = T.length() - 1, back;
    while (true) {
        back = 0;
        while (i >= 0 && (back > 0 || S[i] == '#')) {
            back += S[i] == '#' ? 1 : -1;
            i--;
        }
        back = 0;
        while (j >= 0 && (back > 0 || T[j] == '#')) {
            back += T[j] == '#' ? 1 : -1;
            j--;
        }
        if (i >= 0 && j >= 0 && S[i] == T[j]) {
            i--;
            j--;
        } else {
            break;
        }
    }
    return i == -1 && j == -1;        
}
```

This function compares two strings, `S` and `T`, considering backspaces represented by '#' characters. It simulates the process of typing each string with backspaces and checks if the resulting strings are identical.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool backspace Compare(string S, string T) {
	```
	Defines the function `backspace Compare` that takes two strings `S` and `T` and compares them after processing the backspaces.

2. **Variable Initialization**
	```cpp
	    int i = S.length() - 1, j = T.length() - 1, back;
	```
	Initializes two pointers, `i` and `j`, to point to the end of both strings, and a variable `back` to track the number of backspaces.

3. **Loop Start**
	```cpp
	    while (true) {
	```
	Starts an infinite loop to process the strings until the end of the comparison.

4. **Variable Reset**
	```cpp
	        back = 0;
	```
	Resets the `back` variable to 0 at the start of each loop iteration.

5. **Backspace Processing S**
	```cpp
	        while (i >= 0 && (back > 0 || S[i] == '#')) {
	```
	Processes the string `S` by skipping characters that are backspaces or undoing the effect of backspaces.

6. **Update Back**
	```cpp
	            back += S[i] == '#' ? 1 : -1;
	```
	Updates the `back` variable, incrementing it when a backspace ('#') is encountered and decrementing it otherwise.

7. **Pointer Decrement S**
	```cpp
	            i--;
	```
	Moves the pointer `i` to the previous character in string `S`.

8. **Variable Reset Again**
	```cpp
	        back = 0;
	```
	Resets the `back` variable before processing the string `T`.

9. **Backspace Processing T**
	```cpp
	        while (j >= 0 && (back > 0 || T[j] == '#')) {
	```
	Processes string `T` by skipping backspaces or undoing the effect of backspaces.

10. **Update Back Again**
	```cpp
	            back += T[j] == '#' ? 1 : -1;
	```
	Updates the `back` variable for string `T`, incrementing for backspaces and decrementing otherwise.

11. **Pointer Decrement T**
	```cpp
	            j--;
	```
	Moves the pointer `j` to the previous character in string `T`.

12. **Character Comparison**
	```cpp
	        if (i >= 0 && j >= 0 && S[i] == T[j]) {
	```
	Compares the characters at positions `i` and `j` in `S` and `T`.

13. **Pointer Decrement Both**
	```cpp
	            i--;
	```
	Moves the pointer `i` to the previous character in string `S`.

14. **Pointer Decrement Both**
	```cpp
	            j--;
	```
	Moves the pointer `j` to the previous character in string `T`.

15. **Mismatch Found**
	```cpp
	        } else {
	```
	Handles the case where the characters at `S[i]` and `T[j]` do not match.

16. **Exit Loop**
	```cpp
	            break;
	```
	Exits the loop when a mismatch is found.

17. **Final Check**
	```cpp
	    return i == -1 && j == -1;        
	```
	Returns `true` if both strings `S` and `T` have been fully processed and no mismatches were found; otherwise, returns `false`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear as we make a single pass over the array, with constant time checks for each element.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant since we only need a few variables to track the peak and the longest mountain length.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/backspace-string-compare/description/)

---
{{< youtube TOwf2xKKfJ8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
