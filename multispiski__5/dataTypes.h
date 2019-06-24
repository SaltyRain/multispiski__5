//
//  dataTypes.h
//  multispiski__5
//
//  Created by Тимур Гарипов on 24/06/2019.
//  Copyright © 2019 Timur. All rights reserved.
//

#ifndef dataTypes_h
#define dataTypes_h

struct choice
{
    virtual int chooseStruct() = 0;
};

struct reg: choice
{
    reg *c_next; //указывает либо на студента ,либо на себя
    reg *s_next; //указывает либо на курс ,либо на себя
    reg() {
        c_next = nullptr;
        s_next = nullptr;
    }
    reg( reg* cnext, reg *snext) : c_next(cnext), s_next(snext) {};
    int chooseStruct() override
    {
        return 0;
    }
};

struct student: choice
{
    char *name;
    student *ptr; //указывает на такой же либо на курс
    student() {
        name = nullptr;
        ptr = nullptr;
    }
    int chooseStruct() override
    {
        return -1;
    }
};

struct course: choice
{
    int course_id;
    course *ptr; //указывает на такой же либо на студента
    course() {
        course_id = -1;
        ptr = nullptr;
    }
    int chooseStruct() override
    {
        return 1;
    }
};


#endif /* dataTypes_h */
