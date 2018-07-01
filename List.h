#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>
#define SIZE 45
struct film
{
	char title[SIZE];
	int rating;
};
typedef struct film Item;
typedef struct node
{
	Item item;
	struct node *next;
}Node;
typedef Node *List;//首字母大写的 都被 typedef成可以用来声明其它变量的类型的声明符
//函数声明要加分号
void InitializeList(List *plist);
//初始化一个链表，无返回值，参数是 List类型的指针，List类型见前文typedef List
bool ListIsEmpty(const List *plist);
//判断链表是否为空，const确保参数在此函数内不会被更改 
bool ListIsFull(const List *plist);
unsigned int ListItemCount(const List *plist);
bool AddItem(Item item, List *list);
//to judge whether the list is able to add a item or not, If yes,retrun true and add the item in the end of list,otherwise return false
void Traverse(const List *plist, void(*pfun)(Item item));
//use a function to traverse every item in the list,pfun is pointer to function which turn void
void EmptyTheList(List *plist);
#endif
