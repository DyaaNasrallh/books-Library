#include"UserList.h"
UserList::UserList(){
    capacity=0;
    usersCount=0;
}
UserList::UserList(int capaciy){
    this->capacity=capacity;
    users=new User[capacity];
    usersCount=0;
}
void UserList::addUser(User &user){
    if(usersCount<capacity){
        users[usersCount]=user;
        users[usersCount].setId(usersCount+1);
        usersCount++;}
    else
    cout<<"*******the list are full*******\n";    
}
User* UserList::searchUser(string userName ){
for(int i=0;i<capacity;i++){
    if(users[i].getName()==userName)
    return &users[i];
}
return nullptr;
}
User* UserList::searchUser(int userId ){
for(int i=0;i<capacity;i++){
    if(users[i].getId()==userId)
    return &users[i];
}
return nullptr;
}
void UserList::deleteUser(int id){
    for (int i=0;i<usersCount;i++){
        if(users[i].getId()==id)
        {
            while(i<usersCount-1){
                users[i]=users[i+1];
                users[i].setId(i+1);
                i++;
            }
            usersCount--;
            capacity--;
            break;
        }
    }

}
ostream&operator<<(ostream& output,const UserList&userList){
   for(int i=0;i<userList.usersCount;i++){
    output<<userList.users[i];
   } 
   return output;
}
UserList::~UserList(){
    delete[] users;
}