# Write your MySQL query statement below

SELECT w.name as warehouse_name, SUM(w.units * p.length * p.height * p.width) as volume  FROM Warehouse w JOIN 
Products p ON w.product_id = p.product_id GROUP BY w.name