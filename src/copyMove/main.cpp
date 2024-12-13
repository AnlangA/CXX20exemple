#include <iostream>

class Vector {
public:
    // 构造函数
    Vector(int s) : elem{new double[s]}, sz{s} {
        for (int i = 0; i < s; ++i) elem[i] = 0;
    }

    // 析构函数
    ~Vector() {
        delete[] elem;
    }

    // 拷贝构造函数
    Vector(const Vector& a) : elem{new double[a.sz]}, sz{a.sz} {
        for (int i = 0; i < sz; ++i) {
            elem[i] = a.elem[i];
        }
    }

    // 拷贝赋值运算符
    Vector& operator=(const Vector& a) {
        if (this != &a) {  // 自赋值检查
            double* p = new double[a.sz];
            for (int i = 0; i < a.sz; ++i) {
                p[i] = a.elem[i];
            }
            delete[] elem;
            elem = p;
            sz = a.sz;
        }
        return *this;
    }
    // 下标运算符
    double& operator[](int i) {
        if (i < 0 || i >= sz) throw std::out_of_range("Vector::operator[]");
        return elem[i];
    }

private:
    double* elem;
    int sz;
};
int main() {
    std::cout << "创建并初始化向量:" << std::endl;
    Vector v1(3);
    v1[0] = 1.0; v1[1] = 2.0; v1[2] = 3.0;

    std::cout << "\n演示拷贝构造:" << std::endl;
    Vector v2(v1);  // 调用拷贝构造函数
    std::cout << "v2[0] = " << v2[0] << "; v2[1]=" <<  v2[1] << "; v2[2]=" << v2[2];

    std::cout << "\n演示拷贝赋值:" << std::endl;
    Vector v3(5);
    v3 = v1;  // 调用拷贝赋值运算符
    std::cout << "v3[0] = " << v3[0] << "; v3[1]=" <<  v3[1] << "; v3[2]=" << v3[2];

    std::cout << "\n演示移动构造:" << std::endl;
    Vector v4 = std::move(v1);  // v1的资源被移动到v4
    try {
        std::cout << "v1[0] = " << v1[0] << "; v1[1]=" <<  v1[1] << "; v1[2]=" << v1[2];
    } catch (const std::out_of_range& e) {
        std::cout << "v1 had moved. Error: " << e.what() << std::endl;
    }
    std::cout << "v4[0] = " << v4[0] << "; v4[1]=" <<  v4[1] << "; v4[2]=" << v4[2];

    std::cout << "\n演示移动赋值:" << std::endl;
    Vector v5(2);
    Vector& ref1(v2);
    v5 = std::move(ref1);  // v2的资源被移动到v5
    try {
        std::cout << "v2[0] = " << v2[0] << "; v2[1]=" <<  v2[1] << "; v2[2]=" << v2[2];
    } catch (const std::out_of_range& e) {
        std::cout << "v2 had moved. Error: " << e.what() << std::endl;
    }
    std::cout << "v5[0] = " << v5[0] << "; v5[1]=" <<  v5[1] << "; v5[2]=" << v5[2] << std::endl;


    return 0;
}
