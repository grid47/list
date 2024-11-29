
+++
authors = ["grid47"]
title = "Leetcode 66: Plus One"
date = "2024-10-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 66: Plus One in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/66.webp"
youtube = "tDjI08W1I7g"
youtube_upload_date="2022-03-07"
youtube_thumbnail="https://i.ytimg.com/vi/tDjI08W1I7g/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/66.webp" 
    alt="A glowing number gently increasing by one, signifying growth and positivity."
    caption="Solution to LeetCode 66: Plus One Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a large integer represented as an array of digits. Each digits[i] represents the ith digit of the integer, arranged from most significant to least significant. The task is to increment the integer by one and return the resulting digits as an array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An integer array digits where each element is a single digit of a number.
- **Example:** `Input: digits = [2,4,6]`
- **Constraints:**
	- 1 <= digits.length <= 100
	- 0 <= digits[i] <= 9
	- digits[0] != 0 (no leading zeros)

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array representing the incremented value of the given integer.
- **Example:** `Output: [2,4,7]`
- **Constraints:**
	- The output array should be of size digits.length or digits.length + 1, depending on whether a carry was generated.

{{< dots >}}
### Core Logic 🔍
**Goal:** Increment the integer represented by the array by one and return the resulting digits as an array.

- Initialize a variable to handle the carry, starting with a value of 1 (representing the increment).
- Iterate over the digits array from the least significant digit to the most significant.
- Add the carry to the current digit. Update the digit to the modulo 10 of the sum, and update the carry as the integer division of the sum by 10.
- If the carry remains after the iteration, prepend it to the array.
- Return the resulting array.
{{< dots >}}
### Problem Assumptions ✅
- The input array will always represent a valid non-negative integer.
- The result will fit within the array size constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: digits = [2,4,6]`  \
  **Explanation:** The array represents the number 246. Adding one gives 246 + 1 = 247, so the output is [2,4,7].

- **Input:** `Input: digits = [5,9,9]`  \
  **Explanation:** The array represents the number 599. Adding one gives 599 + 1 = 600, so the output is [6,0,0].

{{< dots >}}
## Approach 🚀
Use an iterative approach starting from the least significant digit, handling any carry generated at each step. If there's a carry left after iterating through all digits, prepend it to the array.

### Initial Thoughts 💭
- The task involves managing carries as you increment the number represented by the array.
- The most significant digit might need to expand the array if a carry remains after processing all digits.
- Start with the least significant digit and propagate the carry towards the most significant digit.
{{< dots >}}
### Edge Cases 🌐
- Not applicable as digits.length >= 1 is guaranteed.
- A 100-digit array with the last digit causing a carry that propagates through all digits.
- A single-digit array [9], which becomes [1,0].
- An array with all digits being 9, such as [9,9,9], which becomes [1,0,0,0].
- Ensure the output correctly reflects carry propagation, even for very large arrays.
{{< dots >}}
## Code 💻
```cpp
vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    for (int i = n - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            return digits;
        }
        digits[i] = 0;
    }

    // If we reach here, all digits were 9, so we need to add a new digit
    vector<int> result(n + 1, 0);
    result[0] = 1;
    return result;
}
```

This code adds one to a given number represented as an array of digits.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> plusOne(vector<int>& digits) {
	```
	This line declares a function named `plusOne` that takes a vector of digits `digits` as input and returns a vector representing the incremented number.

2. **Get Number of Digits**
	```cpp
	    int n = digits.size();
	```
	This line gets the number of digits in the input number.

3. **Iterate from Rightmost Digit**
	```cpp
	    for (int i = n - 1; i >= 0; i--) {
	```
	This loop iterates through the digits of the number from right to left.

4. **Check for Carryover**
	```cpp
	        if (digits[i] < 9) {
	```
	This condition checks if the current digit is less than 9. If so, it means we can simply increment it and return the result.

5. **Increment Digit**
	```cpp
	            digits[i]++;
	```
	This line increments the current digit by 1.

6. **Return the Result**
	```cpp
	            return digits;
	```
	This line returns the modified `digits` vector, which now represents the incremented number.

7. **Handle Carryover**
	```cpp
	        digits[i] = 0;
	```
	If the current digit is 9, we set it to 0 and continue to the next digit, carrying over the 1.

8. **Handle Carryover to the Leftmost Digit**
	```cpp
	    // If we reach here, all digits were 9, so we need to add a new digit
	    vector<int> result(n + 1, 0);
	    result[0] = 1;
	```
	If we reach the end of the loop without finding a digit less than 9, it means all digits were 9. In this case, we need to create a new vector with one extra digit, set the first digit to 1, and return it.

9. **Return the Result**
	```cpp
	    return result;
	```
	This line returns the newly created vector representing the incremented number.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

We process each digit once, resulting in a linear time complexity.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

Space is O(1) if the input can be modified in-place; otherwise, O(n) for the output array in case of carry propagation.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/plus-one/description/)

---
{{< youtube tDjI08W1I7g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
