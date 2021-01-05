#include "arry.h"

//初始化链表
void init_arry(S_Arry* pArry, uint32_t length)
{
	pArry->pBase = (uint32_t*)malloc(sizeof(uint32_t) * length);

	//判断空间分配是否成功,如果空间分配失败,系统会将NULL分配给pArry->pBase
	if (NULL == pArry->pBase)
	{
		cout << "内存分配失败" << endl;
		exit(-1);		//中止程序
	}
	else
	{
		pArry->len = length;
		pArry->cnt = 0;
	}
	return;
}

//判断链表是否为空
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

//判断链表是否为存放满
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

//显示链表数据
void show(S_Arry* pArry)
{
	if (is_empty_arry(pArry))
	{
		cout << "输出数组为空" << endl;
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

//添加数据
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

//插入数据
bool insert_arry(S_Arry* pArry, uint32_t pos, int32_t val)
{
	if (is_full_arry(pArry))
	{
		cout << "数组溢出,插入失败!!!" << endl;
		return FLASE;
	}

	if ((pos < 1) || (pos > pArry->cnt + 1))
	{
		cout << "插入位置错误,插入失败!!!" << endl;
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

//删除数据
bool detel_arry(S_Arry* pArry, uint32_t pos, int32_t* pVal)
{
	if (is_empty_arry(pArry))
	{
		cout << "数组数据为空,删除失败!!!" << endl;
		return FLASE;
	}

	if ((pos < 1) || (pos > pArry->cnt))
	{
		cout << "删除位置错误,删除失败" << endl;
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

//倒置数据
void inversion_arry(S_Arry* pArry)
{
	uint32_t temp;
	uint32_t end;

	if (is_empty_arry(pArry))
	{
		cout << "数据为空,倒置失败!!!" << endl;
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

//排序数据
void sort_arry(S_Arry* pArry)
{
	uint32_t temp;
	for (size_t i = 0; i < pArry->cnt; i++)
	{
		for (size_t j = i + 1; j < pArry->cnt; j++)
		{
			if (pArry->pBase[i] > pArry->pBase[j])				//"<"降序排序  ">"升序排序
			{
				temp = pArry->pBase[i];
				pArry->pBase[i] = pArry->pBase[j];
				pArry->pBase[j] = temp;
			}
		}
	}
}
