#include<iostream>
#include<string>
#define MAX 1000
using namespace std;
struct Person
{
	string m_Name;//通讯人名字
	int m_Sex;//性别：1男 2女
	int m_Age;//年龄
	string m_Phone;//电话
	string m_Addr;//住址
};
struct Addressbooks
{
	struct Person personArray[MAX];
	int m_size;
};
//显示字幕
void showfunction()
{
	cout << "* * * * * * * * * * * * * * * * * *" << endl;
	cout << "* * * * * 1、添加联系人 * * * * * *" << endl;
	cout << "* * * * * 2、显示联系人 * * * * * *" << endl;
	cout << "* * * * * 3、删除联系人 * * * * * *" << endl;
	cout << "* * * * * 4、查找联系人 * * * * * *" << endl;
	cout << "* * * * * 5、修改联系人 * * * * * *" << endl;
	cout << "* * * * * 6、清空联系人 * * * * * *" << endl;
	cout << "* * * * * 0、退出通讯录 * * * * * *" << endl;
	cout << "* * * * * * * * * * * * * * * * * *" << endl;
}
//添加联系人函数
void addperson(Addressbooks* abs)
{
	if (abs->m_size == MAX)
	{
		cout << "联系人已满，无法添加。" << endl;
	}
	else
	{
		//名字
		string name;
		cout << "请输入名字：";
		cin >> name;
		abs->personArray[abs->m_size].m_Name = name;
		//性别
		cout << "请输入性别：" << '\n'
			<< "(1--男)" << '\n'
			<< "(2--女)" << '\n'
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
			cout << "输入错误，请重新输入" << endl;
		}
		//年龄
		int age = 0;
		cout << "请输入年龄：";
		cin >> age;
		abs->personArray[abs->m_size].m_Age = age;
		//联系电话
		string phone = "";
		cout << "请输入联系电话：";
		cin >> phone;
		abs->personArray[abs->m_size].m_Phone = phone;
		//家庭住址
		string addr = "";
		cout << "请输入家庭地址：";
		cin >> addr;
		abs->personArray[abs->m_size].m_Addr = addr;
		abs->m_size++;
		cout << "添加成功。"<<'\n';
	}
}
void showperson(Addressbooks *abs)
{
	if (abs->m_size==0)
	{
		cout << "当前数据为0" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << '\t';
			cout << "性别：" << (abs->personArray[i].m_Sex == 1?"男":"女") << '\t';
			cout << "年龄：" << abs->personArray[i].m_Age << '\t';
			cout << "联系电话：" << abs->personArray[i].m_Phone << '\t';
			cout << "家庭住址：" << abs->personArray[i].m_Addr << endl;
		}
	}
}
//删除联系人：先创建查找函数（若找到联系人返回他的位置，没找到则返回-1）
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
	cout << "请输入你想删除的联系人：";
	string name = "";
	cin >> name;
	int ret = isExist(abs, name);//abs本身就是地址，所以不需要取址
	if (ret!=-1)
	{
		for (int i = ret; i < abs->m_size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
}
void findPerson(Addressbooks* abs)
{
	cout << "请输入你要查找的联系人：";
	string name = "";
	cin >> name;
	int ret = isExist(abs, name);
	if (ret!=1)
	{
		cout<<"姓名：" << abs->personArray[ret].m_Name << '\t';
		cout <<"年龄" << abs->personArray[ret].m_Age << '\t';
		cout <<"性别：" << abs->personArray[ret].m_Sex << '\t';
		cout<<"联系电话：" << abs->personArray[ret].m_Phone << '\t';
		cout << "家庭地址：" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
}
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入你想修改的联系人：";
	string name = "";
	cin >> name;
	int ret = isExist(abs, name);//abs本身就是地址，所以不需要取址
	if (ret != -1)
	{
		cout << "请输入名字：";
		cin >> name;
		abs->personArray[abs->m_size].m_Name = name;
		//性别
		cout << "请输入性别：" << '\n'
			<< "(1--男)" << '\n'
			<< "(2--女)" << '\n'
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
			cout << "输入错误，请重新输入" << endl;
		}
		//年龄
		int age = 0;
		cout << "请输入年龄：";
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//联系电话
		string phone = "";
		cout << "请输入联系电话：";
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//家庭住址
		string addr = "";
		cout << "请输入家庭地址：";
		cin >> addr;
		abs->personArray[ret].m_Addr = addr;
		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
}
void cleanPerson(Addressbooks* abs)
{
	abs->m_size = 0;
	cout << "通讯录已全部清除" << endl;
}
int main()
{
	Addressbooks abs;//通讯录源
	abs.m_size = 0;//初始化通讯录人数
	int select = 0;
	while (true)
	{
		showfunction();
		cin >> select;
		switch (select)
		{
		case 1://添加联系人
			addperson(&abs);
			break;
		case 2://显示联系人
			showperson(&abs);
			break;
		case 3://删除联系人
			deletePerson(&abs);
			break;
		case 4://查找联系人
			findPerson(&abs);
			break;
		case 5://修改联系人
			modifyPerson(&abs);
			break;
		case 6://清空联系人
			cleanPerson(&abs);
			break;
		case 0://退出通讯录
			cout << "欢迎下次使用" << endl;
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}