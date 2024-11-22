
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
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### 🛣️ **The Problem:**

You are given two lists:
- **gas[i]**: the amount of gas available at the i-th gas station.
- **cost[i]**: the amount of gas required to travel from the i-th gas station to the next one.

We need to figure out:
1. **Is it possible to complete a circular route starting from one of the stations?**
2. If it is possible, **which station should we start at?**

Your task is to determine the **index of the starting station** such that the car can travel around the entire circle of gas stations without running out of gas. If it's not possible, return `-1`.

---

### 🚗 **Let's Solve It Step by Step:**

#### Step 1: **Check the Feasibility of Completing the Circuit**

Before diving into finding the right starting station, we need to check if completing the circuit is even possible.

1️⃣ **Total Gas vs Total Cost**  
   First, we calculate the total gas available (`total_gas`) and the total cost to travel (`total_cost`). If at any point, the total gas is less than the total cost, it is impossible to complete the journey, and we should return `-1`.

Let’s calculate these sums:

```cpp
int total_gas = 0;
int total_cost = 0;

for (int i = 0; i < gas.size(); i++) {
    total_gas += gas[i];    // Total gas available at all stations
    total_cost += cost[i];  // Total cost to travel between all stations
}
```

- **If `total_gas < total_cost`**, it’s impossible to complete the journey. We can safely return `-1` at this point:
  
```cpp
if (total_gas < total_cost) return -1;
```

#### Step 2: **Start Simulating the Journey**

If completing the journey is possible, we need to figure out from **which station** we should start.

2️⃣ **Greedy Approach**  
   We’ll use a greedy approach to simulate the journey. The idea is to start from each station and see if we can complete the trip. If at any point we run out of gas, we reset our journey and start from the next station.

We’ll keep track of:
- The current fuel in the tank (`current_gas`).
- The total remaining fuel (`total_gas_so_far`).

For each station:
1. Add the gas available at the station to the current fuel.
2. Subtract the cost required to travel to the next station.
3. If at any point the `current_gas` becomes negative, reset the journey and consider the next station as the new potential starting point.

Here’s how we can simulate this:

```cpp
int current_gas = 0; // Tracks current fuel
int start_station = 0; // Candidate for the start station

for (int i = 0; i < gas.size(); i++) {
    current_gas += gas[i];    // Add gas from current station
    current_gas -= cost[i];   // Subtract the cost to travel to next station
    
    if (current_gas < 0) {    // If we run out of gas, reset journey
        current_gas = 0;      // Reset the tank
        start_station = i + 1; // Consider the next station as the new start
    }
}
```

- **Why do we reset?**  
  If at station `i` the current gas drops below zero, it means that we cannot start from station `i` or any previous station. Hence, we reset and try starting from the next station (`i + 1`).

#### Step 3: **Return the Starting Station**

After simulating the journey, the `start_station` will be the index of the last station where the circuit can successfully be completed.

To account for the **1-indexed** return value, we will return the result as:

```cpp
return start_station;
```

---

### 📈 **Time and Space Complexity**

- **Time Complexity**:  
  The approach involves a single pass through the stations, making it **O(n)** where `n` is the number of stations.

- **Space Complexity**:  
  We only use a few variables to track the gas and current station index, so the space complexity is **O(1)**.

---

### 🚀 **Summary**

By following these steps:
1. We first check if completing the journey is possible by comparing the total gas and total cost.
2. If it's feasible, we simulate the journey with a greedy approach, resetting the journey whenever we run out of gas and moving to the next station.
3. The final result will give us the station index from which we can start to complete the circular journey without running out of gas.

If it's not possible to complete the journey, we return `-1`.

This approach ensures that we efficiently find the right station in linear time, making it optimal for large inputs.

---

[`Link to LeetCode Lab`](https://leetcode.com/problems/gas-station/description/)

---
{{< youtube xmJZSYSvgfE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
