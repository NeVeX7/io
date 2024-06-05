#include <bits/stdc++.h> 
using namespace std; 

void towerOfHanoi(int n, char ini, char fin, char extra) 
{ 
	if (n == 0) { 
		return; 
	} 
	towerOfHanoi(n - 1, ini, extra, fin); 
	cout << "Move disk " << n << " from rod " << ini << " to " << fin << endl; 
	towerOfHanoi(n - 1, extra, fin, ini); 
} 

int main() 
{ 
	int N = 3; 
	towerOfHanoi(N, 'A', 'C', 'B'); 
	return 0; 
} 
