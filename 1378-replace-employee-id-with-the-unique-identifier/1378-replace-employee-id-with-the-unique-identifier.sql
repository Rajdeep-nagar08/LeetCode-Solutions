# Write your MySQL query statement below


# select e1.unique_id, e2.name from EmployeeUNI e1 right join Employees e2 on e1.id=e2.id;


select e1.name, e2.unique_id from Employees e1 left join EmployeeUNI e2 on e1.id=e2.id;