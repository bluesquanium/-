# Write your MySQL query statement below
#select distinct (salary) as SecondHighestSalary
#from employee
#order by salary desc
#limit 1
#offset 1

# Solution 1
#select max(salary) as SecondHighestSalary
#from employee
#where salary < (select max(salary) from employee)

# Solution 2
select (
    case
    when count(distinct salary) <= 1 then null
    else (select salary from employee order by salary desc limit 1,1)
    end
) as SecondHighestSalary
from employee
