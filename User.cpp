#include"User.h"
int User::count =0;
User::User(){
    name="";
    age=0;
    count++;
    id=count;
    password="";
    email="";
}
User::User( string n,int a,string p,string e){
name=n;
age=a;
password=p;
email=e;
count++;
id=count;
}
//copy constructor
User::User(const User & user){
    name=user.name;
    age=user.age;
    password=user.password;
    email=user.email;
    id=user.id;
}
void User::setName(string n ){
    name=n;
}
void User::setAge(int a){
    age=a;
}
void User::setEmail(string e){
    email=e;
}
void User::setId(int id){
    this->id=id;
}
void User::setPassword(string password){
    this->password=password;
}
string User::getName() const{
    return name;
}
int User::getAge() {
return age;
}
string User::getPassword() const{
    return password;
}
int User::getId() {
return id;
}
string User::getEmail() const{
    return email;
}
 bool User::operator==(const User& user ){
    if(name!=user.name||id!=user.id||age!=user.age||email!=user.email)
    return false;
    return true;
 }
 istream&operator>>(istream &input,User & user){
    cout<<"Enter user name :";input>>user.name;
    cout<<"Enter user password :";input>>user.password;
    cout<<"Enter user Age :";input>>user.age;
    cout<<"Enter user Email :";input>>user.email;
    return input;
 }
 ostream&operator<<(ostream &output, User& user){
    output<<"========User "<<user.getId()<<" info========"<<endl;
    output<<user.getId()<<endl<<"user name is: "<<user.getName()<<endl<<"user email is:"<<user.getEmail()<<endl<<"user age is: "<<user.getAge()<<endl;
    return output;
 }
