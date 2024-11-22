
+++
authors = ["grid47"]
title = "Leetcode 1029: Two City Scheduling"
date = "2024-07-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1029: Two City Scheduling in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "d-B_gk_gJtQ"
youtube_upload_date="2022-03-25"
youtube_thumbnail="https://i.ytimg.com/vi/d-B_gk_gJtQ/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        /*
        
        2n people - interview
        
        
        */
        int mc = 0;
        vector<int> refund;
        
        for(auto c : costs) {
            mc += c[0];
            refund.push_back(c[1] - c[0]);
        }
        sort(refund.begin(), refund.end());
        int n = costs.size()/ 2;
        
        for(int i = 0; i < n; i++) {
            mc += refund[i];
        }
        
        return mc;
    }
};
{{< /highlight >}}
---



### Problem Statement
The problem requires minimizing the cost of sending `2n` people to two cities, City A and City B. Each person has two associated costs: one for traveling to City A and another for traveling to City B. The objective is to send `n` people to each city such that the total travel cost is minimized.

For example, if we have the following costs for four people:
- Person 1: City A costs $10, City B costs $20
- Person 2: City A costs $30, City B costs $50
- Person 3: City A costs $20, City B costs $40
- Person 4: City A costs $30, City B costs $10

The goal is to select two people for City A and two people for City B while minimizing the total cost.

### Approach
To solve the problem optimally:
1. **Initial Cost Calculation**: First, calculate the total cost of sending everyone to City A. This serves as a baseline cost.
2. **Refund Calculation**: Create a list of "refunds," which represent the difference in cost for sending each person to City B instead of City A. If sending someone to City B is cheaper than sending them to City A, the refund will be a positive value.
3. **Sorting Refunds**: Sort the list of refunds. The smallest refunds indicate the most cost-effective switches from City A to City B.
4. **Selecting the Cheapest Refunds**: To ensure that exactly `n` people are sent to each city, select the first `n` elements from the sorted refund list and add them to the initial cost.

### Code Breakdown (Step by Step)

1. **Function Declaration**:
   - The function `twoCitySchedCost` is declared within the `Solution` class and takes a 2D vector of integers (`vector<vector<int>>& costs`) representing the costs for each person traveling to the two cities.

2. **Initialization**:
   - An integer variable `mc` is initialized to `0`. This variable will store the minimum cost.
   - A vector of integers `refund` is declared to store the cost differences between sending each person to City B versus City A.

3. **Calculating Initial Costs and Refunds**:
   - A range-based for loop iterates through each person's costs:
     - `mc` is incremented by the cost of sending each person to City A (`c[0]`).
     - The refund value (`c[1] - c[0]`), which indicates how much more it costs to send a person to City B compared to City A, is calculated and added to the `refund` vector.

4. **Sorting Refunds**:
   - The `refund` vector is sorted in ascending order. This sorting allows us to prioritize the smallest refund values, which represent the best candidates for switching to City B.

5. **Selecting the Cheapest Refunds**:
   - The variable `n` is computed as half the size of the costs vector (`costs.size() / 2`), indicating how many people should be sent to City A and how many to City B.
   - A for loop runs from `0` to `n - 1`:
     - For each iteration, the smallest refunds are added to `mc`. This accounts for the cost of sending the first `n` cheapest individuals to City B.

6. **Returning the Result**:
   - Finally, the function returns `mc`, which now contains the total minimized cost of sending `n` people to each city.

### Complexity Analysis
- **Time Complexity**: The time complexity of this solution is \(O(n \log n)\) due to the sorting of the refund vector, where \(n\) is half the number of total individuals (or the number of cost pairs). The initial cost calculation is \(O(n)\), making the dominant factor the sorting operation.
  
- **Space Complexity**: The space complexity is \(O(n)\) to store the refund values, which is necessary to keep track of the cost differences.

### Conclusion
The `twoCitySchedCost` function effectively minimizes the travel cost of sending `2n` individuals to two cities using a straightforward approach based on cost comparisons. By leveraging sorting and careful selection of individuals based on their travel costs, the function guarantees that the minimum possible cost is achieved while meeting the requirement of sending exactly `n` people to each city.

This method is particularly useful in scenarios such as resource allocation, transportation optimization, and cost management in logistics. The clarity and efficiency of the algorithm demonstrate its practical applicability in real-world situations where minimizing costs while satisfying constraints is critical.

In summary, this implementation showcases how to balance decision-making with computational efficiency in algorithm design, providing a robust solution to a common problem in operations research and optimization. Understanding such techniques is valuable for software engineers and data scientists aiming to tackle complex optimization challenges.


[`Link to LeetCode Lab`](https://leetcode.com/problems/two-city-scheduling/description/)

---
{{< youtube d-B_gk_gJtQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
