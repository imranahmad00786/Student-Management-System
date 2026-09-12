#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Student{
	int id;
	string name;
	float marks;
};

// Save data into file

void saveData(Student students[],int count)
{
	ofstream file("students.txt");
	
	for(int i=0;i<count;i++)
	{
		file << students[i].id << " " << students[i].name << " " << students[i].marks << endl;
	}
	
	file.close();
	
	cout << "\nData saved successfully!\n";
}

// Load data from file
int loadData(Student students[])
{
	ifstream file("students.txt");
	
	int count = 0;
	
	while(file >> students[count].id >> students[count].name >> students[count].marks)
	{
		count++;
	}
	
	file.close();
	
	return count;
}

int main()
{
	Student students[100];
	
	// Load previous data
	int count = loadData(students);
	
	int choice;
	
	do{
		cout << "===================================================\n";
		cout << "\n=========== STUDENT MANAGEMENT SYSTEM ===========\n";
		cout << "\n====================================================\n";
		cout << "1. Add Student\n";
		cout << "2. Search Student\n";
		cout << "3. Update Student\n";
		cout << "4. Delete Student\n";
		cout << "5. Display All Students\n";
		cout << "6. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		
		// 1.Add Student
		if(choice == 1)
		{
			cout << "Enter Student ID: ";
			cin >> students[count].id;
			cout << "Enter Student Name: ";
			cin.ignore();
			getline(cin,students[count].name);
			cout << "Enter Student Marks: ";
			cin >> students[count].marks;
			
			count++;
			
			cout << "Student added successfully!\n";
		}
		
		// 2.Search Student
		else if(choice == 2)
		{
			int searchID;
			bool found = false;
			
			cout << "\nEnter student ID to search: ";
			cin >> searchID;
			
			for(int i=0; i < count; i++)
			{
				if(students[i].id == searchID)
				{
					cout << "\nStudent Found!\n";
					cout << "ID: " << students[i].id << endl;
					cout << "Name: " << students[i].name << endl;
					cout << "Marks: " << students[i].marks << endl;
					
					found = true;
					break;
				}
			}
		if(!found){
			cout << "Student not found!\n";
		}
	}
	
	// 3.Update Student
	else if(choice == 3)
	{
		int updateID;
		bool found = false;
		
		cout << "\nEnter Student ID to update: ";
		cin >> updateID;
		for(int i=0;i<count;i++)
		{
			if(students[i].id == updateID)
			{
				cout << "Enter New Name: ";
				cin.ignore();
				getline(cin,students[i].name);
				cout << "Enter New Marks: ";
				cin >> students[i].marks;
				cout << "Student updated successfully!\n";
				
				found = true;
				break;
			}
		}
		if (!found)
		{
			cout << "Student not found!\n";
		}
	}
	
	// 4.Delete Student
	else if(choice == 4)
	{
		int deleteID;
		bool found = false;
		
		cout << "Enter Student ID to delete: ";
		cin >> deleteID;
		
		for(int i=0;i<count;i++)
		{
			if(students[i].id == deleteID)
			{
				for(int j=i;j<count-1;j++)
				{
					students[j] = students[j+1];
				}
				count--;
				
				cout << "Student Deleted Successfully!\n";
				
				found = true;
				break;	
			}
		}
		if(!found)
		{
			cout << "Student not found!\n";
		}
	}
	
	// 5.Display Students
	else if(choice == 5)
	{
		cout << "\n=======All Students=======\n";
		for(int i=0;i<count;i++)
		{
			cout << "\nStudent " << i+1 << endl;
			cout << "ID: " << students[i].id << endl;
			cout << "Name: " << students[i].name << endl;
			cout << "Marks: " << students[i].marks << endl;
		}
	}
	
	// 6.Exit
	else if(choice == 6)
	{
		cout << "\nProgram closed.\n";
	}
	
	// Invalid Choice
	else
	{
		cout << "\nInvalid Choice!\n";
	}
	
	
	}while(choice != 6);
	
	return 0;
}
