#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include<Windows.h>
using namespace std;
typedef struct LNode
{
	char Name[20];           //����
	char Gender[5];          //�Ա�
	char B_Department[10];   //����
	char K_Department[10];	 //����
	int Num;                 //����
	int Age;                 //����
	int Tel;                 //�绰
	int length;              //ͳ�Ƴ���
	struct LNode *next;
}LNode,*LinkList;
struct mima
{
	char a[10];
	char b[10];
}m[20];
//��ʼ������
void Init_info(LinkList &L)
{
	L = new LNode;
	L->next = NULL;
	L->length  = 0;
	printf("��ʼ���ɹ���\n");
}
//����ϵͳ
void help() 
{
    cout<<"\n0.��ӭʹ��ϵͳ������\n"<<endl;
    cout<<"\n2.���ղ˵���ʾ�������ִ���;\n"<<endl;
    cout<<"\n3.������ע�Ᵽ��;\n"<<endl;
    cout<<"\n4.лл����ʹ�ã�\n"<<endl;
}
//������Ϣ
void fileWrite(LinkList L)
{
	LinkList q;
	q = L->next ;
	FILE*fp;
	int j;
	fp=fopen("c://data1.txt","w");
	if(fp==NULL)
		printf("�ļ��򿪴���\n");
	while(q)
	{
			 fprintf(fp,"%d%5s%5d%5s%5s%5s%5d\n",q->Num,q->Name ,q->Age ,q->Gender ,q->B_Department ,q->K_Department ,q->Tel );
			q = q->next ;
	}
	fclose(fp);
	printf("***********************����ɹ�******************************\n");
}


//���Ա����Ϣ
void insert(LinkList &L)
{
	LinkList t;
	t = new LNode;
	cout<<"�����빤�ţ�"<<endl;
	scanf("%d",&t->Num);
	cout<<"������������"<<endl;
	scanf("%s",t->Name );
	cout<<"�������Ա�"<<endl;
	scanf("%s",t->Gender);
	cout<<"���������䣺"<<endl;
	scanf("%d",&t->Age );
	cout<<"���������ڲ��ţ�"<<endl;
	scanf("%s",t->B_Department);
	cout<<"���������ڿ��ң�"<<endl;
	scanf("%s",t->K_Department);
	cout<<"������绰��"<<endl;
	scanf("%d",&t->Tel);
	 t->next = L->next   ;
	 L->next = t;
	 L->length ++;
	 fileWrite(L);
}
//ˢ����Ϣ
void update(LinkList &L)
{    LinkList q,t;
	t = L ; 
	int j=0;
		FILE*fp;
	fp=fopen("c:\\data1.txt","r");
	if(fp==NULL)
		printf("�������");
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
	printf("******************ˢ�³ɹ�************************************\n");
	fclose(fp);
}
//��ʾ����Ա����Ϣ
void display(LinkList L)
{
	int i,j=1,k,s;
	k = L->length /3;
	LinkList q;
	q = L->next;
	printf("   ����  ����   ����  �Ա�  ����  ����  �绰		\n");
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
	 printf("                                            ��%dҳ,��%dҳ                                          ",j-1,k);
 }
printf("\n");
}
//��ѯԱ����Ϣ
void seek(LinkList L)
{
	int m,num,a=0;
	char name[20];
	LinkList q;
	q = L ;
	printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("-------------------------1.�����Ų�ѯ-----------------------\n");
    printf("-------------------------2.��������ѯ-----------------------\n");
    printf("-------------------------3.�˳����˵�-----------------------\n");
    printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf(" * * * * * * * * * *�������ѯ��ʽǰ�����* * * * * * * * * *\n");
	scanf("%d",&m);
	switch(m)
	{
		case 1:
			{
				cout<<"������Ҫ���ҵĹ��ţ�"<<endl;
				scanf("%d",&num);
				while(q)
				{
					if(q->Num  == num)
					{
						a=1;
						printf("   ����  ���� ���� �Ա� ���� ���� �绰		\n");
						 printf("--------------------------------------------------------------------\n");
						 printf("%5d%5s%5d%5s%5s%5s%5d\n",q->Num,q->Name ,q->Age ,q->Gender ,q->B_Department ,q->K_Department ,q->Tel );
						 break;
					}
					q = q->next ;
				}
				if(a == 0)
				 printf("�����ڸ�Ա����\n");
				break;
			}
		case 2:
			{
				cout<<"������Ҫ���ҵ�������"<<endl;
				scanf("%s",name );
				while(q)
			{
				
				if(!strcmp(q->Name,name))
				{
					a=1;
					printf("   ����  ���� ���� �Ա� ���� ���� �绰		\n");
				    printf("--------------------------------------------------------------------\n");
					 printf("%5d%5s%5d%5s%5s%5s%5d\n",q->Num,q->Name ,q->Age ,q->Gender ,q->B_Department ,q->K_Department ,q->Tel );
						 break;
				}
				q = q->next ;
			}
				if(a == 0)
				 printf("�����ڸ�Ա����\n");
		
				break;
			}
		case 3:
			break;
	}
	}

//  ɾ��;
void dele(LinkList &L)
{
	LinkList q,t;
	q = L->next ;
	int a = 0;
	char name[20];
	printf("������Ҫɾ��Ա����������");
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
		 printf("�����ڸ�Ա�������������Ƿ�������ȷ��");

}
//�޸���Ϣ
void modify(LinkList &L)
{
	LinkList q;
	int m,a=0;
	q = L ;
	char name[20];
	printf("������Ҫ�޸�Ա����������");
	scanf("%s",name);
	while(q)
	{
		if(!strcmp(q->Name,name))
		{
			a = 1;
	printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("-------------------------1.�޸�����-----------------------\n");
    printf("-------------------------2.�޸�����-----------------------\n");
    printf("-------------------------3.�޸��Ա�-----------------------\n");
	printf("-------------------------4.�޸Ĺ���-----------------------\n");
	printf("-------------------------5.�޸Ĳ���-----------------------\n");
	printf("-------------------------6.�޸Ŀ���-----------------------\n");
	printf("-------------------------7.�޸ĵ绰-----------------------\n");
	printf("-----------------------8.�޸���ɣ��˳�-------------------\n");
    printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	while(1)
	{
	printf(" * * * * * * * * * * * *�������޸ĵ����* * * * * * * * *\n");
	scanf("%d",&m);
	switch(m)
	{
	case 1:
		{
			printf("�������µ�������");
			scanf("%s",q->Name);
			break;
		}
	case 2:
		{
			printf("�������µ����䣺");
			scanf("%d",&q->Age);
		
			break;
		}
	case 3:
		{
			printf("�������µ��Ա�");
			scanf("%s",q->Gender);
			break;
		}
	case 4:
		{
			printf("�������µĹ��ţ�");
			scanf("%d",&q->Num);
			break;
		}
	case 5:
		{
			printf("�������µĲ��ţ�");
			scanf("%s",q->B_Department);
			
			break;
		}
	case 6:
		{
			printf("�������µĿ��ң�");
			scanf("%s",q->K_Department);
			
			break;
		}
	case 7:
		{
			printf("�������µĵ绰��");
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
			printf("�����ڸ�Ա�������������Ƿ�������ȷ��");
}
//ͳ��Ա����Ϣ
void statis (LinkList &L)
{
	LinkList q,t,p;
	q = L->next  ;
	char a[10] = "a",b[10] = "b",c[10] = "c",d[10]="d",e[10]="e",f[10]="f";
	printf("�ڲ���a�����У�\n" );
	while (q)
	{
		if(!strcmp(q->B_Department,a))
			printf("%5s",q->Name );
		q = q->next ;
	}
	q = L->next;
	printf("\n�ڲ���b�����У�\n" );
	while (q)
	{
		if(!strcmp(q->B_Department,b))
			printf("%5s",q->Name );
		q = q->next ;
	}
	q = L->next;
	printf("\n�ڲ���c�����У�\n" );
	while (q)
	{
		if(!strcmp(q->B_Department ,c))
			printf("%5s",q->Name );
		q = q->next ;
	}
	q = L->next;
	printf("\n�ڿ���d�����У�\n" );
	while (q)
	{
		if(!strcmp(q->K_Department ,d))
			printf("%5s",q->Name );
		q = q->next ;
	}
	q = L->next;
	printf("\n�ڿ���e�����У�\n" );
	while (q)
	{
		if(!strcmp(q->K_Department ,e))
			printf("%5s",q->Name );
		q = q->next ;
	}
	q = L->next;
	printf("\n�ڿ���f�����У�\n" );
	while (q)
	{
		if(!strcmp(q->K_Department ,f))
			printf("%5s",q->Name );
		q = q->next ;
	}

}
//�˵�
void menu(LinkList &L)
{
	update(L);
	int num;
	int k = 1;
	
	while(k)
	{
	printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * *|*\n");
    printf(" *|                 ��ҵ��Ϣ��Ϣ����ϵͳ		  |*\n");
    printf(" *|                                                       |*\n");
    printf(" *|       * * * * * * *ϵͳ���ܲ˵�* * * * * * *          |*\n");
    printf(" *|    --------------------------------------------       |*\n");
    printf(" *|                                                       |*\n");
    printf(" *|       0.ϵͳ������˵��  |   1.���Ա����Ϣ            |*\n");
    printf(" *|                                                       |*\n");
    printf(" *|       2.�鿴Ա����Ϣ    |   3.�޸�Ա����Ϣ            |*\n");
    printf(" *|                                                       |*\n");
    printf(" *|       4.ɾ��Ա����Ϣ    |   5.ͳ��Ա����Ϣ            |*\n");
    printf(" *|                                                       |*\n");
    printf(" *|       6.����Ա����Ϣ    |   7.����Ա����Ϣ            |*\n");
    printf(" *|                                                       |*\n");
    printf(" *|                    8.�˳�ϵͳ                         |*\n");
    printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("------------------------------------------------------------\n");
	printf("��ѡ��˵����:");
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
            printf("����0-8֮��ѡ��\n");
	}


}
}
int main()
{
	system("title ��ҵԱ����Ϣ����ϵͳ");  //�޸�С�ڿ������
	LinkList L;
    Init_info(L);
	menu(L);
	return 0;
}


