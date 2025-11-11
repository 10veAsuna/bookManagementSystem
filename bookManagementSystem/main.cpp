#include <iostream>
#include "book.h"
#include "borrowRecord.h"
#include "LibraryManager.h"

using namespace Library;

int main() {
    LibraryManager library;
    int choice;
    // 在main函数开始添加测试数据
    Library::Book book1("001", "C++ Primer", "Lippman", 99.9, 3);
    Library::Book book2("002", "算法导论", "Cormen", 128.0, 2);
    Library::Book book3("003", "设计模式", "Gamma", 89.9, 1);

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    do {
        std::cout << "\n=========== 图书馆管理系统 ===========" << std::endl;
        std::cout << "1. 添加图书" << std::endl;
        std::cout << "2. 显示所有图书" << std::endl;
        std::cout << "3. 查找图书" << std::endl;
        std::cout << "4. 借书" << std::endl;
        std::cout << "5. 还书" << std::endl;
        std::cout << "6. 查看借阅记录" << std::endl;
        std::cout << "7. 热门图书统计" << std::endl;
        std::cout << "0. 退出" << std::endl;
        std::cout << "请选择功能: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string isbn, name, author;
            double price;
            int quantity;

            std::cout << "请输入ISBN: ";
            std::cin >> isbn;
            std::cout << "请输入书名: ";
            std::cin >> name;
            std::cout << "请输入作者: ";
            std::cin >> author;
            std::cout << "请输入价格: ";
            std::cin >> price;
            std::cout << "请输入库存数量: ";
            std::cin >> quantity;

            Book newBook(isbn, name, author, price, quantity);
            library.addBook(newBook);
            std::cout << "添加成功！" << std::endl;
            break;
        }
        case 2:
            library.showAllBooks();
            break;
        case 3: {
            std::string keyword;
            std::cout << "请输入书名或作者: ";
            std::cin >> keyword;
            library.searchBook(keyword);
            break;
        }
        case 4: {
            int cardNumber;
            std::string isbn;
            std::cout << "请输入借书证号: ";
            std::cin >> cardNumber;
            std::cout << "请输入ISBN: ";
            std::cin >> isbn;
            library.borrowBook(cardNumber, isbn);
            break;
        }
        case 5: {
            int cardNumber;
            std::string isbn, returnDate;
            std::cout << "请输入借书证号: ";
            std::cin >> cardNumber;
            std::cout << "请输入ISBN: ";
            std::cin >> isbn;
            std::cout << "请输入还书日期(YYYY-MM-DD): ";
            std::cin >> returnDate;
            library.returnBook(cardNumber, isbn, returnDate);
            break;
        }
        case 6:
            library.getBorrowRecord();
            break;
        case 7:
            library.statisticPopularBooks();
            break;
        case 0:
            std::cout << "谢谢使用！" << std::endl;
            break;
        default:
            std::cout << "无效选择！" << std::endl;
        }
    } while (choice != 0);

    return 0;
}