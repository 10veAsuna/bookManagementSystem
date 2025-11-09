#pragma once
#ifndef BORROWRECORD_H
#define BORROWRECORD_H
#include "book.h"
#include <string>
namespace BorrowRecord {
	class BorrowRecord
	{
	public:
		BorrowRecord() = default;
		BorrowRecord(int id, int is, std::string b, std::string e, std::string r) :isbn(is), idCardNumber(id) , borrowDay(b) , expectedReturnDay(e), realReturnDay(r){};
		int showIDCardNumber()const {
			return idCardNumber;
		}

		int showIsbn()const {
			return isbn;
		}

		std::string showBorrowDay()const {
			return borrowDay;
		}

		std::string showExpectedReturnDay()const {
			return expectedReturnDay;
		}

		std::string showRealReturnDay()const {
			return realReturnDay;
		}
	private:
		int idCardNumber;		//借书证号
		int isbn;				//书号
		std::string borrowDay;	//借阅日期
		std::string expectedReturnDay;	//应还日期
		std::string realReturnDay;		//实际还书日期
	};


}
#endif // !BORROWRECORD_H
