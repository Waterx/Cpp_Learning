#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define cutoff 3
FILE* fp;

void Swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}
int Median3(int A[], int Left, int Right) {
	int Center = (Left + Right) / 2;
	//以下三个if可以实现小到大排序
	if (A[Left] > A[Center]) {
		Swap(A[Left], A[Center]);
	}
	if (A[Left] > A[Right]) {
		Swap(A[Left], A[Right]);
	}
	if (A[Right] < A[Center]) {
		Swap(A[Right], A[Center]);
	}

	//把枢纽元放到Right-1的位置“隐藏”
	Swap(A[Center], A[Right - 1]);
	return A[Right - 1];
}

void Qsort(int A[], int Left, int Right) {

}

void QuickSort(int A[], int N) {
	Qsort(A, 0, N - 1);
}

// 插入排序，处理N<20时比快速排序快，处理小数组排序
void InsertionSort(int A[], int N) {
	int i, j, tmp;
	for (i = 1; i < N; i++) {
		tmp = A[i];
		j = i ;
		while (tmp < A[j - 1]) {
			A[j] = A[j - 1];//vs与gcc在这里处理机制不同，不用--稳一些
			j--;
			if (j == 0) break;
		}
		Swap(A[j], tmp);

	}
}



int main() {

	//设置计时开始
	double duration;
	clock_t  finish, start;
	start = clock();

	//------以下实现了一行行读取数据-------
	int array[2000];
	int i = 0;
	fp = fopen("data.txt", "r");
	char line[10];
	while (fgets(line, sizeof(line), fp)) {
		printf("%s", line);//把元素输出到屏幕上
		array[i++] = atoi(line);
	}
	fclose(fp);

	//运行快速排序
	InsertionSort(array, 2000);
	//QuickSort(array, 2000);

	//设置计时结束
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;  // 统计时间duration
	printf("\nThe CPU time is %2.6f seconds:\n", duration);

	//输出结果到文件resultsMS.txt
	fp = fopen("resultsMS.txt", "w+");
	fprintf(fp, "TimeMS = %f\n", duration);
	for (i = 0; i < 2000; i++) {
		fprintf(fp, "%d\n", array[i]);
		printf("%d\n", array[i]);
	}
	return 0;

}