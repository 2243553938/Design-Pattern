#include<iostream>
#include<windows.h>
#include<thread> // thread线程,process进程
using namespace std;

// 单例模式下-单线程环境下懒汉式存在的问题

class SingleTon {
private:
	static SingleTon* instance;
	SingleTon() {
		Sleep(1000);
	};
	SingleTon(const SingleTon& other) { };
	SingleTon operator=(const SingleTon&) {};
public:
	static SingleTon* getInstance();
};


SingleTon* SingleTon::instance = nullptr;

SingleTon* ::SingleTon::getInstance() {
	if (instance == nullptr) {
		instance = new SingleTon;
	}
	return instance;
}

// 回调函数
void threadFunc() {
	// double word 双字(DWORD)
	DWORD id = GetCurrentThreadId();
	// 实例化
	SingleTon* ins = SingleTon::getInstance();
	cout << "当前线程的ID:" << id << "的实例为:" << ins << endl;
}

int main() {
	int threadNum = 3;
	thread threads[3];
	for (int i = 0; i < threadNum; i++) {
		threads[i] = thread(threadFunc);
	}
	for (int i = 0; i < threadNum; i++) {
		threads[i].join();
	}
	return 0;
}








