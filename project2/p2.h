#include <iostream>
#include <fstream>
#include <string.h>
#include "/ee259/tools/pro_2/sample_p1.h" // implementation of base class

using namespace std;

ifstream input_file_p2("studentName.txt", ios::in);
//ofstream output_file_p2("out.1", ios::app);

  class SORT_INFO:public STUDENT_GRADE{
   public:      // public interfaces for this class

        SORT_INFO(int, int); // example: b.SORT_INFO(x, y);
				// constructor;
				// x is noof students, y is noof projects

        void SORT_ID(char *); // example: b.SORT_GRADE("ASCENDING");
				// interface to sort student ids in 
				// ascending order; returns no values;

        void SORT_GRADE(char *, int); // example: b.SORT_GRADE("ASCENDING", 2);
				// interface to sort exam 2 grades in 
				// ascending order; returns no values;

        void SORT_NAME(char *); // example: b.SORT_NAME("ASCENDING");
			    	// interface to sort students by last names
			    	// in alphabetical or reverse alphabetical order; 
			    	// returns no values;

   // protected vars below can only be accessed within this class and inherited classes
   // they are not directly accessible from main
   protected: 
	char LastName[20][12];   // array to hold student's last name
	char FirstName[20][12];  // array to hold student,s first name
   };

SORT_INFO::SORT_INFO(int x, int y)
	: STUDENT_GRADE(x, y) // call to base class which requires two parameters
{
	int i;
	output_file_p2 << "++++ P2 START ++++" << endl;
	output_file_p2 << "++++ P2 OUTPUT FROM STUDENT_GRADE CONSTRUCTOR:" << endl;	

	for(i = 0; i < n; i++)
	{
		input_file_p2 >> LastName[i] >> FirstName[i];
	}
	output_file_p2 << "++++ P2 AN OBJECT OF SORT_INFO IS CREATED." << endl;
	output_file_p2 << "++++ P2 END ++++" << endl;
}

void
SORT_INFO::SORT_ID(char * DIRECTION)
{
	int i, j, k;
	int min, min_pos, max, max_pos, tempo;
	char tempo_name[12];

	// your code goes below:
	
	for(i = 0; i<n; i++)
	{
		min = ids[i];
		min_pos = i;
		for(j = i; j<n; j++)
		{
			if(min>ids[j])
			{
				min = ids[j];
				min_pos = j;
			}
			else{}
		}
		tempo = ids[i];
		ids[i] = ids[min_pos];
		ids[min_pos] = tempo;
	}

}

void
SORT_INFO::SORT_GRADE(char * DIRECTION, int x)
{
	int i, j, k;
	int min, min_pos, max, max_pos, tempo;
	char tempo_name[12];

	// your code goes below:

	for(i = 0; i<n; i++)
	{
		min = ids[i][x];
		min_pos = i;
		for(j = i; j<n; j++)
		{
			if(min>ids[j][x])
			{
				min = ids[j][x];
				min_pos = j;
			}
			else{}
		}
		tempo = ids[i][x];
		ids[i] = ids[min_pos][x];
		ids[min_pos][x] = tempo;
	}

}
}

void
SORT_INFO::SORT_NAME(char * DIRECTION)
{
	int i, j, k;
	int min_pos, max_pos, tempo;
	char min_name[12], max_name[12], tempo_name[12];

	// your code goes below:
	for(i = 0; i<n; i++)
	{
		strcpy(&min_name[0], &LastName[i][0]);
		min_pos = i;
		for(j = i; j<n; j++)
		{
			if(strcmp(&min_name[0], &LastName[j][0])>0)
			{
				strcpy(&min_name[0],&LastName[j][0]);
			//added by me:
				min_pos = j;
			}
			else{}
		}
		strcpy(&tempo_name[0], &LastName[i][0]);
		strcpy(&LastName[i][0],&LastName[min_pos][0]);
		strcpy(&LastName[min_pos][0], &tempo_name[0]);

}// end method


















