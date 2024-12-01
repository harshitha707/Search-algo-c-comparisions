#include <iostream> 
#include <vector>


int linearSearch_cpp(const std::vector<int>& arr, int searchValue) {
	for (int i = 0; i < arr.size(); ++i) {
		if (searchValue == arr.at(i)) {
			return i;
		}
	}
	return -1;
}

int linearSearch_c(int array[], int size, int searchValue) {
	for (int i = 0; i < size; ++i) {
		if (searchValue == array[i]) {
			return i;
		}
	}
	return -1;
}

int main() {

	std::vector<int> arr{ 100, 4, 22, INT_MAX, 7, 3 };
	int userValue;

	std::cout << "Enter the value: " << std::endl;
	std::cin >> userValue;

	int result = linearSearch_cpp(arr, userValue);
	int result = linearSearch_c(arr.data(), arr.size(), userValue);

	if (result >= 0) {
		std::cout << "the value is found at " << result << " position in the array" << std::endl;
	}
	else {
		std::cout << "the value is not found" << std::endl;
	}
	

}
