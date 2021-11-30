#include <iostream>
using namespace std;

void ff() {
	cout << "Глобальынй уровень" << endl;
}
class BASE {
public: int i;
	  BASE(int _i, long _l, double _d) {
		  i = _i;
		  l = _l;
		  d = _d;
	  }
	  BASE() {
		  i = 11;
		  l = 22;
		  d = 33;
		  cout << "Был вызван конструтор по умолчанию из класса BASE" << endl;
}
	  void show() {
		  cout << "i занимает " << sizeof(i) << " байт(а), значение = " << i << endl;
		  cout << "l занимает " << sizeof(l) << " байт(а), значение = " << l << endl;
		  cout << "d занимает " << sizeof(d) << " байт(а), значение = " << d << endl;
	  }
	  void ff() {
		  cout << "Класс Base" << endl;
	  }
private: long l;
protected: double d;
friend class DERIVED;
};

class DERIVED: public BASE {
public:
	DERIVED(float _f, int _i, long _l, double _d ){
		f = _f;
		i = _i;
		l = _l;
		d = _d;
	}
	DERIVED() {
		f =44;
	}
	void show() {
		cout << "i занимает " << sizeof(i) << " байт(а), значение = " << i << endl;
		cout << "l занимает " << sizeof(l) << " байт(а), значение = " << l << endl;
		cout << "d занимает " << sizeof(d) << " байт(а), значение = " << d << endl;
		cout << "f занимает " << sizeof(f) << " байт(а), значение = " << f << endl;
	}
	void ff() {
		cout << "Класс DERIVED" << endl;
	}
private: float f;
 friend class DERIVED_1;
};

class DERIVED_1 : public DERIVED {
public:
	void foo() {
		ff();
	}
	void ff() {
		cout << "Класс DERIVED_1" << endl;
	}
	  /*DERIVED_1(float _f, int _i, long _l, double _d) {
		  f = _f;
		  i = _i;
		  l = _l;
		  d = _d;
	  }*/
};

int main() {
	setlocale(LC_ALL, "rus");
	BASE Obj1(66,77,88);
	DERIVED Obj2(99,111,222,333);
	DERIVED_1 Obj3;
	cout <<"Размер BASE = "<<sizeof(BASE)<<endl;
	Obj1.show();
	cout << "Размер DERIVED = "<<sizeof(DERIVED)<< endl;
	Obj2.show();
	cout << "Размер DERIVED_1 = " << sizeof(DERIVED_1) << endl;
	Obj3.show();
	Obj3.foo();
	return 0;
};
