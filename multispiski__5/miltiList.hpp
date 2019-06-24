//
//  miltiList.hpp
//  multispiski__5
//
//  Created by Тимур Гарипов on 24/06/2019.
//  Copyright © 2019 Timur. All rights reserved.
//

#ifndef miltiList_hpp
#define miltiList_hpp

#include <stdio.h>
#include "dataTypes.h"

#define ER_POS -1

class multiList
{
public:
    ~multiList();
    
    void addStudentToCourse(const char *stud_name, int course_id); //добавление студента на курс
    void removeStudentFromCourse(const char *stud_name, int course_id); //удалить студента с курса
    void expelStudent(const char *stud_name); //исключить студента со всех курсов
    void clearCourse(int course_id); //удалить всех студентов с курса
    void getStudList(int course_id) const; //получить список студентов курса
    void getCourseList(const char *stud_name) const; //получить список всех курсов студента
    void print() const;

private:
    static const int SIZE = 20;
    course _course_arr[SIZE]; //массив курсов
    student _student_arr[SIZE]; //массив студентов
    
    void insertCourseArr(int c_id); //вставка курса в массив курсов
    void insertStudentArr(const char *s_name); //вставка студента в массив студентов
    
    int countKey(const char *s_name) const; //подсчет ключа
    int countHash(int key, int iter) const; //подсчте хэша
    int searchFreeCoursePos(int c_id, int hs) const;
    int searchFreeStudentPos(const char *s_name, int hs, int key) const;
    int searchStudent(int hs, int key, const char *s_name) const;
    int searchCourse(int hs, int c_id) const;
};


#endif /* miltiList_hpp */
