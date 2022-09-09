# 从不订购的客户
select Name as Customers
from Customers
left join Orders
on Customers.Id = Orders.CustomerId
where Orders.Id is null;