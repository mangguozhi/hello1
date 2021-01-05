#include "arry.h"

//��ʼ������
void init_arry(S_Arry* pArry, uint32_t length)
{
	pArry->pBase = (uint32_t*)malloc(sizeof(uint32_t) * length);

	//�жϿռ�����Ƿ�ɹ�,����ռ����ʧ��,ϵͳ�ὫNULL�����pArry->pBase
	if (NULL == pArry->pBase)
	{
		cout << "�ڴ����ʧ��" << endl;
		exit(-1);		//��ֹ����
	}
	else
	{
		pArry->len = length;
		pArry->cnt = 0;
	}
	return;
}

//�ж������Ƿ�Ϊ��
bool is_empty_arry(S_Arry* arry)
{
	if (0 == arry->cnt)
	{
		return TRUE;
	}
	else
	{
		return FLASE;
	}
}

//�ж������Ƿ�Ϊ�����
bool is_full_arry(S_Arry* pArry)
{
	if (pArry->cnt == pArry->len)
	{
		return TRUE;
	}

	else
	{
		return FLASE;
	}
}

//��ʾ��������
void show(S_Arry* pArry)
{
	if (is_empty_arry(pArry))
	{
		cout << "�������Ϊ��" << endl;
	}
	else
	{
		for (size_t i = 0; i < pArry->cnt; i++)
		{
			cout << *(pArry->pBase + i) << " ";
		}
		cout << endl;
	}
	return;
}

//�������
bool append_arry(S_Arry* pArry, int32_t val)
{
	if (is_full_arry(pArry))
	{
		return FLASE;
	}
	else
	{
		pArry->pBase[pArry->cnt] = val;
		pArry->cnt += 1;
		return TRUE;
	}
}

//��������
bool insert_arry(S_Arry* pArry, uint32_t pos, int32_t val)
{
	if (is_full_arry(pArry))
	{
		cout << "�������,����ʧ��!!!" << endl;
		return FLASE;
	}

	if ((pos < 1) || (pos > pArry->cnt + 1))
	{
		cout << "����λ�ô���,����ʧ��!!!" << endl;
		return FLASE;
	}

	for (uint32_t i = pArry->cnt - 1; i >= pos - 1; i--)
	{
		pArry->pBase[i + 1] = pArry->pBase[i];
	}
	pArry->pBase[pos - 1] = val;
	pArry->cnt++;
	return true;
}

//ɾ������
bool detel_arry(S_Arry* pArry, uint32_t pos, int32_t* pVal)
{
	if (is_empty_arry(pArry))
	{
		cout << "��������Ϊ��,ɾ��ʧ��!!!" << endl;
		return FLASE;
	}

	if ((pos < 1) || (pos > pArry->cnt))
	{
		cout << "ɾ��λ�ô���,ɾ��ʧ��" << endl;
		return FLASE;
	}

	*pVal = pArry->pBase[pos - 1];

	for (size_t i = pos - 1; i < pArry->cnt; i++)
	{
		pArry->pBase[i] = pArry->pBase[i + 1];
	}
	pArry->cnt--;
	return true;
}

//��������
void inversion_arry(S_Arry* pArry)
{
	uint32_t temp;
	uint32_t end;

	if (is_empty_arry(pArry))
	{
		cout << "����Ϊ��,����ʧ��!!!" << endl;
		return;
	}

	end = pArry->cnt - 1;
	for (size_t i = 0; i < pArry->cnt / 2; i++)
	{
		temp = pArry->pBase[i];
		pArry->pBase[i] = pArry->pBase[end];
		pArry->pBase[end] = temp;
		end -= 1;
	}
	return;
}

//��������
void sort_arry(S_Arry* pArry)
{
	uint32_t temp;
	for (size_t i = 0; i < pArry->cnt; i++)
	{
		for (size_t j = i + 1; j < pArry->cnt; j++)
		{
			if (pArry->pBase[i] > pArry->pBase[j])				//"<"��������  ">"��������
			{
				temp = pArry->pBase[i];
				pArry->pBase[i] = pArry->pBase[j];
				pArry->pBase[j] = temp;
			}
		}
	}
}
