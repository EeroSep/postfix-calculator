#include <iostream>
#include "Extended_stack.h"
#include "utility.h"


char get_command()
{
   char command;
   bool waiting = true;
   std::cout << "Select command and press <Enter>:";

   while (waiting) {
      std::cin >> command;
      command = tolower(command);
      if (command == '?' || command == '=' || command == '+' ||
          command == '-' || command == '*' || command == '/' ||
          command == 'q' ) waiting = false;


      else {
         std::cout << "Please enter a valid command:"   << std::endl
              << "[?]push to stack   [=]print top" << std::endl
              << "[+] [-] [*] [/]   are arithmetic operations" << std::endl
              << "[Q]uit." << std::endl;
      }
   }
   return command;
}
bool do_command(char command, Extended_stack &stack)
{
   double p, q;
   switch (command){
   case '?':
    std::cout << "Enter a real number: " << std::flush;
    std::cin >> p;
    if (stack.push(p) == overflow) {
        std::cout << "Stack overflow, number lost." << std::endl;
        
    }
    break;
    case '=':
    if (stack.top(p) == underflow) {
        std::cout << "Stack empty." << std::endl;
    }
    else {
        std::cout << p << std::endl;
    }
    break;
    case '+':
    if (stack.top(p) == underflow) {
        std::cout << "Stack empty." << std::endl;
    }
    else {
        stack.pop();
        if (stack.top(q) == underflow) {
            std::cout << "Stack has only one number." << std::endl;
            stack.push(p);
        }
        else {
            stack.pop();
            if (stack.push(q + p) == overflow) {
                std::cout << "Stack overflow, result lost." << std::endl;
            }
        }
    }
    break;
    case 'q':
        std::cout << "Calculation finsihed." << std::endl;
        return false;
    break;
    default:
        std::cout << "Command not implemented." << std::endl;
    break;
   }
    return true;
}
int main() {
    
    Extended_stack stored_numbers;
    introduction();
    instructions();
    while (do_command(get_command(), stored_numbers));


    return 0;
}