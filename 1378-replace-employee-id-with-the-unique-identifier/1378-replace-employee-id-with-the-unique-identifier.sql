# Write your MySQL query statement below

SELECT u.unique_id, name from Employees e LEFT JOIN EmployeeUNI u
on e.id = u.id;