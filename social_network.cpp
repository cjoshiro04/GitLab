#include <iostream>
#include "user.h"
#include "network.h"

int main () {

  network network;
  bool running = true;

  while(running) {
    std::cout << "Social Network Menu:" << std::endl;
    std::cout << "1. Add a User" << std::endl;
    std::cout << "2. Add Friend Connection" << std::endl;
    std::cout << "3. Remove Friend Connection" << std::endl;
    std::cout << "4. Print Users" << std::endl;
    std::cout << "5. Print Friends" << std::endl;
    std::cout << "6. Write to File" << std::endl;
    std::cout << "7. Exit" << std::endl;

    int option;
    std::cout << "Please pick an option (type number of option)";
    std::cin >> option;

    if (option == 1) {
      std::string firstName;
      std::string lastName;
      int year;
      int zip;
      std::cout << "Please enter name (first last), birth year, and zip code: ";
      std::cin >> firstName >> lastName >> year >> zip;
      std::string fullName = firstName + " " + lastName;
      std::size_t id = network.numUsers();
      network.addUser(User(id, fullName, year, zip, {}));
    } 
    else if (option == 2) {
      std::string names;
      std::string first1;
      std::string last1;
      std::string first2;
      std::string last2;
      std::string user1;
      std::string user2;
      int success;
      std::cout << "Please enter two usernames of your friends: ";
      std::cin >> first1 >> last1 >> first2 >> last2;
      user1 = first1 + " " + last1;
      user2 = first2 + " " + last2;
      success = network.addConnection(user1, user2);
      if (success == 0) {
      	std::cout << "connection added successfully" << std::endl;
      }
      else {
      	std::cout << "failed to add connection :( " << std::endl;
      }
    } 
    else if (option == 3) {
      std::string username1;
      std::string username2;
      std::string names;
      std::string first1;
      std::string last1;
      std::string first2;
      std::string last2;
      std::cout << "Please enter two usernames to remove the connection between them: ";
      std::cin >> first1 >> last1 >> first2 >> last2;
      username1 = first1 + " " + last1;
      username2 = first2 + " " + last2;
      int success = network.removeConnection(username1, username2);
      if (success == 0) {
      	std::cout << "connection removed successfully" << std::endl;
      }
      else {
      	std::cout << "failed to remove connection :( " << std::endl;
      }
    } 
    else if (option == 4) {
      for (std::size_t i = 0; i < network.numUsers(); i++) {
  	    //write out num users
  	    if (i==0) {
  	    std::cout << std::to_string(network.numUsers()) << std::endl;
  	    }
        User* curUser = network.getUser(i);
        std::cout << std::to_string(curUser->getId()) << std::endl;
        std::cout << "	" + curUser->getName() << std::endl;
        std::cout << "	" + std::to_string(curUser->getYear()) << std::endl;
        std::cout << "	" + std::to_string(curUser->getZip()) << std::endl;
        std::cout << "	";
        for (std::size_t k = 0; k < (curUser->getFriends()).size(); k++) { 
		  std::cout << std::to_string((curUser->getFriends())[k]) << " ";
	    }
	    std::cout << std::endl;
      }
    } 
    else if (option == 5) {
      std::string first;
      std::string last;
      std::string username;
      std::cout << "Enter a username to print friends: ";
      std::cin >> first >> last;
      username = first + " " + last;
      std::cout << "username: " << username << std::endl;
      std::size_t userId = network.getId(username);
      User* user = network.getUser(userId);
      std::cout << "Id    Name    Year    Zip" << std::endl;
      std::cout << "=========================" << std::endl;
      std::vector<std::size_t> friendsVector = user->getFriends();
      for (std::size_t i = 0; i < user->getFriends().size(); i++) {
      	std::size_t curUserId = friendsVector[i];
      	User* curUser = network.getUser(curUserId);
      	if (user != nullptr) {
      	  std::cout << std::to_string(curUser->getId()) << "	";
      	  std::cout << curUser->getName() << "	";
      	  std::cout << std::to_string(curUser->getYear()) << "	";
      	  std::cout << std::to_string(curUser->getZip()) << "	";
      	}
      	else {
      		continue;
      	}
      }
      std::cout << std::endl;
    } 
    else if (option == 6) {
      std::string filename;
      std::cout << "Enter a filename to write to: ";
      std::cin >> filename;
      int success = network.writeUsers(filename.c_str());
      if (success == 0) {
        std::cout << "Data written to file successfully!" << std::endl;
      } 
      else {
        std::cout << "Failed writing to file." << std::endl;
      }
    } 
    else if (option == 7) {
      std::cout << "Exiting program..." << std::endl;
      running = false;
      break;
    } 
    else {
      return -1;
    }
  }
  return 0;
}