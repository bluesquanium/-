# Write your MySQL query statement below

#Solution1
#select e.name as Employee
#from employee e, employee e2
#where e2.id = e.managerid and e.salary > e2.salary

#Solution2
select e.name Employee
from employee e
inner join employee e2 on e.managerid = e2.id
where e.salary > e2.salary