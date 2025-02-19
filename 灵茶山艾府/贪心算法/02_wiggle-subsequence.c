// 376.摆动序列
// Created by Administrator on 2025/2/18.
// https://leetcode.cn/problems/wiggle-subsequence/
// https://www.bilibili.com/video/BV17M411b7NS


// 代码随想录：
int wiggleMaxLength(int* nums, int numsSize) {
	if (numsSize <= 1)
		return numsSize;

	int length = 1;
	int preDiff = 0, postDiff = 0;
	for (int i = 0; i < numsSize - 1; i++) {
		postDiff = nums[i + 1] - nums[i];

		// 若preDiff与postDiff符号长度不符，则子序列长度++。更新preDiff的符号
		// 若preDiff与curDiff符号一致，当前i元素为连续升序/连续降序子序列的中间元素。不被记录入长度
		// 注：当preDiff为0时，curDiff为正或为负都属于符号不同
		if ((preDiff >= 0 && postDiff < 0) || (preDiff <= 0 && postDiff > 0)) {
			preDiff = postDiff;
			length++;
		}
	}

	return length;
}



// 第一次做：
//		通过了28/32个测试用例
// int wiggleMaxLength(int* nums, int numsSize) {
//     if (numsSize == 1)
//         return 1;
//
//     int result = 0;
//     if (numsSize >= 2) {
//         // 记录除表头表尾的中间元素的摆动数
//         for (int i = 1; i < numsSize - 1; i++) {
//             int preDiff = nums[i] - nums[i - 1];
//             int postDiff = nums[i + 1] - nums[i];
//             // 首位之外的摆动数量
//             if (preDiff * postDiff < 0)
//                 result++;
//             // 若有平坡，则一个平坡算一个摆动
//             if (preDiff != 0 && preDiff * postDiff == 0)
//                 result++;
//         }
//     }
//
//     // 若数组单调且整个数组为平坡时，返回1
//     if (result == 0 && nums[0] == nums[numsSize - 1])
//         return 1;
//     // 若数组单调且不为平坡时，返回0+2，即2
//     // 若数组有摆动有平坡，则返回中间的result值+首尾的两个摆动
//     else
//         return result + 2;
// }
//
//
// 未通过用例：[1, 0, 0]       平坡位于表头或表尾
//			预期输出：2
//			输出：3
// 未通过用例：[1, 2, 2, 3, 4]       单调有平坡
//			预期输出：2
//			输出：3

