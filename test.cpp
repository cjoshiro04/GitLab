#include "user.h"
#include "network.h"
#include <iostream>

void testConstructorGetter() {
  std::cout << "testConstructorGetter...";
  User* u = new User(3,"Jason Chen", 2000, 94087, {0, 1, 2});
  assert(u->getId() == 3);
  std::cout << "Passed!" << std::endl;
}

void testGetName() {
  std::cout << "testGetName...";
  User* u = new User(3,"Jason Chen", 2000, 94087, {0, 1, 2});
  assert(u->getName() == "Jason Chen");
  std::cout << "Passed!" << std::endl;
}

void testGetYear() {
  std::cout << "testGetYear...";
  User* u = new User(3,"Jason Chen", 2000, 94087, {0, 1, 2});
  assert(u->getYear() == 2000);
  std::cout << "Passed!" << std::endl;
}

void testGetZip() {
  std::cout << "testGetZip...";
  User* u = new User(3,"Jason Chen", 2000, 94087, {0, 1, 2});
  assert(u->getZip() == 94087);
  std::cout << "Passed!" << std::endl;
}

void testGetFriends() {
  std::cout << "testGetFriends...";
  User* u = new User(3,"Jason Chen", 2000, 94087, {0, 1, 2});
  assert((u->getFriends())[0] == 0);
  assert((u->getFriends())[1] == 1);
  assert((u->getFriends())[2] == 2);
  assert((u->getFriends()).size() == 3);
  std::cout << "Passed!" << std::endl;
}

void testAddFriend() {
  std::cout << "testAddFriend...";
  User* u = new User(3,"Jason Chen", 2000, 94087, {0, 1, 2});
  u->addFriend(3);
  u->addFriend(4);
  assert((u->getFriends())[0] == 0);
  assert((u->getFriends())[1] == 1);
  assert((u->getFriends())[2] == 2);
  assert((u->getFriends())[3] == 3);
  assert((u->getFriends())[4] == 4);
  assert((u->getFriends()).size() == 5);
  std::cout << "Passed!" << std::endl;
}

void testDeleteFriend() {
  std::cout << "testDeleteFriend...";
  User* u = new User(3,"Jason Chen", 2000, 94087, {0, 1, 2});
  u->deleteFriend(2);
  u->deleteFriend(1);
  assert((u->getFriends())[0] == 0);
  assert((u->getFriends()).size() == 1);
  std::cout << "Passed!" << std::endl;
}

void testAddConnection() {
  std::cout << "testAddConnection...";
  network network;
  User u1 = User(0,"Jason Chen", 2000, 94087, {});
  User u2 = User(1,"Chev Kila", 2004, 94086, {});
  network.addUser(u1);
  network.addUser(u2);
  //first adding should return 0
  int success = network.addConnection("Jason Chen", "Chev Kila");
  //repeating it should return -1
  int success2 = network.addConnection("Jason Chen", "Chev Kila");
  //case that users not in network
  int success3 = network.addConnection("Jeremy Chang", "Bryson Gomes");
  assert(success == 0);
  assert(success2 == -1);
  assert(success3 == -1);
  std::cout << "Passed!" << std::endl;
}

void testRemoveConnection() {
  std::cout << "testRemoveConnection...";
  network network;
  User u1 = User(3,"Jason Chen", 2000, 94087, {0, 1, 2});
  User u2 = User(2,"Chev Kila", 2004, 94086, {1, 2, 3});
  network.addUser(u1);
  network.addUser(u2);
  int success = network.removeConnection("Jason Chen", "Chev Kila");
  assert(success == 0);
  std::cout << "Passed!" << std::endl;
}

void testGetId() {
  std::cout << "testGetId...";
  network network;
  User u1 = User(3,"Jason Chen", 2000, 94087, {0, 1, 2});
  User u2 = User(2,"Chev Kila", 2004, 94086, {1, 2, 3});
  network.addUser(u1);
  network.addUser(u2);

  int idJason = network.getId("Jason Chen");
  int idChev = network.getId("Chev Kila");

  assert(idJason == 3);
  assert(idChev == 2);
  std::cout << "Passed!" << std::endl;
}

void testNumUsers() {
  std::cout << "testNumUsers...";
  network network;
  User u1 = User(3,"Jason Chen", 2000, 94087, {0, 1, 2});
  User u2 = User(2,"Chev Kila", 2004, 94086, {1, 2, 3});
  network.addUser(u1);
  network.addUser(u2);

  int numUsers = network.numUsers();

  assert(numUsers == 2);
  std::cout << "Passed!" << std::endl;
}

void testGetUser() {
  std::cout << "testGetUser...";
  network network;
  User u1 = User(3,"Jason Chen", 2000, 94087, {0, 1, 2});
  User u2 = User(2,"Chev Kila", 2004, 94086, {1, 2, 3});
  network.addUser(u1);
  network.addUser(u2);

  User* user1 = network.getUser(3);
  User* user2 = network.getUser(2);

  assert(user1->getName() == "Jason Chen");
  assert(user2->getName() == "Chev Kila");
  std::cout << "Passed!" << std::endl;
}

int main() {
  //user class tests
  testConstructorGetter();
  testGetName();
  testGetYear();
  testGetZip();
  testGetFriends(); 
  testAddFriend();
  testDeleteFriend();

  //network class tests
  testAddConnection();
  testRemoveConnection();
  testGetId();
  testNumUsers();
  testGetUser();
  return 0;
}