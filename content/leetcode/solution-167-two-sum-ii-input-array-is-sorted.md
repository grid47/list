
+++
authors = ["grid47"]
title = "Leetcode 167: Two Sum II - Input Array Is Sorted"
date = "2024-10-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 167: Two Sum II - Input Array Is Sorted in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/167.webp"
youtube = "ciPrKYoOQkI"
youtube_upload_date="2024-01-14"
youtube_thumbnail="https://i.ytimg.com/vi/ciPrKYoOQkI/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/167.webp" 
    alt="A sorted array with glowing pairs of numbers, gently highlighting the solution to the sum."
    caption="Solution to LeetCode 167: Two Sum II - Input Array Is Sorted Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a sorted array of integers, find two numbers whose sum equals a target value. Return the indices of these two numbers, ensuring they are 1-indexed.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a sorted array `numbers` of integers and a `target` integer.
- **Example:** `numbers = [1, 5, 8, 12], target = 13`
- **Constraints:**
	- 2 <= numbers.length <= 30,000
	- -1,000 <= numbers[i] <= 1,000
	- The array is sorted in non-decreasing order.
	- -1,000 <= target <= 1,000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array of two integers representing the 1-indexed positions of the two numbers that add up to the target.
- **Example:** `Output: [2, 3]`
- **Constraints:**
	- The output array contains exactly two integers.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find two indices such that the sum of the numbers at those indices equals the target.

- Use a two-pointer approach to iterate through the array.
- Start with pointers at the beginning and end of the array.
- Move the pointers towards each other based on whether the sum is less than or greater than the target.
{{< dots >}}
### Problem Assumptions ✅
- The array is already sorted in non-decreasing order.
- There is exactly one valid solution.
{{< dots >}}
## Examples 🧩
- **Input:** `numbers = [1, 5, 8, 12], target = 13`  \
  **Explanation:** The sum of 5 and 8 equals 13, so the solution is at indices 2 and 3.

{{< dots >}}
## Approach 🚀
We will use a two-pointer approach to efficiently find the solution in O(n) time.

### Initial Thoughts 💭
- The array is sorted, so we can use the two-pointer technique to find the pair.
- We will initialize two pointers: one at the beginning and one at the end of the array, and move them based on the current sum.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that the array will always have at least two elements.
- For large arrays, the solution is efficient with O(n) time complexity.
- If the target is negative, the same approach works.
- Since the array is sorted and there's exactly one solution, the two-pointer approach is optimal.
{{< dots >}}
## Code 💻
```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans(2, 0);
    map<int, int> mp;
    for(int i = 0; i < nums.size(); i++) {
        if(mp.count(nums[i])) {
            ans[0] = mp[nums[i]] + 1;
            ans[1] = i + 1;
            return ans;
        } else {
            mp[target - nums[i]] = i;
        }
    }
    return ans;
}
```

This function solves the 'Two Sum' problem by finding two indices in the array such that their sum equals the given target. It uses a map to store the complement of the target minus the current number and its index.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> twoSum(vector<int>& nums, int target) {
	```
	Define the function 'twoSum' which takes a vector of integers 'nums' and an integer 'target', and returns a vector of two indices whose sum equals the target.

2. **Variable Initialization**
	```cpp
	    vector<int> ans(2, 0);
	```
	Initialize a vector 'ans' with two elements, both set to 0, which will store the indices of the two numbers that sum to the target.

3. **Map Declaration**
	```cpp
	    map<int, int> mp;
	```
	Declare a map 'mp' to store the complement (target - nums[i]) as the key, and the index of the number as the value.

4. **For Loop**
	```cpp
	    for(int i = 0; i < nums.size(); i++) {
	```
	Start a loop to iterate through each element of the input vector 'nums'.

5. **Condition Check**
	```cpp
	        if(mp.count(nums[i])) {
	```
	Check if the current number 'nums[i]' exists in the map 'mp'. If it does, the two sum condition is met.

6. **Index Assignment**
	```cpp
	            ans[0] = mp[nums[i]] + 1;
	```
	If the condition is true, assign the index of the first number (found in the map) to 'ans[0]'. Add 1 to make the index 1-based.

7. **Index Assignment**
	```cpp
	            ans[1] = i + 1;
	```
	Assign the current index 'i' to 'ans[1]' (adding 1 to make it 1-based) as the second index of the two numbers whose sum equals the target.

8. **Return Statement**
	```cpp
	            return ans;
	```
	Return the result vector 'ans' containing the indices of the two numbers that sum to the target.

9. **Else Condition**
	```cpp
	        } else {
	```
	If the current number is not in the map, proceed to store its complement (target - nums[i]) in the map.

10. **Map Insertion**
	```cpp
	            mp[target - nums[i]] = i;
	```
	Store the complement of the current number (target - nums[i]) as the key and its index 'i' as the value in the map 'mp'.

11. **Return Statement**
	```cpp
	    return ans;
	```
	Return the 'ans' vector, which will contain the indices of the two numbers whose sum equals the target, if they are found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we only need to iterate through the array once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we are using only constant extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/)

---
{{< youtube ciPrKYoOQkI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
