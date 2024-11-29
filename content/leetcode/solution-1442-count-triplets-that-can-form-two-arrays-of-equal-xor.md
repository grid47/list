
+++
authors = ["grid47"]
title = "Leetcode 1442: Count Triplets That Can Form Two Arrays of Equal XOR"
date = "2024-06-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1442: Count Triplets That Can Form Two Arrays of Equal XOR in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Bit Manipulation","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "e4Yx9KjqzQ8"
youtube_upload_date="2024-05-30"
youtube_thumbnail="https://i.ytimg.com/vi/e4Yx9KjqzQ8/maxresdefault.jpg"
comments = true
+++



---
You are given an array of integers `arr`. We want to find the number of triplets `(i, j, k)` where `0 <= i < j <= k < arr.length`, such that the bitwise XOR of elements between indices `i` and `j-1` (inclusive) equals the bitwise XOR of elements between indices `j` and `k` (inclusive).
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An array of integers `arr`.
- **Example:** `Input: arr = [4,5,6,7,8]`
- **Constraints:**
	- 1 <= arr.length <= 300
	- 1 <= arr[i] <= 10^8

{{< dots >}}
### Output Specifications 📤
- **Output:** The number of triplets `(i, j, k)` that satisfy the given condition.
- **Example:** `Output: 2`
- **Constraints:**
	- Output must be an integer representing the count of such triplets.

{{< dots >}}
### Core Logic 🔍
**Goal:** Identify and count all triplets `(i, j, k)` where the XOR of elements in the defined subarrays is equal.

- Compute the prefix XOR for the array.
- Use nested loops to iterate through possible values of `i` and `j`.
- Check if the prefix XOR for the subarrays defined by `(i, j, k)` are equal.
- If they are equal, count the number of valid `k` values for that `(i, j)`.
{{< dots >}}
### Problem Assumptions ✅
- The input array `arr` is non-empty.
- The integers in `arr` are positive.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: arr = [4,1,2,3,4]`  \
  **Explanation:** The triplets are (0,1,2) and (2,3,4), where the XOR conditions are satisfied.

{{< dots >}}
## Approach 🚀
Utilize prefix XOR to simplify comparisons of subarray XOR values. Iterate through the array to count valid triplets.

### Initial Thoughts 💭
- XOR has useful properties: `x ^ x = 0` and `x ^ 0 = x`.
- Prefix XOR allows us to compute XOR of subarrays efficiently.
- If prefix[i] == prefix[j], then XOR from i to j-1 is 0.
{{< dots >}}
### Edge Cases 🌐
- Input: arr = [] -> Output: 0
- Input: arr of length 300 with random values -> Should run within time constraints.
- Input: arr = [1,1,1,1,1] -> Output: 10, as all triplets are valid.
- Prefix XOR should handle large numbers up to 10^8.
{{< dots >}}
## Code 💻
```cpp
int countTriplets(vector<int>& nums) {

    int res = 0, n = nums.size();
    vector<int> arr(n+1,0);
    for(int i = 1; i < n + 1; i++)
        arr[i] = arr[i -1] ^ nums[i-1];
    for(int i = 0; i < n+1; i++) {
        for(int j = i + 1; j < n+1; j++)
            if(arr[i] == arr[j])
            res += j - i- 1;
        }
    return res;
}
```

The `countTriplets` function calculates the number of triplets in an array `nums` where the XOR of the first element to the second equals the XOR of the second to the third. It uses a prefix XOR array (`arr`) to efficiently compute the number of triplets by comparing XOR values.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int countTriplets(vector<int>& nums) {
	```
	Defines the function `countTriplets`, which takes a reference to a vector `nums` containing integers and returns the count of triplets that satisfy the XOR condition.

2. **Variable Initialization**
	```cpp
	    int res = 0, n = nums.size();
	```
	Initializes the result variable `res` to 0 (which will hold the number of valid triplets) and calculates the size of the `nums` array (`n`).

3. **Prefix Array Initialization**
	```cpp
	    vector<int> arr(n+1,0);
	```
	Creates a vector `arr` of size `n+1` to store prefix XOR values. It is initialized to 0, and `arr[i]` will store the XOR of elements from the start to index `i-1`.

4. **Prefix XOR Calculation**
	```cpp
	    for(int i = 1; i < n + 1; i++)
	```
	Starts a loop to calculate the prefix XOR of the `nums` array and store the results in the `arr` vector.

5. **XOR Calculation**
	```cpp
	        arr[i] = arr[i -1] ^ nums[i-1];
	```
	For each index `i`, updates `arr[i]` to the XOR of `arr[i-1]` (previous prefix XOR value) and the current element `nums[i-1]`.

6. **Outer Loop**
	```cpp
	    for(int i = 0; i < n+1; i++) {
	```
	Starts an outer loop from index `i=0` to `i=n` to compare the prefix XOR values and find the triplet matches.

7. **Inner Loop**
	```cpp
	        for(int j = i + 1; j < n+1; j++)
	```
	Starts an inner loop from index `j=i+1` to `j=n` to compare the XOR values between the indices `i` and `j`.

8. **XOR Comparison**
	```cpp
	            if(arr[i] == arr[j])
	```
	Checks if the XOR of the elements from index `i` to `j-1` equals the XOR of the elements from index `j` to the end, indicating a valid triplet.

9. **Result Update**
	```cpp
	            res += j - i- 1;
	```
	If the XOR values at indices `i` and `j` match, it adds `j - i - 1` to the result `res`, counting the number of valid triplets between `i` and `j`.

10. **Return Statement**
	```cpp
	    return res;
	```
	Returns the final count of valid triplets stored in the `res` variable.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

Nested loops iterate through pairs of indices, leading to quadratic complexity.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The prefix XOR array requires linear space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/)

---
{{< youtube e4Yx9KjqzQ8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
