
+++
authors = ["grid47"]
title = "Leetcode 2815: Max Pair Sum in an Array"
date = "2024-01-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2815: Max Pair Sum in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "DUrmIZhrj4o"
youtube_upload_date="2023-08-13"
youtube_thumbnail="https://i.ytimg.com/vi/DUrmIZhrj4o/maxresdefault.jpg"
comments = true
+++



---
You are given an integer array `nums`, and you need to find the maximum sum of any two distinct numbers in the array such that the largest digit in both numbers is the same.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers `nums`.
- **Example:** `nums = [2536, 1613, 3366, 162]`
- **Constraints:**
	- 2 <= nums.length <= 100
	- 1 <= nums[i] <= 104

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum sum of two numbers from the array where the largest digit in both numbers is the same. If no such pair exists, return -1.
- **Example:** `5902`
- **Constraints:**
	- The answer will always be a valid integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the pair of numbers with the same largest digit and return their maximum sum.

- 1. Identify the largest digit in each number.
- 2. Group numbers by their largest digits.
- 3. For each group, find the two largest numbers and return their sum.
- 4. If no group has at least two numbers, return -1.
{{< dots >}}
### Problem Assumptions ✅
- The input array will always contain at least two integers.
- The numbers in the array are positive integers.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [2536, 1613, 3366, 162]`  \
  **Explanation:** All numbers in the list have 6 as their largest digit. The sum of the two largest numbers, 2536 and 3366, gives the maximum sum of 5902.

{{< dots >}}
## Approach 🚀
To solve this problem, we can iterate through the numbers, extract their largest digit, and group numbers by this digit. Then, we can find the two largest numbers in each group and compute the maximum sum.

### Initial Thoughts 💭
- We need to efficiently find the largest digit in each number.
- We need to group the numbers based on their largest digit.
- We can use a dictionary to store numbers grouped by their largest digit.
{{< dots >}}
### Edge Cases 🌐
- Input should always have at least two numbers.
- The input size will not exceed 100 elements.
- If no two numbers share the same largest digit, return -1.
- The input size is manageable with respect to both time and space complexity.
{{< dots >}}
## Code 💻
```cpp
int maxSum(vector<int>& nums) {
    
    vector<vector<int>> ids(10);
    
    for(int x: nums) {
        int val = x;
        int f = x % 10;
        while(x > 0) {
            f = max(f, x % 10);
            x /= 10;
        }
        ids[f].push_back(val);            
    }
    int ans = -1;
    for(int i = 0; i < ids.size(); i++) {
        sort(ids[i].begin(), ids[i].end());
        int n = ids[i].size();
        if(ids[i].size() >= 2) {
            // cout << ids[i][n - 1] << " " << ids[i][n - 2] << " "<< ids[i][n - 1] + ids[i][n - 2] << "\n";
            ans = max(ans, ids[i][n - 1] + ids[i][n - 2]);
        }
    }
    return ans;
}
```

This function calculates the maximum sum of two numbers from a list where both numbers share the same highest digit. It iterates through each number, extracts its highest digit, and adds the number to a bucket indexed by that digit. Then, it finds the two largest numbers in each bucket and returns the maximum sum found across all buckets.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int maxSum(vector<int>& nums) {
	```
	Declares the function `maxSum`, which takes a vector of integers `nums` and returns an integer value.

2. **Vector Initialization**
	```cpp
	    vector<vector<int>> ids(10);
	```
	Initializes a 2D vector `ids` of size 10 to store numbers categorized by their highest digit.

3. **For Loop Start**
	```cpp
	    for(int x: nums) {
	```
	Starts a loop to iterate over each integer `x` in the input vector `nums`.

4. **Assign Value**
	```cpp
	        int val = x;
	```
	Assigns the value of `x` to a new variable `val` to preserve the original number.

5. **Get Last Digit**
	```cpp
	        int f = x % 10;
	```
	Extracts the last digit of `x` by taking the modulus with 10 and stores it in `f`.

6. **While Loop Start**
	```cpp
	        while(x > 0) {
	```
	Begins a while loop to iterate through each digit of `x` to find the highest digit.

7. **Find Maximum Digit**
	```cpp
	            f = max(f, x % 10);
	```
	Updates `f` to store the maximum digit encountered during the iteration.

8. **Remove Last Digit**
	```cpp
	            x /= 10;
	```
	Reduces `x` by removing its last digit.

9. **Store Value in Bucket**
	```cpp
	        ids[f].push_back(val);            
	```
	Adds the value `val` to the bucket `ids[f]` corresponding to its highest digit `f`.

10. **Initialize Answer**
	```cpp
	    int ans = -1;
	```
	Initializes the variable `ans` to -1 to store the maximum sum found.

11. **Bucket Processing Loop**
	```cpp
	    for(int i = 0; i < ids.size(); i++) {
	```
	Starts a loop to process each bucket in `ids`.

12. **Sort Bucket**
	```cpp
	        sort(ids[i].begin(), ids[i].end());
	```
	Sorts the numbers in bucket `ids[i]` in ascending order.

13. **Bucket Size Check**
	```cpp
	        int n = ids[i].size();
	```
	Stores the size of bucket `ids[i]` in the variable `n`.

14. **Check for Two Numbers**
	```cpp
	        if(ids[i].size() >= 2) {
	```
	Checks if there are at least two numbers in the bucket to calculate a sum.

15. **Calculate Maximum Sum**
	```cpp
	            ans = max(ans, ids[i][n - 1] + ids[i][n - 2]);
	```
	Calculates the sum of the two largest numbers in the current bucket and updates `ans` if the sum is greater than the current value of `ans`.

16. **Return Result**
	```cpp
	    return ans;
	```
	Returns the maximum sum found, stored in `ans`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n) where n is the length of the array.
- **Average Case:** O(n log n).
- **Worst Case:** O(n log n).

The dominant factor is the sorting operation for each group of numbers.

### Space Complexity 💾
- **Best Case:** O(n) for storing the numbers in the dictionary.
- **Worst Case:** O(n) for storing the numbers in the dictionary.

The space complexity is proportional to the number of elements in the input array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/max-pair-sum-in-an-array/description/)

---
{{< youtube DUrmIZhrj4o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
