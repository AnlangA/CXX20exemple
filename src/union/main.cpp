#include <cstring>
#include <iostream>
#include <string> // std::string
#include <variant>
// Basic union
union NumberUnion {
  int intValue;
  float floatValue;
  double doubleValue;
};
union Data {
  struct {
    int x;
    int y;
  } point;

  struct {
    double length;
    double width;
  } rectangle;
};

class SafeUnion {
private:
  union Data {
    int intValue;
    float floatValue;
    char stringValue[20];

    // Union constructors
    Data() : intValue(0) {} // Default constructor
  } data;

  enum class Type { INT, FLOAT, STRING } currentType;

public:
  SafeUnion() : currentType(Type::INT) {}

  void setInt(int value) {
    data.intValue = value;
    currentType = Type::INT;
  }

  void setFloat(float value) {
    data.floatValue = value;
    currentType = Type::FLOAT;
  }

  void setString(const char *value) {
    strncpy(data.stringValue, value, 19);
    data.stringValue[19] = '\0';
    currentType = Type::STRING;
  }

  void printValue() {
    switch (currentType) {
    case Type::INT:
      std::cout << "Int: " << data.intValue << "\n";
      break;
    case Type::FLOAT:
      std::cout << "Float: " << data.floatValue << "\n";
      break;
    case Type::STRING:
      std::cout << "String: " << data.stringValue << "\n";
      break;
    }
  }
};
// Using union to save memory in a data structure
struct Pixel {
  union {
    struct {
      short red;
      short green;
      short blue;
      short alpha;
    };
    int color; // Same memory as the individual components
  };
};
int main() {
  NumberUnion num;

  num.intValue = 42;
  std::cout << "Int value: " << num.intValue << "\n";

  num.floatValue = 3.14f; // This overwrites the previous int value
  std::cout << "Float value: " << num.floatValue << "\n";
  std::cout << "Int value is now corrupted: " << num.intValue << "\n";

  Data data;
  // Using as a point
  data.point.x = 10;
  data.point.y = 20;
  std::cout << "Point: (" << data.point.x << ", " << data.point.y << ")\n";

  // Using as a rectangle
  data.rectangle.length = 5.5;
  data.rectangle.width = 2.5;
  std::cout << "Rectangle: " << data.rectangle.length << " x "
            << data.rectangle.width << "\n";

  // Modern C++ alternative to unions
  std::variant<int, float, std::string> data1 = 0;  // 默认初始化为int类型的0

     // 赋值一个整数并打印
     data1 = 42;
     if (std::holds_alternative<int>(data1)) {
         std::cout << "Integer: " << std::get<int>(data1) << "\n";
     }

     // 赋值一个浮点数并打印
     data1 = 3.14f;
     if (std::holds_alternative<float>(data1)) {
         std::cout << "Float: " << std::get<float>(data1) << "\n";
     }

     // 赋值一个字符串并打印
     data1 = "Hello";
     if (std::holds_alternative<std::string>(data1)) {
         std::cout << "String: " << std::get<std::string>(data1) << "\n";
     }
     // 错误处理：尝试获取错误类型的示例
     try {
         std::get<int>(data1); // 这会抛出异常，因为data当前持有的是std::string
     } catch (const std::bad_variant_access& e) {
         std::cout << "Error: " << e.what() << "\n";
     }

  SafeUnion value;

  value.setInt(42);
  value.printValue();

  value.setFloat(3.14f);
  value.printValue();

  value.setString("Hello World");
  value.printValue();

  Pixel p;
  p.color = 0xFF0000FF; // Red color

  std::cout << "Red: " << (int)p.red << "\n";
  std::cout << "Green: " << (int)p.green << "\n";
  std::cout << "Blue: " << (int)p.blue << "\n";
  std::cout << "Alpha: " << (int)p.alpha << "\n";

  std::cout << "Size of Pixel: " << sizeof(Pixel) << " bytes\n";
}
