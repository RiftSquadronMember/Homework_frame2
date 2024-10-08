#include <iostream>
#include <windows.h>
#include <random>
#include <ctime>
#include <string>

void ta(std::string text) {
	for (int i = 0; i < text.length(); i++) {
		std::cout << text[i];
		if (text[i] == ',') {
			Sleep(500);
		}
		else if (text[i] == '.') {
			Sleep(700);
		}
		else{ Sleep(5); }
	}
	text.clear();
}





int main() {
	bool process_ended = false;
	int choice = 0;
	do {
		ta("Choose the homework:\n\n1 - Convertor[work in progress]\n2 - [blank]\n3 - [blank]\n0 - Terminate process\n\n>>> ");
		std::cin >> choice;
		system("cls");
	} while (choice < 0 || choice > 3);
	if (choice == 0) {
		return 0;
	}
	else if (choice == 1) {
		bool deal = false;
		double Dollar = 96.75, Euro = 106.19, Yuan = 13.7, Farit = 37, Yen = 0.65, Rouble = 0,
			Volutes[5]{}, amount_to_buy = 0, comission = 0, spent = 0, gain = 0, comission_ate = 0;
		std::string type_o_volute = "blank";

		Volutes[0] = Dollar;
		Volutes[1] = Euro;
		Volutes[2] = Yuan;
		Volutes[3] = Farit;
		Volutes[4] = Yen;


		do {ta("Enter the amount of roubles you want to convert\n\n>>> ");
			std::cin >> Rouble;
			system("cls");} while (Rouble < 0);

			do {
				do {
					ta("What do you want to convert rubles into?\n\n1 - Dollar\n2 - Euro\n3 - Yuan\n4 - Farit\n5 - Yen\n\n>>> ");
					std::cin >> choice;
					system("cls");
					if (choice < 1 || choice > 5) {
						ta("You got out of the list, please, enter the valid value\n\n");
						Sleep(700);
					}
				} while (choice < 1 || choice > 5);
				
				amount_to_buy = Rouble / Volutes[choice - 1];
				comission = amount_to_buy * 0.05;
				if (choice == 1) { type_o_volute = "Dollar"; }
				if (choice == 2) { type_o_volute = "Euro"; }
				if (choice == 3) { type_o_volute = "Yuan"; }
				if (choice == 4) { type_o_volute = "Farit"; }
				if (choice == 5) { type_o_volute = "Yen"; }


				ta("Amount of Roubles you have\t\t- ");
				std::cout << Rouble << std::endl << std::endl;
				ta("Volute selected\t\t\t\t- ");
				std::cout << type_o_volute << std::endl;
				ta("Current cost[in roubles]\t\t- ");
				std::cout << Volutes[choice - 1] << std::endl;
				ta("Amount of volute you can buy[com off]\t- ");
				std::cout << amount_to_buy << std::endl;
				ta("Comission\t\t\t\t- ");
				std::cout << comission << std::endl;
				ta("\nTotal amount of cash\nyou'll get with comission\t\t- ");
				std::cout << amount_to_buy - comission << std::endl;
				ta("\nDeal?\n1 - Confirm\n2 - Decline\n\n>>> ");
				std::cin >> choice;
				system("cls");
				if (choice == 1) {
					ta("Deal confirmed, now you\n");
					while (true) {
						gain += amount_to_buy - comission;
						spent += Rouble;
						comission_ate += comission;
						std::cout << "- Gained " << gain << " " << type_o_volute << "s\n";
						std::cout << "- Spent " << spent << " Roubles\n";
						ta("\n- Comission \"ate\" ");
						std::cout << comission_ate <<" Roubles in total\n\n";
						ta("Would you like to repeat the operation?\n\n1 - yes\n2 - no\n>>> ");
						std::cin >> choice;
						if (choice == 1) {
							system("cls");
							ta("Deal repeated, now you\n");
						}
						else { return 0; }
					}
				}
			} while (process_ended = true);
	}
	else if (choice == 2) {
		return 0;
	}
	else if (choice == 3) {
		return 0;
	}
	return 0;
}