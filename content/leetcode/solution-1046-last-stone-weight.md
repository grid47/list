
+++
authors = ["grid47"]
title = "Leetcode 1046: Last Stone Weight"
date = "2024-07-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1046: Last Stone Weight in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Heap (Priority Queue)"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "bmcFr1AdiJg"
youtube_upload_date="2023-04-24"
youtube_thumbnail="https://i.ytimg.com/vi/bmcFr1AdiJg/maxresdefault.jpg"
comments = true
+++



---
In this problem, we have an array of integers representing stones. Each stone has a weight, and on each turn, we choose the two heaviest stones, smash them together, and apply the following rules: If the two stones have the same weight, both are destroyed. If they have different weights, the stone with the smaller weight is destroyed, and the stone with the larger weight gets reduced by the smaller stone's weight. The process continues until at most one stone remains. Your task is to return the weight of the last remaining stone. If no stones are left, return 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array `stones`, where each element represents the weight of a stone.
- **Example:** `Input: stones = [5, 10, 2, 6]`
- **Constraints:**
	- 1 <= stones.length <= 30
	- 1 <= stones[i] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the weight of the last remaining stone after applying the smash rules described above. If there are no stones left, return 0.
- **Example:** `Output: 4`
- **Constraints:**
	- The result will always fit within a 32-bit integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to simulate the process of smashing stones and compute the weight of the last remaining stone.

- 1. Use a priority queue (max heap) to efficiently find and remove the two heaviest stones.
- 2. Continue the process of smashing the two heaviest stones until one or no stones remain.
- 3. If there is one stone left, return its weight. If no stones remain, return 0.
{{< dots >}}
### Problem Assumptions ✅
- At least one stone will always be present.
- Stone weights will be positive integers.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: stones = [5, 10, 2, 6]`  \
  **Explanation:** We start with the stones [5, 10, 2, 6]. First, we smash 10 and 6, resulting in 4 (10 - 6). The new array is [5, 2, 4]. Next, we smash 5 and 4, resulting in 1 (5 - 4). The new array is [2, 1]. Finally, we smash 2 and 1, resulting in 1. The last stone remaining is 1.

- **Input:** `Input: stones = [3, 7, 9, 5]`  \
  **Explanation:** We start with the stones [3, 7, 9, 5]. First, we smash 9 and 7, resulting in 2 (9 - 7). The new array is [3, 5, 2]. Next, we smash 5 and 3, resulting in 2 (5 - 3). The new array is [2, 2]. Finally, we smash 2 and 2, resulting in 0. The last stone remaining is 0.

{{< dots >}}
## Approach 🚀
The solution involves using a max heap (priority queue) to efficiently manage the largest stones and simulate the smashing process.

### Initial Thoughts 💭
- The priority queue is a good data structure for this problem since it allows us to quickly retrieve the largest elements.
- We can use a max heap to always retrieve and remove the heaviest stones during each turn.
{{< dots >}}
### Edge Cases 🌐
- The array will never be empty, as there will always be at least one stone.
- For the maximum input size of 30 stones, the algorithm will still perform efficiently due to the use of a priority queue.
- If all stones are the same, they will all be destroyed in pairs until no stones remain.
- We are guaranteed that there will be at most 30 stones, so the priority queue approach will work efficiently.
{{< dots >}}
## Code 💻
```cpp
priority_queue<int> pq;
int lastStoneWeight(vector<int>& stones) {
    for(int x: stones) {
        pq.push(x);
    }
    while(!pq.empty()) {
        int x = pq.top();
        pq.pop();
        if(pq.empty()) return x;
        
        int y = pq.top();
         pq.pop();
         if(y == x) {}
         else {
                pq.push(abs(y-x));
         }            
    }
    return 0;
}
```

This function simulates the process of smashing stones, where the largest stones are chosen two at a time, and if they are not equal in weight, the result of their collision is reinserted back into the priority queue. The function repeats this until there is one stone or none left, returning the weight of the last remaining stone, or 0 if no stones are left.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	priority_queue<int> pq;
	```
	Declare a priority queue 'pq' to store the stones' weights in a way that allows easy retrieval of the heaviest stones.

2. **Function Definition**
	```cpp
	int lastStoneWeight(vector<int>& stones) {
	```
	Define the function 'lastStoneWeight' that accepts a vector of integers representing stone weights and returns the weight of the last stone or 0 if no stone is left.

3. **Loop Through Stones**
	```cpp
	    for(int x: stones) {
	```
	Loop through the vector 'stones', where each stone's weight is stored in the variable 'x'.

4. **Push to Priority Queue**
	```cpp
	        pq.push(x);
	```
	Push each stone's weight 'x' into the priority queue 'pq' to maintain the stones in a max-heap order.

5. **While Loop**
	```cpp
	    while(!pq.empty()) {
	```
	Start a while loop that continues as long as there are stones remaining in the priority queue.

6. **Pop Maximum Stone**
	```cpp
	        int x = pq.top();
	```
	Retrieve the heaviest stone from the priority queue (the top element) and store it in the variable 'x'.

7. **Pop Maximum Stone**
	```cpp
	        pq.pop();
	```
	Remove the heaviest stone from the priority queue after it has been retrieved.

8. **Base Case**
	```cpp
	        if(pq.empty()) return x;
	```
	If there are no stones left in the priority queue, return the weight of the last remaining stone 'x'.

9. **Pop Next Stone**
	```cpp
	        int y = pq.top();
	```
	Retrieve the next heaviest stone from the priority queue and store its weight in the variable 'y'.

10. **Pop Next Stone**
	```cpp
	         pq.pop();
	```
	Remove the second heaviest stone from the priority queue.

11. **Collision Check**
	```cpp
	         if(y == x) {}
	```
	If the two stones have equal weights, no action is needed as both are destroyed.

12. **Push Result Back**
	```cpp
	         else {
	```
	If the stones have different weights, compute the result of their collision.

13. **Push Result Back**
	```cpp
	                pq.push(abs(y-x));
	```
	Push the result of the collision (absolute difference between 'x' and 'y') back into the priority queue to continue the process.

14. **Return Final Result**
	```cpp
	    return 0;
	```
	If the while loop finishes without returning a result, return 0, indicating there are no stones left.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

In the worst case, we perform n-1 operations, where each operation involves removing the two largest stones from the priority queue, which takes O(log n) time.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required to store the priority queue with the stones.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/last-stone-weight/description/)

---
{{< youtube bmcFr1AdiJg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
