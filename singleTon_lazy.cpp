#include<iostream>
using namespace std;

// 单例模式demo-懒汉式
class SingleTon {
private:
	static SingleTon* instance;
	SingleTon() {} // 无参构造
	// 拷贝构造函数 &防止栈溢出（递归死循环）
	SingleTon(const SingleTon& other) {}
	// 赋值
	SingleTon& operator=(const SingleTon&) {}
public:
	static SingleTon* getInstancce();
};

// 不创建新的实例
SingleTon* SingleTon::instance = nullptr;


SingleTon* SingleTon::getInstancce() {
	if (instance == nullptr) {
		instance = new SingleTon();
	}
	return instance;
}


int main() {
	SingleTon* inst1 = SingleTon::getInstancce();
	SingleTon* inst2 = SingleTon::getInstancce();
	SingleTon* inst3 = SingleTon::getInstancce();
	
	cout << inst1 << endl;
	cout << inst2 << endl;
	cout << inst3 << endl;

	return 0;
}




