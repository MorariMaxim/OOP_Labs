#include <iostream>
#include <string>
#include <vector>

using namespace std;
enum contactenum
{
	Prieten_type, Coleg_type, Cunoscut_type
};
class Contact {	
public:
	std::string nume;
	contactenum type;	
protected:
	virtual void forthedynamiccast() {};
	Contact(){};
};

class Prieten : public Contact {
public:
	std::string adresa;
	std::string numartelefon;
	std::string datanastere;
	
};
class Coleg : public Contact {
public:
	std::string firma;
	std::string numartelefon;
	std::string adresa;
};

class Cunoscut : public Contact {
public:
	std::string numartelefon;
};

class Agenda {

	vector<Contact*> contacts;
public:
	Contact* find(string nume) {

		for (Contact * c : contacts)
		{
			if (c->nume == nume) return c;
		}
	}
	vector<Contact*> prieteni() {

		vector<Contact*> res;
		
		for (Contact* c : contacts)
		{			
			
			auto p = dynamic_cast<Prieten*>(c);
			if (p != nullptr) res.push_back(c);
			
			//if (c->type == contactenum::Prieten_type)  res.push_back(c);
		}
		return res;
	}
	void deletecontact(string nume) {
		for (auto  it = contacts.begin(); it != contacts.end(); it++)
		{
			if (( * it)->nume == nume) {
				contacts.erase(it);
				break;
			}
		}
	}
	void adauga(Contact* c) {
		contacts.push_back(c);
	}
};