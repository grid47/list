
+++
authors = ["grid47"]
title = "Leetcode 2839: Check if Strings Can be Made Equal With Operations I"
date = "2024-01-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2839: Check if Strings Can be Made Equal With Operations I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "b46PWRWHFp4"
youtube_upload_date="2023-09-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/b46PWRWHFp4/maxresdefault.webp"
comments = true
+++



---
You are given two strings s1 and s2, each consisting of 4 lowercase English letters. You can perform a specific operation multiple times, where you swap two characters at indices i and j such that j - i = 2. The task is to determine if it's possible to make s1 equal to s2 after performing any number of such operations.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two strings, s1 and s2, each containing 4 lowercase English letters.
- **Example:** `s1 = 'abcd', s2 = 'cdab'`
- **Constraints:**
	- Both s1 and s2 have a length of 4.
	- Both strings consist only of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if it's possible to make the two strings equal using the described operations, otherwise return false.
- **Example:** `true`
- **Constraints:**
	- The output should be a boolean value indicating whether the strings can be made equal or not.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if it's possible to transform s1 into s2 using the allowed operations.

- Check if s1 is already equal to s2.
- If not, attempt to swap characters at indices (0, 2) and (1, 3).
- If the resulting string matches s2 after any number of swaps, return true.
- If no such transformation is possible, return false.
{{< dots >}}
### Problem Assumptions ✅
- Only the swap operation between indices (i, j) where j - i = 2 is allowed.
- Both input strings are of the same length (4).
{{< dots >}}
## Examples 🧩
- **Input:** `s1 = 'abcd', s2 = 'cdab'`  \
  **Explanation:** We can swap characters at indices (0, 2) and (1, 3) to transform s1 into s2.

- **Input:** `s1 = 'abcd', s2 = 'dacb'`  \
  **Explanation:** No number of swaps can make s1 equal to s2.

{{< dots >}}
## Approach 🚀
The problem can be solved by checking if it's possible to transform s1 into s2 by performing the allowed swap operations.

### Initial Thoughts 💭
- We are given that both strings are of length 4, so there are only a limited number of swap operations to check.
- By swapping characters at indices (0, 2) and (1, 3), we should be able to check if the strings can be made equal.
{{< dots >}}
### Edge Cases 🌐
- Since the strings always have a length of 4, empty inputs are not possible.
- The problem has a fixed size input (length of 4), so large inputs are not a concern.
- The strings may consist of identical characters or all different characters.
- Ensure that the logic works within the fixed input size.
{{< dots >}}
## Code 💻
```cpp
bool canBeEqual(string s1, string s2) {
    if(s1 == s2) return true;
    
    if(s1[0] != s2[0]) swap(s1[0],s1[2]);
    if(s1 == s2) return true;
    
    if(s1[1] != s2[1]) swap(s1[1],s1[3]);
    if(s1 == s2) return true;
    
    return false;
}
```

The provided code compares two strings by swapping characters and checking if they become equal.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Initialization**
	```cpp
	bool canBeEqual(string s1, string s2) {
	```
	Function definition to check if two strings can be made equal by swapping characters.

2. **Base Case**
	```cpp
	    if(s1 == s2) return true;
	```
	Base case check if both strings are already equal.

3. **Swap Step 1**
	```cpp
	    if(s1[0] != s2[0]) swap(s1[0],s1[2]);
	```
	Checks if the first characters are unequal, swaps the first and third characters of s1.

4. **Base Case**
	```cpp
	    if(s1 == s2) return true;
	```
	Checks again if the strings are now equal after the first swap.

5. **Swap Step 2**
	```cpp
	    if(s1[1] != s2[1]) swap(s1[1],s1[3]);
	```
	Checks if the second characters are unequal, swaps the second and fourth characters of s1.

6. **Base Case**
	```cpp
	    if(s1 == s2) return true;
	```
	Checks again if the strings are now equal after the second swap.

7. **Return**
	```cpp
	    return false;
	```
	Returns false if the strings are still not equal after the swaps.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The time complexity is constant as the input size is fixed at 4.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as we only need a few variables to store the strings.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/description/)

---
{{< youtube b46PWRWHFp4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
