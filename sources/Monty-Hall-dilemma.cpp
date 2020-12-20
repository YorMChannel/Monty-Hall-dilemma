#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool executeExp(int i);
bool hasInt(int* door, int n);

double success = 0, failed = 0;

int main() {
	srand(time(NULL));
	int n;
	printf("��ƼȦ ������ ������ �� �� �������� �Է����ּ���. : ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		executeExp(i);
	}
	printf("��� : %.2lf%%", success / (success + failed) * 100);
	scanf("%d", n);
}

bool executeExp(int i) {
	int door[3] = { 0, };
	int rand1 = rand() % 3, select = rand() % 3;
	door[rand1] = 1;

	printf("%d�� ", i + 1);

	for (int i = 0; i < 3; i++) { //�� ���� �����ֱ�
		if (door[i] == 1) {
			printf("��");
			continue;
		}
		printf("��");
	}

	door[select] = -1;

	printf("     ");
	for (int i = 0; i < 3; i++) { //�����Ѱ� �����ֱ�
		if (i == select) {
			printf("��");
			continue;
		}
		if (door[i] == 1) {
			printf("��");
			continue;
		}
		printf("��");
	}

	for (int i = 0; i < 3; i++) { //�� �����ֱ�
		if (door[i] == 0 && i != select) {
			door[i] == -1;
			break;
		}
	}

	if (hasInt(door, 1)) { //��� ����
		success++;
		printf("     ����\n");
		return true;
	}
	failed++;
	printf("     ����\n");
	return false;
}

bool hasInt(int* door, int n) {
	for (int i = 0; i < 3; i++) {
		if (door[i] == n) {
			return true;
		}
	}
	return false;
}