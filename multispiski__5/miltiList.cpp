//
//  miltiList.cpp
//  multispiski__5
//
//  Created by Тимур Гарипов on 24/06/2019.
//  Copyright © 2019 Timur. All rights reserved.
//

#include "miltiList.hpp"
#include <cstring>


void multiList:: addStudentToCourse(const char *stud_name, int course_id)
{
    int s_key = countKey(stud_name);
    int s_hash = countHash(s_key, 0);
    int c_hash = countHash(course_id, 0);
    
    int stud_pos = searchStudent(s_hash, s_key, stud_name);
    if (stud_pos == ER_POS)
        return;
    
    int course_pos = searchCourse(s_hash, course_id)
    if (course_pos == ER_POS)
        return;
    
    
}





void multiList:: insertCourseArr(int c_id)
{
    int hash = countHash(c_id, 0);
    
    if (_course_arr[hash].course_id == -1) //место есть - вставляем
    {
        _course_arr[hash].course_id = c_id;
        return;
    }
    
    int pos = searchFreeCoursePos(c_id, hash); //ищем свободную
    if (pos != ER_POS) //нашли -> вставили
    {
        _course_arr[pos].course_id = c_id;
    }
    
    
}

void multiList:: insertStudentArr(const char *s_name)
{
    int key = countKey(s_name);
    int hash = countHash(key, 0);
    
    if (_student_arr[hash].name == nullptr)
    {
        _student_arr[hash].name = new char[20];
        strcpy(_student_arr[hash].name, s_name); //копируем строку в массив
        return;
    }
    
    int pos = searchFreeStudentPos(s_name, hash, key);
    if (pos != ER_POS)
    {
        if (_student_arr[pos].name == nullptr)
            _student_arr[pos].name = new char[20]; //не выделяем память для удаленной до этого строки
        
        strcpy(_student_arr[pos].name, s_name); //копируем строку в массив
    }
}


int multiList:: searchFreeCoursePos(int c_id, int hs) const
{
    int pos = ER_POS;
    int iter = 0;
    int original_hash = c_id;
    
    while (_course_arr[hs].course_id != -1)
    {
        if (_course_arr[hs].course_id == c_id)
            return ER_POS; //вставить не можем
        
        iter++;
        hs = countHash(c_id, iter);
        
        if (pos != ER_POS)
            pos = hs; //запоминаем позицию для дальнейшей вставки
        
        if (hs == original_hash)
            break;
    }
    if (pos == ER_POS) //если не нашли позицию удаленного элемента
        pos = hs; //то возвращаем позицию элемента nullptr
    
    return pos;
    
}

int multiList:: searchFreeStudentPos(const char *s_name, int hs, int key) const
{
       // при запуске этой функции мы изначально знаем, что такой hs в массиве есть
    int pos = ER_POS;
    int iter = 0;
    int original_hash = hs;
    
    while (_student_arr[hs].name != nullptr)
    {
        if (strcmp(_student_arr[hs].name, s_name) == 0) //строки совпали
            return ER_POS; //значит вставить не можем, позиция занята
        
        //выполняем повторное хеширование
        iter++;
        hs = countHash(key, iter); //считаем новый хэш
        
        if (pos != ER_POS)
            pos = hs; //запоминаем позицию для дальнейшей вставки
        
        if (hs == original_hash)
            break;
    }
    
    if (pos == ER_POS) //если не нашли позицию удаленного элемента
        pos = hs; //то возвращаем позицию элемента nullptr
    
    return pos;
}


int multiList:: searchCourse(int hs, int c_id) const
{
    int original_hash = c_id;
    int iter = 0;
    
    while (_course_arr[hs].course_id != -1)
    {
        if (_course_arr[hs].course_id == c_id) //нашли совпадение
        {
            return hs;
        }
        //повторное хеширование
        iter++;
        hs = countHash(c_id, iter);
        if (hs == original_hash)//вернулись к исходному хэшу -> класс закончился
            break;
    }
    return ER_POS;
}

int multiList:: searchStudent(int hs, int key, const char *s_name) const
{
    int original_hash = hs;
    int iter = 0;
    
    while (_student_arr[hs].name != nullptr) //пока не закончился класс
    {
        if (strcmp(_student_arr[hs].name, s_name) == 0)
            return hs;
        
        //выполняем повторное хеширование
        iter++;
        hs = countHash(key, iter); //считаем новый хэш
        if (hs == original_hash) //вернулись к исходному хэшу -> класс закончился
            break;
    }
    return ER_POS;
}


int multiList:: countKey(const char *s_name) const
{
    int key = 0;
    for (int i=0; i < strlen(s_name); i++)
        key += s_name[i];
    
    return key;
}

int multiList:: countHash(int key, int iter) const
{
    return (key + iter) % SIZE;
}
