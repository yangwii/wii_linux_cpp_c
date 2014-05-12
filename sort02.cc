#include <boost/noncopyable.hpp>
#include <boost/ptr_container/ptr_vector.hpp>

#include <algorithm>
#include <string>
#include <ext/vstring.h>
#include <vector>

//#include <datatime/Timestamp.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <sys/resource.h>

using namespace std;

typedef __gnu_cxx::__sso_string string;

class InputFile : boost::noncopyable
{
public:
	InputFile(const char* filename)
			:file_(fopen(filename, "rb"))
	{
		assert(file_);
		setbuffer(file_, buffer_, sizeof buffer_);
	}
	~InputFile()
	{
		fclose(file_);
	}

	bool readLine(string *line)
	{
		char buf[256];
		if(fgets_unlocked(buf, sizeof buf, file_))
		{
			line->assign(buf);
			return true;
		}
		else
		{
			return false;
		}
	}

	int read(char *buf, int size)
	{
		return fread_unlocked(buf, 1, size, file_);
	}
private:
	FILE* file_;
	char buffer_[64 * 1024];
};

const int kRecordSize = 100;
const int kKeySize = 10;

class OutputFile : boost::noncopyable
{
public:
	OutputFile(const char* filename)
		:file_(fopen(filename, "wb"))
	{
		assert(file_);
		setbuffer(file_, buffer_, sizeof buffer_);
	}

	~OutputFile()
	{
		fclose(file_);
	}

	void writeLine(const string& line)
	{
		if(line.empty())
		{
			fwrite_unlocked("\n", 1, 1, file_);
		}
		else if(line[line.size() - 1] == '\n')
		{
			fwrite_unlocked(line.c_str(), 1, line.size(), file_);
		}
		else
		{
			fwrite_unlocked(line.c_str(), 1, line.size(), file_);
			fwrite_unlocked("\n", 1, 1, file_);
		}
	}

	void writeRecord(char (&record)[kRecordSize])
	{
		fwrire_unlocked(record, 1, kRecordSize, file_);
	}

private:
	FILE* file_;
	char buffer_[64 * 1024];
};

const bool kUserReadLine = false;
const int kBatchRecords = 10000000;

void readInput(InputFile &in, vector<string> *data)
{
	int64_t totalSize = 0;
	data->clear();
	data->reverse(kBatchRecords);

	for(int i = 0; i < kBatchRecords; i++)
	{
		char buf[kRecordSize];
		if(int n = in.read(buf, sizeof buf))
		{
			assert(n == kRecordSize);
			totalSize += n;
			data->push_back(string(buf, n));
		}
		else
		{
			break;
		}
	}
}

struct Key
{
	char key[kKeySize];
	int index;

	Key(const string& record, int idx)
			:index(idx)
	{
		memcpy(key, record, sizeof key);
	}

	bool operator < (const Key& rhs) const
	{
		return memcmp(key, rhs.key, sizeof key) < 0;
	}
};

void _sort(const vector<string>& data, vector<Key>* keys)
{
	keys->reverse(data.size());
	for(int i = 0; i < data.size(); i++)
	{
		keys->push_back(Key(data[i], i));
	}

	sort(keys->begin(), keys->end());
}
void sortSplit(const char* filename)
{
	vector<string> data;

	InputFile in(filename);
	int batch = 0;
	while(true)
	{
		readInput(in, &data);
		printf("size:%zd\n", data.size());

		if(data.empty())
		{
			break;
		}
		vector<Key> keys;
		_sort(data, &keys);

		{	
			char output[256];
			snprintf(output, sizeof output, TMP_DIR "tmp%d", batch++);

			OutputFile(output);
			for(vector<Key>::iterator it = keys.begin();
								it != keys.end(); it++)
			{
				out.writeLine(data[it->index]);
			}
		}
	}

	return batch;
}

struct Record
{
	char data[kRecordSize];
	InputFile* input;

	Record(InputFile* in)
		:input(in)
	{
	}

	bool next()
	{
		return input->read(data, sizeof data) == kRecordSize;
	}

	bool operator<(const Record& rhs) const
	{
		return memcmp(data, rhs.data, kKeySize) > 0;
	}
};

void merge(const int batch)
{
	printf("Merge %d files\n", batch);
	
	boost::ptr_vector<InputFile> inputs;
	vector<Record> keys;

	for(int i = 0; i < batch; i++)
	{
		char filename[128];
		snprintf(filename, sizeof filename, TMP_DIR "tmp%d", i);
		inputs.push_back(new InputFile(filename));
		Record rec(&inputs.back());
		if(rec.next())
		{
			keys.push_back(rec);
		}
	}

	OutputFile out("output");
	make_heap(keys.begin(), keys.end());
	while(!keys.empty())
	{
		pop_heap(keys.begin(), keys.end());
		out.writeRecord(keys.back().data);

		if(keys.back().next())
		{
			push_heap(keys.begin(), keys.end());
		}
		else
		{
			keys.pop_back();
		}
	}
}
int main(void)
{
	bool kKeepIntermediateFiles = false;
	
	{
		size_t kOneGB = 1024*1024*1024;
		rlimit tl {1.0*kOneGB, 1.0*kOneGB};
		setrlimit(RLIMIT_AS, &rl);
	}

	int batch = sortSplit(argv[1]);
	return 0;
}
