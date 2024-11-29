
+++
authors = ["grid47"]
title = "Leetcode 868: Binary Gap"
date = "2024-08-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 868: Binary Gap in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Bit Manipulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "I5pfHLmrBrA"
youtube_upload_date="2024-05-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/I5pfHLmrBrA/maxresdefault.webp"
comments = true
+++



---
Given a positive integer `n`, determine the maximum distance between any two adjacent 1's in the binary representation of `n`. Two 1's are adjacent if only 0's separate them. If there are no two adjacent 1's, return 0. The distance between two 1's is the absolute difference in their positions when counting from the rightmost bit.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A single positive integer `n`.
- **Example:** `Input: n = 13`
- **Constraints:**
	- 1 <= n <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum distance between any two adjacent 1's in the binary representation of `n`. If there are no adjacent 1's, return 0.
- **Example:** `Output: 2`
- **Constraints:**
	- The output is a single integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the longest distance between any two adjacent 1's in the binary representation of `n`.

- Convert the number `n` into its binary representation.
- Identify the positions of all 1's in the binary string.
- Calculate the distances between consecutive 1's.
- Return the maximum distance found.
{{< dots >}}
### Problem Assumptions ✅
- Input `n` is always a valid positive integer within the specified range.
- The binary representation of `n` has at least one 1.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 13`  \
  **Explanation:** Binary representation of 13 is '1101'. The distances between adjacent 1's are 2 (positions 1 and 3) and 1 (positions 3 and 4). The maximum distance is 2.

- **Input:** `Input: n = 2`  \
  **Explanation:** Binary representation of 2 is '10'. There are no two adjacent 1's, so the output is 0.

- **Input:** `Input: n = 21`  \
  **Explanation:** Binary representation of 21 is '10101'. The distances between adjacent 1's are 2 (positions 1 and 3) and 2 (positions 3 and 5). The maximum distance is 2.

{{< dots >}}
## Approach 🚀
Iterate through the binary representation of `n` while keeping track of the positions of 1's and computing the distances between consecutive 1's.

### Initial Thoughts 💭
- The binary representation of any number is finite.
- We only need to calculate distances between positions of 1's.
- Iterate through the binary digits to find the indices of 1's.
- Track the maximum distance dynamically while traversing.
{{< dots >}}
### Edge Cases 🌐
- Not applicable as `n` is always provided.
- Handle binary representations of numbers close to 10^9 efficiently.
- Inputs like `n = 1` (binary '1') should return 0.
- Inputs like `n = 2` (binary '10') should return 0.
- Ensure the function runs in O(log n) time complexity.
{{< dots >}}
## Code 💻
```cpp
int binaryGap(int n) {
    int res = 0;
    for (int d = -32; n; n >>=1, d++)
        if (n % 2) 
        { 
            res = max(res, d);
            d   = 0;
        }
    return res;
}
```

This code defines a function to find the maximum binary gap in an integer. It iterates through the bits of the number and tracks the longest sequence of consecutive 0s between 1s.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int binaryGap(int n) {
	```
	The function definition for `binaryGap`, which takes an integer `n` and returns the length of its longest sequence of consecutive 0s in its binary representation.

2. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	Initializes the result variable `res` to store the maximum binary gap found during the iteration.

3. **Loop Setup**
	```cpp
	    for (int d = -32; n; n >>=1, d++)
	```
	Sets up a loop to iterate over the bits of `n`. The variable `d` tracks the distance from the last 1-bit, starting from -32.

4. **Condition Check**
	```cpp
	        if (n % 2) 
	```
	Checks if the current bit is 1 by using the modulus operator.

5. **Block Start**
	```cpp
	        { 
	```
	Begins the block of code to execute when a 1-bit is found.

6. **Max Gap Calculation**
	```cpp
	            res = max(res, d);
	```
	Updates the result `res` with the maximum of the current `res` and the value of `d`, which represents the current gap between 1s.

7. **Reset Distance**
	```cpp
	            d   = 0;
	```
	Resets the distance variable `d` to 0 after finding a 1-bit, as the gap calculation restarts.

8. **Block End**
	```cpp
	        }
	```
	Ends the block of code for when a 1-bit is encountered.

9. **Return Statement**
	```cpp
	    return res;
	```
	Returns the maximum binary gap found during the loop.

10. **Function End**
	```cpp
	}
	```
	Marks the end of the `binaryGap` function.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log n)
- **Average Case:** O(log n)
- **Worst Case:** O(log n)

The binary representation of `n` has at most log n bits, so the solution iterates through each bit.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space used is constant, as we only maintain a few variables for calculations.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/binary-gap/description/)

---
{{< youtube I5pfHLmrBrA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
