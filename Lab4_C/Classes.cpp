#include "Classes.h"
void Date::show() {
	printf("Date:%02d/%02d/%4d\n", day, month, year);
}
Date Thing::check_date(Date how_long) {
	Date good;
	int d = made.get_day() + how_long.get_day();
	int m = made.get_month() + how_long.get_month() + d / 31;
	int y = made.get_year() + how_long.get_year() + m / 13;
	int d1 = d%30, m1=m%12;
	if (d % 30 == 0)
		d1 = 30;
	if (m % 12 == 0)
		m1 = 12;
	good.set(y, m1, d1);
	return good;
}
void Thing::set(string n, Date d, int pr, int am) {
 name = n;
 made = d;
 price = pr;
 amount = am;
}
long Thing::all_price(){
	return ((long)price) * amount;
}
void Thing::show1() {
	cout << name << endl;
	made.show();
	cout << "Price: " << price << "; Amount: " << amount << endl;
}
void Prom::show() {
	show1();
	cout << "Transporting way: " << transporting << endl;
	cout << "Place to store: ";
	if (place == 0)
		cout << "Stock" << endl;
	else
		cout << "Shop" << endl;
}
void Eat::show() {
	show1();
	cout << "You can store this product " << how_long.get_year() 
		<< "years, " << how_long.get_month() << "month and " << how_long.get_day() << "days" << endl;
}
bool Eat::is_bad(Date today) {    //чи є строк придатності більшим за пройдений час від дати виробництва
	bool bad=true;
	Date good_day=check_date(how_long);
	if (today.get_year() < good_day.get_year())
		bad = false;
	else if (today.get_year() == good_day.get_year() && today.get_month() < good_day.get_month())
		bad = false;
	else if (today.get_year() == good_day.get_year() && today.get_month() == good_day.get_month()&& today.get_day() <= good_day.get_day())
		bad = false;
	return bad;
}