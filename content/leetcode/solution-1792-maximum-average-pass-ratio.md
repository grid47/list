
+++
authors = ["grid47"]
title = "Leetcode 1792: Maximum Average Pass Ratio"
date = "2024-05-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1792: Maximum Average Pass Ratio in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ZjydWQCVg80"
youtube_upload_date="2021-03-14"
youtube_thumbnail="https://i.ytimg.com/vi/ZjydWQCVg80/maxresdefault.jpg"
comments = true
+++



---
A school has several classes, and each class will have students taking a final exam. You are provided with a 2D array where each class is represented by two values: the number of students who will pass and the total number of students in the class. Additionally, a number of brilliant students, 'extraStudents,' is provided. These brilliant students are guaranteed to pass if assigned to any class. The goal is to assign these extra students to maximize the average pass ratio of all classes. The pass ratio of a class is defined as the number of students passing divided by the total number of students in the class. You need to return the maximum possible average pass ratio after optimally distributing the extra students.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a 2D array classes where each element classes[i] = [passi, totali], representing the number of students passing and the total number of students in the ith class. You are also given an integer extraStudents representing the number of extra students who can be assigned to any class to help improve the pass ratio.
- **Example:** `Input: classes = [[2, 5], [3, 6], [4, 8]], extraStudents = 3`
- **Constraints:**
	- 1 <= classes.length <= 10^5
	- classes[i].length == 2
	- 1 <= passi <= totali <= 10^5
	- 1 <= extraStudents <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum possible average pass ratio after optimally assigning the extra students.
- **Example:** `Output: 0.72345`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Maximize the average pass ratio by optimally assigning extra students to classes.

- Calculate the initial pass ratio for each class.
- For each class, compute the potential gain in the pass ratio if one extra student is assigned.
- Use a priority queue to always assign extra students to the class with the highest potential gain in pass ratio.
- Repeat the process until all extra students are assigned.
- Return the average of the new pass ratios across all classes.
{{< dots >}}
### Problem Assumptions ✅
- All classes have a valid number of students, and the input data follows the format specified.
{{< dots >}}
## Examples 🧩
- **Input:** `classes = [[2, 5], [3, 6], [4, 8]], extraStudents = 3`  \
  **Explanation:** In this case, we can assign the extra students to the classes with the lowest initial pass ratios to maximize the average pass ratio.

- **Input:** `classes = [[1, 2], [3, 5], [2, 2]], extraStudents = 2`  \
  **Explanation:** Assigning the extra students to the first class will result in the highest increase in pass ratio.

{{< dots >}}
## Approach 🚀
To solve the problem, we need to assign the extra students to classes in a way that maximizes the overall average pass ratio. We can achieve this by calculating the potential gain for each class when an extra student is assigned and prioritizing classes that have the largest potential gain.

### Initial Thoughts 💭
- Each class has a different starting pass ratio.
- The potential improvement in pass ratio is greatest for classes with the lowest initial ratios.
- We need to calculate the gain from assigning extra students to each class and use a priority queue to select the class that would benefit the most from receiving an extra student.
{{< dots >}}
### Edge Cases 🌐
- Empty input is not possible as per the problem constraints.
- The solution should be efficient enough to handle up to 10^5 classes and extra students.
- The classes and extra students are always within the specified constraints, so no special handling for negative values is needed.
- Classes will have at least one student, and the total students in each class will not exceed 10^5.
{{< dots >}}
## Code 💻
```cpp
double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    auto profit = [&](double pass, double total) {
        return (pass + 1)/(total +1) -(pass/ total);
    };

    double total = 0;
    priority_queue<pair<double, array<int, 2>>> pq;
    for(auto &c: classes) {
        total += (double) c[0]/c[1];
        pq.push({profit(c[0], c[1]), {c[0], c[1]}});
    }

    while(extraStudents--) {
        auto [addedProfit, c] = pq.top(); pq.pop();
        total += addedProfit;
        pq.push({profit(c[0] + 1, c[1] + 1), {c[0] +1, c[1] +1}});
    }
    return total/ classes.size();
}
```

This function calculates the maximum possible average ratio of students passing after distributing extra students to the classes in a way that maximizes the ratio. It uses a greedy approach with a priority queue to distribute extra students based on the most beneficial class.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
	```
	Define the function `maxAverageRatio` that takes a reference to a 2D vector `classes` and an integer `extraStudents`. The function returns a `double` representing the maximum average ratio of passing students after distributing the extra students.

2. **Lambda Function Definition**
	```cpp
	    auto profit = [&](double pass, double total) {
	```
	Define a lambda function `profit` that calculates the improvement in the passing ratio when one extra student is added to a class. The improvement is computed using the formula `(pass + 1)/(total + 1) - (pass/total)`.

3. **Profit Calculation**
	```cpp
	        return (pass + 1)/(total + 1) - (pass / total);
	```
	This line returns the profit of adding one extra student to the class, calculated by comparing the new passing ratio to the original ratio.

4. **Variable Initialization**
	```cpp
	    double total = 0;
	```
	Initialize a variable `total` to accumulate the total passing ratio for all classes.

5. **Priority Queue Definition**
	```cpp
	    priority_queue<pair<double, array<int, 2>>> pq;
	```
	Define a priority queue `pq` that will store pairs of profit values and class data (the number of passing and total students) to prioritize the classes that benefit the most from extra students.

6. **Loop Over Classes**
	```cpp
	    for(auto &c: classes) {
	```
	Iterate over each class in the `classes` vector to calculate the initial passing ratio and store the profit of adding one student to each class.

7. **Total Passing Ratio Calculation**
	```cpp
	        total += (double) c[0]/c[1];
	```
	Add the passing ratio for each class to the `total`. This is calculated by dividing the number of passing students `c[0]` by the total number of students `c[1]`.

8. **Push to Priority Queue**
	```cpp
	        pq.push({profit(c[0], c[1]), {c[0], c[1]}});
	```
	Push the calculated profit and the class data (number of passing and total students) to the priority queue.

9. **While Loop for Extra Students**
	```cpp
	    while(extraStudents--) {
	```
	Start a while loop that runs `extraStudents` times to distribute the extra students to the classes.

10. **Top Priority Class**
	```cpp
	        auto [addedProfit, c] = pq.top(); pq.pop();
	```
	Get the class with the highest potential profit from adding an extra student, remove it from the priority queue.

11. **Update Total**
	```cpp
	        total += addedProfit;
	```
	Update the `total` passing ratio by adding the profit of the class that received an extra student.

12. **Push Updated Class to Queue**
	```cpp
	        pq.push({profit(c[0] + 1, c[1] + 1), {c[0] + 1, c[1] + 1}});
	```
	Push the updated class data (after adding one extra student) along with the new profit to the priority queue.

13. **Final Return**
	```cpp
	    return total / classes.size();
	```
	Return the average passing ratio after distributing all extra students, calculated by dividing the total passing ratio by the number of classes.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n), where n is the number of classes, as we perform operations related to the priority queue for each class and extra student.
- **Average Case:** O(n log n), as the time complexity will depend on the number of classes and extra students.
- **Worst Case:** O(n log n), due to the priority queue operations.

The algorithm primarily depends on sorting and heap operations which take O(log n) time, making the overall complexity O(n log n).

### Space Complexity 💾
- **Best Case:** O(n), since we must store all classes in memory at once.
- **Worst Case:** O(n), as we need space to store the classes and the priority queue.

The space complexity is linear due to the storage of classes and the priority queue.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-average-pass-ratio/description/)

---
{{< youtube ZjydWQCVg80 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
