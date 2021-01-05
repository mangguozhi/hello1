#ifndef _ARRY_H
#define _ARRY_H

#include "command.h"
#include "header.h"

typedef struct ArryList
{
	uint32_t* pBase;			//存储数组的第一个地址
	uint32_t len;				//最大容纳元素数
	uint32_t cnt;				//当前数组的有效个数
	uint32_t increment;			//自动增长因子,一般扩充因子数的内存空间
}S_Arry;

using namespace std;

void init_arry(S_Arry* pArry, uint32_t length);					//初始化链表
void show(S_Arry* arry);										//显示链表数据
bool is_empty_arry(S_Arry* arry);								//判断链表是否为空
bool is_full_arry(S_Arry* arry);								//判断链表是否为存放满
bool append_arry(S_Arry* pArry, int32_t val);					//添加数据
bool insert_arry(S_Arry* pArry, uint32_t pos, int32_t val);		//插入数据
bool detel_arry(S_Arry* pArry, uint32_t pos, int32_t* pVal);	//删除数据
void inversion_arry(S_Arry* pArry);								//倒置数据
void sort_arry(S_Arry* pArry);									//冒泡排序数据

#endif // !_ARRY_H

