
+++
authors = ["grid47"]
title = "Leetcode 1921: Eliminate Maximum Number of Monsters"
date = "2024-04-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1921: Eliminate Maximum Number of Monsters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "6QQRayzOTD4"
youtube_upload_date="2021-07-04"
youtube_thumbnail="https://i.ytimg.com/vi/6QQRayzOTD4/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {

        int n = dist.size();
        vector<double> res(n, 0);
        for(int i = 0; i < n; i++)
        res[i] = (double(dist[i]) / speed[i]);

        sort(res.begin(), res.end());

        long j = 0, ans = 0;
        for (int i = 0; i < n; i++)
            if(j < res[i]) {
                ans++;
                j++;
            } else break;

        return (int) ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem involves determining how many monsters can be eliminated before they reach the city. Each monster has a certain distance to travel (`dist[i]`) and a speed (`speed[i]`). The goal is to calculate how many monsters can be eliminated before any of them arrive, based on the time it takes each monster to reach the city.

### Approach

To solve this problem, we can follow these steps:

1. **Calculate Arrival Times**: For each monster, we need to compute the time it takes to reach the city, which can be calculated using the formula:
   \[
   \text{time} = \frac{\text{distance}}{\text{speed}}
   \]

2. **Store and Sort Arrival Times**: Store these arrival times in a vector and then sort them. This allows us to handle the monsters in the order they will arrive.

3. **Eliminate Monsters**: Using a loop, we check if we can eliminate the monster at the current index before its arrival time. We maintain a counter to track how many monsters can be eliminated.

4. **Return Result**: Finally, we return the count of monsters that can be eliminated.

### Code Breakdown (Step by Step)

Let's take a closer look at the provided code:

```cpp
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
```
This line defines a class `Solution` with a public method `eliminateMaximum`, which takes two vectors, `dist` and `speed`, as input parameters.

```cpp
        int n = dist.size();
        vector<double> res(n, 0);
```
Here, we determine the size of the input arrays (both should be the same) and initialize a vector `res` of size `n` to hold the calculated arrival times.

```cpp
        for(int i = 0; i < n; i++)
            res[i] = (double(dist[i]) / speed[i]);
```
In this loop, we compute the arrival time for each monster using the formula discussed earlier and store it in the `res` vector. We use `double` to ensure we have precise floating-point division.

```cpp
        sort(res.begin(), res.end());
```
After calculating all arrival times, we sort the `res` vector in ascending order. This sorting will help us process the monsters in the order they will arrive.

```cpp
        long j = 0, ans = 0;
```
We initialize two counters: `j` to keep track of the number of monsters we have eliminated, and `ans` to count how many monsters can be eliminated.

```cpp
        for (int i = 0; i < n; i++)
            if(j < res[i]) {
                ans++;
                j++;
            } else break;
```
In this loop, we iterate through the sorted arrival times. If `j` (the number of monsters we have eliminated) is less than the current monster's arrival time (`res[i]`), it means we can eliminate this monster. We increment both `ans` and `j`. If we encounter a monster that cannot be eliminated (i.e., `j` is not less than `res[i]`), we break out of the loop.

```cpp
        return (int) ans;
    }
};
```
Finally, we return the count of monsters that can be eliminated, casting `ans` to an integer.

### Complexity

- **Time Complexity**: The time complexity of this algorithm is O(n log n) due to the sorting step, where `n` is the number of monsters. The loop that counts how many monsters can be eliminated runs in O(n) time.

- **Space Complexity**: The space complexity is O(n) because we are using an additional vector `res` to store the arrival times.

### Conclusion

The `eliminateMaximum` function efficiently determines how many monsters can be eliminated before they reach the city based on their distances and speeds. The approach leverages sorting and a simple counting mechanism to provide an optimal solution.

### Key Features

1. **Precise Time Calculation**: The use of floating-point arithmetic ensures that the arrival times are calculated accurately, which is crucial for determining whether a monster can be eliminated.

2. **Efficient Sorting**: Sorting the arrival times allows for a straightforward comparison to see if monsters can be eliminated in the order of their arrival.

3. **Simple Logic**: The logic used to determine how many monsters can be eliminated is clear and easy to follow, making the implementation straightforward.

### Use Cases

1. **Simulation Games**: This algorithm can be applied in game development, particularly in scenarios where players need to eliminate threats before they reach a target.

2. **Resource Management**: In resource management applications, similar logic can be used to manage incoming threats or resources based on their arrival times.

3. **Event Processing**: The approach can be adapted for processing events in real-time systems where events have different processing times.

4. **Competitive Programming**: Understanding this type of problem can help in competitive programming contexts where efficient data handling and sorting are required.

5. **Networking**: In network management, similar principles can be applied to handle data packets based on their transmission times, ensuring timely processing and preventing bottlenecks.

By grasping this solution, developers can enhance their skills in problem-solving and optimization, enabling them to tackle a variety of challenges involving timing and order in programming tasks.

[`Link to LeetCode Lab`](https://leetcode.com/problems/eliminate-maximum-number-of-monsters/description/)

---
{{< youtube 6QQRayzOTD4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
