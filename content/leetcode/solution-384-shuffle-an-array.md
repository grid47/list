
+++
authors = ["grid47"]
title = "Leetcode 384: Shuffle an Array"
date = "2024-09-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 384: Shuffle an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Randomized"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/384.webp"
youtube = "LSNxktnyoh8"
youtube_upload_date="2021-05-01"
youtube_thumbnail="https://i.ytimg.com/vi/LSNxktnyoh8/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/384.webp" 
    alt="A glowing array where elements shuffle into new positions, gently highlighting the change."
    caption="Solution to LeetCode 384: Shuffle an Array Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an integer array nums. Design an algorithm to randomly shuffle the array. All permutations of the array should be equally likely as a result of the shuffling.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array nums.
- **Example:** `nums = [1, 2, 3]`
- **Constraints:**
	- 1 <= nums.length <= 50
	- -10^6 <= nums[i] <= 10^6
	- All elements of nums are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output consists of the array after applying the shuffle or reset method.
- **Example:** `Output: [3, 1, 2] after shuffle, [1, 2, 3] after reset`
- **Constraints:**
	- The result of shuffle should be a random permutation of the array.
	- The result of reset should return the array in its original configuration.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to implement a random shuffle that gives each permutation an equal probability.

- Save the original configuration of the array.
- Use the Fisher-Yates (or Knuth) algorithm to shuffle the array randomly.
- On calling reset, return the original configuration.
- On calling shuffle, return a new randomly shuffled version of the array.
{{< dots >}}
### Problem Assumptions ✅
- The input array is non-empty and has unique elements.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: [1, 2, 3]`  \
  **Explanation:** The shuffle operation should return a random permutation of [1, 2, 3] such as [3, 1, 2]. The reset operation should return the array to its original form [1, 2, 3].

{{< dots >}}
## Approach 🚀
The approach involves using a simple but efficient algorithm for shuffling (like Fisher-Yates) and maintaining the original array for reset.

### Initial Thoughts 💭
- Randomly shuffling requires a well-known algorithm to ensure each permutation has equal probability.
- By maintaining the original array and shuffling a copy, we can ensure efficient reset and shuffle operations.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that nums will have at least one element.
- The solution should handle cases where nums has up to 50 elements efficiently.
- Ensure that shuffle works even when nums has only one element, as this is a valid edge case.
- Ensure the shuffle operation is random but efficient.
{{< dots >}}
## Code 💻
```cpp
class Solution {
vector<int> arr;
public:
Solution(vector<int>& nums) {
    arr = nums;
}

vector<int> reset() {
    return arr;
}

vector<int> shuffle() {
    vector<int> stk(arr);
    int n = stk.size();
    for(int i = 0; i < n; i++) {
        int j = rand() % (n - i);
        swap(stk[i + j], stk[i]);
    }
    return stk;
}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
```

This class `Solution` handles the `reset` and `shuffle` operations on a given array. The `reset` function returns the original array, while the `shuffle` function randomly shuffles the array elements using the Fisher-Yates algorithm.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class Solution {
	```
	This line defines the class `Solution` that will contain methods to reset and shuffle an array.

2. **Member Variable**
	```cpp
	vector<int> arr;
	```
	A private member variable `arr` is defined to store the original array passed to the constructor.

3. **Access Specifier**
	```cpp
	public:
	```
	The `public` access specifier follows, meaning that the subsequent methods will be accessible outside the class.

4. **Constructor**
	```cpp
	Solution(vector<int>& nums) {
	```
	The constructor `Solution` takes a reference to a vector `nums` and initializes the member variable `arr` with the input array.

5. **Constructor Logic**
	```cpp
	    arr = nums;
	```
	The constructor assigns the input array `nums` to the member variable `arr` to store the original array.

6. **Reset Method**
	```cpp
	vector<int> reset() {
	```
	The `reset` method returns the original array stored in `arr`.

7. **Reset Logic**
	```cpp
	    return arr;
	```
	The `reset` method simply returns the original array `arr`.

8. **Shuffle Method**
	```cpp
	vector<int> shuffle() {
	```
	The `shuffle` method returns a randomly shuffled version of the original array `arr`.

9. **Shuffling Logic**
	```cpp
	    vector<int> stk(arr);
	```
	A new vector `stk` is created and initialized with the elements of the original array `arr`.

10. **Size Calculation**
	```cpp
	    int n = stk.size();
	```
	The size of the vector `stk` is stored in the variable `n`.

11. **Shuffling Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	This loop iterates over each element in the vector `stk` to perform the shuffling.

12. **Random Index Generation**
	```cpp
	        int j = rand() % (n - i);
	```
	A random index `j` is generated within the remaining unshuffled part of the array.

13. **Swapping Elements**
	```cpp
	        swap(stk[i + j], stk[i]);
	```
	The elements at indices `i` and `i + j` are swapped to shuffle the array.

14. **Return Shuffled Array**
	```cpp
	    return stk;
	```
	The shuffled array `stk` is returned from the `shuffle` method.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Both the shuffle and reset operations run in linear time.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is linear, as we store a copy of the original array and work with a temporary shuffled array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/shuffle-an-array/description/)

---
{{< youtube LSNxktnyoh8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
