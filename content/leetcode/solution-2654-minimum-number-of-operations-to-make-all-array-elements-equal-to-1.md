
+++
authors = ["grid47"]
title = "Leetcode 2654: Minimum Number of Operations to Make All Array Elements Equal to 1"
date = "2024-02-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2654: Minimum Number of Operations to Make All Array Elements Equal to 1 in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "9LOYxdctbs0"
youtube_upload_date="2023-04-23"
youtube_thumbnail="https://i.ytimg.com/vi/9LOYxdctbs0/maxresdefault.jpg"
comments = true
+++



---
You are given an array of positive integers 'nums'. You can perform an operation on this array where you select two consecutive elements and replace one of them with the gcd (greatest common divisor) of the two elements. The goal is to make all elements of the array equal to 1 using the minimum number of operations. If it's impossible to make all elements equal to 1, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of positive integers, nums, with a length between 2 and 50. The integers in nums can be as large as 10^6.
- **Example:** `Input: nums = [3, 9, 6, 12]`
- **Constraints:**
	- 2 <= nums.length <= 50
	- 1 <= nums[i] <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of operations required to make all elements in the array equal to 1, or return -1 if it is impossible.
- **Example:** `Output: 3`
- **Constraints:**
	- The output should be an integer representing the minimum number of operations or -1 if it's impossible.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the minimum number of operations to convert all elements of the array to 1 by using gcd operations on consecutive elements.

- Step 1: Check if the array already contains 1. If so, return the number of operations required to change all elements to 1.
- Step 2: For each subarray of consecutive elements, calculate their gcd and check if it's 1.
- Step 3: Track the minimum number of steps needed to achieve an array of all ones by applying gcd operations iteratively on the elements.
{{< dots >}}
### Problem Assumptions ✅
- The array nums will always have at least two elements.
- If it's possible to convert the entire array to 1, it can be done using a series of gcd operations on consecutive elements.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [3, 9, 6, 12]`  \
  **Explanation:** In this case, we can perform the following operations: 3 and 9 have gcd 3, then 9 and 6 have gcd 3, and finally 6 and 12 have gcd 6. Using gcd on consecutive elements, we eventually convert all elements to 1 after 3 operations.

- **Input:** `Input: nums = [5, 15, 25]`  \
  **Explanation:** For this case, we cannot reduce these elements to 1 since their gcd is greater than 1. Therefore, it is impossible to make all elements equal to 1, and the output is -1.

{{< dots >}}
## Approach 🚀
We approach this problem by using a sliding window technique, calculating the gcd of consecutive elements and updating the array progressively. The goal is to minimize the number of operations required to make all elements 1.

### Initial Thoughts 💭
- If the array already contains a 1, the solution is straightforward and involves replacing all other elements with 1.
- If the gcd of the entire array is greater than 1, it is impossible to convert all elements to 1.
- A brute force approach of checking every pair of consecutive elements might be inefficient, so we will focus on the gcd values to minimize operations.
{{< dots >}}
### Edge Cases 🌐
- The input is guaranteed to have at least two elements, so there will be no empty arrays.
- The array can have up to 50 elements, and the values of nums[i] can go up to 10^6, so we need an efficient solution.
- If the array contains multiple 1's, the answer should be 0 operations.
- If all elements share a common factor greater than 1, the answer should be -1.
- Ensure the solution works within time limits for the maximum array size of 50.
{{< dots >}}
## Code 💻
```cpp

int minOperations(vector<int>& nums) {


    int cnt = 0;
    
    for(int x: nums) if (x == 1) cnt++;
    if(cnt > 0) return nums.size() - cnt;
    
    int t = INT_MAX;
    for(int i = 0; i < nums.size(); i++) {
        int last = nums[i];
        for(int j = i + 1; j < nums.size(); j++) {
            last = __gcd(last, nums[j]);
            if(last == 1) {
                t = min(t, j - i);
            }
        }
    }
    
    
    return t == INT_MAX? -1: t + nums.size() - 1;
}
```

This function calculates the minimum number of operations required to make all elements in the input array 'nums' equal to 1 by utilizing the greatest common divisor (GCD).

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minOperations(vector<int>& nums) {
	```
	The function `minOperations` takes a reference to a vector of integers `nums` and returns an integer representing the minimum number of operations.

2. **Variable Initialization**
	```cpp
	    int cnt = 0;
	```
	A counter `cnt` is initialized to zero. This will keep track of how many times the value 1 appears in the input array.

3. **Loop: Counting Ones**
	```cpp
	    for(int x: nums) if (x == 1) cnt++;
	```
	A loop that iterates through the array and increments the `cnt` for every occurrence of the value 1.

4. **Conditional Check**
	```cpp
	    if(cnt > 0) return nums.size() - cnt;
	```
	If `cnt` is greater than 0, meaning there are ones in the array, the function returns the size of the array minus the number of ones, representing the number of operations.

5. **Variable Declaration**
	```cpp
	    int t = INT_MAX;
	```
	A variable `t` is initialized to the maximum possible integer value, which will later store the minimum distance between indices where GCD of the subarray is 1.

6. **Nested Loop: GCD Calculation**
	```cpp
	    for(int i = 0; i < nums.size(); i++) {
	```
	A nested loop is used to find pairs of elements in the array where their GCD is 1.

7. **Inner Loop: GCD Calculation**
	```cpp
	        int last = nums[i];
	```
	The variable `last` is initialized to the current element of the array `nums[i]`. It will be used to calculate the GCD of subsequent elements.

8. **Inner Loop: GCD Calculation**
	```cpp
	        for(int j = i + 1; j < nums.size(); j++) {
	```
	This loop iterates through the array starting from index `i + 1` and calculates the GCD of the elements.

9. **GCD Calculation**
	```cpp
	            last = __gcd(last, nums[j]);
	```
	The GCD of the current value of `last` and the current element `nums[j]` is computed using the built-in `__gcd` function.

10. **GCD Check**
	```cpp
	            if(last == 1) {
	```
	If the GCD between `last` and `nums[j]` is 1, the distance between indices `i` and `j` is a valid candidate.

11. **Update Minimum Distance**
	```cpp
	                t = min(t, j - i);
	```
	The minimum distance `t` is updated to the smaller of its current value and the difference between indices `j` and `i`.

12. **Final Calculation**
	```cpp
	    return t == INT_MAX? -1: t + nums.size() - 1;
	```
	If no valid subarray was found, the function returns -1; otherwise, it returns the minimum number of operations calculated.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The best case is when the gcd is 1 for all elements, and the worst case is when we have to check all consecutive pairs in the array.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, as we only need a few variables to store temporary results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/description/)

---
{{< youtube 9LOYxdctbs0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
