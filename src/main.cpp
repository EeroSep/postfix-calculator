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
          command == 'q' || command == 'x' || command == 's') waiting = false;


      else {
         std::cout << "Please enter a valid command:"   << std::endl
              << "[?]push to stack   [=]print top" << std::endl
              << "[+] [-] [*] [/]   are arithmetic operations" << std::endl
              << "[x]Exchange [s]sum" << std::endl
              << "[Q]uit." << std::endl;
      }
   }
   return command;
}
bool do_command(char command, Extended_stack &stack)
{
   double p, q;
   double sum = 0;
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
    case '-':
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
            if (stack.push(q - p) == overflow) {
                std::cout << "Stack overflow, result lost." << std::endl;
            }
        }
    }
    break;
    case '*':
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
            if (stack.push(p * q) == overflow) {
                std::cout << "Stack overflow, result lost." << std::endl;
            }
        }
    }
    break;
    case '/':
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
            if (q == 0) {
                std::cout << "Division by zero." << std::endl;
            }
            else if (stack.push(q / p) == overflow) {
                std::cout << "Stack overflow, result lost." << std::endl;
            }
        }
    }
    break;
    case 'q':
        std::cout << "Calculation finished." << std::endl;
        return false;
    break;
    case 'x':
    if (stack.top(p) == underflow) {
        std::cout << "Stack empty." << std::endl;
    }
    else {
        Extended_stack temp;
        stack.pop();
        if (stack.top(q) == underflow) {
            std::cout << "Stack has only one number." << std::endl;
            stack.push(p);
        }
        else {
            stack.pop();
            stack.push(p);
            stack.push(q);
        }
    }
    break;
    case 's':
    
    if (stack.top(p) == underflow) {
        std::cout << "Stack empty." << std::endl;
        break;
    }
    while (stack.top(p) != underflow) {
        sum += p;
        stack.pop();
    }
    if (stack.push(sum) == overflow) {
        std::cout << "Stack overflow, sum lost." << std::endl;
    }
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