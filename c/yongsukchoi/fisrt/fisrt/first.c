#include <stdio.h>
// �Ʒ��� second_function() �� ����ϱ� ���� ��� ������ include �Ͽ����ϴ�.
#include "second.h"
#include "fourth.h"

int main(void) {
	// printf�� �� �״�� �Ұ�ȣ ���ο� �ִ� ���ڿ��� ����մϴ�.
	// ���ڿ��� "" (�ֵ���ǥ) ���̿� ������ ����ִ� �������� �����˴ϴ�.
	// '\n' �� ���� ���� (����) �� ������ �����մϴ�.
	printf("Hello First C Programming!\n");

	// second_function �� ��° �۾��̴ٶ�� �ǹ̷� �ۼ��Ͽ���
	// �ܺο� �ִ� �Լ��� ����� ���� *.C ���ϰ� *.h ������ ���� �ۼ��ؾ� �մϴ�.
	// ����� ���� �Լ��� �̸��� �ۼ��ϰ� �Ұ�ȣ�� ���� �ݾƾ� �մϴ�.
	second_function();
	fourth_function();

	// fourth_function���� ���� 7�� ����ϵ��� �����ô�!

	return 0;
}