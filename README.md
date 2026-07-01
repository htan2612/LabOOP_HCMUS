# Lab 01 – Introduction to Class (C++)

## Lý thuyết tổng quan

### 1. Class là gì?
Class là một kiểu dữ liệu do người dùng tự định nghĩa, đóng gói dữ liệu (attributes) và hành vi (methods) lại với nhau.

```cpp
class TenClass {
private:
    // thuộc tính (ẩn với bên ngoài)
    int x;
public:
    // phương thức (giao tiếp với bên ngoài)
    void setX(int x);
    int getX() const;
};
```

---

### 2. Encapsulation (Đóng gói)
- `private`: chỉ truy cập được bên trong class
- `public`: truy cập được từ bên ngoài
- `protected`: dùng khi kế thừa

**Quy tắc:** thuộc tính luôn để `private`, truy cập qua getter/setter.

```cpp
class Fraction {
private:
    int numerator, denominator;   // không ai ngoài class được đụng trực tiếp
public:
    int getNumerator() const { return numerator; }
    void setNumerator(int n) { numerator = n; }
};
```

---

### 3. Constructor (Hàm tạo)
Tự động gọi khi tạo object. Không có kiểu trả về.

| Loại | Mô tả | Ví dụ |
|------|-------|-------|
| Default constructor | Không tham số | `Fraction()` |
| Parameterized constructor | Có tham số | `Fraction(int num, int den)` |
| Copy constructor | Sao chép từ object khác | `Fraction(const Fraction& f)` |

```cpp
// Cách viết chuẩn dùng initializer list
Fraction::Fraction() : numerator(0), denominator(1) {}
Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {}
```

---

### 4. Destructor (Hàm huỷ)
Tự động gọi khi object bị xoá. Quan trọng khi dùng bộ nhớ động.

```cpp
class IntegerArray {
private:
    int* data;
public:
    IntegerArray()  { data = new int[10]; }
    ~IntegerArray() { delete[] data; }    // bắt buộc để tránh memory leak
};
```

---

### 5. `const` method
Phương thức không thay đổi dữ liệu của object — dùng từ khoá `const` sau tên hàm.

```cpp
void outputFraction() const;   // đảm bảo không sửa numerator, denominator
bool isValid() const;
```

---

### 6. Getter & Setter
- **Getter**: đọc giá trị thuộc tính private
- **Setter**: ghi giá trị, có thể kiểm tra hợp lệ trước khi gán

```cpp
double getTheoryScore() const { return theoryScore; }

void setTheoryScore(double s) {
    if (s >= 0 && s <= 10) theoryScore = s;
    else cout << "Invalid score!" << endl;
}
```

---

### 7. Tổ chức file (.h và .cpp)

| File | Nội dung |
|------|----------|
| `ClassName.h` | Khai báo class (declaration) |
| `ClassName.cpp` | Định nghĩa các method (definition) |
| `main.cpp` | Chương trình chính |

```cpp
// ClassName.h
#pragma once
class Point {
    ...
};

// ClassName.cpp
#include "ClassName.h"
Point::Point() : x(0), y(0) {}

// main.cpp
#include "ClassName.h"
int main() { Point p; }
```

`#pragma once` ngăn file `.h` bị include nhiều lần.

---

### 8. `this` pointer
Con trỏ trỏ đến object hiện tại, dùng khi tên tham số trùng với tên thuộc tính.

```cpp
void setX(double x) {
    this->x = x;   // this->x là thuộc tính, x là tham số
}
```

---

### 9. Bộ nhớ động (Dynamic Memory)
Dùng khi kích thước chưa biết lúc biên dịch.

```cpp
int* data = new int[size];   // cấp phát
delete[] data;               // giải phóng — BẮT BUỘC

// Copy constructor khi có bộ nhớ động
IntegerArray::IntegerArray(const IntegerArray& other) : size(other.size) {
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = other.data[i];
}

// Assignment operator
IntegerArray& IntegerArray::operator=(const IntegerArray& other) {
    if (this == &other) return *this;   // tự gán
    delete[] data;
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = other.data[i];
    return *this;
}
```

**Quy tắc Rule of Three:** nếu class có destructor → cần viết thêm copy constructor và assignment operator.

---

### 10. Reuse class (Tái sử dụng)
Class có thể dùng làm thuộc tính của class khác.

```cpp
class Student {
private:
    Date dob;       // dùng lại class Date
    string name;
};

class Rectangle {
private:
    Point vertices[4];   // dùng lại class Point
};
```

---

## Tóm tắt từng bài

### Ex1 – Fraction
- Class phân số với `numerator`, `denominator`
- Rút gọn bằng GCD (Euclidean algorithm)
- Các phép tính: cộng, trừ, nhân, chia

### Ex2 – Point
- Toạ độ thực `(x, y)` trong hệ Oxy
- Khoảng cách Euclidean: `sqrt((x2-x1)² + (y2-y1)²)`
- Khoảng cách đến gốc O: `sqrt(x² + y²)`

### Ex3 – Rectangle
- Gồm 4 đỉnh là object `Point`, theo chiều kim đồng hồ
- Kiểm tra hợp lệ: tích vô hướng 2 cạnh kề = 0 (vuông góc) và 2 cặp cạnh đối bằng nhau
- Tính chu vi, diện tích chỉ khi hình chữ nhật hợp lệ

### Ex4 – Date
- Kiểm tra năm nhuận: chia hết 4 nhưng không chia hết 100, hoặc chia hết 400
- Ngày hôm sau / hôm trước: xử lý tràn tháng, tràn năm
- So sánh 2 ngày theo thứ tự năm → tháng → ngày

### Ex5 – Student
- Tái sử dụng class `Date` cho ngày sinh
- Xếp loại: Excellent ≥ 8.0 / Good ≥ 6.5 / Average ≥ 5.0 / Weak < 5.0
- Điểm phải trong khoảng [0, 10]

### Ex6 – IntegerArray
- Mảng động: `new int[size]` / `delete[] data`
- Bắt buộc: default constructor, parameterized constructor, copy constructor, assignment operator, destructor
- Sắp xếp tăng dần bằng selection sort

---

## Lỗi thường gặp

| Lỗi | Nguyên nhân | Cách sửa |
|-----|------------|----------|
| `LNK2019` unresolved external | File `.cpp` không được add vào project | Add file vào project Visual Studio |
| `error C3646` unknown override specifier | Thiếu `#include <string>` trong `.h` | Thêm `#include <string>` và `using namespace std;` |
| Memory leak | Quên `delete[]` trong destructor | Luôn viết destructor khi dùng `new` |
| Tự gán (`a = a`) | Không kiểm tra trong `operator=` | Thêm `if (this == &other) return *this;` |