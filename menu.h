#ifndef MENU_H
#define MENU_H
#include <string>
#include <vector>

class BakedGoods {
	protected:
		std::string name;
		double price;
		int bakeTime;
		std::vector<std::string> ingredients;

	public:
		BakedGoods(const BakedGoods &myBakedGoods);
		BakedGoods(std::string itemName, double itemPrice, int itemBakeTime, std::vector<std::string> itemIngredients);
		double getPrice();
		std::vector<std::string> getIngredients();
		void listIngredients(const std::vector<std::string> &itemIngredients);//Want to pass vector by const reference here
		void printOrder();
};

class Bread : public BakedGoods {
	public: 
		Bread(const Bread &myBread);
		Bread(std::string itemName, double itemPrice, int itemBakeTime, std::vector<std::string> itemIngredients);
};

class Bagel : public Bread {
	public:
		Bagel(const Bagel &myBagel);
		Bagel(std::string itemName, double itemPrice, int itemBakeTime, std::vector<std::string> itemIngredients);
};

class Cake : public BakedGoods {
	std::string decoration;

	public:
		friend std::string frosting();
		Cake(const Cake &myCake);
		Cake(std::string itemName, double itemPrice, int itemBakeTime, std::vector<std::string> itemIngredients);
		void setDecoration(std::string decorationText);
		std::string getDecoration();
};

class Cookie : public BakedGoods {
	public:
		Cookie(const Cookie &myCookie);
		Cookie(std::string itemName, double itemPrice, int itemBakeTime, std::vector<std::string> itemIngredients);
};

Bread selectBread();
Bagel selectBagel();
Cake selectCake();
Cookie selectCookie();

#endif