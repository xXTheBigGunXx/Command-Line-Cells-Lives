#include <iostream>
#include <array>
#include <algorithm>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>

const int rows = 40;
const int columns = 78;

const std::string space = std::string(1, char(219)) + std::string(1, char(219));
const std::string cell = std::string(1, char(176)) + std::string(1, char(176));


std::string ConvertDecimalToBinary(int number, int length);

void MatrixFormation(std::array<std::string, columns> &matrix);

void MatrixFormation(std::array<std::string, columns> &matrix, std::array<std::string, columns> &copy, std::string binary);

void PrintGrid(std::array<std::string, columns> matrix);

std::string CopyFormation(std::array<std::string, columns> &matrix, int index,std::string temp, std::string binary);

int main()
{
    std::srand(std::time(0));
    std::cout<<"\033[2J";

    for(int i = 0; i < 10; i++){
        std::array<std::string, columns> matrix;
        std::string binary = ConvertDecimalToBinary(/*std::rand() % 256*/165, 8);
        //std::cout<<binary<<'\n';

        MatrixFormation(matrix);
        
        for(int i = 0; i < rows; i++){
            std::array<std::string, columns> copy;
            PrintGrid(matrix);
            MatrixFormation(matrix, copy, binary);
            matrix = copy;
            Sleep(50);
        }
        Sleep(2000);
        std::cout << "\033[H";
    }

    system("pause");
}

std::string ConvertDecimalToBinary(int number, int length){
    std::string binary = "";

    while (number != 0) {
        binary += std::to_string(number % 2);
        number /= 2;
    }
    while(binary.size() < length){
        binary+="0";
    }
    //std::reverse(binary.begin(), binary.end());

    return binary;
}

void MatrixFormation(std::array<std::string, columns> &matrix){
    for(int i = 0; i < columns; i++){
        matrix[i] = space;
    }
    matrix[columns/2] = cell;    
}

void PrintGrid(std::array<std::string, columns> matrix){
    for(int i = 0; i < columns; i++){
        std::cout<<matrix[i];
    }std::cout<<'\n';
}

void MatrixFormation(std::array<std::string, columns> &matrix, std::array<std::string, columns> &copy, std::string binary){
    copy[0] = matrix[0];
    copy[columns - 1] = matrix[columns - 1];
    
    for(int i = 1; i < columns-1; i++){
        std::string temp = "";
        for(int j = -1; j < 2; j++){
            if(matrix[i + j] == space){
                temp += "0";
            }else{
                temp += "1";
            }
        }
        copy[i] = CopyFormation(matrix, i, temp, binary);
        //std::cout<<temp<<" ";

        temp.clear();
    }      
}

std::string CopyFormation(std::array<std::string, columns> &matrix, int index,std::string temp, std::string binary){
    if(temp[0] == '0' and temp[1] == '0' and temp[2] == '0'){
        if(binary[0] == '1'){return cell;}
    }
    else if (temp[0] == '0' and temp[1] == '0' and temp[2] == '1'){
        if(binary[1] == '1'){return cell;}
    }
    else if (temp[0] == '0' and temp[1] == '1' and temp[2] == '0'){
        if(binary[2] == '1'){return cell;}
    }
    else if (temp[0] == '0' and temp[1] == '1' and temp[2] == '1'){
        if(binary[3] == '1'){return cell;}
    }
    else if (temp[0] == '1' and temp[1] == '0' and temp[2] == '0'){
        if(binary[4] == '1'){return cell;}
    }
    else if (temp[0] == '1' and temp[1] == '0' and temp[2] == '1'){
        if(binary[5] == '1'){return cell;}
    }
    else if (temp[0] == '1' and temp[1] == '1' and temp[2] == '0'){
        if(binary[6] == '1'){return cell;}
    }
    else if (temp[0] == '1' and temp[1] == '1' and temp[2] == '1'){
        if(binary[7] == '1'){return cell;}
    }

    return space;
}