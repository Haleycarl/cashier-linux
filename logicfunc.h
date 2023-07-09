#include "sqlite3.h"
#include <iostream>
/*
For logic such as:
Scanning
Inserting
Deleting
Total
*/
class Logic{
	private:
		float price,total;
		std::string name;
		std::string prod_code;
	public:
		void clearevery(){
			price=0;
			name="";
			total=0;
		}
		float prodtotal(){
			return total;
		}
		std::string prodcode(){
			return prod_code;
		}
		float prodprice(){
			return price;
		}
		std::string prodname(){
			return name;
		}
		void scan(std::string code){
			sqlite3 *db;
			sqlite3_stmt *stmt;
			sqlite3_open("data.db",&db);
			prod_code =  code;
			name = "";
			price = 0;
			std::string query = "select * from products where code = " + code +";";
			sqlite3_prepare_v2(db, query.c_str() ,-1, &stmt, NULL);
			sqlite3_step(stmt);
			if(sqlite3_column_text(stmt,1) != NULL){ // Handle error if the data doesnt exists
				name = (char *)sqlite3_column_text(stmt, 1); 
				price = sqlite3_column_double(stmt,2);
				total+=price;
			}
			sqlite3_close(db);
		}
		void insert(std::string code,std::string name,std::string price){
			sqlite3 *db;
			sqlite3_open("data.db",&db);
			std::string query = "insert or replace into products values("+code+",'"+name+"',"+price+");";
			sqlite3_exec(db,query.c_str(), NULL, 0, NULL);
			sqlite3_close(db);

		}
		void erase(std::string code){
			sqlite3 *db;
			sqlite3_open("data.db",&db);
			std::string query = "delete from products where code = "+code+";";
			sqlite3_exec(db,query.c_str(), NULL, 0, NULL);
			sqlite3_close(db);

		}
};
