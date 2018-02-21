//
// Created by Thomas Couchoud on 06/02/2018.
//

#ifndef TP_C_SORTPAT_H
#define TP_C_SORTPAT_H

#include "Patient.h"

class SortPat
{
public:
	SortPat();
	Patient & operator()(Patient & p);
};

#endif //TP_C_SORTPAT_H
