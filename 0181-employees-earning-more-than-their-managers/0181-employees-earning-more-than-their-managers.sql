# Write your MySQL query statement below
select name as Employee from Employee e where salary>(SELECT salary FROM Employee m WHERE m.id = e.managerId);