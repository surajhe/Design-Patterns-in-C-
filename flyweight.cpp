//Program tested on Microsoft Visual Studio 2008 - Zahid Ghadialy
//Flyweight is part of Structural Patterns
//Structural Patterns deal with decoupling the interface and implementation of classes and objects
//A Flyweight uses sharing to support large numbers of fine-grained objects efficiently. 

//We will take an example of charachter class. Each charachter is unique and can have different size
//but the rest of the features will remain the same.

#include<iostream>
#include<string>
#include<map>

using namespace std;

// The 'Flyweight' abstract class
class Character
{
public:
  virtual void Display(int pointSize) = 0;

protected:
  char symbol_;
  int width_;
  int height_;
  int ascent_;
  int descent_;
  int pointSize_;
};

// A 'ConcreteFlyweight' class
class CharacterA : public Character
{
public:
  CharacterA()
  {
    symbol_    = 'A';
    width_     = 120;
    height_    = 100;
    ascent_    = 70;
    descent_   = 0;
    pointSize_ = 0; //initialise
  }
  void Display(int pointSize)
  {
    pointSize_ = pointSize;
    cout<<symbol_<<" (pointsize "<<pointSize_<<" )"<<endl;
  }
};

// A 'ConcreteFlyweight' class
class CharacterB : public Character
{
public:
  CharacterB()
  {
    symbol_    = 'B';
    width_     = 140;
    height_    = 100;
    ascent_    = 72;
    descent_   = 0;
    pointSize_ = 0; //initialise
  }
  void Display(int pointSize)
  {
    pointSize_ = pointSize;
    cout<<symbol_<<" (pointsize "<<pointSize_<<" )"<<endl;
  }
};

//C, D, E,...

// A 'ConcreteFlyweight' class
class CharacterZ : public Character
{
public:
  CharacterZ()
  {
    symbol_    = 'Z';
    width_     = 100;
    height_    = 100;
    ascent_    = 68;
    descent_   = 0;
    pointSize_ = 0; //initialise
  }
  void Display(int pointSize)
  {
    pointSize_ = pointSize;
    cout<<symbol_<<" (pointsize "<<pointSize_<<" )"<<endl;
  }
};

// The 'FlyweightFactory' class
class CharacterFactory
{
public:
  virtual ~CharacterFactory()
  {
    while(!characters_.empty())
    {
      map<char, Character*>::iterator it = characters_.begin();
      delete it->second;
      characters_.erase(it);
    }
  }
  Character* GetCharacter(char key)
  {
    Character* character = NULL;
    if(characters_.find(key) != characters_.end())
    {
      character = characters_[key];
    }
    else
    {
      switch(key)
      {
      case 'A':
        character = new CharacterA();
        break;
      case 'B':
        character = new CharacterB();
        break;
      //...
      case 'Z':
        character = new CharacterZ();
        break;
      default:
        cout<<"Not Implemented"<<endl;
        throw("Not Implemented");
      }
      characters_[key] = character;
    }
    return character;
  }
private:
  map<char, Character*> characters_;
};


//The Main method
int main()
{
  string document = "AAZZBBZB";
  const char* chars = document.c_str();

  CharacterFactory* factory = new CharacterFactory;

  // extrinsic state
  int pointSize = 10;

  // For each character use a flyweight object
  for(size_t i = 0; i < document.length(); i++)
  {
    pointSize++;
    Character* character = factory->GetCharacter(chars[i]);
    character->Display(pointSize);
  }

  //Clean memory
  delete factory;

  return 0;
}
