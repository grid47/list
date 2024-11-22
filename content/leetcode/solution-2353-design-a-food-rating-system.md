
+++
authors = ["grid47"]
title = "Leetcode 2353: Design a Food Rating System"
date = "2024-03-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2353: Design a Food Rating System in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Design","Heap (Priority Queue)","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Ikp8SgbgbEo"
youtube_upload_date="2023-12-17"
youtube_thumbnail="https://i.ytimg.com/vi/Ikp8SgbgbEo/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class FoodRatings {
    unordered_map<string, set<pair<int, string>>> cus_itm;
    unordered_map<string, string> fd_cus;
    unordered_map<string, int> fd_rat;
public:
    FoodRatings(vector<string>& fd, vector<string>& cus, vector<int>& rat) {
        int n = fd.size();
        for(int i = 0; i < n; i++) {
            cus_itm[cus[i]].insert(pair(-rat[i], fd[i]));
            fd_cus[fd[i]] = cus[i];
            fd_rat[fd[i]] = rat[i];
        }
    }
    
    void changeRating(string fd, int rat) {
        string cus = fd_cus[fd];
        int r = fd_rat[fd];
        cus_itm[cus].erase({-r, fd});
        cus_itm[cus].insert({-rat, fd});
        fd_rat[fd] = rat;
 
    }
    
    string highestRated(string cus) {
        return begin(cus_itm[cus])->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
{{< /highlight >}}
---

### Problem Statement

The problem is to design a system for tracking food ratings based on cuisine type. Given lists of food items, their respective cuisines, and initial ratings, we need to support two main operations:
1. **`changeRating`**: Change the rating of a specific food item and update its position based on the new rating.
2. **`highestRated`**: Retrieve the highest-rated food item for a specified cuisine.

### Approach

The solution uses hash maps (`unordered_map`) and an ordered set (`set`) to efficiently store and retrieve the ratings for foods by cuisine. The main design involves:
- **Mapping cuisines to foods** with ratings using a set, which keeps food items sorted by their ratings.
- **Tracking food-cuisine relationships** and **food-rating values** separately with hash maps, enabling efficient updating of ratings.
- Ensuring that food items with equal ratings are sorted lexicographically to satisfy the requirements.

### Code Breakdown (Step by Step)

#### Class Definition and Member Variables
```cpp
unordered_map<string, set<pair<int, string>>> cus_itm;
unordered_map<string, string> fd_cus;
unordered_map<string, int> fd_rat;
```
- `cus_itm`: Maps each cuisine to a set of foods, sorted by rating in descending order. Each entry in the set is a pair `(-rating, food_name)` to ensure high ratings appear first.
- `fd_cus`: Maps each food item to its cuisine, allowing quick access to a food’s cuisine.
- `fd_rat`: Maps each food item to its rating, enabling quick lookups and updates.

#### Constructor
```cpp
FoodRatings(vector<string>& fd, vector<string>& cus, vector<int>& rat) {
    int n = fd.size();
    for(int i = 0; i < n; i++) {
        cus_itm[cus[i]].insert(pair(-rat[i], fd[i]));
        fd_cus[fd[i]] = cus[i];
        fd_rat[fd[i]] = rat[i];
    }
}
```
- Initializes the `FoodRatings` object by populating the maps.  
- For each food item, the constructor:
  - Inserts `(-rating, food)` into the `cus_itm` set for the correct cuisine.
  - Updates `fd_cus` and `fd_rat` with the food’s cuisine and rating.

#### `changeRating` Method
```cpp
void changeRating(string fd, int rat) {
    string cus = fd_cus[fd];
    int r = fd_rat[fd];
    cus_itm[cus].erase({-r, fd});
    cus_itm[cus].insert({-rat, fd});
    fd_rat[fd] = rat;
}
```
- Retrieves the current cuisine and rating for the specified food.
- Removes the food with the old rating from `cus_itm[cus]`, inserts it with the new rating, and updates `fd_rat[fd]`.

#### `highestRated` Method
```cpp
string highestRated(string cus) {
    return begin(cus_itm[cus])->second;
}
```
- Retrieves and returns the food with the highest rating for the specified cuisine by accessing the first element in `cus_itm[cus]`.

### Complexity

- **Time Complexity**:
  - **Constructor**: **O(n log n)**, where `n` is the number of food items. Each insertion into `cus_itm` (a set) is **O(log n)**.
  - **changeRating**: **O(log m)**, where `m` is the number of foods within a cuisine, due to insertion and deletion in the set.
  - **highestRated**: **O(1)**, as accessing the highest-rated food item is **O(1)**.

- **Space Complexity**: **O(n)**, where `n` is the number of foods, for storing the data in the hash maps and sets.

### Conclusion

The `FoodRatings` class provides an efficient way to manage and retrieve food ratings by cuisine. By leveraging hash maps for quick lookups and an ordered set to keep foods sorted by rating, this solution achieves efficient insertion, updating, and retrieval of the highest-rated foods. This approach is suitable for real-time updates, making it ideal for applications that require frequent rating adjustments.

[`Link to LeetCode Lab`](https://leetcode.com/problems/design-a-food-rating-system/description/)

---
{{< youtube Ikp8SgbgbEo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
