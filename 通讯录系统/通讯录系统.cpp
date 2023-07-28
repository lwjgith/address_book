#include<iostream>
#include<string>
#define max 1000
using namespace std;


struct people
{
	string name;
	string sex;
	int age;
	string tel;
	string address;
};

struct addressbooks {
	struct people personArray[max];
	int m_size;
};

void addPeople(addressbooks * abs) 
{
	if (abs->m_size == max)
	{
		cout << "通讯录已满" << endl;
		return;
	}
	else
	{
		string name;
		cout << "输入姓名" << endl;
		cin >> name;
		abs->personArray[abs->m_size].name = name;

		string sex;
		cout << "输入性别" << endl;
		cin >> sex;
		while (sex.compare("男") && sex.compare("女"))
		{
			cout << "输入有误，请重新输入";
			cin >> sex;
		}
		abs->personArray[abs->m_size].sex = sex;

		int age;
		cout << "输入年龄" << endl;
		cin >> age;
		abs->personArray[abs->m_size].age = age;

		string tel;
		cout << "输入电话" << endl;
		cin >> tel;
		abs->personArray[abs->m_size].tel = tel;

		string address;
		cout << "输入地址" << endl;
		cin >> address;
		abs->personArray[abs->m_size].address = address;

		abs->m_size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");//清屏
	}
}

void showPeopleInfo(addressbooks abs)
{
	if (abs.m_size != 0) {
		cout << "姓名\t性别\t年龄\t电话\t\t地址\n";
		for (int i = 0; i < abs.m_size; i++)
		{
			cout << abs.personArray[i].name << "\t";
			cout << abs.personArray[i].sex << "\t";
			cout << abs.personArray[i].age << "\t";
			cout << abs.personArray[i].tel << "\t\t";
			cout << abs.personArray[i].address << "\n";
		}
	}
	else
	{
		cout << "记录为空" << endl;
	}
	system("pause");
	system("cls");
}
int isExist(addressbooks *abs, string name) 
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personArray[i].name == name)
		{
			return i;
		}
	}
	return -1;
}
 void deletepeople(addressbooks *abs)
{
	 cout << "请输入删除的联系人" << endl;
	 string name;
	 cin >> name;
	 int ret = isExist(abs, name);
	 if (ret == -1)
	 {
		 cout << "未找到联系人"<< endl;
	 }
	 else
	 {
		 if (ret == 0)
		 {
			 abs->m_size = 0;
		 }
		 for (int i = ret; i < abs->m_size; i++)
		 {
			 abs->personArray[i] = abs->personArray[i + 1];
		 }
		 abs->m_size--;
		 cout << "删除成功";
	 }
	 system("pause");
	 system("cls");
}

 void searchPeople(addressbooks abs)
 {
	 cout << "请输入查找联系人姓名";
	 string name;
	 cin >> name;
	 int ret = isExist(&abs, name);
	 if (ret != -1)
	 {
		 cout << "姓名:" << abs.personArray[ret].name << "\t";
		 cout << "性别:" << abs.personArray[ret].sex << "\t";
		 cout << "年龄:" << abs.personArray[ret].age << "\t";
		 cout << "电话:" << abs.personArray[ret].tel << "\t";
		 cout << "地址:" << abs.personArray[ret].address << endl;
	 }
	 else
	 {
		 cout << "查无此人" << endl;
	 }
	 system("pause");
	 system("cls");
 }

 void modifyPeople(addressbooks *abs)
 {
	 cout << "请输入修改联系人的姓名" << endl;
	 string name;
	 cin >> name;
	 int ret = isExist(abs, name);
	 if (ret != -1)
	 {
		 string name;
		 cout << "输入姓名" << endl;
		 cin >> name;
		 abs->personArray[ret].name = name;

		 string sex;
		 cout << "输入性别" << endl;
		 cin >> sex;
		 while (sex.compare("男") && sex.compare("女"))
		 {
			 cout << "输入有误，请重新输入";
			 cin >> sex;
		 }
		 abs->personArray[ret].sex = sex;

		 int age;
		 cout << "输入年龄" << endl;
		 cin >> age;
		 abs->personArray[ret].age = age;

		 string tel;
		 cout << "输入电话" << endl;
		 cin >> tel;
		 abs->personArray[ret].tel = tel;

		 string address;
		 cout << "输入地址" << endl;
		 cin >> address;
		 abs->personArray[ret].address = address;
		 cout << "修改成功" << endl;
	 }
	 else 
	 {
		 cout << "未找到联系人";
	 }
	 system("pause");
	 system("cls");

 }
 void clearPeople(addressbooks *abs)
 {
	 abs->m_size = 0;
	 cout << "通讯录已空" << endl;
	 system("pause");
	 system("cls");
 }

void showMenu()
{
	cout << "*********************" << endl;
	cout << "*****1.添加联系人*****" << endl;
	cout << "*****2.显示联系人*****" << endl;
	cout << "*****3.删除联系人*****" << endl;
	cout << "*****4.查找联系人*****" << endl;
	cout << "*****5.修改联系人*****" << endl;
	cout << "*****6.清空联系人*****" << endl;
	cout << "*****0.退出通讯录*****" << endl;
	cout << "*********************" << endl;
}

int main()
{
	struct addressbooks abs;
	abs.m_size = 0;
	int select = 0;
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1: // 1.添加联系人
			addPeople(&abs);
			break;
		case 2: // 2.显示联系人
			showPeopleInfo(abs);
			break;
		case 3: // 3.删除联系人
			deletepeople(&abs);
			break;
		case 4: // 4.查找联系人
			searchPeople(abs);
			break;
		case 5: // 5.修改联系人
			modifyPeople(&abs);
			break;
		case 6: // 6.清空联系人
			clearPeople(&abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
}