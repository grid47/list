
+++
authors = ["grid47"]
title = "Leetcode 475: Heaters"
date = "2024-09-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 475: Heaters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/475.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/475.webp" 
    alt="A grid where heaters light up and warm nearby houses, with each heater softly illuminating its effect."
    caption="Solution to LeetCode 475: Heaters Problem"
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
    int findRadius(vector<int>& home, vector<int>& warm) {
        sort(home.begin(), home.end());
        sort(warm.begin(), warm.end());
        int m = home.size(), n = warm.size();
        
        vector<int> res(m, INT_MAX);
        
        for(int h = 0, w = 0; h < m && w < n; ) {
            if (home[h] <= warm[w]) {
                res[h] = warm[w] - home[h];
                h++;
            } else w++;
        }
        
        for(int h = m - 1, w = n - 1; h >= 0 && w >= 0; ) {
            if (home[h] >= warm[w]) {
                res[h] = min(res[h], home[h] - warm[w]);
                h--;
            } else w--;
        }
        
        return *max_element(res.begin(), res.end());
    }
};
{{< /highlight >}}
---

### Problem Statement

In this problem, we are tasked with determining the minimum radius needed for heaters to cover all the houses on a 1D line. Specifically, we are given two arrays:
- **home**: A list of positions of houses on a 1D axis.
- **warm**: A list of positions of heaters on the same axis.

The goal is to find the smallest radius such that every house is within the radius of at least one heater. The radius of a heater is defined as the distance between the heater's position and the farthest house it can cover.

### Approach

To solve this problem, we need to minimize the maximum distance from each house to the closest heater. The strategy involves:
1. **Sorting the Arrays**: By sorting the `home` and `warm` arrays, we can ensure that we compare houses and heaters in order, which helps in efficiently finding the closest heater for each house.
2. **Two-Pass Approach**: 
   - In the first pass, we iterate through the homes from left to right, finding the nearest heater that is to the right or equal to the current house.
   - In the second pass, we iterate through the homes from right to left, finding the nearest heater that is to the left or equal to the current house.
3. **Final Result**: For each house, the final radius required is the minimum of the distances to the closest heater from the left and right directions. We then return the largest radius among all houses to ensure that all houses are covered.

### Code Breakdown (Step by Step)

#### Step 1: Sort the Home and Warm Arrays
```cpp
sort(home.begin(), home.end());
sort(warm.begin(), warm.end());
```
- We begin by sorting both the `home` and `warm` arrays. Sorting ensures that we can process the houses and heaters in an ordered manner, which simplifies the process of finding the nearest heater to each house.

#### Step 2: Initialize a Result Array
```cpp
int m = home.size(), n = warm.size();
vector<int> res(m, INT_MAX);
```
- We initialize a result array `res` of size `m` (number of houses) where each element represents the minimum distance from a house to the nearest heater. Initially, we set all elements to `INT_MAX`, indicating that we have not yet computed the distance for each house.

#### Step 3: First Pass - Left to Right
```cpp
for(int h = 0, w = 0; h < m && w < n; ) {
    if (home[h] <= warm[w]) {
        res[h] = warm[w] - home[h];
        h++;
    } else w++;
}
```
- This loop iterates over the houses (`h` index) and heaters (`w` index) from left to right.
- For each house, we check if the current heater is positioned at or before the house (`home[h] <= warm[w]`).
  - If the heater is positioned before or at the house, we compute the distance from this house to the heater and update the `res[h]` with this distance.
  - We then move to the next house (`h++`).
  - If the heater is farther from the house, we move to the next heater (`w++`) to find the closest one.

#### Step 4: Second Pass - Right to Left
```cpp
for(int h = m - 1, w = n - 1; h >= 0 && w >= 0; ) {
    if (home[h] >= warm[w]) {
        res[h] = min(res[h], home[h] - warm[w]);
        h--;
    } else w--;
}
```
- This loop works similarly to the first pass, but in this case, we iterate from right to left.
- For each house, we check if the current heater is positioned at or after the house (`home[h] >= warm[w]`).
  - If the heater is positioned after or at the house, we compute the distance from this house to the heater.
  - We then update the `res[h]` array with the minimum of the existing value in `res[h]` and the new computed distance to the current heater. This ensures we get the minimum distance to a heater from either direction.
  - We then move to the next house (`h--`) or the next heater (`w--`) based on the comparison.

#### Step 5: Return the Maximum Radius
```cpp
return *max_element(res.begin(), res.end());
```
- After processing all the houses, we take the maximum value in the `res` array, which represents the minimum radius required to cover all the houses. This is the largest distance from any house to its closest heater.

### Complexity

#### Time Complexity:
- **Sorting**: Sorting both the `home` and `warm` arrays takes `O(m log m + n log n)`, where `m` is the number of houses and `n` is the number of heaters.
- **First Pass**: The first pass involves iterating over both the `home` and `warm` arrays, which takes `O(m + n)` time.
- **Second Pass**: The second pass also involves iterating over both the `home` and `warm` arrays, which takes `O(m + n)` time.
- **Final Calculation**: The final step of finding the maximum value in the `res` array takes `O(m)` time.
- **Overall Time Complexity**: The overall time complexity is dominated by the sorting step, which gives us `O(m log m + n log n)`.

#### Space Complexity:
- We use a result array `res` of size `m` to store the minimum distance for each house, which requires `O(m)` space.
- We do not use any additional data structures that grow with the input size, so the overall space complexity is `O(m)`.

### Conclusion

This solution efficiently computes the minimum radius required to cover all houses with heaters by using a two-pass approach: one from left to right and the other from right to left. By sorting both the `home` and `warm` arrays, we can easily compute the closest heater for each house in both directions and find the minimum radius. The algorithm runs in `O(m log m + n log n)` time and uses `O(m)` space, making it optimal for this problem. This approach guarantees that every house is covered by the nearest heater while minimizing the maximum radius.

[`Link to LeetCode Lab`](https://leetcode.com/problems/heaters/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
