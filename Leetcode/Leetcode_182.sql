# 查找重复的电子邮箱
select email
from Person
group by email having count(email) > 1