#include <iostream>
#include <string>
using namespace std;
class Date {   //дати
	int year;
	int month;
	int day;
public:
	void set(int y, int m, int d) { year = y; month = m; day = d; }   //задання дати
	int get_year() { return year; }   
	int get_month() { return month; }
	int get_day() { return day; }
	void show();                         //виведення у форматованому вигляді
};
class Thing {
protected:
	string name;
	Date made;
	int price;
	int amount;
public:
	void set(string, Date, int, int);
	Date check_date(Date);                 //дата, до якої продукт придатний
	long all_price();                     //підрахунок загальної вартості окремої позиції
	void show1();                         //виведення даних
};
class Prom :public Thing {
	string transporting;           //вид транспортування
	int place;                     //місце зберігання
public:
	void set_transport(string tr) { transporting = tr; }
	void set_place(int pl) { place = pl; }
	int get_place() { return place; }
	void show();
};
class Eat : public Thing {
	Date how_long;                //строк придатності
public:
	void set_how_long(Date d) { how_long = d; }
	bool is_bad(Date);
	void show();
};