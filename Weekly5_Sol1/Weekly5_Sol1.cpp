//จงเขียนโปรแกรมรับ string มา 1 ชุด แล้วหาว่าตัวอักษรใดมีจำนวนตัวมากที่สุด(Level 3)

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>						//Problem 56, Solution 1, ID Student 65010902


int store[94];          //character				!    "   #   ...    }  ~
						//index array			0    1   2   ...   92  93
						//ASCII					33  34  35   ...   125 126


bool zeroall = true;	//ใช้เช็คว่า เป็น0 หมดทุกตัวไหม


bool most = true;		// ใฃ้เฃ็คว่ามีค่ามากสุดหรือป่าว



void store_num(int j)		// function ทำหน้าที่ บวกจำนวนตัวอักษร store[]
{
	store[j - 33] += 1;
}

int main()
{
	

	char str[100];
	scanf("%s", str);


	for (int i = 0; i <= (strlen(str) - 1); i++)
	{
		for (int j = 33; j <= 126; j++)            //  !  "   #  --->  }  ~
		{
			if (str[i] == j)
			{
				store_num(j);
			}
		}
	}



	for (int x = 0; x <= 93; x++)
	{
		if (store[x] != 0)
		{
			zeroall = false;
			break;
		}
	}
	if (zeroall == true)
	{
		for (int y = 33; y <= 126; y++)
		{
			printf("%c ", y);					// กรณี = 0หมด ปริ้นทุกตัว
		}
	}


	for (int j = 0; j <= 93; j++)
	{
		if (store[j] == 0)
		{
			most = false;
		}

		else
		{
			for (int k = 0; k <= 93; k++)
			{
				if ((store[k] / store[j]) > 1)		// store[j] ไม่ได้มีมากสุด
				{
					most = false;
					break;
				}
			}

		}

		if (most == true)
		{
			printf("%c ", j + 33);
		}

		most = true;

	}
	return 0;
}