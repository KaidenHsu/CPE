#include<iostream>
#include<sstream>
#include<string>
#include<stack>
using namespace std;

int main(){
    //declarations
    string str;
    int N, num, sequence[2][50] = {{0}}, *seqOld = NULL, *seqNew = NULL;
    char left, op;

    while(cin >> str >> N){ //read test cases
        stack<int> stack_num;
        stack<char> stack_op;
        stringstream ss(str);

        while(true){ //generate the two stacks
            ss >> left >> num >> op;
            stack_num.push(num);
            stack_op.push(op);
            if(op == ']') break;
        }

        while(true){
            //pop elements from the two stacks one by one
            num = stack_num.top();
            stack_num.pop();
            op = stack_op.top();
            stack_op.pop();

            if(op == ']'){ //constant sequence
                seqOld = sequence[0];
                seqNew = sequence[1];

                for(int i = 0; i < N; i++) seqNew[i] = num;
            }else if(op == '+'){ // "+" cases
                swap(seqOld, seqNew);

                seqNew[0] = num;
                for(int i = 1; i < N; i++) seqNew[i] = seqNew[i - 1] + seqOld[i - 1];
            }else if(op == '*'){ // "*" cases
                swap(seqOld, seqNew);

                seqNew[0] = num * seqOld[0];
                for(int i = 1; i < N; i++) seqNew[i] = seqNew[i - 1] * seqOld[i];
            }

            if(stack_num.empty()) break; //stack is empty
        }

        //output
        cout << seqNew[0];
        for(int i = 1; i < N; i++) cout << " " << seqNew[i];
        cout << endl;
    }
}