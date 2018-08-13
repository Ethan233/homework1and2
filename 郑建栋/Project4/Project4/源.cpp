#include<iostream>
#include<iomanip>
using namespace std;
int isleap(int);//�ж�����
int week_of_mewyear_day(int);//����ָ�����Ԫ�����ڼ�
void showYear(int);//������ʾ
void showMon(int,int);//������ʾ
void showHead();//��ʾ��ͷ
int  week_of_mewmonth_day(int year, int month);//����ָ���꼰�µĵ�һ�������ڼ�
int getLenOfMonth(int year, int month);//����ָ���꼰�µ�����
int main()
{
	int choice;
	int year, mon;
	while (1)
	{
		system("cls");//ϵͳ����
		cout << "��������ѯ" <<endl;
		cout << "*********************************" << endl;
		cout << "1   �������" << endl;
		cout << "2   �������" << endl;
		cout << "0   �˳�" << endl;
		cout << "*********************************" << endl;
		cout << "����������ѡ��";
		cin >> choice;
		switch (choice)
		{
		case 1:cout<< "��������ʾ�����";
			cin >> year;
			showYear(year);
			break;
		case 2:cout << "��������ʾ����ݼ��·�";
			cin >> year >> mon;
			showMon(year, mon);
			break;
		case 0:exit(0);
		}
	}
	return 0;
}
//isleap�����жϸ���������Ƿ�Ϊ����
int isleap(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1;
	else
		return 0;
}
// getLenOfMonth��������ָ�����µ�����
int getLenOfMonth(int year, int month)
{
	int len_of_month;
	if (month ==4 || month ==6 || month ==9 || month ==11)
		len_of_month = 30;
	else if (month ==2)
	{
		if (isleap(year))
			len_of_month = 29;
		else
			len_of_month = 28;
	}
	else
		len_of_month = 31;
	return len_of_month;
}
// week_of_mewyear_day��������������Ԫ����������
int week_of_mewyear_day(int year)
{
	int n = year - 1900;
	n = n + (n - 1) / 4 + 1;
	n = n % 7;
	return n;
}
//int  week_of_mewmonth_day����ָ���꼰�µĵ�һ�������ڼ�
int  week_of_mewmonth_day(int year, int month)
{
	int n = year - 1900;
	n = n + (n - 1) / 4 + 1;
	for (int i = 1; i < month; i++)
	{
		n = n + getLenOfMonth(year, i);
	}
	n = n % 7;
	return n;
}
//showHead��ʾ��ͷ
void showHead()
{
	cout << "--------------------------------------" << endl;
	cout << "SUN MON TUE WED THU FRI SAT" << endl;
	cout << "--------------------------------------" << endl;
}
//void showYear����������ʾ����
void showYear(int year)
{
	int month, day, weekday, len_of_month, i;
	cout << endl << year << endl;
	weekday = week_of_mewyear_day(year);
	for (month = 1; month <= 12; month++)
	{
		getchar();
		cout << endl << month<< endl;
		showHead();
		for (i = 0; i < weekday; i = i + 1)
			cout << " ";
		len_of_month = getLenOfMonth(year, month);
		for (day = 1; day <= len_of_month; day++)
		{
			cout << setw(3) << day << " ";
			weekday++;
			if (weekday == 7)
			{
				weekday = 0;
				cout << endl;
			}
		}
		cout << endl;
	}
}
//showMon����������ʾ����
void showMon(int year,int mon)
{
	int day, weekday, len_of_month, i;
	cout << endl << year << endl;
	cout << endl << mon << endl;
	weekday = week_of_mewmonth_day(year, mon);
	getchar();
	showHead();
	for (i = 0; i < weekday; i = i + 1)
		cout << "     ";
	len_of_month = getLenOfMonth(year, mon);
	for (day = 1; day <= len_of_month; day++)
	{
		cout << setw(3) << day << " ";
		weekday++;
		if (weekday == 7)
		{
			weekday = 0;
			cout << endl;
		}
	}
	cout << endl;
	getchar();
}