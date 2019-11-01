using System;
using System.Collections.Generic;
using System.Text;
using System.Text.RegularExpressions;
using System.IO;

namespace Automato{

    class Program{
        
        static void Main(string[] args){

            string[] argument = args;
            string data = "";
            List<string> dataParts = new List<string>();

            List<String> expressions = new List<String>();

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
                if(@Regex.IsMatch(part, expr01)){
                    Console.WriteLine("<numero, "+part+">");
                }
                if(@Regex.IsMatch(part, expr02)){
                    Console.WriteLine("<subtração,>");
                }
                if(@Regex.IsMatch(part, expr03)){
                    Console.WriteLine("<soma,>");
                }
                if(@Regex.IsMatch(part, expr04)){
                    Console.WriteLine("<multiplicação,>");
                }
                if(@Regex.IsMatch(part, expr05)){
                    Console.WriteLine("<divisão,>");
                }
                if(!@Regex.IsMatch(part, expr01) && !@Regex.IsMatch(part, expr02) && !@Regex.IsMatch(part, expr03) && !@Regex.IsMatch(part, expr04) && !@Regex.IsMatch(part, expr05)){
                    Console.WriteLine("<não identificado, "+part+">");
                }
                
            }

            return;
        
            
        }

    }
}
