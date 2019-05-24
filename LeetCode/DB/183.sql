/*
select c.name as Customers
from customers c
left join orders o on c.id = o.customerid
where o.customerId is null
*/

select c.name as Customers
from customers c
where c.id not in (select o.customerId from orders o)