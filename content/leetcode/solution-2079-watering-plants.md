
+++
authors = ["grid47"]
title = "Leetcode 2079: Watering Plants"
date = "2024-04-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2079: Watering Plants in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "6GNga8RRNSQ"
youtube_upload_date="2021-11-21"
youtube_thumbnail="https://i.ytimg.com/vi/6GNga8RRNSQ/maxresdefault.jpg"
comments = true
+++



---
You need to water `n` plants arranged in a row. Starting at the river, you water the plants in order, refilling your watering can when it runs out. The goal is to determine the total number of steps to water all the plants.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `plants` where each element represents the amount of water a plant needs, and an integer `capacity` representing the watering can's capacity.
- **Example:** `[3, 3, 2, 4], capacity = 6`
- **Constraints:**
	- 1 <= n <= 1000
	- 1 <= plants[i] <= 10^6
	- max(plants[i]) <= capacity <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the total number of steps required to water all the plants.
- **Example:** `For input [3, 3, 2, 4] and capacity 6, the output is 20.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Compute the total steps needed to water all the plants.

- Start at the river with a full watering can.
- For each plant, check if there is enough water in the can. If not, return to the river to refill.
- Water the plant and subtract the required water from the can.
- Keep track of the total steps taken, including both watering steps and refill steps.
{{< dots >}}
### Problem Assumptions ✅
- You will always have enough capacity to water the first plant.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1`  \
  **Explanation:** In this case, you water the plants, and whenever the watering can runs out, you return to the river to refill, taking the required steps each time.

- **Input:** `Example 2`  \
  **Explanation:** Here, the plants require a total of 16 steps to water all of them, including the refills.

{{< dots >}}
## Approach 🚀
The solution involves simulating the watering process, keeping track of the watering can's water level and the total steps taken.

### Initial Thoughts 💭
- A greedy approach works here where you water each plant and refill when necessary.
- The solution should iterate over the plants and simulate the watering process step-by-step.
{{< dots >}}
### Edge Cases 🌐
- The array will never be empty.
- The solution must work for up to 1000 plants efficiently.
- The plants array might contain very large numbers that require multiple refills.
- Ensure the solution handles the edge case where all plants require more water than the capacity of the watering can.
{{< dots >}}
## Code 💻
```cpp
int wateringPlants(vector<int>& num, int cap) {
    int n = num.size();
    int rel = cap;
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(num[i] > rel) {
            rel = cap;
            res += 2*i;
        } 
        rel -= num[i];            
    }
    return res + n;
}
```

This function simulates the process of watering plants by considering the total number of steps taken to go back to the water source and re-fill the water can when needed.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int wateringPlants(vector<int>& num, int cap) {
	```
	This is the function declaration for `wateringPlants`, which accepts a vector `num` containing the water requirements of the plants and an integer `cap` representing the water can's capacity. It returns the total number of steps to water all plants.

2. **Variable Initialization**
	```cpp
	    int n = num.size();
	```
	This line initializes `n` to the size of the `num` vector, which represents the total number of plants.

3. **Variable Initialization**
	```cpp
	    int rel = cap;
	```
	This line initializes the variable `rel` to store the remaining water in the can, initially set to the full capacity `cap`.

4. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	This line initializes a counter `res` to zero, which will track the total number of steps taken to water all the plants.

5. **For Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	This `for` loop iterates through each plant in the `num` vector, where `i` is the index of the current plant.

6. **Conditional Check**
	```cpp
	        if(num[i] > rel) {
	```
	This condition checks if the remaining water `rel` is insufficient to water the current plant (`num[i]`). If true, the water can needs to be refilled.

7. **Water Can Refill**
	```cpp
	            rel = cap;
	```
	This line simulates refilling the water can by resetting `rel` to the full capacity `cap`.

8. **Step Calculation**
	```cpp
	            res += 2*i;
	```
	This adds `2 * i` steps to the total count `res`, since it requires `i` steps to walk to the water source and `i` steps to return to the current plant after refilling.

9. **Water Deduction**
	```cpp
	        rel -= num[i];            
	```
	This line decreases the remaining water in the can by the amount needed to water the current plant.

10. **Final Step Calculation**
	```cpp
	    return res + n;
	```
	This line returns the total number of steps taken, including one step for each plant to water it.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear in relation to the number of plants, since each plant is processed once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, as we only need a few variables to track the water level and steps.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/watering-plants/description/)

---
{{< youtube 6GNga8RRNSQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
