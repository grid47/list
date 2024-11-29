
+++
authors = ["grid47"]
title = "Leetcode 2512: Reward Top K Students"
date = "2024-02-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2512: Reward Top K Students in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "-ZE6ZmNU6KQ"
youtube_upload_date="2022-12-24"
youtube_thumbnail="https://i.ytimg.com/vi_webp/-ZE6ZmNU6KQ/maxresdefault.webp"
comments = true
+++



---
You are given two lists of words: one representing positive feedback and the other representing negative feedback. Each feedback word affects a student's points: a positive word adds 3 points, while a negative word subtracts 1 point. For each feedback report, which is associated with a student, calculate the total score by counting the occurrences of positive and negative words. After evaluating all reports, return the top k students based on their total points. In case of a tie in points, the student with the lower ID should rank higher.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given the following inputs: 
- `positive_feedback`: A list of words indicating positive feedback.
- `negative_feedback`: A list of words indicating negative feedback.
- `report`: A list of feedback reports for students.
- `student_id`: A list of student IDs corresponding to each report.
- `k`: An integer specifying how many top students to return based on their scores.
- **Example:** `positive_feedback = ["creative", "enthusiastic", "hardworking"], negative_feedback = ["lazy"], report = ["the student is hardworking and lazy", "the student is creative and enthusiastic"], student_id = [1, 2], k = 2`
- **Constraints:**
	- 1 <= positive_feedback.length, negative_feedback.length <= 10^4
	- 1 <= report[i].length <= 100
	- 1 <= student_id[i] <= 10^9
	- 1 <= k <= n

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the top k student IDs ranked by their points. If multiple students have the same points, return the one with the lower student ID first.
- **Example:** `[2, 1]`
- **Constraints:**
	- Return the IDs of the top k students.

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the total score for each student based on the feedback words, sort them in descending order by score, and then return the top k students.

- 1. Initialize sets for positive and negative feedback words.
- 2. Loop through each report and calculate the score for each student by checking the occurrence of positive and negative words.
- 3. Use a priority queue to sort the students by their scores in descending order, prioritizing lower IDs in case of a tie.
- 4. Extract the IDs of the top k students from the priority queue.
{{< dots >}}
### Problem Assumptions ✅
- All student IDs are unique.
- Words in the report are separated by a single space.
- There are no overlapping words between the positive and negative feedback lists.
{{< dots >}}
## Examples 🧩
- **Input:** `positive_feedback = ["smart","brilliant","studious"], negative_feedback = ["not"], report = ["this student is studious", "the student is smart"], student_id = [1, 2], k = 2`  \
  **Explanation:** In this case, both students have the same number of positive feedback (3 points), but since student 1 has a lower ID, he ranks higher. The output is [1, 2].

- **Input:** `positive_feedback = ["smart","brilliant","studious"], negative_feedback = ["not"], report = ["this student is not studious", "the student is smart"], student_id = [1, 2], k = 2`  \
  **Explanation:** Student 1 has 3 points (1 positive, 1 negative), while student 2 has 3 points (1 positive). Since student 2 has more points, the output is [2, 1].

{{< dots >}}
## Approach 🚀
To solve the problem, we iterate over the feedback reports, calculate the points for each student based on the occurrence of positive and negative words, and then rank them in descending order of their points. The solution utilizes a priority queue to efficiently sort the students and handle ties.

### Initial Thoughts 💭
- The positive and negative feedback words can be stored in sets for quick lookup.
- We need to consider both positive and negative feedback for each report.
- We can use a priority queue to handle the sorting of students and ensure that the lowest ID student ranks higher in case of ties.
{{< dots >}}
### Edge Cases 🌐
- If either positive_feedback or negative_feedback is empty, the solution should still work by handling the absence of words in the feedback reports.
- If there are a large number of students or reports, the solution should be optimized to handle large inputs efficiently.
- Ensure that the solution handles cases where students have equal points but different IDs.
- Handle edge cases where n = 1 or k = 1, ensuring that the solution works for small input sizes.
{{< dots >}}
## Code 💻
```cpp
vector<int> topStudents(vector<string>& pos, vector<string>& neg, vector<string>& report, vector<int>& id, int k) {
    set<string> p, n;
    for(auto it: pos) {
        p.insert(it);
    }
    for(auto it: neg) {
        n.insert(it);
    }
    
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    
    int sz = report.size();
    for(int i = 0; i < sz; i++) {
        string s = report[i];
        int prv = 0;
        int sum = 0;
        for(int j = 0; j < s.size(); j++) {
            if(s[j] == ' ' || j == s.size() - 1) {
                string str = s.substr(prv, (j == s.size() - 1? s.size(): j) - prv);
                // cout << str << " ";
                prv = j + 1;
                if(p.count(str)) sum += 3;
                if(n.count(str)) sum -= 1;
            }
        }
        // cout << sum << " " << id[i] << "\n";
        pq.push({sum, id[i]});
    }
    cout << "\n";
    vector<int> ans;
    while(!pq.empty() && k--) {
        cout << pq.top()[0] << " " << pq.top()[1] << "\n";
        ans.push_back(pq.top()[1]);
        pq.pop();
    }
    return ans;
}
```

The `topStudents` function calculates the top `k` students based on a report of positive and negative feedback words. Students are rewarded or penalized based on the occurrence of these words in their report, and the final result returns the top `k` students ordered by their score.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> topStudents(vector<string>& pos, vector<string>& neg, vector<string>& report, vector<int>& id, int k) {
	```
	Defines the `topStudents` function, which takes in five parameters: a list of positive words `pos`, a list of negative words `neg`, the student reports `report`, student ids `id`, and the integer `k` which determines how many top students to return.

2. **Set Initialization**
	```cpp
	    set<string> p, n;
	```
	Initializes two sets, `p` and `n`, to store the positive and negative words respectively.

3. **Set Population**
	```cpp
	    for(auto it: pos) {
	```
	Iterates through the list of positive words `pos` and adds each word to the set `p`.

4. **Set Population**
	```cpp
	        p.insert(it);
	```
	Inserts each positive word into the set `p`.

5. **Set Population**
	```cpp
	    for(auto it: neg) {
	```
	Iterates through the list of negative words `neg` and adds each word to the set `n`.

6. **Set Population**
	```cpp
	        n.insert(it);
	```
	Inserts each negative word into the set `n`.

7. **Priority Queue Initialization**
	```cpp
	    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
	```
	Initializes a priority queue `pq` to store the students' scores and ids, ordered by their scores using a custom comparator `cmp`.

8. **Size Calculation**
	```cpp
	    int sz = report.size();
	```
	Calculates the size of the `report` vector, which corresponds to the number of students.

9. **Loop Structure**
	```cpp
	    for(int i = 0; i < sz; i++) {
	```
	Starts a loop to iterate over each student report.

10. **Variable Initialization**
	```cpp
	        string s = report[i];
	```
	Stores the current student's report (a string) in the variable `s`.

11. **Variable Initialization**
	```cpp
	        int prv = 0;
	```
	Initializes a variable `prv` to track the position of the previous space in the report for word extraction.

12. **Variable Initialization**
	```cpp
	        int sum = 0;
	```
	Initializes a variable `sum` to accumulate the student's score based on positive and negative words.

13. **Word Extraction Loop**
	```cpp
	        for(int j = 0; j < s.size(); j++) {
	```
	Starts a loop to iterate over each character in the student's report string `s`.

14. **Character Check**
	```cpp
	            if(s[j] == ' ' || j == s.size() - 1) {
	```
	Checks if the current character is a space or if it's the last character in the string to extract a word.

15. **Word Extraction**
	```cpp
	                string str = s.substr(prv, (j == s.size() - 1? s.size(): j) - prv);
	```
	Extracts the current word from the report string `s` using `substr` and stores it in `str`.

16. **Word Extraction**
	```cpp
	                prv = j + 1;
	```
	Updates `prv` to the position of the next character after the space or the last character in the string.

17. **Score Calculation**
	```cpp
	                if(p.count(str)) sum += 3;
	```
	If the word is found in the positive set `p`, it adds 3 points to the `sum`.

18. **Score Calculation**
	```cpp
	                if(n.count(str)) sum -= 1;
	```
	If the word is found in the negative set `n`, it subtracts 1 point from the `sum`.

19. **Priority Queue Insertion**
	```cpp
	        pq.push({sum, id[i]});
	```
	Pushes a pair of the calculated score `sum` and the student's id into the priority queue `pq`.

20. **Result Initialization**
	```cpp
	    vector<int> ans;
	```
	Initializes a vector `ans` to store the ids of the top `k` students.

21. **Priority Queue Processing**
	```cpp
	    while(!pq.empty() && k--) {
	```
	Starts a while loop to process the priority queue `pq` and extract the top `k` students.

22. **Priority Queue Processing**
	```cpp
	        cout << pq.top()[0] << " " << pq.top()[1] << "\n";
	```
	Outputs the score and id of the top student in the priority queue.

23. **Result Population**
	```cpp
	        ans.push_back(pq.top()[1]);
	```
	Adds the id of the top student to the result vector `ans`.

24. **Priority Queue Processing**
	```cpp
	        pq.pop();
	```
	Removes the top student from the priority queue `pq`.

25. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the vector `ans` containing the ids of the top `k` students.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n) - The best case occurs when there is minimal feedback, but sorting still takes O(n log n) time.
- **Average Case:** O(n log n) - The average case involves iterating over the reports and sorting the students, which takes O(n log n) time.
- **Worst Case:** O(n log n) - In the worst case, the solution needs to iterate over all feedback reports and sort the students, resulting in O(n log n) time complexity.

The time complexity is driven by the sorting step, which dominates the calculation of scores.

### Space Complexity 💾
- **Best Case:** O(n) - The space complexity remains O(n) in the best case, where only a small number of students and reports are processed.
- **Worst Case:** O(n) - The space complexity is dominated by the storage of feedback reports and the priority queue.

The space complexity is influenced by the need to store feedback reports and student scores.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/reward-top-k-students/description/)

---
{{< youtube -ZE6ZmNU6KQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
