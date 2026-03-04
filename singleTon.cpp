#include <iostream>
using namespace std;

// 单例模式demo-饿汉式
class SingleTon {
private:
	static SingleTon* instance;
	SingleTon(){ } // 无参构造
	// 拷贝构造函数 &防止栈溢出（递归死循环）
	SingleTon(const SingleTon& other){ }
	// 赋值
	SingleTon& operator=(const SingleTon&){ }
public:
	static SingleTon* getInstance() {
		return instance;
	}

};
// 类外实例化静态（static）变量
SingleTon* SingleTon::instance = new SingleTon();



int main() {
	SingleTon* ins1 = SingleTon::getInstance();
	SingleTon* ins2 = SingleTon::getInstance();
	SingleTon* ins3 = SingleTon::getInstance();
	
	cout << ins1 << endl;
	cout << ins2 << endl;
	cout << ins3 << endl;
}