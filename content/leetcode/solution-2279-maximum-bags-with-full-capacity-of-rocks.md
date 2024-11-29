
+++
authors = ["grid47"]
title = "Leetcode 2279: Maximum Bags With Full Capacity of Rocks"
date = "2024-03-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2279: Maximum Bags With Full Capacity of Rocks in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "8s25uCT7vhY"
youtube_upload_date="2022-05-22"
youtube_thumbnail="https://i.ytimg.com/vi_webp/8s25uCT7vhY/maxresdefault.webp"
comments = true
+++



---
You have `n` bags, each capable of holding a certain number of rocks. You are given two arrays: `capacity` where `capacity[i]` is the maximum number of rocks that bag `i` can hold, and `rocks` where `rocks[i]` is the current number of rocks in bag `i`. You also have `additionalRocks` which represents the number of rocks you can distribute into the bags. Your goal is to determine the maximum number of bags that can be filled to their capacity after placing the additional rocks in any of the bags.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two arrays `capacity` and `rocks`, where each represents the capacity and current number of rocks in each bag, respectively. You are also given an integer `additionalRocks` that represents the number of rocks you can place in the bags.
- **Example:** `Input: capacity = [5, 7, 8, 3], rocks = [3, 2, 5, 2], additionalRocks = 4`
- **Constraints:**
	- n == capacity.length == rocks.length
	- 1 <= n <= 5 * 10^4
	- 1 <= capacity[i] <= 10^9
	- 0 <= rocks[i] <= capacity[i]
	- 1 <= additionalRocks <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of bags that can be filled to their full capacity after distributing the additional rocks.
- **Example:** `Output: 3`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to maximize the number of bags that can be filled to their full capacity by strategically distributing the additional rocks.

- Calculate the number of additional rocks needed to fill each bag to its capacity.
- Store the differences between the `capacity[i]` and `rocks[i]` in a sorted order to prioritize filling bags that require fewer rocks.
- Distribute the additional rocks starting from the bag that needs the least amount of rocks.
- Count how many bags can be filled completely with the available additional rocks.
{{< dots >}}
### Problem Assumptions ✅
- You can place the additional rocks in any of the bags in any order.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: capacity = [5, 7, 8, 3], rocks = [3, 2, 5, 2], additionalRocks = 4`  \
  **Explanation:** In this case, the number of rocks required to fill each bag are [2, 5, 3, 1]. We can place 2 rocks in bag 0, 1 rock in bag 3, and 1 rock in bag 1. This allows us to fill 3 bags to their full capacity. The output is 3.

- **Input:** `Input: capacity = [10, 5, 3], rocks = [4, 2, 1], additionalRocks = 6`  \
  **Explanation:** Here, the required rocks to fill each bag are [6, 3, 2]. We can place 3 rocks in bag 1, and 3 rocks in bag 2, filling 2 bags. The output is 2.

{{< dots >}}
## Approach 🚀
The strategy involves calculating the additional rocks needed for each bag and then sorting these requirements to fill as many bags as possible with the available rocks.

### Initial Thoughts 💭
- The problem is essentially about distributing resources (additional rocks) optimally across different bags.
- The fewer the number of additional rocks needed to fill a bag, the higher the likelihood that bag will be filled.
- The problem can be solved efficiently using a greedy approach, where we prioritize bags that require fewer rocks.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs as n is guaranteed to be at least 1.
- The solution must handle arrays of size up to 50,000 and values of capacity and additionalRocks up to 1 billion efficiently.
- If additionalRocks is greater than or equal to the total sum of missing rocks across all bags, then all bags can be filled.
- The solution should run in O(n log n) time due to the sorting step.
{{< dots >}}
## Code 💻
```cpp
int maximumBags(vector<int>& cap, vector<int>& rock, int cnt) {
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int n = rock.size();
    
    for(int i = 0; i < n; i++)
        pq.push(cap[i] - rock[i]);
    
    int res = 0;
    
    while(!pq.empty() && cnt >= pq.top()) {
        res++;
        cnt -= pq.top();
        pq.pop();
    }
    return res;
}
```

This function computes the maximum number of bags that can be filled given the capacity of each bag and the amount of rocks already in each bag. It uses a priority queue to prioritize filling bags with the least remaining space until the available capacity (cnt) is depleted.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int maximumBags(vector<int>& cap, vector<int>& rock, int cnt) {
	```
	The function header for `maximumBags`, which takes the capacity (`cap`) and rock (`rock`) counts for each bag, as well as the available capacity (`cnt`). It returns an integer representing the maximum number of bags that can be filled.

2. **Queue Initialization**
	```cpp
	    priority_queue<int, vector<int>, greater<int>> pq;
	```
	This initializes a priority queue `pq` that will store the available space in each bag (difference between capacity and rocks), ordered in increasing order. This allows us to process the bags with the smallest remaining space first.

3. **Size Calculation**
	```cpp
	    int n = rock.size();
	```
	This stores the number of bags (the size of the `rock` vector) in the variable `n`. We assume both `cap` and `rock` vectors are of the same size.

4. **Queue Population**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	This loop iterates over each bag to calculate the available space in each bag (capacity - rocks). This difference is pushed into the priority queue.

5. **Queue Population (cont.)**
	```cpp
	        pq.push(cap[i] - rock[i]);
	```
	For each bag, the difference between the capacity and the rocks already in the bag is computed and pushed into the priority queue `pq`.

6. **Result Initialization**
	```cpp
	    int res = 0;
	```
	The variable `res` is initialized to zero. This will store the total number of bags that can be filled.

7. **Filling Bags**
	```cpp
	    while(!pq.empty() && cnt >= pq.top()) {
	```
	This `while` loop runs as long as the priority queue `pq` is not empty and there is enough capacity (`cnt`) to fill the current bag with the least remaining space.

8. **Result Update**
	```cpp
	        res++;
	```
	Each time a bag is filled, the result counter `res` is incremented.

9. **Capacity Deduction**
	```cpp
	        cnt -= pq.top();
	```
	The available capacity `cnt` is reduced by the amount required to fill the current bag (the value at the top of the priority queue).

10. **Queue Pop**
	```cpp
	        pq.pop();
	```
	The current bag is removed from the priority queue after it is processed.

11. **Return Statement**
	```cpp
	    return res;
	```
	The function returns the total number of bags that were filled (`res`).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is O(n log n) due to the sorting of the required rock differences.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we store the differences between capacities and rocks for each bag.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/description/)

---
{{< youtube 8s25uCT7vhY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
