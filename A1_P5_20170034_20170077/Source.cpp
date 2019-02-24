#include <iostream>
#include <string>
#include <set>

using namespace std;
void RecPermute(string soFar, string rest, set<string>& created)

{
	if (rest == "") {
		// No more characters 
		if (created.insert(soFar).second)	//new encountered word
			cout << soFar << endl; // Print the word 
	}
	else // Still more chars 
	// For each remaining char 

		for (int i = 0; i < rest.length(); i++) {

			string next = soFar + rest[i]; // Glue next char 

			string remaining = rest.substr(0, i) + rest.substr(i + 1);
			RecPermute(next, remaining, created);
		}

}

// "wrapper" function 
void ListPermutations(string s) {
	set<string> created;
	RecPermute("", s, created);
}

int main() {
	//best code ever, right?
	ListPermutations("aaab");
	cout << endl << endl;
	ListPermutations("Mkkaa");
	cout << endl << endl;


}