#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Matrix{
    float **Mat;  	                                 // Pointer of 2D Array
	int Row , Col;
public:	
	Matrix():Row(2),Col(2){               // Default Constructor Set The Size of Rows and Column = 2
	Mat = new float *[Row];        // Create The Pointer of 2D Array
	for(int i = 0; i < Row; i++)
      Mat[i] = new float[Col];

	for(int i = 0; i < Row; i++)      // Set All Elements Equal = 0
		for(int j = 0; j < Col; j++)
		Mat[i][j] = 0;
	}
	// Constructor with Parameters to Get Size of Rows and Columns
   	Matrix(int row, int col):Row(row),Col(col){
	Mat = new float *[Row]; // Create The Pointer of 2D Array
	for(int i = 0; i < Row; i++)
      Mat[i] = new float[Col];

	for(int i = 0; i < Row; i++)                    // Set All Elements Equal = 0
		for(int j = 0; j < Col; j++)
		Mat[i][j] = 0;
	}
	// Copy Constructor with Object
	Matrix(const Matrix &M):Row(M.Row), Col(M.Col){
	Mat = new float *[M.Row];
	for(int i = 0; i < M.Row; i++)
      Mat[i] = new float[M.Col];

	for(int i = 0; i < M.Row; i++)
		for(int j = 0; j < M.Col; j++)
		Mat[i][j] = M.Mat[i][j];
	}
	// Copy Constructor with Number
	Matrix(const float N):Row(2),Col(2){
	Mat = new float *[Row];
	for(int i = 0; i < Row; i++)
      Mat[i] = new float[Col];

	for(int i = 0; i < Row; i++)
		for(int j = 0; j < Col; j++)
		Mat[i][j] = N; // Set All Elements Equal = N
	}
	//  +|---[The Prototype of Functions]---|+

	friend int Determent(Matrix &, int); // The Determent of a Matrix Prototype
	friend int Tra(Matrix &M); // Trace Prototype to Get The Sum of Main Diagram
	friend void Triangle_Area();
	friend void Rectangular_Area();
	friend Matrix Transpose(Matrix &M);

	//  +|---[The Prototype of Operator Overloading]---|+

    // +
	Matrix operator +(Matrix &); // M3 = M1 + M2
	Matrix operator +(float);// M3 = M1 + N
	friend Matrix operator +(float, Matrix &);// M3 = N + M1
	// +=
	Matrix &operator +=(Matrix &);// M3 += M2
	Matrix &operator +=(float); // M3 += N
	// -
	Matrix operator -(Matrix &); // M3 = M1 - M2
	Matrix operator -(float);// M3 = M1 - N
	friend Matrix operator -(float, Matrix &);// M3 = N - M1
	// -=
	Matrix &operator -=(Matrix &);// M3 -= M2
	Matrix &operator -=(float); // M3 -= N
	// ++
    Matrix operator ++(int); // M++
    Matrix operator ++(); // ++M
    //--
    Matrix operator --(int); // M--
    Matrix operator --(); // --M
    // /
    Matrix operator /(float); // M3 = M2 / N
    friend Matrix operator /(float, Matrix &);               // M3 = N / M2
    // /=
    Matrix &operator /=(float); // M3 /= N
    // *
	Matrix operator *(Matrix &); // M3 = M1 * M2
	Matrix operator *(float);// M3 = M1 * N
	friend Matrix operator *(float, Matrix &);// M3 = N * M1
	// *=
	Matrix &operator *=(Matrix &);// M3 -= M2
	Matrix &operator *=(float); // M3 -= N
    // =
    Matrix &operator =(const float);  // M = N
	Matrix &operator =(const Matrix &); // M1 = M2
	// Transpose
	Matrix operator ~(); // M1 = ~M
	// cin & cout
	friend istream &operator >>(istream &, const Matrix &); // cin >> M
	friend ostream &operator <<(ostream &, const Matrix &);// cout << M

	~Matrix(){                         // Destructor to Delete The Pointers
 		for(int i = 0; i < Row; i++)
			delete[] Mat[i];
		delete[] Mat;
   	}
};              // End of Class

	//  +|---[The Body of Functions]---|+

int Determent(Matrix &M, int Size){ // The Determent of a Matrix Function

	if(M.Row == M.Col){
	if( Size == 1) return M.Mat[0][0];

long long Det = 0;                          // To Sum The Determent
Matrix SubMat(Size-1,Size-1);  // Sub Matrix if The Main Matrix = [3][3] So The SubMat = [2][2]

for(int Co = 0; Co < Size; Co++){                // Co is The Column for First Row [0,Co][0,Co][0,Co]
	int i = 0;                                                   // i are The Row For The SubMat
           for(int R = 1; R < Size; R++){        // R is The First & Second
              int j = 0;                                 // j are The Column For The SubMat
	for(int C = 0; C < Size; C++){              // C is Col for First & Second Row
	       if( C == Co) continue;          // Because the Element in Co will Delete its Column & Row
                 SubMat.Mat[i][j] = M.Mat[R][C];             // To Create The SubMatrix
				j++;                                       // Plus The Column of The SubMat
				}
			i++;                                               // Plus The Row of The SubMat
		}
	int sign = (Co % 2 == 0)? 1 : -1;                     // To Show The Operator plus or minus ?
	Det += sign * M.Mat[0][Co] * (Determent(SubMat, Size-1));                                                                                    
                                                                                        // To Find The Determent for The SubMatrix
	}                  // Just First Row
	return Det;
	} else{
	cout <<"\n\t ! -[Error : \"The Row & The Column of this Matrix \"Must Be Equal\" [Square Matrix] \"]- ! \n";
	exit(0);
	}
}
// Trace Function to Get The Sum of Main Diagram
int Tra(Matrix &M){
	if(M.Col == M.Row){
		int Tra = 0;
		for(int i = 0; i < M.Row; i++)
			for(int j = 0; j < M.Col; j++)
				if(i == j)
				Tra += M.Mat[i][j];

	return Tra;
	}
	else{
	cout <<"\n\t ! -[Error : \"The Row & The Column of this Matrix \"Must Be Equal\" [Square Matrix] \"]- ! \n";
	exit(0);
	}
}
Matrix Transpose(Matrix &M){
	Matrix M1(M.Col,M.Row);
	for(int i = 0; i < M1.Row; i++)
		for (int j = 0; j < M1.Col;j++)
			M1.Mat[i][j] = M.Mat[j][i];
	return M1;
}
void Triangle_Area(){
    Matrix M(3,3);
    M = 1;
    cout <<"\n\tEnter The Coordinates Of The First  Point: ";
		cin >> M.Mat[0][0] >> M.Mat[0][1];

    cout <<"\n\tEnter The Coordinates Of The Second Point: ";
		cin >> M.Mat[1][0] >> M.Mat[1][1];

    cout <<"\n\tEnter The Coordinates Of The Third  Point: ";
		cin >> M.Mat[2][0] >> M.Mat[2][1];

	cout<<"\n\tThe Matrix Of The Triangle Is: ";
		cout << M;

	cout<<"\n\tThe Area Of The Triangle Is: "<< abs(0.5*Determent(M,3)) << endl;
}
void Rectangular_Area(){
	Matrix M(2,4);
	cout <<"\n\tEnter The Coordinates Of The First  Point: ";
	cin >> M.Mat[0][0] >> M.Mat[1][0];
	cout <<"\n\tEnter The Coordinates Of The Second Point: ";
	cin >> M.Mat[0][1] >> M.Mat[1][1] ;
	cout <<"\n\tEnter The Coordinates Of The Third  Point: ";
	cin >> M.Mat[0][2] >> M.Mat[1][2] ;
	cout <<"\n\tEnter The Coordinates Of The Forth  Point: ";
	cin >> M.Mat[0][3] >> M.Mat[1][3];

	int Width,Hieght;
	int X = pow(int(M.Mat[0][0]-M.Mat[0][1]),2)+pow(int(M.Mat[1][0]-M.Mat[1][1]),2);
	int Y = pow(int(M.Mat[0][2]-M.Mat[0][3]),2)+pow(int(M.Mat[1][2]-M.Mat[1][3]),2);
	if(sqrt(X)==sqrt(Y)){
		cout<<"\n\n\tThe Rectangular Matrix Is :\n\n";
		cout<< M;
		Width=sqrt(X);
		Hieght=sqrt(pow(int(M.Mat[0][1]-M.Mat[0][2]),2)+pow(int(M.Mat[1][1]-M.Mat[1][2]),2));
		cout<<"\n\n\tThe Area Of The Rectangular = "<< Width*Hieght << endl;
	}
	else{
		cout<<"\n\t! -[Error : \"The Coordinates Doesn't Make A Rectangular\"]- ! ";
		exit(0);
	}
}
	//  +|---[The Body of Operator Overloading]---|+
   //  Operator +
Matrix Matrix::operator +(Matrix &M){   // M3 = M1 + M2
	if( Row == M.Row && Col == M.Col){
	Matrix Sum(Row,Col);
    for(int r = 0; r < Row; r++)
        for(int c = 0; c < Col; c++)
            Sum.Mat[r][c] = Mat[r][c] + M.Mat[r][c];

    return Sum;
	}else {
	cout << "\n\t ! -[Error : \"The Size of The First Matrix \"NOT Equal\" The Size of The Second Matrix\"]- ! \n";
	exit(0);
	}
}
Matrix Matrix::operator +(float N){ // M3 = M1 + N
	Matrix Sum(Row,Col);
    for(int r = 0; r < Row; r++)
        for(int c = 0; c < Col; c++)
            Sum.Mat[r][c] = Mat[r][c] + N;

    return Sum;
}
Matrix operator +(float N, Matrix &M){ // M3 = N + M1
	Matrix Sum(M.Row,M.Col);
    for(int r = 0; r < M.Row; r++)
        for(int c = 0; c < M.Col; c++)
            Sum.Mat[r][c] = N + M.Mat[r][c];

    return Sum;
}
//  Operator +=
Matrix &Matrix::operator +=(Matrix &M){ // M3 += M2
	if( Row == M.Row && Col == M.Col){
		*this = *this + M;

	return *this;
	} else {
		cout << "\n\t ! -[Error : \"The Size of The First Matrix \"NOT Equal\" The Size of The Second Matrix\"]- ! \n";
		exit(0);
	}
}
Matrix &Matrix::operator +=(float N){ // M3 += M2
		*this = *this + N;
	return *this;
}
//  Operator -=
Matrix &Matrix::operator -=(Matrix &M){ // M3 -= M2
	if( Row == M.Row && Col == M.Col){
		*this = *this - M;

	return *this;
	} else {
		cout << "\n\t ! -[Error : \"The Size of The First Matrix \"NOT Equal\" The Size of The Second Matrix\"]- ! \n";
		exit(0);
	}
}
Matrix &Matrix::operator -=(float N){ // M3 -= M2
 		*this = *this - N;

	return *this;
}
//  Operator -
Matrix Matrix::operator -(Matrix &M){   // M3 = M1 - M2
	if( Row == M.Row && Col == M.Col){
	Matrix Minus(Row,Col);
    for(int r = 0; r < Row; r++)
        for(int c = 0; c < Col; c++)
            Minus.Mat[r][c] = Mat[r][c] - M.Mat[r][c];

    return Minus;
	} else {
		cout << "\n\t ! -[Error : \"The Size of The First Matrix \"NOT Equal\" The Size of The Second Matrix\"]- ! \n";
		exit(0);
	}
}
Matrix Matrix::operator -(float N){ // M3 = M1 - N
	Matrix Minus(Row,Col);
    for(int r = 0; r < Row; r++)
        for(int c = 0; c < Col; c++)
            Minus.Mat[r][c] = Mat[r][c] - N;

	return Minus;
}
Matrix operator -(float N, Matrix &M){ // M3 = N - M1
	Matrix Minus(M.Row,M.Col);
    for(int r = 0; r < M.Row; r++)
        for(int c = 0; c < M.Col; c++)
            Minus.Mat[r][c] = N - M.Mat[r][c];

    return Minus;
}
// Operator /
Matrix Matrix::operator /(float N){
	Matrix M3(Row,Col);
	for(int i = 0; i < Row; i++)
		for(int j = 0; j < Col; j++)
			M3.Mat[i][j] = Mat[i][j] / N;

	return M3;
}
Matrix operator /(float N,Matrix &M){
	Matrix M3(M.Row,M.Col);
	for(int i = 0; i < M.Row; i++)
		for (int j = 0; j < M.Col; j++)
			M3.Mat[i][j] = N / M.Mat[i][j];

	return M3;
}
//  Operator /=
Matrix &Matrix::operator /=(float N){
		*this = *this / N;

	return *this;
}
//  Operator *
Matrix Matrix::operator *(Matrix &M){   //  M1  *  M2  = M3
	if( Col == M.Row){             // Ex   3*2    2*1    3*1
	Matrix Mult(Row,M.Col);           //   1 2     7      x
    for(int r = 0; r < Row; r++)      //   3 4     8      y
        for(int c = 0; c < Col; c++)  //   5 6            z
			for(int k = 0; k < Row; k++)
            Mult.Mat[r][c] += Mat[r][k] * M.Mat[k][c];

    return Mult;
	} else {
		cout << "\n\t ! -[Error : \"The Column of The First Matrix \"Must Equal\" The Row of The Second Matrix\"]- ! \n";
		exit(0);
	}
}
Matrix Matrix::operator *(float N){ // M3 = M1 * N
	Matrix Sum(Row,Col);
    for(int r = 0; r < Row; r++)
        for(int c = 0; c < Col; c++)
            Sum.Mat[r][c] = Mat[r][c] * N;

    return Sum;
}
Matrix operator *(float N, Matrix &M){ // M3 = N * M1
	Matrix Sum(M.Row,M.Col);
    for(int r = 0; r < M.Row; r++)
        for(int c = 0; c < M.Col; c++)
            Sum.Mat[r][c] = N * M.Mat[r][c];
    return Sum;
}
//  Operator *=
Matrix &Matrix::operator *=(Matrix &M){ // M3 *= M2
	if( Row == M.Row && Col == M.Col){
		*this = *this * M;

    return *this;
	} else {
		cout << "\n\t ! -[Error : \"The Column of The First Matrix \"Must Equal\" The Row of The Second Matrix\"]- ! \n";
		exit(0);
	}
}
Matrix &Matrix::operator *=(float N){ // M3 *= M2
		*this = *this * N;

	return *this;
}
// operator =
Matrix &Matrix::operator =(const float N){
	for(int i = 0; i < Row; i++)
		for(int j = 0; j < Col; j++)
		Mat[i][j] = N; // Set All Elements Equal = N

	return *this;
}
Matrix &Matrix::operator =(const Matrix &M){ // M1 = M2
	this->~Matrix();
	Row = M.Row, Col = M.Col;

	Mat = new float *[Row]; // Create The Pointer of 2D Array
	for(int i = 0; i < Row; i++)
      Mat[i] = new float[Col];

	for(int i = 0; i < M.Row; i++)
		for(int j = 0; j < M.Col; j++)
		Mat[i][j] = M.Mat[i][j];

	return *this;}
// New Operator for Transpose  M1 = ~M
Matrix Matrix::operator ~(){          // Ex   Mat[Row][Col]  M.Mat[Col][Row]
	Matrix M(Col,Row);                //         2*3              3*2
	for(int i = 0; i < M.Row; i++)    //        1 2 3             1 4
		for (int j = 0; j < M.Col;j++)//        4 5 6             2 5
			M.Mat[i][j] = Mat[j][i];  //                          3 6

	return M;
}
// Operator ++
Matrix Matrix::operator ++(int){ // M++
	Matrix M(Row,Col);
	M = *this;
		*this = *this + 1;

	return M;
}
Matrix Matrix::operator ++(){ // ++M
		*this = *this + 1;

	return *this;
}
// Operator--
Matrix Matrix::operator --(int){ // M--
	Matrix M(Row,Col);
	M = *this;
		*this = *this - 1;

	return M;
}
Matrix Matrix::operator --(){ // --M
		*this = *this - 1;

	return *this;
}
//  Operator cin & cout
istream &operator >>(istream &cin,const Matrix &M){
	cout <<"\n\tEnter The Elements of The Matrix ["<< M.Row <<"]["<< M.Col <<"] :\n";
	for(int i = 0; i < M.Row; i++){
		for(int j = 0; j < M.Col; j++){
			cout <<"\t\t\t" ;
			cin >> M.Mat[i][j];
		}
		cout <<"\n";
	}
    return cin;
}
ostream &operator <<(ostream &cout,const Matrix &M){
	cout <<"\n\t";
	for(int i = 0; i < M.Row; i++){
		for(int j = 0; j < M.Col; j++){
			cout <<'\t' ;
			cout << M.Mat[i][j];
		}
		cout <<"\n\t";
	} 
     cout <<'\n';
	return cout;
}

int main(){

   int Num;
   do{
    Num = 0;
	system("cls");

        //        +|---[The Main Menu of The Matrix Project]---|+
    cout << "\n\t\t\t+|---[The Main Menu of The Matrix Project]---|+\n" << endl
             << "\t+ Get The Operators About Matrices\t\t>>> Enter: 1\n\t"
	        << "____________________________________________________________" << endl
             << "\t+ Get The Functions About Matrices\t\t>>> Enter: 2\n\t"
	        << "____________________________________________________________" << endl
	        << "\t+ Get The Area of Triangle With Matrix Program\t>>> Enter: 3\n\t"
	        << "____________________________________________________________" << endl
	        << "\t+ Get The Area of Rectangle With Matrix Program\t>>> Enter: 4\n\t"
	        << "____________________________________________________________" << endl
             << "\n\t- To Exit >>> Enter: 0" << endl;
    cout <<"\n\t Enter A Number: ";
            cin >> Num;

    if(Num == 1){		// Start Loop of The Operators About Matrices
		int Numo = 0;
		 do{
		Numo = 0;
		system("cls");

			//        +|---[The Menu of The Operators About Matrices]---|+
	cout << "\n\t\t\t+|---[The Menu of The Operators About Matrices]---|+\n" << endl
              << "\t+ To Sum Many Matrices as You Want \t\t>>> Enter: 1\n\t"
	         << "____________________________________________________________" << endl
	         << "\t+ To Minus Many Matrices as You Want\t\t>>> Enter: 2\n\t"
	         << "____________________________________________________________" << endl
             << "\t+ To Multiply Many Square Matrices as You Want\t>>> Enter: 3\n\t"
	        << "____________________________________________________________" << endl
             << "\n\t- To Back To The Main Menu >>> Enter: 0" << endl;
	
cout <<"\n\t Enter A Number: ";
		cin >> Numo;

				  //        +|---[Sum Many Matrices]---|+
	if(Numo == 1){
	system("cls");
	int Numb, rsize, csize;
	
    cout << "\n\t\t\t+|---[Sum Many Matrices]---|+\n" << endl
	         << "\n\tEnter The Number of Matrices You Want To Sum : ";
		   cin >> Numb;
	cout << "\n\tEnter The [Row] and [Column] Size of Matrices : ";
		    cin >> rsize >> csize;

	Matrix M(rsize,csize);
	Matrix Sum(rsize,csize);
	for(int i = 0; i < Numb; i++){
	cout << "\n\tMatrix Number : " << i+1;
		cin >> M;
		Sum += M;
	}
	system("cls");
	cout << "\n\t The Sum :" << Sum;

    cout  << "\n\t+ To Back To Menu of Programming Enter : ANY NUMBER"
              << "\n\t- To Back To The Main Menu >>> Enter: 0" << endl
              <<"\n\t Enter A Number: ";
                       cin >> Numo;
	 }
	else if(Numo == 2){//   +|---[Minus Many Matrices]---|+
	system("cls");
	int Numb, rsize, csize;
	
     cout << "\n\t\t\t+|---[Minus Many Matrices]---|+\n" << endl
	         << "\n\tEnter The Number of Matrices You Want To Minus : ";
		      cin >> Numb;
	cout << "\n\tEnter The [Row] and [Column] Size of Matrices : ";
		      cin >> rsize >> csize;

	Matrix M(rsize,csize);
	Matrix Minus(rsize,csize);
	cout << "\n\tMatrix Number : " << 1;
	cin>>M;            	Minus=M;
	for (int i = 1; i < Numb; i++){
	            cout << "\n\tMatrix Number : " << i+1;
		cin >> M;
		Minus -= M;
	}
	system("cls");
	cout << "\n\t The Minus :" << Minus;
     cout << "\n\t+ To Back To Menu of Programming Enter : ANY NUMBER"
              << "\n\t- To Back To xThe Main Menu >>> Enter: 0" << endl
              <<"\n\t Enter A Number: ";
                       cin >> Numo;
	 }
     else if(Numo == 3){               //      +|---[Multiply Many Square Matrices]---|+
	system("cls");
	int Numb, ssize;
	cout << "\n\t\t\t+|---[Multiply Many Square Matrices]---|+\n" << endl
	         << "\n\tEnter The Number of Square Matrices You Want To Multiply : ";
			cin >> Numb;
	cout << "\n\tEnter The Size of Square Matrices : ";
		cin >> ssize;
	Matrix M(ssize,ssize);
	Matrix Mult(ssize,ssize);
	cout << "\n\tMatrix Number : " << 1;
	cin>>M;    Mult=M;
	for(int i = 1; i < Numb; i++){
     	cout << "\n\tMatrix Number : " << i+1;
		cin >> M;
		Mult *= M;
	}
	system("cls");
	cout << "\n\t The Mult :" << Mult;
     cout << "\n\t+ To Back To Menu of Programming Enter : ANY NUMBER"
              << "\n\t- To Back To The Main Menu >>> Enter: 0" << endl
              <<"\n\t Enter A Number: ";
                     cin >> Numo;
    }
    } 
    while(Numo != 0); // End Loop of The Operators About Matrices
    }
    else if(Num == 2){		// Start Loop of The Functions About Matrices
	system("cls");
		int Numf = 0;
      	do{
		Numf = 0;
		system("cls");

			//        +|---[The Menu of The Functions About Matrices]---|+
	cout << "\n\t\t\t+|---[The Menu of The Functions About Matrices]---|+\n" << endl
              << "\t+ To Get The Determine of a Matrix\t\t>>> Enter: 1\n\t"
	         << "____________________________________________________________" << endl
	         << "\t+ To Get The Transpose of a Matrix\t\t>>> Enter: 2\n\t"
	         << "____________________________________________________________" << endl
	         << "\t+ To Get The Trace of a Matrix \t\t\t>>> Enter: 3\n\t"
	         << "____________________________________________________________" << endl
              << "\n\t- To Back To The Main Menu >>> Enter: 0" << endl;
	cout <<"\n\t Enter A Number: ";
		cin >> Numf;

	if(Numf == 1){                          //  To Get The Determine of a Matrix
	system("cls");
	int Size;
	cout <<"\n\tEnter The Size for The Square Matrix: ";
    cin >> Size;

    Matrix M(Size, Size);
    cin >> M; // To Set The Elements of The Matrix
    cout << "\n\tThe Determent of This Matrix is : " << Determent(M,Size);

    cout << "\n\t+ To Back To Menu of Programming Enter : ANY NUMBER"
             << "\n\t- To Back To The Main Menu >>> Enter: 0" << endl
             <<"\n\t Enter A Number: ";
                      cin >> Numf;
	}
	else if(Numf == 2){                    // To Get The Transpose of a Matrix
	system("cls");
	int rSize, cSize;
	cout <<"\n\tEnter The Size of [Row] and [Column] for Matrix: ";
             cin >> rSize >> cSize;

    Matrix M(rSize, cSize);
            cin >> M;                             // To Set The Elements of The Matrix
    cout << "\n\tThe Transpose of This Matrix is : " << ~M << endl;
    cout << "\n\t+ To Back To Menu of Programming Enter : ANY NUMBER"
             << "\n\t- To Back To The Main Menu >>> Enter: 0" << endl
             <<"\n\t Enter A Number: ";
                      cin >> Numf;
	}
     else if(Numf == 3){                  // To Get The Trace of a Matrix
	system("cls");
	int Size;
	cout <<"\n\tEnter The Size for The Square Matrix: ";
     cin >> Size;

    Matrix M(Size, Size);
    cin >> M;
    cout << "\n\tThe Sum of Main Diagram Matrix is : " << Tra(M) << endl;
    cout << "\n\t+ To Back To Menu of Programming Enter : ANY NUMBER"
             << "\n\t- To Back To The Main Menu >>> Enter: 0" << endl
             <<"\n\t Enter A Number: ";
                    cin >> Numf;
}
	}
    while( Numf != 0);            // End Loop of The Functions About Matrices
    }
     else if(Num == 3){         // Get The Area of Triangle With Matrix Program
	system("cls");
     Triangle_Area();

    cout << "\n\t+ To Back To Menu of Programming Enter : ANY NUMBER"
             << "\n\t- To Exit >>> Enter: 0" << endl
             <<"\n\t Enter A Number: ";
                     cin >> Num;
    }
     else if (Num == 4){               //  Get The Area of Rectangle With Matrix Program
	system("cls");

	Rectangular_Area();

    cout << "\n\t+ To Back To Menu of Programming Enter : ANY NUMBER"
             << "\n\t- To Exit >>> Enter: 0" << endl
             <<"\n\t Enter A Number: ";
                    cin >> Num;
    }
    }
    while(Num != 0);  // End Loop of The Main Menu of Program
                                    // End of Project
	system("cls");
	cout <<"\n\n\t\t Thanks You to use Our Program"
	         <<"\n\t\t    This Project was Made By\n\n"
	         <<"\t - Ahmed El-Tabarani sec 2 | "<<" - Asmaa Mahmoud     sec 2\n"
	         <<"\t - El-Hussain Salama sec 2 | "<<" - Omnia Osman       sec 2\n"
	         <<"\t - Ismail Akram      sec 2 | "<<" - Eman Muhamed      sec 2\n"
	         <<"\t - Mahmoud Gamal     sec 7 | \n"<< endl;
    
return 0;   
}
