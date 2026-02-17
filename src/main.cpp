#include <iostream>
#include "Extended_stack.h"
#include "utility.h"
#include <cmath>
#include <string>
#include <vector>
#include <sstream>

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
          command == 'q' || command == 'x' || command == 's' ||
          command == 'a' || command == '%' || command == '^' ||
          command == 'v') waiting = false;


      else {
         std::cout << "Please enter a valid command:"   << std::endl
              << "[?]push to stack   [=]print top" << std::endl
              << "[+] [-] [*] [/]   are arithmetic operations" << std::endl
              << "[x]Exchange [s]sum [a]average [%]modulo [^]power [v]square root" << std::endl
              << "[Q]uit." << std::endl;
      }
   }
   return command;
}
bool do_command(char command, Extended_stack &stack)
{
   double p, q;
   double sum = 0;
   int count = 0;
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

    case 'a':
    count = stack.size();
    if (stack.top(p) == underflow) {
        std::cout << "Stack empty." << std::endl;
        break;
    }
    while (stack.top(p) != underflow) {
        sum += p;
        stack.pop();
    }
    if (stack.push(sum / count) == overflow) {
        std::cout << "Stack overflow, average lost." << std::endl;
    }
    break;

    case '%':
    if (stack.top(p) == underflow) {
        std::cout << "Stack empty." << std::endl;
        break;
    }
    stack.pop();
    if (stack.top(q) == underflow) {
        std::cout << "Stack has only one number." << std::endl;
        stack.push(p);
        break;
    }
    stack.pop();
    if (p == 0) {
        std::cout << "Division by zero." << std::endl;
    }
    else if (stack.push(std::fmod(q, p)) == overflow) {
        std::cout << "Stack overflow, result lost." << std::endl;
    }
    break;
    case '^':
    if (stack.top(p) == underflow) {
        std::cout << "Stack empty." << std::endl;
        break;
    }
    stack.pop();
    if (stack.top(q) == underflow) {
        std::cout << "Stack has only one number." << std::endl;
        stack.push(p);
        break;
    }
    stack.pop();
    if (stack.push(std::pow(q, p)) == overflow) {
        std::cout << "Stack overflow, result lost." << std::endl;
    }
    break;
    case 'v':
    if (stack.top(p) == underflow) {
        std::cout << "Stack empty." << std::endl;
        break;
    }
    stack.pop();
    if (p < 0) {
        std::cout << "Cannot take square root of a negative number." << std::endl;
    }
    else if (stack.push(std::sqrt(p)) == overflow) {
        std::cout << "Stack overflow, result lost." << std::endl;
    }
    break;
    default:
        std::cout << "Command not implemented." << std::endl;
    break;
   }
    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: laskin -p for prompts or laskin RPN" << std::endl;
        return 1;
    }

    Extended_stack stored_numbers;

    if (std::string(argv[1]) == "-p") {
        introduction();
        instructions();
        while (do_command(get_command(), stored_numbers));
        return 0;
    }
    std::istringstream iss(argv[1]);
    std::string token;
    while (iss >> token) {
        try {
            double num = std::stod(token);
            if (stored_numbers.push(num) == overflow) {
                std::cout << "Stack overflow, number lost." << std::endl;
            }
        }
        catch (const std::invalid_argument&) {
            for (char command : token) {
                if (!do_command(command, stored_numbers)) {
                    return 0;
                }
            }
        }
    }

    return 0;
}