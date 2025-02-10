#include <iostream>
#include <sys/time.h>

#include "BaseDefine.h"
using namespace std;

QWORD getCurUSec()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (QWORD)tv.tv_sec * 1000000 + tv.tv_usec;
}

class test
{
	public:
		friend test func(int val);
		test() {bzero(a, 20);}
		//test(const test& cp) {bcopy(cp.a, a, 20);}
		virtual ~test() = default;
	private:
		int a[5];
};

class InitList
{
	public:
		InitList (int val) : j (val)
	{
		cout << j << endl;
		i = j;
		cout <<i << endl;
	}
	private:
		int i;
		int j;
		static int k;
};

class X
{
	public:
		X() = default;
		virtual ~X() = default;
	public:
			int a = 0;
			int b = 0;
			int c = 0;
};

class Y : public virtual X
{
	public:
		Y() = default;
		~Y() = default;
	public:
		int d = 0;
};

class Z : public virtual X
{
	public:
		Z() = default;
		~Z() = default;
	public:
		int e = 'd';
		int f = 'd';
};

class A : public Y, public Z
{
	public:
		A() : X(), Y(), Z() {}
		~A() = default;
		void func() {cout << "virtual func" <<endl;}
	public:
		int g = 0;
};

test func(int val)
{
	test a;
	a.a[0] = val;
	a.a[4] = val;
	return a;
}