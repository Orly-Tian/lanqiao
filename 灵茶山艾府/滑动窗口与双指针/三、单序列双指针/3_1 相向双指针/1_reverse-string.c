// 反转字符串之二题
// Created by Administrator on 2024/12/26.
// https://www.bilibili.com/video/BV1dT411j7NN?spm_id_from=333.788.videopod.sections&vd_source=4c293aa27f67a76d01553a3b9517eaf3



// 344.反转字符串
// Created by Administrator on 2024/12/27.
// https://leetcode.cn/problems/reverse-string/


void reverseString(char* s, int sSize) {
    int i = 0, j = sSize - 1;
    while (i < j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++, j--;
    }
}

int main() {
    char s[5] = {'h', 'e', 'l', 'l', 'o'};
    reverseString(s, 5);
}



// 541.反转字符串2
// Created by Administrator on 2024/12/26.
// https://leetcode.cn/problems/reverse-string-ii/


char* reverseStr(char* s, int k) {
    int i = 0;
    while (i < k) {
        if (i == k - 1)


        i++;
        if (i == 2 * k)
            i = 0;
    }
}
