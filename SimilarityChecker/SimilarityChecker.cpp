#include <string>
#include <vector>
#include <map>

using namespace std;

class SimilarityChecker {
public:
	int getLengthPoint(const string& str1, const std::string& str2) {
		int A = getLongLength(str1, str2);
		int B = getShortLength(str1, str2);

		if (isSameLength(A, B)) return MAX_LENGTH_POINT;
		if (isDoubleLengthGap(A, B)) return MIN_LENGTH_POINT;
		return getPartialLengthPoint(A, B);
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

	int getAlphaPoint(string str1, string str2)
	{
		map<char, bool> hasAlphabet;
		saveAlphabetToMap(str1, hasAlphabet);

		bool isFound = false;
		bool isDifferent = false;
		for (int i = 0; i < str2.length(); ++i)
		{
			if(hasAlphabet.find(str2[i])!= hasAlphabet.end())
			{
				isFound = true;
				hasAlphabet.erase(str2[i]);
			}
			else
			{
				isDifferent = true;
			}
		}
		if (hasAlphabet.size() == 0 && isDifferent == false) return 40;
		else if (isFound == false) return 0;
		else
		{
			hasAlphabet.clear();
			saveAlphabetToMap(str1, hasAlphabet);
			saveAlphabetToMap(str2, hasAlphabet);
			int totalAlphabetCnt = hasAlphabet.size();

			//같은 알파벳 개수 세기
			hasAlphabet.clear();
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
			return ((double)sameAlphabetCnt / totalAlphabetCnt) * 40;
		}
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

	bool isSameLength(int A, int B) {
		return A == B;
	}

	bool isDoubleLengthGap(int A, int B) {
		return A >= B * 2;
	}

	int getPartialLengthPoint(int A, int B) {
		int GAP = A - B;
		return (B - GAP) * MAX_LENGTH_POINT / B;
	}

	const int MAX_LENGTH_POINT = 60;
	const int MIN_LENGTH_POINT = 0;
};