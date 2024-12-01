#include <iostream>
#include <vector>



int RecursiveBinarySearch_impl(int arr[], int low, int high, int searchValue) {
	if (low >= high) {
		return -1;
	}
	int mid = (low + high) / 2;
	if (arr[mid] == searchValue) {
		return mid;
	}
	else if(arr[mid] > searchValue) {
		return RecursiveBinarySearch_impl(arr, low, mid - 1, searchValue);
	}
	return RecursiveBinarySearch_impl(arr, mid + 1, high, searchValue);
}

int RecursiveBinarySearch(int arr[], int size, int searchValue) {
	return RecursiveBinarySearch_impl(arr, 0, size - 1, searchValue);

}

int BinarySearch(int array[], int size, int searchValue) {

	int low = 0;
	int high = size - 1;

	int mid = (low + high) / 2;


	while (low < high) {
		if (searchValue == array[mid]) {
			return mid;
		}
		else if (searchValue < array[mid]) {
			high = mid - 1;

		}
		else {
			low = mid + 1;

		}
		mid = (low + high) / 2;
	}
	return -1;

}

int main() {

	std::vector<int> a = { 1, 12, 34, 56, 76, 87, 93, 100, 154, INT_MAX };
	
	int userValue;

	std::cout << "Input the search value: " << std::endl;
	std::cin >> userValue;

	//int result = BinarySearch(a.data(), a.size(), userValue);
	int result = RecursiveBinarySearch(a.data() , a.size(), userValue);

	if (result >= 0) {
		std::cout << "The value " << a[result] << " is found at " << result << std::endl;
	}
	else {
		std::cout << "The " << userValue << " was not found" << std::endl;
	}

}
