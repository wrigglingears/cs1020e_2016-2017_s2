//=====================================================================
// FILE: findwords.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: Xu Weichen	
// MATRIC NO.  : A0155584W
// NUS EMAIL   : e0031721@u.nus.edu
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

//Horizontal left to right search
bool H_search(string mat [], string word, int R, int C) {
	int word_length = word.size();
	if (word_length > C) {
		return false;
	}
	else {
		for (int i = 0; i < R; i++) {
			if (mat[i].find(word) != string::npos) {
				return true; }
			}
		return false;
	}
}

//Horizontal right to left search
bool H_search_r(string mat [], string word, int R, int C) {
	reverse(word.begin(),word.end());
	return H_search(mat, word, R, C);
}

//Vertical top to bottom search 
bool V_search(string mat [], string word, int R, int C) {
	int word_length = word.size();
	if (word_length > R) {
		return false;
		}
	else {
		for (int i = 0; i < C; i++) {
			string temp;
			for (int j = 0; j < R; j++) {
				temp += mat[j][i];
			}
			if (temp.find(word) != string::npos) {
				return true; }
		}
		return false;
	}
}

//Vertical bottom to top search
bool V_search_r(string mat [], string word, int R, int C) {
	reverse(word.begin(),word.end());
	return V_search(mat, word, R, C);
}
//Left diagonal search, top left to bottom right
bool LD_search(string mat [], string word, int R, int C) {
	int word_length = word.size();
	if (word_length >= sqrt(R*R + C*C)) {
		return false;
	}
	else {
		for (int i = 0; i < C - word_length + 1; i++) {
			string temp;
			for (int j = 0; (j < R) and (j < C - i); j++) {
				temp += mat[j][i + j];
			}
			if (temp.find(word) != string::npos) {
				return true;
			}
		}
		
		for (int i = 1; i < R - word_length + 1; i++) {
			string temp;
			for (int j = 0; (j < C) and (j < R - i) ; j++) {
				temp += mat[i + j][j];
			}
			if (temp.find(word) != string::npos) {
				return true; }
		}		
	return false;
	}
}

// Left diagonal search, bottom right to top left
bool LD_search_r(string mat [], string word, int R, int C) {
	reverse(word.begin(),word.end());
	return LD_search(mat, word, R, C);
}

//Right diagonal search, top right to bottom left
bool RD_search(string mat [], string word, int R, int C) {
	for (int i = 0; i < R; i++) {
		reverse(mat[i].begin(), mat[i].end());
	}
	return LD_search(mat, word, R, C);
}

//Right diagonal search, bottom left to top right
bool RD_search_r(string mat[], string word, int R, int C) {
	reverse(word.begin(), word.end());
	return RD_search(mat, word, R, C);
}

int main()
{
	int R, C;
	cin >> R >> C;
	string mat[R];
	//insert each individual row as a string into a string array of R strings
	for (int i = 0; i < R; i++) {
		cin >> mat[i];
	}
	int N;
	cin >> N;
	string* words = new string[N];
	//insert each word the user is testing into a string array of N elements
	for (int j = 0; j < N; j++) {
		cin >> words[j];
	}
	//if any search comes back to be true, yes is return, else no
	for (int i = 0; i < N; i++) {
		if (H_search(mat, words[i], R, C) || H_search_r(mat, words[i], R, C) || V_search(mat, words[i], R, C) || V_search_r(mat, words[i], R, C) || LD_search(mat, words[i], R, C) || LD_search_r(mat, words[i], R, C) || RD_search(mat, words[i], R, C) || RD_search_r(mat, words[i], R, C)) {
			cout << "YES" << endl;
		} 
		else {
			cout << "NO" << endl;
		}
	}
	
    return 0;
}
