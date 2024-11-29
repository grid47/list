
+++
authors = ["grid47"]
title = "Leetcode 2233: Maximum Product After K Increments"
date = "2024-03-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2233: Maximum Product After K Increments in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "lSr-tKjbiAM"
youtube_upload_date="2022-04-10"
youtube_thumbnail="https://i.ytimg.com/vi_webp/lSr-tKjbiAM/maxresdefault.webp"
comments = true
+++



---
You are given an array of non-negative integers and an integer k. In one operation, you can choose any element from the array and increment it by 1. Your task is to determine the maximum product of the array elements after at most k operations. The result should be returned modulo 10^9 + 7.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array nums of integers and an integer k. The array nums contains non-negative integers.
- **Example:** `nums = [1, 2, 3], k = 4`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 0 <= nums[i] <= 10^6
	- 1 <= k <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum product of the array after performing at most k operations, modulo 10^9 + 7.
- **Example:** `Output: 72`
- **Constraints:**
	- The result should fit within the 32-bit signed integer range after taking the modulo.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to maximize the product of the array elements by distributing k increments across the elements. To achieve this, we want to increment the smallest elements first, as this maximizes the overall product.

- 1. Use a priority queue (min-heap) to store the elements in the array, ensuring that the smallest element can be incremented efficiently.
- 2. Increment the smallest element by 1 at each operation, and reinsert it back into the priority queue.
- 3. After performing all k operations, compute the product of all the elements in the array.
- 4. Return the product modulo 10^9 + 7.
{{< dots >}}
### Problem Assumptions ✅
- The array is non-empty and contains at least one element.
- The value of k is guaranteed to be a positive integer.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1, 2, 3], k = 4`  \
  **Explanation:** To maximize the product, we first increment 1 to 2, then 2 to 3, and finally increment 3 to 4. The array becomes [2, 3, 4], and the product is 2 * 3 * 4 = 24.

- **Input:** `Input: nums = [5, 1, 2], k = 3`  \
  **Explanation:** To maximize the product, we first increment 1 to 2, then 2 to 3, and finally 3 to 4. The array becomes [5, 3, 4], and the product is 5 * 3 * 4 = 60.

- **Input:** `Input: nums = [10, 20], k = 10`  \
  **Explanation:** Here, we increment the smaller number, 10, 10 times. The array becomes [20, 20], and the product is 20 * 20 = 400.

{{< dots >}}
## Approach 🚀
We approach the problem using a greedy strategy where we increment the smallest elements first to maximize the product. This can be efficiently achieved using a priority queue.

### Initial Thoughts 💭
- The product will be maximized by focusing on increasing the smallest numbers in the array.
- Using a priority queue (min-heap) allows us to efficiently increment the smallest element and track changes as we proceed with the operations.
{{< dots >}}
### Edge Cases 🌐
- The array is guaranteed to have at least one element.
- The algorithm must handle up to 100,000 elements and efficiently perform up to 100,000 operations.
- The array elements could be zero, which would require handling increment operations to avoid multiplication by zero.
- The priority queue approach is efficient enough to handle the constraints within the time limit.
{{< dots >}}
## Code 💻
```cpp
int maximumProduct(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
    
    while(k--) {
        int mini = pq.top();
        pq.pop();
        pq.push(mini + 1);
    }
    
    long long ans = 1, mod = (long) 1e9 + 7;
    
    while(!pq.empty()) {
        ans = ((ans % mod) * (pq.top() % mod)) % mod;
        pq.pop();
    }
    
    return ans;
}
```

This function calculates the maximum product that can be obtained by performing 'k' increment operations on the smallest elements of the array. It uses a priority queue to always increment the smallest element and calculates the product of the final elements modulo 1e9+7.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maximumProduct(vector<int>& nums, int k) {
	```
	Defines the function 'maximumProduct', which takes a vector of integers 'nums' and an integer 'k', and returns the maximum product after performing 'k' increments on the smallest elements in 'nums'.

2. **Priority Queue Initialization**
	```cpp
	    priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
	```
	Initializes a priority queue 'pq' to store the elements of 'nums' in ascending order, allowing easy access to the smallest element.

3. **Loop Initialization**
	```cpp
	    
	```
	The next step involves performing a loop to increment the smallest elements in the priority queue.

4. **Loop Control**
	```cpp
	    while(k--) {
	```
	This loop will run 'k' times, decrementing 'k' each time to perform the increment operation on the smallest element.

5. **Priority Queue Operations**
	```cpp
	        int mini = pq.top();
	```
	Extracts the smallest element from the priority queue and stores it in 'mini'.

6. **Priority Queue Operations**
	```cpp
	        pq.pop();
	```
	Removes the smallest element (stored in 'mini') from the priority queue.

7. **Priority Queue Operations**
	```cpp
	        pq.push(mini + 1);
	```
	Increments the smallest element and pushes it back into the priority queue.

8. **Variable Initialization**
	```cpp
	    long long ans = 1, mod = (long) 1e9 + 7;
	```
	Initializes 'ans' to 1 for storing the product result, and 'mod' to 1e9+7 to perform modulo operations and avoid overflow.

9. **Loop Control**
	```cpp
	    while(!pq.empty()) {
	```
	This loop will continue until the priority queue is empty, multiplying the elements to compute the product.

10. **Product Calculation**
	```cpp
	        ans = ((ans % mod) * (pq.top() % mod)) % mod;
	```
	Calculates the product of the current 'ans' and the top element of the priority queue, applying modulo to prevent overflow.

11. **Priority Queue Operations**
	```cpp
	        pq.pop();
	```
	Removes the top element from the priority queue after it has been used in the product calculation.

12. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the final result of the product of all elements in the priority queue after performing 'k' increments, modulo 1e9+7.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(k log n)

Each of the k operations involves extracting and inserting an element into the priority queue, which takes O(log n) time. Hence, the total time complexity is O(k log n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of the array in the priority queue.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-product-after-k-increments/description/)

---
{{< youtube lSr-tKjbiAM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
