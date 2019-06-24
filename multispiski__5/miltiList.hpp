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


class multiList
{
public:
    void addStudentToCourse(const char *stud_name, unsigned int course_id); //добавление студента на курс
    void removeStudentFromCourse(const char *stud_name, unsigned int course_id); //удалить студента с курса
    void expelStudent(const char *stud_name); //исключить студента со всех курсов
    void clearCourse(unsigned int course_id); //удалить всех студентов с курса
    void getStudList(unsigned int course_id) const; //получить список студентов курса
    void getCourseList(const char *stud_name) const; //получить список всех курсов студента
    void print() const;

private:
    
};


#endif /* miltiList_hpp */
