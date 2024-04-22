#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

struct transaction_slip
{
    string date;
    long int bid;
    long int srno;
    long int mid;
    int type;
    int access;
};

class Library
{
private:
    long int book_id; // Unique identifier
    long int serial_no; // Unique identifier
    string title;
    string author;
    string publisher;
    float price; // In Indian Rupees
    int noc; // Number of copies of a book

public:
    Library(long int bid, long int sr, string t, string a, string pub, float cost, int nc)
        : book_id(bid), serial_no(sr), title(t), author(a), publisher(pub), price(cost), noc(nc) {}

    long int getBookId() const { return book_id; }
    long int getSerialNo() const { return serial_no; }
    int getNumOfCopies() const { return noc; }
};

class Member
{
private:
    int member_type; // 0 for student and 1 for faculty
    long int member_id; // Unique identifier
    string name;
    string email;
    string addr;
    int nob; // Number of books borrowed

public:
    Member(int mt, long int mid, string n, string e, string ar)
        : member_type(mt), member_id(mid), name(n), email(e), addr(ar), nob(0) {}

    long int getMemberId() const { return member_id; }
    int getNumOfBooksBorrowed() const { return nob; }
    void incrementNumOfBooksBorrowed() { nob++; }
    void decrementNumOfBooksBorrowed(){nob--;}
    int getMemberType() const { return member_type; }
};

class Transaction
{
private:
    transaction_slip slipdet;

public:
    Transaction(transaction_slip s) : slipdet(s) {}

    int borrow(Library &lob, Member &mob)
    {
        if (mob.getMemberId() == slipdet.mid && lob.getBookId() == slipdet.bid && lob.getSerialNo() == slipdet.srno)
        {
            mob.incrementNumOfBooksBorrowed();

            if (mob.getMemberType() == 0 && mob.getNumOfBooksBorrowed() > 2)
                return 0;
            else if (mob.getMemberType() == 1 && mob.getNumOfBooksBorrowed() > 10)
                return 0;
            else if (slipdet.access > lob.getNumOfCopies())
                return 0;
            else
            {
                slipdet.access += 1;
                return 1;
            }
        }
        else
            return 0;
    }
    int returnBook(Library &lob, Member &mob)
    {
        if (mob.getMemberId() == slipdet.mid && lob.getBookId() == slipdet.bid && lob.getSerialNo() == slipdet.srno)
        {
            mob.decrementNumOfBooksBorrowed();
            slipdet.access -= 1;

            return 1; // Book returned successfully
        }
        else
            return 0; // Book return failed
    }
};

int main()
{
    // Create a Library object
    Library library1(1001, 12345, "Book Title", "Author Name", "Publisher", 20.5, 10);

    // Create a Member object
    Member member1(0, 123, "John Doe", "john@example.com", "1234 Street, City, Country");

    // Create a Transaction object
    transaction_slip slip = {"2023-09-25", 1001, 12345, 123, 0, 1}; // Sample transaction slip
    Transaction transaction(slip);

    // Attempt to borrow a book
    int result = transaction.borrow(library1, member1);

    if (result)
        cout << "Book borrowed successfully." << endl;
    else
        cout << "Unable to borrow the book." << endl;

    return 0;
}
