
+++
authors = ["grid47"]
title = "Leetcode 2530: Maximal Score After Applying K Operations"
date = "2024-02-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2530: Maximal Score After Applying K Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "nsOipmYbRlc"
youtube_upload_date="2023-01-08"
youtube_thumbnail="https://i.ytimg.com/vi/nsOipmYbRlc/maxresdefault.jpg"
comments = true
+++



---
You are given a list of integers `nums` and an integer `k`. In each operation, you choose an index `i`, increase your score by `nums[i]`, and replace `nums[i]` with `ceil(nums[i] / 3)`. Apply exactly `k` operations and return the maximum score you can achieve.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `nums` of integers and an integer `k`.
- **Example:** `[10, 10, 10, 10, 10], 5`
- **Constraints:**
	- 1 <= nums.length, k <= 10^5
	- 1 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a single integer representing the maximum score after applying exactly `k` operations.
- **Example:** `50`
- **Constraints:**
	- The output will be an integer representing the maximum score achievable.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to maximize the score by carefully selecting the index `i` at each operation.

- Initialize a max-heap (priority queue) with all elements of `nums`.
- For each of the `k` operations, extract the maximum element, increase the score by this value, and replace it with `ceil(nums[i] / 3)`.
- Repeat the operation for exactly `k` times and return the final score.
{{< dots >}}
### Problem Assumptions ✅
- You must apply exactly `k` operations.
- The `nums` array is modified after each operation.
{{< dots >}}
## Examples 🧩
- **Input:** `[15, 10, 20, 5, 30], 5`  \
  **Explanation:** In this example, after applying the operation to each element, the final score is 15 + 20 + 30 + 5 + 10 = 80.

- **Input:** `[10, 20, 15, 10], 3`  \
  **Explanation:** The optimal sequence of operations results in a final score of 45.

- **Input:** `[1, 1, 1, 1, 1], 3`  \
  **Explanation:** In this case, after 3 operations, the score is simply 3.

{{< dots >}}
## Approach 🚀
To maximize the score, always choose the largest element for each operation, ensuring the most valuable elements are reduced in value last.

### Initial Thoughts 💭
- Using a max-heap (priority queue) helps efficiently find the largest element for each operation.
- The solution needs to be efficient, as `nums.length` and `k` can be as large as 100,000.
{{< dots >}}
### Edge Cases 🌐
- The array `nums` is always non-empty, as the length is at least 1.
- Ensure that the solution works efficiently for large inputs (up to 100,000 elements and operations).
- Handle cases where elements are small, such as 1, which will always be replaced by 1 after an operation.
- The problem requires an efficient approach, such as using a max-heap to handle up to 100,000 operations efficiently.
{{< dots >}}
## Code 💻
```cpp
long long maxKelements(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for(int i = 0; i < nums.size(); i++) {
        pq.push(nums[i]);
    }
    long long ans = 0;
    while(k--) {
        int tmp = pq.top();
        cout << tmp << " ";
        ans += tmp;
        pq.pop();
        pq.push(ceil(tmp/3.0));
        
    }
    return ans;
}
```

The 'maxKelements' function computes the sum of the 'k' largest elements from a vector 'nums', repeatedly modifying these elements by dividing each one by 3 after it is used.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	long long maxKelements(vector<int>& nums, int k) {
	```
	This is the function definition for 'maxKelements', which accepts a vector of integers 'nums' and an integer 'k', returning a long long value.

2. **Variable Initialization**
	```cpp
	    priority_queue<int> pq;
	```
	A priority queue 'pq' is declared to store integers. This will be used to efficiently access the largest element at any time.

3. **Loop**
	```cpp
	    for(int i = 0; i < nums.size(); i++) {
	```
	A for loop is initiated to iterate over the vector 'nums' and push each element into the priority queue.

4. **Queue Operation**
	```cpp
	        pq.push(nums[i]);
	```
	Each element from the 'nums' vector is pushed into the priority queue 'pq', which will automatically arrange the elements in descending order.

5. **Variable Initialization**
	```cpp
	    long long ans = 0;
	```
	A variable 'ans' is initialized to 0 to store the cumulative sum of the largest elements selected from the queue.

6. **Loop**
	```cpp
	    while(k--) {
	```
	A while loop runs 'k' times to extract the largest element, update it, and accumulate the result.

7. **Queue Operation**
	```cpp
	        int tmp = pq.top();
	```
	The top element of the priority queue (the largest element) is stored in the variable 'tmp'.

8. **Accumulate Sum**
	```cpp
	        ans += tmp;
	```
	The value of 'tmp' is added to the cumulative sum 'ans'.

9. **Queue Operation**
	```cpp
	        pq.pop();
	```
	The top element (which has already been used) is removed from the priority queue.

10. **Queue Operation**
	```cpp
	        pq.push(ceil(tmp/3.0));
	```
	The value 'tmp' is divided by 3 and rounded up, then pushed back into the priority queue to be used in subsequent iterations.

11. **Return Statement**
	```cpp
	    return ans;
	```
	The final accumulated sum 'ans' is returned as the result of the function.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(k log n)
- **Average Case:** O(k log n)
- **Worst Case:** O(k log n)

Each heap operation (extract and insert) takes O(log n) time, and we perform `k` operations.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of the heap, where `n` is the length of the `nums` array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximal-score-after-applying-k-operations/description/)

---
{{< youtube nsOipmYbRlc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
