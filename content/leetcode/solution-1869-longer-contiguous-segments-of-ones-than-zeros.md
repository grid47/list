
+++
authors = ["grid47"]
title = "Leetcode 1869: Longer Contiguous Segments of Ones than Zeros"
date = "2024-05-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1869: Longer Contiguous Segments of Ones than Zeros in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "K0WT66cPNmo"
youtube_upload_date="2021-05-23"
youtube_thumbnail="https://i.ytimg.com/vi_webp/K0WT66cPNmo/maxresdefault.webp"
comments = true
+++



---
You are given a binary string s. Your task is to determine whether the longest contiguous segment of 1's is strictly longer than the longest contiguous segment of 0's. Return true if this condition holds, otherwise return false.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary string s containing only '0' and '1'.
- **Example:** `"101100101"`
- **Constraints:**
	- 1 <= s.length <= 100
	- s[i] is either '0' or '1'

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if the longest contiguous segment of 1's is strictly longer than the longest contiguous segment of 0's; otherwise return false.
- **Example:** `true`
- **Constraints:**
	- The result is a boolean value (true or false).

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the longest contiguous segments of 1's and 0's in the binary string and compare their lengths.

- Iterate through the string to identify the lengths of contiguous segments of 1's and 0's.
- Track the maximum length of the 1's and 0's segments.
- Return true if the longest 1's segment is longer than the longest 0's segment; otherwise return false.
{{< dots >}}
### Problem Assumptions ✅
- The input string s is valid, containing only '0' or '1'.
{{< dots >}}
## Examples 🧩
- **Input:** `"10101"`  \
  **Explanation:** In this example, the longest contiguous segment of 1's is 2, and the longest contiguous segment of 0's is 1, so the answer is true.

{{< dots >}}
## Approach 🚀
The approach is to scan through the binary string, track the longest contiguous segments of 1's and 0's, and then compare their lengths.

### Initial Thoughts 💭
- We need to handle both the 1's and 0's segments efficiently.
- It would be efficient to iterate through the string once and calculate the maximum lengths of both 1's and 0's.
{{< dots >}}
### Edge Cases 🌐
- The string is never empty based on the given constraints.
- For large strings, the approach should still work in O(n) time complexity.
- When the string consists entirely of 0's or 1's, the answer should be determined based on the other segment's length being 0.
- Handle strings with a mix of 1's and 0's, as well as strings consisting of only 1's or only 0's.
{{< dots >}}
## Code 💻
```cpp
bool checkZeroOnes(string s) {
    int z = 0, o = 0, gz = 0, oz = 0, res = 1;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '0') z++;
        else z = 0;
        if(s[i] == '1') o++;
        else o = 0;
        gz = max(gz, z);
        oz = max(oz, o);
    }
    return oz > gz;
}
```

This code defines a function `checkZeroOnes` that checks if the longest contiguous sequence of 1's in a given binary string is longer than the longest contiguous sequence of 0's. The function keeps track of the count of consecutive 0's and 1's, updates the maximum counts, and returns whether the sequence of 1's is longer than the sequence of 0's.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool checkZeroOnes(string s) {
	```
	Define the `checkZeroOnes` function, which accepts a string `s` representing a binary number and returns a boolean indicating whether the longest sequence of 1's is longer than the longest sequence of 0's.

2. **Variable Declaration**
	```cpp
	    int z = 0, o = 0, gz = 0, oz = 0, res = 1;
	```
	Declare integer variables to track the number of consecutive 0's (`z`), 1's (`o`), and their respective maximum counts (`gz` for 0's and `oz` for 1's). A variable `res` is also initialized but not used in this implementation.

3. **Loop Initialization**
	```cpp
	    for(int i = 0; i < s.size(); i++) {
	```
	Start a loop that iterates over each character in the input string `s`.

4. **Condition Check (Zero)**
	```cpp
	        if(s[i] == '0') z++;
	```
	Check if the current character is '0'. If true, increment the count of consecutive 0's (`z`).

5. **Reset Zero Count**
	```cpp
	        else z = 0;
	```
	If the current character is not '0', reset the count of consecutive 0's (`z`) to 0.

6. **Condition Check (One)**
	```cpp
	        if(s[i] == '1') o++;
	```
	Check if the current character is '1'. If true, increment the count of consecutive 1's (`o`).

7. **Reset One Count**
	```cpp
	        else o = 0;
	```
	If the current character is not '1', reset the count of consecutive 1's (`o`) to 0.

8. **Update Max Zero Count**
	```cpp
	        gz = max(gz, z);
	```
	Update the maximum count of consecutive 0's (`gz`) to the greater of the current `gz` and the current count of consecutive 0's (`z`).

9. **Update Max One Count**
	```cpp
	        oz = max(oz, o);
	```
	Update the maximum count of consecutive 1's (`oz`) to the greater of the current `oz` and the current count of consecutive 1's (`o`).

10. **Return Statement**
	```cpp
	    return oz > gz;
	```
	Return a boolean indicating whether the longest sequence of 1's (`oz`) is greater than the longest sequence of 0's (`gz`).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) where n is the length of the string.
- **Average Case:** O(n) for each scan through the string.
- **Worst Case:** O(n) for a string of length n, as we must traverse the entire string.

The time complexity is linear because we only iterate through the string once.

### Space Complexity 💾
- **Best Case:** O(1) for the same reason.
- **Worst Case:** O(1) since we are using only a few variables to track the maximum segment lengths.

The space complexity is constant because no additional data structures are needed.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/description/)

---
{{< youtube K0WT66cPNmo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
