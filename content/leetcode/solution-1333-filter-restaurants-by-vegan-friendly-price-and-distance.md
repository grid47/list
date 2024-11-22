
+++
authors = ["grid47"]
title = "Leetcode 1333: Filter Restaurants by Vegan-Friendly, Price and Distance"
date = "2024-06-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1333: Filter Restaurants by Vegan-Friendly, Price and Distance in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        if(a[1] == b[1]) return a[0] > b[0];
        else return a[1] > b[1];
    }
    
    vector<int> filterRestaurants(vector<vector<int>>& rest, int veg, int mxp, int mxd) {
        
        vector<vector<int>> ans;
        
        for(auto r: rest) {
            if((!veg || (veg == r[2])) && r[3] <= mxp && r[4] <= mxd) {
                ans.push_back({r[0], r[1]});
            }
        }
        
        sort(ans.begin(), ans.end(), cmp);
        
        vector<int> res;
        for(auto x: ans) {
            res.push_back(x[0]);
        }
        return res;
    }
};
{{< /highlight >}}
---


### Problem Statement
In this task, you are required to filter a list of restaurants based on specific conditions and then sort them according to certain preferences. The input consists of a list of restaurants, where each restaurant has attributes such as its ID, rating, whether it is vegetarian, maximum price, and maximum distance. You need to filter out restaurants based on whether they are vegetarian (if requested), their maximum price, and maximum distance, then sort the results based on their ratings and IDs.

### Approach
The solution follows a structured approach:
1. **Filtering the Restaurants**: The first step involves checking each restaurant against the provided criteria (vegetarian status, maximum price, and maximum distance). Only those that meet the criteria will be included in the results.

2. **Sorting the Results**: Once the restaurants are filtered, the next step is to sort them based on their ratings. If two restaurants have the same rating, the one with the higher ID should come first.

3. **Returning the Result**: Finally, the function returns a list of restaurant IDs that match the criteria.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        if(a[1] == b[1]) return a[0] > b[0];
        else return a[1] > b[1];
    }
```
- The `Solution` class is defined with a public method called `filterRestaurants`. Inside it, a static comparison function `cmp` is declared to facilitate sorting. This function takes two vectors representing restaurants.
- It compares the ratings (the second element of the vectors). If the ratings are equal, it sorts them by their IDs (the first element) in descending order. This ensures that higher-rated restaurants are prioritized, and in case of a tie, the restaurant with the higher ID is favored.

```cpp
    vector<int> filterRestaurants(vector<vector<int>>& rest, int veg, int mxp, int mxd) {
        vector<vector<int>> ans;
```
- The `filterRestaurants` function takes three parameters: `rest`, which is a vector of restaurant information; `veg`, which indicates whether vegetarian options are required; `mxp`, the maximum price; and `mxd`, the maximum distance.
- An empty vector `ans` is initialized to store the filtered restaurant details that meet the specified criteria.

```cpp
        for(auto r: rest) {
            if((!veg || (veg == r[2])) && r[3] <= mxp && r[4] <= mxd) {
                ans.push_back({r[0], r[1]});
            }
        }
```
- A loop iterates over each restaurant in the `rest` vector.
- The filtering condition checks:
  - If `veg` is not set (indicating vegetarian preference is not required) or matches the restaurant's vegetarian status (`r[2]`).
  - If the restaurant's price (`r[3]`) does not exceed the maximum price (`mxp`).
  - If the restaurant's distance (`r[4]`) is within the specified maximum distance (`mxd`).
- If a restaurant meets all conditions, its ID and rating (`{r[0], r[1]}`) are added to the `ans` vector.

```cpp
        sort(ans.begin(), ans.end(), cmp);
```
- After filtering, the `sort` function is called on the `ans` vector to arrange the filtered restaurants based on the criteria defined in the `cmp` function.

```cpp
        vector<int> res;
        for(auto x: ans) {
            res.push_back(x[0]);
        }
        return res;
    }
};
```
- A new vector `res` is initialized to store the IDs of the filtered and sorted restaurants.
- A loop extracts the IDs from the `ans` vector and adds them to `res`.
- Finally, the function returns the `res` vector containing the sorted restaurant IDs.

### Complexity Analysis

- **Time Complexity**: The time complexity for this solution is \(O(n \log n)\), where \(n\) is the number of restaurants in the input. This complexity arises primarily from the sorting step. The filtering operation runs in \(O(n)\) time.

- **Space Complexity**: The space complexity is \(O(n)\) due to the use of the `ans` vector that stores the filtered restaurant information. Additionally, the `res` vector for the final results contributes to the space usage.

### Conclusion
The provided solution effectively filters and sorts a list of restaurants based on specified criteria, making it a useful tool for users seeking dining options that meet their preferences. By leveraging sorting and conditional checks, the algorithm ensures that only the most relevant restaurants are returned in a prioritized manner.

This approach can be particularly beneficial in applications related to food delivery, restaurant review systems, or any platform that provides user-centric recommendations. Understanding the implementation of such filtering and sorting mechanisms can enhance one's problem-solving skills in algorithm design, especially in dealing with multi-criteria decision-making problems.

In summary, mastering techniques like this enables developers to create efficient and user-friendly applications that cater to diverse user needs, ultimately improving user experience and satisfaction.

[`Link to LeetCode Lab`](https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
