//题目描述
//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
//输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
//例如数组{ 3,4,5,1,2 }为{ 1,2,3,4,5 }的一个旋转，该数组的最小值为1。
//NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

#include<vector>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& rotateArray) {
        if (rotateArray.size() <= 0)
            return 0;

        int index1 = 0;
        int index2 = rotateArray.size() - 1;
        int midIndex = index1;

        while (index1 < index2)
        {
            midIndex = index1 + (index2 - index1) / 2;
            if (rotateArray[midIndex] < rotateArray[index2])
                index2 = midIndex;
            else if (rotateArray[midIndex] > rotateArray[index2])
                index1 = midIndex + 1;
            else
                index2--;
        }
        return rotateArray[index1];
    }
};