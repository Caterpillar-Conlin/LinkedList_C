//list.c make function come true
#include <stdio.h>
#include <stdlib.h>
#include "List.h"
//局部函数原型
static void CopyToNode(Item item, Node *pnode);//Node 在List.h中tpyede过了
//接口函数的实现，即头文件中的
void InitializeList (List *plist)
{
	*plist = NULL;

}
bool ListIsEmpty(const List *plist)
{
	if (*plist == NULL)
		return true;
	else
		return false;
}
bool ListIsFull(const List*plist)//有疑问，链表没内存=计算机没内存？
{
	Node *pt;
	bool full;
	pt = (Node *)malloc(sizeof(Node));//分配内存给*pt，返回指向Node类型的地址给pt
	if (pt == NULL)
		full = true;
	else
		full = false;
	free(pt);
	return full;
}
unsigned int ListItemCount(const List *plist)
{
	unsigned int count = 0;
	Node *pnode = *plist;
	while (pnode!=NULL)
	{
		++count;
		pnode = pnode->next;
	}
	return count;

}
bool AddItem(Item item, List *plist)//效率低，因为从头向后找，可以重写list结构，加一个尾结点地址
{
	Node *pnew;
	Node *scan = *plist;//1              //scan是指向*plist的地址，，即*scan是**plist，List是指向Node的指针，plist是指向List的指针，所以scan是指向Node的指针
	pnew = (Node*)malloc(sizeof(Node));
	if (pnew == NULL)//若没内存
		return false;
	 CopyToNode(item, pnew);//2,,,,,1,2都是将参数给函数中的变量，不可以直接在函数中使用item，plist，为啥？
	pnew->next = NULL;//参数是个item不是node，所以给他加上结构
	if (scan == NULL)
		*plist = pnew;//如果list为空，list的值变成新节点的地址，*号有必要，plist是指向指针的指针
	else
	{
		while (scan->next!=NULL)
		{
			scan = scan->next;
		}
		scan->next = pnew;
	}
	return true;
}
void Traverse(const List * plist, void(*pfun)(Item item))
{
	Node * pnode = *plist; /* 设置链表的开始 */
	while(pnode!= NULL)
	{
		(*pfun)(pnode->item); /* 把函数应用于链表中的项 */
		pnode = pnode->next;/* 前进到下一项　*/
	}
}
void EmptyTheList(List *plist)
{
	Node * psave;
	while (*plist != NULL)
	{
		psave = (*plist)->next;/* 保存下一个节点的地址　 */
		free(*plist);/* 释放当前节点　　　　 */
		*plist = psave;/* 前进至下一个节点　　　*/
	}
}
/* 局部函数定义 */
/* 把一个项拷贝到节点中 */
static void CopyToNode(Item item, Node *pnode)
{
	pnode->item = item;/* 拷贝结构 */
}
