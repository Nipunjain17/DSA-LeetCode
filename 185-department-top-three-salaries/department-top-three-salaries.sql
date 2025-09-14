# Write your MySQL query statement below

SELECT d.name Department, e.name Employee, e.salary Salary
FROM Department AS d, Employee AS e
WHERE e.departmentId = d.id AND 
(SELECT COUNT(DISTINCT salary) FROM Employee
WHERE salary>e.salary AND departmentId = e.departmentId)<3
ORDER BY d.name , e.salary DESC;
