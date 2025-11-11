#pragma once
#ifndef BORROWRECORD_H
#define BORROWRECORD_H

#include <string>

namespace Library {
	class BorrowRecord
	{
	public:
		BorrowRecord() = default;
		BorrowRecord(int id, std::string is, std::string b, std::string e) :isbn(is), idCardNumber(id) , borrowDay(b) , expectedReturnDay(e){};
		
		int getIDCardNumber()const {
			return idCardNumber;
		}

		std::string getIsbn()const {
			return isbn;
		}

		std::string getBorrowDay()const {
			return borrowDay;
		}

		std::string getExpectedReturnDay()const {
			return expectedReturnDay;
		}

		std::string getRealReturnDay()const {
			return realReturnDay;
		}

		void setRealReturnDay(const std::string& returnDay) {
			realReturnDay = returnDay;
		}

		bool isReturned() const {
			return !realReturnDay.empty();
		}
	private:
		int idCardNumber;		//借书证号
		std::string isbn;				//书号
		std::string borrowDay;	//借阅日期
		std::string expectedReturnDay;	//应还日期
		std::string realReturnDay;		//实际还书日期
	};


}
#endif // !BORROWRECORD_H
