/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:02:49 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/09/18 19:11:00 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string numberToString(int number) {
    std::stringstream ss;
    ss << number;
    return ss.str();
}

void displayError(const std::string& message, const std::string& detail = "")
{
    std::cerr << "\033[31mERROR\033[0m: " << message << std::endl;
    if (!detail.empty()) {
        std::cerr << "   ➤ " << detail << std::endl;
    }
    std::cerr << "   Usage: ./replace <filename> <s1> <s2>" << std::endl;
}

std::string ft_replace(std::string line, std::string s1, std::string s2)
{
    int index = -1;
    
    index = line.find(s1);
    while (index != -1)
    {
        line = line.substr(0, index) + s2 + line.substr(index + s1.length(), line.length());
        index = line.find(s1, index + s1.length());
    }

    return line;
}

int ft_read_replace(std::string filename, std::string s1, std::string s2)
{
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        displayError("Failed to open file: " + filename,
            "Check if file exists and has read permissions");
            return 1;
    }
    
    std::ofstream outFile(filename.append(".replace").c_str());
    if (!outFile.is_open()) {
        displayError("Failed to create output file",
                    "Check write permissions in the directory");
        return 1;
    }
    
    std::string line;
    while (std::getline(inputFile, line)){
        line = ft_replace(line, s1, s2);
        outFile << line << std::endl;
    }
    
    inputFile.close();
    outFile.close();
    return 0;
}

int main(int argc, char const *argv[])
{
    std::string filename;
    std::string s1;
    std::string s2;
    
    if (argc == 4){
        filename = argv[1];
        s1 = argv[2];
        s2 = argv[3];
        if (s1.empty()) {
            displayError("Search string (s1) cannot be empty",
                 "Please provide a valid string to search for");
            return 1;
        }
        return (ft_read_replace(filename, s1, s2));
    } else {
        displayError("Invalid number of arguments", "Expected 3 arguments, got " + numberToString(argc-1));
        return 1;
    }
    return 0;
}

/* int main(int argc, char const *argv[])
{
    std::string text;
    std::string s1;
    std::string s2;
    int index = -1;
    
    if (argc == 4){
        text = argv[1];
        s1 = argv[2];
        s2 = argv[3];
        index = text.find(s1);
        while (index != -1){
            text = text.substr(0, index) + s2 + text.substr(index + s1.length(), text.length());
            index = text.find(s1);
        }
        std::cout << text;
    }
    return 0;
} */
