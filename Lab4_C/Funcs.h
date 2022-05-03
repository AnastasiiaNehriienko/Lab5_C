#include "Classes.h"
void create_proms(int&, Prom*);   //створення масиву пром.товарів
void create_eats(int&, Eat*);     //створення масиву харч.товарів
long bad_products(int, Eat*);          //підрахунок вартості
long stock_products(int, Prom*);       //підрахунок вартості
void show(long, long);            //виведення вартості

void create_proms(int&x, Prom*vctr) {
	for (int i = 0; i < x; i++) {
		Prom thing;
		string name1;
		Date made1;
		int y, m, d;
		int price1;
		int amount1;
		string transport1;
		int place1;
		cout << "Enter the name:"; cin.ignore();
		getline(cin, name1);
		cout << "Enter year, month and day, when it was made(with spaces between):"; 
		cin >> y >> m >> d; made1.set(y, m, d);
		cout << "Enter the price and amount(with spaces):"; cin >> price1 >> amount1;
		cout << "Enter the way of transporting:"; cin.ignore();
		getline(cin, transport1);
		cout << "Press 0 for storing on the stock and 1 for storing in the shop: ";
		cin >> place1;
		thing.set(name1, made1, price1, amount1);
		thing.set_transport(transport1);
		thing.set_place(place1);
		vctr[i]=thing;
	}
	for (int j = 0; j < x; j++)
		vctr[j].show();         //проміжні дані
}
void create_eats(int&x, Eat*vctr) {
	for (int i = 0; i < x; i++) {
		Eat thing;
		string name1;
		Date made1;
		int y, m, d;
		int price1;
		int amount1;
		Date how_long1;
		int y2, m2, d2;
		cout << "Enter the name:"; cin.ignore();
		getline(cin, name1);
		cout << "Enter year, month and day, when it was made(with spaces between):"; 
		cin >> y >> m >> d; made1.set(y, m, d);
		cout << "Enter the price and amount(with spaces):"; cin >> price1 >> amount1;
		cout << "Enter year, month and day, how long you can use it(with spaces between):";
		cin >> y2 >> m2 >> d2; how_long1.set(y2, m2, d2);
		thing.set(name1, made1, price1, amount1);
		thing.set_how_long(how_long1);
		vctr[i]=thing;
	}
	for (int j = 0; j < x; j++)
		vctr[j].show();           //проміжні дані
}
long bad_products(int x, Eat*vctr) {
	long sum = 0;
	Date today;
	int y, m, d;
	cout << "What date is it today(year, month and day with spaces)?";
	cin >> y >> m >> d;
	today.set(y, m, d);
	for (int i = 0; i < x; i++) {
		if (vctr[i].is_bad(today))
			sum += vctr[i].all_price();
	}
	return sum;
}
long stock_products(int x, Prom*vctr) {
	long sum=0;
	for (int i = 0; i <x; i++) {
		if (vctr[i].get_place() == 0)
			sum += vctr[i].all_price();
	}
	return sum;
}
void show(long bads, long stock) {
	cout << "The total price of bad products is: " << bads << endl;
	cout << "The total price of stock products is: " << stock << endl;
}