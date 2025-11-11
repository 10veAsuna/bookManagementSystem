#pragma once
#ifndef BOOK_H
#define BOOK_H

#include <string>

namespace Library {
	class Book {
	private:
		std::string ISBN;
		std::string name;
		std::string author;
		double price;
		int quantityInStock;	//库存数量
		int borrowTimes;		//借阅次数

	public:
		//默认构造函数
		Book() = default;
		//含参构造函数
		Book(std::string i, std::string n, std::string a , double p, int q) : ISBN(i), name(n), author(a),  price(p), quantityInStock(q), borrowTimes(0) {};
		
		std::string getISBN() const{
			return ISBN;
		}

		std::string getName() const{
			return name;
		}

		std::string getAuthor() const{
			return author;
		}

		int getQuantityInStock() const {
			return quantityInStock;
		}

		int getBorrowTimes() const {
			return borrowTimes;
		}

		double getPrice()const {
			return price;
		}

		//设置库存和借阅次数的方法
		void setQuantityInStock(int quantity) {
			quantityInStock = quantity;
		}

		void increaseBorrowTimes() {
			borrowTimes++;
		}

		void decreaseQuantity() {
			if (quantityInStock > 0){	
				quantityInStock--;
			}
		}

		void increaseQuantity() {
			quantityInStock++;
		}
	};
}
#endif // !BOOK_H
