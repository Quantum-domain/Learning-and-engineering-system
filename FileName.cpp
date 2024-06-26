#include<iostream>
#include<string>
#define MAX 1000
using namespace std;
struct Person
{
	string m_Name;//ͨѶ������
	int m_Sex;//�Ա�1�� 2Ů
	int m_Age;//����
	string m_Phone;//�绰
	string m_Addr;//סַ
};
struct Addressbooks
{
	struct Person personArray[MAX];
	int m_size;
};
//��ʾ��Ļ
void showfunction()
{
	cout << "* * * * * * * * * * * * * * * * * *" << endl;
	cout << "* * * * * 1�������ϵ�� * * * * * *" << endl;
	cout << "* * * * * 2����ʾ��ϵ�� * * * * * *" << endl;
	cout << "* * * * * 3��ɾ����ϵ�� * * * * * *" << endl;
	cout << "* * * * * 4��������ϵ�� * * * * * *" << endl;
	cout << "* * * * * 5���޸���ϵ�� * * * * * *" << endl;
	cout << "* * * * * 6�������ϵ�� * * * * * *" << endl;
	cout << "* * * * * 0���˳�ͨѶ¼ * * * * * *" << endl;
	cout << "* * * * * * * * * * * * * * * * * *" << endl;
}
//�����ϵ�˺���
void addperson(Addressbooks* abs)
{
	if (abs->m_size == MAX)
	{
		cout << "��ϵ���������޷���ӡ�" << endl;
	}
	else
	{
		//����
		string name;
		cout << "���������֣�";
		cin >> name;
		abs->personArray[abs->m_size].m_Name = name;
		//�Ա�
		cout << "�������Ա�" << '\n'
			<< "(1--��)" << '\n'
			<< "(2--Ů)" << '\n'
			<< ":";
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_Age = sex;
				break;
			}
			cout << "�����������������" << endl;
		}
		//����
		int age = 0;
		cout << "���������䣺";
		cin >> age;
		abs->personArray[abs->m_size].m_Age = age;
		//��ϵ�绰
		string phone = "";
		cout << "��������ϵ�绰��";
		cin >> phone;
		abs->personArray[abs->m_size].m_Phone = phone;
		//��ͥסַ
		string addr = "";
		cout << "�������ͥ��ַ��";
		cin >> addr;
		abs->personArray[abs->m_size].m_Addr = addr;
		abs->m_size++;
		cout << "��ӳɹ���"<<'\n';
	}
}
void showperson(Addressbooks *abs)
{
	if (abs->m_size==0)
	{
		cout << "��ǰ����Ϊ0" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << '\t';
			cout << "�Ա�" << (abs->personArray[i].m_Sex == 1?"��":"Ů") << '\t';
			cout << "���䣺" << abs->personArray[i].m_Age << '\t';
			cout << "��ϵ�绰��" << abs->personArray[i].m_Phone << '\t';
			cout << "��ͥסַ��" << abs->personArray[i].m_Addr << endl;
		}
	}
}
//ɾ����ϵ�ˣ��ȴ������Һ��������ҵ���ϵ�˷�������λ�ã�û�ҵ��򷵻�-1��
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i <abs->m_size; i++)
	{
		if (abs->personArray[i].m_Name == name) 
		{
			return i;
		}
	}
	return -1;
}
void deletePerson(Addressbooks* abs)
{
	cout << "����������ɾ������ϵ�ˣ�";
	string name = "";
	cin >> name;
	int ret = isExist(abs, name);//abs������ǵ�ַ�����Բ���Ҫȡַ
	if (ret!=-1)
	{
		for (int i = ret; i < abs->m_size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
}
void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ�ˣ�";
	string name = "";
	cin >> name;
	int ret = isExist(abs, name);
	if (ret!=1)
	{
		cout<<"������" << abs->personArray[ret].m_Name << '\t';
		cout <<"����" << abs->personArray[ret].m_Age << '\t';
		cout <<"�Ա�" << abs->personArray[ret].m_Sex << '\t';
		cout<<"��ϵ�绰��" << abs->personArray[ret].m_Phone << '\t';
		cout << "��ͥ��ַ��" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
}
void modifyPerson(Addressbooks* abs)
{
	cout << "�����������޸ĵ���ϵ�ˣ�";
	string name = "";
	cin >> name;
	int ret = isExist(abs, name);//abs������ǵ�ַ�����Բ���Ҫȡַ
	if (ret != -1)
	{
		cout << "���������֣�";
		cin >> name;
		abs->personArray[abs->m_size].m_Name = name;
		//�Ա�
		cout << "�������Ա�" << '\n'
			<< "(1--��)" << '\n'
			<< "(2--Ů)" << '\n'
			<< ":";
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_Age = sex;
				break;
			}
			cout << "�����������������" << endl;
		}
		//����
		int age = 0;
		cout << "���������䣺";
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//��ϵ�绰
		string phone = "";
		cout << "��������ϵ�绰��";
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//��ͥסַ
		string addr = "";
		cout << "�������ͥ��ַ��";
		cin >> addr;
		abs->personArray[ret].m_Addr = addr;
		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
}
void cleanPerson(Addressbooks* abs)
{
	abs->m_size = 0;
	cout << "ͨѶ¼��ȫ�����" << endl;
}
int main()
{
	Addressbooks abs;//ͨѶ¼Դ
	abs.m_size = 0;//��ʼ��ͨѶ¼����
	int select = 0;
	while (true)
	{
		showfunction();
		cin >> select;
		switch (select)
		{
		case 1://�����ϵ��
			addperson(&abs);
			break;
		case 2://��ʾ��ϵ��
			showperson(&abs);
			break;
		case 3://ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4://������ϵ��
			findPerson(&abs);
			break;
		case 5://�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://�����ϵ��
			cleanPerson(&abs);
			break;
		case 0://�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}