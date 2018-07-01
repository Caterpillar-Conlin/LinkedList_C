#include <stdio.h>
#include <stdlib.h>//提供exit
#include <string.h>
#include"List.h"//双引号是指从当前目录下寻找
void showmovies(Item item);
char* s_gets(char*st, int n);//将输入的前n个字符存入st指针指向的地址，返回首字符地址
int main(void)
{
	List movies;//movies 是list型的，List 是指向Node的指针，
	Item temp;
	InitializeList(&movies);//参数定义时是List *plist，即参数是指向List型的指针，所以movies加上取地址符号
	if (ListIsFull(&movies))
	{
		fprintf(stderr, "No memory available\n");
		exit(1);//退出整个程序，返回1，用来判断错误类型
	}
	puts("Enter first movie title:");
	while (s_gets(temp.title,SIZE)!=NULL && temp.title[0]!='\0')
	{
		puts("Enter your rating,<0-10>:");
		scanf_s("%d", &temp.rating);//vs scanf报错加_s
		while (getchar()!='\n')//打分时，scanf只会接受前面的数 ？？防止 后面输入的垃圾信息背后面接收，所以知道回车才开始结束这个无操作的循环
		{
			continue;
		}

		if(AddItem(temp, &movies) == false)
		{
			fprintf(stderr, "Problem　allocating　memory\n");
			break;
		}
		if(ListIsFull(&movies))
		{
			puts("The　list　is　now　full.");
			break;
		}
		puts("Enter　next　movie　title　(empty　line　to　stop):");
	}
	if(ListIsEmpty(&movies))
		printf("No　data　entered.　");
	else
	{
		printf("Here　is　the　movie　list:\n");
		Traverse(&movies, showmovies);
	}
	printf("You　entered　%d　movies.\n", ListItemCount(&movies));
	/* 清理　　　 */
	EmptyTheList(&movies);
	printf("Bye!\n");
	return 0;
	getchar();//防止退出
	getchar();//防止退出tchar();//防止退出
	getchar();//防止退出
}
//内部函数实现
void showmovies(Item item)
{
	printf("Movie:　%s　 Rating:　%d\n", item.title,item.rating);
}
char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;
	ret_val = fgets(st, n, stdin);//输入
	if (ret_val)
	{
		find = strchr(st, '\n');// 查找换行符
		if (find)// 如果地址不是NULL，
			*find = '\0';// 在此处放置一个空字符
		else//超出 n
			while(getchar() != '\n')
			continue;// 处理输入行的剩余内容
	}
	return ret_val;
	
}

//需要学习的新函数fgets，strchr
