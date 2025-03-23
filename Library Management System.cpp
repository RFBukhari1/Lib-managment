#include <iostream>
#include <vector>
#include<fstream>
using namespace std;



class User
{   
	public:
		string name;
	    string password;
		User(string n, string p) : name(n), password(p) {}
		string getName() const { return name; }
		string getPassword() const { return password; }
		
		/*not sure if we want to add students and libranians ourselves from 
		console rather than through declaring them in main with the help of constructor
		would we use setter. If we do need setters then they will aslo be used 
		in child classes of class User*/
		
};

class Librarian : public User
{
	string id;
	
	public:
		Librarian(string n, string p, string i) : User(n, p), id(i) {}
		string getId() const { return id; }
		void printDetails() //override
		{
			cout<<"Libranian Information:"<<endl;
			cout<<"Name: "<<name<<endl;
			cout<<"Librarian Id: "<<id<<endl;
		}
		/*not sure if for deletion of something would deconstructor be used or
		something else will be used*/
};

class Student : public User
{
	string regNo;
	
	public:
		Student(string n, string p, string rg) : User(n, p), regNo(rg) {}
		string getRegNo() const { return regNo; }
		void printDetails() //override
		{
			cout<<"Student Information:"<<endl;
			cout<<"Name: "<<name<<endl;
			cout<<"Registration Number: "<<regNo<<endl;
		}
		/*same problem here as in the libranian class not sure how to delete
		the students*/
};

class Book
{
	string title;
	string author;
	string genre;
	int yearOP;
	int quantity;
	
	public:
		Book(string t, string a, string g, int yop, int q)
		{
			title = t;
    	    author = a;
    	    genre = g;
    	    yearOP = yop;
        	quantity = q;
		}
		
		void setTitle(string t) { title = t; }
		void setAuthor(string a) { author = a; }
		void setGenre(string g) { genre = g; }
		void setYearOP(int yop) { yearOP = yop; }
		void setQuantity(int q) { quantity = q; }
		
		string getTitle() const { return title; }
		string getAuthor() const { return author; }
		string getGenre() const { return genre; }
		int getYearOP() const { return yearOP; }
		int getQuantity() const { return quantity; }
};

class Library
{
	vector<Book> books;
	vector<Student*> students;
	vector<Librarian*> librarians;
	
	public:
		void addBooks(const Book& b) //add books
		{
		     books.push_back(b);
		}
		
		void addStudents(Student* s)  //add students
		{
			students.push_back(s);
		}
		
		void addLibrarians(Librarian* l)  //add librarians
		{
			librarians.push_back(l);
		}
		void addNewBooks()  //add new books into inventory
		{
				
		        string title, author,genre;
		        int YearOP,quantity;
		
		        cout << "Enter book title: ";
		        getline(cin, title);
		        cin.ignore();
		        
		        cout << "Enter author name: ";
		        getline(cin, author);
		        cin.ignore();
		         
		        cout << "Enter genre: ";
		        getline(cin, genre);
		        cin.ignore();
		        
		        cout << "Enter Year of Publiction: ";
		        cin>>YearOP;
		      
				cout << "Enter quantity (should be greater than 0): ";
                cin >> quantity;

               while (quantity <= 0)  //using while loop 
            {
                cout << "Quantity should be greater than 0, Please enter a valid quantity: ";
                cin >> quantity;
            } 
    
            cin.ignore();
    
            Book newBook(title, author, genre, YearOP, quantity);
            addBooks(newBook);
    
            cout << "Book added to the library successfully." << endl;
		}
		 
					
		void updateBookQuantity(string& title, int newQuantity)  //update quantity of book in inventory
		{
			   	
			for(Book& b : books)
			   	
			{
			   	if (b.getTitle() == title)
			   		
			   	{
			   			
			   		cout << "Current quantity of book " << title << ": " << b.getQuantity() << endl;
			  		int newQuantity;
			        cout << "Enter the quantity to add for book '" << title << "': ";
			        cin >> newQuantity;
			   		books.setQuantity(b.getQuantity() + newQuantity);
			   		cout << "Book quantity updated successfully. New quantity: " << b.getQuantity() << endl;
			   		return;
			   			
				}
			}
				
			//if the title is not found
			cout<<"Book With Title " <<title << "not found in the library" <<endl;
		}
		
		/*in display functions below remember to mention total books in library and total
		number of students and libranians registered*/
		
		void displayBooks() //display total books 
		{
	
//		        int total = 0;
//		        for (Book& b : books) 
//				{
//		            total += b.getQuantity();
//		        }
//		        cout << "Total number of books in the library: " << total << endl;
            cout << "Total number of books in the library: " << books.size() << endl;
		        
		}
		
		void displayStudents()  //display total students
		{
			cout << "Total number of students registered in the library: " << students.size() << endl;
		}
		void displayLibrarians()  //display total librarians
		{
			cout << "Total number of librarians registered in the library: " << librarians.size() << endl;
		}
		
		bool bookAvailable(const string& btitle)  //function to determine if a book is available in inventory
			 
			{
		        for (const Book& b : books) 
			    {
		            if (b.getTitle() == btitle && b.getQuantity() > 0) 
					{
		                return true;
		            }
		        }
		        return false;
            }
            
		bool searchBook(const string& btitle) //search by title
	    {
			    for (const Book& b : books) 
				{
			        if (b.getTitle() == btitle) 
					{
						
			            cout << "Book found!"<<endl;
			            cout << "Title: " << b.getTitle() << endl;
			            cout << "Author: " << b.getAuthor() << endl;
			            cout << "Genre: " << b.getGenre() << endl;
			            cout << "Year of Publication: " << b.getYearOP() << endl;
			            cout << "Quantity: " << b.getQuantity() << endl;
			            return true;
			            
			        }
	    		}
			    cout << "Book with title '" << btitle << "' not found in the library." << endl;
			    return false;
			}
			
		 vector<Book> searchBookByAuthor(const string& authorName) const  //search by author
         {
           vector<Book> booksByAuthor;

            for (const Book& b : books)
          {
             if (b.getAuthor() == authorName && b.getQuantity() > 0)
              {
                  booksByAuthor.push_back(b);
              }
        }

    return booksByAuthor;
}
//You can then call this function to search for books by a specific author and receive a list of books 
//meeting the criteria. For example:
//vector<Book> booksByAuthor = searchBookByAuthor("Author Name");

vector<Book> searchBookByGenre(const string& genreName) const  //search by genre
{
    vector<Book> booksByGenre;

    for (const Book& b : books)
    {
        if (b.getGenre() == genreName && b.getQuantity() > 0)
        {
            booksByGenre.push_back(b);
        }
    }

    return booksByGenre;
}
//You can then call this function to search for books by a specific genre and receive a list of books 
//meeting the criteria. For example:
//vector<Book> booksByGenre = searchBookByGenre("Genre Name");


//	    void deleteBooks() //delete books 
//{
//    int numBooks;
//    cout << "How many books do you want to delete? ";
//    cin >> numBooks;
//    cin.ignore(); // Clear newline character from input buffer
//
//    for (int i = 0; i < numBooks; ++i) 
//    {
//        string title;
//        cout << "Enter title of book " << (i + 1) << ": ";
//        getline(cin, title);
//
//        int copiesToDelete;
//        cout << "Enter number of copies to delete for book '" << title << "': ";
//        cin >> copiesToDelete;
//        cin.ignore(); // Clear newline character from input buffer
//
//        for (Book& book : books) 
//        {
//            if (book.getTitle() == title) 
//            {
//                int currentQuantity = book.getQuantity();
//                if (currentQuantity >= copiesToDelete) 
//                {
//                    book.setQuantity(currentQuantity - copiesToDelete);
//                    cout << copiesToDelete << " copies of book '" << title << "' deleted successfully." << endl;
//                } 
//                else 
//                {
//                    cout << "Error: Cannot delete more copies than available for book '" << title << "'." << endl;
//                }
//                break; // Stop searching after finding the book
//            }
//        }
//    }
//}

		
		void saveBook() const //file handling
		{
		}
		void loadBook() //file handling
		{
		}
		void saveStudent() const //file handling
		{
		}
		void loadStudent() //file handling
		{
		}
		void saveLibrarian() const //file handling
		{
		}
		void loadLibrarian() //file handling
		{
		}
};

//leave code after this comment alone and only work on the code above

void displayUserMenu()
{
	cout<<"1. Issue New Book\n2. Return Book\n3. Check Your Dues\n4. Logout"<<endl;
	cout<<"Enter your choice: ";
}

int main ()
{
	displayUserMenu();
}
