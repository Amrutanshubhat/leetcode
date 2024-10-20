class Solution {
public:
  bool parseBoolExpr(string expression) {
    stack<char> op, param;
    for (const char &c : expression) {
      switch (c) {
      case '(':
      case 't':
      case 'f':
        param.push(c);
        break;

      case '&':
      case '|':
      case '!':
        op.push(c);
        break;

      case ')': {

        char oper = op.top();
        op.pop();
        char res;
        while (param.top() != '(') {
          res = param.top();
          param.pop();
          switch (oper) {
          case '&': {
            if (param.top() != '(' && res == 't')
              res = param.top() == 't' ? 't' : 'f';
          } break;

          case '|': {
            if (param.top() != '(' && res == 'f')
              res = param.top() == 't' ? 't' : 'f';
          } break;

          case '!':
            res = res == 't' ? 'f' : 't';
            break;
          }
          if (param.top() == '(')
            break;
          param.top() = res;
        }
        param.pop();
        param.push(res);
      } break;
      }
    }
    return param.top() == 't' ? true : false;
  }
};
