#include <iostream>
#include <mutex>
using namespace std;


class Singleton
{
  private :
    Singleton();
    static Singleton* obj;
  
  public :
      static Singleton &GetInstance()
      {
        if(!obj)
        {
         // mutex _mutex;
         // lock_guard<mutex> _lock(_mutex);
         // if(!obj)
          //{            
            obj = new Singleton();
         // }
        }
        
        return *obj;
      }
};  
