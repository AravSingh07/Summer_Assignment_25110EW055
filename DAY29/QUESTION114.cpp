#include <iostream>

using namespace std;

// Maximum capacity allocation for the static array
const int MAX_SIZE = 100;

// Function prototypes for modularity
void displayArray(const int arr[], int currentSize);
void insertElement(int arr[], int& currentSize);
void deleteElement(int arr[], int& currentSize);
int searchElement(const int arr[], int currentSize, int target);
void bubbleSort(int arr[], int currentSize);

int main() {
    int arr[MAX_SIZE];
    int currentSize = 0;
    int choice;

    // Initial configuration
    cout << "Enter the initial number of elements (Max " << MAX_SIZE << "): ";
    cin >> currentSize;

    if (currentSize > MAX_SIZE || currentSize < 0) {
        cout << "Invalid size! Resetting array size to 0.\n";
        currentSize = 0;
    } else if (currentSize > 0) {
        cout << "Enter " << currentSize << " elements:\n";
        for (int i = 0; i < currentSize; i++) {
            cin >> arr[i];
        }
    }

    // Infinite menu execution loop until manual termination
    do {
        cout << "\n===============================\n";
        cout << "   ARRAY OPERATIONS SYSTEM     \n";
        cout << "===============================\n";
        cout << "1. Display Array\n";
        cout << "2. Insert Element\n";
        cout << "3. Delete Element by Index\n";
        cout << "4. Search Element (Linear Search)\n";
        cout << "5. Sort Array (Bubble Sort)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayArray(arr, currentSize);
                break;
            case 2:
                insertElement(arr, currentSize);
                break;
            case 3:
                deleteElement(arr, currentSize);
                break;
            case 4: {
                if (currentSize == 0) {
                    cout << "Array is empty! Nothing to search.\n";
                    break;
                }
                int target;
                cout << "Enter the element to search for: ";
                cin >> target;
                int index = searchElement(arr, currentSize, target);
                if (index != -1) {
                    cout << "Element found at index: " << index << "\n";
                } else {
                    cout << "Element not found in the array.\n";
                }
                break;
            }
            case 5:
                bubbleSort(arr, currentSize);
                break;
            case 6:
                cout << "Exiting system. Goodbye!\n";
                break;
            default:
                cout << "Invalid selection! Please enter a number between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}

// 1. Array Traversal & Visualization
void displayArray(const int arr[], int currentSize) {
    if (currentSize == 0) {
        cout << "The array is currently empty.\n";
        return;
    }
    cout << "Current Array Elements: ";
    for (int i = 0; i < currentSize; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// 2. Element Insertion with Shift Dynamics
void insertElement(int arr[], int& currentSize) {
    if (currentSize >= MAX_SIZE) {
        cout << "Error: Array Overflow! Cannot insert more elements.\n";
        return;
    }

    int element, position;
    cout << "Enter the element to insert: ";
    cin >> element;
    cout << "Enter the index position (0 to " << currentSize << "): ";
    cin >> position;

    // Bounds checking
    if (position < 0 || position > currentSize) {
        cout << "Invalid index position execution aborted.\n";
        return;
    }

    // Shift data chunks rightward to preserve sequential positions
    for (int i = currentSize; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    currentSize++; // Update pointer state
    cout << "Element inserted successfully!\n";
}

// 3. Index Deletion with Collapse Dynamics
void deleteElement(int arr[], int& currentSize) {
    if (currentSize == 0) {
        cout << "Error: Array Underflow! No items exist to delete.\n";
        return;
    }

    int position;
    cout << "Enter index position to delete (0 to " << currentSize - 1 << "): ";
    cin >> position;

    // Bounds validation
    if (position < 0 || position >= currentSize) {
        cout << "Invalid index! Operation aborted.\n";
        return;
    }

    // Collapse remaining elements leftward over the targeted deletion vector
    for (int i = position; i < currentSize - 1; i++) {
        arr[i] = arr[i + 1];
    }

    currentSize--; // Reduce memory boundaries
    cout << "Element deleted successfully!\n";
}

// 4. Linear Search Lookup Strategy
int searchElement(const int arr[], int currentSize, int target) {
    for (int i = 0; i < currentSize; i++) {
        if (arr[i] == target) {
            return i; // Target match discovered
        }
    }
    return -1; // Target missing element failure flag
}

// 5. Array In-Place Bubble Sorting Algorithm
void bubbleSort(int arr[], int currentSize) {
    if (currentSize <= 1) {
        cout << "Array already optimal or trivial to sort.\n";
        return;
    }

    for (int i = 0; i < currentSize - 1; i++) {
        bool swapped = false; // Flag to trace early optimization states
        for (int j = 0; j < currentSize - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Perform value swap mutation
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // Break early if array becomes sorted prematurely
        if (!swapped) break;
    }
    cout << "Array sorted ascendingly via bubble sort.\n";
}
