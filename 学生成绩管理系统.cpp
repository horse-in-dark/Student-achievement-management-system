#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define N 6
struct student
{
	long num;//学号
	char name[10];//姓名
	int score[3];//三门课成绩
	float average;//平均分
	char sex[8];//性别

};
struct user
{
	char zhanghao[20];
	char mima[15];
};
int n = 0;

void welcome()
{
	printf("\n\n\n\n");
	printf("\t\t\t\t----------------------------------\t\t\t\n");
	printf("\t\t\t\t====                       =======\t\t\t\n");
	printf("\t\t\t\t----欢迎使用学生成绩管理系统------\t\t\t\n");
	printf("\t\t\t\t====                       =======\t\t\t\n");
	printf("\t\t\t\t----------------------------------\t\t\t\n");
	printf("\n\n\n\n");
}

void login()//这是注册登录函数 
{
	int key = 0;//定义了一个作为循环条件的数字 
	while (key == 0)
	{
		struct user u;//定义了一个结构体变量u 
		int choose;//定义了一个数字变量用于记录用户选择 
		int k = 4;//定义了一个数字作为用户登录可尝试次数 
		char cho = 'n';//定义了一个字符变量记录用户的选择 
		char zh[40], mi[40];//定义了两个字符数组存储登录时输入的账号密码 
		printf("\t\t\t\t-----------请登录或注册-----------\t\t\n");
		printf("\t\t\t\t---           1.注册           ---\t\t\t\n");
		printf("\t\t\t\t---           2.登录           ---\t\t\t\n");
		printf("请输入序号进行操作:\n");
		scanf("%d", &choose);//读取用户的选择赋值给变量 
		switch (choose)//做了一个多路分支以适应用户的不同选择 
		{
		case 1:
			printf("请输入您的账户：\n");
			scanf("%s", u.zhanghao);//读取用户输入注册账户 
			printf("请输入您的密码：\n");//读取用户输入注册密码 
			scanf("%s", u.mima);
			printf("\n注册成功\n");
			printf("按任意键进入登陆页面\n");
			system("pause");
			system("cls");//清屏函数使界面看起来简洁 
			continue;//注册完成跳出该轮循环进行下一轮循环进行登录 
		case 2:
			while (key == 0)
			{
				printf("登录:\n");
				printf("请输入您的账号：\n");
				scanf("%s", zh);//读取用户登录账户 
				printf("请输入您的密码：\n");
				scanf("%s", mi);//读取用户登录密码 
				if (strcmp(zh, u.zhanghao) == 0 && strcmp(mi, u.mima) == 0)//判断用户登录账号密码和注册时的账号密码是否相同 
				{
					printf("登陆成功！\n");
					key = 1; //令循环条件变量值改变使循环结束 
					printf("按任意键进入主菜单：\n");
					getch();
				}
				else//用户输错账号密码时的情况 
				{
					k--;//可尝试输入密码次数减一次 
					printf("账号或密码错误，请重新输入,还有%d次机会\n", k);
					if (k == 0)//做出了当次数用尽时的系统操作 
					{
						printf("您输入错误次数过多，请稍候再试！\n");
						key = 1; //使循环结束 
						printf("按任意键退出系统：\n");
						getch();
						exit(1);
					}
				}
			}
			break;//跳出整个循环 
		}
	}

}



void input(struct student stu[])
{
	void average(struct student stu[6]);
	char ch;
	while (1)
	{
		printf("请输入第%d个学生的学号：\n", n + 1);
		scanf("%ld", &stu[n].num);
		printf("请输入第%d个学生姓名：\n", n + 1);
		scanf("%s", stu[n].name);
		printf("请输入第%d个学生性别(female or male)：\n", n + 1);
		scanf("%s", stu[n].sex);
	aa:	printf("请输入第%d个学生的C语言成绩：\n", n + 1);
		scanf("%d", &stu[n].score[0]);
		if (stu[n].score[0] < 0 || stu[n].score[0]>100)
		{
			printf("输入错误!重新输入！\n");
			goto aa;
		}
	bb:	printf("请输入第%d个学生的高数成绩：\n", n + 1);
		scanf("%d", &stu[n].score[1]);
		if (stu[n].score[1] < 0 || stu[n].score[1]>100)
		{
			printf("输入错误!重新输入！\n");
			goto bb;
		}
	cc:	printf("请输入第%d个学生的英语成绩：\n", n + 1);
		scanf("%d", &stu[n].score[2]);



		if (stu[n].score[2] < 0 || stu[n].score[2]>100)
		{
			printf("输入错误!重新输入！\n");
			goto cc;
		}
		n++;
		average(stu);

		system("cls");
		printf("继续输入吗?(y/n)");
		fflush(stdin);  //
		ch = getchar();   //从键盘输入一个字符
		if (ch == 'y' || ch == 'Y')
			continue;
		if (ch == 'n' || ch == 'N')
			break;

	}
	printf("按任意键返回主菜单：\n");
	getch();
}



void average(struct student stu[N])
{
	int i, j;

	for (i = 0; i < n; i++)

	{
		stu[i].average = 0;
		for (j = 0; j < 3; j++)

			stu[i].average += stu[i].score[j];

		stu[i].average = stu[i].average / 3.0;
	}


}
void print(struct student stu[N])
{
	int p;
	void display_1(struct student stu[N]);
	void display_2(struct student stu[N]);
	while (1)
	{
		system("cls");
		printf("\t\t\t*********************************\n");
		printf("\t\t\t*     1. 按列显示               *\n");
		printf("\t\t\t*     2. 按行显示               *\n");
		printf("\t\t\t*     3. 返回主菜单             *\n");
		printf("\t\t\t********************************\n\n");
		printf("请选择（1-3）：");
		scanf("%d", &p);
		switch (p)
		{
		case 1: display_1(stu); break;
		case 2: display_2(stu); break;
		case 3:	return;
		}
	}

}


void display_1(struct student stu[N])
{
	int i;
	system("cls");
	if (n == 0)
		printf("无学生数据\n");
	if (n > 0)
	{
		printf("%d 个学生数据为:\n", n);
		for (i = 0; i < n; i++)
		{
			printf("=============================\n");
			printf("学号:%ld\n姓名:%s\n性别：%s\nC语言:%d\n高数:%d\n英语:%d\n平均分:%.2f\n", stu[i].num, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].average);
			printf("=============================\n");
		}
	}
	printf("按任意键返回上一页：\n");
	getch();
}


void display_2(struct student stu[N])
{
	int i;
	system("cls");

	if (n == 0)
		printf("无学生数据\n");
	if (n > 0)
	{
		printf("%d 个学生数据为:\n", n);
		printf("学号\t姓名\t性别\tC语言\t高数\t英语\t平均分\n");
		printf("%d\n", n);
		printf("==================================================\n");
		for (i = 0; i < n; i++)
		{
			printf("%ld\t%s\t%s\t%d\t%d\t%d\t%.2f\n", stu[i].num, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].average);
		}
	}
	printf("按任意键返回上一页：\n");
	getch();
}
void query(struct student stu[])
{
	int m;
	void xingming(struct student stu[]);
	void xuehao(struct student stu[]);
	void xingbie(struct student stu[]);
	printf("\t\t\t\t*     1. 输入学生姓名            *\n");
	printf("\t\t\t\t*     2. 输入学生学号            *\n");
	printf("\t\t\t\t*     3. 输入学生性别            *\n");
	printf("查找学生的方式\n");
	printf("请选择（1-3):\n");
	scanf("%d", &m);
	switch (m)
	{
	case 1: xingming(stu); break;
	case 2: xuehao(stu); break;
	case 3: xingbie(stu); break;
	}
	printf("按任意键返回主菜单：\n");
	getch();
}
void xingming(struct student stu[])
{
	int i;
	char name1[10];
	printf("输入学生姓名：\n");
	scanf("%s", name1);
	for (i = 0; i < n; i++)
	{
		if (strcmp(name1, stu[i].name) == 0)
		{
			printf("学号\t姓名\t性别\tC语言\t高数\t英语\t平均分\n");
			printf("%ld\t%s\t%s\t%d\t%d\t%d\t%.2f\n", stu[i].num, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].average);
		}

	}
}

void xuehao(struct student stu[])
{
	int i;
	long num1;
	printf("输入学生学号：\n");
	scanf("%ld", &num1);
	for (i = 0; i < n; i++)
	{
		if (num1 == stu[i].num)
		{
			printf("学号\t姓名\t性别\tC语言\t高数\t英语\t平均分\n");
			printf("%ld\t%s\t%s\t%d\t%d\t%d\t%.2f\n", stu[i].num, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].average);
		}

	}
}


void xingbie(struct student stu[])
{
	int i;
	char sex1[8];
	printf("输入学生性别：\n");
	scanf("%s", sex1);
	for (i = 0; i < n; i++)
	{
		if (strcmp(sex1, stu[i].sex) == 0)
		{
			printf("学号\t姓名\t性别\tC语言\t高数\t英语\t平均分\n");
			printf("%ld\t%s\t%s\t%d\t%d\t%d\t%.2f\n", stu[i].num, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].average);
		}

	}

}


void high(struct student stu[])
{
	int i;
	struct student max;
	max = stu[0];
	for (i = 1; i < n; i++)
		if (stu[i].average > max.average)
			max = stu[i];
	printf("最高分的学生数据是:\n");
	printf("学号:\t姓名:\tC语言:\t高数:\t英语:\t平均分\n");
	printf("%ld\t%s\t%d\t%d\t%d\t%.2f\n", max.num, max.name, max.score[0], max.score[1], max.score[2], max.average);
	printf("\n\n");
	printf("按任意键返回主菜单：\n");
	getch();
}

void sort(struct student stu[N])
{
	int i, j;
	struct student t;
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < n - i; j++)
		{
			if (stu[j].average < stu[j + 1].average)
			{
				t = stu[j]; stu[j] = stu[j + 1]; stu[j + 1] = t;
			}
		}
	}
	display_2(stu);

}

void dele(struct student stu[])
{
	int i, j = 0;
	long x;
	char ch;
	printf("输入要删除的学生的学号：\n");
	scanf("%ld", &x);
	printf("\n");
	for (i = 0; i < n; i++)
		if (stu[i].num == x)
		{
			printf("学号\t姓名\t性别\tC语言\t高数\t英语\t平均分\n");
			printf("%ld\t%s\t%s\t%d\t%d\t%d\t%.2f\n", stu[i].num, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].average);
			printf("\n找到该学生，确认要删除该学生的信息?（y/n)");
			fflush(stdin);  //
			ch = getchar();   //从键盘输入一个字符
			if (ch == 'y' || ch == 'Y')
			{

				printf("loading....\n");
				for (j = i; j < n; j++)
				{
					stu[j] = stu[j + 1];

				}

				printf("完成删除!\n");
				n--;

			}
			if (ch == 'n' || ch == 'N')
				break;
		}

	printf("按任意键返回主菜单：\n");
	getch();
}

void append(struct student stu[])
{
	char ch;
	++n;
	printf("添加第%d个学生的数据\n", n);

	while (1)
	{

		printf("请输入第%d个学生的学号：\n", n);
		scanf("%ld", &stu[n - 1].num);
		printf("请输入第%d个学生姓名：\n", n);
		scanf("%s", stu[n - 1].name);
		printf("请输入第%d个学生性别(female or male)：\n", n);
		scanf("%s", stu[n - 1].sex);
	aa:	printf("请输入第%d个学生的C语言成绩：\n", n);
		scanf("%d", &stu[n - 1].score[0]);
		if (stu[n - 1].score[0] < 0 || stu[n - 1].score[0]>100)
		{
			printf("输入错误!重新输入！\n");
			goto aa;
		}
	bb:	printf("请输入第%d个学生的高数成绩：\n", n);
		scanf("%d", &stu[n - 1].score[1]);
		if (stu[n - 1].score[1] < 0 || stu[n - 1].score[1]>100)
		{
			printf("输入错误!重新输入！\n");
			goto bb;
		}
	cc:	printf("请输入第%d个学生的英语成绩：\n", n);
		scanf("%d", &stu[n - 1].score[2]);

		if (stu[n - 1].score[2] < 0 || stu[n - 1].score[2]>100)
		{
			printf("输入错误!重新输入！\n");
			goto cc;
		}


		average(stu);


		system("cls");
		printf("继续添加吗?(y/n)");
		fflush(stdin);  //
		ch = getchar();   //从键盘输入一个字符
		if (ch == 'y' || ch == 'Y')
			continue;
		if (ch == 'n' || ch == 'N')
			break;

	}
	printf("按任意键返回主菜单：\n");
	getch();
}

void modify(struct student stu[])
{
	int i, m;
	long y;
	char ch;

	printf("输入学生的学号:\n");
	scanf("%ld", &y);
	for (i = 0; i < n; i++)
	{
		if (y == stu[i].num)
		{
			printf("该学生的信息：\n");
			printf("学号\t姓名\t性别\tC语言\t高数\t英语\t平均分\n");
			printf("%ld\t%s\t%s\t%d\t%d\t%d\t%.2f\n", stu[i].num, stu[i].name, stu[i].sex, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].average);
			printf("\n找到该学生，确认要修改吗?（y/n)");
		}


		while (1)
		{

			fflush(stdin);  //刷新缓冲区

			ch = getchar();   //从键盘输入一个字符
			if (ch == 'y' || ch == 'Y')
			{

				printf("\t\t\t\t*     1. 学生姓名              *\n");
				printf("\t\t\t\t*     2. 学生性别              *\n");
				printf("\t\t\t\t*     3. 学生C语言成绩         *\n");
				printf("\t\t\t\t*     4. 学生数学成绩          *\n");
				printf("\t\t\t\t*     5. 学生英语成绩          *\n");
				printf("输入所要修改的项(1-5)：\n");
				scanf("%d", &m);

				switch (m)
				{
				case 1:
				{
					printf("输入正确的姓名：\n");
					scanf("%s", stu[i].name);
					printf("是否继续修改?(y/n)");
				}
				; break;
				case 2:
				{
					printf("输入正确的性别(female or male)：\n");
					scanf("%s", stu[i].sex);
					printf("是否继续修改?(y/n)");
				}; break;
				case 3:
				{
					printf("输入正确的C语言成绩：\n");
					scanf("%d", &stu[i].score[0]);
					printf("是否继续修改?(y/n)");
				}; break;
				case 4:
				{
					printf("输入正确的高数成绩：\n");
					scanf("%d", &stu[i].score[1]);
					printf("是否继续修改?(y/n)");
				}; break;
				case 5:
				{
					printf("输入正确的英语成绩：\n");
					scanf("%d", &stu[i].score[2]);
					printf("是否继续修改?(y/n)");
				}; break;
				}
				stu[i].average = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2]) / 3.0;
			}
			else
				break;

		}
		break;
	}

	printf("按任意键返回主菜单：\n");
	getch();
}


int main()
{
	int n;
	struct student stu[N];
	system("cls");
	//清屏函数
	system("color 70");
	welcome();

	login();//调用登录函数, 要求输入用户密码，当密码正确时进入主菜单
	while (1)
	{
		system("cls");
		printf("\t\t\t\t**********************************\n");
		printf("\t\t\t\t*     1. 输入学生数据            *\n");
		printf("\t\t\t\t*     2. 显示学生数据            *\n");
		printf("\t\t\t\t*     3. 修改学生数据            *\n");
		printf("\t\t\t\t*     4. 查询学生数据            *\n");
		printf("\t\t\t\t*     5. 成绩排序                *\n");
		printf("\t\t\t\t*     6. 找最高成绩              *\n");
		printf("\t\t\t\t*     7. 删除学生数据            *\n");
		printf("\t\t\t\t*     8. 添加学生数据            *\n");
		printf("\t\t\t\t*     0. 退出                    *\n");
		printf("\t\t\t\t**********************************\n\n");
		printf("请选择（0-8）：");
		scanf("%d", &n);
		switch (n)
		{
		case 1: input(stu); break;
		case 2: print(stu); break;
		case 3: modify(stu); break;
		case 4: query(stu); break;
		case 5: sort(stu); break;
		case 6: high(stu); break;
		case 7: dele(stu); break;
		case 8: append(stu); break;
		case 0:exit(1);
		}
	}
	return 0;
}




