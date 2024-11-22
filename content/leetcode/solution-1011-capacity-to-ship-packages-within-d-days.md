
+++
authors = ["grid47"]
title = "Leetcode 1011: Capacity To Ship Packages Within D Days"
date = "2024-07-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1011: Capacity To Ship Packages Within D Days in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ER_oLmdc-nw"
youtube_upload_date="2023-02-22"
youtube_thumbnail="https://i.ytimg.com/vi/ER_oLmdc-nw/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 25000000;
        for(int w: weights)
        left = max(left, w);

        while(left < right) {
            int mid = (left + right) / 2;
            int need =1, cur = 0;
            for(int i = 0; i <  weights.size() && need <= days; cur += weights[i++])
                if(cur + weights[i] > mid)
                cur = 0, need++;
            if(need > days) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
{{< /highlight >}}
---



### Problem Statement
The problem involves determining the minimum shipping capacity of a ship such that a set of packages can be delivered within a specified number of days. Each package has a specific weight, and the ship can carry a maximum weight in a single day. The goal is to minimize the weight capacity of the ship while ensuring that all packages are delivered within the given number of days.

For example, given weights `[1, 2, 3, 4, 5]` and a limit of `3` days, we want to find the smallest capacity that allows these packages to be shipped within that timeframe.

### Approach
To solve this problem, we can utilize a binary search strategy to efficiently determine the minimum ship capacity:
1. **Initialize Bounds**: Set the lower bound (`left`) to the heaviest package and the upper bound (`right`) to the sum of all package weights. The ship must be able to carry at least the heaviest package and at most all packages in one trip.
2. **Binary Search**: Perform a binary search between these bounds to find the minimum capacity. For each mid-point capacity, determine whether it is possible to ship all packages within the allowed number of days.
3. **Feasibility Check**: Implement a helper mechanism that checks how many days are needed to ship all packages for a given capacity. If it exceeds the allowed days, we need to increase the capacity.

### Code Breakdown (Step by Step)

1. **Function Declaration**:
   - The function `shipWithinDays` is defined as a public member of the `Solution` class, taking a vector of integers `weights` and an integer `days` as parameters.

2. **Initializing Bounds**:
   - We initialize `left` to 0 and `right` to a large number, specifically `25,000,000`. This upper bound is significantly higher than any possible total weight, ensuring we have a reasonable search space.
   - We then iterate through the `weights` array to find the maximum weight of a single package. This value is assigned to `left` since the ship's capacity must be at least as large as the heaviest package.

3. **Binary Search Loop**:
   - A `while` loop runs as long as `left` is less than `right`. This loop will narrow down the search space for the minimum capacity.
   - Inside the loop, we calculate the midpoint `mid` between `left` and `right`. This value represents the current capacity being tested.

4. **Feasibility Check for Current Capacity**:
   - We initialize `need` to 1, representing the number of days required, and `cur` to 0, which tracks the current weight being loaded onto the ship.
   - A `for` loop iterates through each weight in `weights`. The condition `need <= days` ensures that we do not exceed the allowed number of days:
     - In each iteration, we check if adding the current weight `weights[i]` to `cur` exceeds the `mid` capacity.
     - If it does exceed, we reset `cur` to 0 and increment `need` by 1 to indicate we need another day for shipping.
     - If `need` exceeds `days`, it indicates that the current capacity is insufficient.

5. **Adjusting Search Bounds**:
   - After checking all weights, we determine if the current capacity (`mid`) is feasible:
     - If `need` is greater than `days`, we increase the lower bound (`left = mid + 1`), indicating we need a larger capacity.
     - If it is within the limit, we reduce the upper bound (`right = mid`), indicating the current capacity might be sufficient.

6. **Returning the Result**:
   - Once the binary search concludes, the function returns the value of `left`, which represents the minimum capacity of the ship needed to ship all packages within the allowed number of days.

### Complexity Analysis
- **Time Complexity**: The time complexity of this function is O(n log m), where `n` is the number of packages (the size of the `weights` vector) and `m` is the sum of weights (the range of possible capacities). The binary search operates in O(log m), while the inner loop that checks the feasibility runs in O(n).
- **Space Complexity**: The space complexity is O(1) because we are only using a fixed amount of additional space for variables, regardless of the input size.

### Conclusion
The `shipWithinDays` function effectively determines the minimum shipping capacity required to deliver packages within a specified timeframe by utilizing a binary search strategy. This method efficiently narrows down potential capacities while leveraging a linear scan to validate feasibility for each midpoint capacity.

This solution highlights the importance of combining binary search with greedy strategies to solve optimization problems, particularly those involving constraints. Understanding this approach can significantly enhance problem-solving skills in algorithmic challenges, especially in scenarios that require efficiency and correctness.

Moreover, this implementation showcases the utility of careful management of search bounds and iterations, making it a valuable tool for similar problems encountered in competitive programming and technical interviews. The clarity of the algorithm allows for easy adaptations to related challenges, ensuring its relevance in a variety of contexts.

In summary, the `shipWithinDays` function serves as an excellent example of how to leverage efficient searching and evaluation techniques to solve real-world problems involving logistics and constraints, demonstrating the power of algorithmic thinking in practical applications.


[`Link to LeetCode Lab`](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/)

---
{{< youtube ER_oLmdc-nw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
