
+++
authors = ["grid47"]
title = "Leetcode 1962: Remove Stones to Minimize the Total"
date = "2024-04-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1962: Remove Stones to Minimize the Total in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "lLAvgl2voc4"
youtube_upload_date="2021-08-08"
youtube_thumbnail="https://i.ytimg.com/vi_webp/lLAvgl2voc4/maxresdefault.webp"
comments = true
+++



---
You are given an array of integers `piles`, where each element represents the number of stones in a pile, and an integer `k`. You need to perform the following operation exactly `k` times: Choose any pile, and remove `floor(piles[i] / 2)` stones from it. You can apply the operation to the same pile multiple times. The goal is to minimize the total number of stones left in all piles after performing the operation `k` times.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers `piles` and an integer `k`. The `piles` array represents the initial number of stones in each pile, and `k` represents the number of operations to perform.
- **Example:** `piles = [10, 20, 30], k = 3`
- **Constraints:**
	- 1 <= piles.length <= 10^5
	- 1 <= piles[i] <= 10^4
	- 1 <= k <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a single integer representing the minimum possible total number of stones left after applying the `k` operations.
- **Example:** `Output: 50`
- **Constraints:**
	- The total number of stones in all piles should be minimized after exactly `k` operations.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to reduce the total number of stones by performing `k` operations on the piles, by always removing the maximum number of stones possible at each step.

- Step 1: Use a max-heap (priority queue) to efficiently select the pile with the most stones at each operation.
- Step 2: For each operation, remove stones from the pile with the most stones, reducing it by half (floor division).
- Step 3: Repeat this process `k` times.
- Step 4: After all operations, sum the remaining stones in the piles to get the result.
{{< dots >}}
### Problem Assumptions ✅
- The input array `piles` is non-empty.
- The integer `k` is within the valid range.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: piles = [10, 20, 30], k = 3`  \
  **Explanation:** In this example, we have 3 piles with 10, 20, and 30 stones, and we are allowed 3 operations. The optimal sequence is to remove stones from the piles with the most stones in each operation, thus minimizing the total stones remaining.

{{< dots >}}
## Approach 🚀
The approach is to use a max-heap (priority queue) to repeatedly select the pile with the most stones and perform the operation of removing `floor(piles[i] / 2)` stones from it. This ensures that the stones are removed in the most efficient way possible to minimize the total remaining.

### Initial Thoughts 💭
- Using a max-heap allows us to always select the pile with the maximum stones efficiently.
- We can perform each operation in logarithmic time relative to the number of piles, making this approach efficient enough for the input constraints.
{{< dots >}}
### Edge Cases 🌐
- The `piles` array will not be empty.
- Ensure the solution handles the maximum limits for both `piles.length` and `k` efficiently.
- If `k` is 0, no operation should be performed, and the sum of the stones remains unchanged.
- Ensure to handle the edge cases where piles have minimal or maximal values.
{{< dots >}}
## Code 💻
```cpp
int minStoneSum(vector<int>& piles, int k) {
    
    priority_queue<int> pq;
    
    for(int i = 0; i < piles.size(); i++)
        pq.push(piles[i]);
    
    while(k--) {
        int top = pq.top();
        top = top - floor(top/2);
        pq.pop();
        if(top > 0)
        pq.push(top);
    }

    int sum = 0;
    while(!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    return sum;
}
```

This function minimizes the sum of stone piles after performing k operations to reduce the largest stone pile by half.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Code Initialization**
	```cpp
	int minStoneSum(vector<int>& piles, int k) {
	```
	Function definition starts with taking two parameters: a vector of piles and an integer k representing the number of operations.

2. **Priority Queue Initialization**
	```cpp
	    priority_queue<int> pq;
	```
	A priority queue is created to store the stone piles, with the largest elements given higher priority.

3. **Initialization**
	```cpp
	    
	```
	Empty line for clarity.

4. **Loop Through Piles**
	```cpp
	    for(int i = 0; i < piles.size(); i++)
	```
	A loop starts to iterate over each pile.

5. **Priority Queue Population**
	```cpp
	        pq.push(piles[i]);
	```
	Each pile is added to the priority queue.

6. **While Loop for k Operations**
	```cpp
	    while(k--) {
	```
	A while loop begins to perform k operations, decrementing k each time.

7. **Top Element of Queue**
	```cpp
	        int top = pq.top();
	```
	The top element (largest pile) of the priority queue is fetched.

8. **Modify Top Element**
	```cpp
	        top = top - floor(top/2);
	```
	The top element is reduced by half (rounded down).

9. **Remove Top Element**
	```cpp
	        pq.pop();
	```
	The modified element is removed from the priority queue.

10. **Conditional Push Back**
	```cpp
	        if(top > 0)
	```
	If the new value is greater than 0, the modified value is pushed back into the priority queue.

11. **Push Modified Top**
	```cpp
	        pq.push(top);
	```
	The modified top value is reinserted into the priority queue.

12. **Sum Initialization**
	```cpp
	    int sum = 0;
	```
	A variable 'sum' is initialized to accumulate the final sum of the remaining stone piles.

13. **Sum Calculation**
	```cpp
	    while(!pq.empty()) {
	```
	A loop begins to calculate the sum of the remaining piles in the priority queue.

14. **Add Top to Sum**
	```cpp
	        sum += pq.top();
	```
	The top element of the priority queue (the largest remaining pile) is added to the sum.

15. **Remove Top**
	```cpp
	        pq.pop();
	```
	The top element is removed from the priority queue after being added to the sum.

16. **Return Result**
	```cpp
	    return sum;
	```
	The final sum of the stone piles is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(k log n)
- **Average Case:** O(k log n)
- **Worst Case:** O(k log n)

In each operation, we perform a pop and push operation on the heap, both of which take O(log n) time, where `n` is the number of piles.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the heap, where `n` is the number of piles.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/)

---
{{< youtube lLAvgl2voc4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
