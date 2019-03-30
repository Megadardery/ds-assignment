#include <bits/stdc++.h>
#include "Searcher.h"

using namespace std;

const int maxs = 100000;

Searcher::performanceStat runTests(Searcher& sh, int tests, bool existing) {
	Searcher::performanceStat t;
	string word;

	//cout << setw(10) << "n" << setw(10) << "result" << setw(10) << "comps" << setw(10) << "time in us" << endl;
	int totalComp = 0, totalTime = 0;
	for (int i = 0; i < tests; i++) {
		if (existing)
			word = sh.getRandomWord();
		else
			word = sh.makeUpRandomWord();
		t = sh.testPerformance(word);
		totalComp += t.comparisons;
		totalTime += t.timeInUs;
		//cout << setw(10) << i + 1 << setw(10) << t.result << setw(10) << t.comparisons << setw(10) << t.timeInUs << '\n';
	}

	//cout << "Average Time: " << 1.0 * totalTime / tests << endl;
	//cout << "Average Comparisons: " << 1.0 * totalComp / tests << endl;

	return { -1,totalComp,totalTime };
}

/*
	Note for reader:
	The Searcher::performanceStat::comparisons is the number of 'string' comparisons done
	using the string.compare function. Notice that the loop comparisons and the result interpertations
	are not taken into account.
*/
int main()
{
	ofstream graph1("graphTime.csv");
	ofstream graph2("graphComparisons.csv");
	graph1 << "Data Size,Existing Word,Random Word\n";
	graph2 << "Data Size,Existing Word,Random Word\n";
	Searcher sh;
	sh.loadData("words.txt");

	int cursz = 10;
	for (int i = cursz; i <= maxs; i += cursz) // change here
	{
		sh.setDataSize(cursz);
		graph1 << i << ",";
		graph2 << i << ",";

		Searcher::performanceStat t;
		t = runTests(sh, 100, 1);

		graph1 << t.timeInUs << ",";
		graph2 << t.comparisons << ",";

		t = runTests(sh, 100, 0);
		graph1 << t.timeInUs << '\n';
		graph2 << t.comparisons << '\n';

		if (i >= cursz * 10) cursz *= 10;
	}
}