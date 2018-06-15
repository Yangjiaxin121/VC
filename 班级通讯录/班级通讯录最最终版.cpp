#include<iostream>                    //声明各种头文件
#include<conio.h>
#include<fstream>
#include<string>
#include<string.h>
#include<stdlib.h>
using namespace std;
class AddressBook;                         
class Student                           //定义电话簿Book类和学生信息Student类，并将Book声明为Student的友元类
{
public:
	friend AddressBook;
private:
	char num[20];                      //定义各种学生信息
	char name[20];
	char age[20];
	char addr[20];
	char tel[20];
	char QQ[20];
	char E_mail[20];
};
class AddressBook
{
public:
	void add();               //增加函数
	void alter();            //修改函数
	void del();				//删除函数
	void save();                              //保存函数
	void query();							 //查询函数
	void display();                         //简单的预览功能函数
protected:
	Student stu[30];						//定义Student类型的对象数组
	static int count;						//静态成员count和k用来计数
	static int k;
};
int AddressBook::count=0;
int AddressBook::k=0;
int find(char num[]);						//声明find函数用来查找所在文件的位置
void AddressBook::add()
{
	cout<<endl<<endl<<"                 欢迎来到添加页面...........~(￣▽￣)~*........"<<endl<<endl;
	cout<<"                                    添加后记得在主菜单选4保存哦~~~（￣▽￣）／ "<<endl;
	char num[20];
	for(int r1=0;r1<100;r1++)
	{
		cout<<"~亲~请输入学号(=￣ω￣=):";
		cin>>num;			
		int t=0;
		for(int j=0;num[j]!='\0';j++)
		{
			if(num[j]>='A'&&num[j]<='Z'||num[j]>='a'&&num[j]<='z')
			{
				t=t+1;
				if(t>0)
				{
					cout<<endl<<"亲~您输入的学号不对哦~~"<<endl<<endl;
					break;
				}
			}

		}
		if(t==0)
		{
			r1=200;
			break;
		}
	}										//add函数里，先输入学号判断是否重复，然后再输入其他的信息，输入到内存中
	for(int i=0;i<count;i++)
	{
		if(strcmp(num,stu[i].num)==0)
		{
			cout<<"土鳖~~学号重复啦，是不是打错了~ (＠￣ー￣＠)~"<<endl;
			system("CLS");
			add();						//goto回到A出重新输入
		}
	}
	cout<<endl;
	strcpy(stu[count].num,num);	
	char name[20];
	for(int r2=0;r2<100;r2++)
	{
		cout<<"~亲~请输入名字￣ 3￣ :";           //输入以下信息，并复制到对象数组里
		cin>>name;
		int t=0;
		for(int j=0;name[j];j++)
		{
			if(name[j]>='0'&&name[j]<='9')
			{
				t=t+1;
				if(t>0)
				{
					cout<<endl<<"亲~您输入的名字格式不对哦~~"<<endl<<endl;
					break;
				}
			}

		}	
		if(t==0)
		{
			r2=200;
			break;
		}
	}
	cout<<endl;
	strcpy(stu[count].name,name);
	char age[20];
	for(int r3=0;r3<100;r3++)
	{
		cout<<"~亲~请输入年龄￣ε ￣ :";
		cin>>age;		
		int t=0;
		for(int j=0;age[j];j++)
		{
			if(age[j]>='A'&&age[j]<='Z'||age[j]>='a'&&age[j]<='z')
			{
				t=t+1;
				if(t>0)
				{
					cout<<endl<<"亲~您输入的年龄不对哦~~"<<endl<<endl;
					break;
				}
			}

		}	
		if(t==0)
		{
			r3=200;
			break;
		}
	}	
	cout<<endl;
	strcpy(stu[count].age,age);
	cout<<"~亲~请输入地址￣ 3￣ :";
	char addr[20];
	cin>>addr;
	cout<<endl;
	strcpy(stu[count].addr,addr);
	char tel[20];
	for(int r4=0;r4<100;r4++)
	{
		cout<<"~亲~请输入电话￣ω￣:";
		cin>>tel;	
		int t=0;
		for(int j=0;tel[j];j++)
		{
			if(tel[j]>='A'&&tel[j]<='Z'||tel[j]>='a'&&tel[j]<='z')
			{
				t=t+1;
				if(t>0)
				{
					cout<<endl<<"亲~您输入的电话不对哦~~"<<endl<<endl;
					break;
				}
			}

		}	
		if(t==0)
		{
			r4=200;
			break;
		}
	}	
	cout<<endl;
	strcpy(stu[count].tel,tel);	
	char QQ[20];
	for(int r5=0;r5<100;r5++)
	{
		cout<<"~亲~请输入QQ￣▽￣:";
		cin>>QQ;
		int t=0;
		for(int j=0;QQ[j];j++)
		{
			if(QQ[j]>='A'&&QQ[j]<='Z'||QQ[j]>='a'&&QQ[j]<='z')
			{
				t=t+1;
				if(t>0)
				{
					cout<<endl<<"亲~您输入的QQ不对哦~~"<<endl<<endl;
					break;
				}
			}

		}	
		if(t==0)
		{
			r5=200;
			break;
		}
	}	
	cout<<endl;
	strcpy(stu[count].QQ,QQ);
	cout<<"~亲~请输入E_mail (￣0 ￣)y:";
	char E_mail[20];
	cin>>E_mail;
	cout<<endl;
	strcpy(stu[count].E_mail,E_mail);
	count++;
	cout<<"~~亲~添加完了吧.........︿(￣︶￣)︽(￣︶￣)︿飛.飛.飛. "<<endl;
	cout<<endl<<"哈哈......(→_→).......按任意键继续哈~~"<<endl;
	getch();
	system("CLS");
}
void AddressBook::alter()
{
	cout<<endl<<endl<<"                 欢迎来到修改页面...........●▽●........"<<endl<<endl;
	cout<<"~亲~请输入修改人的学号...(Ｕ３Ｕ*)：";
	char num[20];
	cin>>num;
	int ln=find(num);
	ifstream infile("text.txt",ios::in);				//首先在文件中找到你要修改数据的位置
	if(!infile)
	{cerr<<"open error!.....文件打不开，快说，是不是你偷走的...[蔑视](￣_,￣ )"<<endl;
	 exit(1);
	}
	char b[300][20];
	for(int i=0;i<300;i=i+7)
	{
		infile>>b[i];
		if(strcmp(b[i],"\0"))					//再将文件中的数据全部写入数组b中
		{
			for(int p=1;p<7;p++)
			{
				infile>>b[i+p];
				k=k+1;
			}
		}	
	}
	infile.close ();
	ofstream outfile("text.txt",ios::out);
	if(!outfile)
	{cerr<<"open error!.....文件打不开，快说，是不是你偷走的...[蔑视](￣_,￣ )"<<endl;
	 exit(1);
	}
	for(int j=0;j<k*7;j++)
	{
		if(j==ln)
		{					//再找到对应位置修改对应的数据后重新写入文件中
			outfile<<b[j]<<endl;
			cout<<"*******************************************************************************"<<endl<<endl<<endl;
			cout<<"~亲~请输入要修改的内容：                                   输入t退出"<<endl<<endl;
			cout<<"1.姓名	2.年龄	3.地址	4.电话	5.QQ	6.E_mail"<<endl<<endl<<endl;
			cout<<"*******************************************************************************"<<endl;
			char x;
			cin>>x;
			if(x>'0'&&x<'8')
			{
				switch(x)
				{	
		
					case '1':
						cout<<endl<<endl<<"............请输入名字0.0:";
						char name2[20];
						cin>>name2;
						strcpy(b[j+1],name2);
						cout<<"\t诶呦，不错呦~~恭喜你修改成功~~(:_;) ";
						break;
					case '2':
						cout<<endl<<endl<<"............请输入年龄0.0:";
						char age2[20];
						cin>>age2;
						strcpy(b[j+2],age2);
						cout<<"\t诶呦，不错呦~~恭喜你修改成功~~(:_;)";
						break;
					case '3':
						cout<<endl<<endl<<"............请输入你的地址0.0:";
						char addr2[20];
						cin>>addr2;
						strcpy(b[j+3],addr2);
						cout<<"\t诶呦，不错呦~~恭喜你修改成功~~(:_;)";
						break;
					case '4':
						cout<<endl<<endl<<"............请输入你的电话0.0:";
						char tel2[20];
						cin>>tel2;
						strcpy(b[j+4],tel2);
						cout<<"\t诶呦，不错呦~~恭喜你修改成功~~(:_;)";
						break;
					case '5':
						cout<<endl<<endl<<"............请输入你的QQ0.0:";
						char QQ2[20];
						cin>>QQ2;
						strcpy(b[j+5],QQ2);
						cout<<"\t诶呦，不错呦~~恭喜你修改成功~~(:_;)";
						break;
					case '6':
						cout<<endl<<endl<<"............请输入你的油箱(~￣▽￣)~[]0.0:";
						char E_mail2[20];
						cin>>E_mail2;
						strcpy(b[j+6],E_mail2);
						cout<<"诶呦，不错呦~~恭喜你修改成功~~(:_;)"<<endl;
						break;
				}
			}
			else
			{
					cout<<"你说你是不是傻~~┑(￣▽ ￣)┍,重新输入吧！"<<endl;
					getch();
					system("CLS");
					alter();
			}
			
		}
		else if(strcmp(b[j],"\0")!=0)
		{
			outfile<<b[j]<<endl;                   //其他数据直接写入文件中
		}
		else
			break;
	}
	cout<<endl<<"哈哈......(→_→).......按任意键继续哈~~"<<endl;
	getch();
	system("CLS");
}
void AddressBook::del()
{
	cout<<endl<<endl<<"                 欢迎来到删除页面...........⊙ω⊙........"<<endl<<endl;
	cout<<endl<<"~亲~请输入删除人的学号...(Ｕ３Ｕ*)：";
	char num[20];
	cin>>num;
	cout<<endl;
	int ln=find(num);							//删除函数，先找到需要删除的数据在文件中的位置
	ifstream infile("text.txt",ios::in);
	if(!infile)
	{cerr<<"open error!.....文件打不开，快说，是不是你偷走的...[蔑视](￣_,￣ )"<<endl;
	 exit(1);
	}
	char b[300][20];
	for(int i=0;i<300;i=i+7)
	{
		infile>>b[i];
		if(strcmp(b[i],"\0"))
		{
			for(int p=1;p<7;p++)
			{
				infile>>b[i+p];                              //将全部数据先写入数组b中
				k=k+1;
			}
		}	
	}
	infile.close ();
	ofstream outfile("text.txt",ios::out);
	if(!outfile)
	{cerr<<"open error!.....文件打不开，快说，是不是你偷走的...[蔑视](￣_,￣ )"<<endl;
	 exit(1);
	}
	for(int j=0;j<k*7;j++)
	{
		if(j==ln)
		{
			j=j+6;                               //跳过需要删除的部分，将其他数据直接写入文件中
			cout<<"诶呦，删除成功了！是不是后悔了，可惜没有后悔药.....（ ￣ー￣）[冷笑]"<<endl;

		}
		else if(strcmp(b[j],"\0")!=0)
		{
			outfile<<b[j]<<endl;
		}
		else
			break;
	}	
		outfile.close ();
		cout<<endl<<"哈哈......(→_→).......按任意键继续哈~~"<<endl;
		getch();
		system("CLS");
}

void AddressBook::save()
{
	cout<<endl<<endl<<"                 欢迎来到保存页面...........⊙ω⊙........"<<endl<<endl;
	ofstream outfile("text.txt",ios::app);
	if(!outfile)
	{cerr<<"open error!.....文件打不开，快说，是不是你偷走的...[蔑视](￣_,￣ )"<<endl;
	 exit(1);
	}
	cout<<"快输入要保存人的学号○（＊￣︶￣＊）○：";
	char num1[20];
	cin>>num1;
    int i;
	int j=0;
	for(i=0;i<count;i++)
	{
     	if(strcmp(num1,stu[i].num)==0)
		{
			outfile<<stu[i].num<<endl;
			outfile<<stu[i].name<<endl;                        //将内存中的数据直接写入文件中
			outfile<<stu[i].age<<endl;
			outfile<<stu[i].addr<<endl;
			outfile<<stu[i].tel<<endl;
			outfile<<stu[i].QQ<<endl;                       
			outfile<<stu[i].E_mail<<endl;
			cout<<endl<<endl<<"亲~~............保存成功了！....看得出是天才啊~(～o￣▽￣)～o ~。。。"<<endl;
		}
		else if(strcmp(num1,"t")==0)
		{
			i=count;
		}
        else
		{
			if(j==count-1)
			{
				system("CLS");
				cout<<endl<<endl<<"~亲~这个人是不是人间蒸发了~~~~o(*￣︶￣*)o"<<endl<<endl;
				cout<<"亲~~请重新输入学号~          "<<endl;
				save();
			}	
			j=j+1;

		}
	}	
	cout<<endl<<"哈哈......(→_→).......按任意键继续哈~~"<<endl;
	getch();
	system("CLS");
	outfile.close ();
}
void AddressBook::query()
{
	cout<<endl<<endl<<"                 欢迎来到查询页面...........⊙ω⊙........"<<endl<<endl;
	cout<<"听说你要查水表，偶不，是查人.......<(￣︶￣)↗"<<endl<<endl;
	getch();
	cout<<"就不给你查.........┗(｀o′)┓哼┏(｀○′)┛哼┏(｀o′)┓哈┗(｀O′)┛兮"<<endl<<endl;
	getch();
	cout<<"叫声帅哥给你查.......(￣_,￣ )"<<endl<<endl;
	getch();
	cout<<"好好好，给你查啦.........╮(￣▽￣)╭"<<endl<<endl;
	cout<<"想怎么查你选：         1.学号查询	          2.姓名查询	"<<endl;
	char x;
	cin>>x;
	if(x=='1')
	{
		ifstream infile("text.txt",ios::in);
		if(!infile)
		{cerr<<"open error!.....文件打不开，快说，是不是你偷走的...[蔑视](￣_,￣ )"<<endl;
		 exit(1);
		}
		cout<<"快输入要查询人的学号○（＊￣︶￣＊）○:";
		char num1[20];
		cin>>num1;
		int i;
		int j=0;
		char a[300][20];
		cout<<endl;
		for(i=0;i<300;i=i+7)						//找到需要查找数据的位置，并赋给数组a，并输出
		{
			infile>>a[i];
     		if(strcmp(num1,a[i])==0)
			{
				for(int p=1;p<7;p++)
					infile>>a[i+p];
				cout<<"学号："<<a[i]<<endl;
				cout<<"姓名："<<a[i+1]<<endl;
				cout<<"年龄："<<a[i+2]<<endl;
				cout<<"地址："<<a[i+3]<<endl;
				cout<<"电话："<<a[i+4]<<endl;
				cout<<"QQ："<<a[i+5]<<endl;
				cout<<"E_mail："<<a[i+6]<<endl;
				cout<<"It's his information !"<<endl<<endl;
				cout<<"快说对不对......╰（￣▽￣）╭ "<<endl;
				cout<<endl;
				break;
			}
			else if(strcmp(num1,"t")==0)
			{
				i=300;
			}
			else
			{
				j=j+1;
				if(j==30)
				{
					system("CLS");
					cout<<"~亲~这货是不是人间蒸发了~~~~o(*￣︶￣*)o"<<endl;
					query();
				}
			}
		
		}
		infile.close ();
	}
	else if(x=='2')
	{
		ifstream infile("text.txt",ios::in);
		if(!infile)
		{cerr<<"open error!.....文件打不开，快说，是不是你偷走的...[蔑视](￣_,￣ )"<<endl;
		 exit(1);
		}
		cout<<"快输入要查询人的姓名○（＊￣︶￣＊）○:";
		char num1[20];
		cin>>num1;
		int i;
		int j=0;
		char a[300][20];
		for(i=1;i<300;i=i+7)
		{
			infile>>a[i];
     		if(strcmp(num1,a[i])==0)                       //同上
			{
				for(int p=1;p<7;p++)
					infile>>a[i+p];
				cout<<"学号："<<a[i-7]<<endl;
				cout<<"姓名："<<a[i]<<endl;
				cout<<"年龄："<<a[i+1]<<endl;
				cout<<"地址："<<a[i+2]<<endl;
				cout<<"电话："<<a[i+3]<<endl;
				cout<<"QQ："<<a[i+4]<<endl;
				cout<<"E_mail："<<a[i+5]<<endl;
				cout<<"It's his information !"<<endl;
				cout<<"快说对不对......╰（￣▽￣）╭ "<<endl;
				cout<<endl;
				break;
			}
			else if(strcmp(num1,"t")==0)
			{
				i=300;
			}
			else
			{
				j=j+1;
				if(j==30)
				{
					cout<<"~亲~这货是不是人间蒸发了~~~~o(*￣︶￣*)o"<<endl;
					cout<<"~亲~这货是不是人间蒸发了~~~~o(*￣︶￣*)o"<<endl;
					query();
				}
			}
		
		}
		infile.close ();
	}
	
	else if(x=='t')
	{
	}
	else
	{
		cout<<"傻逼了吧，是不是打错了.........╭∩╮(︶︿︶）╭∩╮"<<endl;
	}
	cout<<endl<<"哈哈......(→_→).......按任意键继续哈~~"<<endl;
	getch();
	system("CLS");
}
void AddressBook::display()
{
	ifstream infile("text.txt",ios::in);
	if(!infile)
	{cerr<<"open error!.....文件打不开，快说，是不是你偷走的...[蔑视](￣_,￣ )"<<endl;
	 exit(1);
	}                                                 //直接从文件里把全部数据赋给数组a，并输出
    int i;
	int j=0;
	char a[300][20];                                      
	cout<<endl<<endl<<endl;
	cout<<"~亲，这就是全部了~~~~~<(￣︶￣)> []~(￣▽￣)~"<<endl<<endl;
	for(i=0;i<300;i=i+7)
	{
		infile>>a[i];
		if(strcmp(a[i],"\0"))
		{
			for(int p=1;p<7;p++)
				infile>>a[i+p];
			cout<<" 学号："<<a[i]<<endl;
			cout<<" 姓名："<<a[i+1]<<endl;
			cout<<" 年龄："<<a[i+2]<<endl;
			cout<<" 地址："<<a[i+3]<<endl;
			cout<<" 电话："<<a[i+4]<<endl;
			cout<<" QQ："<<a[i+5]<<endl;
			cout<<" E_mail："<<a[i+6]<<endl;
			cout<<" It's your information !"<<endl<<endl;
			j=j+1;
		}
		else
		{
			if(j==0)
			{
				cout<<"亲~~通讯录什么都没有啊~你也太懒了吧....."<<endl;
				break;
			}
		}
	}
	infile.close ();
	cout<<endl<<"哈哈......(→_→).......按任意键继续哈~~"<<endl;
	getch();
	system("CLS");
}
int find(char num[])
{
	ifstream infile("text.txt",ios::in);
	if(!infile)
	{cerr<<"open error!.....文件打不开，快说，是不是你偷走的...[蔑视](￣_,￣ )"<<endl;
	 exit(1);
	}
    int i;
	int ln;
	char a[300][20];
	for(i=0;i<300;i=i+7)                           //find函数通过比较文件里的函数，找到对应的位置
	{
		infile>>a[i];
     	if(strcmp(num,a[i])==0)
		{
			ln=i/7;
			infile.close();
			return ln;
		}
	}
	cout<<"~亲~这货是不是人间蒸发了~~~~o(*￣︶￣*)o"<<endl;
	return -1;
}
int main()
{
	AddressBook b;
	int a=1;					//初始界面
	do
	{
		cout<<endl<<endl;
		cout<<"    ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★  "<<endl;
		cout<<"    ※                                                                    ※  "<<endl;
    	cout<<"    △             ☆☆☆☆☆ 欢 迎 使 用 班 级 通 讯 录 ☆☆☆☆☆       △  "<<endl;
		cout<<"    ※                                                                    ※  "<<endl;
	    cout<<"    ※                        ~<请选择你要使用的要求>~                    ※  "<<endl;
		cout<<"    ※                                                                    ※  "<<endl;
	    cout<<"    ※                           【1】增加联系人                          ※  "<<endl;
      	cout<<"    ※                           【2】修改联系人                          ※  "<<endl;
	    cout<<"    ※                           【3】删除联系人                          ※  "<<endl;
	    cout<<"    ※                           【4】保存联系人                          ※  "<<endl;
	    cout<<"    ※                           【5】查询联系人                          ※  "<<endl;
	    cout<<"    ※                           【6】预览                                ※  "<<endl;
	    cout<<"    ※                           【7】退出                                ※  "<<endl;
	    cout<<"    ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★  "<<endl<<endl;
		char w[100];
		char  x;
		cin>>w;
		if(strlen(w)==1)
		{
			x=w[0];
		}
		system("CLS");
		if(x>'0'&&x<'8')
		{
			switch(x)                           //界面里的选择
			{
				case('1'): b.add(); break;
				case('2'): b.alter(); break;
				case('3'): b.del(); break;
				case('4'): b.save(); break;
				case('5'): b.query(); break;
				case('6'): b.display(); break;
				case('7'): 
					{cout<<endl<<endl<<endl<<"亲~~真的要说再见了吗?              1.逗你的~~              2.我就是要退出~~"<<endl;
					char d;
					cin>>d;
					if(d=='1')
					{
					}
					else if(d=='2')
					{
						cout<<"不是很有能耐吗，退出啊~~(＠＾０＾)"<<endl<<endl;
						getch();
						cout<<"我悄悄告诉你其实是3.......╮(￣▽￣)╭"<<endl<<endl;
						getch();
						cout<<"好吧，是2"<<endl<<endl;
						cin>>d;
						if(d=='2')
						{
							a=0;
						}
					}
					system("CLS");
					break;}
			}
		}
		else
		{
			system("CLS");
			cout<<endl<<endl<<"\t~~~~~~~~~~~~~~~~~~~~呵呵哒,(→_→)傻逼了吧~~~~~~~~~~~~~~~~~~~~"<<endl;
			getch();
			system("CLS");
		}
	}while(a);
	return 0;
}