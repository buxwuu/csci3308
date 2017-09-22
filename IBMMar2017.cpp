#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <time.h>
#include <string>
using namespace std;
// can we do all rows first and then all columns? or vice versa? check with 4x4 matrix
// is the 4x4 matrix valuable?
// minimum for 2x2 matrix is 3
// pattern to the minimum marks dependent on matrix size?
// genetic algorithm (how to improve on random evolution?)
// check rows/columns with their given

struct Achtung{
	int value;
	int marks;
};//}

//void ThisIsWhereYouAddThingsToYourPreviouslyAforementionedFuckYouArray(int suckmygoddamneddick){
//}
//T.I.W.Y.A.T.T.Y.P.A.FuckYou.A.
ostream& operator <<(ostream& os, Achtung& as){
	os<<"Achtung: "<<as.value<<" - Mark count: "<<as.marks;
}
//osu streams are best streams	
// no fuck streams
//no fuck you
// no fuck YOU
//NO
//FUCK YOU
//JUMPS FUR DAYS
// ^^ confirmed
//DAYZ is trash

int achtungCalculator(int matrix[][8]){
	int sum1 = 0,sum2 = 0;
	for(int start = 0; start<8; ++start){
		int j=0;
		for (int i=start; j<8;j++){
			if(i<8){
				sum1+=matrix[i][j];
				++i;
			}
			else{
				i=i%8;
				sum1+=matrix[i][j];
				++i;
			}
		}
		sum2*=pow(2,start+5);
	}
	for(int start = 8; start>0 ;--start){
		int j=0;
		for (int i=start; j<8;j++){
			if(i<8){
				sum1+=matrix[i][j];
				++i;
			}
			else{
				i=i%8;
				sum1+=matrix[i][j];
				++i;
			}
		}
		sum2*=pow(2,start+5);
	}
	return sum1-sum2;
}

void darwinIt(int matrix[][8], int marks){
	int mutateNumber; //Number of things to mutate
	int theChosenRow; //rANDAKIN THE CHOSEN ONE
	int theChosenCol;
	if (marks>64){
		cout<<"PLEASE GOD HELP US\n";
                exit(0);
	}
	else if (marks == 64){
		mutateNumber = 63;
	}
	else if (marks<64 && marks>55){
		mutateNumber = 16;
	}
	else if (marks<=55 && marks>46){
		mutateNumber = 8;
	}
	else if (marks<=46 && marks>=38){
		mutateNumber = 4;
	}
	else if (marks<38){
		mutateNumber = 2;
	}
	else{
		cout<<"EXIT LIGHT, ENTER DEBUGGING\n";
	}
	for (int i=0;i<mutateNumber;i++){
		theChosenRow = rand() % 8;
		theChosenCol = rand() % 8;
		matrix[theChosenRow][theChosenCol] = rand() % 3;
	}
        marks = 0;
        for (int i = 0; i < 8; i++){
            for (int j = 0; j < 8; j++){
                if (matrix[i][j] % 3 == 0){
                    marks++;
                }
            }//}
        }
}
//^^^^ colored lobster function
void getInitConfig(int matrix[][8]){
	cout << "Enter initial matrix conflaggirinationly row by row:" << endl;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			matrix[i][j] = getchar() - 48;
		}
	}
}//}

void printMatrix(int matrix[][8], int rows, int columns, int marks){
  // why does this work
  // 1s and 0s
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < columns; j++){
      cout << setw(2) << matrix[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  // print number of marks
  cout << marks << endl << endl;
}

void optimizeRows(int matrix[][8], int rows, int columns){
  int zeroes_count, ones_count, twos_count;
  for (int i = 0; i < rows; i++){
    zeroes_count = ones_count = twos_count = 0;
    for (int j = 0; j < columns; j++){
      if (matrix[i][j] == 0){
        zeroes_count++;
      }
      else if (matrix[i][j] == 1){
        ones_count++;
      }
      else {
        twos_count++;
      }//}
    }
    if (ones_count >= zeroes_count && ones_count >= twos_count){
      for (int j = 0; j < columns; j++){
        matrix[i][j] = (matrix[i][j] + 2) % 3;
      }
    }
    else if (twos_count >= zeroes_count && twos_count >= ones_count){
      for (int j = 0; j < columns; j++){
        matrix[i][j] = (matrix[i][j] + 1) % 3;
      }//}
    }
  }
}

void optimizeColumns(int matrix[][8], int rows, int columns){
  int zeroes_count, ones_count, twos_count;
  for (int i = 0; i < columns; i++){
    zeroes_count = ones_count = twos_count = 0;
    for (int j = 0; j < rows; j++){
      if (matrix[j][i] == 0){
        zeroes_count++;
      }
      else if (matrix[j][i] == 1){
        ones_count++;
      }
      else {
        twos_count++;
      }
    }
    if (ones_count >= zeroes_count && ones_count >= twos_count){
      for (int j = 0; j < rows; j++){
        matrix[j][i] = (matrix[j][i] + 2) % 3;
      }
    }//}
    else if (twos_count >= zeroes_count && twos_count >= ones_count){
      for (int j = 0; j < rows; j++){
        matrix[j][i] = (matrix[j][i] + 1) % 3;
      }
    }
  }
}//}
//fuk u
void optimizeRow(int matrix[][8], int row_num, int columns, bool &changed, int &marks){
  int zeroes_count, ones_count, twos_count;
  zeroes_count = ones_count = twos_count = 0;
  for (int j = 0; j < columns; j++){
    if (matrix[row_num][j] == 0){
      zeroes_count++;
    }
    else if (matrix[row_num][j] == 1){
      ones_count++;
    }
    else {
      twos_count++;
    }//}
  }
  if (ones_count >= zeroes_count && ones_count >= twos_count){
      cout<<"";
    for (int j = 0; j < columns; j++){
      matrix[row_num][j] = (matrix[row_num][j] + 2) % 3;
      changed = true;
    }
    marks = marks + ones_count - zeroes_count;
  }
  else if (twos_count >= zeroes_count && twos_count >= ones_count){
    for (int j = 0; j < columns; j++){
      matrix[row_num][j] = (matrix[row_num][j] + 1) % 3;
      changed = true;
    }
    marks = marks + twos_count - zeroes_count;
  }
}
//maximum overdrive
void optimizeColumn(int matrix[][8], int column_num, int rows, bool &changed, int &marks){
  int zeroes_count, ones_count, twos_count;
  zeroes_count = ones_count = twos_count = 0;
  for (int j = 0; j < rows; j++){
    if (matrix[j][column_num] == 0){
      zeroes_count++;
    }
    else if (matrix[j][column_num] == 1){
      ones_count++;
    }//}
    else {
      twos_count++;
    }
  }
  if (ones_count >= zeroes_count && ones_count >= twos_count){
    for (int j = 0; j < rows; j++){
      matrix[j][column_num] = (matrix[j][column_num] + 2) % 3;
      changed = true;
    }
    marks = marks + ones_count - zeroes_count;
  }//}//}//}
  else if (twos_count >= zeroes_count && twos_count >= ones_count){
    for (int j = 0; j < rows; j++){
      matrix[j][column_num] = (matrix[j][column_num] + 1) % 3;
      changed = true;
    }
    marks = marks + twos_count - zeroes_count;
  }//}
}

int main(int argc, char const *argv[]) {
  int matrix[8][8];
  srand(time(NULL));
  int commLine = 0;
  bool changed = false;
  int marks = 0;
  Achtung a;
  a.value=achtungCalculator(matrix);
  // generates IBM's array configuration; should be used for testing purposes only
  //for (int i = 0; i < 8; i++){
  //  for (int j = 0; j < 8; j++){
  //    matrix[i][j] = ((i + 1) * (j + 1)) % 3;
  //  }
  //}
  // generates an array of all ones; stupid test case
  // for (int i = 0; i < 8; i++){
  //   for (int j = 0; j < 8; j++){
  //     matrix[i][j] = 1;
  //   }
  // }
  //he doesn't mean that it's beautiful just the way that it is
  // get initial array from user
  cout<<argv[1][10]<<endl;
  cout<<"Press 1 to get array from command line\n";
  cin>>commLine;
  if (commLine == 1){
    for (int i = 0; i < 8; i++){
      for (int j = 0; j < 8; j++){
        matrix[i][j] = argv[1][i*8+j]-48;
      }
    }
    goto here;
  }
  getInitConfig(matrix);
  here:;
  // determine initial mark count
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      if (matrix[i][j] % 3 == 0){
        marks++;
      }
    }//}
  }
  // print contents of array for debugging purposes
  printMatrix(matrix, 8, 8, marks);
  while (true){
  	// use machine learning to generate a new configuration to try
        //cout<<"Marks is "<<marks<<endl;
  	darwinIt(matrix, marks);
        //cout<<"EVOLUTION IS A GO\n";
        //cout<<"Marks2 is "<<marks<<endl;
  	// try to break array and raise mark count as much as possible
  	while (true){
            //cout<<"Made it to me!!! :D\n";
            changed = false;
	    for (int j = 0; j < 8; j++){
                optimizeRow(matrix, j, 8, changed, marks);
                printMatrix(matrix,8,8,marks);
                //cout<<"Markie here: "<<marks<<endl;
                optimizeColumn(matrix, j, 8, changed, marks);
                //cout<<"Markie2 here: "<<marks<<endl;
	    }
	    if (!changed || marks > 37){
                cout<<"Breaking\n";
	    	break;
	    }//}
	  }
	// check to see if we've found a solution
	if (marks < 37){
		cout << "SOLUTION FOUND:" << endl;
		printMatrix(matrix, 8, 8, marks);
                break;
		// we can choose to break out of the loop here if we're satisfied with the solution, or continue going to try and find a better solution
		// we can also save the matrix to a file or something here
	}
  }
  // print resulting contents of array once we're done transforming and breaking it
  printMatrix(matrix, 8, 8, marks);
}
//Are shoes feet???????????