#include <iostream>
#include <cmath>
#include <algorithm>
#include <boost/multiprecision/cpp_int.hpp>
 
 
 
class DimensionlessNum
{
    //dimensionless - безразмерный
 
    std::string Num = "null";
 
public:
    DimensionlessNum(std::string str)
    {
        Num = str;
    }
 
    //перегрузка оператора умножения
    DimensionlessNum operator *(const DimensionlessNum num)
    {
        int SIZE_NUM_OTHER = num.Num.size();    //длинна строки числа справа
        int SIZE_NUM_THIS = this->Num.size();   //длинна строки числа слева
 
        int *arr_num_OTHER = new int[SIZE_NUM_OTHER];
        int *arr_num_THIS = new int[SIZE_NUM_THIS];
 
        int *arr_RESULT = new int[SIZE_NUM_OTHER + SIZE_NUM_THIS];
 
        for(int i = 0; i < SIZE_NUM_OTHER + SIZE_NUM_THIS; i++)
        {
            arr_RESULT[i] = 0;
        }
 
        std::string str_result;
        str_result.resize(SIZE_NUM_OTHER+SIZE_NUM_THIS);    //для того, чтобы не было релокации памяти
 
        //конвертация string в int[]
        for(int i = 0; i < SIZE_NUM_OTHER ; i++)
        {
            arr_num_OTHER[i] = num.Num[SIZE_NUM_OTHER-1 - i] - '0';
            //std::cout << arr_num_OTHER[i];
        }
        //std:: cout<< std::endl;
 
        for(int i = 0; i < SIZE_NUM_THIS ; i++)
        {
            arr_num_THIS[i] = this->Num[SIZE_NUM_THIS-1 - i] - '0';
            //std::cout << arr_num_THIS[i];
        }
        //std:: cout<< std::endl;
 
 
        //цикл перемножения двух массивов
        str_result = "";
        for(int i = 0; i < SIZE_NUM_OTHER ; i++)
        {
            for(int j = 0; j < SIZE_NUM_THIS ; j++)
            {
                int local_result = arr_num_OTHER[i] * arr_num_THIS[j];
                arr_RESULT[j+i] += local_result % 10;
                arr_RESULT[j+i+1] += local_result / 10;
 
                if(arr_RESULT[j+i] > 9)
                {
                    arr_RESULT[j+i+1] += arr_RESULT[j+i] / 10;
                    arr_RESULT[j+i] = arr_RESULT[j+i] % 10;
                }
            }
        }
 
        //std:: cout<< std::endl;
 
 
        int i = SIZE_NUM_OTHER+SIZE_NUM_THIS-1;
        while(arr_RESULT[i] == 0)
            i--;                                //этим действием убираются лишние нули в начале
 
 
        for(; i >= 0 ; i--)
        {
            str_result += std::to_string(arr_RESULT[i]);
        }
 
        //std:: cout<< std::endl;
        DimensionlessNum result(str_result);
 
        delete[] arr_num_OTHER;
        delete[] arr_num_THIS;
 
        return result;
    }
 
    //перегрузка оператора умножения
    DimensionlessNum operator =(const DimensionlessNum num)
    {
        return this->Num=num.Num;
    }
 
  
DimensionlessNum operator ++()
    {
        
        int length_extension = 0;
 
        int SIZE_NUM_THIS = this->Num.size();
 
        for(int i = 0; i < SIZE_NUM_THIS; i++)                 //перевод в целочисленный массив при этом в обратном порядке
            if(Num[i] == '9') length_extension ++;      //считаем сколько цифр равны 9
 
 
        if (SIZE_NUM_THIS == length_extension)
        {
            SIZE_NUM_THIS++;
        }
 
        int *arr_num_THIS = new int[SIZE_NUM_THIS];
 
        /********ИНКРЕМЕНТ*******/
        arr_num_THIS[0]++;
        /********ИНКРЕМЕНТ*******/
 
        for(int i = 0; i < SIZE_NUM_THIS; i ++)
        {
            arr_num_THIS[i+1] += arr_num_THIS[i] / 10;
            arr_num_THIS[i] = arr_num_THIS[i] % 10;
        }
 
        return *this;
    }
 
    bool operator < (const DimensionlessNum & num)
    {
        //быстрый возврат
        if(this->Num.size() < num.Num.size()) return true;
            //долгий
        else if(this->Num.size() == num.Num.size())
        {
            for(int i = 0; i < Num.size(); i++)
            {
                if(this->Num[i] != num.Num[i])          //если числа оба очень большие, и количество цифр равны, именно такая комбинация ускорит сравнение.
                    if(this->Num[i] < num.Num[i]) return true;
                    else return false;
            }
        }
 
    }
 
    void Print()
    {
        std::cout << this->Num << std::endl;
        //std::cout << this->Num.size();
    }
};
 
DimensionlessNum fact(DimensionlessNum &num1)
{
    DimensionlessNum f("1");
    ++num1;
    for(DimensionlessNum i("1"); i < num1 ;++i )
    {
        i.Print();
 
        f = f * i;
    }
    std::cout<<std::endl;
 
    return f;
}
 
int main()
{
 
 
    DimensionlessNum num ("18");
    ++num;
    num.Print();
    //fact(num).Print();
 
    //num.Print();
