
+++
authors = ["grid47"]
title = "Leetcode 1642: Furthest Building You Can Reach"
date = "2024-05-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1642: Furthest Building You Can Reach in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "zyTeznvXCtg"
youtube_upload_date="2024-02-17"
youtube_thumbnail="https://i.ytimg.com/vi/zyTeznvXCtg/maxresdefault.jpg"
comments = true
+++



---
You are given an array `heights` representing the heights of buildings, along with a certain number of bricks and ladders. Your task is to determine the furthest building you can reach by optimally using bricks and ladders.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array `heights` of length `n`, where each element represents the height of a building. You are also given two integers: `bricks` (the number of bricks available) and `ladders` (the number of ladders available).
- **Example:** `heights = [7, 12, 6, 9, 5, 17, 21, 4, 18], bricks = 15, ladders = 3`
- **Constraints:**
	- 1 <= heights.length <= 10^5
	- 1 <= heights[i] <= 10^6
	- 0 <= bricks <= 10^9
	- 0 <= ladders <= heights.length

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the furthest building index (0-indexed) you can reach using the given ladders and bricks optimally.
- **Example:** `4`
- **Constraints:**
	- Return -1 if you cannot move beyond the first building.

{{< dots >}}
### Core Logic 🔍
**Goal:** To move from building to building, using bricks and ladders optimally for the height differences.

- 1. Calculate the height difference between each consecutive building.
- 2. Use ladders for the largest height differences first.
- 3. Use bricks for the remaining height differences.
- 4. Stop when you run out of bricks or ladders, and return the furthest building index.
{{< dots >}}
### Problem Assumptions ✅
- Assume the height array is non-empty.
- Assume the number of ladders is non-negative and within the bounds of the array length.
{{< dots >}}
## Examples 🧩
- **Input:** `heights = [5, 3, 8, 7, 10, 15, 13], bricks = 8, ladders = 2`  \
  **Explanation:** You can move from building 0 to building 4 by optimally using bricks for the height difference between buildings 1 and 2 and using a ladder for the difference between buildings 3 and 4.

{{< dots >}}
## Approach 🚀
We need to use ladders first for the largest height differences, and use bricks for the smaller ones, to maximize the furthest building we can reach.

### Initial Thoughts 💭
- Ladders should be used for the largest height differences to save bricks.
- Bricks should be used for smaller height differences when ladders are exhausted.
- Use a priority queue to manage the height differences and decide where to use bricks or ladders.
{{< dots >}}
### Edge Cases 🌐
- The input heights array is empty.
- Ensure the solution handles large arrays and large numbers of bricks and ladders efficiently.
- When there are no height differences, no bricks or ladders are needed.
- Ensure that the solution works within the provided constraints.
{{< dots >}}
## Code 💻
```cpp

int furthestBuilding(vector<int>& h, int bri, int lad) {
    int n = h.size();
    vector<int> bc(n - 1, 0);
    
    for(int i = 0; i < n - 1; i++) {
        bc[i] = h[i + 1] - h[i] < 0 ? 0: h[i + 1] - h[i];
        // cout << bc[i] << " ";
    }
 
    // cout << "\n";
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int i = 0, sum = 0;
    for(; i < n - 1; i++) {

        if(bc[i] == 0) continue;
        
        if(pq.size() < lad) {
            pq.push(bc[i]);
        } else {
            pq.push(bc[i]);
            if(sum + pq.top() <= bri)
            sum += pq.top();
            else return i;
            pq.pop();
        }
        
    }
    // cout << sum << " " << bri << " " << i;
    return n - 1;
    // Use ladders first
    // when ladders are over
    // check are them could be replaced with bricks
    // if yes, continue to assigning released ladder
    // else return where it had overflown
}
```

This function calculates the furthest building that can be reached using a combination of bricks and ladders. The function first calculates the difference between heights and stores them in a priority queue. It then checks if the current height difference can be traversed with the available ladders and bricks.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int furthestBuilding(vector<int>& h, int bri, int lad) {
	```
	The function starts by defining the function signature and initializing the variables for the number of buildings (h), bricks (bri), and ladders (lad).

2. **Variable Initialization**
	```cpp
	    int n = h.size();
	```
	The size of the building heights array is stored in the variable 'n' to be used for iteration.

3. **Array Initialization**
	```cpp
	    vector<int> bc(n - 1, 0);
	```
	An array 'bc' is initialized to store the differences in heights between consecutive buildings.

4. **Loop**
	```cpp
	    for(int i = 0; i < n - 1; i++) {
	```
	A loop starts from the first building to calculate the height difference between each consecutive building.

5. **Height Difference Calculation**
	```cpp
	        bc[i] = h[i + 1] - h[i] < 0 ? 0: h[i + 1] - h[i];
	```
	The height difference is calculated and stored in the 'bc' array. If the difference is negative, it is set to 0.

6. **Priority Queue Initialization**
	```cpp
	    priority_queue<int, vector<int>, greater<int>> pq;
	```
	A priority queue 'pq' is initialized to manage the smallest height differences when traversing buildings.

7. **Variable Initialization**
	```cpp
	    int i = 0, sum = 0;
	```
	Two variables 'i' (for the current building index) and 'sum' (to track the total bricks used) are initialized.

8. **Loop**
	```cpp
	    for(; i < n - 1; i++) {
	```
	A loop starts to iterate over each building to check if the height difference can be covered with the available resources.

9. **Check if Height Difference is Zero**
	```cpp
	        if(bc[i] == 0) continue;
	```
	If the height difference between buildings is zero, no resources are needed, and the loop continues.

10. **Check Ladder Availability**
	```cpp
	        if(pq.size() < lad) {
	```
	If there are still ladders available, push the current height difference into the priority queue.

11. **Push to Priority Queue**
	```cpp
	            pq.push(bc[i]);
	```
	Push the current building height difference into the priority queue.

12. **Else Block**
	```cpp
	        } else {
	```
	If no ladders are available, the program uses bricks to cover the building gap.

13. **Push to Priority Queue Again**
	```cpp
	            pq.push(bc[i]);
	```
	Push the current building height difference into the priority queue.

14. **Check if Bricks are Sufficient**
	```cpp
	            if(sum + pq.top() <= bri)
	```
	Check if the total sum of bricks used so far and the top of the priority queue (smallest height difference) is less than or equal to the available bricks.

15. **Update Brick Usage**
	```cpp
	            sum += pq.top();
	```
	If bricks are sufficient, add the current smallest height difference to the sum of bricks used.

16. **Return if Bricks are Insufficient**
	```cpp
	            else return i;
	```
	If the current height difference cannot be covered with the available bricks, return the current building index.

17. **Pop from Priority Queue**
	```cpp
	            pq.pop();
	```
	Remove the smallest height difference from the priority queue.

18. **Return Result**
	```cpp
	    return n - 1;
	```
	Return the index of the furthest building that can be reached using the available ladders and bricks.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The worst case occurs when we need to process all the height differences and manage the priority queue.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is primarily determined by the space used for the priority queue.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/furthest-building-you-can-reach/description/)

---
{{< youtube zyTeznvXCtg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
