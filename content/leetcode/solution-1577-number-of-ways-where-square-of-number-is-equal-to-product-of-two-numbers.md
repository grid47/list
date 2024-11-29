
+++
authors = ["grid47"]
title = "Leetcode 1577: Number of Ways Where Square of Number Is Equal to Product of Two Numbers"
date = "2024-06-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1577: Number of Ways Where Square of Number Is Equal to Product of Two Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Two Pointers"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ZNAJbQTv3yk"
youtube_upload_date="2020-09-06"
youtube_thumbnail="https://i.ytimg.com/vi/ZNAJbQTv3yk/maxresdefault.jpg"
comments = true
+++



---
Given two integer arrays, nums1 and nums2, return the total number of valid triplets that can be formed under two conditions: 

Type 1: A triplet (i, j, k) is valid if nums1[i]^2 == nums2[j] * nums2[k] where 0 <= i < nums1.length and 0 <= j < k < nums2.length. 
Type 2: A triplet (i, j, k) is valid if nums2[i]^2 == nums1[j] * nums1[k] where 0 <= i < nums2.length and 0 <= j < k < nums1.length.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two arrays of integers, nums1 and nums2.
- **Example:** `Input: nums1 = [3, 6], nums2 = [4, 9, 1, 2]`
- **Constraints:**
	- 1 <= nums1.length, nums2.length <= 1000
	- 1 <= nums1[i], nums2[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the total number of valid triplets formed based on the given conditions. The result should be returned as an integer.
- **Example:** `Output: 2`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to count the number of valid triplets by iterating through both arrays and checking the two conditions for each triplet.

- 1. Iterate through nums1 and for each element, compute the square of the element and check if it matches any valid product of two elements from nums2.
- 2. Repeat the above step for nums2 to check the second condition for type 2 triplets.
- 3. Use a map to store previously seen values to optimize checking the valid triplets.
{{< dots >}}
### Problem Assumptions ✅
- The arrays are guaranteed to have integers within the specified range.
- The solution should efficiently handle arrays with lengths up to 1000.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: nums1 = [3, 6], nums2 = [4, 9, 1, 2]`  \
  **Explanation:** The valid triplets are: 

Type 1: (1, 0, 2), nums1[1]^2 = nums2[0] * nums2[2]. 
Type 2: (0, 0, 1), nums2[0]^2 = nums1[0] * nums1[1].

- **Input:** `Example 2: nums1 = [5, 5], nums2 = [5, 5, 5]`  \
  **Explanation:** All triplets are valid because the square of each element in nums1 and nums2 equals the product of two other elements in the opposite array.

- **Input:** `Example 3: nums1 = [1, 2], nums2 = [2, 4, 3]`  \
  **Explanation:** There are 0 valid triplets since none of the conditions hold for any triplet.

{{< dots >}}
## Approach 🚀
The approach focuses on iterating through both arrays while checking the two conditions to count valid triplets. By leveraging a map to store counts of numbers, we optimize the process of checking whether a product exists.

### Initial Thoughts 💭
- Each triplet must satisfy one of the two conditions involving the square of an element from one array and the product of two elements from the other array.
- Efficiency can be improved by using a map to store previously seen elements, thus avoiding redundant calculations.
- The map helps keep track of elements efficiently, reducing the time complexity for each triplet check.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that the arrays have at least one element, so no empty arrays will be encountered.
- For arrays with lengths approaching 1000, the algorithm should efficiently handle the larger input sizes.
- Arrays with identical elements (e.g., nums1 = [5, 5], nums2 = [5, 5, 5]) should be handled correctly.
- The algorithm should be efficient enough to handle large inputs while ensuring correctness.
{{< dots >}}
## Code 💻
```cpp
int numTriplets(vector<int>& nums1, vector<int>& nums2) {
    long res = 0;

    for(int v: nums1)
        res += twoProd((long)v * v, nums2);
    for(int v: nums2)
        res += twoProd((long)v * v, nums1);

    return res;
}


long twoProd(long i, vector<int> &nums) {
    map<long, long> mp;
    
    int cnt = 0;
    for(int n : nums) {
        if(i % n == 0)
            cnt += mp[i / n];
        mp[n]++;
    }
    
    return cnt;
}
```

This solution calculates the number of valid triplets where the product of two numbers in one array divides the square of a number in the other array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int numTriplets(vector<int>& nums1, vector<int>& nums2) {
	```
	Define the function `numTriplets` that takes two integer vectors, `nums1` and `nums2`, as input.

2. **Variable Initialization**
	```cpp
	    long res = 0;
	```
	Initialize a variable `res` to store the count of valid triplets.

3. **Looping Through `nums1`**
	```cpp
	    for(int v: nums1)
	```
	Start iterating over each element `v` in the first array `nums1`.

4. **Function Call - twoProd**
	```cpp
	        res += twoProd((long)v * v, nums2);
	```
	For each element `v`, call the helper function `twoProd` with the square of `v` and `nums2` to calculate the count of valid triplets.

5. **Looping Through `nums2`**
	```cpp
	    for(int v: nums2)
	```
	Start iterating over each element `v` in the second array `nums2`.

6. **Function Call - twoProd**
	```cpp
	        res += twoProd((long)v * v, nums1);
	```
	For each element `v`, call the helper function `twoProd` with the square of `v` and `nums1` to calculate the count of valid triplets.

7. **Return Result**
	```cpp
	    return res;
	```
	Return the final result, which is the total count of valid triplets.

8. **Helper Function Definition**
	```cpp
	long twoProd(long i, vector<int> &nums) {
	```
	Define the helper function `twoProd`, which calculates the number of pairs of numbers from the array `nums` whose product divides `i`.

9. **Map Initialization**
	```cpp
	    map<long, long> mp;
	```
	Initialize a map `mp` to store the frequency of numbers encountered while iterating through `nums`.

10. **Variable Initialization**
	```cpp
	    int cnt = 0;
	```
	Initialize a variable `cnt` to count the number of valid pairs.

11. **Looping Through `nums`**
	```cpp
	    for(int n : nums) {
	```
	Iterate through each number `n` in the array `nums`.

12. **Checking Divisibility**
	```cpp
	        if(i % n == 0)
	```
	Check if `i` is divisible by `n`.

13. **Counting Valid Pairs**
	```cpp
	            cnt += mp[i / n];
	```
	If `i` is divisible by `n`, add to the count `cnt` the number of times `i / n` has been encountered in the map `mp`.

14. **Updating Map**
	```cpp
	        mp[n]++;
	```
	Increment the count of `n` in the map `mp`.

15. **Return Count**
	```cpp
	    return cnt;
	```
	Return the total count of valid pairs.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The best case occurs when no valid triplets are found, but in the worst case, the solution needs to check every combination of elements, leading to O(n^2) time complexity.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

In the worst case, the space complexity is O(n) due to the map storing intermediate counts. In the best case, space complexity can be constant if the map doesn't store many elements.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/description/)

---
{{< youtube ZNAJbQTv3yk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
