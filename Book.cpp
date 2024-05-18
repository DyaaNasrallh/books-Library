#include"Book.h"
int Book::count=0;
Book::Book(){
    title="";
    isbn="";
    count++;
    id=count;
    category="";
    averageRating=0.0;
    //author=new User;
    numRating=0;
    sumRating=0.0;
    //hasAuthor=false;
}
Book::Book(string titel,string isbn,string category){
    this->title=titel;
    this->isbn=isbn;
    this->category=category;
    this->sumRating=sumRating;
    this->numRating;
    count++;
    id=count;
    averageRating=0.0;
    numRating=0;
    sumRating=0.0;
    //hasAuthor=false;
    //author=new User;
}
Book::Book(const Book & book){
    title=book.title;
    isbn=book.isbn;
    category=book.category;
    id=book.id;
    sumRating=book.sumRating;
    numRating=book.numRating;
    averageRating=book.averageRating;
    author=book.author;
}
void Book::setTitle(string title){
this->title=title;
}
string Book::getTitle() const{
    return title;
}
void Book::setIsbn(string isbn){
    this->isbn=isbn;
}
string Book::getIsbn()const{
    return isbn;
}
void Book::setId(int id){
    this->id=id;
}
int Book::getId()const{
    return id;
}
void Book::setCategory(string category ){
   this->category=category;
}
string Book::getCategory()const{
   return category;
}
double Book::getAverageRating () const{
    return averageRating;
}
void Book::setAuthor(const User & user){
   //hasAuthor=true;
    author=user;
}
User Book::getAuthor()const{
    return author;
}
int Book::getNumRating()const{
    return numRating;
}
double Book::getSumRating()const{
    return sumRating;
}
void Book::rateBook(double rate){
   if(rate<=5&&rate>0){
   numRating++;
   sumRating+=rate;
   averageRating=sumRating/numRating;}
}
bool Book:: operator==(const Book& book){
    if(id!=book.id||title!=book.title||category!=book.category)
    return true;
    return false;
}
istream &operator>>( istream & input,Book &book){
cout<<"Enter the book name :";input>>book.title;
cout<<"Enter the book category :";input>>book.category;
cout<<"Enter the book isbn :";input>>book.isbn;
return input;
}
ostream &operator<<(ostream &output,const Book &book){
output<<"========Book "<<book.id<<" info========"<<endl;
output<<"Book name:"<<book.getTitle()<<"| Book category :"<<book.getCategory();
output<<"| book rates :"<<book.getAverageRating()<<"| isbn :"<<book.getIsbn()<<endl;
if(book.getAuthor().getName()!="")
output<<(book.author);
output<<"=================="<<endl;
return output;
}
/*Book::~Book(){
    delete author;
}*/