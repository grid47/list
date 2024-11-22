
+++
authors = ["grid47"]
title = "Leetcode 2960: Count Tested Devices After Test Operations"
date = "2024-01-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2960: Count Tested Devices After Test Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "77lcjZ2prk8"
youtube_upload_date="2023-12-11"
youtube_thumbnail="https://i.ytimg.com/vi/77lcjZ2prk8/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int ans = 0;
        for(auto b: batteryPercentages) ans += (b > ans)?1: 0;
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement:
Given an array `batteryPercentages`, representing the battery percentage of different devices, the task is to count how many devices have a battery percentage greater than or equal to the count of devices that have been considered so far.

The problem asks for an efficient way to compute this count for every device as we process them sequentially.

### Approach:
This problem can be solved by iterating over the array and maintaining a running count of the devices that have a higher battery percentage than the current count. The key observation here is that for each device, we compare its battery percentage to the current count of tested devices and update the count accordingly.

1. **Iterate through the array**: We will iterate over the `batteryPercentages` array, one element at a time, and maintain a variable that tracks how many devices have been tested and meet the condition (battery percentage greater than the count of tested devices).

2. **Comparison**: For each device, we compare its battery percentage with the current count of tested devices. If the device's battery percentage is greater than the current count, we increment the count of tested devices. This ensures that only devices with sufficiently high battery percentages are counted.

3. **Return the result**: Finally, after processing all the devices, we return the total count of tested devices.

### Code Breakdown (Step by Step):
Let's break down the code to understand the individual steps:

#### 1. **Initialization**:
```cpp
int ans = 0;
```
- We initialize a variable `ans` to store the count of devices that meet the condition. Initially, the count is set to 0, since no devices have been tested yet.

#### 2. **Iterate through the battery percentages**:
```cpp
for(auto b: batteryPercentages)
```
- We use a `for` loop to iterate through each element `b` in the `batteryPercentages` array. Here, `auto` allows the variable `b` to take the type of each element in the array (which is an integer representing the battery percentage of a device).

#### 3. **Condition to count the device**:
```cpp
ans += (b > ans) ? 1 : 0;
```
- This line contains a conditional (ternary) operator that checks if the battery percentage of the current device (`b`) is greater than the current value of `ans` (the count of devices tested so far).
- If `b > ans` is true, the count of tested devices `ans` is incremented by 1. Otherwise, it remains unchanged.
- This ensures that devices with a higher battery percentage than the current count are counted.

#### 4. **Return the result**:
```cpp
return ans;
```
- After iterating through all the devices, we return the value of `ans`, which represents the number of devices that meet the condition of having a battery percentage greater than the count of tested devices.

### Complexity Analysis:

#### Time Complexity:
- The time complexity of this solution is **O(n)**, where `n` is the length of the `batteryPercentages` array. This is because we are iterating over the array exactly once and performing constant-time operations for each element.

#### Space Complexity:
- The space complexity is **O(1)** because we are only using a few integer variables (`ans` and `b`) that do not depend on the size of the input array. No additional data structures are used that grow with the input size.

### Conclusion:
This problem is solved efficiently by iterating over the array of battery percentages while maintaining a running count of tested devices that meet the condition. The solution works in linear time, making it suitable for large arrays. By leveraging the simple comparison and conditional logic, we are able to count the devices that have battery percentages greater than the current count efficiently, with constant space complexity.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-tested-devices-after-test-operations/description/)

---
{{< youtube 77lcjZ2prk8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
