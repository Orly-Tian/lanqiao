# 1.两数之和
# Created by Administrator on 2025/1/1.
# https://leetcode.cn/problems/two-sum/



# leetcode官方题解:
#       (暴力枚举)
class Solution:
    # self代表类的实例本身,用于访问本实例下的属性或其他方法
    # nums:List[int]是一个类型注解,表示nums参数为一个整型列表
    # target是另一个类型注解,表示target参数为一个整型变量
    # -> List[int]表示为一个返回类型注解,代表该方法应返回一个整型列表
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        for i in range(0, n):
            for j in range(i + 1, n):
                if nums[i] + nums[j] == target:
                    return [i, j]
        return []



# 第一版:
#       (暴力枚举)
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(0, len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    result = [i, j]
        return result

