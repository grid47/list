
+++
authors = ["grid47"]
title = "Leetcode 2462: Total Cost to Hire K Workers"
date = "2024-03-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2462: Total Cost to Hire K Workers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Heap (Priority Queue)","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "4hb3bZS1o1o"
youtube_upload_date="2022-11-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/4hb3bZS1o1o/maxresdefault.webp"
comments = true
+++



---
You are given an array of integers where each element represents the cost of hiring a worker. You need to hire exactly k workers by running k sessions. In each session, choose the worker with the lowest cost from either the first 'candidates' workers or the last 'candidates' workers. If there is a tie, choose the worker with the smallest index.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given three values: the costs array, k (the number of workers to hire), and candidates (the number of workers to consider from both the beginning and end of the remaining workers).
- **Example:** `costs = [5, 8, 3, 1, 6, 2], k = 2, candidates = 3`
- **Constraints:**
	- 1 <= costs.length <= 10^5
	- 1 <= costs[i] <= 10^5
	- 1 <= k, candidates <= costs.length

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the total cost of hiring exactly k workers following the selection rule.
- **Example:** `For costs = [5, 8, 3, 1, 6, 2], k = 2, candidates = 3, the output is 4.`
- **Constraints:**
	- The result should be an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** To hire exactly k workers by choosing from the first 'candidates' workers or the last 'candidates' workers based on the minimum cost and smallest index for ties.

- Initialize a priority queue to track the lowest cost workers.
- Iterate through the first 'candidates' and last 'candidates' workers, pushing them into the queue.
- For each of the k hiring sessions, pop the worker with the lowest cost and smallest index from the queue.
- After each hiring session, update the queue with the next possible workers from both the beginning and end.
{{< dots >}}
### Problem Assumptions ✅
- The workers are chosen according to the lowest cost with the smallest index for ties.
- Once a worker is chosen, they are no longer available for subsequent selections.
{{< dots >}}
## Examples 🧩
- **Input:** `For costs = [5, 8, 3, 1, 6, 2], k = 2, candidates = 3`  \
  **Explanation:** In the first hiring session, we choose the worker with the cost of 1 (index 3), and in the second session, we choose the worker with the cost of 3 (index 2), totaling 4.

{{< dots >}}
## Approach 🚀
Use a priority queue (min-heap) to select the lowest cost worker at each session from the first 'candidates' workers or the last 'candidates' workers.

### Initial Thoughts 💭
- We need to keep track of the workers in the first and last 'candidates' positions.
- A priority queue will help efficiently select the worker with the lowest cost.
- Ensure that the heap is updated after each selection to reflect the remaining candidates.
{{< dots >}}
### Edge Cases 🌐
- If the costs array is empty, return 0.
- If the array is large, ensure the solution is optimized for time complexity.
- If all workers have the same cost, select the worker with the smallest index.
- The solution must handle up to 100,000 workers efficiently.
{{< dots >}}
## Code 💻
```cpp
long long totalCost(vector<int>& costs, int k, int cand) {
    long long cost = 0;
    int n = costs.size();
    int l = cand - 1, r = n - cand; // inclusive
    
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    
    if(l >= r) {
        for(int i = 0; i < n; i++)
            pq.push({costs[i], i});
        
        while(k--) {
            cost += pq.top()[0];
            pq.pop();
        }
        return cost;
    }
    
    
    int i = 0;
    while(i <= l) {
        pq.push({costs[i], i});
        i++;
    }
    
    i = n - 1;
    
    while(i >= r) {
        pq.push({costs[i], i});
        i--;
    }
    
    while(k--) {
        auto it = pq.top();
        pq.pop();
        cost += it[0];
        if(it[1] <= l && l < r - 1) {
            l++;
            pq.push({costs[l], l});
        } else if(it[1] >= r && l < r - 1) {
            r--;
            pq.push({costs[r], r});
        }
        
    }
    return cost;
}
```

This code calculates the minimum total cost to choose 'k' workers by utilizing a priority queue to select candidates based on their costs efficiently.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	long long totalCost(vector<int>& costs, int k, int cand) {
	```
	The function signature defining inputs: a cost array, the number of workers 'k,' and a candidate range 'cand.'

2. **Variable Initialization**
	```cpp
	    long long cost = 0;
	```
	Initialize the total cost to zero.

3. **Variable Initialization**
	```cpp
	    int n = costs.size();
	```
	Determine the size of the input cost array.

4. **Variable Initialization**
	```cpp
	    int l = cand - 1, r = n - cand; // inclusive
	```
	Set up the left and right candidate range boundaries.

5. **Priority Queue Initialization**
	```cpp
	    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	```
	Declare a min-heap priority queue to manage costs and indices.

6. **Condition Check**
	```cpp
	    if(l >= r) {
	```
	Check if the left and right boundaries overlap, indicating all elements can be pushed directly.

7. **Loop**
	```cpp
	        for(int i = 0; i < n; i++)
	```
	Iterate through the entire cost array to push elements into the priority queue.

8. **Priority Queue Operation**
	```cpp
	            pq.push({costs[i], i});
	```
	Push the cost and index pair into the priority queue.

9. **Loop**
	```cpp
	        while(k--) {
	```
	Iterate to extract the minimum 'k' costs from the priority queue.

10. **Priority Queue Operation**
	```cpp
	            cost += pq.top()[0];
	```
	Add the minimum cost from the top of the queue.

11. **Priority Queue Operation**
	```cpp
	            pq.pop();
	```
	Remove the top element from the priority queue.

12. **Return**
	```cpp
	        return cost;
	```
	Return the total minimum cost when all workers are selected.

13. **Loop**
	```cpp
	    while(i <= l) {
	```
	Push elements from the left boundary range into the priority queue.

14. **Priority Queue Operation**
	```cpp
	        pq.push({costs[i], i});
	```
	Push left-side candidates into the priority queue.

15. **Loop**
	```cpp
	    while(i >= r) {
	```
	Push elements from the right boundary range into the priority queue.

16. **Priority Queue Operation**
	```cpp
	        pq.push({costs[i], i});
	```
	Push right-side candidates into the priority queue.

17. **Priority Queue Operation**
	```cpp
	        auto it = pq.top();
	```
	Extract the current minimum cost element.

18. **Condition Check**
	```cpp
	        if(it[1] <= l && l < r - 1) {
	```
	Check if the selected candidate is from the left and adjust the boundary.

19. **Priority Queue Operation**
	```cpp
	            pq.push({costs[l], l});
	```
	Push the next candidate from the left boundary.

20. **Condition Check**
	```cpp
	        } else if(it[1] >= r && l < r - 1) {
	```
	Check if the selected candidate is from the right and adjust the boundary.

21. **Priority Queue Operation**
	```cpp
	            pq.push({costs[r], r});
	```
	Push the next candidate from the right boundary.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(k log k)
- **Average Case:** O(k log k)
- **Worst Case:** O(k log k)

Each operation (insertion and removal) in the priority queue takes O(log k), and we perform k operations.

### Space Complexity 💾
- **Best Case:** O(k)
- **Worst Case:** O(k)

The space complexity is O(k) due to the storage required for the priority queue to manage the workers.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/total-cost-to-hire-k-workers/description/)

---
{{< youtube 4hb3bZS1o1o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
