#include <string>

using namespace std;

class SimilarityChecker
{
public:
	int getPartialPoint(string text1, string text2)
	{
		int gap = abs((int)text1.size() - (int)text2.size());

		int shortTextSize = text1.size();
		if (text1.size() > text2.size())
		{
			shortTextSize = text2.size();
		}
		return (1 - ( (double) gap / shortTextSize)) * 60;
	}

	int getLengthPoint(string text1, string text2)
	{
		if (text1.size() == text2.size()) return 60;
		else if (text1.size() >= text2.size() * 2
			|| text1.size() * 2 <= text2.size())
		{
			return 0;
		}
		else {
			return getPartialPoint(text1, text2);
		}
	}
};
