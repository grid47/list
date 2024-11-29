
+++
authors = ["grid47"]
title = "Leetcode 2425: Bitwise XOR of All Pairings"
date = "2024-03-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2425: Bitwise XOR of All Pairings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation","Brainteaser"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "mFFtmUdq2jI"
youtube_upload_date="2022-10-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/mFFtmUdq2jI/maxresdefault.webp"
comments = true
+++



---
You are given two arrays, nums1 and nums2, each consisting of non-negative integers. You need to calculate the XOR of all possible pairings between the integers in nums1 and nums2. The result should be the XOR of all the numbers from this new array formed by XORing every integer in nums1 with every integer in nums2.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two arrays nums1 and nums2. Each integer in nums1 will be paired with every integer in nums2 exactly once.
- **Example:** `nums1 = [5, 2], nums2 = [3, 4, 6]`
- **Constraints:**
	- 1 <= nums1.length, nums2.length <= 10^5
	- 0 <= nums1[i], nums2[j] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the XOR of all the integers in the array formed by XORing each integer from nums1 with each integer from nums2.
- **Example:** `Output: 4`
- **Constraints:**
	- The output will be an integer, which is the result of XORing all elements from the resulting array.

{{< dots >}}
### Core Logic 🔍
**Goal:** To compute the XOR of all pairings of elements from nums1 and nums2 efficiently.

- 1. Iterate over all elements in nums1 and nums2.
- 2. For each pair, XOR the elements and accumulate the result.
- 3. After processing all pairs, return the XOR of all the results.
{{< dots >}}
### Problem Assumptions ✅
- The arrays nums1 and nums2 are non-empty and contain non-negative integers.
- The XOR operation will be applied to all pairings of elements from nums1 and nums2.
{{< dots >}}
## Examples 🧩
- **Input:** `nums1 = [5, 2], nums2 = [3, 4, 6]`  \
  **Explanation:** We first calculate the pairwise XOR results: 5^3, 5^4, 5^6, 2^3, 2^4, 2^6. These results are then XORed together to get the final result.

{{< dots >}}
## Approach 🚀
We need to calculate the XOR of all pairings efficiently. Instead of explicitly creating the array, we can optimize the calculation by leveraging properties of XOR.

### Initial Thoughts 💭
- The XOR operation has the property that it is both commutative and associative, meaning the order of operations does not matter.
- We can avoid explicitly building the nums3 array by directly calculating the XOR as we process the pairings of nums1 and nums2.
{{< dots >}}
### Edge Cases 🌐
- Since nums1 and nums2 are non-empty as per the problem constraints, no need to handle empty arrays.
- The solution should handle the case where nums1 and nums2 contain up to 10^5 elements.
- The solution must handle large values in nums1 and nums2, which can go up to 10^9.
- Make sure the solution is optimized for time complexity, especially when handling large inputs.
{{< dots >}}
## Code 💻
```cpp
int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    
    int xr1 = nums1[0], xr2 = nums2[0];
    
    for(int i = 1; i < m; i++)
        xr1 ^= nums1[i];
    
    for(int i = 1; i < n; i++)
        xr2 ^= nums2[i];

    if((n % 2) == 0) {
        if((m % 2) == 0) {
            return 0;
        } else {
            return xr2;
        }
    } else {
        if((m % 2) == 0) {
            return xr1;
        } else {
            return xr1 ^ xr2;
        }            
    }
    return -1;
}
```

This function calculates the XOR of numbers from two vectors `nums1` and `nums2` and handles different scenarios based on the parity of the vector sizes.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Code Initialization**
	```cpp
	int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
	```
	Defines the function that will calculate the XOR of two integer vectors.

2. **Variable Declaration**
	```cpp
	    int m = nums1.size(), n = nums2.size();
	```
	Declares and initializes variables `m` and `n` to store the sizes of `nums1` and `nums2`.

3. **XOR Initialization**
	```cpp
	    int xr1 = nums1[0], xr2 = nums2[0];
	```
	Initializes `xr1` and `xr2` to the first elements of `nums1` and `nums2`, respectively, to begin the XOR operation.

4. **XOR Operation 1**
	```cpp
	    for(int i = 1; i < m; i++)
	```
	Loop through the rest of `nums1` starting from index 1.

5. **XOR Operation 2**
	```cpp
	        xr1 ^= nums1[i];
	```
	XORs each element of `nums1` with `xr1` to accumulate the result.

6. **XOR Operation 3**
	```cpp
	    for(int i = 1; i < n; i++)
	```
	Loop through the rest of `nums2` starting from index 1.

7. **XOR Operation 4**
	```cpp
	        xr2 ^= nums2[i];
	```
	XORs each element of `nums2` with `xr2` to accumulate the result.

8. **Condition 1**
	```cpp
	    if((n % 2) == 0) {
	```
	Checks if the size of `nums2` is even.

9. **Condition 2**
	```cpp
	        if((m % 2) == 0) {
	```
	Checks if the size of `nums1` is even, when `nums2` is even.

10. **Return 0**
	```cpp
	            return 0;
	```
	If both `nums1` and `nums2` are of even size, return 0.

11. **Return 1**
	```cpp
	        } else {
	```
	If `nums1` is of odd size and `nums2` is of even size.

12. **Return 2**
	```cpp
	            return xr2;
	```
	Returns the XOR of `nums2` if `nums1` is of odd size and `nums2` is even.

13. **Else Condition 1**
	```cpp
	    } else {
	```
	Else part when `nums2` has odd size.

14. **Condition 4**
	```cpp
	        if((m % 2) == 0) {
	```
	Checks if the size of `nums1` is even, when `nums2` is odd.

15. **Return 3**
	```cpp
	            return xr1;
	```
	Returns `xr1` if `nums1` is even and `nums2` is odd.

16. **Condition 5**
	```cpp
	        } else {
	```
	If both `nums1` and `nums2` are of odd size.

17. **Return 4**
	```cpp
	            return xr1 ^ xr2;
	```
	Returns the XOR of both `xr1` and `xr2` if both vectors have odd sizes.

18. **Final Return**
	```cpp
	    return -1;
	```
	Return -1 as a fallback if none of the conditions match.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we only need to iterate through nums1 and nums2 once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we only need a few variables to store intermediate results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/bitwise-xor-of-all-pairings/description/)

---
{{< youtube mFFtmUdq2jI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
