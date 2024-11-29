
+++
authors = ["grid47"]
title = "Leetcode 1498: Number of Subsequences That Satisfy the Given Sum Condition"
date = "2024-06-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1498: Number of Subsequences That Satisfy the Given Sum Condition in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "WZhNEfbGYEo"
youtube_upload_date="2023-05-06"
youtube_thumbnail="https://i.ytimg.com/vi/WZhNEfbGYEo/maxresdefault.jpg"
comments = true
+++



---
You are given an array of integers nums and an integer target. Your task is to count how many non-empty subsequences of nums exist such that the sum of the minimum and maximum element in each subsequence is less than or equal to target. Return the result modulo 10^9 + 7.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array nums and an integer target.
- **Example:** `nums = [2, 5, 7, 8], target = 10`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^6
	- 1 <= target <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of valid subsequences modulo 10^9 + 7.
- **Example:** `Output: 3`
- **Constraints:**
	- The result should be returned modulo 10^9 + 7.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to count subsequences where the sum of the minimum and maximum elements in the subsequence is less than or equal to the given target.

- Sort the array to efficiently find pairs of subsequences where the sum of the minimum and maximum values is <= target.
- Use a sliding window technique to count valid subsequences.
- For each element, calculate the number of subsequences that can be formed with that element as the minimum, using binary search to find the maximum valid subsequence.
{{< dots >}}
### Problem Assumptions ✅
- The input array always has at least one element.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [2, 5, 7, 8], target = 10`  \
  **Explanation:** The valid subsequences are: [2], [2, 5], [2, 5, 7], and [2, 7]. All of their minimum and maximum sums are less than or equal to 10.

- **Input:** `nums = [1, 3, 5, 7], target = 8`  \
  **Explanation:** The valid subsequences are: [1], [3], [1, 3], and [1, 5], which satisfy the condition.

{{< dots >}}
## Approach 🚀
We can solve this problem using a sorted array and a sliding window technique to count valid subsequences. The number of subsequences can be computed using the binary search technique to find the range of valid subsequences.

### Initial Thoughts 💭
- Sorting the array helps find subsequences with valid sums of minimum and maximum elements.
- The key observation is that once the array is sorted, finding the valid subsequences becomes a matter of using two pointers or binary search.
{{< dots >}}
### Edge Cases 🌐
- The input array will never be empty, as it is guaranteed to have at least one element.
- The solution should efficiently handle arrays of size up to 10^5.
- If all elements in nums are the same, the valid subsequences are just the combinations of that element.
- The solution must work within the given time limits for large inputs.
{{< dots >}}
## Code 💻
```cpp
int mod = (int) 1e9 + 7;
int pow2(int idx) {
    if(idx == 0) return 1;
    long res;
    if(idx % 2) {
        res = pow2(idx / 2);
        res = (res * res * 2) % mod;
    }else {
        res = pow2(idx / 2);
        res = (res * res) % mod;            
    }
    return res;
}

int numSubseq(vector<int>& nums, int target) {
    
    sort(nums.begin(), nums.end());
    
    long res = 0, n = nums.size();
    
    for(int i = 0; i < n; i++) {
        
        if(nums[i] * 2 > target) break;
        
        int end = target - nums[i];
        auto it = upper_bound(nums.begin(), nums.end(), end);
        
        int idx = it - nums.begin();

        res = (res + pow2(idx - i - 1)) % mod;
        
    }
    return res;
}
```

This function calculates the number of subsequences of a given array `nums` whose sum of the smallest and largest element is less than or equal to `target`. It utilizes the `pow2` function for efficiently calculating powers of 2 modulo a large prime value to avoid overflow.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Modulo Initialization**
	```cpp
	int mod = (int) 1e9 + 7;
	```
	Set the value of `mod` to (10^9 + 7), a large prime used for modulo operations to prevent integer overflow in the result calculations.

2. **Power Function Declaration**
	```cpp
	int pow2(int idx) {
	```
	Define the `pow2` function which calculates (2^{idx} % 	ext{mod}). It uses recursion and the properties of exponents for efficient computation.

3. **Base Case**
	```cpp
	    if(idx == 0) return 1;
	```
	If the exponent is 0, return 1, as any number raised to the power of 0 is 1.

4. **Variable Declaration**
	```cpp
	    long res;
	```
	Declare a variable `res` to store the result of the power calculation.

5. **Odd Exponent Check**
	```cpp
	    if(idx % 2) {
	```
	If the exponent is odd, proceed to calculate (2^{idx} % 	ext{mod}) by splitting it into smaller subproblems.

6. **Recursive Call for Odd Exponent**
	```cpp
	        res = pow2(idx / 2);
	```
	Recursively calculate (2^{rac{idx}{2}} % 	ext{mod}).

7. **Odd Exponent Final Calculation**
	```cpp
	        res = (res * res * 2) % mod;
	```
	For an odd exponent, square the result of the recursive call and multiply by 2 to get (2^{idx} % 	ext{mod}).

8. **Even Exponent Calculation**
	```cpp
	    }else {
	```
	If the exponent is even, calculate the power using the even exponent property.

9. **Recursive Call for Even Exponent**
	```cpp
	        res = pow2(idx / 2);
	```
	Recursively calculate (2^{rac{idx}{2}} % 	ext{mod}).

10. **Even Exponent Final Calculation**
	```cpp
	        res = (res * res) % mod;            
	```
	For an even exponent, square the result of the recursive call to get (2^{idx} % 	ext{mod}).

11. **Return Final Result**
	```cpp
	    return res;
	```
	Return the calculated result of (2^{idx} % 	ext{mod}).

12. **Main Function Declaration**
	```cpp
	int numSubseq(vector<int>& nums, int target) {
	```
	Declare the `numSubseq` function, which calculates the number of subsequences in the array `nums` whose sum of the smallest and largest element is less than or equal to `target`.

13. **Sorting**
	```cpp
	    sort(nums.begin(), nums.end());
	```
	Sort the array `nums` in non-decreasing order to facilitate the calculation of valid subsequences.

14. **Variable Initialization**
	```cpp
	    long res = 0, n = nums.size();
	```
	Initialize a result variable `res` to 0 and a variable `n` to store the size of the array `nums`.

15. **Loop Over Array**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Loop through the elements of the sorted array `nums`.

16. **Target Check**
	```cpp
	        if(nums[i] * 2 > target) break;
	```
	If the current element is greater than half of `target`, no valid subsequences can be formed, so exit the loop.

17. **Calculate Upper Bound**
	```cpp
	        int end = target - nums[i];
	```
	Calculate the maximum possible value for the largest element of the subsequence, `end`, by subtracting `nums[i]` from `target`.

18. **Binary Search**
	```cpp
	        auto it = upper_bound(nums.begin(), nums.end(), end);
	```
	Use binary search to find the first element in `nums` that is greater than `end`.

19. **Calculate Index**
	```cpp
	        int idx = it - nums.begin();
	```
	Calculate the index of the element found by `upper_bound` to determine how many valid subsequences can be formed.

20. **Add to Result**
	```cpp
	        res = (res + pow2(idx - i - 1)) % mod;
	```
	Add the number of valid subsequences formed between `i` and `idx - 1` to the result, using the `pow2` function to calculate powers of 2.

21. **Return Final Result**
	```cpp
	    return res;
	```
	Return the final result, the total number of valid subsequences.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is O(n log n) because the array is sorted and binary search is performed for each element.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space used for sorting the array and storing intermediate results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/)

---
{{< youtube WZhNEfbGYEo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
