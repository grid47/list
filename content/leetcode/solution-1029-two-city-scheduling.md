
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
comments = true
+++



---
A company is planning to interview 2n people, and for each person, there are two possible cities where they can be interviewed. The cost of flying a person to city A or city B is given. You need to find the minimum cost to fly exactly n people to each city. The challenge is to select n people for city A and the remaining n people for city B such that the total cost is minimized.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 2D array where each element costs[i] = [aCosti, bCosti], representing the cost of flying the i-th person to city A and city B, respectively.
- **Example:** `costs = [[10,20],[30,200],[400,50],[30,20]]`
- **Constraints:**
	- 2 <= costs.length <= 100
	- costs.length is even
	- 1 <= aCosti, bCosti <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the minimum total cost to fly n people to each city.
- **Example:** `Output: 110`
- **Constraints:**
	- The total number of people is even, so exactly half will be sent to each city.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the total cost of flying exactly n people to each city while considering both possible costs for each person.

- 1. For each person, calculate the difference in cost between flying them to city A and flying them to city B.
- 2. Accumulate the cost for flying everyone to city A initially.
- 3. Sort the differences in cost (refunds) and select the smallest n differences to add to the total cost, representing the people who will be sent to city B.
- 4. Return the final accumulated cost.
{{< dots >}}
### Problem Assumptions ✅
- The number of people is always even, and half of them must go to each city.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: costs = [[10,20],[30,200],[400,50],[30,20]]`  \
  **Explanation:** The optimal way is to send the first two people to city A with costs 10 and 30, and the last two to city B with costs 50 and 20. The minimum total cost is 10 + 30 + 50 + 20 = 110.

- **Input:** `Input: costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]`  \
  **Explanation:** Here, the optimal solution gives a total cost of 1859, balancing between the lower costs for each city.

{{< dots >}}
## Approach 🚀
The problem can be approached using a greedy algorithm. First, calculate the initial total cost by sending all people to city A. Then, sort the differences in cost between cities A and B for each person and adjust the total cost by sending the n least expensive people to city B.

### Initial Thoughts 💭
- The problem can be solved with sorting and greedy selection of the least expensive adjustments.
- Sorting the differences between costs and choosing the n smallest adjustments ensures the minimum cost for city assignments.
{{< dots >}}
### Edge Cases 🌐
- The input array will always have at least 2 elements, so there is no need to handle empty inputs.
- The algorithm must handle arrays of up to 100 elements efficiently.
- If the costs for city A and city B are equal for all people, the cost is the same regardless of where each person is sent.
- The number of elements in the input array will always be even.
{{< dots >}}
## Code 💻
```cpp
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
```

This function calculates the minimum cost of sending half of the people to one city and the other half to another city, by utilizing cost sorting and refund differences.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int twoCitySchedCost(vector<vector<int>>& costs) {
	```
	Define the function `twoCitySchedCost` which computes the minimum cost to assign people to two cities.

2. **Initialize Cost**
	```cpp
	    int mc = 0;
	```
	Initialize the variable `mc` to store the minimum cost.

3. **Initialize Refund Vector**
	```cpp
	    vector<int> refund;
	```
	Declare a vector `refund` to store the cost difference when sending a person to city B instead of city A.

4. **Iterate Costs**
	```cpp
	    for(auto c : costs) {
	```
	Iterate through the costs array to calculate the initial cost and populate the refund differences.

5. **Add City A Cost**
	```cpp
	        mc += c[0];
	```
	Add the cost of sending the person to city A to the total cost `mc`.

6. **Calculate Refund**
	```cpp
	        refund.push_back(c[1] - c[0]);
	```
	Calculate the refund for sending the person to city B instead of city A and add it to the refund vector.

7. **Sort Refunds**
	```cpp
	    sort(refund.begin(), refund.end());
	```
	Sort the refund vector to prioritize the smallest refunds.

8. **Calculate Half Size**
	```cpp
	    int n = costs.size()/ 2;
	```
	Calculate half the size of the costs array, representing the number of people per city.

9. **Add Smallest Refunds**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Iterate through the first half of the sorted refunds to add the smallest refunds to the total cost.

10. **Update Minimum Cost**
	```cpp
	        mc += refund[i];
	```
	Update the total minimum cost `mc` by adding the smallest refunds.

11. **Return Result**
	```cpp
	    return mc;
	```
	Return the calculated minimum cost `mc`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is O(n log n) due to the sorting step for selecting the n least expensive people to send to city B.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of refund values in an array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/two-city-scheduling/description/)

---
{{< youtube d-B_gk_gJtQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
