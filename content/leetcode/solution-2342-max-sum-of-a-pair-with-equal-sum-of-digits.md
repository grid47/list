
+++
authors = ["grid47"]
title = "Leetcode 2342: Max Sum of a Pair With Equal Sum of Digits"
date = "2024-03-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2342: Max Sum of a Pair With Equal Sum of Digits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "uOPtnfVSFuQ"
youtube_upload_date="2022-07-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/uOPtnfVSFuQ/maxresdefault.webp"
comments = true
+++



---
You are given an array `nums` of positive integers. You need to find two indices `i` and `j` such that `i != j`, and the sum of digits of the numbers `nums[i]` and `nums[j]` is the same. Return the maximum sum of `nums[i] + nums[j]` that you can obtain over all valid pairs of indices. If no such pair exists, return `-1`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `nums` of length `n` where `n` is between 1 and 10^5.
- **Example:** `nums = [28, 17, 45, 64, 23]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum sum of `nums[i] + nums[j]` for two indices `i` and `j` where the sum of the digits of `nums[i]` equals the sum of the digits of `nums[j]`. If no such pair exists, return `-1`.
- **Example:** `93`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find pairs of integers whose sum of digits are the same, and return the maximum sum of such pairs.

- For each number in the array, calculate the sum of its digits.
- Store the largest number encountered for each sum of digits.
- For each new number, if its sum of digits has been seen before, calculate the sum of the current number and the previously encountered number with the same sum of digits, and update the maximum sum if necessary.
{{< dots >}}
### Problem Assumptions ✅
- The input array is valid and contains positive integers.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [28, 17, 45, 64, 23]`  \
  **Explanation:** The sum of digits of 28 is 10, the sum of digits of 64 is 10 as well, so the pair (28, 64) gives the maximum sum of 93.

{{< dots >}}
## Approach 🚀
We calculate the sum of digits of each number in the array and then find the maximum sum for numbers that share the same sum of digits.

### Initial Thoughts 💭
- We can calculate the sum of digits of a number by repeatedly dividing by 10 and summing the remainders.
- The key observation is that we only need to track the largest numbers for each sum of digits.
{{< dots >}}
### Edge Cases 🌐
- The input array will not be empty according to the constraints.
- The solution should efficiently handle arrays of length up to 10^5.
- If no two numbers have the same sum of digits, the output should be -1.
- The numbers are positive and at most 10^9, so care must be taken to handle large numbers.
{{< dots >}}
## Code 💻
```cpp
int maximumSum(vector<int>& nums) {
    
    map<int, int> mp;
    
    int ans = -1;
    
    for(int x: nums) {
        int sum = 0;
        int tmp = x;
        while(tmp > 0) {
            sum += (tmp % 10);
            tmp /= 10;
        }
        if(mp.count(sum)) {
            ans = max(ans, x + mp[sum]);
            mp[sum] = max(x, mp[sum]);
        } else {
            mp[sum] = x;
        }
    }
    
    return ans;
}
```

This code defines a function `maximumSum` that takes a vector of integers and calculates the maximum sum of a pair of integers in the vector such that the sum of their digits is the same.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Initialization**
	```cpp
	int maximumSum(vector<int>& nums) {
	```
	The function `maximumSum` is initialized with a vector of integers `nums`.

2. **Variable Declaration**
	```cpp
	    map<int, int> mp;
	```
	A map `mp` is declared to store the sum of digits as the key and the corresponding number as the value.

3. **Variable Declaration**
	```cpp
	    int ans = -1;
	```
	The variable `ans` is initialized to -1 to keep track of the maximum sum.

4. **Loop Start**
	```cpp
	    for(int x: nums) {
	```
	A loop is initiated to iterate over each element `x` in the vector `nums`.

5. **Variable Initialization**
	```cpp
	        int sum = 0;
	```
	A variable `sum` is initialized to 0 to store the sum of digits of the current element `x`.

6. **Variable Initialization**
	```cpp
	        int tmp = x;
	```
	The variable `tmp` is initialized with the value of `x` to compute the sum of its digits.

7. **Loop Start**
	```cpp
	        while(tmp > 0) {
	```
	A while loop is started to iterate through each digit of `tmp`.

8. **Digit Extraction**
	```cpp
	            sum += (tmp % 10);
	```
	The last digit of `tmp` is extracted and added to `sum`.

9. **Digit Extraction**
	```cpp
	            tmp /= 10;
	```
	The last digit is removed from `tmp` by integer division by 10.

10. **Condition Check**
	```cpp
	        if(mp.count(sum)) {
	```
	A condition checks if the sum of digits `sum` is already present in the map `mp`.

11. **Max Calculation**
	```cpp
	            ans = max(ans, x + mp[sum]);
	```
	If the sum is found in the map, the maximum sum is updated using the current element `x` and the value stored in `mp[sum]`.

12. **Map Update**
	```cpp
	            mp[sum] = max(x, mp[sum]);
	```
	The value in the map `mp` for the current `sum` is updated to be the larger of the current element `x` and the previous value.

13. **Condition Else**
	```cpp
	        } else {
	```
	If the sum of digits is not found in the map, a new entry is added.

14. **Map Insertion**
	```cpp
	            mp[sum] = x;
	```
	The value `x` is inserted into the map `mp` with `sum` as the key.

15. **Return Statement**
	```cpp
	    return ans;
	```
	The function returns the value of `ans`, which holds the maximum sum of pairs with the same digit sum.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the input array `nums`, as we iterate over the array once and perform a constant-time operation to calculate the sum of digits for each number.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we use a hashmap to store the largest number for each sum of digits.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/)

---
{{< youtube uOPtnfVSFuQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
