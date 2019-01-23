#include <iostream>
#include <fstream>
#include <string.h>
//#include "/ee259/tools/pro_4/sample_p3.h" // implementation of base class
#include "sample_p3.h" // implementation of base class

using namespace std;

  class OVERLOADED_BURSAR:public BURSAR_INFO{

   public:      // public methods for this class

        OVERLOADED_BURSAR(char *, int, int);  // constructor 1:
			// Example: OVERLOADED_BURSAR B("ObjName1", x, y);
                        // instantiate object B of class OVERLOADED_BURSAR 
			// with nam ObjName1, x students and y exams;

        OVERLOADED_BURSAR(char *);  // constructor 2:
			// Example: OVERLOADED_BURSAR B;
                        // instantiate object B of class OVERLOADED_BURSAR
			// there are 0 students;

	void PRINT_IDS(void); // Example: b.PRINT_IDS();
                        // method prints student ids;
                        // returns no values;

	void ADD_STUDENT(char *, char *, int); 
			// Example: B.ADD_STUDENT("PEGGY", "HEIDI", 1234);
			// Add student to object B;
			// Set all exam grades to 0;
			// returns no values;

	void DELETE_STUDENT(char *, char *, int); 
			// Example: B.DELETE_STUDENT("PEGGY", "HEIDI", 1234);
			// Delete student from object B;
			// returns no values;

        int operator == (OVERLOADED_BURSAR); // Example: if (B1 == B2)
                        // returns 1 if the number of students in B1
                        // and B2 are equal;
                        // returns 0 otherwise;

        int operator == (int); // Example: if (B1 == 4)
                        // returns 1 if the number of students in B1
                        // is equal to 4;
                        // returns 0 otherwise;

        int operator > (OVERLOADED_BURSAR); // Example: if (B1 > B2)
                        // returns 1 if the maximum grade of students
			// received in all exams in B1 is greater than in B2;
                        // returns 0 otherwise;

	void operator = (OVERLOADED_BURSAR); // Example: B1 = B2;
			// assign student ids and exam grades of B2 to B1; 
			// B2 remains unchanged;
			// returns no values;

        OVERLOADED_BURSAR operator + (OVERLOADED_BURSAR); // Example: B1 + B2;
                        // create a TEMP object; 
			// copy the student ids, names and exams of B1 to TEMP
			// and then append B2 elements to TEMP;
			// return TEMP object;
                        // for simplicity, assume all students are unique;
	protected:
		char objectName[12]; // name for this object; max 11 chars
   };

OVERLOADED_BURSAR::OVERLOADED_BURSAR(char * ObjN, int x, int y)
	: BURSAR_INFO(x, y)
{
	strcpy(objectName, ObjN);
	// your code goes below:
	output_file_p4 << "++++++++ P4 START ++++" << endl;
	output_file_p4 << "++++++++ P4 OUTPUT FROM OVERLOADED_BURSAR CONSTRUCTOR:" << endl;
	output_file_p4 << "++++++++ P4 AN OBJECT OF OVERLOADED_BURSAR WITH THE NAME OF ObjN IS CREATED." << endl;
	output_file_p4 << "++++++++ P4 END ++++" << endl;
}

OVERLOADED_BURSAR::OVERLOADED_BURSAR(char * ObjN)
	: BURSAR_INFO(0, 0)
{
	// no output is generated; base classes assign n=0 and p=0 and do not generate outputs; 
	strcpy(objectName, ObjN);
}

void 
OVERLOADED_BURSAR::PRINT_IDS()
{
	// your code goes below:
	//Printing output for the given object whose name is stored in string 
	//objectName as copied from ObjN in constructor
	output_file_p4 << "++++++++ P4 START ++++" << endl;
	output_file_p4 << "++++++++ P4 OUTPUT FROM PRINT_IDS METHOD FOR OBJECT "<< objectName<<":" << endl;
	LIST_ID(1);
}

void 
OVERLOADED_BURSAR::ADD_STUDENT(char * F, char *L, int x)
{
	// your code goes below:
	int j;
	//Printing output for the given object whose name is stored in string 
	//objectName as copied from ObjN in constructor
	output_file_p4 << "++++++++ P4 START ++++" << endl;
	
	//if First and Last names, and id valid, increment noof students, fill in id, Last and First name,
	//and assign 0 to all grades for new student
	
	if(x <1000 || x > 9999)
	{
		output_file_p4 << "++++++++ P4 OUTPUT FROM ADD_STUDENT METHOD FOR "<< objectName<<":" << endl;
		output_file_p4 << "++++++++ P4 INPUT ERROR." << endl;
		
	}
	else
	{	
		output_file_p4 << "++++++++ P4 OUTPUT FROM ADD_STUDENT METHOD FOR OBJECT "<< objectName<<":" << endl;
		n++;
		ids[n-1] = x;
		strcpy(LastName[n-1], L);
		strcpy(FirstName[n-1], F);
		for(j = 0; j<p; j++)
		{
			grades[n-1][j] = 0;
		}
		output_file_p4 << "++++++++ P4 STUDENT "<< L <<","<< F <<" WITH ID "<< x <<" IS ADDED." << endl;
	}
	output_file_p4 << "++++++++ P4 END ++++" << endl;
}

void 
OVERLOADED_BURSAR::DELETE_STUDENT(char * F, char *L, int x)
{
	// your code goes below:
	int i, j;
	int FOUND, FOUND_POS;
	output_file_p4 << "++++++++ P4 START ++++" << endl;
	output_file_p4 << "++++++++ P4 OUTPUT FROM DELETE_STUDENT METHOD FOR OBJECT "<<objectName<<": "<< endl;
	FOUND = 0;
	for(i =0; i < n && FOUND == 0; i++)
	{
		if(strcmp(FirstName[i], F)== 0 && strcmp(LastName[i], L) == 0 )
		{
			FOUND = 1;
			FOUND_POS = i;
		}
		else{}
	}
	if(x <1000 || x > 9999)
	{
		output_file_p4 << "++++++++ P4 INPUT ERROR." << endl;
		
	}
	else if(FOUND == 0)
	{
		output_file_p4 << "++++++++ P4 NO SUCH STUDENT "<< L<<", "<< F <<" WITH ID "<<x<<" IS FOUND." << endl;
	}
	else
	{	
		n--;
		ids[n] = NULL;
		LastName[n] = NULL
		FirstName[n] = NULL;
		for(j = 0; j<p; j++)
		{
			grades[n] = NULL;
		}
		output_file_p4 << "++++++++ P4 STUDENT "<< L <<","<< F <<" WITH ID "<< x <<" IS DELETED." << endl;
		output_file_p4 << "++++++++ P4 NOW THERE ARE "<< n-1 <<" STUDENTS." << endl;
	}
	output_file_p4 << "++++++++ P4 END ++++" << endl;
}

int 
OVERLOADED_BURSAR::operator == (OVERLOADED_BURSAR Obj)
{
	// your code goes below:
	output_file_p4 << "++++++++ P4 START ++++" << endl;
	output_file_p4 << "++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR == METHOD FOR OBJECT "<< objectName<<": "<< endl;
	output_file_p4 << "++++++++ P4 CHECKING IF NUMBER OF STUDENTS IN "<<objectName<<" AND "<<Obj<<" ARE EQUAL: " << endl;
	//Checking if noof students in object OVERLOADED_BURSAR1(the one we are calling the method on), is equal to 
	//the noof students in object OVERLOADED_BURSAR1(the one we are passing as a parameter to the method)	
	if(n == Obj.n)
	{
		output_file_p4 << "++++++++ P4 RETURNS TRUE." << endl;
		return 1; 
	}	
	else
	{
		output_file_p4 << "++++++++ P4 RETURNS FALSE." << endl;
		return 0;
	}
	output_file_p4 << "++++++++ P4 END ++++" << endl;
}

int 
OVERLOADED_BURSAR::operator == (int x)
{
	// your code goes below:
	output_file_p4 << "++++++++ P4 START ++++" << endl;
	output_file_p4 << "++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR == METHOD FOR OBJECT "<< objectName<<": "<< endl;
	output_file_p4 << "++++++++ P4 CHECKING IF NUMBER OF STUDENTS IN "<<objectName<<" IS EQUAL TO "<<x;
	//Checking if noof students in object OVERLOADED_BURSAR1(the one we are calling the method on), is equal to 
	//the integer x	
	if(n == x)
	{
		output_file_p4 << "++++++++ P4 RETURNS TRUE." << endl;
		return 1; 
	}	
	else
	{
		output_file_p4 << "++++++++ P4 RETURNS FALSE." << endl;
		return 0;
	}
	output_file_p4 << "++++++++ P4 END ++++" << endl;
}

int 
OVERLOADED_BURSAR::operator > (OVERLOADED_BURSAR Obj)
{
	
	int max1, max2, i, j;
	output_file_p4 << "++++++++ P4 START ++++" << endl;
	output_file_p4 << "++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR > METHOD FOR OBJECT "<< objectName<<": "<< endl;
	output_file_p4 << "++++++++ P4 CHECKING IF MAX IN "<<objectName<<" > MAX IN "<<Obj<<":  "<<endl;
	//Finding max of all grades for student1, using as a template method for finding max from sample_p1.h	
	max1 = grades[0][0];
		for(i = 0; i < n; i++)
		{
			for(j = 0;j<p;j++)
			{
				if (max1 < grades[i][j])	
				{
					max1 = grades[i][j];
				}
				else{}
			}
		}
	//Finding max of all grades for student1, using as a template method for finding max from sample_p1.h, accessing
	//the grades array, and the n, and p attributes inside Obj (object representing student2)
	max2 = Obj.grades[0][0];
		for(i = 0; i < Obj.n; i++)
		{
			for(j = 0;j<Obj.p;j++)
			{
				if (max2 < Obj.grades[i][j])	
				{
					max2 = Obj.grades[i][j];
				}
				else{}
			}
		}
	
	if(max1 > max2)
	{
		output_file_p4 << "++++++++ P4 RETURNS TRUE." << endl;
		return 1; 
	}	
	else
	{
		output_file_p4 << "++++++++ P4 RETURNS FALSE." << endl;
		return 0;
	}
	output_file_p4 << "++++++++ P4 END ++++" << endl;
}

void 
OVERLOADED_BURSAR::operator = (OVERLOADED_BURSAR Obj)
{
	// your code goes below:
}

OVERLOADED_BURSAR 
OVERLOADED_BURSAR::operator + (OVERLOADED_BURSAR Obj)
{
	OVERLOADED_BURSAR TEMP; // create a temp object
	strcpy(TEMP.objectName, "TEMP");
	// your code goes below:

	return TEMP;
}
