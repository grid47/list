
+++
authors = ["grid47"]
title = "Leetcode 2008: Maximum Earnings From Taxi"
date = "2024-04-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2008: Maximum Earnings From Taxi in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Dynamic Programming","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "QoAuE1v2vxA"
youtube_upload_date="2021-09-18"
youtube_thumbnail="https://i.ytimg.com/vi/QoAuE1v2vxA/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> rides;
    vector<long long> memo;
    int n;

    long long dp(int idx) {
        
        if(idx == rides.size()) return 0;
        
        if(memo[idx] != -1) return memo[idx];
        
        long long ans = dp(idx + 1);
                
        
        int end = rides[idx][1];
        
        int l = idx + 1, r = rides.size() - 1;
        int pos = rides.size();
        
        while(l <= r) {
            int mid = l + (r - l + 1) / 2;
            if(rides[mid][0] >= end) {
                pos = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
            
        ans = max(ans, dp(pos) + rides[idx][2]);        
        return memo[idx] = ans;
    }
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& ride) {
        this->n = n;
        rides = ride;
        sort(rides.begin(), rides.end());
        
        for(int i = 0; i < rides.size(); i++)
            rides[i][2] += rides[i][1] - rides[i][0];
        
        memo.resize(rides.size() + 1, -1);
        return dp(0);

    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand is to determine the maximum earnings a taxi driver can make given a set of rides. Each ride is represented by a start time, end time, and a fare. The goal is to find the maximum total earnings by selecting non-overlapping rides such that the driver can choose rides in a way that they do not overlap in time. 

For instance, if we have rides defined as `ride = [[1, 3, 10], [2, 5, 15], [3, 6, 20]]`, the driver can select rides such that they earn the maximum fare without any overlap. In this case, choosing the rides `[1, 3, 10]` and `[3, 6, 20]` results in maximum earnings of `10 + 20 = 30`.

### Approach

To efficiently solve this problem, we can utilize dynamic programming along with binary search. The main steps involved in the approach are:

1. **Data Transformation**: For each ride, we transform the input to include the net earnings, which is calculated as `fare + (end time - start time)`. This helps us directly work with the total earnings for each ride.

2. **Sorting**: We sort the rides based on their end times. This is crucial because it allows us to easily find the next ride that can be taken after the current ride has ended.

3. **Dynamic Programming with Memoization**: We define a recursive function that calculates the maximum earnings starting from a given ride index. The function checks:
   - If the current ride is not selected, it recursively calls itself for the next ride.
   - If the current ride is selected, it uses binary search to find the next non-overlapping ride and recursively calculates the earnings from that point.

4. **Memoization**: To optimize the recursive calls, we use a memoization array that stores previously computed results for ride indices to avoid redundant calculations.

### Code Breakdown (Step by Step)

Let's dissect the code and understand how each part contributes to the solution:

1. **Class Definition**: We start by defining a class named `Solution`, which encapsulates the logic for our solution.

    ```cpp
    class Solution {
    public:
        vector<vector<int>> rides;
        vector<long long> memo;
        int n;
    ```

2. **Dynamic Programming Function**: The `dp` function calculates the maximum earnings starting from a given index `idx`:

    ```cpp
    long long dp(int idx) {
    ```

3. **Base Case**: If we reach the end of the rides list, we return `0` as there are no further rides to consider.

    ```cpp
    if(idx == rides.size()) return 0;
    ```

4. **Memoization Check**: If we have already computed the result for the current index, we return the stored result to avoid redundant calculations.

    ```cpp
    if(memo[idx] != -1) return memo[idx];
    ```

5. **Earnings Without Current Ride**: We first calculate the maximum earnings if the current ride is skipped.

    ```cpp
    long long ans = dp(idx + 1);
    ```

6. **End Time Extraction**: We store the end time of the current ride for later calculations.

    ```cpp
    int end = rides[idx][1];
    ```

7. **Binary Search for Next Ride**: We initialize pointers for binary search to find the next ride that starts after the current ride ends. This helps in identifying non-overlapping rides efficiently.

    ```cpp
    int l = idx + 1, r = rides.size() - 1;
    int pos = rides.size();
    
    while(l <= r) {
        int mid = l + (r - l + 1) / 2;
        if(rides[mid][0] >= end) {
            pos = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    ```

8. **Earnings With Current Ride**: We calculate the potential maximum earnings by including the current ride's earnings and adding it to the earnings from the next possible ride found via binary search.

    ```cpp
    ans = max(ans, dp(pos) + rides[idx][2]);
    ```

9. **Store Result in Memoization Array**: Finally, we store the computed maximum earnings for the current index in the memoization array.

    ```cpp
    return memo[idx] = ans;
    ```

10. **Main Function**: The `maxTaxiEarnings` function initializes the problem, transforms the ride data, sorts it, and starts the recursive dynamic programming process.

    ```cpp
    long long maxTaxiEarnings(int n, vector<vector<int>>& ride) {
        this->n = n;
        rides = ride;
        sort(rides.begin(), rides.end());
    ```

11. **Calculating Net Earnings**: We modify the rides to include net earnings.

    ```cpp
    for(int i = 0; i < rides.size(); i++)
        rides[i][2] += rides[i][1] - rides[i][0];
    ```

12. **Memoization Initialization**: We prepare the memoization array to store results for all ride indices.

    ```cpp
    memo.resize(rides.size() + 1, -1);
    return dp(0);
    ```

### Complexity

The time complexity of this solution is O(n log n) due to the sorting step and the binary search for each ride, where `n` is the number of rides. The space complexity is O(n) for the memoization array and the transformed rides array. This approach efficiently handles the problem constraints and ensures that we compute the maximum earnings with minimal redundant calculations.

### Conclusion

In conclusion, this code offers a clear and efficient solution to the problem of maximizing taxi earnings from a list of rides. By using a combination of dynamic programming and binary search, it effectively handles the challenge of selecting non-overlapping rides. The transformation of the input rides to include net earnings simplifies the calculations, and the memoization strategy optimizes performance. Overall, the implementation not only demonstrates strong algorithmic techniques but also provides a robust framework for addressing similar problems in algorithmic challenges, making it a valuable reference for developers and algorithm enthusiasts alike.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-earnings-from-taxi/description/)

---
{{< youtube QoAuE1v2vxA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
