
+++
authors = ["grid47"]
title = "Leetcode 344: Reverse String"
date = "2024-10-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 344: Reverse String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/344.webp"
youtube = "P68JPXtFyYg"
youtube_upload_date="2020-01-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/P68JPXtFyYg/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/344.webp" 
    alt="A string gently reversing itself, with the characters softly shifting places in a calming, fluid motion."
    caption="Solution to LeetCode 344: Reverse String Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a list of characters s. Your task is to reverse the order of characters in the list in-place, modifying the input list directly and without using any extra memory.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a list of characters.
- **Example:** `s = ["a", "b", "c", "d"]`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- Each character in the list is a printable ASCII character.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the input list with the characters reversed in place.
- **Example:** `["d", "c", "b", "a"]`
- **Constraints:**
	- The input list must be modified in-place.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to reverse the list of characters in place, without using extra memory.

- Initialize two pointers, one at the start and the other at the end of the list.
- Swap the characters at these two pointers and move the pointers towards each other.
- Continue swapping until the pointers meet or cross.
{{< dots >}}
### Problem Assumptions ✅
- The input is a valid list of printable ASCII characters.
{{< dots >}}
## Examples 🧩
- **Input:** `s = ["a","b","c","d"]`  \
  **Explanation:** The list is reversed in place, resulting in ["d","c","b","a"].

- **Input:** `s = ["r","e","v","e","r","s","e"]`  \
  **Explanation:** The list is reversed in place, resulting in ["e","s","r","e","v","e","r"].

{{< dots >}}
## Approach 🚀
The solution involves reversing the input list in place by swapping elements from both ends towards the center.

### Initial Thoughts 💭
- The problem requires modifying the list directly, using two pointers to swap elements in place.
- The approach should use constant space and iterate through the list in a linear fashion.
{{< dots >}}
### Edge Cases 🌐
- The input list should not be empty as the length is guaranteed to be >= 1.
- The solution must be efficient enough to handle input sizes up to 100,000.
- When the list has only one character, the list remains unchanged after reversal.
- The solution must operate in O(n) time complexity and O(1) space complexity.
{{< dots >}}
## Code 💻
```cpp
void reverseString(vector<char>& s) {
    int i = 0, j = s.size() - 1;
    while(i <= j) {
        swap(s[i++], s[j--]);
    }
}
```

This function reverses a string in-place by swapping characters from both ends until the entire string is reversed. The time complexity is O(n), where n is the number of characters in the string.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	void reverseString(vector<char>& s) {
	```
	This is the function declaration for `reverseString`. The function takes a reference to a vector of characters, `s`, and modifies it to reverse the characters in place.

2. **Variable Initialization**
	```cpp
	    int i = 0, j = s.size() - 1;
	```
	Initialize two pointers: `i` starts at the beginning of the vector, and `j` starts at the end of the vector. These pointers will be used to swap characters from both ends.

3. **Loop Until Pointers Meet**
	```cpp
	    while(i <= j) {
	```
	The while loop continues as long as `i` is less than or equal to `j`. This ensures that we are swapping characters until the pointers meet or cross.

4. **Swap Characters**
	```cpp
	        swap(s[i++], s[j--]);
	```
	Swap the characters at positions `i` and `j`. The `i++` and `j--` increment and decrement the pointers after each swap to move toward the center of the vector.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear since the solution requires a single pass over the list.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant since the solution only uses two pointers.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/reverse-string/description/)

---
{{< youtube P68JPXtFyYg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
