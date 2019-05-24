# Write your MySQL query statement below

select distinct p.Email as Email
from person p
inner join person p2 on p.email = p2.email
where p.id != p2.id