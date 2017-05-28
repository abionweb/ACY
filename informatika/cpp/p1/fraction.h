/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fraction.h
 * Author: pavel
 *
 * Created on 28 мая 2017 г., 3:49
 */

#ifndef FRACTION_H
#define FRACTION_H

struct fraction {
//public:
    int first, second;
    int Init(int, int);
    int Read();
    void Show();
    int summa();
    
    /*fraction();
    fraction(const fraction& orig);
    virtual ~fraction();*/
//private:

};

#endif /* FRACTION_H */

