
#include <iostream>
#include <stack>

using namespace std;

int main() {
  stack < int > stack_value; // definiujemy stosy wartosci i operatorow
  stack < char > stack_operator;
  char token;
  char op;
  int value1, value2, brackets = 0;
  const int u_enter = 13; //kod ascii 13 - wczytujemy wyrazenie do nacisniecia ENTER

  cin >> token;
  while (token != u_enter) {
    if (token >= '0' && token <= '9') {
      stack_value.push(token - '0');
    }
    if (token == '+' || token == '-' || token == '*' || token == '/') {
      stack_operator.push(token);
    }
    if (token == '(') {
      brackets++;
    } else if (token == ')') {
      brackets--;
      value1 = stack_value.top();
      stack_value.pop();
      value2 = stack_value.top();
      stack_value.pop();
      op = stack_operator.top();
      stack_operator.pop();
      if (op == '+') {
        stack_value.push(value2 + value1);
      }
      if (op == '-') {
        stack_value.push(value2 - value1);
      }
      if (op == '*') {
        stack_value.push(value2 * value1);
      }
      if (op == '/') {
        if (value1 != 0)
          stack_value.push(value2 / value1);
        else {
          cout << "NaN";
          return 1;
        }

      }
      if (brackets == 0) {
        break;
      }
    }
    cin >> token;
  }

  cout << stack_value.top() << endl; // na wyjsciu zostaje wyswietlony wynik dzialan
  return 0;
}






