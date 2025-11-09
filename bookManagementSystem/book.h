#pragma once
#ifndef BOOK_H
#define BOOK_H

#include <string>

namespace Book {
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
		Book(std::string i, std::string n,double p, std::string a, int q) : ISBN(i), name(n), author(a), quantityInStock(q), borrowTimes(0),price(p) {};
		
		std::string showISBN() const{
			return ISBN;
		}

		std::string showName() const{
			return name;
		}

		std::string showAuthor() const{
			return author;
		}

		int showQuantityInStock() const {
			return quantityInStock;
		}

		int showBorrowTimes() const {
			return borrowTimes;
		}

		double showPrice()const {
			return price;
		}


	};
}
#endif // !BOOK_H
