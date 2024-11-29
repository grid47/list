
+++
authors = ["grid47"]
title = "Leetcode 1040: Moving Stones Until Consecutive II"
date = "2024-07-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1040: Moving Stones Until Consecutive II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Two Pointers","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "4Xhq2NDbA-I"
youtube_upload_date="2020-01-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/4Xhq2NDbA-I/maxresdefault.webp"
comments = true
+++



---
You are given a list of stones placed at different positions along the X-axis. A stone is considered an endpoint if it has the smallest or largest position. In one move, you can pick an endpoint stone and move it to any unoccupied position. The game ends when no more moves are possible, which occurs when the stones are in three consecutive positions. The goal is to find the minimum and maximum number of moves that can be made to achieve this configuration.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array 'stones' where each element represents the position of a stone on the X-axis. The values are unique.
- **Example:** `Input: stones = [8, 3, 15]`
- **Constraints:**
	- 3 <= stones.length <= 10^4
	- 1 <= stones[i] <= 10^9
	- All stone positions are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array with two integers. The first integer is the minimum number of moves to make the stones consecutive, and the second integer is the maximum number of moves.
- **Example:** `Output: [2, 3]`
- **Constraints:**
	- The output array should contain exactly two integers, representing the minimum and maximum possible moves.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the minimum and maximum number of moves needed to make the stones consecutive.

- 1. Sort the stone positions in ascending order.
- 2. Find the largest gap between consecutive stones, which helps in determining the maximum number of moves.
- 3. Calculate the number of stones that need to be moved by checking the gaps in the sorted array.
{{< dots >}}
### Problem Assumptions ✅
- The stones are initially placed in unique positions along the X-axis.
- The goal is to achieve three consecutive positions for all the stones.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: stones = [8, 3, 15]`  \
  **Explanation:** We can move stone at position 3 to 6, which results in a configuration of [6, 8, 15], completing the game in 2 moves. The maximum moves would involve moving stones in a way that stretches the positions out before finally bringing them together.

- **Input:** `Input: stones = [12, 10, 6, 4, 15]`  \
  **Explanation:** We can move stone at position 4 to 7, and stone at position 15 to 13, for a total of 3 moves to make the stones consecutive. For the maximum number of moves, we would take a more staggered approach before finally making the stones consecutive.

{{< dots >}}
## Approach 🚀
The solution involves calculating both the minimum and maximum number of moves needed to make the stones consecutive. The approach uses sorting and gap calculation to determine how many moves are needed for each stone.

### Initial Thoughts 💭
- The problem requires determining the smallest and largest gaps between stones after sorting them, which helps in deciding the optimal moves.
- We can use sorting to simplify the problem. Once sorted, calculating gaps between consecutive stones will reveal how many moves are required to bring all stones together.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least three stones, so no need to handle empty inputs.
- The algorithm should handle large inputs efficiently, with up to 10^4 stones and positions as large as 10^9.
- Ensure that the solution handles cases where the positions are already close to each other, requiring minimal or no moves.
- Make sure to avoid illegal moves, such as moving a stone to a position already occupied by another stone.
{{< dots >}}
## Code 💻
```cpp
vector<int> numMovesStonesII(vector<int>& pos) {
    sort(pos.begin(), pos.end());
    
    int low = INT_MAX;
    int j = 0, n = pos.size();
    for(int i = 0; i < n; i++) {
        while(pos[i] - pos[j] + 1 > n) j++;
        
        int cnt = i - j + 1;
        
        if(cnt == n - 1 && pos[i] - pos[j] + 1 == n - 1)
            low = min(low, 2);
        else low = min(low, n - cnt);
    }
    return vector<int>{low, max(pos[n - 1] - pos[1] + 1 - (n - 1), pos[n - 2] - pos[0] + 1 - (n - 1))};
}
```

This code solves the problem of finding the minimum and maximum number of moves required to align stones in a specific order within a given range. The input 'pos' is a vector of stone positions, and the code uses sorting and a sliding window approach to calculate the results.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> numMovesStonesII(vector<int>& pos) {
	```
	Define the function 'numMovesStonesII' that calculates the minimum and maximum number of moves required to move stones to a valid configuration.

2. **Sorting**
	```cpp
	    sort(pos.begin(), pos.end());
	```
	Sort the positions of the stones to make sure they are in increasing order, which is necessary for the sliding window approach.

3. **Initialization**
	```cpp
	    int low = INT_MAX;
	```
	Initialize 'low' to store the minimum number of moves, starting with the highest possible value.

4. **Variable Initialization**
	```cpp
	    int j = 0, n = pos.size();
	```
	Initialize 'j' (the start of the sliding window) and 'n' (the total number of stones).

5. **Outer Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Start a loop to iterate over each stone position, checking possible ranges of positions.

6. **Sliding Window**
	```cpp
	        while(pos[i] - pos[j] + 1 > n) j++;
	```
	Adjust the sliding window by moving the start index 'j' to ensure the number of stones within the window does not exceed the total number of stones.

7. **Count Stones in Window**
	```cpp
	        int cnt = i - j + 1;
	```
	Calculate the number of stones within the current sliding window.

8. **Condition Check for Minimum Moves**
	```cpp
	        if(cnt == n - 1 && pos[i] - pos[j] + 1 == n - 1)
	```
	Check if the number of stones within the window is one less than the total number of stones and if the distance between the first and last stone in the window is also 'n - 1'.

9. **Update Minimum Moves**
	```cpp
	            low = min(low, 2);
	```
	If the condition is met, set the minimum number of moves to 2, since only two moves are required to align the stones.

10. **Update Minimum Moves**
	```cpp
	        else low = min(low, n - cnt);
	```
	If the condition is not met, set the minimum moves to 'n - cnt', where 'cnt' is the number of stones in the window.

11. **Return Statement**
	```cpp
	    return vector<int>{low, max(pos[n - 1] - pos[1] + 1 - (n - 1), pos[n - 2] - pos[0] + 1 - (n - 1))};
	```
	Return a vector containing the minimum and maximum moves, where the maximum is calculated based on the largest gap between consecutive stones.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step, which is O(n log n), where n is the number of stones.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required to store the stone positions.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/moving-stones-until-consecutive-ii/description/)

---
{{< youtube 4Xhq2NDbA-I >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
