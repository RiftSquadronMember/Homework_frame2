#include <iostream>
#include <windows.h>
#include <vector>
#include <random>
#include <string>
#include <ctime>
#include <chrono>

int date_difference(int day1, int month1, int year1, int day2, int month2, int year2) {
	std::tm date1{};
	date1.tm_year = year1 - 1900;
	date1.tm_mon = month1 - 1;
	date1.tm_mday = day1;
	
	std::tm date2{};
	date2.tm_year = year2 - 1900;
	date2.tm_mon = month2 - 1;
	date2.tm_mday = day2;


	auto point1 = std::chrono::system_clock::from_time_t(std::mktime(&date1));
	auto point2 = std::chrono::system_clock::from_time_t(std::mktime(&date2));
	
	auto difference = std::chrono::duration_cast<std::chrono::hours>(point2 - point1);
	return difference.count() / 24;
}



void task_1(){
	int date1[3], date2[3];
	std::cout << "Enter the first date day\t: ";
	std::cin >> date1[0];
	std::cout << "Enter the first date month\t: ";
	std::cin >> date1[1];
	std::cout << "Enter the first date year\t: ";
	std::cin >> date1[2];
	std::cout << "\n\n=====-----------------===>\n\n";
	std::cout << "Enter the second date day\t: ";
	std::cin >> date2[0];
	std::cout << "Enter the second date month\t: ";
	std::cin >> date2[1];
	std::cout << "Enter the second date year\t: ";
	std::cin >> date2[2];
	system("cls");
	std::cout << "Difference between date ["
		<< date1[0] << "." << date1[1] << "." << date1[2] << "] and date ["
		<< date2[0] << "." << date2[1] << "." << date2[2] << "] is "
		<< date_difference(date1[0], date1[1], date1[2], date2[0], date2[1], date2[2]) << " days\n\n";
}


void task_2() {
	const int array_size = 10;
	float array_numbers[array_size]{1,2,3,4,5,6,7,8,9,10}, value1 = 0;
	std::cout << "Array to solve: [";
	for (int i = 0; i < array_size; i++) {
		std::cout << array_numbers[i];
		value1 += array_numbers[i];
		if (i < array_size - 1) {
			std::cout << ", ";
		}
	}
	std::cout << "]";
	std::cout << "\nTotal sum:\t" << value1;
	value1 = value1 / array_size;
	std::cout << "\nAnswer:\t\t" << value1;
}



void task_3() {
	int* array_size = new int(0), *positive = new int(0), *neutral = new int(0), *negative = new int(0);
	std::cout << "Enter the list size: ";
	std::cin >> *array_size;
	float* dynamic_array = new float[*array_size];
	system("cls");
	for (int i = 0; i < *array_size; i++) {		
		std::cout << " [" << i + 1 << "/" << *array_size << "] := ";
		std::cin >> dynamic_array[i];
		system("cls");
	}
	std::cout << "Array to count: [";
	for (int i = 0; i < *array_size; i++) {
		std::cout << dynamic_array[i];
		if (dynamic_array[i] < 0) { *negative += 1; }
		else if (dynamic_array[i] > 0) { *positive += 1; }
		else if (dynamic_array[i] == 0) { *neutral += 1; }
		if (i < *array_size - 1) {std::cout << ", ";}
	}
	std::cout << "]\n\nPositive numbers: "<< *positive<<"\nNegative numbers: "<<*negative
		<<"\nNeutral numbers: "<<*neutral;

	

}


int main(){
	int task_choice = -1;
	do { system("cls"); 
	std::cout << "Tasks avialable:\n1 - difference between dates\n2 - Mid number\n3 - Positive|zero|negative\nEnter the task number: ";
	std::cin >> task_choice; } while (task_choice < 1 || task_choice > 3);
	system("cls");
	if (task_choice == 1) {
		task_1();
	}
	else if (task_choice == 2) {
		task_2();
	}
	else if (task_choice == 3) {
		task_3();
	}
	std::cout << "\n\n\n";
	
	return 0;
}
