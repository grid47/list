
+++
authors = ["grid47"]
title = "Leetcode 1985: Find the Kth Largest Integer in the Array"
date = "2024-04-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1985: Find the Kth Largest Integer in the Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Divide and Conquer","Sorting","Heap (Priority Queue)","Quickselect"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "lRCaNiqO3xI"
youtube_upload_date="2021-08-29"
youtube_thumbnail="https://i.ytimg.com/vi/lRCaNiqO3xI/maxresdefault.jpg"
comments = true
+++



---
You are given an array of strings nums, where each string represents a non-negative integer. You need to find the kth largest integer in the array. Note that duplicates should be considered distinctly. For example, if the array is ['1', '2', '2'], the first largest integer is '2', the second largest is also '2', and the third largest is '1'.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of strings nums, where each string represents an integer, and an integer k that represents the kth largest number to return.
- **Example:** `nums = ['5', '12', '15', '9'], k = 2`
- **Constraints:**
	- 1 <= k <= nums.length <= 10^4
	- 1 <= nums[i].length <= 100
	- nums[i] consists of only digits
	- nums[i] will not have any leading zeros

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the string that represents the kth largest integer from the input array.
- **Example:** `Output: '12'`
- **Constraints:**
	- The output should be the kth largest number, as a string.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the kth largest integer in the list, where duplicates are counted distinctly.

- Use a priority queue (min-heap) to maintain the top k largest numbers.
- For each number in the array, insert it into the priority queue.
- If the size of the heap exceeds k, remove the smallest element.
- After processing all numbers, the root of the heap will be the kth largest number.
{{< dots >}}
### Problem Assumptions ✅
- The array is non-empty and contains valid numbers as strings.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = ['5', '12', '15', '9'], k = 2`  \
  **Explanation:** After sorting the array in non-decreasing order, we get ['5', '9', '12', '15']. The 2nd largest number is '12'.

- **Input:** `Input: nums = ['2', '1', '2'], k = 3`  \
  **Explanation:** The sorted array is ['1', '2', '2']. The 3rd largest number is '1'.

{{< dots >}}
## Approach 🚀
We will use a priority queue (min-heap) to efficiently track the kth largest element as we process each element in the array.

### Initial Thoughts 💭
- We can maintain a heap of size k to efficiently keep track of the largest numbers seen so far.
- Using a heap will allow us to remove the smallest number efficiently when the heap size exceeds k, ensuring the heap always holds the k largest numbers.
{{< dots >}}
### Edge Cases 🌐
- The array will always contain at least one number, so this case doesn't need to be handled explicitly.
- For large arrays, ensure that the priority queue is implemented efficiently to handle up to 10,000 numbers.
- If k equals the length of the array, the kth largest number is the smallest element in the array.
- The algorithm should operate within O(n log k) time complexity, where n is the length of the array.
{{< dots >}}
## Code 💻
```cpp
string kthLargestNumber(vector<string>& nums, int k) {
    priority_queue<string, vector<string>, cmp> pq;
    for(int i = 0; i < nums.size(); i++) {
        
        pq.push(nums[i]);
        while(pq.size() > k) {
            pq.pop();
        }


    }
    
    return pq.top();
}
```

This function finds the k-th largest number in a list of string numbers using a priority queue to maintain the top k largest elements.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string kthLargestNumber(vector<string>& nums, int k) {
	```
	Defines the function `kthLargestNumber` which takes a vector of strings `nums` and an integer `k` to find the k-th largest number.

2. **Priority Queue Initialization**
	```cpp
	    priority_queue<string, vector<string>, cmp> pq;
	```
	Initializes a priority queue `pq` that will store strings in descending order based on the custom comparator `cmp`.

3. **Looping**
	```cpp
	    for(int i = 0; i < nums.size(); i++) {
	```
	Starts a loop that iterates through each element in the vector `nums`.

4. **Queue Operation**
	```cpp
	        pq.push(nums[i]);
	```
	Pushes the current string from `nums` into the priority queue.

5. **Queue Size Check**
	```cpp
	        while(pq.size() > k) {
	```
	Checks if the size of the priority queue exceeds `k`, and if so, removes the smallest element.

6. **Queue Operation**
	```cpp
	            pq.pop();
	```
	Removes the smallest element from the priority queue to maintain only the top `k` largest elements.

7. **Return Statement**
	```cpp
	    return pq.top();
	```
	Returns the top element of the priority queue, which will be the k-th largest number.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log k)
- **Average Case:** O(n log k)
- **Worst Case:** O(n log k)

We insert each element into the heap, which takes O(log k) time. The total time complexity is O(n log k), where n is the number of elements.

### Space Complexity 💾
- **Best Case:** O(k)
- **Worst Case:** O(k)

We use a heap of size k, so the space complexity is O(k).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/description/)

---
{{< youtube lRCaNiqO3xI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
