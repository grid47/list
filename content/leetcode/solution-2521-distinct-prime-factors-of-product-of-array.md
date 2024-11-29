
+++
authors = ["grid47"]
title = "Leetcode 2521: Distinct Prime Factors of Product of Array"
date = "2024-02-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2521: Distinct Prime Factors of Product of Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "HKc9PcSzNic"
youtube_upload_date="2023-01-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/HKc9PcSzNic/maxresdefault.webp"
comments = true
+++



---
Given an array of positive integers `nums`, find the number of distinct prime factors in the product of all the elements in the array. A prime factor of a number is a number that divides it evenly, and only divisible by 1 and itself. The goal is to calculate the distinct prime factors present in the prime factorization of the product of all elements in `nums`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array `nums` containing positive integers. You need to calculate the number of distinct prime factors of the product of all elements in `nums`.
- **Example:** `nums = [3, 9, 12, 15]`
- **Constraints:**
	- 1 <= nums.length <= 10^4
	- 2 <= nums[i] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of distinct prime factors of the product of all elements in `nums`.
- **Example:** `Output: 3`
- **Constraints:**
	- The output should be an integer representing the number of distinct prime factors.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find how many distinct prime factors are present in the prime factorization of the product of all elements in the `nums` array.

- Initialize a set to store prime factors.
- Iterate through each number in the `nums` array.
- For each number, find its prime factors and add them to the set.
- After processing all numbers, the size of the set will give the number of distinct prime factors.
{{< dots >}}
### Problem Assumptions ✅
- All elements in `nums` are positive integers and greater than 1.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [3, 9, 12, 15]`  \
  **Explanation:** The product of these numbers is `4860`. The prime factorization of `4860` is `2^2 * 3^5 * 5`. Hence, there are 3 distinct prime factors: `2`, `3`, and `5`.

- **Input:** `nums = [4, 16, 64]`  \
  **Explanation:** The product of these numbers is `4096`, which has the prime factorization `2^12`. Hence, there is only 1 distinct prime factor: `2`.

{{< dots >}}
## Approach 🚀
The solution involves iterating through each element in the array, finding its prime factors, and storing them in a set to ensure distinctness. The final answer is the size of the set.

### Initial Thoughts 💭
- We need to find all prime factors of numbers in `nums` and ensure that we count distinct prime factors only.
- We can use a set to store prime factors as they are discovered. This ensures that each prime factor is counted only once.
{{< dots >}}
### Edge Cases 🌐
- This problem does not require handling empty inputs as `nums` will always contain at least one element.
- The solution should handle arrays with up to 10^4 elements efficiently.
- Special attention is needed when elements in `nums` are powers of a single prime (e.g., `4, 16, 64`).
- Ensure that the prime factorization process works efficiently for numbers up to 1000.
{{< dots >}}
## Code 💻
```cpp
set<int> cnt;

void fact(int num) {
    while(num % 2 == 0) {
        cnt.insert(2);
        num /= 2;
    }
    for(int i = 3; i <= num; i+=2) {
        while(num % i == 0) {
            cnt.insert(i);
            num /= i;
        }
    }
}

int distinctPrimeFactors(vector<int>& nums) {
    
    int n = nums.size();
    for(int i = 0; i < n; i++)
        fact(nums[i]);
    
    
    return cnt.size() ;
}
```

This code defines a function to calculate the number of distinct prime factors of integers in a vector `nums`. The `fact` function factors each number and inserts the prime factors into a set `cnt`. The `distinctPrimeFactors` function iterates over the input numbers, calling `fact` on each, and returns the number of distinct prime factors.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Set Initialization**
	```cpp
	set<int> cnt;
	```
	Define a set `cnt` to store the distinct prime factors of the input numbers.

2. **Empty Line**
	```cpp
	
	```
	An empty line for visual separation in the code.

3. **Function Definition**
	```cpp
	void fact(int num) {
	```
	Define the function `fact` which takes an integer `num` as input and factors it into prime factors.

4. **While Loop (Even Factor)**
	```cpp
	    while(num % 2 == 0) {
	```
	Check if `num` is divisible by 2. If true, continue dividing `num` by 2 and insert 2 into the set `cnt`.

5. **Set Insertion**
	```cpp
	        cnt.insert(2);
	```
	Insert the prime factor 2 into the set `cnt`.

6. **Division**
	```cpp
	        num /= 2;
	```
	Divide `num` by 2 and continue checking if it is divisible by 2 until it is no longer divisible.

7. **For Loop (Odd Factors)**
	```cpp
	    for(int i = 3; i <= num; i+=2) {
	```
	Start a for loop to check divisibility by odd numbers starting from 3, incrementing by 2 each time.

8. **While Loop (Odd Factor)**
	```cpp
	        while(num % i == 0) {
	```
	Check if `num` is divisible by the current odd number `i`. If true, continue dividing `num` by `i` and insert `i` into the set `cnt`.

9. **Set Insertion**
	```cpp
	            cnt.insert(i);
	```
	Insert the prime factor `i` into the set `cnt`.

10. **Division**
	```cpp
	            num /= i;
	```
	Divide `num` by `i` and continue checking if it is divisible by `i` until it is no longer divisible.

11. **Function Definition**
	```cpp
	int distinctPrimeFactors(vector<int>& nums) {
	```
	Define the function `distinctPrimeFactors`, which takes a vector of integers `nums` as input and calculates the number of distinct prime factors of all the numbers in the vector.

12. **Size Calculation**
	```cpp
	    int n = nums.size();
	```
	Calculate the size of the input vector `nums` and store it in the variable `n`.

13. **For Loop (Iterating Over Numbers)**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Start a for loop to iterate over each element of the input vector `nums`.

14. **Function Call**
	```cpp
	        fact(nums[i]);
	```
	Call the `fact` function on each element of `nums` to calculate its prime factors and insert them into the set `cnt`.

15. **Return Statement**
	```cpp
	    return cnt.size();
	```
	Return the size of the set `cnt`, which contains the distinct prime factors of all the numbers in the vector `nums`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log m), where n is the length of `nums` and m is the largest number in `nums`.
- **Average Case:** O(n log m), where n is the length of `nums` and m is the largest number in `nums`.
- **Worst Case:** O(n log m), where n is the length of `nums` and m is the largest number in `nums`.

Finding prime factors for each number requires trial division up to the square root of the number, which is logarithmic in nature.

### Space Complexity 💾
- **Best Case:** O(n), where n is the number of distinct prime factors found.
- **Worst Case:** O(n), where n is the number of distinct prime factors found.

We store each prime factor in a set, so space complexity depends on the number of distinct prime factors.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/description/)

---
{{< youtube HKc9PcSzNic >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
