#include <iostream>
#include <vector>

using namespace std;


// Simplified demonstration of QT's PARENT-child relationship for memory management

class Base
{
public:
   Base(string nm, Base* ptr = nullptr)
   {
      name = nm;
      if (ptr)
      {
         ptr->childs.push_back(this);
         parent = ptr->name;
      }
   }

   ~Base()
   {
      cout << "Deleted " << name << "\n";
      for (auto el : childs)
      {
         delete el;
      }
   }


   string name;
   vector<Base*> childs;
   string parent;
};


class Widget_t1 : public Base
{
public:
   Widget_t1(string nm, Base* ptr = nullptr)
      : Base{nm, ptr}
   {
   }
};

class Widget_t2 : public Widget_t1
{
public:
      Widget_t2(string nm, Widget_t1* p = nullptr)
         : Widget_t1{nm, p}
      {

      }
};


int main(int argc, char** argv)
{
   Base base{"base"};
   Widget_t1* widget1 = new Widget_t1{"widget1", &base};
   Widget_t1* widget2 = new Widget_t1{"widget2", &base};
   Widget_t2* widget3 = new Widget_t2{"widget3", widget2};




// log

   cout  << base.name << "' parent: " << base.parent << "\n";
   cout << base.name << "' childs: ";
   for (auto child : base.childs)
   {
      cout << child->name << " ";
   }
   cout << "\n";
   cout << "\n";


   cout  << widget1->name << "' parent: " << widget1->parent << "\n";
   cout << widget1->name << "' childs: ";
   for (auto child : widget1->childs)
   {
      cout << child->name << " ";
   }
   cout << "\n";
   cout << "\n";

   cout  << widget2->name << "' parent: " << widget2->parent << "\n";
   cout << widget2->name << "' childs: ";
   for (auto child : widget2->childs)
   {
      cout << child->name << " ";
   }
   cout << "\n";
   cout << "\n";
   cout << "\n";
}