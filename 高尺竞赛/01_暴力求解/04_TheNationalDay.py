from datetime import *


# 日期类题目，使用Python调用内置模块datetime

a = date(1949, 10, 1)
b = date(2012, 10, 1)

count = 0
while a <= b:
    if a.weekday() == 6 and a.month == 10 and a.day == 1:
        count += 1
    a += timedelta(1)
  
print(count)


