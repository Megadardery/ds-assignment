#include <bits/stdc++.h>
#include "Searcher.h"

using namespace std;

void runTests(Searcher& sh, int tests, bool existing) {
	Searcher::performanceStat t;
	string word;

	cout << setw(10) << "n" << setw(10) << "result" << setw(10) << "comps" << setw(10) << "time in us" << endl;
	int totalComp = 0, totalTime = 0;
	for (int i = 0; i < tests; i++) {
		if (existing)
			word = sh.getRandomWord();
		else
			word = sh.makeUpRandomWord();
		t = sh.testPerformance(word);
		totalComp += t.comparisons;
		totalTime += t.timeInUs;
		cout << setw(10) << i + 1 << setw(10) << t.result << setw(10) << t.comparisons << setw(10) << t.timeInUs << '\n';
	}
	cout << "Average Time: " << 1.0 * totalTime / tests << endl;
	cout << "Average Comparisons: " << 1.0 * totalComp / tests << endl;
}

/*
	Note for reader:
	The Searcher::performanceStat::comparisons is the number of 'string' comparisons done
	using the string.compare function. Notice that the loop comparisons and the result interpertations
	are not taken into account.
*/
int main()
{
	cout << left;
	int numOfWords;
	cout << "How many ten-thousands words do you want to perform the test on? (1-10)\n";
	cin >> numOfWords;
	numOfWords *= 10000;

	Searcher sh;
	sh.loadData("d:\\words.txt", numOfWords);

	int tests;
	cout << "How many tests? ";
	cin >> tests;

	cout << "For Random existing words:\n";
	runTests(sh, tests, 1);
	cout << "For Random non-existing words:\n";
	runTests(sh, tests, 0);


}