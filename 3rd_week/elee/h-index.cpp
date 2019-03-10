#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	int size = citations.size(); // size of citations array

	// sort
	for (int i = 0; i < size; ++i)
	{
		int max = i;

		for (int j = i; j < size; ++j)
		{
			if (citations[max] < citations[j])
				max = j;
		}

		int temp = citations[max];
		citations[max] = citations[i];
		citations[i] = temp;
	}

	// h-index
	while (true)
	{
		if (answer < size && citations[answer] >= answer + 1)
			++answer;
		else
			break;
	}

	return answer;
}