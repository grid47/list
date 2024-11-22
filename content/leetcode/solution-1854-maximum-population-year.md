
+++
authors = ["grid47"]
title = "Leetcode 1854: Maximum Population Year"
date = "2024-05-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1854: Maximum Population Year in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Counting","Prefix Sum"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "2W2yijatcTY"
youtube_upload_date="2021-05-09"
youtube_thumbnail="https://i.ytimg.com/vi_webp/2W2yijatcTY/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> sum(102, 0);
        
        for(auto v: logs) {
            sum[v[1] - 1950]--;
            sum[v[0] - 1950]++;
        }
        
        for(int i = 1; i < 102; i++) {
            sum[i] += sum[i - 1];
            cout << sum[i] << " ";
        }
        
        int mx = 0, yr = 2050;
        for(int i = 101; i >= 0; i--) {
            if(sum[i] >= mx) {
                yr = i + 1950;
                mx = sum[i];
            }
        }
        return yr;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand is to determine the year with the maximum population based on birth and death logs provided for a range of years. Each log entry contains a birth year and a death year for a person. The objective is to find the year during which the population was at its peak, given that the logs span from 1950 to 2050.

### Approach

To tackle this problem, we will use a counting array to track the population changes over the years. We will implement the following steps:

1. **Initialize a Counting Array**: Create an array that will represent population changes from 1950 to 2050.
2. **Process Each Log Entry**: For each log entry, increment the count at the birth year and decrement the count at the death year.
3. **Calculate the Population Over the Years**: Iterate through the counting array to calculate the cumulative population for each year.
4. **Determine the Year with Maximum Population**: Identify the year with the highest population, returning that year.

### Code Breakdown (Step by Step)

Here’s the complete implementation of the solution:

```cpp
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> sum(102, 0);
        
        for(auto v: logs) {
            sum[v[1] - 1950]--;   // Decrease population count at death year
            sum[v[0] - 1950]++;   // Increase population count at birth year
        }
```
- **Class Declaration**: The solution is encapsulated in a class named `Solution`.
- **Function Definition**: The function `maximumPopulation` takes a vector of vectors (`logs`) where each inner vector represents the birth and death years.
- **Counting Array Initialization**: A vector `sum` of size 102 (to cover years from 1950 to 2050) is initialized to zero. This array will be used to track population changes over time.
- **Population Change Updates**: For each log entry:
  - The death year (indicated by `v[1]`) results in a decrease in population, hence `sum[v[1] - 1950]--`.
  - The birth year (indicated by `v[0]`) results in an increase in population, hence `sum[v[0] - 1950]++`.

```cpp
        for(int i = 1; i < 102; i++) {
            sum[i] += sum[i - 1];  // Cumulative population count
            cout << sum[i] << " ";  // Debug output of the cumulative sums
        }
```
- **Cumulative Population Calculation**: We iterate from index 1 to 101, updating the `sum` array to reflect the cumulative population. This means that each entry now represents the population at the end of that year.
- **Debugging Output**: A debugging statement (`cout << sum[i] << " ";`) is included to print the population for each year. This can help in tracing the internal state of the program during execution.

```cpp
        int mx = 0, yr = 2050;
        for(int i = 101; i >= 0; i--) {
            if(sum[i] >= mx) {  // Track the maximum population
                yr = i + 1950;  // Calculate the actual year
                mx = sum[i];    // Update maximum population
            }
        }
        return yr;  // Return the year with maximum population
    }
};
```
- **Find Year with Maximum Population**: We initialize `mx` to track the maximum population encountered and `yr` to store the year corresponding to that population.
- **Backward Looping**: We loop backward through the `sum` array (from index 101 to 0) to find the maximum population year. This ensures that in case of ties, we prefer the latest year.
- **Return Statement**: Finally, we return the year that has the maximum population.

### Complexity

- **Time Complexity**: 
  - The time complexity for processing the logs is \( O(n) \), where \( n \) is the number of log entries. Each log entry requires constant time operations to update the counting array.
  - The time complexity for computing the cumulative population and finding the maximum is \( O(1) \) since it iterates through a fixed-size array of 102 elements.

- **Space Complexity**: 
  - The space complexity is \( O(1) \) in terms of extra space used since we are only utilizing the counting array of size 102 and a few integer variables for computation.

### Conclusion

The provided solution efficiently determines the year with the maximum population based on the given birth and death logs. By utilizing a counting array and performing cumulative calculations, the implementation achieves optimal time and space complexity.

This solution highlights effective programming techniques, including the use of arrays for counting, cumulative sums for population tracking, and efficient loop structures to find the desired result. It is well-suited for competitive programming and real-world applications where such demographic analysis might be necessary. 

In summary, the algorithm can handle a variety of scenarios involving demographic logs, making it versatile and efficient for population analysis over a specified time range.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-population-year/description/)

---
{{< youtube 2W2yijatcTY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
