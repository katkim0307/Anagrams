// kk4036_hw9_q2.cpp : Test for Anagrams
// 2 strs are anagrams if the letters can be rearranged to form each other.
// e.g. "Eleven plus two" is an anagram of "Twelve plus one"
// Each string contains 1 'v', 3 'e's, 2 'i's, etc.
// Write a program that determines if two strings are anagrams.
// Should not be case sensitive and should disregard any punct/spaces.
//  T(n) = O(n)
// (1) total # of letters (only letters) must match
// (2) count the # of every letter's occurrences (even the unused ones)
// (3) # of letter occurrrences of str1 must match that of str2

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main1();
void makeLowerCase(string &s);
void numOfLettersArr(int arr[]);
void countNumOfLetters(string s, int arr[]);
bool isAnagram1(string s1, string s2);

int main2();		// simpler than main1()
int countLettersInArr(string s, int arr[], int arrSize);
bool isAnagram2(string s1, string s2);

const int NUM_OF_ALPHA = 26;
int main()
{
	main1();
	cout << endl;
	main2();
	return 0;
}

int main1()
{
	string s1, s2;

	cout << "Please enter a line of text 1: " << endl;
	getline(cin, s1);
	cout << "Please enter a line of text 2: " << endl;
	getline(cin, s2);

	if (isAnagram1(s1, s2))
		cout << s1 << " and " << s2 << " are anagrams." << endl;
	else
		cout << s1 << " and " << s2 << " are not anagrams." << endl;

	return 0;
}

//make upper-case letters lower-case
void makeLowerCase(string &s) {
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = tolower(s[i]);
	}
}

//set the frequency of every letter to 0
void numOfLettersArr(int arr[]) {
	for (int i = 0; i < NUM_OF_ALPHA; i++)
		arr[i] = 0;
}

//count the frequency of every letter in s and store it in the array
void countNumOfLetters(string s, int arr[]) {
	for (char c : s)	//for (int i = 0; i < s.size(); i++) { c = s[i]; }
		arr[c - 'a']++;
}

bool isAnagram1(string s1, string s2) {
	int letterCountArr1[NUM_OF_ALPHA], letterCountArr2[NUM_OF_ALPHA];

	makeLowerCase(s1);
	makeLowerCase(s2);

	numOfLettersArr(letterCountArr1);
	numOfLettersArr(letterCountArr2);

	countNumOfLetters(s1, letterCountArr1);
	countNumOfLetters(s2, letterCountArr2);

	for (int i = 0; i < NUM_OF_ALPHA; i++) {
		if (letterCountArr1[i] != letterCountArr2[i])
			return false;
	}
	return true;
}

int main2()
{
	string text1, text2;

	cout << "Enter Text 1: ";
	getline(cin, text1);
	cout << "Enter Text 2: ";
	getline(cin, text2);

	if (isAnagram2(text1, text2))
		cout << text1 << " and " << text2 << " are anagrams." << endl;
	else
		cout << text1 << " and " << text2 << " are not anagrams." << endl;

	return 0;
}

int countLettersInArr(string s, int arr[], int arrSize)
{
	// make lower case
	for (unsigned int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = tolower(s[i]);
	}

	char c;
	int count = 0;
	for (unsigned int i = 0; i < s.length(); i++) {
		c = s[i];
		if (c >= 'a' && c <= 'z') {
			arr[c - 'a']++;
			count++;
		}
	}
	return count;
}

bool isAnagram2(string s1, string s2)
{
	int letterCount1[NUM_OF_ALPHA] = {}, letterCount2[NUM_OF_ALPHA] = {};
	int numLetter1 = countLettersInArr(s1, letterCount1, NUM_OF_ALPHA);
	int numLetter2 = countLettersInArr(s2, letterCount2, NUM_OF_ALPHA);

	if (numLetter1 != numLetter2)
		return false;

	for (int i = 0; i < NUM_OF_ALPHA; i++) {
		if (letterCount1[i] != letterCount2[i])
			return false;
	}

	return true;
}


/*#include <algorithm>
T(n) = O(n)
void sortString(string &s){
	sort(s.begin(), s.end());
}*/