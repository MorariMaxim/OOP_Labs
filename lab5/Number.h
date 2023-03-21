class Number

{
	int num;
	char base;
	int digitcount;
	char* representation;

public:

	Number(const char* value, int base); // where base is between 2 and 16
	Number(int val);
	~Number();
	char operator[] (int index);
	Number& operator= (Number&& num1);
	Number& operator= (int num1);
	Number& operator= (const char* str);
	void operator-- ();
	void operator-- (int value);
	void operator+= (const Number& num1);
	bool operator > (const Number& num1);
	bool operator >= (const Number& num1);
	bool operator < (const Number &num1);
	bool operator <= (const Number &num1);
	bool operator == (const Number &num1);
	friend Number operator+ (const Number& num1, const Number& num2);
	friend Number operator- (const Number& num1, const Number& num2);

	Number(const Number& obj);
	Number(Number&& obj);


	void SwitchBase(int newBase);

	void Print();

	int  GetDigitsCount();

	int  GetBase();

};

int tobase10(const char* value, int base);
char* tobasex(int value, int base_);