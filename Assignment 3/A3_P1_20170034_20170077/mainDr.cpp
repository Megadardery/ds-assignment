#include <iostream>
#include <algorithm>

template<typename T>
class doubly_list {
private:
	struct node {
		T val;
		node* nxt = nullptr;
		node* prev = nullptr;
	};

	node* head;
	node* tail;

	//insert a node between nod->prev and nod
	node* _insert(node* nod, const T& _val) {
		++_sz;
		node* tmp = new node;
		tmp->val = _val;
		tmp->nxt = nod;
		tmp->prev = nod->prev;		//this is either the correct previous, or nullptr

		//if no prev, that means this is the parent
		if (nod->prev == nullptr)
			head = tmp;
		else
			nod->prev->nxt = tmp;

		nod->prev = tmp;
		return tmp;
	}
	node* _erase(node* nod) {
		--_sz;
		nod->nxt->prev = nod->prev;		//this is either the correct previous, or nullptr

		if (nod->prev == nullptr)
			head = nod->nxt;
		else
			nod->prev->nxt = nod->nxt;

		node* ret = nod->nxt;
		delete nod;

		return ret;
	}

	size_t _sz;

public:
	class iterator {
		node* base;
	public:
		iterator(node* _base = nullptr) : base(_base) {}

		T& operator*() { return base->val; }
		//const T& operator*() const { return base->val; }

		bool operator ==(const iterator& it) const {
			return base == it.base;
		}
		bool operator !=(const iterator& it) const {
			return base != it.base;
		}

		iterator& operator++() {
			base = base->nxt;
			return *this;
		}
		iterator operator++(int) {
			iterator tmp = base;
			base = base->nxt;
			return tmp;
		}
		iterator& operator--() {
			base = base->prev;
			return *this;
		}
		iterator operator--(int) {
			iterator tmp = base;
			base = base->prev;
			return tmp;
		}

		template<typename T>
		friend class doubly_list;
	};

	doubly_list() {
		tail = new node;
		head = tail;
		_sz = 0;
	}
	doubly_list(T val, size_t size) : doubly_list() {
		for (size_t i = 0; i < size; i++) {
			push_back(val);
		}
	}
	doubly_list(const doubly_list<T>& lst) : doubly_list() {
		for (auto it = lst.begin(); it != lst.end(); ++it) {
			push_back(*it);
		}
	}

	doubly_list<T>& operator = (doubly_list<T> lst) {
		clear();
		for (auto it = lst.begin(); it != lst.end(); ++it) {
			push_back(*it);
		}
		return *this;
	}

	void push_back(const T& _val) { _insert(tail, _val); }
	void push_front(const T& _val) { _insert(head, _val); }

	void pop_back() { _erase(tail->prev); }
	void pop_front() { _erase(head); }

	iterator insert(const iterator& it, const T& _val) { return iterator(_insert(it.base, _val)); }
	iterator erase(const iterator& it) { return iterator(_erase(it.base)); }

	iterator begin() const { return iterator(head); }
	iterator end() const { return iterator(tail); }

	size_t size() { return _sz; }

	void clear() {
		iterator cur = begin();
		while (cur != end()) {
			cur = erase(cur);
		}
	}

	~doubly_list() {
		clear();
		delete tail;
	}
};

using namespace std;

template<typename T>
void print(T _val) { cout << _val << " "; }
int main() {
	doubly_list<int>::iterator it;

	cout << "\nTesting pushback\n";
	doubly_list<int> lst1;
	lst1.push_back(5);
	lst1.push_back(7);
	lst1.push_back(9);

	for_each(lst1.begin(), lst1.end(), print<int>);

	cout << "\nTesting insertion\n";
	it = lst1.begin();
	++it;
	it = lst1.insert(it, 6);
	lst1.insert(++++it, 8);

	for_each(lst1.begin(), lst1.end(), print<int>);

	doubly_list<int> lst2;
	lst2 = lst1;

	cout << "\nTesting erase\n";
	it = lst1.begin();
	++++it;
	lst1.erase(it++);
	lst1.pop_back();
	lst1.pop_front();

	for_each(lst1.begin(), lst1.end(), print<int>);

	cout << "\nTesting copying\n";

	for_each(lst2.begin(), lst2.end(), print<int>);

	cout << "\nTesting memory leakage\n";
	for (int i = 0; i < 1000000; i++) {
		doubly_list<int> lst4 = lst2;
	}

	cout << "\nSet breakpoint on this line to monitor memory\n";
}
