#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "menu.h"

BakedGoods::BakedGoods(const BakedGoods &myBakedGoods) {
}

BakedGoods::BakedGoods(std::string itemName, double itemPrice, int itemBakeTime, std::vector<std::string> itemIngredients) {
	name = itemName;
	price = itemPrice;
	bakeTime = itemBakeTime;
	ingredients = itemIngredients;
}

double BakedGoods::getPrice() {
	return price;
}

std::vector<std::string> BakedGoods::getIngredients() {
	return ingredients;
}

void BakedGoods::listIngredients(const std::vector<std::string> &itemIngredients) {
	std::string ingredient;
	std::size_t numIngredients = itemIngredients.size();

	std::cout << "\nIngredients: " << std::endl;

	for (int i=0; i<numIngredients; ++i) {
		ingredient = itemIngredients.at(i);
		std::cout << "-" + ingredient << std::endl;
	}
}

void BakedGoods::printOrder() {
	std::string paymentMethod;

	std::cout << "\nAlright! So we've got a " << name << ", coming right up!" << std::endl;
	std::cout << "That'll be $" << std::setprecision(2) << std::fixed << price << "." << std::endl;
	std::cout << "Will you be paying with cash or credit?\n1 - Cash\n2 - Credit" << std::endl;

	std::cin >> paymentMethod;

	if (paymentMethod != "1" && paymentMethod != "2") {
		std::cout << "\nTrying to steal from me, eh? Get out of my bakery before I call the police!";
		exit (EXIT_FAILURE);
	} else {
		std::cout << "\nThanks! It's going to take about " << bakeTime << " minutes to prepare your order. Would you like to read a list of ingredients while you wait? (yes/no)";
	}
}

Bread::Bread(const Bread &myBread) : BakedGoods(myBread) {
}

Bread::Bread(std::string itemName, double itemPrice, int itemBakeTime, std::vector<std::string> itemIngredients) : BakedGoods(itemName, itemPrice, itemBakeTime, itemIngredients) {
}

Bagel::Bagel(const Bagel &myBagel) : Bread(myBagel) {
}

Bagel::Bagel(std::string itemName, double itemPrice, int itemBakeTime, std::vector<std::string> itemIngredients) : Bread(itemName, itemPrice, itemBakeTime, itemIngredients) {
}

Cake::Cake(const Cake &myCake) : BakedGoods(myCake) {
}

Cake::Cake(std::string itemName, double itemPrice, int itemBakeTime, std::vector<std::string> itemIngredients) : BakedGoods(itemName, itemPrice, itemBakeTime, itemIngredients) {
}

Cookie::Cookie(const Cookie &myCookie) : BakedGoods(myCookie) {
}

Cookie::Cookie(std::string itemName, double itemPrice, int itemBakeTime, std::vector<std::string> itemIngredients) : BakedGoods(itemName, itemPrice, itemBakeTime, itemIngredients) {
}

Bread selectBread() {
	std::string isSweet;
	std::string breadName;
	std::string itemSelection;
	std::string slicedSelection;
	std::string toastSelection;
	bool isSliced;
	bool isToasted;
	std::vector<std::string> breadIngredients;

	breadIngredients.push_back("Flour");
	breadIngredients.push_back("Sugar");
	breadIngredients.push_back("Salt");

	std::cout << "Would you like something sweet? (yes/no) ";

	std::cin >> isSweet;

	if (isSweet == "yes" || isSweet == "Yes") {
		std::cout << "\nSure thing! Here are your choices:" << std::endl;

		std::cout << "1 - Banana\n2 - Pumpkin" << std::endl;
		std::cin >> itemSelection;
		if (itemSelection == "1") {
			breadName = "Loaf of Banana Bread";
			breadIngredients.push_back("Banana");
			breadIngredients.push_back("Egg");
			breadIngredients.push_back("Milk");
			breadIngredients.push_back("Baking Soda");
			breadIngredients.push_back("Vanilla");
		} else if (itemSelection == "2") {
			breadName = "Loaf of Pumpkin Bread";
			breadIngredients.push_back("Pumpkin");
			breadIngredients.push_back("Egg");
			breadIngredients.push_back("Milk");
			breadIngredients.push_back("Baking Soda");
			breadIngredients.push_back("Vanilla");
		} else {
			std::cout << "\nThat's not a choice. Stop wasting my time and get out of my bakery!" << std::endl;
			exit (EXIT_FAILURE);
		}
	} else if (isSweet == "no" || isSweet == "No") {
		std::cout << "\nSure thing! Here are your choices:" << std::endl;

		std::cout << "1 - Italian\n2 - French\n3 - Sourdough" << std::endl;
		std::cin >> itemSelection;
		if (itemSelection == "1") {
			breadName = "Loaf of Italian Bread";
			breadIngredients.push_back("Yeast");
		} else if (itemSelection == "2") {
			breadName = "Loaf of French Bread";
			breadIngredients.push_back("Yeast");
			breadIngredients.push_back("Egg White");
		} else if (itemSelection == "3") {
			breadName = "Loaf of Sourdough";
			breadIngredients.push_back("Yeast");
		} else {
			std::cout << "\nThat's not a choice. Stop wasting my time and get out of my bakery!" << std::endl;
			exit (EXIT_FAILURE);
		}
	} else {
		std::cout << "\nStop wasting my time and get out of my bakery!" << std::endl;
		exit (EXIT_FAILURE);
	}

	std::cout << "\nWould you like it sliced? (yes/no) ";

	std::cin >> slicedSelection;

	if (slicedSelection == "yes" || slicedSelection == "Yes") {
		breadName = breadName + ", sliced";
	} else if (slicedSelection == "no" || slicedSelection == "No") {
		std::cout << "\nOkay, we won't slice it for you." << std::endl;
	} else {
		std::cout << "\nStop wasting my time and get out of my bakery!" << std::endl;
		exit (EXIT_FAILURE);
	}

	return Bread(breadName, 10.99, 2, breadIngredients);
}

Bagel selectBagel() {
	std::string isSweet;
	std::string bagelName;
	std::string itemSelection;
	std::string slicedSelection;
	std::string toastSelection;
	bool isSliced;
	bool isToasted;
	std::vector<std::string> bagelIngredients;

	bagelIngredients.push_back("Flour");
	bagelIngredients.push_back("Sugar");
	bagelIngredients.push_back("Salt");
	bagelIngredients.push_back("Yeast");

	std::cout << "Would you like something sweet? (yes/no) ";

	std::cin >> isSweet;

	if (isSweet == "yes" || isSweet == "Yes") {
		std::cout << "\nSure thing! Here are your choices:" << std::endl;
		std::cout << "1 - Blueberry\n2 - Cinnamon Sugar" << std::endl;
		std::cin >> itemSelection;
		if (itemSelection == "1") {
			bagelName = "Blueberry Bagel";
			bagelIngredients.push_back("Blueberry");
		} else if (itemSelection == "2") {
			bagelName = "Cinnamon Sugar Bagel";
			bagelIngredients.push_back("Cinammon");
		} else {
			std::cout << "\nThat's not a choice. Stop wasting my time and get out of my bakery!" << std::endl;
			exit (EXIT_FAILURE);
		}
	} else if (isSweet == "no" || isSweet == "No") {
		std::cout << "\nSure thing! Here are your choices:" << std::endl;
		std::cout << "1 - Plain\n2 - Onion\n3 - Everything" << std::endl;
		std::cin >> itemSelection;
		if (itemSelection == "1") {
			bagelName = "Plain Bagel";
		} else if (itemSelection == "2") {
			bagelName = "n Onion Bagel";
			bagelIngredients.push_back("Onion");
		} else if (itemSelection == "3") {
			bagelName = "n Everything Bagel";
			bagelIngredients.push_back("Onion");
			bagelIngredients.push_back("Poppy Seeds");
			bagelIngredients.push_back("Sesame Seeds");
		} else {
			std::cout << "\nThat's not a choice. Stop wasting my time and get out of my bakery!" << std::endl;
			exit (EXIT_FAILURE);
		}
	} else {
		std::cout << "\nStop wasting my time and get out of my bakery!" << std::endl;
		exit (EXIT_FAILURE);
	}

	std::cout << "\nWould you like it sliced? (yes/no) ";

	std::cin >> slicedSelection;

	if (slicedSelection == "yes" || slicedSelection == "Yes") {

		std::cout << "\nWould you like it toasted? (yes/no) ";
		std::cin >> toastSelection;

		if (toastSelection == "yes" || toastSelection == "Yes") {
			isToasted = true;
			bagelName = "Sliced and Toasted" + bagelName;
		} else if (toastSelection == "no" || toastSelection == "No") {
			isToasted = false;
			bagelName = "Sliced " + bagelName;
		} else {
			std::cout << "\nSince you can't make up your mind, I'll make it up for you. You're getting it toasted." << std::endl;
			isToasted = true;
			bagelName = "Sliced and Toasted" + bagelName;
		}

		std::cout << "\nWould you like any extras? (yes/no) ";

		std::cin >> itemSelection;

		if (itemSelection == "yes" || itemSelection == "Yes") {
			std::cout << "\nAwesome! Here are your choices:\n1 - Cream Cheese\n2 - Jelly" << std::endl;
			std::cin >> itemSelection;

			if (itemSelection == "1") {
				bagelIngredients.push_back("Cream");
				bagelName = bagelName + " with Cream Cheese";
			} else if (itemSelection == "2") {
				bagelIngredients.push_back("Grape Juice");
				bagelIngredients.push_back("Fruit Pectin");
				bagelName = bagelName + " with Jelly";
			} else {
				std::cout << "\nThat's not a choice. Stop wasting my time and get out of my bakery!" << std::endl;
				exit (EXIT_FAILURE);
			}
		}
	} else if (slicedSelection == "no" || slicedSelection == "No") {
		std::cout << "\nOkay, we won't slice it for you." << std::endl;
	} else {
		std::cout << "\nStop wasting my time and get out of my bakery!" << std::endl;
		exit (EXIT_FAILURE);
	}

	return Bagel(bagelName, 5.99, 5, bagelIngredients);
}

std::string frosting() {
	std::string frostingChoice;

	std::cout << "\nWhat kind of frosting would you like?\n1 - Buttercream\n2 - Whipped Cream\n3 - Cream Cheese" << std::endl;
	std::cin >> frostingChoice;

	if (frostingChoice == "1") {
		return "Buttercream Frosting";
	} else if (frostingChoice == "2") {
		return "Whipped Cream Frosting";
	} else if (frostingChoice == "3") {
		return "Cream Cheese Frosting";
	} else {
		return "No Frosting";
	}
}

void Cake::setDecoration(std::string decorationText) {
	decoration = decorationText;
}

std::string Cake::getDecoration() {
	return decoration;
}

Cake selectCake() {
	std::string chocolateSelection;
	std::string cakeName;
	std::string itemSelection;
	std::string frostedSelection;
	std::vector<std::string> cakeIngredients;

	cakeIngredients.push_back("Flour");
	cakeIngredients.push_back("Sugar");
	cakeIngredients.push_back("Eggs");
	cakeIngredients.push_back("Milk");
	cakeIngredients.push_back("Butter");
	cakeIngredients.push_back("Vanilla");
	cakeIngredients.push_back("Salt");
	cakeIngredients.push_back("Baking Powder");

	std::cout << "Would you like something with chocolate? (yes/no) ";

	std::cin >> chocolateSelection;

	if (chocolateSelection == "yes" || chocolateSelection == "Yes") {
		std::cout << "\nSure thing! Here are your choices:" << std::endl;
		std::cout << "1 - Birthday Cake\n2 - Pound Cake\n3 - Red Velvet" << std::endl;
		std::cin >> itemSelection;
		if (itemSelection == "1") {
			cakeName = "Chocolate Birthday Cake";
			cakeIngredients.push_back("Cocoa Powder");
		} else if (itemSelection == "2") {
			cakeName = "Chocolate Pound Cake";
			cakeIngredients.push_back("Cocoa Powder");
		} else if (itemSelection == "3") {
			cakeName = "Red Velvet Cake";
			cakeIngredients.push_back("Cocoa Powder");
			cakeIngredients.push_back("Vinegar");
			cakeIngredients.push_back("Beets");
		} else {
			std::cout << "\nThat's not a choice. Stop wasting my time and get out of my bakery!" << std::endl;
			exit (EXIT_FAILURE);
		}
	} else if (chocolateSelection == "no" || chocolateSelection == "No") {
		std::cout << "\nSure thing! Here are your choices:" << std::endl;
		std::cout << "1 - Birthday Cake\n2 - Pound Cake" << std::endl;
		std::cin >> itemSelection;
		if (itemSelection == "1") {
			cakeName = "Vanilla Birthday Cake";
		} else if (itemSelection == "2") {
			cakeName = "Vanilla Pound Cake";
		} else {
			std::cout << "\nThat's not a choice. Stop wasting my time and get out of my bakery!" << std::endl;
			exit (EXIT_FAILURE);
		}
	} else {
		std::cout << "\nStop wasting my time and get out of my bakery!" << std::endl;
		exit (EXIT_FAILURE);
	}

	std::cout << "\nWould you like it frosted? (yes/no) ";

	std::cin >> frostedSelection;

	if (frostedSelection == "yes" || frostedSelection == "Yes") {
		cakeName = cakeName + " with " + frosting();
		cakeIngredients.push_back("Cream");
	} else if (frostedSelection == "no" || frostedSelection == "No") {
		std::cout << "\nOkay, we won't frost it for you." << std::endl;
	} else {
		std::cout << "\nStop wasting my time and get out of my bakery!" << std::endl;
		exit (EXIT_FAILURE);
	}

	return Cake(cakeName, 30.99, 60, cakeIngredients);
}

Cookie selectCookie() {
	std::string chocolateSelection;
	std::string cookieName;
	std::string itemSelection;
	std::string frostedSelection;
	std::vector<std::string> cookieIngredients;

	cookieIngredients.push_back("Flour");
	cookieIngredients.push_back("Sugar");
	cookieIngredients.push_back("Eggs");
	cookieIngredients.push_back("Butter");
	cookieIngredients.push_back("Vanilla");
	cookieIngredients.push_back("Salt");

	std::cout << "Would you like something with chocolate? (yes/no) ";

	std::cin >> chocolateSelection;

	if (chocolateSelection == "yes" || chocolateSelection == "Yes") {
		std::cout << "\nSure thing! Here are your choices:" << std::endl;
		std::cout << "1 - Chocolate Chip\n2 - Triple Chocolate" << std::endl;
		std::cin >> itemSelection;
		if (itemSelection == "1") {
			cookieName = "Chocolate Chip Cookie";
			cookieIngredients.push_back("Milk Chocolate Chips");
		} else if (itemSelection == "2") {
			cookieName = "Triple Chocolate Cookie";
			cookieIngredients.push_back("Cocoa Powder");
			cookieIngredients.push_back("Milk Chocolate Chips");
			cookieIngredients.push_back("White Chocolate Chips");
		} else {
			std::cout << "\nThat's not a choice. Stop wasting my time and get out of my bakery!" << std::endl;
			exit (EXIT_FAILURE);
		}
	} else if (chocolateSelection == "no" || chocolateSelection == "No") {
		std::cout << "\nSure thing! Here are your choices:" << std::endl;
		std::cout << "1 - Sugar\n2 - Peanut Butter" << std::endl;
		std::cin >> itemSelection;
		if (itemSelection == "1") {
			cookieName = "Sugar Cookie";
		} else if (itemSelection == "2") {
			cookieName = "Peanut Butter Cookie";
			cookieIngredients.push_back("Peanut Butter");
		} else {
			std::cout << "\nThat's not a choice. Stop wasting my time and get out of my bakery!" << std::endl;
			exit (EXIT_FAILURE);
		}
	} else {
		std::cout << "\nStop wasting my time and get out of my bakery!" << std::endl;
		exit (EXIT_FAILURE);
	}

	std::cout << "\nWould you like it frosted? (yes/no) ";

	std::cin >> frostedSelection;

	if (frostedSelection == "yes" || frostedSelection == "Yes") {
		cookieName = cookieName + " with " + frosting();
		cookieIngredients.push_back("Cream");
	} else if (frostedSelection == "no" || frostedSelection == "No") {
		std::cout << "\nOkay, we won't frost it for you." << std::endl;
	} else {
		std::cout << "\nStop wasting my time and get out of my bakery!" << std::endl;
		exit (EXIT_FAILURE);
	}

	return Cookie(cookieName, 1.99, 5, cookieIngredients);
}