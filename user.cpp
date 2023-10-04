#include "user.h"

  //Primary Constructor
  User::User(std::size_t id, std::string name, std::size_t year, std::size_t zip, std::vector<std::size_t> friends) {
    _id = id;
    _name = name;
    _year = year;
    _zip = zip;
    _friends = friends;
  }

  //Accessors
  
  std::size_t const User::getId() {return _id;}

  std::string const User::getName() {return _name;}

  std::size_t const User::getYear() {return _year;}

  std::size_t const User::getZip() {return _zip;}

  std::vector<std::size_t> & User::getFriends() {return _friends;}

  //Mutators

  void User::addFriend(std::size_t id) {
  	_friends.push_back(id);
  }

  void User::deleteFriend(std::size_t id) {
  	_friends.erase(std::remove(_friends.begin(), _friends.end(), id), _friends.end());
  }