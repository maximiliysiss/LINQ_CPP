#pragma once
class TestClassForTest
{
public:
	int i, j;

	friend bool operator<(const TestClassForTest t, const TestClassForTest t2) { return true; }
	friend bool operator>(const TestClassForTest t, const TestClassForTest t2) { return true; }
	friend bool operator==(const TestClassForTest t, const TestClassForTest t2) { return true; }
};

