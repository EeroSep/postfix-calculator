#pragma once

typedef double Stack_entry;
enum Error_code { success, underflow, overflow };
constexpr int maxstack = 100;

class Extended_stack {
public:
   Extended_stack();
   Error_code pop();
   Error_code push(const Stack_entry &item);
   Error_code top(Stack_entry &item) const;
   bool empty() const;
   void clear(); 
   bool full() const; 
   int size() const; 

private:
   int count;
   Stack_entry entry[maxstack];
};