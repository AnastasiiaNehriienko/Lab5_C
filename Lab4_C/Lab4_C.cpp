#include "Funcs.h"

int main() {
	int n, m;
	cout << "Enter the amount of prom.products:";  //кількість промислових продуктів
	cin >> n;
	Prom* proms = new Prom[n];   //масив для пром.товарів
	create_proms(n, proms);
	cout << "Enter the amount of eatable products:";  //кількість харчевих продуктів
	cin >> m;
	Eat* eats = new Eat[m];   //масив для харч.товарів
	create_eats(m, eats);
	long bads = bad_products(m, eats);   //загальна вартість продуктів, які вже не можна споживати
	long stock =  stock_products(n, proms);  //загальна вартість продуктів на складі
	show(bads, stock);   //виведення вартості
	delete[]proms;   //видалення динамічних масивів
	delete[]eats;
	return 0;
}