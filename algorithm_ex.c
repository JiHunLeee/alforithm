/*
�Ǳ� : ��.�ҹ��� ���� ���� ���ĺ��� �Է��ϸ� ��.�ҹ��ڸ� �Ǻ��Ͽ� ���� ������ �����Ͽ� ����ϴ� ���α׷�
% �迭�� ����� ���
1. �Է¹��� �迭�� �̸��� input_ary�� �Ѵ�
2. �迭�� ũ��� 10���� ���Ѵ�
3. ���� �˰����� ���������� ����Ѵ�.
4. �������� �˰����� �Լ��� ����Ѵ�.
5.�ҹ��� ���� �迭�̸��� lower_ary �� �Ѵ�.
6. �빮�� ���� �迭 �̸��� upper_ary�� �Ѵ�.

#���Ḯ��Ʈ�� ����� ���(�������� �ο��ȴ�)
1. �Է¹��� �迭�̸���  input_ary�� �Ѵ�.
2. �迭�� ũ��� 10�������Ѵ�.
3. ���� �˰����� ���������� ����Ѵ�.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void insertionSort(char* pary, int sz);							//�Լ� ȣ��

int main()
{
	char input_ary[10];											//�Է¹޴� �迭 
	char lower_ary[10] = { 0 };									//�ҹ��� �迭
	char upper_ary[10] = { 0 };									//�빮�� �迭
	int i = 0, j = 0,k=0;										//������ ���������� �� ���� ���� �ʱ�ȭ


\

	printf("10�ڸ� ��ҹ��� ���о��� �Է��ϼ���.\n");
	for (i = 0; i <10; i++)										//�迭 �ݺ����� �������� �迭�� ������ŭ ����
	{
		scanf("%c", &input_ary[i]);								//�迭0��° ����� �������� �ݺ��ؼ� �������� ����
		getchar();
	}
	for (i = 0; i < 10; i++)									//���° �迭�濡 ������ Ȯ��
	{											
		printf("input_ary[%d]��°\t%c\n", i, input_ary[i]);
	}
	
	int size = sizeof(input_ary) / sizeof(input_ary[0]);		//�Է¹��� �� ũ�� Ȯ��

	for (i = 0; i < size;i++)									//ũ�⸸ŭ �ݺ������� ���� �˻�
	{
		if ((input_ary[i] >= 'A') && (input_ary[i] <= 'Z'))		// �빮��
		{
			upper_ary[j] = input_ary[i];						//upper_ary ���� ����
			j++;												//���� �ɴ븶�� ī���� (upper_ary ������ ���̵ȴ�)
		}	
		else if ((input_ary[i] >= 'a') && (input_ary[i] <= 'z')) // �ҹ���
		{
			lower_ary[k]= input_ary[i];							//lower_ary ���� ����
			k++;												//���� �ɴ븶�� ī���� (lower_ary ������ ���̵ȴ�)
		}
	}
	//insertionSort(input_ary, size);							//�Է��� �迭 ���� �� Ȯ�� (������ �ʿ�X)
	printf("\n");
	
	/*
	for (i = 0; i < j; i++) {									//upper_ary �� ������ Ȯ��
		printf("%c ", upper_ary[i]);
	}
	*/
	//	int size1 = sizeof(upper_ary) / sizeof(upper_ary[0]);	//upper_ary ����� ���� ���� 10�̶�� ������ �Լ��ȿ� ���� ������ �ְڴٸ� �����������
	//insertionSort(upper_ary, size1);							//���� ������ ���Ǹ� ��� ���ڷ� 10�־ ���� ������ 10���� ����� ����
	printf("upper_ary �迭 :");
	insertionSort(upper_ary, j);								//�������� �Լ����� upper_ary�迭�� ī������ j���� 

	/*
	for (i = 0; i < k; i++) {
		printf("%c ", lower_ary[i]);							//lower_ary �� ������ Ȯ��
	}
	*/
//	int size2 = sizeof(lower_ary) / sizeof(lower_ary[0]);	
//	insertionSort(lower_ary, size2);	
	printf("lower_ary �迭 : ");
	insertionSort(lower_ary, k);								//�������� �Լ����� lower_ary�迭�� ī������ j���� 

	
	return 0;
}
void insertionSort(char* pary, int sz)							//�������� �Լ� 
{

	int i, j, temp;
	for (i = 1; i < sz; i++) {									//�ι�° �ε����� Ű������ ù��° �ε��� ���� ��

		for (j = i; j > 0; j--)									// ���ʴ�� ����Ǹ鼭 �����ϴ� �ݺ���
		{
			if (pary[j - 1] > pary[j])							//�տ� �ִ� ���� ū ��쿡 �ڸ� �ٲ��� �Ѵ�.
			{
				temp = pary[j];									//���� ����
				pary[j] = pary[j - 1];
				pary[j - 1] = temp;
			}
		}
	}
	for (j = 0; j < sz; j++)
	{
	//	if(pary[j] != NULL)												//�� �빮�ڹ迭 �ҹ��� �迭�� �μ�Ʈ��Ʈ �Լ��� ������� ����ҽ� �ΰ� �����ϰ� ���
		printf("%c  ", pary[j]);
	}
}
