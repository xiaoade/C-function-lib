#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>

void exd(int* a, int* b) //交换两个整形值
{
	int t = *a;
	*a = *b;
	*b = t;
}

void exf(float* a, float* b) //交换两个浮点类型值
{
	float t = *a;
	*a = *b;
	*b = t;
}

void showchar(int n, char c) //显示字符n次
{
	for (int i = 0; i < n; i++)
		putchar(c);
}

int dsum(int a[], int n) //对一个整型数组求和
{
	int sum = 0;
	for (; n > 0; n--)
		sum += a[n - 1];
	return sum;
}

float fsum(float a[], int n) //对一个浮点型数组求和
{
	float sum = 0;
	for (; n > 0; n--)
		sum += a[n - 1];
	return sum;
}

int dmi(int a, int n) //整数的n次方
{
	int r = 1;
	for (; n > 0; n--)
		r *= a;
	return r;
}

float fmi(float a, int n) //浮点数的n次方
{
	float r = 1;
	for (; n > 0; n--)
		r *= a;
	return r;
}

int dfac(int d) //d的阶乘
{
	int r = 1;
	for (; d > 1; d--)
		r *= d;
	return r;
}

long double pi(float m) //估算圆周率，m为精度
{
	int sgn = 1;
	long double d = 1, pi4 = 0, t;
	do
	{
		t = 1.0 / d;
		pi4 += t * sgn;
		d += 2;
		sgn = -sgn;
	} while (t > m);
	return 4 * pi4;
}

long double e1(float m) //估算自然对数，m为精度
{
	int c = 1;
	long double e = 1, j = 1, d;
	do
	{
		j *= c;
		d = 1 / j;
		e += d;
		c++;
	} while (d > m);
	return e;
}

bool pn(int n) //判断一个数是否为素数
{
	if (n == 2)
		return true;
	if (n < 2)
		return false;
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return false;
	return true;
}

bool check_date(int yyyy, int mm, int dd, bool outputerr) //检查一个日期是否合法，并给出错误提示（可选）
{
	int err = 0, mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (((yyyy % 4 == 0) && (yyyy % 100 != 0)) || (yyyy % 400 == 0))
		mon[1]++;
	if (mm > 12 || mm < 1)
	{
		if (outputerr == true)
			printf("The MONTH must be between 1 and 12!\nMONTH\"%d\" is not legal!", mm);
		if (dd < 1 || dd>31)
			if (outputerr == true)
				printf("The DAY must be between 1 and 31!\nDAY\"%d\" is not legal!", dd);
		return false;
	}
	if (dd<1 || dd>mon[mm - 1])
	{
		if (outputerr == true)
			printf("The DAY must be between 1 and %d!\nDAY\"%d\" is not legal!", mon[mm - 1], dd);
		return false;
	}
	return true;
}

bool check_time(int hh, int mm, int ss, bool outputerr) //检查一个时间是否合法，并给出错误提示（可选）
{
	int err = 0;
	if (hh < 0 || hh>23)
	{
		err++;
		if (outputerr == true)
			printf("The HOUR must be between 0 and 24.\nHOUR \"%d\" is not legal!", hh);
	}
	if (mm < 0 && mm>60)
	{
		err++;
		if (outputerr == true)
			printf("The MINUTE must be between 0 and 59.\nMINUTE \"%d\" is not legal!", mm);
	}
	if (ss < 0 && ss>60)
	{
		err++;
		if (outputerr == true)
			printf("The SECOND must be between 0 and 59.\nSECOND \"%d\" is not legal!", ss);
	}
	return err;
}

void dpx(int a[], int n, bool up) //整型数组升降序排列（冒泡）
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (up == true)
				if (a[i] > a[j])
					exd(a + i, a + j);
			if (up == false)
				if (a[i] < a[j])
					exd(a + i, a + j);
		}
}

void fpx(float a[], int n, bool up) //浮点类型数组升降序排列（冒泡）
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (up == true)
				if (a[i] > a[j])
					exf(a + i, a + j);
			if (up == false)
				if (a[i] < a[j])
					exf(a + i, a + j);
		}
}

char get_first(void) //取输入列中的第一个字符
{
	char ch = getchar();
	while (getchar() != '\n')
		continue;
	return ch;
}

char* s_gets(char* st, int n) //改进型字符串输入函数
{
	char* ret_val, * find;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}

int* dArr(int n) //创建一个长度为n的int类型的数组
{return (int*)malloc(n * sizeof(int));}

long* ldArr(int n) //创建一个长度为n的int类型的数组
{return (long*)malloc(n * sizeof(long));}

long long* lldArr(int n) //创建一个长度为n的int类型的数组
{return (long long*)malloc(n * sizeof(long long));}

float* fArr(int n) //创建一个长度为n的int类型的数组
{return (float*)malloc(n * sizeof(float));}

double* lfArr(int n) //创建一个长度为n的int类型的数组
{return (double*)malloc(n * sizeof(double));}

long double* llfArr(int n) //创建一个长度为n的int类型的数组
{return (long double*)malloc(n * sizeof(long double));}
