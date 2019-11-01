using System;
using System.Collections.Generic;
using System.Text;
using System.Text.RegularExpressions;
using System.IO;

namespace Automato{

    class Program{
        
        static void Main(string[] args){

            int status = 0;
            string[] argument = args;
            string data = "";

            List<string> dataParts = new List<string>();
            List<string> expressions = new List<string>();
            List<string> result = new List<string>();


            try{
                StreamReader sr = new StreamReader(argument[0]);
                while(!sr.EndOfStream){
                    data = sr.ReadLine();  
                    expressions.Add(data);
                }
                
            }
            catch{
                foreach(string arg in argument){
                    if(arg != null){
                        expressions.Add(arg);
                    }
                    
                }
                
            }

            foreach(string expression in expressions){
                string[] elements = expression.Split(' ');
                foreach(string elem in elements){
                    dataParts.Insert(dataParts.Count, elem);
                    break;
                }
            }

            

            const string expr01 = @"^[0-9]+$";
            const string expr02 = @"-";
            const string expr03 = @"\+";
            const string expr04 = @"\*";
            const string expr05 = @"\/";


            foreach(string part in dataParts){
                if(@Regex.IsMatch(part, expr01) && status == 0){
                    result.Add("<numero, "+part+">");
                    status = 1;
                    continue;
                }
                if(@Regex.IsMatch(part, expr02) && status == 1){
                    result.Add("<subtração,>");
                    status = 0;
                    continue;
                }
                if(@Regex.IsMatch(part, expr03) && status == 1){
                    result.Add("<soma,>");
                    status = 0;
                    continue;
                }
                if(@Regex.IsMatch(part, expr04) && status == 1){
                    result.Add("<multiplicação,>");
                    status = 0;
                    continue;
                }
                if(@Regex.IsMatch(part, expr05) && status == 1){
                    result.Add("<divisão,>");
                    status = 0;
                    continue;
                }
                else{
                    foreach(string expr in expressions){
                        Console.Write(expr);
                        Console.Write(" ");
                    }
                    Console.WriteLine("Expressão não reconhecida");
                    return;
                }
                
            }

            foreach(string res in result){
                Console.WriteLine(res);
            }

            return;
        
            
        }

    }
}
