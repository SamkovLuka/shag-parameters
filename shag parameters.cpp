#include <iostream>
#include <unordered_set>

using namespace std;

// Домашнє завдання 1
// завдання 1
void uniqueFromA(int* A, int M, int* B, int N) {
    
    int* result = new int[M];
    int resultSize = 0;

   
    for (int i = 0; i < M; i++) {
        bool found = false;
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }
        
        if (!found) {
            bool isUnique = true;
            for (int k = 0; k < resultSize; k++) {
                if (result[k] == A[i]) {
                    isUnique = false;
                    break;
                }
            }
            if (isUnique) {
                result[resultSize++] = A[i];
            }
        }
    }

  
    cout << "Elements of array A that are not in array B: ";
    for (int i = 0; i < resultSize; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    delete[] result;
}


// завдання 2
void uniqueElementsFromBoth(int* A, int M, int* B, int N) {
    int* result = new int[M + N];
    int resultSize = 0;

    for (int i = 0; i < M; i++) {
        bool foundInB = false;
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                foundInB = true;
                break;
            }
        }
        if (!foundInB) {
            bool isUnique = true;
            for (int k = 0; k < resultSize; k++) {
                if (result[k] == A[i]) {
                    isUnique = false;
                    break;
                }
            }
            if (isUnique) {
                result[resultSize++] = A[i];
            }
        }
    }

   

    for (int i = 0; i < N; i++) {
        bool foundInA = false;
        for (int j = 0; j < M; j++) {
            if (B[i] == A[j]) {
                foundInA = true;
                break;
            }
        }
        if (!foundInA) {
            bool isUnique = true;
            for (int k = 0; k < resultSize; k++) {
                if (result[k] == B[i]) {
                    isUnique = false;
                    break;
                }
            }
            if (isUnique) {
                result[resultSize++] = B[i];
            }
        }
    }

   
    cout << "Unique elements from A and B: ";
    for (int i = 0; i < resultSize; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    delete[] result;
}





// домашнє завдання 2
// Завдання 1
int* allocateArray(int size) {
    return new int[size];
}


void initializeArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter element [" << i << "]: ";
        cin >> array[i];
    }
}


void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}


void deleteArray(int* array) {
    delete[] array;
}




int* addElement(int* array, int& size, int element) {
    int* newArray = new int[size + 1];
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    newArray[size] = element;
    size++;
    delete[] array;
    return newArray;
}




int* insertElement(int* array, int& size, int element, int index) {
    if (index < 0 || index > size) {
        cout << "Invalid index" << endl;
        return array;
    }

    int* newArray = new int[size + 1];
    for (int i = 0; i < index; i++) {
        newArray[i] = array[i];
    }
    newArray[index] = element;
    for (int i = index; i < size; i++) {
        newArray[i + 1] = array[i];
    }
    size++;
    delete[] array;
    return newArray;
}




int* deleteElement(int* array, int& size, int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index" << endl;
        return array;
    }

    int* newArray = new int[size - 1];
    for (int i = 0; i < index; i++) {
        newArray[i] = array[i];
    }
    for (int i = index + 1; i < size; i++) {
        newArray[i - 1] = array[i];
    }
    size--;
    delete[] array;
    return newArray;
}

// Домашнє завдання 2
// завдання 2
bool isPrime(int number) {
    if (number < 2) return false;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return false;
    }
    return true;
}




int* removePrimes(int* array, int& size) {
    int newSize = 0;
    for (int i = 0; i < size; i++) {
        if (!isPrime(array[i])) {
            array[newSize++] = array[i];
        }
    }

    int* newArray = new int[newSize];
    for (int i = 0; i < newSize; i++) {
        newArray[i] = array[i];
    }
    delete[] array;
    size = newSize;
    return newArray;
}








// завдання 3
void separateElements(int* array, int size, int*& positives, int& posSize, int*& negatives, int& negSize, int*& zeros, int& zeroSize) {
    posSize = negSize = zeroSize = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] > 0) posSize++;
        else if (array[i] < 0) negSize++;
        else zeroSize++;
    }

    positives = new int[posSize];
    negatives = new int[negSize];
    zeros = new int[zeroSize];

    int posIndex = 0, negIndex = 0, zeroIndex = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] > 0) positives[posIndex++] = array[i];
        else if (array[i] < 0) negatives[negIndex++] = array[i];
        else zeros[zeroIndex++] = array[i];
    }
}








int main() {
    int M, N;
    cout << "Enter the size of array A: ";
    cin >> M;
    cout << "Enter the size of array B: ";
    cin >> N;

    int* A = allocateArray(M);
    int* B = allocateArray(N);

    cout << "Enter the elements of array A: ";
    initializeArray(A, M);

    cout << "Enter the elements of array B: ";
    initializeArray(B, N);



    uniqueFromA(A, M, B, N);



    
    uniqueElementsFromBoth(A, M, B, N);


    deleteArray(A);
    deleteArray(B);

}
