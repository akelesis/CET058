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
                    expressions.Add(@"\\n");
                }
                
                int index = expressions.LastIndexOf(@"\\n");
                expressions.RemoveAt(index);
            }
            catch{
                foreach(string arg in argument){
                    if(arg != null){
                        expressions.Add(arg);
                    }
                    if(arg.Equals('*')){
                        expressions.Add("\\*");
                    }
                    
                }
                
            }

            foreach(string expression in expressions){
                string[] elements = expression.Split(' ');
                foreach(string elem in elements){
                    dataParts.Insert(dataParts.Count, elem);
                }
            }



            foreach(string part in dataParts){
                
                if((Int32.Parse(part[0].ToString()) >= 97 && Int32.Parse(part[0].ToString()) <= 122) && status == 0){
                    String identificador = "";
                    for(int i = 0; i < part.Length; i++){
                        if((Int32.Parse(part[i].ToString()) >= 97 && Int32.Parse(part[i].ToString()) <= 122) && status == 0){
                            identificador = identificador+part[i];
                            status = 1;
                        }
                        if((Int32.Parse(part[i].ToString()) >= 65 && Int32.Parse(part[i].ToString()) <= 90) && status == 1){
                            identificador = identificador+part[i];
                        }
                        if(Int32.Parse(part[i].ToString()) >= 97 && Int32.Parse(part[i].ToString()) <= 122 && status == 1){
                            identificador = identificador+part[i];
                        }
                        if(Int32.Parse(part[i].ToString()) == 95 && status == 1){
                            identificador = identificador+part[i];
                        }
                    }
                    result.Add("<identificador, "+identificador+">");
                    continue;
                }
                if(Int32.Parse(part) == 52 && status == 1){
                    result.Add("<multiplicacao,>");
                    status = 0;
                    continue;

                }
                if(Int32.Parse(part) == 53 && status == 1){
                    result.Add("<adição,>");
                    status = 0;
                    continue;
                }
                if(Int32.Parse(part) == 55 && status == 1){
                    result.Add("<subtração,>");
                    status = 0;
                    continue;
                }
                if(Int32.Parse(part) == 57 && status == 1){
                    result.Add("<divisão,>");
                    status = 0;
                    continue;
                }
                else{
                    Console.WriteLine(part);
                    Console.WriteLine(status);
                    foreach(string expr in expressions){
                        Console.Write(expr);
                        Console.Write(" ");
                    }
                    Console.WriteLine("Expressão não reconhecida");
                    return;
                }
                
            }
            

            foreach(string res in result){
                if(status == 0){
                    foreach(string expr in expressions){
                        Console.Write(expr);
                        Console.Write(" ");
                    }
                    Console.WriteLine("Expressão não reconhecida");
                    return;
                }
                Console.WriteLine(res);
            }

            return;
        
            
        }

    }
}
