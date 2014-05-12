#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

typedef int Record;
typedef vector<Record> File;

struct Input
{
	Record value;
	size_t index;
	const File* file;

	explicit Input(const File* f)
		:value(-1), index(0), file(f)
	{
	}

	bool next()
	{
		if(index < file->size())
		{
			value = (*file)[index];
			++index;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator < (const Input& rhs) const
	{
		return value > rhs.value;
	}
};

File mergeN(const vector<File>& file)
{
	File output;
	vector<Input> inputs;
	for(size_t i = 0; i < file.size(); i++)
	{
		Input input(&file[i]);
		if(input.next())
		{
			inputs.push_back(input);
		}
	}

	make_heap(inputs.begin(), inputs.end());

	while(!inputs.empty())
	{
		pop_heap(inputs.begin(), inputs.end());
		output.push_back(inputs.back().value);

		if(inputs.back().next())
		{
			push_heap(inputs.begin(), inputs.end());
		}
		else
		{
			inputs.pop_back();
		}
	}

	return output;
}

int main(void)
{
	int sum = 0;
	const int kFiles = 32;
	vector<File> files(kFiles);
	for(int i = 0; i < kFiles; i++)
	{
		int num = rand() % 1000;
		sum += num;
		File file(num);
		generate(file.begin(), file.end(), &rand);
		sort(file.begin(), file.end());
		files[i].swap(file);
	}

	File output = mergeN(files);

	copy(output.begin(), output.end(), ostream_iterator<Record>(cout, "\n"));
	
	cout<<"Number:"<<sum<<endl;
	return 0;
}
