#include <iostream>
#include <fstream>
#include <vector>

int Knapsack(const int V[], const int P[], const int &n, const int &m){

	int **M, S[n], i, j, c = 0, s;
	bool **C;
	
	M = new int*[m+1];
	C = new bool*[m+1];
	
	for(int x = 0; x <= m; x++){
		M[x] = new int[n+1];
		C[x] = new bool[n+1];
		M[x][n] = 0;
		C[x][n] = false;	
	}
	
	for(i = n - 1; i >= 0; i--){

		for(j = 0; j <= m; j++){

			if(j - P[i] >= 0 && M[j - P[i]][i + 1] + V[i] > M[j][i + 1]){
				M[j][i] = M[j - P[i]][i + 1] + V[i];
				C[j][i] = true;
			}

			else{
				M[j][i] = M[j][i+1];
				C[j][i] = false;
			}
		}
	}

	j--;
	s = M[j][0];

	for(i = 0; i < n; i++){

		if (j <= 0)
			break;

		if(C[j][i]){
			S[c] = i;
			c++;
			j -= P[i];
		}

	}

	std::cout << "The solution set is: {";

	for(i = 0; i < c - 1; i++)
		std::cout << S[i] + 1 << ", ";
	std::cout << S[i] + 1 << "}" << std::endl;
	
	std::cout << "Giving a total profit of " << s << std::endl;

	return s;
}

int main(int argc, char *argv[]){
	if(argc > 1){

		std::ifstream file(argv[1]);
		int n, m;

		if(file.is_open()){
			file >> n;
			file >> m;
			int P[n], V[n];

			for(int i = 0; i < n; i++){
				file >> P[i];
				file >> V[i];
			}

			Knapsack(V, P, n, m);
		}	

	}
							
}

