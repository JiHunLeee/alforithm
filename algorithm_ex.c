/*
실기 : 대.소문자 구분 없이 알파벳을 입력하면 대.소문자를 판별하여 사전 순으로 정렬하여 출력하는 프로그램
% 배열을 사용할 경우
1. 입력받을 배열의 이름은 input_ary로 한다
2. 배열의 크기는 10으로 정한다
3. 정렬 알고리즘은 삽입정렬을 사용한다.
4. 삽입정렬 알고리즘은 함수로 사용한다.
5.소문자 저장 배열이름은 lower_ary 로 한다.
6. 대문자 저장 배열 이름은 upper_ary로 한다.

#연결리스트를 사용할 경우(가산점이 부여된다)
1. 입력받은 배열이름은  input_ary로 한다.
2. 배열의 크기는 10으로정한다.
3. 정렬 알고리즘은 삽입정렬을 사용한다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void insertionSort(char* pary, int sz);						//함수 호출

int main()
{
	char input_ary[10];							//입력받는 배열 
	char lower_ary[10] = { 0 };						//소문자 배열
	char upper_ary[10] = { 0 };						//대문자 배열
	int i = 0, j = 0,k=0;							//포문과 이프문에서 쓸 변수 선언 초기화


\

	printf("10자리 대소문자 구분없이 입력하세요.\n");
	for (i = 0; i <10; i++)							//배열 반복문은 포문으로 배열방 갯수만큼 실행
	{
		scanf("%c", &input_ary[i]);					//배열0번째 방부터 포문으로 반복해서 열번까지 실행
		getchar();
	}
	for (i = 0; i < 10; i++)						//몇번째 배열방에 들어가는지 확인
	{											
		printf("input_ary[%d]번째\t%c\n", i, input_ary[i]);
	}
	
	int size = sizeof(input_ary) / sizeof(input_ary[0]);			//입력받은 값 크기 확인

	for (i = 0; i < size;i++)						//크기만큼 반복문으로 조건 검색
	{
		if ((input_ary[i] >= 'A') && (input_ary[i] <= 'Z'))		// 대문자
		{
			upper_ary[j] = input_ary[i];				//upper_ary 값에 대입
			j++;							//실행 될대마다 카운터 (upper_ary 사이즈 값이된다)
		}	
		else if ((input_ary[i] >= 'a') && (input_ary[i] <= 'z')) 	// 소문자
		{
			lower_ary[k]= input_ary[i];				//lower_ary 값에 대입
			k++;							//실행 될대마다 카운터 (lower_ary 사이즈 값이된다)
		}
	}
	//insertionSort(input_ary, size);					//입력한 배열 정렬 및 확인 (실행할 필요X)
	printf("\n");
	
	/*
	for (i = 0; i < j; i++) {						//upper_ary 잘 들어갔는지 확인
		printf("%c ", upper_ary[i]);
	}
	*/
	//	int size1 = sizeof(upper_ary) / sizeof(upper_ary[0]);		//upper_ary 사이즈를 정의 위에 10이라고 줬지만 함수안에 굳이 변수로 넣겠다면 정의해줘야함
	//insertionSort(upper_ary, size1);					//위의 사이즈 정의를 배고 숫자로 10넣어도 무관 선언을 10으로 해줬기 때문
	printf("upper_ary 배열 :");
	
	insertionSort(upper_ary, j);						//삽입정렬 함수에서 upper_ary배열을 카운터한 j까지 

	/*
	for (i = 0; i < k; i++) {
		printf("%c ", lower_ary[i]);					//lower_ary 잘 들어갔는지 확인
	}
	*/
//	int size2 = sizeof(lower_ary) / sizeof(lower_ary[0]);	
//	insertionSort(lower_ary, size2);	
	printf("lower_ary 배열 : ");
	insertionSort(lower_ary, k);						//삽입정렬 함수에서 lower_ary배열을 카운터한 j까지 

	
	return 0;
}
void insertionSort(char* pary, int sz)						//삽입정렬 함수 
{

	int i, j, temp;
	for (i = 1; i < sz; i++) {						//두번째 인덱스를 키값으로 첫번째 인덱스 값과 비교

		for (j = i; j > 0; j--)						// 차례대로 진행되면서 정렬하는 반복문
		{
			if (pary[j - 1] > pary[j])				//앞에 있는 값이 큰 경우에 자리 바꿈을 한다.
			{
				temp = pary[j];					//스왑 공식
				pary[j] = pary[j - 1];
				pary[j - 1] = temp;
			}
		}
	}
	for (j = 0; j < sz; j++)
	{
		//if(pary[j] != NULL)						//각 대문자배열 소문자 배열을 인설트솔트 함수에 사이즈로 사용할시 널값 제외하고 출력
		printf("%c  ", pary[j]);
	}
}
