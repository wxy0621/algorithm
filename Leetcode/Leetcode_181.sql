# 超过经理收入的员工
# Solution
select e1.Name as Employee
from Employee e1, Employee e2
where e1.ManagerId = e2.Id
and e1.Salary > e2.Salary

# Solution2
select e1.Name as Employee
from Employee e1
where Salary > (select Salary from Employee where Id = e1.ManagerId)