
+++
authors = ["grid47"]
title = "Leetcode 1870: Minimum Speed to Arrive on Time"
date = "2024-05-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1870: Minimum Speed to Arrive on Time in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "XtwJqb1HI-o"
youtube_upload_date="2021-05-23"
youtube_thumbnail="https://i.ytimg.com/vi/XtwJqb1HI-o/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    bool canReach(int speed, vector<int>& dist, double hour) {
        
        double est = 0;
        
        for(int i = 0; i < dist.size(); i++) {
            if(i == (dist.size() - 1)) est += (double)dist[i]/ speed; 
            else est = ceil(est + (double)dist[i]/ speed);
        }
        // cout << speed << " " << est << " " << (est <= hour) << "\n";
        return est <= hour;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 0, r = INT_MAX - 1;
        
        int ans = INT_MAX;
        
        while(l <= r) {
            int speed = l + (r - l + 1)/2;
            
            if(canReach(speed, dist, hour)) {
                ans = speed;
                r = speed - 1;
            } else {
                l = speed + 1;
            }
        }
        return ans == INT_MAX? -1: ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The goal of this problem is to determine the minimum speed required to travel through a series of distances within a given time limit. Given an array of distances and a maximum time in hours, the task is to find the minimum speed (in units of distance per hour) that allows the traveler to reach the destination without exceeding the specified time limit. If it is impossible to reach the destination within the given time, the function should return -1.

### Approach

To solve this problem, we can utilize a binary search strategy combined with a helper function that checks if a given speed allows reaching the destination within the specified time. The approach involves the following key steps:

1. **Binary Search Setup**: Define a search space for the speed, starting from 1 (the minimum speed) to a very large value (e.g., `INT_MAX`), as we are looking for the minimum speed that allows us to reach the destination.

2. **Helper Function**: Create a helper function `canReach` that takes a speed, distances, and time as parameters. This function will calculate the estimated time required to complete the journey with the given speed and return whether this time is within the specified limit.

3. **Estimate Time Calculation**:
   - Iterate through each distance.
   - For each distance, calculate the time taken to cover it at the current speed.
   - Use the `ceil` function to ensure that any partial distance incurs a full hour of travel time, except for the last distance, which can be a fraction.
   - Accumulate the total estimated time and compare it with the given hour.

4. **Binary Search Execution**: 
   - Perform binary search by repeatedly adjusting the speed based on whether the current speed can successfully complete the journey within the allowed time.
   - If the speed works, try to find a lower speed (move left); otherwise, increase the speed (move right).

5. **Final Result**: If the minimum speed is found, return it; if not, return -1 to indicate that it's impossible to complete the journey within the given time.

### Code Breakdown (Step by Step)

1. **Class Definition**: Start by defining the `Solution` class, which will contain the method to solve the problem.

    ```cpp
    class Solution {
    public:
    ```

2. **Helper Function Declaration**: The `canReach` function is declared, which checks if the destination can be reached within the specified hour at a given speed.

    ```cpp
    bool canReach(int speed, vector<int>& dist, double hour) {
    ```

3. **Estimate Time Calculation**: Inside the `canReach` function, initialize a variable to accumulate the estimated time.

    ```cpp
    double est = 0;
    ```

4. **Iterating Through Distances**: Use a loop to iterate through each distance in the `dist` array.

    ```cpp
    for(int i = 0; i < dist.size(); i++) {
    ```

5. **Calculating Time for Each Distance**: For each distance, calculate the time required to travel that distance at the given speed:
   - If it's the last distance, directly add the time to the estimate.
   - For other distances, add the time and apply the `ceil` function to account for any partial time.

    ```cpp
    if(i == (dist.size() - 1)) est += (double)dist[i] / speed; 
    else est = ceil(est + (double)dist[i] / speed);
    ```

6. **Returning the Result from Helper Function**: After iterating through all distances, check if the estimated time is within the allowed hour and return the result.

    ```cpp
    return est <= hour;
    }
    ```

7. **Main Function Declaration**: Now, define the main function `minSpeedOnTime`, which implements the binary search logic.

    ```cpp
    int minSpeedOnTime(vector<int>& dist, double hour) {
    ```

8. **Binary Search Initialization**: Set the initial bounds for the binary search.

    ```cpp
    int l = 0, r = INT_MAX - 1;
    int ans = INT_MAX;
    ```

9. **Binary Search Loop**: Implement the binary search loop, calculating the midpoint speed and checking if it is sufficient.

    ```cpp
    while(l <= r) {
        int speed = l + (r - l + 1) / 2;
        
        if(canReach(speed, dist, hour)) {
            ans = speed; // If it works, update the answer
            r = speed - 1; // Try for a lower speed
        } else {
            l = speed + 1; // Increase speed
        }
    }
    ```

10. **Final Result Check**: After completing the search, check if a valid speed was found and return the appropriate result.

    ```cpp
    return ans == INT_MAX ? -1 : ans;
    }
    ```

### Complexity

The time complexity of this solution can be broken down into two parts:
- The binary search operates in \(O(\log(\text{MAX\_SPEED}))\), where `MAX_SPEED` is `INT_MAX`, which is a constant.
- For each speed checked, the `canReach` function processes the distances in \(O(n)\), where \(n\) is the length of the `dist` array.

Thus, the overall time complexity is \(O(n \log(\text{MAX\_SPEED}))\). The space complexity is \(O(1)\) as we are using a fixed amount of extra space for variables.

### Conclusion

In summary, the `minSpeedOnTime` function provides an efficient means to calculate the minimum speed required to reach a destination within a specified time, utilizing binary search and careful time estimation. The algorithm effectively balances speed and accuracy, ensuring that it can handle large input sizes due to its logarithmic nature in searching for the minimum speed. By leveraging the `canReach` helper function, we maintain clarity in the code while addressing the complexity of calculating time across multiple distances. This implementation serves as a robust solution for problems involving optimization and timing constraints in journey planning and can be adapted for various related challenges in algorithm design and competitive programming. Overall, this code exemplifies an efficient approach to solving a practical problem with clear logic and structure.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-speed-to-arrive-on-time/description/)

---
{{< youtube XtwJqb1HI-o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
