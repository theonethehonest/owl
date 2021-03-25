#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include<Windows.h>
using namespace std;
typedef struct LNode
{
	char Name[20];           //姓名
	char Gender[5];          //性别
	char B_Department[10];   //部门
	char K_Department[10];	 //科室
	int Num;                 //工号
	int Age;                 //年龄
	int Tel;                 //电话
	int length;              //统计长度
	struct LNode *next;
}LNode,*LinkList;
struct mima
{
	char a[10];
	char b[10];
}m[20];
//初始化链表
void Init_info(LinkList &L)
{
	L = new LNode;
	L->next = NULL;
	L->length  = 0;
	printf("初始化成功！\n");
}
//帮助系统
void help() 
{
    cout<<"\n0.欢迎使用系统帮助！\n"<<endl;
    cout<<"\n2.按照菜单提示键入数字代号;\n"<<endl;
    cout<<"\n3.操作后注意保存;\n"<<endl;
    cout<<"\n4.谢谢您的使用！\n"<<endl;
}
//保存信息
void fileWrite(LinkList L)
{
	LinkList q;
	q = L->next ;
	FILE*fp;
	int j;
	fp=fopen("c://data1.txt","w");
	if(fp==NULL)
		printf("文件打开错误\n");
	while(q)
	{
			 fprintf(fp,"%d%5s%5d%5s%5s%5s%5d\n",q->Num,q->Name ,q->Age ,q->Gender ,q->B_Department ,q->K_Department ,q->Tel );
			q = q->next ;
	}
	fclose(fp);
	printf("***********************保存成功******************************\n");
}


//添加员工信息
void insert(LinkList &L)
{
	LinkList t;
	t = new LNode;
	cout<<"请输入工号："<<endl;
	scanf("%d",&t->Num);
	cout<<"请输入姓名："<<endl;
	scanf("%s",t->Name );
	cout<<"请输入性别："<<endl;
	scanf("%s",t->Gender);
	cout<<"请输入年龄："<<endl;
	scanf("%d",&t->Age );
	cout<<"请输入所在部门："<<endl;
	scanf("%s",t->B_Department);
	cout<<"请输入所在科室："<<endl;
	scanf("%s",t->K_Department);
	cout<<"请输入电话："<<endl;
	scanf("%d",&t->Tel);
	 t->next = L->next   ;
	 L->next = t;
	 L->length ++;
	 fileWrite(L);
}
//刷新信息
void update(LinkList &L)
{    LinkList q,t;
	t = L ; 
	int j=0;
		FILE*fp;
	fp=fopen("c:\\data1.txt","r");
	if(fp==NULL)
		printf("输出错误");
	while(1)
	{
		q = new LNode;
	if(fscanf(fp,"%d%5s%5d%5s%5s%5s%5d\n",&q->Num,q->Name ,&q->Age ,q->Gender ,q->B_Department ,q->K_Department ,&q->Tel )==7)
	{
		L->length=L->length +1;
		q->next  = L->next ;
		L->next  = q;
	}
	else break;
	}
	printf("******************刷新成功************************************\n");
	fclose(fp);
}
//显示所有员工信息
void display(LinkList L)
{
	int i,j=1,k,s;
	k = L->length /3;
	LinkList q;
	q = L->next;
	printf("   工号  姓名   年龄  性别  部门  科室  电话		\n");
	 printf("--------------------------------------------------------------------\n");
while(q)
 {
	 getchar();
	 j = j+1;
	 for(i = 0; i < 3; i++)
	 {
	 printf("%5d%10s%5d%5s%5s%5s%5d\n",q->Num,q->Name ,q->Age ,q->Gender ,q->B_Department ,q->K_Department ,q->Tel );
	 q = q->next ;
	 }
	 printf("                                            第%d页,共%d页                                          ",j-1,k);
 }
printf("\n");
}
//查询员工信息
void seek(LinkList L)
{
	int m,num,a=0;
	char name[20];
	LinkList q;
	q = L ;
	printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("-------------------------1.按工号查询-----------------------\n");
    printf("-------------------------2.按姓名查询-----------------------\n");
    printf("-------------------------3.退出本菜单-----------------------\n");
    printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf(" * * * * * * * * * *请输入查询方式前的序号* * * * * * * * * *\n");
	scanf("%d",&m);
	switch(m)
	{
		case 1:
			{
				cout<<"请输入要查找的工号："<<endl;
				scanf("%d",&num);
				while(q)
				{
					if(q->Num  == num)
					{
						a=1;
						printf("   工号  姓名 年龄 性别 部门 科室 电话		\n");
						 printf("--------------------------------------------------------------------\n");
						 printf("%5d%5s%5d%5s%5s%5s%5d\n",q->Num,q->Name ,q->Age ,q->Gender ,q->B_Department ,q->K_Department ,q->Tel );
						 break;
					}
					q = q->next ;
				}
				if(a == 0)
				 printf("不存在该员工！\n");
				break;
			}
		case 2:
			{
				cout<<"请输入要查找的姓名："<<endl;
				scanf("%s",name );
				while(q)
			{
				
				if(!strcmp(q->Name,name))
				{
					a=1;
					printf("   工号  姓名 年龄 性别 部门 科室 电话		\n");
				    printf("--------------------------------------------------------------------\n");
					 printf("%5d%5s%5d%5s%5s%5s%5d\n",q->Num,q->Name ,q->Age ,q->Gender ,q->B_Department ,q->K_Department ,q->Tel );
						 break;
				}
				q = q->next ;
			}
				if(a == 0)
				 printf("不存在该员工！\n");
		
				break;
			}
		case 3:
			break;
	}
	}

//  删除;
void dele(LinkList &L)
{
	LinkList q,t;
	q = L->next ;
	int a = 0;
	char name[20];
	printf("请输入要删除员工的姓名：");
	scanf("%s",name);
		while(q)
		{
		if(!strcmp(q->next->Name,name))
		{
			q->next = q->next->next;
			a = 1;
			L->length--;
			fileWrite(L);
			break;
		}
		q = q->next ;
		}
	if(a == 0)
		 printf("不存在该员工，请检查姓名是否输入正确！");

}
//修改信息
void modify(LinkList &L)
{
	LinkList q;
	int m,a=0;
	q = L ;
	char name[20];
	printf("请输入要修改员工的姓名：");
	scanf("%s",name);
	while(q)
	{
		if(!strcmp(q->Name,name))
		{
			a = 1;
	printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("-------------------------1.修改姓名-----------------------\n");
    printf("-------------------------2.修改年龄-----------------------\n");
    printf("-------------------------3.修改性别-----------------------\n");
	printf("-------------------------4.修改工号-----------------------\n");
	printf("-------------------------5.修改部门-----------------------\n");
	printf("-------------------------6.修改科室-----------------------\n");
	printf("-------------------------7.修改电话-----------------------\n");
	printf("-----------------------8.修改完成，退出-------------------\n");
    printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	while(1)
	{
	printf(" * * * * * * * * * * * *请输入修改的序号* * * * * * * * *\n");
	scanf("%d",&m);
	switch(m)
	{
	case 1:
		{
			printf("请输入新的姓名：");
			scanf("%s",q->Name);
			break;
		}
	case 2:
		{
			printf("请输入新的年龄：");
			scanf("%d",&q->Age);
		
			break;
		}
	case 3:
		{
			printf("请输入新的性别：");
			scanf("%s",q->Gender);
			break;
		}
	case 4:
		{
			printf("请输入新的工号：");
			scanf("%d",&q->Num);
			break;
		}
	case 5:
		{
			printf("请输入新的部门：");
			scanf("%s",q->B_Department);
			
			break;
		}
	case 6:
		{
			printf("请输入新的科室：");
			scanf("%s",q->K_Department);
			
			break;
		}
	case 7:
		{
			printf("请输入新的电话：");
			scanf("%d",&q->Tel);
			break;

		}
	case 8:
		break;
	}
	if(m == 8)
		break;
	}
	break;
		}
		else
			q = q->next ;
	
	}
	if(a == 0)
			printf("不存在该员工，请检查姓名是否输入正确！");
}
//统计员工信息
void statis (LinkList &L)
{
	LinkList q,t,p;
	q = L->next  ;
	char a[10] = "a",b[10] = "b",c[10] = "c",d[10]="d",e[10]="e",f[10]="f";
	printf("在部门a的人有：\n" );
	while (q)
	{
		if(!strcmp(q->B_Department,a))
			printf("%5s",q->Name );
		q = q->next ;
	}
	q = L->next;
	printf("\n在部门b的人有：\n" );
	while (q)
	{
		if(!strcmp(q->B_Department,b))
			printf("%5s",q->Name );
		q = q->next ;
	}
	q = L->next;
	printf("\n在部门c的人有：\n" );
	while (q)
	{
		if(!strcmp(q->B_Department ,c))
			printf("%5s",q->Name );
		q = q->next ;
	}
	q = L->next;
	printf("\n在科室d的人有：\n" );
	while (q)
	{
		if(!strcmp(q->K_Department ,d))
			printf("%5s",q->Name );
		q = q->next ;
	}
	q = L->next;
	printf("\n在科室e的人有：\n" );
	while (q)
	{
		if(!strcmp(q->K_Department ,e))
			printf("%5s",q->Name );
		q = q->next ;
	}
	q = L->next;
	printf("\n在科室f的人有：\n" );
	while (q)
	{
		if(!strcmp(q->K_Department ,f))
			printf("%5s",q->Name );
		q = q->next ;
	}

}
//菜单
void menu(LinkList &L)
{
	update(L);
	int num;
	int k = 1;
	
	while(k)
	{
	printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * *|*\n");
    printf(" *|                 企业信息信息管理系统		  |*\n");
    printf(" *|                                                       |*\n");
    printf(" *|       * * * * * * *系统功能菜单* * * * * * *          |*\n");
    printf(" *|    --------------------------------------------       |*\n");
    printf(" *|                                                       |*\n");
    printf(" *|       0.系统帮助及说明  |   1.添加员工信息            |*\n");
    printf(" *|                                                       |*\n");
    printf(" *|       2.查看员工信息    |   3.修改员工信息            |*\n");
    printf(" *|                                                       |*\n");
    printf(" *|       4.删除员工信息    |   5.统计员工信息            |*\n");
    printf(" *|                                                       |*\n");
    printf(" *|       6.所有员工信息    |   7.保存员工信息            |*\n");
    printf(" *|                                                       |*\n");
    printf(" *|                    8.退出系统                         |*\n");
    printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("------------------------------------------------------------\n");
	printf("请选择菜单编号:");
    scanf("%d",&num);
    switch(num) {
        case 0:
            help();
            break;
        case 1:
            insert(L);
            break;
        case 2:
            seek(L);
            break;
        case 3:
            modify(L);
            break;
        case 4:
            dele(L);
			break;
		case 5:
			statis (L);
			break;
		case 6:
			display(L);
			break;
  
       case 7:
            fileWrite(L);
            break;
	   case 8:
            k=0;
            break;
		
        default:
            printf("请在0-8之间选择\n");
	}


}
}
int main()
{
	system("title 企业员工信息管理系统");  //修改小黑框的名字
	LinkList L;
    Init_info(L);
	menu(L);
	return 0;
}


