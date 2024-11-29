
+++
authors = ["grid47"]
title = "Leetcode 1073: Adding Two Negabinary Numbers"
date = "2024-07-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1073: Adding Two Negabinary Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "mrK37adgvjo"
youtube_upload_date="2019-12-21"
youtube_thumbnail="https://i.ytimg.com/vi_webp/mrK37adgvjo/maxresdefault.webp"
comments = true
+++



---
You are given two numbers represented in base -2. Each number is given as an array of binary digits (0s and 1s), where the most significant bit is at the beginning of the array. Your task is to add these two numbers together and return the result in the same format, as an array of 0s and 1s in base -2, without leading zeros.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two arrays, arr1 and arr2, each representing a number in base -2. The arrays contain binary digits, where arr1[i] and arr2[i] are either 0 or 1, and there are no leading zeros in either array.
- **Example:** `Input: arr1 = [1, 0, 1], arr2 = [1, 1]`
- **Constraints:**
	- 1 <= arr1.length, arr2.length <= 1000
	- arr1[i] and arr2[i] are 0 or 1
	- arr1 and arr2 have no leading zeros

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an array of binary digits representing the sum of the two input numbers in base -2, with no leading zeros.
- **Example:** `Output: [1, 0, 0, 0]`
- **Constraints:**
	- The output should be a binary array representing the sum of the numbers in base -2.

{{< dots >}}
### Core Logic 🔍
**Goal:** To add two numbers in base -2 and return the result in base -2 format without leading zeros.

- 1. Initialize a carry variable to store any carryover during the addition process.
- 2. Traverse both arrays from the least significant bit to the most significant bit.
- 3. Add the corresponding bits from both arrays along with the carry, and store the result in the result array.
- 4. If the sum of bits results in a carry, update the carry variable.
- 5. Continue this process until all bits have been added, and ensure the result array has no leading zeros.
{{< dots >}}
### Problem Assumptions ✅
- The input arrays represent valid binary numbers in base -2.
- The solution should handle arrays of varying lengths efficiently.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: arr1 = [1, 0, 1], arr2 = [1, 1]`  \
  **Explanation:** The number represented by arr1 is 5 and the number represented by arr2 is 3. Their sum is 8, which is represented as [1, 0, 0, 0] in base -2.

- **Input:** `Input: arr1 = [1, 0, 1], arr2 = [0]`  \
  **Explanation:** The number represented by arr1 is 5 and arr2 is 0. The sum is 5, represented as [1, 0, 1].

{{< dots >}}
## Approach 🚀
We can solve this problem by simulating the addition of binary digits with base -2. The carry needs to be handled as we traverse through the arrays, and the result should be constructed accordingly.

### Initial Thoughts 💭
- Each array is a representation of a number in base -2, and we need to perform addition similarly to binary addition, but with negative powers of 2.
- We need to handle carries properly, as base -2 has alternating signs for powers of 2.
- The solution should process each digit from least significant to most significant and adjust for carries using the base -2 arithmetic.
{{< dots >}}
### Edge Cases 🌐
- Both input arrays cannot be empty. Each array must represent a valid binary number in base -2.
- Ensure that the solution is efficient and handles arrays with lengths up to 1000 elements.
- If one of the input arrays represents zero, the other array should be returned as the result.
- The solution should handle arrays of varying lengths and ensure correct handling of carries.
{{< dots >}}
## Code 💻
```cpp
vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
    int carry = 0, i = arr1.size() -1, j = arr2.size() -1;
    vector<int> res;
    while(carry || i >= 0 || j >= 0) {
        if(i >= 0) carry += arr1[i--];
        if(j >= 0) carry += arr2[j--];
        res.push_back(carry&1);
        carry = -(carry>>1);
    }
    while(res.size() > 1 && res.back() == 0)
        res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}
```

This code defines the function `addNegabinary` which adds two binary numbers represented as vectors in negabinary (base -2) system. The result is returned as a vector of integers representing the sum in the same negabinary format.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
	```
	This line defines the function `addNegabinary` that takes two vectors `arr1` and `arr2`, representing binary numbers in negabinary format, and returns the result of their sum as a vector.

2. **Variable Initialization**
	```cpp
	    int carry = 0, i = arr1.size() -1, j = arr2.size() -1;
	```
	This line initializes the carry variable to store the carry during addition. It also initializes indices `i` and `j` to point to the last elements of `arr1` and `arr2`, respectively.

3. **Result Vector Initialization**
	```cpp
	    vector<int> res;
	```
	This line initializes the vector `res` which will store the result of the negabinary sum.

4. **Main While Loop**
	```cpp
	    while(carry || i >= 0 || j >= 0) {
	```
	This loop continues until there are no more digits left to add in either of the input vectors or there is no carry left.

5. **Adding from First Vector**
	```cpp
	        if(i >= 0) carry += arr1[i--];
	```
	This line adds the current digit from `arr1` to the carry (if `i` is valid), and then decrements the index `i`.

6. **Adding from Second Vector**
	```cpp
	        if(j >= 0) carry += arr2[j--];
	```
	This line adds the current digit from `arr2` to the carry (if `j` is valid), and then decrements the index `j`.

7. **Store Result Bit**
	```cpp
	        res.push_back(carry&1);
	```
	This line adds the least significant bit of `carry` to the result vector `res`. The bit is obtained by performing a bitwise AND operation with 1.

8. **Update Carry**
	```cpp
	        carry = -(carry>>1);
	```
	This line updates the carry for the next iteration by right-shifting the carry by one position (effectively dividing by 2) and then negating the result, as negabinary uses base -2.

9. **Remove Leading Zeros**
	```cpp
	    while(res.size() > 1 && res.back() == 0)
	```
	This loop removes leading zeros from the result vector `res` by checking if the last element is 0 and the vector has more than one element.

10. **Pop Back Zeros**
	```cpp
	        res.pop_back();
	```
	This line removes the last element of the result vector, which is a leading zero.

11. **Reverse Result**
	```cpp
	    reverse(res.begin(), res.end());
	```
	This line reverses the result vector `res` so that the digits are in the correct order, as the least significant bit was added first.

12. **Return Statement**
	```cpp
	    return res;
	```
	This line returns the final result vector `res`, which contains the negabinary sum of the input vectors.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(max(m, n))
- **Average Case:** O(max(m, n))
- **Worst Case:** O(max(m, n))

The time complexity is O(max(m, n)) because we process each digit of both arrays at most once.

### Space Complexity 💾
- **Best Case:** O(max(m, n))
- **Worst Case:** O(max(m, n))

The space complexity is O(max(m, n)) due to the space required to store the result array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/adding-two-negabinary-numbers/description/)

---
{{< youtube mrK37adgvjo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
