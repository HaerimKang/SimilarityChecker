#include <string>
#include <vector>
#include <map>

using namespace std;

class SimilarityChecker {
public:
	int getLengthPoint(const string& str1, const std::string& str2) {
		int A = getLongLength(str1, str2);
		int B = getShortLength(str1, str2);

		if (isSame(A, B)) return MAX_LENGTH_POINT;
		if (isDoubleLengthGap(A, B)) return MIN_LENGTH_POINT;
		return getPartialLengthPoint(A, B);
	}

	int getAlphaPoint(string str1, string str2)
	{
		int totalAlphabetCnt = getTotalAlphabetCnt(str1, str2);
		int sameAlphabetCnt = getSameAlphabetCnt(str1, str2);

		if (isSame(totalAlphabetCnt, sameAlphabetCnt)) return MAX_ALPHABET_POINT;
		else if (sameAlphabetCnt == 0) return MIN_ALPHABET_POINT;
		return getPartialAlphabetPoint(totalAlphabetCnt, sameAlphabetCnt);
	}

private:
	int getLongLength(const string& str1, const string& str2) {
		if (str1.length() > str2.length()) return str1.length();
		return str2.length();
	}

	int getShortLength(const string& str1, const string& str2) {
		if (str1.length() < str2.length()) return str1.length();
		return str2.length();
	}

	bool isSame(int A, int B) {
		return A == B;
	}

	bool isDoubleLengthGap(int A, int B) {
		return A >= B * 2;
	}

	int getPartialLengthPoint(int A, int B) {
		int GAP = A - B;
		return (B - GAP) * MAX_LENGTH_POINT / B;
	}

	void saveAlphabetToMap(string str1, map<char, bool>& hasAlphabet)
	{
		for (int i = 0; i < str1.length(); ++i)
		{
			if (hasAlphabet.find(str1[i]) == hasAlphabet.end())
			{
				hasAlphabet.insert({ str1[i],true });
			}
		}
	}

	int getTotalAlphabetCnt(string str1, string str2)
	{
		map<char, bool> hasAlphabet;
		saveAlphabetToMap(str1, hasAlphabet);
		saveAlphabetToMap(str2, hasAlphabet);
		return hasAlphabet.size();
	}

	int getSameAlphabetCnt(string str1, string str2)
	{
		map<char, bool> hasAlphabet;
		saveAlphabetToMap(str1, hasAlphabet);
		int sameAlphabetCnt = 0;
		for (int i = 0; i < str2.length(); ++i)
		{
			if (hasAlphabet.find(str2[i]) != hasAlphabet.end())
			{
				++sameAlphabetCnt;
				hasAlphabet.erase(str2[i]);
			}
		}
		return sameAlphabetCnt;
	}

	int getPartialAlphabetPoint(int totalAlphabetCnt, int sameAlphabetCnt)
	{
		return ((double)sameAlphabetCnt / totalAlphabetCnt) * MAX_ALPHABET_POINT;
	}

	const int MAX_LENGTH_POINT = 60;
	const int MIN_LENGTH_POINT = 0;

	const int MAX_ALPHABET_POINT = 40;
	const int MIN_ALPHABET_POINT = 0;
};