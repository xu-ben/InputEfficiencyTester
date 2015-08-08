/*
 * win.cpp
 *
 *  Created on: 2012-9-17
 *      Author: ben
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

/**
 * 在ACM竞赛中，核心的是算法的优化。但有的时候，一些算法
 * 外的细节，也会对是否通过题目有所影响。程序的输入输出
 * 方法即是一例。通常，使用scanf函数会比使用cin输入快很
 * 多，但是使用下面的输入外挂，将会比scanf函数更快，原因
 * 是scanf中有许多额外的、关于健壮性的处理和判断。作者在
 * 多台pc机上，g++3.4.5环境中进行对比测试，发现以下函数
 * 比scanf快了5~10倍，比cin快了近100倍。
 */
int get_int2() {
	int res = 0, ch, flag = 0;
	while (!((ch = getchar()) >= '0' && ch <= '9')) {
		if (ch == '-')
			flag = 1;
		if (ch == EOF)
			return 1 << 30;
	}
	res = ch - '0';
	while ((ch = getchar()) >= '0' && ch <= '9')
		res = res * 10 + (ch - '0');
	if (flag == 1)
		res = -res;
	return res;
}

bool get_str(char *str) {
	char c;
	while ((c = getchar()) <= ' ') {
		if(c == EOF) {
			return false;
		}
	}
	int I = 0;
	while (c > ' ') {
		str[I++] = c;
		c = getchar();
	}
	str[I] = 0;
	return true;
}

int main2() {
	freopen("data.in", "w", stdout);
	int a, b;
	for(int i = 0; i < 100000; i++) {
		a = rand();
		b = rand();
		printf("%d %d\n", a, b);
	}
	return 0;
}

void randstr(char *str) {
	int len = rand() % 40 + 1;
	int t;
	for(int i = 0; i < len; i++) {
		t = rand() % 94;
		str[i] = (char)('!' + t);
	}
	str[len] = 0;
}

int main100() {
	freopen("str.in", "w", stdout);
	char str[300];
	for(int i = 0; i < 100000; i++) {
		randstr(str);
		printf("%s ", str);
		randstr(str);
		printf("%s\n", str);
	}
	return 0;
}

void work0() {
	int a, b;
	for(int i = 0; i < 100000; i++) {
		cin>>a>>b;
	}
}

void work1() {
	int a, b;
	for(int i = 0; i < 100000; i++) {
		scanf("%d%d", &a, &b);
//	while(scanf("%d%d", &a, &b) == 2) {
//		printf("%d\n", a + b);
	}
}

void work2() {
	int a, b;
	for(int i = 0; i < 100000; i++) {
		a = get_int2();
		b = get_int2();
//		printf("%d\n", a + b);
	}
}

void work3() {
	char str1[200],  str2[200];
	for(int i = 0; i < 100000; i++) {
		cin>>str1>>str2;
	}
}

void work4() {
	char str1[200], str2[200];
	for(int i = 0; i < 100000; i++) {
		scanf("%s%s", str1, str2);
//		puts(str1);
//		puts(str2);
	}
}

void work5() {
	char str1[200], str2[200];
	for(int i = 0; i < 100000; i++) {
		get_str(str1);
		get_str(str2);
//		scanf("%s%s", str1, str2);
//		puts(str1);
//		puts(str2);
	}
}


int main() {
	freopen("str.in", "r", stdin);
	long t = clock();
	work4();
	t = clock() - t;
	printf("time = %ld ms.\n", t);
	return 0;
}

int main0() {
	freopen("data.in", "r", stdin);
	long t1 = clock();
	work2();
	long t2 = clock();
	printf("%ld\n", t2 - t1);
//	work2();
//	long t3 = clock();
//	printf("%ld\n", t2 - t1);

//	printf("time1 = %ldms.\ntime2 = %ldms.\n", t2 - t1, t3 - t2);
	return 0;
}

