
+++
authors = ["grid47"]
title = "Leetcode 853: Car Fleet"
date = "2024-08-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 853: Car Fleet in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Sorting","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Pr6T-3yB9RM"
youtube_upload_date="2021-10-18"
youtube_thumbnail="https://i.ytimg.com/vi/Pr6T-3yB9RM/maxresdefault.jpg"
comments = true
+++



---
You are given several cars starting at different positions along a road. Each car has a specific speed and is trying to reach a target destination. A car cannot pass another car, but it can catch up and travel at the speed of the slower car. Cars that travel together form a fleet. Your task is to determine the number of car fleets that will reach the target.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given the target distance, an array of car positions, and an array of car speeds.
- **Example:** `Input: target = 15, position = [12, 5, 2, 9], speed = [3, 4, 2, 5]`
- **Constraints:**
	- n == position.length == speed.length
	- 1 <= n <= 10^5
	- 0 < target <= 10^6
	- 0 <= position[i] < target
	- All the values of position are unique.
	- 0 < speed[i] <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of car fleets that will arrive at the target.
- **Example:** `Output: 2`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find how many fleets will form by considering each car's starting position and speed, and determining if it will catch up to others.

- Step 1: Calculate the time it takes for each car to reach the target.
- Step 2: Sort the cars by their starting position in descending order.
- Step 3: Iterate through the sorted list of cars, comparing the time for each car to reach the target with the previous car's time.
- Step 4: If a car reaches the target faster than the previous car, it forms a new fleet. Otherwise, it joins the previous fleet.
{{< dots >}}
### Problem Assumptions ✅
- Cars with the same position cannot exist.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: target = 10, position = [7, 3, 0, 5], speed = [1, 2, 3, 4]`  \
  **Explanation:** In this example, the car starting at position 0 (speed 3) reaches the target before the car starting at position 3 (speed 2), but after the car starting at position 7 (speed 1). The car starting at position 5 (speed 4) forms a fleet with the car starting at position 3 and moves at the same speed. Therefore, there are 2 fleets.

- **Input:** `Input: target = 100, position = [0, 10, 20, 30], speed = [10, 5, 2, 1]`  \
  **Explanation:** In this example, the car starting at position 0 (speed 10) forms a fleet by itself. The cars starting at positions 10, 20, and 30 form a single fleet because each catches up to the previous one.

{{< dots >}}
## Approach 🚀
We solve this problem by first sorting the cars based on their starting positions and then determining how many distinct fleets will reach the target.

### Initial Thoughts 💭
- Cars that are farther ahead will likely have a smaller time to the target, so they may form a new fleet if they travel at a faster speed.
- By calculating the time for each car to reach the target, we can decide if the car forms a new fleet or joins an existing one.
{{< dots >}}
### Edge Cases 🌐
- N/A: The problem guarantees at least one car.
- The solution must handle up to 10^5 cars efficiently.
- If there is only one car, it will form one fleet.
- All positions are unique, and the number of cars will not exceed the specified limit.
{{< dots >}}
## Code 💻
```cpp
int carFleet(int target, vector<int>& pos, vector<int>& v) {
    map<int, double> t;
    for(int i = 0; i < pos.size(); i++) {
        t[-pos[i]] = (double) (target-pos[i]) / v[i];
    }
    
    int fleet = 0;
    double cur = 0;
    
    for(auto it: t) {
        if(it.second > cur) fleet++, cur = it.second;
    }
    return fleet;
}
```

This function calculates the number of car fleets reaching a target. The fleet is determined based on the positions and speeds of the cars.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Initialization**
	```cpp
	int carFleet(int target, vector<int>& pos, vector<int>& v) {
	```
	Define the main function, taking target position, car positions, and car speeds as input.

2. **Data Structure**
	```cpp
	    map<int, double> t;
	```
	Initialize a map to store the time taken for each car to reach the target, using the negative of the position as the key.

3. **Loop**
	```cpp
	    for(int i = 0; i < pos.size(); i++) {
	```
	Start a loop to calculate the time for each car to reach the target.

4. **Calculation**
	```cpp
	        t[-pos[i]] = (double) (target-pos[i]) / v[i];
	```
	For each car, calculate the time it will take to reach the target by using the formula: time = (target - position) / speed.

5. **Variable Initialization**
	```cpp
	    int fleet = 0;
	```
	Initialize the fleet counter to 0.

6. **Variable Initialization**
	```cpp
	    double cur = 0;
	```
	Initialize the variable 'cur' to track the current maximum time seen among the fleets.

7. **Loop**
	```cpp
	    for(auto it: t) {
	```
	Start a loop to process each car's time to reach the target in descending order of positions.

8. **Fleet Calculation**
	```cpp
	        if(it.second > cur) fleet++, cur = it.second;
	```
	If the current car takes more time than the previous one, it forms a new fleet. Update the current time.

9. **Return**
	```cpp
	    return fleet;
	```
	Return the total number of fleets.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting of the positions of the cars, which takes O(n log n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the times of the cars.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/car-fleet/description/)

---
{{< youtube Pr6T-3yB9RM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
