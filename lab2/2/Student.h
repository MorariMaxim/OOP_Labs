class Student {
	char* name=nullptr;
	int mathematics, english, history;
public:
	int getMathsematics();
	char* getName();
	int getEnglish();
	int getHistory();
	float getAverage();
	void setMathsematics(int grade);
	void setEnglish(int grade);
	void setHistory(int grade);
	void setName(const char * toset);
};