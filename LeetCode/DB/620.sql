select *
from cinema c
where id % 2 = 1 and c.description != 'boring'
order by c.rating desc