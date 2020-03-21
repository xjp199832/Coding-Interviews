// 请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

#include <iostream>
#include <cstring>
using namespace std;

//class Solution {
//public:
//	void replaceSpace(char* str, int length) {
//		if (str == nullptr || length <= 0)
//			return;
//
//		int originalLength = 0;
//		int blankCount = 0;
//		int i = 0;
//		while (str[i] != '\0')
//		{
//			originalLength++;
//
//			if (str[i] == ' ')
//				blankCount++;
//
//			i++;
//		}
//
//		int newLength = originalLength + 2 * blankCount;
//		if (newLength + 1 > length)
//			return;
//
//		int oldStrIndex = originalLength;
//		int newStrIndex = newLength;
//		while (oldStrIndex >= 0 && newStrIndex > oldStrIndex)
//		{
//			if (str[oldStrIndex] == ' ')
//			{
//				str[newStrIndex--] = '0';
//				str[newStrIndex--] = '2';
//				str[newStrIndex--] = '%';
//			}
//			else
//			{
//				str[newStrIndex--] = str[oldStrIndex];
//			}
//			--oldStrIndex;
//		}
//	}
//};



class Solution {
public:
    string replaceSpace(string s) {
        int originalLength = s.length();
        if (originalLength <= 0)
            return NULL;
        string str = "";
        for (int i = 0; i < originalLength; i++)
        {
            if (s[i] != ' ')
                str += s[i];
            else
                str += "%20";
        }
        return str;
    }
};


