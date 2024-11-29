
+++
authors = ["grid47"]
title = "Leetcode 2593: Find Score of an Array After Marking All Elements"
date = "2024-02-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2593: Find Score of an Array After Marking All Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting","Heap (Priority Queue)","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "6KKgxkXPtsQ"
youtube_upload_date="2023-03-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/6KKgxkXPtsQ/maxresdefault.webp"
comments = true
+++



---
You are given an array `nums` consisting of positive integers. Starting with a `score = 0`, repeatedly select the smallest unmarked integer, add its value to the score, and mark it along with its adjacent elements (if any). Continue this until all elements are marked, then return the final score.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer array `nums` representing the array of positive integers.
- **Example:** `For example, `nums = [3, 2, 5, 4, 1]`.`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a single integer representing the final score achieved after applying the algorithm.
- **Example:** `For `nums = [3, 2, 5, 4, 1]`, the output is `6`.`
- **Constraints:**
	- The output is an integer representing the final score.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to choose the smallest unmarked element, add its value to the score, and mark it along with its adjacent elements until all elements are marked.

- 1. Initialize a score variable to 0.
- 2. Use a priority queue to efficiently find the smallest unmarked element.
- 3. Add the value of the chosen element to the score.
- 4. Mark the chosen element and its adjacent elements (if they exist).
- 5. Repeat the process until all elements are marked.
{{< dots >}}
### Problem Assumptions ✅
- The input array will always contain at least one integer, and each element will be between 1 and 10^6.
{{< dots >}}
## Examples 🧩
- **Input:** `For `nums = [3, 2, 5, 4, 1]``  \
  **Explanation:** By following the algorithm, we first select `1`, then `2`, and finally `4`. The final score is `1 + 2 + 3 = 6`.

{{< dots >}}
## Approach 🚀
The approach involves selecting the smallest unmarked element using a priority queue and applying the algorithm to maximize the score.

### Initial Thoughts 💭
- We can use a priority queue (min-heap) to efficiently find the smallest unmarked element.
- The greedy approach ensures we select the smallest element at each step to maximize the score.
{{< dots >}}
### Edge Cases 🌐
- The input array will always contain at least one element, so there will be no empty inputs.
- The solution should handle large inputs efficiently with a time complexity of O(n log n).
- If all elements in `nums` are the same, the algorithm should still function correctly.
- The input array will always meet the specified constraints.
{{< dots >}}
## Code 💻
```cpp
long long findScore(vector<int>& nums) {
    long long score = 0;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    int n = nums.size();
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++)
        pq.push({nums[i], i});
    
    while(!pq.empty()) {
        while(!pq.empty() && mp.count(pq.top()[1])) pq.pop();
        if(!pq.empty()) {
            score += pq.top()[0];
            mp[pq.top()[1]] = true;
            mp[pq.top()[1] + 1] = true;
            mp[pq.top()[1] - 1] = true;                
            pq.pop();
        }
    }
    return score;
}
```

This function calculates the total score based on the values in the input vector 'nums', using a priority queue to manage the elements and their corresponding indices. The score is updated based on specific conditions involving adjacent elements.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	long long findScore(vector<int>& nums) {
	```
	This is the function definition where we declare 'findScore', which takes a vector of integers as input and returns a long long score.

2. **Variable Initialization**
	```cpp
	    long long score = 0;
	```
	We initialize the 'score' variable to 0, which will hold the total score.

3. **Priority Queue**
	```cpp
	    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	```
	We declare a priority queue 'pq' that will store vectors of integers, which will be sorted in increasing order based on the first element of the vectors.

4. **Size of Input**
	```cpp
	    int n = nums.size();
	```
	We store the size of the input vector 'nums' in the variable 'n'.

5. **Hash Map**
	```cpp
	    unordered_map<int, int> mp;
	```
	We declare an unordered map 'mp' to track which indices have already been processed.

6. **Loop Initialization**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	This is a loop that iterates through each element of the input vector 'nums'.

7. **Push to Priority Queue**
	```cpp
	        pq.push({nums[i], i});
	```
	We push a vector containing the current element 'nums[i]' and its index 'i' into the priority queue.

8. **While Loop**
	```cpp
	    while(!pq.empty()) {
	```
	This is a while loop that continues until the priority queue is empty.

9. **Check Processed Indices**
	```cpp
	        while(!pq.empty() && mp.count(pq.top()[1])) pq.pop();
	```
	We check if the top element of the priority queue has already been processed. If it has, we pop it from the queue.

10. **If Not Empty**
	```cpp
	        if(!pq.empty()) {
	```
	We proceed if the priority queue is not empty after cleaning out the processed elements.

11. **Add to Score**
	```cpp
	            score += pq.top()[0];
	```
	We add the value of the top element in the priority queue (which is the first element of the vector) to the score.

12. **Mark Current Index**
	```cpp
	            mp[pq.top()[1]] = true;
	```
	We mark the current index as processed in the 'mp' map.

13. **Mark Adjacent Indices**
	```cpp
	            mp[pq.top()[1] + 1] = true;
	```
	We mark the next index as processed.

14. **Mark Adjacent Indices**
	```cpp
	            mp[pq.top()[1] - 1] = true;                
	```
	We mark the previous index as processed.

15. **Pop from Priority Queue**
	```cpp
	            pq.pop();
	```
	We remove the top element from the priority queue after processing it.

16. **Return Score**
	```cpp
	    return score;
	```
	We return the calculated score after processing all elements.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is O(n log n) due to the use of a priority queue for selecting the smallest unmarked element.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we need extra space for the priority queue and marking elements.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/)

---
{{< youtube 6KKgxkXPtsQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
