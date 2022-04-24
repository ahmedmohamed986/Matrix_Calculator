#include<iostream>
#include<math.h>
#include<string.h>
#include<string>
#include<cstdlib>
#include<sstream>
using namespace std;
int getNumbersFromInput(string matrix,float *output);
int getRows(string matrix);
int getColumns(string matrix);
void To2D(float* oneDimarr,float twoDimarr[100][100],int rows,int columns);
void addMatrices(float matrix1[100][100],float matrix2[100][100],int matrix1_rows,int matrix1_columns,int matrix2_rows,int matrix2_columns,float output[100][100])
;
void subtractMatrices(float matrix1[100][100],float matrix2[100][100],int matrix1_rows,int matrix1_columns,int matrix2_rows,int matrix2_columns,float output[100][100])
;
void multiplyMatrices(float matrix1[100][100],float matrix2[100][100],int matrix1_rows,int matrix1_columns,int matrix2_rows,int matrix2_columns,float output[100][100])
;
void displayMatrix(float matrix[100][100],int rows,int columns);
void powerMatrices(float matrix[100][100],int n,int rows,int columns,float output[100][100]);
float getDeterminant(float mat1[100][100],int matrix1_rows,int matrix1_columns);
void getTranspose(float mat1[100][100],int matrix1_rows,int matrix1_columns,float output[100][100]);
void getInverse(float matrix[100][100],int rows,int columns,float output [100][100]);
void divideMatrices(float matrix1 [100][100],float matrix2 [100][100],int matrix1_rows,int matrix1_columns,int matrix2_rows,int matrix2_columns,float output [100][100]);



int main()
{
	float mat1[100][100];
	float mat2[100][100];
	float m1[10000];
	float m2[10000];
	string matrix1;
	string matrix2;
	string operation;
	getline(cin, matrix1);
	int n;


	int matrix1_elements = getNumbersFromInput(matrix1,m1);
	int matrix1_rows = getRows(matrix1);
	int matrix1_columns = getColumns(matrix1);
	
	To2D(m1,mat1,matrix1_rows,matrix1_columns);

	if(matrix1_rows*matrix1_columns != matrix1_elements)
	{
	    cout<<"ERROR";
	}
	else
	{
	 getline(cin, operation);
	

	
   	if(operation == "+")
   	{
   	  float output[100][100];
   	  getline(cin, matrix2);
   	  int matrix2_elements = getNumbersFromInput(matrix2,m2);
	  int matrix2_rows = getRows(matrix2);
	  int matrix2_columns = getColumns(matrix2);
	  if(matrix2_rows*matrix2_columns != matrix2_elements || matrix1_rows != matrix2_rows || matrix1_columns != matrix2_columns)
	  {
	      cout<<"ERROR";
	  }
	  else
	  {
	  To2D(m2,mat2,matrix2_rows,matrix2_columns);
   	  addMatrices(mat1,mat2,matrix1_rows,matrix1_columns,matrix2_rows,matrix2_columns,output);
   	  displayMatrix(output,matrix1_rows,matrix1_columns);
	  }

   	}
   	else if(operation == "-")
   	{
   	  float output[100][100];
   	  getline(cin, matrix2);
   	  int matrix2_elements = getNumbersFromInput(matrix2,m2);
	  int matrix2_rows = getRows(matrix2);
	  int matrix2_columns = getColumns(matrix2);
	  if(matrix2_rows*matrix2_columns != matrix2_elements || matrix1_rows != matrix2_rows || matrix1_columns != matrix2_columns)
	  {
	      cout<<"ERROR";
	  }
	  else
	  {
	  To2D(m2,mat2,matrix2_rows,matrix2_columns);
      subtractMatrices(mat1,mat2,matrix1_rows,matrix1_columns,matrix2_rows,matrix2_columns,output);
      displayMatrix(output,matrix1_rows,matrix1_columns);
	  }
    }
    else if(operation == "*")
    {
      float output[100][100];
      getline(cin, matrix2);
   	  int matrix2_elements = getNumbersFromInput(matrix2,m2);
	  int matrix2_rows = getRows(matrix2);
	  int matrix2_columns = getColumns(matrix2);
	  if(matrix2_rows*matrix2_columns != matrix2_elements || matrix1_columns != matrix2_rows)
	  {
	      cout<<"ERROR";
	  }
	  else
	  {
	  To2D(m2,mat2,matrix2_rows,matrix2_columns);
      multiplyMatrices(mat1,mat2,matrix1_rows,matrix1_columns,matrix2_rows,matrix2_columns,output);
      displayMatrix(output,matrix1_rows,matrix2_columns);
	  }
    }
    else if(operation == "^")
    {
      if(matrix1_rows != matrix1_columns)
      {
          cout<<"ERROR";
      }
      else
      {
      float output[100][100];
      cin>>n;
      powerMatrices(mat1,n,matrix1_rows,matrix1_columns,output);
      displayMatrix(output,matrix1_rows,matrix1_columns);
      }
    }
    else if(operation == "D")
    {
        if(matrix1_rows != matrix1_columns)
       {
         cout<<"ERROR";
       }
       else
       {
        float determinant = getDeterminant(mat1,matrix1_rows,matrix1_columns);
        cout<<determinant;
       }
    }
    else if(operation == "T")
    {
        float output[100][100];
        getTranspose(mat1,matrix1_rows,matrix1_columns,output);
        displayMatrix(output,matrix1_columns,matrix1_rows);
    }
    else if(operation == "I")
    {
       float mat1_copy[100][100];         //copying to another matrix because mat1 will be modified in getDeterminant function
       for(int i = 0;i < matrix1_rows;i++)
       {
           for(int j = 0;j < matrix1_columns;j++)
           {
               mat1_copy[i][j] = mat1[i][j];
           }
       }
       if(getDeterminant(mat1,matrix1_rows,matrix1_columns) == 0 || matrix1_rows != matrix1_columns)
       {
           cout<<"ERROR";
       }
       else
       {
           float output [100][100];
           getInverse(mat1_copy,matrix1_rows,matrix1_columns,output);
           displayMatrix(output,matrix1_columns,matrix1_rows);
        }
	}
	else if(operation == "/")
	{
	  getline(cin, matrix2);
   	  int matrix2_elements = getNumbersFromInput(matrix2,m2);
	  int matrix2_rows = getRows(matrix2);
	  int matrix2_columns = getColumns(matrix2);
	  To2D(m2,mat2,matrix2_rows,matrix2_columns);
	  if(matrix2_rows * matrix2_columns != matrix2_elements || matrix2_columns != matrix2_rows || matrix1_columns != matrix2_rows || getDeterminant(mat2,matrix2_rows,matrix2_columns) == 0)
	  {
	      cout<<"ERROR";
	  }
	  else
	  {
	  float output [100][100];
	  divideMatrices(mat1,mat2,matrix1_rows,matrix1_columns,matrix2_rows,matrix2_columns,output);
	  displayMatrix(output,matrix1_rows,matrix1_columns);
	  }
	}
}
	return 0;
    
}

int getNumbersFromInput(string matrix,float* output)
{
    int index = 1;
    string number;   //filtered number from the string
    int elements = 0;
    
    for (int i = 2; i <= matrix.length(); i++)
	{
		if (matrix[i] == ' ' || matrix[i] == ';' || matrix[i] == ']')
		{
			number = matrix.substr(index, i - index);
			index = i + 1;
			output[elements] = atof(number.c_str());;
			elements++;              //number of elements//
		}
	}
	return elements;
}

int getRows(string matrix)
{
    int rows = 1;
    for (int i = 0; i <= matrix.length(); i++)
	{
		if (matrix[i] == ';')
			rows++;                //number of rows
	}
	return rows;
}
int getColumns(string matrix)
{
    int columns = 1;
    for (int i = 0; i <= matrix.length() - 1; i++)
	{
		if (matrix[i] == ' ')
			columns++;                //number of columns//
		if (matrix[i] == ';')
		{
			break;
		}
	}
	return columns;
}

void To2D(float* oneDimarr,float twoDimarr[100][100],int rows,int columns)
{
    int oneDimarr_index = 0;
    for (int i = 0; i <= rows - 1; i++)
	{
		for (int j = 0; j <= columns - 1; j++)
		{
			twoDimarr[i][j] = oneDimarr[oneDimarr_index];
			oneDimarr_index++;
		}
	}
}
void addMatrices(float matrix1[100][100],float matrix2[100][100],int matrix1_rows,int matrix1_columns,int matrix2_rows,int matrix2_columns,float output[100][100])
{
	if (matrix1_rows == matrix2_rows &&matrix1_columns == matrix2_columns){
			for (int i = 0; i <= matrix1_rows - 1; i++)
			{
				for (int j = 0; j <= matrix1_columns - 1; j++)
				{
				output[i][j] = matrix1[i][j]+matrix2[i][j];
				}
            }
		}
		else
		{
			cout << "ERROR";
			return;
		}
	
}
void subtractMatrices(float matrix1[100][100],float matrix2[100][100],int matrix1_rows,int matrix1_columns,int matrix2_rows,int matrix2_columns,float output[100][100])
{

	if (matrix1_rows == matrix2_rows &&matrix1_columns == matrix2_columns){
			for (int i = 0; i <= matrix1_rows - 1; i++)
			{
				for (int j = 0; j <= matrix1_columns - 1; j++)
				{
				  output[i][j] = matrix1[i][j]+matrix2[i][j];
                }

			}
		}
		else
		{
			cout << "ERROR";
			return;
		}
}
void multiplyMatrices(float matrix1[100][100],float matrix2[100][100],int matrix1_rows,int matrix1_columns,int matrix2_rows,int matrix2_columns,float output[100][100])
{
    if (matrix1_columns == matrix2_rows){
	  for (int i = 0; i < matrix1_rows; i++) {
        for (int j = 0; j < matrix2_columns; j++) {
            output[i][j] = 0;
            for (int k = 0; k < matrix2_rows; k++) {
                output[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
  
}
	else{
		cout << "ERROR";
		return;
		}
}
void powerMatrices(float matrix[100][100],int n,int rows,int columns,float output[100][100])
{
   float matrix2[100][100];
   for(int i = 0;i < rows;i++)    //constructing identity matrix
   {
       for(int j = 0;j < columns;j++)
       {
           if(i == j)
           {
               matrix2[i][j] = 1;
           }
           else
           {
               matrix2[i][j] = 0;
           }
       }
   }
   for(int i = 1;i <= n;i++)
   {
     multiplyMatrices(matrix,matrix2,rows,columns,rows,columns,output);
     for(int i = 0;i < rows;i++)    
     {
       for(int j = 0;j < columns;j++)
       {
          matrix2[i][j] = output[i][j];
       }
     }    
       
   }
}
void displayMatrix(float matrix[100][100],int rows,int columns)
{
  cout<<"[";
    for(int i = 0;i < rows;i++)
    {
        for(int j = 0;j < columns;j++)
        {
            if(j != columns - 1)
            {
              cout<<matrix[i][j]<<" ";
            }
            else
            {
                cout<<matrix[i][j];
            }
        }
        if(i != rows - 1)  //new row
        {
            cout<<";";
        }
    }
    cout<<"]";
}



void getTranspose(float matrix[100][100],int rows,int columns,float output[100][100])
{
    for(int i = 0;i < rows;i++)
    {
        for(int j = 0;j < columns;j++)
        {
            output[j][i] = matrix[i][j];
        }
    }
}

float getDeterminant(float matrix[100][100],int rows,int columns)
{
    float det = 1;
    for (int i = 0; i < columns-1; i++)
    {
        for (int j = i+1; j < rows; j++)
            {
                float temp = matrix[j][i]/matrix[i][i];
                for (int k = 0; k < columns; k++)    
                    matrix[j][k] -= temp*matrix[i][k];
            }
    }
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            {
                if(i == j)
                {
                    det *= matrix[i][j];
                }
            }
    }
    if(det == -0)
   {
       det = 0;
   }
    return det;
}

void getInverse(float matrix[100][100],int rows,int columns,float output [100][100])
{
    //Building Augmented Matrix
    
    for(int i = 0;i < rows;i++)        
       {
        for(int j = columns;j < 2*columns;j++)
        {
            if(j - i == rows)
            {
                matrix[i][j] = 1;
            }
            else
            {
                matrix[i][j] = 0;
            }
        }
       }
       
       
       //zeros the elements under the diagonal
       
       for (int i = 0; i < columns-1; i++)   
    {
        for (int j = i+1; j < rows; j++)
            {
                float temp = matrix[j][i]/matrix[i][i];
                for (int k = 0; k < 2*columns; k++)    
                    matrix[j][k] -= temp*matrix[i][k];
            }
    }
     for (int i = columns-1; i > 0; i--)   //zeros the elements above the diagonal
    {
        for (int j = 0; j < i; j++)
            {
                float temp = matrix[j][i]/matrix[i][i];
                for (int k = 0; k < 2*columns; k++)    
                   { 
                       matrix[j][k] -= temp*matrix[i][k];
                   }
            }
    }
    
    //Getting the identity matrix on the left
    for(int i = 0;i < rows;i++)
    {
        float temp = matrix[i][i];
        for(int j = 0;j < 2*columns;j++)
        {
            matrix[i][j] = matrix[i][j]/temp;
        }
    }
    
    //storing the inverse in the output array
    for(int i = 0;i < rows;i++)
    {
        for(int j = 0;j < columns;j++)
        {
            output[i][j] = matrix[i][columns+j];
        }
    }
}

void divideMatrices(float matrix1 [100][100],float matrix2 [100][100],int matrix1_rows,int matrix1_columns,int matrix2_rows,int matrix2_columns,float output [100][100])
{
    float inverse_output[100][100];
    getInverse(matrix2,matrix2_rows,matrix2_columns,inverse_output);
    multiplyMatrices(matrix1,inverse_output,matrix1_rows,matrix1_columns,matrix2_rows,matrix2_columns,output);
}

