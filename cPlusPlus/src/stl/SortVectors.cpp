#include "SortVectors.h"

// even though this is in cpp and not exposed, while compiling together with other cpps
// runtime crash was happening in runStack testStack.push(Test("Vicky"));
// be careful!
// hence had to be named TestSort instead of Test

class TestSort1
{
public:
	TestSort1(int id, string name) : m_id(id), m_name(name) {}

	void print() const
	{
		cout << m_id << ": " << m_name << endl;
	}

	// usual way
	bool operator<(const TestSort1 &other) const
	{
		return m_name < other.m_name;
	}

private:
	int m_id;
	string m_name;
};

class TestSort2
{
public:
	TestSort2(int id, string name) : m_id(id), m_name(name) {}

	void print() const
	{
		cout << m_id << ": " << m_name << endl;
	}

	// allowed to access private members
	friend bool comp(const TestSort2 &a, const TestSort2 &b);

private:
	int m_id;
	string m_name;
};

// if we can't access the class to implement the operator<
// function pointer - custom comparator
// to access name we need to make it a friend
bool comp(const TestSort2 &a, const TestSort2 &b)
{
	return a.m_name < b.m_name;
}

void runSortVectors()
{
	vector<TestSort1> tests1;
	vector<TestSort2> tests2;

	tests1.push_back(TestSort1(5, "Mike"));
	tests1.push_back(TestSort1(10, "Sue"));
	tests1.push_back(TestSort1(7, "Raj"));
	tests1.push_back(TestSort1(3, "Vicky"));

	tests2.push_back(TestSort2(5, "Mike"));
	tests2.push_back(TestSort2(10, "Sue"));
	tests2.push_back(TestSort2(7, "Raj"));
	tests2.push_back(TestSort2(3, "Vicky"));

	// we can supply a range

	// needs < operator to work
	sort(tests1.begin(), tests1.end());

	// custom comparator function
	sort(tests2.begin(), tests2.end(), comp);

	for (unsigned int i = 0; i < tests1.size(); i++)
	{
		tests1[i].print();
	}

	for (unsigned int i = 0; i < tests2.size(); i++)
	{
		tests2[i].print();
	}
}