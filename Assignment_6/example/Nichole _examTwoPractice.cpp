






/*
Write a function to print all data (name, ID, score...) from a linked list.
Assume the Student struct is from class examples.
This function takes the head of the linked list as a parameter.
*/

print studentList(Student *firstStudentPtr)
{
	index = 1;

	//fictitious table probably not necessary, but I copied it from one of his examples.
	cout << "\n NAME         ID        SCORE" << endl;

	for(Student *nodePtr = firstStudentPtr; nodePtr; nodePtr = nodePtr -> next, index++)
	{
		cout.width (5);
		cout << std::left << index;
		cout.width(10);
		cout << nodePtr -> name;
		cout.width (6);
		cout << nodePtr -> id;
		cout.setf(ios::fixed); cout.precision(2);
		cout << nodePtr -> score << endl;
	}
}

/*
Write a function that removes a student from the linked list of the student name exists.
Function prototype: void removeStudent (Student *&head, string studentName)
*/

void removeStudent(Student *&head, string studentName)
{
	Student *temp = head;

	if (temp -> name == studentName)
	{
		//shift list to left
		menu = temp -> next;
		return;
	}

	//search values in list to find value we want to delete
	while (temp -> next != nullptr)
	{
		//check if next value is target
		if (temp -> next -> name == studentName)
		{
			//saving replacement location
			Student* temp2 = temp -> next -> next;

			//restructure list
			temp -> next = temp2;
			return;
		}
		else
		{
			temp = temp -> next;
		}
	}
}

/*
Write a code segment to ask the user for the student's data and create a linked list.
The user can terminate the input by entering  a negative value for score or you can
ask the user a question.
*/

string studentName;
int id;
double score;
char exit;

Student* firstStudentPtr = 0;

while (true)
{
	cout << "Enter student name: ";
	getline(cin, name);

	cout << "Enter student ID: ";
	cin >> id;
	cin.ignore(10,1000);

	cout<<" Enter student score: ";
	cin>>score;
	cin.ignore(10,1000);

	//insert info into structs
	nextStudent -> name = name;
	nextStudent -> id = id;
	nextStudent -> score = score;

	if (firstStudentPtr == NULL)
	{
		firstStudentPtr = nextStudent;
	}
	else
	{
		nextStudent -> next = firstStudentPtr;
		firstStudentPtr = nextStudent;
	}

	cout<<"Enter q to quit: "<<endl;
	cin>>exit;

	if(exit == 'q' || exit == 'Q')
		break;
}

/*
Write a function to insert a node to a stack.
*/

//copied from module 10 studentStackPushPop.cpp example.
void push (Student *&head, Student *nodePtr)
{
	//allocate new node
	Student* temp = new Student;

	temp -> name = nodePtr -> name;
	temp -> idNumber = nodePtr -> idNumber;
	temp -> gpa = nodePtr -> gpa;

	//link new node into the list
	temp -> next = head;
	head = temp;
}

/*
Write a function to swap the content of two student nodes.
The function should take the address of the nodes as parameters.
*/

void swap (Student *& studentPtr1, Student *& studentPtr2)
{
	temp = studentPtr1;
	studentPtr1 = studentPtr2;
	studnetPtr2 = temp;
}

/*
Write your own strcat() function that takes character arrays and length as parameters.
*/

char* strcat (char *a , int length1 , char *b , int length2)
{
	int i;

	//create new arrray big enough to store a + b
	char *c = new char [length1 + length2]; //c stays at same place. length tells you how many values you can store

	//copy values of a intoi c for length 1
	for (i = 0; i < length; i++)
		c[i] = a[i];

	//copy values of b into c starting after the last location of a
	for (i ; i < length1 + length2; i++)
		//copying with proper offset for b
		c[i] = b [i-length]
	return c;
}
