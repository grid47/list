# Write your MySQL query statement below
SELECT class
FROM
        (SELECT class, COUNT(DISTINCT student) AS num 
        FROM Courses
        GROUP BY class) AS TEMP
WHERE num >= 5;