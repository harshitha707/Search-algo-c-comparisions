#include <iostream>
#include <vector>

int RecursiveBinarySearch(int array[], int low, int high, int searchValue) {

	if (low >= high) {
		return -1;
	}

	int mid = low + (high - low) / 2;

	if (searchValue == array[mid]) {
		return mid;
	}
	else if (searchValue >= array[mid]) {
		return RecursiveBinarySearch(array, mid + 1, high, searchValue);
	}
	else {
		return RecursiveBinarySearch(array, low, mid - 1, searchValue);
	}
}
//int BinarySearch(int array[], int size, int searchValue) {
	//return RecursiveBinarySearch(array, 0, size - 1, searchValue);
//}

int ExponentialSearch(int array[], int size, int searchValue) {

	int range = 1;
	
	while (true) {
		int index = std::min(size, range) - 1;
		int resu = array[index];
		if (searchValue == resu) {
			return index;
		}
		else if (searchValue < resu) {
			return RecursiveBinarySearch(array, range / 2, std::min(size, range), searchValue);
		}
		else if (range > size){
			return -1;
		}
		else {
			range *= 2;
		}
	}
}



int main()
{
	std::vector<int> a = { 1, 4, 7, 12, 23, 34, 53, 46, 49, 52, 66, 69, 72, 78, 99 };

	int userInput;

	std::cout << "Please provide the number you want to find: " << std::endl;
	std::cin >> userInput;

	int result = ExponentialSearch(a.data(), a.size(), userInput);

	if (result >= 0) {
		std::cout << "The number " << a[result] << " is found at " << result << std::endl;
	}
	else {
		std::cout << "Number is not found";
	}
}




