import <iostream>;

class Base {
public:
    virtual void show() {
        std::cout << "Base show()" << std::endl;
    }
    // 虚析构函数
    virtual ~Base() {}
};

class Derived : public Base {
public:
    void show() override {
        std::cout << "Derived show()" << std::endl;
    }
};

int main() {
    Base* ptr = new Derived();
    ptr->show();  // 输出: "Derived show()"
    delete ptr;
    return 0;
}
