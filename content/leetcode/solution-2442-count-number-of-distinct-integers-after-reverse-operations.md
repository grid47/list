
+++
authors = ["grid47"]
title = "Leetcode 2442: Count Number of Distinct Integers After Reverse Operations"
date = "2024-03-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2442: Count Number of Distinct Integers After Reverse Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "YQ_8I9TmsyA"
youtube_upload_date="2022-10-16"
youtube_thumbnail="https://i.ytimg.com/vi_webp/YQ_8I9TmsyA/maxresdefault.webp"
comments = true
+++



---
You are given an array `nums` consisting of positive integers. For each number in the array, you need to reverse its digits and append the reversed number to the end of the array. After performing this operation for all numbers, return the number of distinct integers in the resulting array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `nums` of positive integers.
- **Example:** `nums = [21, 32, 12, 43]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of distinct integers in the final array after reversing and appending each number.
- **Example:** `Output: 6`
- **Constraints:**
	- The result should be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to count the distinct integers in the final array formed by reversing and appending each integer from the original array.

- 1. Reverse the digits of each integer in the array and append the reversed number to the array.
- 2. Use a set to store the integers from the original and reversed numbers to ensure uniqueness.
- 3. Return the size of the set, which gives the number of distinct integers.
{{< dots >}}
### Problem Assumptions ✅
- Each element in the array is a positive integer.
- There will be no empty arrays.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [21, 32, 12, 43]`  \
  **Explanation:** For this array, the reversed numbers would be [12, 23, 21, 34]. The resulting array would be [21, 32, 12, 43, 12, 23, 21, 34]. The distinct integers are {21, 32, 12, 43, 23, 34}, so the result is 6.

- **Input:** `nums = [5, 15, 25, 55]`  \
  **Explanation:** After reversing the numbers, the array becomes [5, 15, 25, 55, 5, 51, 52, 55]. The distinct integers are {5, 15, 25, 55, 51, 52}, so the result is 6.

{{< dots >}}
## Approach 🚀
The approach involves reversing each integer and storing the original and reversed integers in a set to count only distinct values.

### Initial Thoughts 💭
- Reversing each number can be done efficiently by converting the number to a string, reversing the string, and converting it back to an integer.
- A set will help us store only unique numbers, ensuring no duplicates.
- We should reverse each integer, insert both the original and reversed numbers into a set, and return the size of the set.
{{< dots >}}
### Edge Cases 🌐
- The input array is guaranteed to have at least one integer.
- The solution should handle arrays with up to 10^5 integers efficiently.
- When the array contains numbers that become identical after reversal (e.g., 10 becomes 1), it should correctly count distinct values.
- The algorithm must work within the constraints and should use optimized data structures for performance.
{{< dots >}}
## Code 💻
```cpp
int rev(int num) {
    int res = 0;
    while(num > 0) {
        res = res * 10 + num % 10;
        num /= 10;
    }
    return res;
}

int countDistinctIntegers(vector<int>& nums) {
    set<int> cnt;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        cnt.insert(nums[i]);
        cnt.insert(rev(nums[i]));
    }
    
    return cnt.size();        
}
```

This code defines two functions: `rev` to reverse an integer and `countDistinctIntegers` to count the distinct integers in an array after considering both the integers and their reversed counterparts.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int rev(int num) {
	```
	Defining the `rev` function, which takes an integer `num` and returns its reversed value.

2. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	Initializing `res` to store the reversed number, starting with a value of 0.

3. **Loop**
	```cpp
	    while(num > 0) {
	```
	A loop that continues as long as `num` is greater than 0, reversing the digits of `num`.

4. **Mathematical Operation**
	```cpp
	        res = res * 10 + num % 10;
	```
	Extracting the last digit of `num` and adding it to `res` after shifting `res` one place to the left.

5. **Integer Update**
	```cpp
	        num /= 10;
	```
	Removing the last digit from `num` by dividing it by 10.

6. **Return Statement**
	```cpp
	    return res;
	```
	Returning the reversed integer `res`.

7. **Function Definition**
	```cpp
	int countDistinctIntegers(vector<int>& nums) {
	```
	Defining the `countDistinctIntegers` function, which takes a vector `nums` and returns the count of distinct integers after considering both the original integers and their reversed counterparts.

8. **Set Initialization**
	```cpp
	    set<int> cnt;
	```
	Creating a set `cnt` to store distinct integers, ensuring that duplicates are automatically removed.

9. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	Storing the size of the `nums` vector in variable `n`.

10. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Starting a loop that iterates through each element `i` in the `nums` vector.

11. **Insert Element**
	```cpp
	        cnt.insert(nums[i]);
	```
	Inserting the current element `nums[i]` into the set `cnt`.

12. **Insert Reversed Element**
	```cpp
	        cnt.insert(rev(nums[i]));
	```
	Inserting the reversed version of the current element `nums[i]` into the set `cnt`.

13. **Return Statement**
	```cpp
	    return cnt.size();
	```
	Returning the size of the set `cnt`, which represents the number of distinct integers considering both original and reversed elements.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of elements in the array. Each operation (reversing a number and inserting it into the set) takes constant time.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space used by the set to store distinct integers.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/description/)

---
{{< youtube YQ_8I9TmsyA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
