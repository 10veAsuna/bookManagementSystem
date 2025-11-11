#pragma once
#ifndef LIBRARY_MANAGER
#define LIBRARY_MANAGER

#include <iostream>
#include <string>
#include <vector>
#include "book.h"
#include "borrowRecord.h"
namespace Library {
	class LibraryManager {
	private:
		std::vector<Library::Book> books;

		std::vector<Library::BorrowRecord> records;
	public:
		LibraryManager() = default;

        //添加图书，引用传递
        void addBook(const Library::Book& b) {
            books.push_back(b);
        }

        void showAllBooks() {
            if (books.empty()) {
                std::cout << "图书馆暂无图书" << std::endl;
                return;
            }
            for (auto it = books.begin(); it != books.end(); it++) {
                std::cout << "============================" << std::endl;
                std::cout <<
                    "书名 : " << it->getName() << std::endl <<
                    "作者 : " << it->getAuthor() << std::endl <<
                    "ISBN : " << it->getISBN() << std::endl <<
                    "价格 : " << it->getPrice() << std::endl <<
                    "库存数量 : " << it->getQuantityInStock() << std::endl <<
                    "借阅次数 : " << it->getBorrowTimes() << std::endl;
            }
        }

		void searchBook(const std::string& keywords) {
            bool found = false;
            for (auto it = books.begin(); it != books.end(); it++){
                if (keywords == it->getName() || keywords == it->getAuthor()) {
                    std::cout << "============================" << std::endl;
                    std::cout <<
                        "书名 : " << it->getName() << std::endl <<
                        "作者 : " << it->getAuthor() << std::endl <<
                        "ISBN : " << it->getISBN() << std::endl <<
                        "价格 : " << it->getPrice() << std::endl <<
                        "库存数量 : " << it->getQuantityInStock() << std::endl <<
                        "借阅次数 : " << it->getBorrowTimes() << std::endl;
                    found = true;
                }
            }
            if (!found) {
                std::cout << "未找到图书 " << std::endl;
            }
		}

        bool borrowBook(int cardNumber, const std::string& isbn) {
            // 1. 在图书集合中查找这本书
            for (auto& book : books) {
                if (book.getISBN() == isbn) {

                    // 2. 检查这本书的库存是否 > 0
                    if (book.getQuantityInStock() > 0) {

                        // 3. 库存减1，借阅次数加1
                        book.decreaseQuantity();      // quantityInStock--
                        book.increaseBorrowTimes();   // borrowTimes++

                        // 4. 创建借阅记录
                        BorrowRecord record(cardNumber, isbn, "2024-11-11", "2024-12-11");
                        records.push_back(record);

                        std::cout << "借书成功" << std::endl;
                        return true;  // 借书成功
                    }
                    else {
                        std::cout << "库存不足，借书失败" << std::endl;
                        return false;
                    }
                }
            }
            std::cout << "未找到ISBN为" << isbn << "的图书，借书失败" << std::endl;
            return false;  // 借书失败
        }

        // 还书 - 需要实现
        bool returnBook(int cardNumber, const std::string& isbn, const std::string& returnDate) {
            // 需要实现：找到借阅记录，更新还书日期，恢复图书库存
            for (auto& record : records) {
                if (record.getIsbn() == isbn && record.getIDCardNumber() == cardNumber && record.getRealReturnDay().empty()) {
                    record.setRealReturnDay(returnDate);
                    for (auto& book : books) {
                        if (book.getISBN() == isbn) {
                            book.increaseQuantity();
                            std::cout << "还书成功" << std::endl;
                            return true;
                        }
                    }
                }
            }
            std::cout << "未找到借阅记录或图书已还" << std::endl;
            return false;
        }

        void getBorrowRecord() {
            if (records.empty()){
                std::cout << "没有借阅记录" << std::endl;
                return;
            }

            std::cout << "=========== 所有借阅记录 ===========" << std::endl;
            for (const auto& record : records) {
                std::cout << "借书证: " << record.getIDCardNumber()
                    << " | ISBN: " << record.getIsbn()
                    << " | 借期: " << record.getBorrowDay()
                    << " | 应还: " << record.getExpectedReturnDay();

                if (record.getRealReturnDay().empty()) {
                    std::cout << " | 状态: 未归还" << std::endl;
                }
                else {
                    std::cout << " | 实还: " << record.getRealReturnDay() << " | 状态: 已归还" << std::endl;
                }
            }
        }

        void statisticPopularBooks() {
            if (books.empty()) {
                std::cout << "暂无图书数据" << std::endl;
                return;
            }

            std::cout << "=========== 热门图书TOP5 ===========" << std::endl;

            // 创建副本进行排序，不修改原数据顺序
            std::vector<Library::Book> sortedBooks = books;

            for (int i = 0; i < sortedBooks.size() - 1; i++) {
                for (int j = 0; j < sortedBooks.size() - i - 1; j++) {
                    if (sortedBooks[j].getBorrowTimes() < sortedBooks[j + 1].getBorrowTimes()) {
                        auto temp = sortedBooks[j];
                        sortedBooks[j] = sortedBooks[j + 1];
                        sortedBooks[j + 1] = temp;
                    }
                }
            }

            for (int i = 0; i < 5 && i < sortedBooks.size(); i++) {
                std::cout << "第" << (i + 1) << "名: " << sortedBooks[i].getName()
                    << " - 借阅" << sortedBooks[i].getBorrowTimes() << "次" << std::endl;
            }
        }
        
	};
}
#endif // !LIBRARY_MANAGER
