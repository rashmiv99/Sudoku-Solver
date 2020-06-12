#include <iostream>
#include <cstring>
#include <windows.h> 
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Sudoku
{
	int sqr[9][9];
	int solved ;
	public:
		
		Sudoku()
		{			
			int i, j;
			for(i=0; i<9; i++)
			{
				for(j=0; j<9; j++)
				{
					sqr[i][j] = 0;					
				}
			}
			solved = 0;
		}
		
		Sudoku(int a[][9])
		{
			int i, j;
			for(i=0; i<9; i++)
			{
				for(j=0; j<9; j++)
				{
					sqr[i][j] = a[i][j];					
				}
			}
			solved = 0;
		}
		
		void input()
		{			
			int i, j;
			cout<<endl<<"Enter the values for the Sudoku ROW by ROW: "<<endl;
			for(i=0; i<9; i++)
			{
				for(j=0; j<9; j++)
				{
					cout<<" ("<<i+1<<", "<<j+1<<"): ";
					cin>>sqr[i][j];					
				}
			}
		}
		
		int getel(int a, int b)      //[a][b] is the matrix number for the element
		{
			return sqr[a][b];
		}
		
		void getAllEl(int a[][9])
		{
			int i, j;
			for(i=0; i<9; i++)
			{
				for(j=0; j<9; j++)
				{
					a[i][j] = sqr[i][j];					
				}
			}
		}
		
		int checkrow(int el, int r, int c)
		{
			int i, j; 
			for(i=0; i<=8; i++)
			{
				if (el == sqr[r][i])
				{
					return 1;      //returns 1 if it's already present	
				}				 
			}			
			return 0;      //returns 0 if it's not in that row
		}
		
		int checkcolumn(int el, int r, int c)       
		{      //Takes in an element and check if it's already present in row or column
			int i, j;
			for(i=0; i<=8; i++)
			{
				if (el == sqr[i][c])
				{
					return 1;						
				}			 
			}
			return 0;      //returns 0 if element is not in the column
		} 
		
	    void setel(int el, int r, int c)      //Setter for any position
	    {
	    	sqr[r][c] = el;
	    }
	    
	    void display()      //Display function
	    {
	    	int i, j;	    			
			setcolor(5);
		    cout<<endl<<"----------------------------"<<endl;
		    setcolor(15);
			for(i=0; i<9; i++)
			{
				setcolor(5);
				cout<<"|";
				setcolor(15);
				for(j=0; j<9; j++)
				{
					if (sqr[i][j] != 0) 
					{
						cout<<" "<<sqr[i][j];
						if(j==2 || j==5 || j==8)
						{
							setcolor(5);
							cout<<"|";
							setcolor(15);
						}
						else 
						{
							cout<<"|";
						}
					}					
					else  
					{
						if(j==2 || j==5 || j==8)
						{
							setcolor(5);
							cout<<"  "<<"|";
							setcolor(15);
						}	
						else
						{
							cout<<"  "<<"|";
						}
					}
				}
				if(i==2 || i==5 || i==8)
				{
					setcolor(5);
		            cout<<endl<<"----------------------------"<<endl;
		            setcolor(15);
				}
				else
				{
				    cout<<endl<<"----------------------------"<<endl;
				}				
			}	    	
	    }
	    
	    void setcolor(int k)
	    {
	    	HANDLE  hConsole;
	        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	
	        SetConsoleTextAttribute(hConsole, k);
        }
        
	    int done()
	    {
	    	int i, j;
	    	int flag = 1;	
			for(i=0; i<9; i++)
			{				
				for(j=0; j<9; j++)
				{
					if (sqr[i][j] == 0) 
					{
						flag = 0;
					}				
				}				
			}	
			return flag;  
	    }
	    
		void getbox1(int a[][3])
		{      //(1,1) to (3,3)
			int i, j;
			for(i=0; i<3; i++)
			{
				for(j=0; j<3; j++)
				{
					a[i][j] = sqr[i][j];
				}
			}
		} 
		
		void getbox2(int a[][3])
		{      //(1,4) to (3,6)
			int i, j, c=0;
			for(i=0; i<3; i++)
			{
				for(j=3; j<6; j++)
				{
					c = j-3;
					a[i][c] = sqr[i][j];
				}
			}
		}
		
		void getbox3(int a[][3])
		{     //(1,7) to (3,9)
			int i, j, c=0;	
			for(i=0; i<3; i++)
			{
				for(j=6; j<9; j++)
				{
					c = j-6;
					a[i][c] = sqr[i][j];
				}
			}			
		}
		
		void getbox4(int a[][3])
		{      //(4,1) to (6,3)
			int i, j, r;	
			for(i=3; i<6; i++)
			{
				for(j=0; j<3; j++)
				{
					r = i-3;					
					a[r][j] = sqr[i][j];
				}
			}
		}
		
		void getbox5(int a[][3])
		{      //(4,4) to (6,6)
			int i, j, r, c;	
			for(i=3; i<6; i++)
			{
				for(j=3; j<6; j++)
				{
					r = i-3;
					c = j-3;
					a[r][c] = sqr[i][j];
				}
			}
		}
		
		void getbox6(int a[][3])
		{      //(4,7) to (6,9)
			int i, j, r, c;
			for(i=3; i<6; i++)
			{
				for(j=6; j<9; j++)
				{
					r = i-3;
					c = j-6;
					a[r][c] = sqr[i][j];
				}
			}
		}
		
		void getbox7(int a[][3])
		{      //(7,1) to (9,3)
			int i, j, r, c;
			for(i=6; i<9; i++)
			{
				for(j=0; j<3; j++)
				{
					r = i-6;
					a[r][j] = sqr[i][j];
				}
			}
		}
		
		void getbox8(int a[][3])
		{      //(7,4) to (9,6)
			int i, j, r, c;
			for(i=6; i<9; i++)
			{
				for(j=3; j<6; j++)
				{
					r = i-6;
					c = j-3;
					a[r][c] = sqr[i][j];
				}
			}
		}
		
		void getbox9(int a[][3])
		{      //(7,7) to (9,9)
			int i, j, r, c;
			for(i=6; i<9; i++)
			{
				for(j=6; j<9; j++)
				{
					r = i-6;
					c = j-6;
					a[r][c] = sqr[i][j];
				}
			}
		}		
};

struct sudoku
{
	int mat[9][9];
};

void setcolor(int k)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	
	SetConsoleTextAttribute(hConsole, k);
}

int searchbox(int a[][3], int num)      //returns 1 if the number is already in the box
{
	for(int i=0; i<3;i++)
	{
		for(int j=0; j<3; j++)
		{
			if(a[i][j] == num)
			{
				return 1;
			}
		}
    }
    return 0;      //returns 0 if the number was not found in the box
}

bool issafe(Sudoku S1, int row, int column, int num)      //returns True if safe and False if not
{
	int BOX;
	int a[3][3];
	int flag=0;
	if(S1.checkrow(num, row, column) != 0)      //checks the row
	{
		flag = 1;      //flag becomes 1 if it's NOT safe
		return false;
	}
	if(S1.checkcolumn(num, row, column) != 0)      //checks the column
	{
		flag = 1;
		return false;
	}
    if(row<=2 && column<=2)
    {
    	BOX = 1;
    	S1.getbox1(a);
    	int x = searchbox(a, num);      //searchbox should return 1 if num is there in the box and 0 if it's not
        if(x==1) 
        {
		    return false;
	    }	    
	}
	else if(row<=2 && column<=5)
	{
		BOX = 2;
		S1.getbox2(a);
    	int x = searchbox(a, num);  
        if(x == 1)
        {
		    return false;
	    }	    
	}	
	else if(row<=2 && column<=8)
	{
		BOX = 3;
		S1.getbox3(a);
    	int x = searchbox(a, num);
        if(x == 1)
        {
		    return false;
	    }	
	}
	else if(row<=5 && column<=2)
	{
		BOX = 4;
		S1.getbox4(a);
    	int x = searchbox(a, num);
        if(x == 1)
        {
		    return false;
	    }	
	}
	else if(row<=5 && column<=5)
	{
		BOX = 5;
		S1.getbox5(a);
    	int x = searchbox(a, num);
        if(x == 1)
        {
		    return false;
	    }	
	}
	else if(row<=5 && column<=8)
	{
		BOX = 6;
		S1.getbox6(a);
    	int x = searchbox(a, num);
        if(x == 1)
        {
		    return false;
	    }	
	}
	else if(row<=8 && column<=2)
	{
		BOX = 7;
		S1.getbox7(a);
    	int x = searchbox(a, num);
        if(x == 1)
        {
		    return false;
	    }	
	}
	else if(row<=8 && column<=5)
	{
		BOX = 8;
		S1.getbox8(a);
    	int x = searchbox(a, num);
        if(x == 1)
        {
		    return false;
	    }	
	}
	else 
	{
		BOX = 9;
		S1.getbox9(a);
    	int x = searchbox(a, num);
        if(x == 1)
        {
		    return false;
	    }	
	}    
	return true;
}

void findunassigned(int a[9][9], int &r, int &c)      //finds position where no number is assigned
{
	int i, j;
	for(i=0; i<9; i++)
	{
		for(j=0; j<9; j++)
		{
			if(a[i][j] == 0)
			{
				r = i;
				c = j;
				break;
			}
		}
    }
}

bool SolveSudoku(Sudoku &S1)      //Solves Sudoku using Backtracking
{
	int i, j;
	int a[9][9];
	S1.getAllEl(a);
	int k;
	for(k=1; k<=9; k++)
	{
		findunassigned(a, i, j);
		if(issafe(S1, i, j, k) && a[i][j] == 0 )
		{
			a[i][j] = k;
			S1.setel(k, i, j);		
			if(SolveSudoku(S1))
			{
				return true;						
			}
			a[i][j] = 0;
			S1.setel(0, i, j);
	    }
	    if(S1.done() == 1)      //All positions are filled
	    {
	    	return true;
		}
	}
	return false;
}

int CheckUserSolution(Sudoku S1)
{
	int i, j, el;
	int a[9][9], b[9][9];	
	Sudoku copy; 
	copy = S1;
	bool x = SolveSudoku(copy);      //creates a copy containing the right solution
	do      //gets all values for empty spots
	{
		S1.getAllEl(a);
		findunassigned(a, i, j);
		cout<<"\nElement ("<<i+1<<", "<<j+1<<"): ";
		cin>>el;							
		a[i][j] = el;
		S1.setel(el, i, j);
	}
	while(S1.done() != 1);
    copy.getAllEl(b);
    S1.display();
    for(i=0; i<9; i++)
    {
    	for(j=0; j<9; j++)
    	{
    		if(a[i][j] != b[i][j])
    		{
    			return 0;
			}
		}
	}
	return 1;
}

void intro()      //Decoration purpose
{
	for (int i=0; i<3; i++)
	{
	    cout<<endl;
	}
    cout<<"   _____________________         _______         _______         _____________________              _____________________         _______       ________        _______         _______"<<endl;
	Sleep(300);
	system("COLOR 01");
    cout<<"  |                     |       |       |       |       |       |                     \\            |                     |       |       |     /       /       |       |       |       |"<<endl;
	Sleep(300);
	system("COLOR 02");
    cout<<"  |                     |       |       |       |       |       |                      \\           |                     |       |       |    /       /        |       |       |       |"<<endl;
	Sleep(300);
	system("COLOR 03");
    cout<<"  |         ____________|       |       |       |       |       |        ________       \\          |       _______       |       |       |   /       /         |       |       |       | "<<endl;		
	Sleep(300);
	system("COLOR 04");
    cout<<"  |        |                    |       |       |       |       |       |        \\       \\         |      |       |      |       |       |  /       /          |       |       |       |"<<endl;
	Sleep(300);
	system("COLOR 05");
    cout<<"  |        |                    |       |       |       |       |       |         \\       \\        |      |       |      |       |       | /       /           |       |       |       |"<<endl;
	Sleep(300);
	system("COLOR 06");
    cout<<"  |        |____________        |       |       |       |       |       |          |       |       |      |       |      |       |       |/       /            |       |       |       |"<<endl;
	Sleep(300);
	system("COLOR 07");
    cout<<"  |                     |       |       |       |       |       |       |          |       |       |      |       |      |       |               /             |       |       |       |"<<endl;
	Sleep(300);
	system("COLOR 08");
    cout<<"  |                     |       |       |       |       |       |       |          |       |       |      |       |      |       |               |             |       |       |       |"<<endl;
	Sleep(300);
	system("COLOR 09");
    cout<<"  |____________         |       |       |       |       |       |       |          |       |       |      |       |      |       |               \\             |       |       |       |"<<endl;
	Sleep(300);
	system("COLOR 01");
    cout<<"               |        |       |       |       |       |       |       |          |       |       |      |       |      |       |       |\\       \\            |       |       |       |"<<endl;
	Sleep(300);
	system("COLOR 02");
    cout<<"               |        |       |       |       |       |       |       |         /       /        |      |       |      |       |       | \\       \\           |       |       |       |"<<endl;
	Sleep(300);
	system("COLOR 06");
    cout<<"   ____________|        |       |       |_______|       |       |       |________/       /         |      |_______|      |       |       |  \\       \\          |       |_______|       |"<<endl;
	Sleep(300);
	system("COLOR 04");
    cout<<"  |                     |       |                       |       |                       /          |                     |       |       |   \\       \\         |                       |"<<endl;
	Sleep(300);
	system("COLOR 05");
    cout<<"  |                     |       |                       |       |                      /           |                     |       |       |    \\       \\        |                       |"<<endl;
	Sleep(300);
	system("COLOR 03");
    cout<<"  |_____________________|       |_______________________|       |_____________________/            |_____________________|       |_______|     \\_______\\       |_______________________|"<<endl;
	cout<<endl;
	cout<<endl;		
}

main()
{
	Sudoku S1, copy;      //Main sudoku is S1, copy is just to experiment with
    int solved = 0, i, j, val;      //final value to check
	int a[3][3];	
	bool find;	
	int choice=0;	
	char diff;
	srand(time(NULL));
	int n = rand()%3;
	char filestringsE[3][20]={"E:\\Easy1.dat", "E:\\Easy2.dat", "E:\\Easy3.dat"};      //array of easy sudoku
	char filestringsM[3][20]={"E:\\Medium1.dat", "E:\\Medium2.dat", "E:\\Medium3.dat"};      //array of moderate sudoku
	char filestringsH[3][20]={"E:\\Hard1.dat", "E:\\Hard2.dat", "E:\\Hard3.dat"};      //array of hard sudoku
    intro();
    
	do
	{	
	    setcolor(15);
	    cout<<" Enter: "<<endl;
	    cout<<" 1 to Enter a New Sudoku. \n";
	    cout<<" 2 to Solve a Sudoku from Database. \n";
	    cout<<" 3 to Quit. \n\n";
	    cout<<" Enter choice: ";
	    cin>>choice;
	    
	    if(choice == 1)      //TO GET A NEW SUDOKU 
	    {
		    cout<<"\n Enter Sudoku: ";
	        S1.input();      //gets input
		    S1.display();      //displays the sudoku
		    cout<<" CALCULATING...";
		    Sleep(1000);
	        find = SolveSudoku(S1);      //Starts Solving
	        if(find == true)      //solution found
            {
           	    S1.display();    	
	        }
	        else      //solution not found
	        {
	       	    cout<<" No solution found. ";
	        }	
	    }
	    
	    else if(choice == 2)      //CHOOSE FROM EXISTING DATABASE
	    {
		    cout<<"\n Select Difficulty: \n";
		    cout<<" E = Easy \n M = Moderate \n H = Hard ";
		    cout<<endl;
		    cout<<" Enter choice: ";
		    cin>>diff;
		    if(diff == 'E')
		    {	
		        fstream file;
	            file.open(filestringsE[n], ios::in|ios::binary);  
                if(file)      //picks a random sudoku from selected difficulty
		        {
		    	    file.read((char*)&S1, sizeof(Sudoku));
		        }
	        }
	        else if(diff == 'M')
		    {
			    fstream file;
	            file.open(filestringsM[n], ios::in|ios::binary);  	
                if(file)      //picks a random sudoku from selected difficulty
		        {
		    	    file.read((char*)&S1, sizeof(Sudoku));
		        }   
		    }
		    else 
		    {
			    fstream file;
	            file.open(filestringsH[n], ios::in|ios::binary);   
                if(file)      //picks a random sudoku from selected difficulty
		        {
		    	    file.read((char*)&S1, sizeof(Sudoku));
		        }
            }
				        
		    S1.display();      //displays the sudoku    
	        cout<<"\n Enter: "<<endl;      //prompts user for solution
		    cout<<" 1 to Check your Solution. \n";
		    cout<<" 2 to let the program Solve the Sudoku. \n";
		    cout<<" Enter choice: ";
	        cin>>n;
	        cout<<endl;
	        if(n == 1)
	        {
	       	    val = CheckUserSolution(S1);      //gets user's solution and checks it
	       	    if(val == 1)
	       	    {
	       	    	cout<<" Correct Solution!"<<endl;;
				}
			    else
			    {
				    cout<<" Incorrect Solution."<<endl;;
			    }  	
		    }
		    else      //else, let the algorithm solve it                
		    {
			    cout<<" CALCULATING..."<<endl;
			    Sleep(1000);
	            find = SolveSudoku(S1);      //Solves it
	            if(find == true)      //solution found 
                {
                    S1.display();       	
	            }
	            else      //solution not found
	            {
	       	        cout<<" No solution found."<<endl;
	            }
		    }     
	    }
    }
	while (choice!=3);      //End of loop. Checks if user wishes to quit the program
	
	return 0;
}

