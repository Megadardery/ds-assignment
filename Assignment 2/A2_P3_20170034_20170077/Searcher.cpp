#include "Searcher.h"

Searcher::Searcher()
{
	rng.seed((std::chrono::steady_clock::now().time_since_epoch().count()));
}

std::string Searcher::getRandomWord()
{
	std::uniform_int_distribution<int> uid(0, wordlist.size() - 1);
	return wordlist[uid(rng)];
}

std::string Searcher::makeUpRandomWord()
{
	std::uniform_int_distribution<int> uid(0, 25);
	std::uniform_int_distribution<int> uid2(4, 15);
	int n = uid2(rng);
	std::string ret;
	ret.resize(n);
	for (int i = 0; i < n; i++) {
		ret[i] = uid(rng) + 'a';
	}
	return ret;
}

void Searcher::loadData(const char * filename)
{
	sz = 0;
	mainwordlist.clear();
	std::ifstream file(filename);
	if (!file.is_open()) return;
	while (file.peek() != EOF) {
		mainwordlist.push_back("");
		std::getline(file, mainwordlist[sz++]);
	}
}

void Searcher::setDataSize(int words)
{
	wordlist.resize(words);
	for (int i = 0; i < words; ++i) {
		wordlist[i] = mainwordlist[i*sz / words];
	}
}

Searcher::performanceStat Searcher::testPerformance(const std::string & w)
{
	int count = 0;
	auto cmp = [&count](const std::string& a, const std::string& b) {
		count++;
		return a.compare(b);
	};

	auto startTime = std::chrono::high_resolution_clock::now();
	int i = binarySearch(w, cmp);
	auto endTime = std::chrono::high_resolution_clock::now();

	long long us = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();


	return { i,count,us };
}

int Searcher::binarySearch(const std::string & w)
{
	auto cmp = [](const std::string& a, const std::string& b) {
		return a.compare(b);
	};
	return binarySearch(w, cmp);
}

int Searcher::binarySearch(const std::string & w, std::function<int(const std::string&, const std::string&)> cmp)
{
	int st = 0, en = wordlist.size() - 1;
	int md;
	while (st <= en) {
		md = (st + en) / 2;
		int res = cmp(wordlist[md], w);
		if (res == 0)
			return md;
		else if (res < 0)
			st = md + 1;
		else
			en = md - 1;
	}
	return -1;
}