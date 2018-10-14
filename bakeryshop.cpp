#include <iostream>
#include "menu.h"

int main() {
	std::string orderChoice;
	std::string ingredientsChoice;

	std::cout << "What would you like to order today?\n1 - Bread\n2 - Bagel\n3 - Cake\n4 - Cookie" << std::endl;
	std::cin >> orderChoice;

	if (orderChoice == "1") {
		Bread myBread = selectBread();
		myBread.printOrder();

		std::cin >> ingredientsChoice;

		if (ingredientsChoice == "yes" || ingredientsChoice == "Yes") {
			std::cout << "\nThanks for coming in! Here's a list of the ingredients for you to look over." << std::endl;
			myBread.listIngredients(myBread.getIngredients());
		} else if (ingredientsChoice == "no" || ingredientsChoice == "No") {
			std::cout << "\nThanks for coming in! We'll have that right out for you.";
		} else {
			std::cout << "\nI can't really understand you, so... We'll have that right out for you. Thanks for coming in.";
		}
	} else if (orderChoice == "2") {
		Bagel myBagel = selectBagel();
		myBagel.printOrder();

		std::cin >> ingredientsChoice;

		if (ingredientsChoice == "yes" || ingredientsChoice == "Yes") {
			std::cout << "\nThanks for coming in! Here's a list of the ingredients for you to look over." << std::endl;
			myBagel.listIngredients(myBagel.getIngredients());
		} else if (ingredientsChoice == "no" || ingredientsChoice == "No") {
			std::cout << "\nThanks for coming in! We'll have that right out for you.";
		} else {
			std::cout << "\nI can't really understand you, so... We'll have that right out for you. Thanks for coming in.";
		}
	} else if (orderChoice == "3") {
		std::string decoratedSelection;
		std::string decoratedString;
		Cake myCake = selectCake();
		
		std::cout << "\nWould you like it decorated? (yes/no) ";

		std::cin >> decoratedSelection;

		if (decoratedSelection == "yes" || decoratedSelection == "Yes") {
			std::cout << "\nWhat would you like your cake to say?" << std::endl;

			std::cin.clear();
			std::cin.sync();
			std::getline(std::cin, decoratedString);

			myCake.setDecoration(decoratedString);

			std::cout << "\nSo this is what we're going to write on your cake:" << std::endl;
			std::cout << myCake.getDecoration() << std::endl;			
		} else if (decoratedSelection == "no" || decoratedSelection == "No") {
			std::cout << "\nOkay, we won't decorate it for you." << std::endl;
		} else {
			std::cout << "\nStop wasting my time and get out of my bakery!" << std::endl;
			exit (EXIT_FAILURE);
		}

		myCake.printOrder();

		std::cin >> ingredientsChoice;

		if (ingredientsChoice == "yes" || ingredientsChoice == "Yes") {
			std::cout << "\nThanks for coming in! Here's a list of the ingredients for you to look over." << std::endl;
			myCake.listIngredients(myCake.getIngredients());
		} else if (ingredientsChoice == "no" || ingredientsChoice == "No") {
			std::cout << "\nThanks for coming in! We'll have that right out for you.";
		} else {
			std::cout << "\nI can't really understand you, so... We'll have that right out for you. Thanks for coming in.";
		}
	} else if (orderChoice == "4") {
		Cookie myCookie = selectCookie();
		myCookie.printOrder();

		std::cin >> ingredientsChoice;

		if (ingredientsChoice == "yes" || ingredientsChoice == "Yes") {
			std::cout << "\nThanks for coming in! Here's a list of the ingredients for you to look over." << std::endl;
			myCookie.listIngredients(myCookie.getIngredients());
		} else if (ingredientsChoice == "no" || ingredientsChoice == "No") {
			std::cout << "\nThanks for coming in! We'll have that right out for you.";
		} else {
			std::cout << "\nI can't really understand you, so... We'll have that right out for you. Thanks for coming in.";
		}
	} else {
		std::cout << "Stop wasting my time and get out!" << std::endl;
	}
	
	return 0;
}