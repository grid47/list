
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement

In the problem of watering plants, we are given an array representing the number of liters of water required for each plant and a water can with a specific capacity. Our objective is to determine the total number of steps required to water all the plants, given that:

1. The watering can starts full at the beginning of the task.
2. If the water in the can is insufficient to water a plant, we must return to the water source to refill before continuing.

The challenge lies in calculating the total number of steps (both forward to the plants and backward to the water source) to ensure that every plant receives the necessary amount of water.

### Approach

The approach involves simulating the process of watering each plant while keeping track of the current water level in the can. The algorithm can be summarized in the following steps:

1. **Initialization**: Start with the full capacity of the watering can and a counter for the total number of steps.

2. **Iterate Through Each Plant**: For each plant:
   - Check if the water can has enough water to meet the plant's requirement.
   - If it does, simply water the plant and decrease the water level.
   - If it doesn’t, return to the water source to refill the can, add the steps for this round trip, refill the can, and then water the plant.

3. **Final Count of Steps**: After watering all plants, account for the steps taken for each plant, including any trips back to the source.

This method ensures that we efficiently track the water level and the number of steps needed to water all the plants in the least number of trips.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the code implementation:

```cpp
class Solution {
public:
    int wateringPlants(vector<int>& num, int cap) {
```

1. **Function Definition**: The function `wateringPlants` takes in a vector `num`, representing the water required for each plant, and an integer `cap`, the capacity of the watering can.

```cpp
        int n = num.size();
        int rel = cap;
        int res = 0;
```

2. **Variable Initialization**:
   - `n`: The number of plants, which is the size of the `num` vector.
   - `rel`: A variable to track the remaining water in the can, initialized to `cap`.
   - `res`: A variable to count the total steps taken, initialized to zero.

```cpp
        for(int i = 0; i < n; i++) {
```

3. **Loop Through Each Plant**: This loop iterates over each plant indexed by `i`.

```cpp
            if(num[i] > rel) {
                rel = cap;
                res += 2*i;
            } 
```

4. **Check Water Sufficiency**:
   - If the current plant’s water requirement `num[i]` is greater than the remaining water (`rel`), we need to refill.
   - In this case, reset `rel` to `cap` (full can), and add `2*i` to `res` to account for the round trip (to the source and back to the plant).

```cpp
            rel -= num[i];            
        }
```

5. **Water the Plant**:
   - If the can has enough water, subtract the amount of water used (`num[i]`) from `rel`.

```cpp
        return res + n;
    }
};
```

6. **Return Total Steps**:
   - After watering all plants, return the total steps taken, which is the accumulated `res` plus `n` (the steps to each plant).

### Complexity

- **Time Complexity**: The algorithm processes each plant exactly once, leading to a time complexity of \(O(n)\), where \(n\) is the number of plants.

- **Space Complexity**: The space complexity is \(O(1)\) because we only use a fixed amount of additional space for the variables (`n`, `rel`, and `res`), regardless of the input size.

### Conclusion

The solution to the problem of watering plants efficiently models the scenario using a straightforward iterative approach. By tracking the current water level in the can and the total steps taken, we can accurately compute the required trips to water all the plants.

This implementation is optimal, ensuring that each plant is watered in the least number of steps necessary, effectively managing water resources while adhering to the rules of the problem.

This method can be applied in various scenarios where resource management and efficient movement between points are required, demonstrating a clear understanding of the underlying logic and constraints. Such a simulation approach is a powerful technique in algorithm design, especially in resource allocation problems.

[`Link to LeetCode Lab`](https://leetcode.com/problems/watering-plants/description/)

---
{{< youtube 6GNga8RRNSQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
