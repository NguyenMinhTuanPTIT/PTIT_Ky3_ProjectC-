#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <windows.h>
using namespace std;

// Cấu trúc lưu thông tin người dùng
struct NguoiDung {
    string tenDangNhap;
    string matKhau;
    int diemThuong;
};

// Hàm đăng ký người dùng mới
bool dangKyNguoiDung(const string& tenDangNhap, const string& matKhau) {
    // Mở file nguoidung.txt để ghi thêm dữ liệu
    ofstream fileGhi("nguoidung.txt", ios::app);
    if (!fileGhi) {
        wcout << L"Lỗi: Không mở được file nguoidung.txt để ghi!" << endl;
        return false;
    }
    // Ghi thông tin người dùng vào file
    fileGhi << tenDangNhap << " " << matKhau << " 0" << endl;
    fileGhi.close();
    wcout << L"Đăng ký thành công!" << endl;
    return true;
}

// Hàm đăng nhập người dùng
bool dangNhapNguoiDung(const string& tenDangNhap, const string& matKhau) {
    // Mở file nguoidung.txt để đọc
    ifstream fileDoc("nguoidung.txt");
    if (!fileDoc) {
        wcout << L"Lỗi: Không mở được file nguoidung.txt để đọc!" << endl;
        return false;
    }
    // Đọc từng dòng trong file
    string tenLuu, matKhauLuu;
    int diemLuu;
    while (fileDoc >> tenLuu >> matKhauLuu >> diemLuu) {
        if (tenLuu == tenDangNhap && matKhauLuu == matKhau) {
            fileDoc.close();
            wcout << L"Đăng nhập thành công! Chào mừng, " << tenDangNhap.c_str() << endl;
            return true;
        }
    }
    fileDoc.close();
    wcout << L"Tên đăng nhập hoặc mật khẩu không đúng!" << endl;
    return false;
}

int main() {
    // Thiết lập mã hóa UTF-8 cho console
    SetConsoleOutputCP(CP_UTF8);
    // Thiết lập locale tiếng Việt
    setlocale(LC_ALL, "Vietnamese_Vietnam.utf8");
    // Sử dụng wcout để hiển thị tiếng Việt
    wcout << L"Dự án PTIT Kỳ 3 - Giai đoạn 2" << endl;
    // Thử hàm đăng ký và đăng nhập
    dangKyNguoiDung("nguoidung1", "matkhau1");
    dangNhapNguoiDung("nguoidung1", "matkhau1");
    return 0;
}