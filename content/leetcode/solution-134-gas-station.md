
+++
authors = ["grid47"]
title = "Leetcode 134: Gas Station"
date = "2024-10-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 134: Gas Station in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/134.webp"
youtube = "xmJZSYSvgfE"
youtube_upload_date="2020-09-24"
youtube_thumbnail="https://i.ytimg.com/vi/xmJZSYSvgfE/hqdefault.jpg?sqp=-oaymwEmCOADEOgC8quKqQMa8AEB-AHUBoAC4AOKAgwIABABGEsgWShlMA8=&rs=AOn4CLCL_g_r-FNtZHH0a4JeTSLZuNdQig"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/134.webp" 
    alt="A calm sequence of gas stations, each glowing softly, with the optimal starting point gently illuminated."
    caption="Solution to LeetCode 134: Gas Station Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given 'n' gas stations along a circular route, where each station has a certain amount of gas and a cost associated with traveling to the next station. The goal is to find the starting station from where you can complete a full circle. If no such starting station exists, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two integer arrays, gas and cost, where gas[i] represents the gas available at the ith station and cost[i] represents the cost of gas to travel from the ith station to the next.
- **Example:** `gas = [1,2,3,4,5], cost = [3,4,5,1,2]`
- **Constraints:**
	- n == gas.length == cost.length
	- 1 <= n <= 10^5
	- 0 <= gas[i], cost[i] <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the index of the station where the journey can be completed successfully. If no such index exists, return -1.
- **Example:** `Output: 3`
- **Constraints:**
	- The output should be -1 if no valid starting station is found.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the starting station index where the gas in the car is enough to travel around the circuit.

- 1. First, check if the total gas is greater than or equal to the total cost. If not, return -1.
- 2. Traverse through the stations and simulate the journey. If the gas in the tank goes negative, reset the tank and set the next station as the potential starting station.
- 3. If you complete the journey, return the index of the starting station.
{{< dots >}}
### Problem Assumptions ✅
- It is guaranteed that if a solution exists, it will be unique.
{{< dots >}}
## Examples 🧩
- **Input:** `gas = [1,2,3,4,5], cost = [3,4,5,1,2]`  \
  **Explanation:** In this case, you start at station 3. Traveling from station 3, you will be able to make the full journey and return to station 3.

- **Input:** `gas = [2,3,4], cost = [3,4,3]`  \
  **Explanation:** In this case, there is no starting station from where the journey can be completed successfully.

{{< dots >}}
## Approach 🚀
The approach for solving the problem involves checking if the total gas is greater than or equal to the total cost and then simulating the journey to find the valid starting point.

### Initial Thoughts 💭
- We need to find if there exists a starting station from where the journey can be completed.
- First, we check if the total gas is enough to cover the total cost of the journey. If not, return -1.
{{< dots >}}
### Edge Cases 🌐
- If gas and cost are empty arrays, return -1.
- Handle large inputs efficiently within the constraints.
- Check for cases where gas[i] = 0 or cost[i] = 0.
- Ensure that the solution works for both small and large inputs efficiently.
{{< dots >}}
## Code 💻
```cpp
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int tank = 0;
    int net = 0;
    
    for(int i = 0; i < gas.size(); i++) {
        tank += gas[i];
        net += cost[i];
    }
    if (net > tank) return -1;
    
    tank = 0;
    int res = -1;
    
    for(int i = 0; i < gas.size(); i++) {
        tank += gas[i];
        tank -= cost[i];
        if(tank < 0) {
            tank = 0;
            res = i;
        }
    }
    return res + 1;
    
}
```

The code `canCompleteCircuit` determines whether a circular tour of a gas station can be completed, given the amount of gas available at each station and the cost of traveling to the next station.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	```
	The function definition for `canCompleteCircuit` takes two vectors, `gas` and `cost`, representing the gas available at each station and the cost to travel to the next station, respectively.

2. **Variable Initialization**
	```cpp
	    int tank = 0;
	```
	Initialize a variable `tank` to track the gas in the vehicle's tank as we progress through the stations.

3. **Variable Initialization**
	```cpp
	    int net = 0;
	```
	Initialize `net` to store the total difference between gas available and the cost of traveling to the next station.

4. **Loop Iteration**
	```cpp
	    
	```
	Start a loop to iterate through the gas stations.

5. **Loop Iteration**
	```cpp
	    for(int i = 0; i < gas.size(); i++) {
	```
	Iterate through each gas station from index 0 to the last index.

6. **Variable Manipulation**
	```cpp
	        tank += gas[i];
	```
	Add the gas available at the current station to `tank`.

7. **Variable Manipulation**
	```cpp
	        net += cost[i];
	```
	Add the cost to travel to the next station to `net`.

8. **Condition Check**
	```cpp
	    if (net > tank) return -1;
	```
	If the total gas is less than the total cost, return -1 indicating that completing the circuit is not possible.

9. **Variable Initialization**
	```cpp
	    tank = 0;
	```
	Reset `tank` to 0 for the second loop to evaluate the starting station.

10. **Variable Initialization**
	```cpp
	    int res = -1;
	```
	Initialize `res` as -1 to keep track of the station index where the journey can start.

11. **Loop Iteration**
	```cpp
	    for(int i = 0; i < gas.size(); i++) {
	```
	Start another loop to iterate over the stations again to find the valid starting station.

12. **Variable Manipulation**
	```cpp
	        tank += gas[i];
	```
	Add the gas from the current station to `tank`.

13. **Variable Manipulation**
	```cpp
	        tank -= cost[i];
	```
	Subtract the cost to travel to the next station from `tank`.

14. **Condition Check**
	```cpp
	        if(tank < 0) {
	```
	If the `tank` drops below 0, the current station is not a valid starting point.

15. **Variable Reset**
	```cpp
	            tank = 0;
	```
	Reset `tank` to 0 to start from the next station.

16. **Variable Update**
	```cpp
	            res = i;
	```
	Update `res` to the current station index as a potential starting point.

17. **Return Statement**
	```cpp
	    return res + 1;
	```
	Return the index of the valid starting station, adjusting for 1-based indexing.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) as we traverse the list of stations twice.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we are using only a few extra variables for calculations.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/gas-station/description/)

---
{{< youtube xmJZSYSvgfE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
