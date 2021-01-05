#ifndef _ARRY_H
#define _ARRY_H

#include "command.h"
#include "header.h"

typedef struct ArryList
{
	uint32_t* pBase;			//�洢����ĵ�һ����ַ
	uint32_t len;				//�������Ԫ����
	uint32_t cnt;				//��ǰ�������Ч����
	uint32_t increment;			//�Զ���������,һ���������������ڴ�ռ�
}S_Arry;

using namespace std;

void init_arry(S_Arry* pArry, uint32_t length);					//��ʼ������
void show(S_Arry* arry);										//��ʾ��������
bool is_empty_arry(S_Arry* arry);								//�ж������Ƿ�Ϊ��
bool is_full_arry(S_Arry* arry);								//�ж������Ƿ�Ϊ�����
bool append_arry(S_Arry* pArry, int32_t val);					//�������
bool insert_arry(S_Arry* pArry, uint32_t pos, int32_t val);		//��������
bool detel_arry(S_Arry* pArry, uint32_t pos, int32_t* pVal);	//ɾ������
void inversion_arry(S_Arry* pArry);								//��������
void sort_arry(S_Arry* pArry);									//ð����������

#endif // !_ARRY_H

