class Student {
	char* name=nullptr;
	float mathematics, english, history;
public:
	float getMathsematics();
	float getEnglish();
	float getHistory();
	float getAverage();
	char* getName();
	void setMathsematics(float grade);
	void setEnglish(float grade);
	void setHistory(float grade);
	void setName(const char * toset);
};
