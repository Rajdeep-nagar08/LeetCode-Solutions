# Write your MySQL query statement below



select t.employee_id 
from 
(select * from Employees left join Salaries USING(employee_id)
UNION 
select* from Employees right join Salaries USING(employee_id)) 
as t 
where t.name is NULL or t.salary is NULL 
order by employee_id;