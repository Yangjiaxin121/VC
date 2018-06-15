#include<iostream>                    //��������ͷ�ļ�
#include<conio.h>
#include<fstream>
#include<string>
#include<string.h>
#include<stdlib.h>
using namespace std;
class AddressBook;                         
class Student                           //����绰��Book���ѧ����ϢStudent�࣬����Book����ΪStudent����Ԫ��
{
public:
	friend AddressBook;
private:
	char num[20];                      //�������ѧ����Ϣ
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
	void add();               //���Ӻ���
	void alter();            //�޸ĺ���
	void del();				//ɾ������
	void save();                              //���溯��
	void query();							 //��ѯ����
	void display();                         //�򵥵�Ԥ�����ܺ���
protected:
	Student stu[30];						//����Student���͵Ķ�������
	static int count;						//��̬��Աcount��k��������
	static int k;
};
int AddressBook::count=0;
int AddressBook::k=0;
int find(char num[]);						//����find�����������������ļ���λ��
void AddressBook::add()
{
	cout<<endl<<endl<<"                 ��ӭ�������ҳ��...........~(������)~*........"<<endl<<endl;
	cout<<"                                    ��Ӻ�ǵ������˵�ѡ4����Ŷ~~~������������ "<<endl;
	char num[20];
	for(int r1=0;r1<100;r1++)
	{
		cout<<"~��~������ѧ��(=���أ�=):";
		cin>>num;			
		int t=0;
		for(int j=0;num[j]!='\0';j++)
		{
			if(num[j]>='A'&&num[j]<='Z'||num[j]>='a'&&num[j]<='z')
			{
				t=t+1;
				if(t>0)
				{
					cout<<endl<<"��~�������ѧ�Ų���Ŷ~~"<<endl<<endl;
					break;
				}
			}

		}
		if(t==0)
		{
			r1=200;
			break;
		}
	}										//add�����������ѧ���ж��Ƿ��ظ���Ȼ����������������Ϣ�����뵽�ڴ���
	for(int i=0;i<count;i++)
	{
		if(strcmp(num,stu[i].num)==0)
		{
			cout<<"����~~ѧ���ظ������ǲ��Ǵ����~ (�����`����)~"<<endl;
			system("CLS");
			add();						//goto�ص�A����������
		}
	}
	cout<<endl;
	strcpy(stu[count].num,num);	
	char name[20];
	for(int r2=0;r2<100;r2++)
	{
		cout<<"~��~���������֣� 3�� :";           //����������Ϣ�������Ƶ�����������
		cin>>name;
		int t=0;
		for(int j=0;name[j];j++)
		{
			if(name[j]>='0'&&name[j]<='9')
			{
				t=t+1;
				if(t>0)
				{
					cout<<endl<<"��~����������ָ�ʽ����Ŷ~~"<<endl<<endl;
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
		cout<<"~��~������������� �� :";
		cin>>age;		
		int t=0;
		for(int j=0;age[j];j++)
		{
			if(age[j]>='A'&&age[j]<='Z'||age[j]>='a'&&age[j]<='z')
			{
				t=t+1;
				if(t>0)
				{
					cout<<endl<<"��~����������䲻��Ŷ~~"<<endl<<endl;
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
	cout<<"~��~�������ַ�� 3�� :";
	char addr[20];
	cin>>addr;
	cout<<endl;
	strcpy(stu[count].addr,addr);
	char tel[20];
	for(int r4=0;r4<100;r4++)
	{
		cout<<"~��~������绰���أ�:";
		cin>>tel;	
		int t=0;
		for(int j=0;tel[j];j++)
		{
			if(tel[j]>='A'&&tel[j]<='Z'||tel[j]>='a'&&tel[j]<='z')
			{
				t=t+1;
				if(t>0)
				{
					cout<<endl<<"��~������ĵ绰����Ŷ~~"<<endl<<endl;
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
		cout<<"~��~������QQ������:";
		cin>>QQ;
		int t=0;
		for(int j=0;QQ[j];j++)
		{
			if(QQ[j]>='A'&&QQ[j]<='Z'||QQ[j]>='a'&&QQ[j]<='z')
			{
				t=t+1;
				if(t>0)
				{
					cout<<endl<<"��~�������QQ����Ŷ~~"<<endl<<endl;
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
	cout<<"~��~������E_mail (��0 ��)y:";
	char E_mail[20];
	cin>>E_mail;
	cout<<endl;
	strcpy(stu[count].E_mail,E_mail);
	count++;
	cout<<"~~��~������˰�.........��(�����)��(�����)���w.�w.�w. "<<endl;
	cout<<endl<<"����......(��_��).......�������������~~"<<endl;
	getch();
	system("CLS");
}
void AddressBook::alter()
{
	cout<<endl<<endl<<"                 ��ӭ�����޸�ҳ��...........�񨌡�........"<<endl<<endl;
	cout<<"~��~�������޸��˵�ѧ��...(�գ���*)��";
	char num[20];
	cin>>num;
	int ln=find(num);
	ifstream infile("text.txt",ios::in);				//�������ļ����ҵ���Ҫ�޸����ݵ�λ��
	if(!infile)
	{cerr<<"open error!.....�ļ��򲻿�����˵���ǲ�����͵�ߵ�...[����](��_,�� )"<<endl;
	 exit(1);
	}
	char b[300][20];
	for(int i=0;i<300;i=i+7)
	{
		infile>>b[i];
		if(strcmp(b[i],"\0"))					//�ٽ��ļ��е�����ȫ��д������b��
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
	{cerr<<"open error!.....�ļ��򲻿�����˵���ǲ�����͵�ߵ�...[����](��_,�� )"<<endl;
	 exit(1);
	}
	for(int j=0;j<k*7;j++)
	{
		if(j==ln)
		{					//���ҵ���Ӧλ���޸Ķ�Ӧ�����ݺ�����д���ļ���
			outfile<<b[j]<<endl;
			cout<<"*******************************************************************************"<<endl<<endl<<endl;
			cout<<"~��~������Ҫ�޸ĵ����ݣ�                                   ����t�˳�"<<endl<<endl;
			cout<<"1.����	2.����	3.��ַ	4.�绰	5.QQ	6.E_mail"<<endl<<endl<<endl;
			cout<<"*******************************************************************************"<<endl;
			char x;
			cin>>x;
			if(x>'0'&&x<'8')
			{
				switch(x)
				{	
		
					case '1':
						cout<<endl<<endl<<"............����������0.0:";
						char name2[20];
						cin>>name2;
						strcpy(b[j+1],name2);
						cout<<"\t���ϣ�������~~��ϲ���޸ĳɹ�~~(:_;) ";
						break;
					case '2':
						cout<<endl<<endl<<"............����������0.0:";
						char age2[20];
						cin>>age2;
						strcpy(b[j+2],age2);
						cout<<"\t���ϣ�������~~��ϲ���޸ĳɹ�~~(:_;)";
						break;
					case '3':
						cout<<endl<<endl<<"............��������ĵ�ַ0.0:";
						char addr2[20];
						cin>>addr2;
						strcpy(b[j+3],addr2);
						cout<<"\t���ϣ�������~~��ϲ���޸ĳɹ�~~(:_;)";
						break;
					case '4':
						cout<<endl<<endl<<"............��������ĵ绰0.0:";
						char tel2[20];
						cin>>tel2;
						strcpy(b[j+4],tel2);
						cout<<"\t���ϣ�������~~��ϲ���޸ĳɹ�~~(:_;)";
						break;
					case '5':
						cout<<endl<<endl<<"............���������QQ0.0:";
						char QQ2[20];
						cin>>QQ2;
						strcpy(b[j+5],QQ2);
						cout<<"\t���ϣ�������~~��ϲ���޸ĳɹ�~~(:_;)";
						break;
					case '6':
						cout<<endl<<endl<<"............�������������(~������)~[]0.0:";
						char E_mail2[20];
						cin>>E_mail2;
						strcpy(b[j+6],E_mail2);
						cout<<"���ϣ�������~~��ϲ���޸ĳɹ�~~(:_;)"<<endl;
						break;
				}
			}
			else
			{
					cout<<"��˵���ǲ���ɵ~~��(���� ��)��,��������ɣ�"<<endl;
					getch();
					system("CLS");
					alter();
			}
			
		}
		else if(strcmp(b[j],"\0")!=0)
		{
			outfile<<b[j]<<endl;                   //��������ֱ��д���ļ���
		}
		else
			break;
	}
	cout<<endl<<"����......(��_��).......�������������~~"<<endl;
	getch();
	system("CLS");
}
void AddressBook::del()
{
	cout<<endl<<endl<<"                 ��ӭ����ɾ��ҳ��...........�Ѧء�........"<<endl<<endl;
	cout<<endl<<"~��~������ɾ���˵�ѧ��...(�գ���*)��";
	char num[20];
	cin>>num;
	cout<<endl;
	int ln=find(num);							//ɾ�����������ҵ���Ҫɾ�����������ļ��е�λ��
	ifstream infile("text.txt",ios::in);
	if(!infile)
	{cerr<<"open error!.....�ļ��򲻿�����˵���ǲ�����͵�ߵ�...[����](��_,�� )"<<endl;
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
				infile>>b[i+p];                              //��ȫ��������д������b��
				k=k+1;
			}
		}	
	}
	infile.close ();
	ofstream outfile("text.txt",ios::out);
	if(!outfile)
	{cerr<<"open error!.....�ļ��򲻿�����˵���ǲ�����͵�ߵ�...[����](��_,�� )"<<endl;
	 exit(1);
	}
	for(int j=0;j<k*7;j++)
	{
		if(j==ln)
		{
			j=j+6;                               //������Ҫɾ���Ĳ��֣�����������ֱ��д���ļ���
			cout<<"���ϣ�ɾ���ɹ��ˣ��ǲ��Ǻ���ˣ���ϧû�к��ҩ.....�� ���`����[��Ц]"<<endl;

		}
		else if(strcmp(b[j],"\0")!=0)
		{
			outfile<<b[j]<<endl;
		}
		else
			break;
	}	
		outfile.close ();
		cout<<endl<<"����......(��_��).......�������������~~"<<endl;
		getch();
		system("CLS");
}

void AddressBook::save()
{
	cout<<endl<<endl<<"                 ��ӭ��������ҳ��...........�Ѧء�........"<<endl<<endl;
	ofstream outfile("text.txt",ios::app);
	if(!outfile)
	{cerr<<"open error!.....�ļ��򲻿�����˵���ǲ�����͵�ߵ�...[����](��_,�� )"<<endl;
	 exit(1);
	}
	cout<<"������Ҫ�����˵�ѧ�š𣨣������������";
	char num1[20];
	cin>>num1;
    int i;
	int j=0;
	for(i=0;i<count;i++)
	{
     	if(strcmp(num1,stu[i].num)==0)
		{
			outfile<<stu[i].num<<endl;
			outfile<<stu[i].name<<endl;                        //���ڴ��е�����ֱ��д���ļ���
			outfile<<stu[i].age<<endl;
			outfile<<stu[i].addr<<endl;
			outfile<<stu[i].tel<<endl;
			outfile<<stu[i].QQ<<endl;                       
			outfile<<stu[i].E_mail<<endl;
			cout<<endl<<endl<<"��~~............����ɹ��ˣ�....���ó�����Ű�~(��o������)��o ~������"<<endl;
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
				cout<<endl<<endl<<"~��~������ǲ����˼�������~~~~o(*�����*)o"<<endl<<endl;
				cout<<"��~~����������ѧ��~          "<<endl;
				save();
			}	
			j=j+1;

		}
	}	
	cout<<endl<<"����......(��_��).......�������������~~"<<endl;
	getch();
	system("CLS");
	outfile.close ();
}
void AddressBook::query()
{
	cout<<endl<<endl<<"                 ��ӭ������ѯҳ��...........�Ѧء�........"<<endl<<endl;
	cout<<"��˵��Ҫ��ˮ��ż�����ǲ���.......<(�����)�J"<<endl<<endl;
	getch();
	cout<<"�Ͳ������.........��(��o��)���ߩ�(����)���ߩ�(��o��)������(��O��)����"<<endl<<endl;
	getch();
	cout<<"����˧������.......(��_,�� )"<<endl<<endl;
	getch();
	cout<<"�úúã��������.........�r(������)�q"<<endl<<endl;
	cout<<"����ô����ѡ��         1.ѧ�Ų�ѯ	          2.������ѯ	"<<endl;
	char x;
	cin>>x;
	if(x=='1')
	{
		ifstream infile("text.txt",ios::in);
		if(!infile)
		{cerr<<"open error!.....�ļ��򲻿�����˵���ǲ�����͵�ߵ�...[����](��_,�� )"<<endl;
		 exit(1);
		}
		cout<<"������Ҫ��ѯ�˵�ѧ�š𣨣������������:";
		char num1[20];
		cin>>num1;
		int i;
		int j=0;
		char a[300][20];
		cout<<endl;
		for(i=0;i<300;i=i+7)						//�ҵ���Ҫ�������ݵ�λ�ã�����������a�������
		{
			infile>>a[i];
     		if(strcmp(num1,a[i])==0)
			{
				for(int p=1;p<7;p++)
					infile>>a[i+p];
				cout<<"ѧ�ţ�"<<a[i]<<endl;
				cout<<"������"<<a[i+1]<<endl;
				cout<<"���䣺"<<a[i+2]<<endl;
				cout<<"��ַ��"<<a[i+3]<<endl;
				cout<<"�绰��"<<a[i+4]<<endl;
				cout<<"QQ��"<<a[i+5]<<endl;
				cout<<"E_mail��"<<a[i+6]<<endl;
				cout<<"It's his information !"<<endl<<endl;
				cout<<"��˵�Բ���......�t�����������q "<<endl;
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
					cout<<"~��~����ǲ����˼�������~~~~o(*�����*)o"<<endl;
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
		{cerr<<"open error!.....�ļ��򲻿�����˵���ǲ�����͵�ߵ�...[����](��_,�� )"<<endl;
		 exit(1);
		}
		cout<<"������Ҫ��ѯ�˵������𣨣������������:";
		char num1[20];
		cin>>num1;
		int i;
		int j=0;
		char a[300][20];
		for(i=1;i<300;i=i+7)
		{
			infile>>a[i];
     		if(strcmp(num1,a[i])==0)                       //ͬ��
			{
				for(int p=1;p<7;p++)
					infile>>a[i+p];
				cout<<"ѧ�ţ�"<<a[i-7]<<endl;
				cout<<"������"<<a[i]<<endl;
				cout<<"���䣺"<<a[i+1]<<endl;
				cout<<"��ַ��"<<a[i+2]<<endl;
				cout<<"�绰��"<<a[i+3]<<endl;
				cout<<"QQ��"<<a[i+4]<<endl;
				cout<<"E_mail��"<<a[i+5]<<endl;
				cout<<"It's his information !"<<endl;
				cout<<"��˵�Բ���......�t�����������q "<<endl;
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
					cout<<"~��~����ǲ����˼�������~~~~o(*�����*)o"<<endl;
					cout<<"~��~����ǲ����˼�������~~~~o(*�����*)o"<<endl;
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
		cout<<"ɵ���˰ɣ��ǲ��Ǵ����.........�q�ɨr(���ᣩ�q�ɨr"<<endl;
	}
	cout<<endl<<"����......(��_��).......�������������~~"<<endl;
	getch();
	system("CLS");
}
void AddressBook::display()
{
	ifstream infile("text.txt",ios::in);
	if(!infile)
	{cerr<<"open error!.....�ļ��򲻿�����˵���ǲ�����͵�ߵ�...[����](��_,�� )"<<endl;
	 exit(1);
	}                                                 //ֱ�Ӵ��ļ����ȫ�����ݸ�������a�������
    int i;
	int j=0;
	char a[300][20];                                      
	cout<<endl<<endl<<endl;
	cout<<"~�ף������ȫ����~~~~~<(�����)> []~(������)~"<<endl<<endl;
	for(i=0;i<300;i=i+7)
	{
		infile>>a[i];
		if(strcmp(a[i],"\0"))
		{
			for(int p=1;p<7;p++)
				infile>>a[i+p];
			cout<<" ѧ�ţ�"<<a[i]<<endl;
			cout<<" ������"<<a[i+1]<<endl;
			cout<<" ���䣺"<<a[i+2]<<endl;
			cout<<" ��ַ��"<<a[i+3]<<endl;
			cout<<" �绰��"<<a[i+4]<<endl;
			cout<<" QQ��"<<a[i+5]<<endl;
			cout<<" E_mail��"<<a[i+6]<<endl;
			cout<<" It's your information !"<<endl<<endl;
			j=j+1;
		}
		else
		{
			if(j==0)
			{
				cout<<"��~~ͨѶ¼ʲô��û�а�~��Ҳ̫���˰�....."<<endl;
				break;
			}
		}
	}
	infile.close ();
	cout<<endl<<"����......(��_��).......�������������~~"<<endl;
	getch();
	system("CLS");
}
int find(char num[])
{
	ifstream infile("text.txt",ios::in);
	if(!infile)
	{cerr<<"open error!.....�ļ��򲻿�����˵���ǲ�����͵�ߵ�...[����](��_,�� )"<<endl;
	 exit(1);
	}
    int i;
	int ln;
	char a[300][20];
	for(i=0;i<300;i=i+7)                           //find����ͨ���Ƚ��ļ���ĺ������ҵ���Ӧ��λ��
	{
		infile>>a[i];
     	if(strcmp(num,a[i])==0)
		{
			ln=i/7;
			infile.close();
			return ln;
		}
	}
	cout<<"~��~����ǲ����˼�������~~~~o(*�����*)o"<<endl;
	return -1;
}
int main()
{
	AddressBook b;
	int a=1;					//��ʼ����
	do
	{
		cout<<endl<<endl;
		cout<<"    �������������������������������������  "<<endl;
		cout<<"    ��                                                                    ��  "<<endl;
    	cout<<"    ��             ������ �� ӭ ʹ �� �� �� ͨ Ѷ ¼ ������       ��  "<<endl;
		cout<<"    ��                                                                    ��  "<<endl;
	    cout<<"    ��                        ~<��ѡ����Ҫʹ�õ�Ҫ��>~                    ��  "<<endl;
		cout<<"    ��                                                                    ��  "<<endl;
	    cout<<"    ��                           ��1��������ϵ��                          ��  "<<endl;
      	cout<<"    ��                           ��2���޸���ϵ��                          ��  "<<endl;
	    cout<<"    ��                           ��3��ɾ����ϵ��                          ��  "<<endl;
	    cout<<"    ��                           ��4��������ϵ��                          ��  "<<endl;
	    cout<<"    ��                           ��5����ѯ��ϵ��                          ��  "<<endl;
	    cout<<"    ��                           ��6��Ԥ��                                ��  "<<endl;
	    cout<<"    ��                           ��7���˳�                                ��  "<<endl;
	    cout<<"    �������������������������������������  "<<endl<<endl;
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
			switch(x)                           //�������ѡ��
			{
				case('1'): b.add(); break;
				case('2'): b.alter(); break;
				case('3'): b.del(); break;
				case('4'): b.save(); break;
				case('5'): b.query(); break;
				case('6'): b.display(); break;
				case('7'): 
					{cout<<endl<<endl<<endl<<"��~~���Ҫ˵�ټ�����?              1.�����~~              2.�Ҿ���Ҫ�˳�~~"<<endl;
					char d;
					cin>>d;
					if(d=='1')
					{
					}
					else if(d=='2')
					{
						cout<<"���Ǻ����������˳���~~(���ޣ���)"<<endl<<endl;
						getch();
						cout<<"�����ĸ�������ʵ��3.......�r(������)�q"<<endl<<endl;
						getch();
						cout<<"�ðɣ���2"<<endl<<endl;
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
			cout<<endl<<endl<<"\t~~~~~~~~~~~~~~~~~~~~�Ǻ���,(��_��)ɵ���˰�~~~~~~~~~~~~~~~~~~~~"<<endl;
			getch();
			system("CLS");
		}
	}while(a);
	return 0;
}