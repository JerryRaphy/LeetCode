# Write your MySQL query statement below

SELECT DISTINCT(a.num) as ConsecutiveNums
FROM Logs a JOIN Logs b ON
b.id = a.id + 1 AND a.num = b.num
JOIN
Logs c ON c.id = a.id + 2 AND a.num = c.num;