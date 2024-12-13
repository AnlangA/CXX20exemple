#include <iostream>
#include <type_traits>

void may_throw() {
    throw std::runtime_error("This function throws an exception!");
}

void no_throw() noexcept {
    std::cout << "This function does not throw!" << std::endl;
}

int main() {
    // 检查函数是否为 noexcept
    std::cout << "may_throw() is noexcept: " << std::boolalpha
              << noexcept(may_throw()) << std::endl; // 输出 false
    std::cout << "no_throw() is noexcept: " << std::boolalpha
              << noexcept(no_throw()) << std::endl; // 输出 true

    // 调用函数
    try {
        may_throw();
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    no_throw(); // 不抛出异常，正常执行

    return 0;
}
