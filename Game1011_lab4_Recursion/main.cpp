#include <ctime>
#include <iostream>
#include <string>

using namespace std;

// Function prototypes

bool isPalindrome(string,int);

void quickSort(int[],int,int); // Quicksort function
int partition(int[], int, int); // Partition index calculator and re-organize the array according to pivot
void swap(int*, int*); // swap integers

string reverseString(string,int);

int main()
{
	srand(time(NULL));
	
	string word;
	int* intArrayPtr;
	int arraySize,menuOpt;

	cout << "___Welcome to the recursive function Circus!___" << endl << endl;

	do
	{
		cout<<"1. Palindrome Check Machine!\n2. Quicksort Algorithm Magic!\n3. Reverse String Show!\n4. Leave the Circus!" << endl << endl;
		cout << "Please Make a Choose: ";
		cin >> menuOpt;
		while(menuOpt!= 1 && menuOpt != 2 && menuOpt != 3 && menuOpt != 4)
		{
			cout << "Invalid Choose! Please enter a 1, 2, 3 or 4!" << endl;
			cin >> menuOpt;
		}

		switch (menuOpt)
		{
		case 1:
			cout << "Please Enter a word to check if it is Palindrome or not!" << endl;
			cin >> word;
			if (isPalindrome(word, 0))
				cout << word<<" is Palindrome!"<<endl<<endl;
			else 
				cout << word<<" is not a Palindrome!"<<endl<<endl;
			
			break;
		case 2:
			cout << "Please enter size of the array so we will randomly generated and sort for you!!!" << endl;
			cin >> arraySize;

			intArrayPtr = new int[arraySize-1];
			for (int i = 0; i < arraySize; ++i)
			{
				intArrayPtr[i] = rand() % 500;
			}

			quickSort(intArrayPtr, 0, arraySize-1);

			for(int i = 0; i<arraySize;i++)
			{
				cout << intArrayPtr[i] << " ";
			}
			cout<<endl << endl;
			break;
		case 3:
			cout << "Please enter a word to reverse it!" << endl;
			cin >> word;
			
			cout<<"Reverse of "<<word<<" is "<< reverseString(word,0)<<endl<<endl;
			break;
		case 4:
			cout << "Good bye!" << endl << endl;
		}
	}
	while (menuOpt != 4);
	return 0;
}

// Palindrome Function
bool isPalindrome(string word, int pos)
{
	if(pos > word.length()/2) // base case
	{
		return true;
	}
	if (word[pos] != word[word.length() - (pos + 1)])
	{
		return false;
	}
	else
		return true && isPalindrome(word, pos + 1);
}

//QuickSort functions
void quickSort(int array[], int low,int high)
{
	if(low>high) // base case;
	{
		return;
	}
	
	// pi is partitioning index, array[p] is at right place
	int pi = partition(array,low,high);

	//Separately sort elements before partition and after partition
	quickSort(array, low, pi - 1);
	quickSort(array,pi + 1,high);	
}


int partition(int array[], int low, int high) // calculate partition index
{
	int pivot = array[high]; // pivot
	int j = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int i = low; i<=high-1;i++)
	{
		//If current element is smaller than the pivot
		if(array[i] < pivot)
		{
			j++; // increment index of smaller element
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[j + 1], &array[high]);
	return (j + 1);
}

void swap(int* a, int* b) // swap two integer value
{
	int t = *a;
	*a = *b;
	*b = t;
}

string reverseString(string word, int pos) // Reverse string chars
{
	if(pos > word.length()/2) //base case
	{
		return word;
	}
	
	char temp = word[pos]; // temporally keep the char
	
	word[pos] = word[word.length() - (pos+1)]; // swap char from the back of the string
	word[word.length() - (pos + 1)] = temp; // take value from temp
	
	return reverseString(word, pos + 1); //recurse again the function
	
}


