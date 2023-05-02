#include <iostream>
#include <tuple>
 
template<class v>
class Value {
public:
	v val;
	Value(const v& nv) : val(nv){};
};

template<class k, class v>
class node {
public:
	bool init = 0;
	k key;
	Value<v> *value = nullptr;
	void operator=(const v& val) {
		value = new Value<v>(val);
	}
};

template<class k,class v>
class Map {

private:		
		
	int add(const k& key,const v& val) {

		if (max == count) {
			node<k, v>* newcont = new node<k, v>[max * 2];
				
			for (int i = 0; i < max; i++) {
				newcont[i] = container[i];
			}			
			delete[] container;
			container = newcont;			
			max *= 2;
		}
		for (size_t i = 0; i < max; i++)
		{
			if (!container[i].init) {
				container[i].key = key;
				container[i].value = new Value(val);
				container[i].init = 1;
				count++;
				return i;
			}
		}
		 
	}
		
public:
	node<k, v>* container;
	int count;
	int max;
	class iterator {
	public:
		int ind;
		node<k, v>* container;
		int max;
		void operator++() {			
			while (ind < max) {
				if (container[++ind].init) break;
			}			
		}
		auto operator*() {
			return std::make_tuple(container[ind].key, container[ind].value->val, ind);

		}
		bool operator!=(const iterator other) {
			return ind != other.ind;
		}

	};
	node<k, v>& operator [](const k& key) {
		for (int i = 0; i < count; i++) {
			if (container[i].init && container[i].key == key) {
				return container[i];
			}
		}
		int i = add(key, v());
		return container[i];
	}
	int find(const k& key) {
		for (int i = 0; i < max; i++)
		{
			if (container[i].init && container[i].key == key) return i;
		}
		return -1;
	}	
	void Set(const k& key, const v& value) {		
		int f = find(key);
		if (f != -1) {
			container[f].value = new Value(value);
		}
		else {
			add(key, value);
		}
	}
	operator int() {
		return count;
	}
	bool Delete(const k& key) {
		int f = find(key);
		if (f != -1) {
			container[f].init = 0;
			count--;
			return 1;
		}
		return	0;
	}
	bool Get(const k& key, v& value) {
		int f = find(key);
		if (find != -1) {
			value = container[f].value->val;
			return 1;
		}
		return 0;

	}
	void Clear() {
		for (int i = 0; i < max; i++)
		{
			container[i].init =0;
		}
		count = 0;
	}
	bool Includes(const Map<k, v>& map) {
		Map<k, v> copy = map;
		for (auto [key_,value_,index_] : copy) {			
			if (find(key_) == -1) return 0;
		}
		return 1;
	}
	Map() {
		count = 0;
		max = 32;
		container = new node<k, v>[max];
	} 

	iterator begin() {
		int ind = 0;
		for (ind; ind < max; ind++)
		{
			if (container[ind].init) break;
		}		
		return iterator{ ind,container,max};
	};
	iterator end() {
		return iterator{ max,container,max };
	};
};

 
