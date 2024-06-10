#pragma once
/*1. Tower of hanoi recursively*/
/*
Time complexity : O(2^n)
wrost case complextity : 2^n-1
*/
void toh(int disk, char source, char temp, char destination) {
	if (disk == 1) {
		printf("Move : disk %d from %c to %c\n",disk,source,destination);
		return;
	}
	toh(disk-1,source,destination,temp);
	printf("Move : disk %d from %c to %c\n", disk, source, destination);
	toh(disk - 1, destination,temp ,source);
}
/*2. find array is sorted or not recursively*/
/*
Time complexity: O(n)
Space complexity: O(n) for recursive stack space
*/
int isAsorted(int* arr, int length) {
	if (length == 1)return 1;
	return arr[length - 1] < arr[length - 2] && isAsorted(arr, length - 1);
}
int isDsorted(int* arr, int length) {
	if (length == 1)return 1;
	return arr[length - 1] > arr[length - 2] && isDsorted(arr, length - 1);
}
/**/

float Q_rsqrt(float number){
	float x2 = number * 0.5F;
	float y = number;
	long i = *(long*)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float*)&i;
	for(int i = 0; i < 5;i++)
		y = y * (1.5F - (x2 * y * y));
	return y;
}