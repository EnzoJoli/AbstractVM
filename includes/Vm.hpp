#ifndef VM_H
#define VM_H

#include <vector>
#include <list>
#include "Parser.hpp"
#include "Error.hpp"
#include "Factory.hpp"

namespace abstract
{
    class Vm
    {
        private:
            Parser parse;
            std::map<std::string , void (abstract::Vm::*)(std::string)> command;
            std::list<IOperand*> stack;
            std::map<std::string , eOperandType> _type;
            std::vector<IOperand*> _store;
            bool _standart;
            bool _Print;
            bool _exit;
            bool _Dump;
        public:
            Vm();
            ~Vm();
            int getSize();
            std::list<IOperand*> &getStack();
            void execute(std::string input);

            int getInput();
            int getInput(std::string filepath);
            eOperandType getType(std::string arg);
            std::string getValue(std::string arg);
            bool checkType(std::string type);
            bool checkValue(std::string value);
            void Round(eOperandType type, std::string arg);

            void Null(std::string arg);
            void Push(std::string arg);
            void Pop(std::string arg);
            void Clear(std::string arg);
            void Dup(std::string arg);
            void Swap(std::string arg);
            void Dump(std::string arg);
            void Assert(std::string arg);
            void Add(std::string arg);
            void Sub(std::string arg);
            void Mul(std::string arg);
            void Div(std::string arg);
            void Mod(std::string arg);
            void Load(std::string arg);
            void Store(std::string arg);
            void Print(std::string arg);
            void Exit(std::string arg);
    };
}
#endif