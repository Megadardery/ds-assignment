#include <iostream>
#include <string>
#include <vector>
#include "BSTFCI.h"
using namespace std;

struct indexer {
	string val;
	vector<int> lines;
	int curline;

	indexer() {};
	indexer(const string& _val, int _curline) : val(_val), curline(_curline) {
		lines.push_back(_curline);
	};

	bool operator <(const indexer& b) const {
		return val < b.val;
	}
	bool operator >(const indexer& b) const {
		return val > b.val;
	}
	bool operator ==(const indexer& b) const {
		return val == b.val;
	}
	void operator =(const indexer& b) {
		if (val != b.val){
			val = b.val;
			lines.clear();
		}
		lines.push_back(b.curline);
	}
	friend ostream& operator <<(ostream& out, const indexer& b);
};
ostream& operator <<(ostream& out, const indexer& b) {
	out << b.val << " : ";
	for (auto i : b.lines) out << i << " ";
	out << "\n";
	return out;
}
int main() {
	
	BSTFCI<indexer> idx;
	int lines;
	cout << "how many lines? : ";
	cin >> lines;
	cin.ignore();
	for (int i = 0; i < lines; i++) {
		string l;
		getline(cin, l);
		l.push_back(' ');
		string x;
		for (int j = 0; j < l.length(); j++) {
			char c = tolower(l[j]);
			if (c != ' ' && !isalpha(c)) continue;
			if (c == ' ') {
				idx.insert(indexer(x,i+1));
				x = "";
			}
			else
				x.push_back(c);
		}
	}
	cout << endl;
	idx.LPR();
}
/*
I am for truth,
no matter who tells it.
I am for justice,
no matter who it is for or against.
Malcolm X
*/
/*
The only thing that will make you happy
is being happy with who you are,
not who people think you are.
*/
/*
First best is falling in love.
Second best is being in love.
Least best is falling out of love.
But any of it is better than never having been in love.
*sadface*
*/