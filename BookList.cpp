#include"BookList.h"
BookList::BookList(){
  capacity=0;
  booksCount=0;
}
BookList::BookList(int capacity){
  this->capacity=capacity;
  booksCount=0;
  books=new Book[capacity];
}
void BookList::addBook(const Book& book ){
    if(booksCount<capacity){
        books[booksCount]=book;
        books[booksCount].setId(booksCount+1);
        booksCount++;}
    else
    cout<<"*******the list are full*******\n";
}
Book* BookList:: searchBook(string bookTitle){
    for(int i=0;i<booksCount;i++){
    if(books[i].getTitle()==bookTitle)
    return &books[i];
}
return nullptr;
}
Book* BookList:: searchBook(int Id){
    for(int i=0;i<booksCount;i++){
    if(books[i].getId()==Id)
    return &books[i];
}
return nullptr;
}
void BookList::deleteBook(int id){
for (int i=0;i<booksCount;i++){
        if(books[i].getId()==id)
        {
            while(i<booksCount-1){
                books[i]=books[i+1];
                books[i].setId(i+1);
                i++;
            }
            booksCount--;
            capacity--;
            break;
        }
    }
}
ostream&operator<<(ostream& output,const BookList&bookList){
   for(int i=0;i<bookList.booksCount;i++){
    output<<bookList.books[i];
   } 
   return output;
}
BookList::~BookList(){
    delete[] books;
}
Book BookList::getTheHighestRatedBook(){
    Book highes;
     highes=books[0];
for(int i=1;i<booksCount;i++){
if(highes.getAverageRating()<books[i].getAverageRating())
highes=books[i];
}
return highes;
}
void BookList::getBooksForUser( User &user){
    bool found=false;
for(int i=0;i<booksCount;i++){
    if(user==books[i].getAuthor()){
    found=true;
    cout<<books[i];}
}
if(!found)
cout<<"This Author dont has Book"<<endl;
}
Book & BookList:: operator[] (int position){
if(position<0||position>=booksCount)
cout<<"Position Error"<<endl;
else
return books[position];
}