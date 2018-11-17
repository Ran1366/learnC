#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	/*日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个
		嫌疑犯的一个。以下为4个嫌疑犯的供词。
		A说：不是我。
		B说：是C。
		C说：是D。
		D说：C在胡说
		已知3个人说了真话，1个人说的是假话。
		现在请根据这些信息，写一个程序来确定到底谁是凶手。*/
	int s[4];
	int num = 0;
	int muder = 0;
	for (s[0] = 0 ; s[0] < 2 ; s[0]++)
	{
		for (s[1] = 0; s[1] < 2; s[1]++)
		{
			for (s[2] = 0; s[2] < 2; s[2]++)
			{
				for (s[3] = 0; s[3] < 2; s[3]++)
				{
					if (((s[0] == 0) + (s[2] == 1) + (s[3] == 1) + (s[3] == 0)) == 3)
					{
						if ((s[0] + s[1] + s[2] + s[3]) == 1 )
						{
							for (int i = 0 ; i < 4 ; i++)
							{
								if (s[i] == 1)
								{
									printf("%c是凶手！\n",i+65);
								}
							}
						}
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}