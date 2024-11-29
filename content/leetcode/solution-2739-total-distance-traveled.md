
+++
authors = ["grid47"]
title = "Leetcode 2739: Total Distance Traveled"
date = "2024-02-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2739: Total Distance Traveled in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "h7FESSswnR8"
youtube_upload_date="2023-06-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/h7FESSswnR8/maxresdefault.webp"
comments = true
+++



---
A truck has two fuel tanks, one main tank and one additional tank. The truck's mileage is 10 km per liter, and fuel from the additional tank can be injected into the main tank after every 5 liters of fuel consumed. Your task is to calculate the maximum distance the truck can travel, considering both the main tank and the additional tank.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integers: `mainTank` and `additionalTank`, representing the fuel available in the main tank and the additional tank in liters.
- **Example:** `mainTank = 8, additionalTank = 12`
- **Constraints:**
	- 1 <= mainTank <= 100
	- 1 <= additionalTank <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum distance the truck can travel.
- **Example:** `Output: 80`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the total distance the truck can travel by consuming fuel from the main tank and transferring fuel from the additional tank when necessary.

- While there is fuel in the main tank, calculate the distance that can be traveled with the current fuel.
- For every 5 liters consumed, transfer 1 liter from the additional tank to the main tank if possible.
- Repeat until the main tank is empty.
{{< dots >}}
### Problem Assumptions ✅
- Fuel injection only happens after 5 liters are consumed from the main tank.
- The truck’s mileage is always 10 km per liter of fuel.
{{< dots >}}
## Examples 🧩
- **Input:** `mainTank = 8, additionalTank = 12`  \
  **Explanation:** Initially, the truck starts with 8 liters in the main tank, allowing it to travel 80 km. After consuming 5 liters, the additional tank injects 1 liter into the main tank. This continues until the main tank is empty.

- **Input:** `mainTank = 3, additionalTank = 6`  \
  **Explanation:** The truck starts with 3 liters in the main tank, which allows it to travel 30 km. No fuel is injected from the additional tank because fuel transfer only happens after consuming 5 liters.

{{< dots >}}
## Approach 🚀
The approach is to simulate the process of consuming fuel from the main tank and transferring fuel from the additional tank at the appropriate intervals.

### Initial Thoughts 💭
- The additional tank only injects fuel after every 5 liters consumed from the main tank.
- The total distance is calculated by considering the fuel available in the main tank and the injections from the additional tank.
- The process is a repetitive calculation until the main tank is empty.
{{< dots >}}
### Edge Cases 🌐
- Both tanks are empty at the start (not valid in this problem).
- Maximum values for both tanks (100 liters each).
- If the main tank has less than 5 liters initially, no injection occurs.
- Ensure fuel injection happens only after 5 liters are consumed.
{{< dots >}}
## Code 💻
```cpp
int distanceTraveled(int mt, int at) {        
    int net = 0;
    
    while(mt > 0) {
        int red = min(5, mt);
        mt -= red;
        net += red * 10;
        if(red == 5 && at > 0) {
            mt += 1;
            at--;
        }
    }
    
    return net;
}
```

This function calculates the total distance traveled by a vehicle, considering a limit of 5 units per trip, a time buffer, and a penalty factor.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int distanceTraveled(int mt, int at) {
	```
	The function `distanceTraveled` is defined with parameters `mt` (the remaining distance to travel) and `at` (the available time buffer). It returns an integer representing the total distance traveled.

2. **Variable Initialization**
	```cpp
	    int net = 0;
	```
	The variable `net` is initialized to zero to keep track of the total distance traveled.

3. **Loop - Condition**
	```cpp
	    while(mt > 0) {
	```
	A `while` loop starts, which will continue as long as there is remaining distance (`mt > 0`).

4. **Variable Calculation**
	```cpp
	        int red = min(5, mt);
	```
	The variable `red` is assigned the minimum value between 5 and the remaining distance `mt`, representing the distance that can be covered in the current iteration.

5. **Variable Update**
	```cpp
	        mt -= red;
	```
	The remaining distance `mt` is decreased by the value of `red`.

6. **Distance Calculation**
	```cpp
	        net += red * 10;
	```
	The total distance traveled (`net`) is updated by adding the distance covered in this iteration, multiplied by 10 (penalty factor).

7. **Conditional Check**
	```cpp
	        if(red == 5 && at > 0) {
	```
	A condition checks if exactly 5 units were covered (`red == 5`) and if there is any available time buffer (`at > 0`).

8. **Variable Update**
	```cpp
	            mt += 1;
	```
	If the condition is true, 1 unit is added back to `mt` (this represents a penalty for the time buffer).

9. **Variable Update**
	```cpp
	            at--;
	```
	The available time buffer `at` is decremented by 1.

10. **Return Statement**
	```cpp
	    return net;
	```
	The function returns the total distance traveled (`net`), which has been accumulated during the `while` loop.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(n) where n is the amount of fuel in the main tank.
- **Worst Case:** O(n) since the process continues until the main tank is empty.

The time complexity is linear as we process each fuel consumption step.

### Space Complexity 💾
- **Best Case:** O(1) since no extra space is needed.
- **Worst Case:** O(1) as we only use a constant amount of space.

The space complexity is constant because we only need variables to track the fuel amounts.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/total-distance-traveled/description/)

---
{{< youtube h7FESSswnR8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
