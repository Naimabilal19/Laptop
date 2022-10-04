#include <iostream>
#include <string>
using namespace std;

class HDD
{
	string name;
	int cap;
public:
	HDD()
	{
		name = "Transcend StoreJet";
		cap = 4;
	}
	HDD(const char* a1, int c)
	{
		name = a1;
		cap = c;
	}
	HDD(HDD& obj)
	{
		name = obj.name;
		cap = obj.cap;
	}
	void SHOW()
	{
		cout << name << " " << cap << endl;
	}
};

class RAM
{
	string name;
	int memory;
public:
	RAM()
	{
		name = "Kingston Fury";
		memory = 16;
	}
	RAM(const char* a, int b)
	{
		name = a;
		memory = b;
	}
	RAM(RAM& obj)
	{
		name = obj.name;
		memory = obj.memory;
	}
	void SHOW()
	{
		cout << name << " " << memory << endl;
	}
};

class VideoCard
{
	string name;
	int memory;
public:
	VideoCard()
	{
		name = "GeForce";
		memory = 4;
	}
	VideoCard(const char* n1, int m1)
	{
		name = n1;
		memory = m1;
	}
	VideoCard(VideoCard& obj)
	{
		name = obj.name;
		memory = obj.memory;
	}
	void SHOW()
	{
		cout << name << " " << memory <<" "<< endl;
	}
};

class CPU
{
	string name;
	int num_of_cores;
public:
	CPU()
	{
		name = "Kingston Fury";
		num_of_cores = 16;
	}
	CPU(const char* n, int m)
	{
		name = n;
		num_of_cores = m;
	}
	CPU(CPU& obj)
	{
		name = obj.name;
		num_of_cores = obj.num_of_cores;
	}
	void SHOW()
	{
		cout << name << " " << num_of_cores << endl;
	}
};

class Keyboard
{
	string name;
	double price;
public:
	Keyboard()
	{
		name = "A4 Tech";
		price = 1278;
	}
	Keyboard(const char* n, int p)
	{
		name = n;
		price = p;
	}
	Keyboard(Keyboard& obj)
	{
		name = obj.name;
		price = obj.price;
	}
	void SHOW()
	{
		cout << name << " " << price << endl;
	}
};

class Printer
{
	string name;
	double price;
public:
	Printer()
	{
		name = "Canon Pixma";
		price = 4000;
	}
	Printer(const char* n, int p)
	{
		name = n;
		price = p;
	}
	Printer(Printer& obj)
	{
		name = obj.name;
		price = obj.price;
	}
	void SHOW()
	{
		cout << name << " " << price << endl;
	}
};

class Laptop
{
	//уничтожается 
	CPU c;
	RAM r;
	VideoCard vc;
	HDD h;
	
	// не уничтожается 
	Keyboard* obj1;
	Printer* obj2;

	//------------
	int year;
public:
	Laptop(Keyboard* x, Printer* p,const char* n, int m, const char* a, int b, const char* n1, int m1, const char* a1, int c, int y): obj1(x), obj2(p), c(n,m), r(a,b),vc(n1,m1), h(a1,c)
	{
		year = y;
	}
	void Show()
	{
		cout<<"Клавиатура: ";
		obj1->SHOW();
		cout << "Принтер: ";
		obj2->SHOW();
		cout << "Процессор: ";
		c.SHOW();
		cout << "ОП: ";
		r.SHOW();
		cout << "Видеокарта: ";
		vc.SHOW();
		cout << "Жетский диск: ";
		h.SHOW();
	}
	~Laptop()
	{
		cout << "Destruct" << endl;
	}
	void SetKeyboard(Keyboard* k)
	{
		obj1 = k;
	}

	void SetPrinter(Printer* p)
	{
		obj2 = p;
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "-------obj 1----------"<<endl;
	Keyboard obj1{ "Samsung", 1278 };
	Printer obj2{ "Print", 20000};
	Laptop* ptr = new Laptop(&obj1,&obj2, "Kingston Fury", 4000, "RAM", 2000, "GeForce", 3500, "Transcend StoreJet", 1000, 2019);

	ptr->Show();

	cout << "\n";
	delete ptr;
	//obj1.SHOW();
	cout << "\n---- obj 2 -------------------\n";
	Laptop new_obj(&obj1, &obj2, "Cpu_new", 6000, "RAM_new", 2300, "Gee_new", 5500, "New_HDD", 2100, 2021);
	new_obj.Show();
	cout<<endl;

	Keyboard newkey("Apple",3000 );
	new_obj.SetKeyboard(&newkey);
	Printer newpr("New Printer", 12000);
	new_obj.SetPrinter(&newpr);
	new_obj.Show();

	system("pause");
}