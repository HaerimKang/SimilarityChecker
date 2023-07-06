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

	int getAlphaPoint(string str1, string str2)
	{
		map<char, bool> hasAlphabet;
		for(int i=0; i< str1.length(); ++i)
		{
			hasAlphabet.insert({ str1[i],true });
		}

		for (int i = 0; i < str2.length(); ++i)
		{
			if(hasAlphabet.find(str2[i])!= hasAlphabet.end())
			{
				hasAlphabet.erase(str2[i]);
			}
			else
			{
				return 0;
			}
		}
		if (hasAlphabet.size() == 0) return 40;
		else return 0;
		
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