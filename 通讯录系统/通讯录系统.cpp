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
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else
	{
		string name;
		cout << "��������" << endl;
		cin >> name;
		abs->personArray[abs->m_size].name = name;

		string sex;
		cout << "�����Ա�" << endl;
		cin >> sex;
		while (sex.compare("��") && sex.compare("Ů"))
		{
			cout << "������������������";
			cin >> sex;
		}
		abs->personArray[abs->m_size].sex = sex;

		int age;
		cout << "��������" << endl;
		cin >> age;
		abs->personArray[abs->m_size].age = age;

		string tel;
		cout << "����绰" << endl;
		cin >> tel;
		abs->personArray[abs->m_size].tel = tel;

		string address;
		cout << "�����ַ" << endl;
		cin >> address;
		abs->personArray[abs->m_size].address = address;

		abs->m_size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");//����
	}
}

void showPeopleInfo(addressbooks abs)
{
	if (abs.m_size != 0) {
		cout << "����\t�Ա�\t����\t�绰\t\t��ַ\n";
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
		cout << "��¼Ϊ��" << endl;
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
	 cout << "������ɾ������ϵ��" << endl;
	 string name;
	 cin >> name;
	 int ret = isExist(abs, name);
	 if (ret == -1)
	 {
		 cout << "δ�ҵ���ϵ��"<< endl;
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
		 cout << "ɾ���ɹ�";
	 }
	 system("pause");
	 system("cls");
}

 void searchPeople(addressbooks abs)
 {
	 cout << "�����������ϵ������";
	 string name;
	 cin >> name;
	 int ret = isExist(&abs, name);
	 if (ret != -1)
	 {
		 cout << "����:" << abs.personArray[ret].name << "\t";
		 cout << "�Ա�:" << abs.personArray[ret].sex << "\t";
		 cout << "����:" << abs.personArray[ret].age << "\t";
		 cout << "�绰:" << abs.personArray[ret].tel << "\t";
		 cout << "��ַ:" << abs.personArray[ret].address << endl;
	 }
	 else
	 {
		 cout << "���޴���" << endl;
	 }
	 system("pause");
	 system("cls");
 }

 void modifyPeople(addressbooks *abs)
 {
	 cout << "�������޸���ϵ�˵�����" << endl;
	 string name;
	 cin >> name;
	 int ret = isExist(abs, name);
	 if (ret != -1)
	 {
		 string name;
		 cout << "��������" << endl;
		 cin >> name;
		 abs->personArray[ret].name = name;

		 string sex;
		 cout << "�����Ա�" << endl;
		 cin >> sex;
		 while (sex.compare("��") && sex.compare("Ů"))
		 {
			 cout << "������������������";
			 cin >> sex;
		 }
		 abs->personArray[ret].sex = sex;

		 int age;
		 cout << "��������" << endl;
		 cin >> age;
		 abs->personArray[ret].age = age;

		 string tel;
		 cout << "����绰" << endl;
		 cin >> tel;
		 abs->personArray[ret].tel = tel;

		 string address;
		 cout << "�����ַ" << endl;
		 cin >> address;
		 abs->personArray[ret].address = address;
		 cout << "�޸ĳɹ�" << endl;
	 }
	 else 
	 {
		 cout << "δ�ҵ���ϵ��";
	 }
	 system("pause");
	 system("cls");

 }
 void clearPeople(addressbooks *abs)
 {
	 abs->m_size = 0;
	 cout << "ͨѶ¼�ѿ�" << endl;
	 system("pause");
	 system("cls");
 }

void showMenu()
{
	cout << "*********************" << endl;
	cout << "*****1.�����ϵ��*****" << endl;
	cout << "*****2.��ʾ��ϵ��*****" << endl;
	cout << "*****3.ɾ����ϵ��*****" << endl;
	cout << "*****4.������ϵ��*****" << endl;
	cout << "*****5.�޸���ϵ��*****" << endl;
	cout << "*****6.�����ϵ��*****" << endl;
	cout << "*****0.�˳�ͨѶ¼*****" << endl;
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
		case 1: // 1.�����ϵ��
			addPeople(&abs);
			break;
		case 2: // 2.��ʾ��ϵ��
			showPeopleInfo(abs);
			break;
		case 3: // 3.ɾ����ϵ��
			deletepeople(&abs);
			break;
		case 4: // 4.������ϵ��
			searchPeople(abs);
			break;
		case 5: // 5.�޸���ϵ��
			modifyPeople(&abs);
			break;
		case 6: // 6.�����ϵ��
			clearPeople(&abs);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
}