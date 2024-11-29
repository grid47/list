
+++
authors = ["grid47"]
title = "Leetcode 1720: Decode XORed Array"
date = "2024-05-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1720: Decode XORed Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "sthGfBi890o"
youtube_upload_date="2021-01-10"
youtube_thumbnail="https://i.ytimg.com/vi/sthGfBi890o/maxresdefault.jpg"
comments = true
+++



---
You are given an encoded array of length `n - 1`, where each element `encoded[i]` represents the XOR of two consecutive elements in the original array `arr`, i.e., `encoded[i] = arr[i] XOR arr[i + 1]`. You are also given the first element of the original array `arr[0]`. Your task is to decode the array and return the original array `arr`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array `encoded` of length `n - 1` and an integer `first` which is the first element of the original array `arr`.
- **Example:** `Input: encoded = [5, 8, 10], first = 2`
- **Constraints:**
	- 2 <= n <= 10^4
	- encoded.length == n - 1
	- 0 <= encoded[i] <= 10^5
	- 0 <= first <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the decoded array `arr`.
- **Example:** `Output: [2, 7, 15, 5]`
- **Constraints:**
	- The decoded array will always exist and be unique.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to reverse the encoding process and reconstruct the original array `arr` using the given `encoded` array and the first element of `arr`.

- 1. Start by initializing the array `arr` with the first element `first`.
- 2. Iterate through the `encoded` array, and for each value, compute the next element in the original array using XOR: `arr[i + 1] = arr[i] XOR encoded[i]`.
- 3. Continue this process until the entire original array is reconstructed.
{{< dots >}}
### Problem Assumptions ✅
- It is guaranteed that a unique solution exists for every input.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: encoded = [1, 2, 3], first = 1`  \
  **Explanation:** The original array is `[1, 0, 2, 1]`. Using the formula `arr[i+1] = arr[i] XOR encoded[i]`, we can reconstruct the array as follows: `arr[0] = 1`, `arr[1] = arr[0] XOR encoded[0] = 1 XOR 1 = 0`, `arr[2] = arr[1] XOR encoded[1] = 0 XOR 2 = 2`, and `arr[3] = arr[2] XOR encoded[2] = 2 XOR 3 = 1`.

- **Input:** `Input: encoded = [6, 2, 7, 3], first = 4`  \
  **Explanation:** The original array is `[4, 2, 0, 7, 4]`. Reconstructing each element: `arr[0] = 4`, `arr[1] = arr[0] XOR encoded[0] = 4 XOR 6 = 2`, `arr[2] = arr[1] XOR encoded[1] = 2 XOR 2 = 0`, `arr[3] = arr[2] XOR encoded[2] = 0 XOR 7 = 7`, and `arr[4] = arr[3] XOR encoded[3] = 7 XOR 3 = 4`.

{{< dots >}}
## Approach 🚀
We can decode the original array by iterating through the `encoded` array and using XOR operations to reconstruct the original elements, starting with the first element.

### Initial Thoughts 💭
- The problem is based on the XOR operation, which has properties that allow us to reverse the encoding process.
- The XOR operation is its own inverse, meaning that we can recover the original array using the formula `arr[i + 1] = arr[i] XOR encoded[i]`.
{{< dots >}}
### Edge Cases 🌐
- There are no cases with empty inputs, as the length of the `encoded` array is always at least 1.
- The algorithm should efficiently handle cases where `n` is large (up to 10^4).
- If `first` is 0, the first element of the array will be 0, and the rest of the array will be decoded accordingly.
- The solution should work within the provided time and space limits for all valid inputs.
{{< dots >}}
## Code 💻
```cpp
vector<int> decode(vector<int>& encoded, int first) {
    vector<int> res;
    res.push_back(first);
    for(int i = 0; i < encoded.size(); i++)
        res.push_back(res[i] ^ encoded[i]);
    return res;
}
```

This function `decode` reconstructs the original array by applying the XOR operation on the encoded array with the previously decoded elements. It starts with the given `first` element and progressively reconstructs the rest of the array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> decode(vector<int>& encoded, int first) {
	```
	The function `decode` is declared, taking an encoded array `encoded` and an integer `first`, which is the first element of the original array.

2. **Variable Initialization**
	```cpp
	    vector<int> res;
	```
	Declaring an empty vector `res` which will store the reconstructed array.

3. **Push First Element**
	```cpp
	    res.push_back(first);
	```
	Adding the first element `first` to the `res` vector, which is the starting point of the decoded array.

4. **Loop Iteration**
	```cpp
	    for(int i = 0; i < encoded.size(); i++)
	```
	Iterating through the `encoded` array to apply the XOR operation and reconstruct the original array.

5. **XOR Operation**
	```cpp
	        res.push_back(res[i] ^ encoded[i]);
	```
	Using the XOR operation to decode the next element of the original array by XORing the current value in `res` with the corresponding element in `encoded`, then pushing it into the `res` vector.

6. **Return Statement**
	```cpp
	    return res;
	```
	Returning the reconstructed array `res` containing the decoded values.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the `encoded` array.
- **Average Case:** O(n), as we are iterating through the `encoded` array once.
- **Worst Case:** O(n), since we need to process each element of the `encoded` array.

The time complexity is linear in the size of the `encoded` array.

### Space Complexity 💾
- **Best Case:** O(n), since we must store the result array regardless of input size.
- **Worst Case:** O(n), as we are storing the original array `arr` of size `n`.

The space complexity is linear in the size of the `encoded` array, as we need to store the decoded result.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/decode-xored-array/description/)

---
{{< youtube sthGfBi890o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
